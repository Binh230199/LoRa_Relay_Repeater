################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/lora.c \
../Core/Inc/rfm95.c \
../Core/Inc/wlv_def.c 

OBJS += \
./Core/Inc/lora.o \
./Core/Inc/rfm95.o \
./Core/Inc/wlv_def.o 

C_DEPS += \
./Core/Inc/lora.d \
./Core/Inc/rfm95.d \
./Core/Inc/wlv_def.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L152xE -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/lora.d ./Core/Inc/lora.o ./Core/Inc/rfm95.d ./Core/Inc/rfm95.o ./Core/Inc/wlv_def.d ./Core/Inc/wlv_def.o

.PHONY: clean-Core-2f-Inc

