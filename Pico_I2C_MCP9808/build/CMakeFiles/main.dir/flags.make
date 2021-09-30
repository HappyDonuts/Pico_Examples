# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# compile ASM with C:/VSARM/armcc/10 2021.07/bin/arm-none-eabi-gcc.exe
# compile C with C:/VSARM/armcc/10 2021.07/bin/arm-none-eabi-gcc.exe
# compile CXX with C:/VSARM/armcc/10 2021.07/bin/arm-none-eabi-g++.exe
ASM_DEFINES = -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CORE=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_TARGET_NAME=\"main\" -DPICO_USE_BLOCKED_RAM=0

ASM_INCLUDES = -ID:\Users\Javi\GitHub\Pico_Projects\Pico_I2C_MCP9808\Inc -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_base\include -ID:\Users\Javi\GitHub\Pico_Projects\Pico_I2C_MCP9808\build\generated\pico_base -IC:\VSARM\sdk\pico\pico-sdk\src\boards\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_uart\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_i2c\include

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g -ffunction-sections -fdata-sections

C_DEFINES = -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CORE=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_TARGET_NAME=\"main\" -DPICO_USE_BLOCKED_RAM=0

C_INCLUDES = -ID:\Users\Javi\GitHub\Pico_Projects\Pico_I2C_MCP9808\Inc -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_base\include -ID:\Users\Javi\GitHub\Pico_Projects\Pico_I2C_MCP9808\build\generated\pico_base -IC:\VSARM\sdk\pico\pico-sdk\src\boards\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_uart\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_i2c\include

C_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g -ffunction-sections -fdata-sections -std=gnu11

CXX_DEFINES = -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CORE=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_TARGET_NAME=\"main\" -DPICO_USE_BLOCKED_RAM=0

CXX_INCLUDES = -ID:\Users\Javi\GitHub\Pico_Projects\Pico_I2C_MCP9808\Inc -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_stdlib\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_gpio\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_base\include -ID:\Users\Javi\GitHub\Pico_Projects\Pico_I2C_MCP9808\build\generated\pico_base -IC:\VSARM\sdk\pico\pico-sdk\src\boards\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_platform\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2040\hardware_regs\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_base\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2040\hardware_structs\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_claim\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_sync\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_uart\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_divider\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_time\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_timer\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_sync\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_util\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_runtime\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_clocks\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_irq\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_resets\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_pll\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_vreg\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_watchdog\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_xosc\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_printf\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_bootrom\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_bit_ops\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_divider\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_double\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_int64_ops\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_float\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_malloc\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\boot_stage2\include -IC:\VSARM\sdk\pico\pico-sdk\src\common\pico_binary_info\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_stdio\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\pico_stdio_uart\include -IC:\VSARM\sdk\pico\pico-sdk\src\rp2_common\hardware_i2c\include

CXX_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g -ffunction-sections -fdata-sections -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit -std=gnu++17

