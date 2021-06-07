# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# compile ASM with /usr/bin/arm-none-eabi-gcc
# compile C with /bin/arm-none-eabi-gcc-9.2.1
# compile CXX with /usr/bin/arm-none-eabi-g++
ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g   -ffunction-sections -fdata-sections

ASM_DEFINES = -DCFG_TUSB_DEBUG=1 -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DPICO_BIT_OPS_PICO=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_DIVIDER_HARDWARE=1 -DPICO_DOUBLE_PICO=1 -DPICO_FLOAT_PICO=1 -DPICO_INT64_OPS_PICO=1 -DPICO_MEM_OPS_PICO=1 -DPICO_MULTICORE=1 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_PRINTF_PICO=1 -DPICO_TARGET_NAME=\"main\" -DPICO_USE_BLOCKED_RAM=0 -DRP2040_USB_DEVICE_MODE=1 -DTINYUSB_DEVICE_LINKED=1

ASM_INCLUDES = -I/home/wsl/pico/projects/microwave-pc -I/home/wsl/pico/projects/microwave-pc/build -I/home/wsl/pico/pico-sdk/src/common/pico_stdlib/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_gpio/include -I/home/wsl/pico/pico-sdk/src/common/pico_base/include -I/home/wsl/pico/projects/microwave-pc/build/generated/pico_base -I/home/wsl/pico/pico-sdk/src/boards/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_platform/include -I/home/wsl/pico/pico-sdk/src/rp2040/hardware_regs/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_base/include -I/home/wsl/pico/pico-sdk/src/rp2040/hardware_structs/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_claim/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_sync/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_uart/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_divider/include -I/home/wsl/pico/pico-sdk/src/common/pico_time/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_timer/include -I/home/wsl/pico/pico-sdk/src/common/pico_sync/include -I/home/wsl/pico/pico-sdk/src/common/pico_util/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_runtime/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_clocks/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_resets/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_watchdog/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_xosc/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_pll/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_vreg/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_irq/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_printf/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_bootrom/include -I/home/wsl/pico/pico-sdk/src/common/pico_bit_ops/include -I/home/wsl/pico/pico-sdk/src/common/pico_divider/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_double/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_int64_ops/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_float/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_malloc/include -I/home/wsl/pico/pico-sdk/src/rp2_common/boot_stage2/include -I/home/wsl/pico/pico-sdk/src/common/pico_binary_info/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_stdio/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_spi/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_pio/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_flash/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_dma/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_multicore/include -I/home/wsl/pico/pico-sdk/lib/tinyusb/src -I/home/wsl/pico/pico-sdk/lib/tinyusb/src/common -I/home/wsl/pico/pico-sdk/lib/tinyusb/hw -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/include 

C_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g   -ffunction-sections -fdata-sections

C_DEFINES = -DCFG_TUSB_DEBUG=1 -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DPICO_BIT_OPS_PICO=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_DIVIDER_HARDWARE=1 -DPICO_DOUBLE_PICO=1 -DPICO_FLOAT_PICO=1 -DPICO_INT64_OPS_PICO=1 -DPICO_MEM_OPS_PICO=1 -DPICO_MULTICORE=1 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_PRINTF_PICO=1 -DPICO_TARGET_NAME=\"main\" -DPICO_USE_BLOCKED_RAM=0 -DRP2040_USB_DEVICE_MODE=1 -DTINYUSB_DEVICE_LINKED=1

