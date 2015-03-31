################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IsolationForest.cpp \
../Tree.cpp \
../main.cpp \
../utility.cpp 

OBJS += \
./IsolationForest.o \
./Tree.o \
./main.o \
./utility.o 

CPP_DEPS += \
./IsolationForest.d \
./Tree.d \
./main.d \
./utility.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


