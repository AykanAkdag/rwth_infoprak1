################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../add.cpp \
../const.cpp \
../div.cpp \
../expression.cpp \
../mul.cpp \
../result.cpp \
../sub.cpp \
../taschenrechner.cpp 

OBJS += \
./add.o \
./const.o \
./div.o \
./expression.o \
./mul.o \
./result.o \
./sub.o \
./taschenrechner.o 

CPP_DEPS += \
./add.d \
./const.d \
./div.d \
./expression.d \
./mul.d \
./result.d \
./sub.d \
./taschenrechner.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


