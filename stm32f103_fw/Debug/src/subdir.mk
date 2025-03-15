################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g -DSTM32F103xB -DUSER_VECT_TAB_ADDRESS -c -I"C:/GitHub/stm32f103_fw/src/lib/cube_f103/Drivers/CMSIS/Include" -I"C:/GitHub/stm32f103_fw/src/common/hw/include" -I"C:/GitHub/stm32f103_fw/src" -I"C:/GitHub/stm32f103_fw/src/ap" -I"C:/GitHub/stm32f103_fw/src/bsp" -I"C:/GitHub/stm32f103_fw/src/common" -I"C:/GitHub/stm32f103_fw/src/common/core" -I"C:/GitHub/stm32f103_fw/src/hw" -I"C:/GitHub/stm32f103_fw/src/lib" -I"C:/GitHub/stm32f103_fw/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/GitHub/stm32f103_fw/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/GitHub/stm32f103_fw/src/common/hw/include" -I"C:/GitHub/stm32f103_fw/src/lib/cube_f103/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/GitHub/stm32f103_fw/src/lib/cube_f103/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/GitHub/stm32f103_fw/src/lib/cube_f103/USB_DEVICE/App" -I"C:/GitHub/stm32f103_fw/src/lib/cube_f103/USB_DEVICE/Target" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

