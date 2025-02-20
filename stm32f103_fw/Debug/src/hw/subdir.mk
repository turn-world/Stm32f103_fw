################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/hw.c 

OBJS += \
./src/hw/hw.o 

C_DEPS += \
./src/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/%.o src/hw/%.su src/hw/%.cyclo: ../src/hw/%.c src/hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32F103xB -c -I"C:/stm32/stm32f103_fw/src/lib/cube_f103/Drivers/CMSIS/Include" -I"C:/stm32/stm32f103_fw/src/common/hw/include" -I"C:/stm32/stm32f103_fw/src" -I"C:/stm32/stm32f103_fw/src/ap" -I"C:/stm32/stm32f103_fw/src/bsp" -I"C:/stm32/stm32f103_fw/src/common" -I"C:/stm32/stm32f103_fw/src/common/core" -I"C:/stm32/stm32f103_fw/src/hw" -I"C:/stm32/stm32f103_fw/src/lib" -I"C:/stm32/stm32f103_fw/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/stm32/stm32f103_fw/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/stm32/stm32f103_fw/src/common/hw/include" -I"C:/stm32/stm32f103_fw/src/lib/cube_f103/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/stm32/stm32f103_fw/src/lib/cube_f103/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/stm32/stm32f103_fw/src/lib/cube_f103/USB_DEVICE/App" -I"C:/stm32/stm32f103_fw/src/lib/cube_f103/USB_DEVICE/Target" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src-2f-hw

clean-src-2f-hw:
	-$(RM) ./src/hw/hw.cyclo ./src/hw/hw.d ./src/hw/hw.o ./src/hw/hw.su

.PHONY: clean-src-2f-hw

