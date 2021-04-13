################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/calculos.c \
../src/practico_1.c \
../src/utils.c \
../src/utn.c 

OBJS += \
./src/calculos.o \
./src/practico_1.o \
./src/utils.o \
./src/utn.o 

C_DEPS += \
./src/calculos.d \
./src/practico_1.d \
./src/utils.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


