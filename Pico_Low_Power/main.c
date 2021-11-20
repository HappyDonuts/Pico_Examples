#include <stdio.h>
#include "pico/stdlib.h"
#include "pico_sleep/sleep.h"
#include "hardware/rtc.h"
#include "hardware/clocks.h"
#include "hardware/pll.h"

/* Issue : The system goes into sleep or dormant mode
   but cannot wake up properly
*/

static bool awake;

void measure_freqs(void) {
    uint f_pll_sys = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_PLL_SYS_CLKSRC_PRIMARY);
    uint f_pll_usb = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_PLL_USB_CLKSRC_PRIMARY);
    uint f_rosc = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_ROSC_CLKSRC);
    uint f_clk_sys = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_SYS);
    uint f_clk_peri = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_PERI);
    uint f_clk_usb = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_USB);
    uint f_clk_adc = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_ADC);
    uint f_clk_rtc = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_RTC);

    printf("pll_sys  = %dkHz\n", f_pll_sys);
    printf("pll_usb  = %dkHz\n", f_pll_usb);
    printf("rosc     = %dkHz\n", f_rosc);
    printf("clk_sys  = %dkHz\n", f_clk_sys);
    printf("clk_peri = %dkHz\n", f_clk_peri);
    printf("clk_usb  = %dkHz\n", f_clk_usb);
    printf("clk_adc  = %dkHz\n", f_clk_adc);
    printf("clk_rtc  = %dkHz\n", f_clk_rtc);

    // Can't measure clk_ref / xosc as it is the ref
}

static void sleep_callback(void) {
    printf("RTC woke us up\n");
    awake = true;
}

static void rtc_sleep(void) {
    // Start on Friday 5th of June 2020 15:45:00
    datetime_t t = {
            .year  = 2020,
            .month = 06,
            .day   = 05,
            .dotw  = 5, // 0 is Sunday, so 5 is Friday
            .hour  = 15,
            .min   = 45,
            .sec   = 00
    };

    // Alarm 10 seconds later
    datetime_t t_alarm = {
            .year  = 2020,
            .month = 06,
            .day   = 05,
            .dotw  = 5, // 0 is Sunday, so 5 is Friday
            .hour  = 15,
            .min   = 45,
            .sec   = 10
    };

    // Start the RTC
    rtc_init();
    rtc_set_datetime(&t);

    printf("Sleeping for 10 seconds\n");
    uart_default_tx_wait_blocking();

    sleep_goto_sleep_until(&t_alarm, &sleep_callback);
}

int main() {

    const uint8_t wake_pin = 10;
    stdio_init_all();

    measure_freqs();

    sleep_ms(10000);

    // // Wait for the fifo to be drained so we get reliable output
    uart_default_tx_wait_blocking();

    // // UART will be reconfigured by sleep_run_from_xosc
    sleep_run_from_xosc();

    awake = false;

    // sleep_goto_dormant_until_edge_high(wake_pin);
    rtc_sleep();

    measure_freqs();

    // Make sure we don't wake
    while (!awake) {
        printf("Should be sleeping\n");
    }

    return 0;
}