C_INCLUDES = -I/home/wsl/pico/projects/microwave-pc -I/home/wsl/pico/projects/microwave-pc/build -I/home/wsl/pico/pico-sdk/src/common/pico_stdlib/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_gpio/include -I/home/wsl/pico/pico-sdk/src/common/pico_base/include -I/home/wsl/pico/projects/microwave-pc/build/generated/pico_base -I/home/wsl/pico/pico-sdk/src/boards/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_platform/include -I/home/wsl/pico/pico-sdk/src/rp2040/hardware_regs/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_base/include -I/home/wsl/pico/pico-sdk/src/rp2040/hardware_structs/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_claim/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_sync/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_uart/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_divider/include -I/home/wsl/pico/pico-sdk/src/common/pico_time/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_timer/include -I/home/wsl/pico/pico-sdk/src/common/pico_sync/include -I/home/wsl/pico/pico-sdk/src/common/pico_util/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_runtime/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_clocks/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_resets/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_watchdog/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_xosc/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_pll/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_vreg/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_irq/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_printf/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_bootrom/include -I/home/wsl/pico/pico-sdk/src/common/pico_bit_ops/include -I/home/wsl/pico/pico-sdk/src/common/pico_divider/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_double/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_int64_ops/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_float/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_malloc/include -I/home/wsl/pico/pico-sdk/src/rp2_common/boot_stage2/include -I/home/wsl/pico/pico-sdk/src/common/pico_binary_info/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_stdio/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_spi/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_pio/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_flash/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_dma/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_multicore/include -I/home/wsl/pico/pico-sdk/lib/tinyusb/src -I/home/wsl/pico/pico-sdk/lib/tinyusb/src/common -I/home/wsl/pico/pico-sdk/lib/tinyusb/hw -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/include 

CXX_FLAGS = -mcpu=cortex-m0plus -mthumb -Og -g   -ffunction-sections -fdata-sections -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit

CXX_DEFINES = -DCFG_TUSB_DEBUG=1 -DCFG_TUSB_MCU=OPT_MCU_RP2040 -DCFG_TUSB_OS=OPT_OS_PICO -DPICO_BIT_OPS_PICO=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Debug\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_DIVIDER_HARDWARE=1 -DPICO_DOUBLE_PICO=1 -DPICO_FLOAT_PICO=1 -DPICO_INT64_OPS_PICO=1 -DPICO_MEM_OPS_PICO=1 -DPICO_MULTICORE=1 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_PRINTF_PICO=1 -DPICO_TARGET_NAME=\"main\" -DPICO_USE_BLOCKED_RAM=0 -DRP2040_USB_DEVICE_MODE=1 -DTINYUSB_DEVICE_LINKED=1

CXX_INCLUDES = -I/home/wsl/pico/projects/microwave-pc -I/home/wsl/pico/projects/microwave-pc/build -I/home/wsl/pico/pico-sdk/src/common/pico_stdlib/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_gpio/include -I/home/wsl/pico/pico-sdk/src/common/pico_base/include -I/home/wsl/pico/projects/microwave-pc/build/generated/pico_base -I/home/wsl/pico/pico-sdk/src/boards/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_platform/include -I/home/wsl/pico/pico-sdk/src/rp2040/hardware_regs/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_base/include -I/home/wsl/pico/pico-sdk/src/rp2040/hardware_structs/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_claim/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_sync/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_uart/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_divider/include -I/home/wsl/pico/pico-sdk/src/common/pico_time/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_timer/include -I/home/wsl/pico/pico-sdk/src/common/pico_sync/include -I/home/wsl/pico/pico-sdk/src/common/pico_util/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_runtime/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_clocks/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_resets/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_watchdog/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_xosc/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_pll/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_vreg/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_irq/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_printf/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_bootrom/include -I/home/wsl/pico/pico-sdk/src/common/pico_bit_ops/include -I/home/wsl/pico/pico-sdk/src/common/pico_divider/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_double/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_int64_ops/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_float/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_malloc/include -I/home/wsl/pico/pico-sdk/src/rp2_common/boot_stage2/include -I/home/wsl/pico/pico-sdk/src/common/pico_binary_info/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_stdio/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_spi/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_pio/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_flash/include -I/home/wsl/pico/pico-sdk/src/rp2_common/hardware_dma/include -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_multicore/include -I/home/wsl/pico/pico-sdk/lib/tinyusb/src -I/home/wsl/pico/pico-sdk/lib/tinyusb/src/common -I/home/wsl/pico/pico-sdk/lib/tinyusb/hw -I/home/wsl/pico/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/include 

