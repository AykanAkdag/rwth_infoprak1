################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Variablen.cpp 

OBJS += \
./Variablen.o 

CPP_DEPS += \
./Variablen.d 


# Each subdirectory must supply rules for building sources it contributes
Variablen.o: ../Variablen.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"Variablen.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


