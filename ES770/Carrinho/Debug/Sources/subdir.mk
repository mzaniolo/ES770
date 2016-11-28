################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Serial.c \
../Sources/autoteste.c \
../Sources/debugUart.c \
../Sources/encoder_hal.c \
../Sources/fsl_debug_console.c \
../Sources/main.c \
../Sources/mcg_hal.c \
../Sources/pid.c \
../Sources/pwm_motor.c \
../Sources/sensor_hal.c \
../Sources/spline.c \
../Sources/util.c 

OBJS += \
./Sources/Serial.o \
./Sources/autoteste.o \
./Sources/debugUart.o \
./Sources/encoder_hal.o \
./Sources/fsl_debug_console.o \
./Sources/main.o \
./Sources/mcg_hal.o \
./Sources/pid.o \
./Sources/pwm_motor.o \
./Sources/sensor_hal.o \
./Sources/spline.o \
./Sources/util.o 

C_DEPS += \
./Sources/Serial.d \
./Sources/autoteste.d \
./Sources/debugUart.d \
./Sources/encoder_hal.d \
./Sources/fsl_debug_console.d \
./Sources/main.d \
./Sources/mcg_hal.d \
./Sources/pid.d \
./Sources/pwm_motor.d \
./Sources/sensor_hal.d \
./Sources/spline.d \
./Sources/util.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -I"C:\Freescale\KSDK_1.2.0\platform\utilities\inc" -I"C:\Freescale\KSDK_1.2.0\platform\system\inc" -I"C:\Freescale\KSDK_1.2.0\platform\osa\inc" -I"C:\Freescale\KSDK_1.2.0\platform\hal\inc" -I"C:\Freescale\KSDK_1.2.0\platform\drivers\inc" -I"C:\Freescale\KSDK_1.2.0/platform/utilities/inc" -I"C:\Freescale\KSDK_1.2.0/platform/utilities/src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -I"C:\Freescale\KSDK_1.2.0\platform\utilities\inc" -I"C:\Freescale\KSDK_1.2.0\platform\system\inc" -I"C:\Freescale\KSDK_1.2.0\platform\osa\inc" -I"C:\Freescale\KSDK_1.2.0\platform\hal\inc" -I"C:\Freescale\KSDK_1.2.0\platform\drivers\inc" -I"C:\Freescale\KSDK_1.2.0\lib" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"Sources/main.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


