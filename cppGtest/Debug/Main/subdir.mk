################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Main/Addition.cpp \
../Main/Multiply.cpp \
../Main/factorial.cpp 

OBJS += \
./Main/Addition.o \
./Main/Multiply.o \
./Main/factorial.o 

CPP_DEPS += \
./Main/Addition.d \
./Main/Multiply.d \
./Main/factorial.d 


# Each subdirectory must supply rules for building sources it contributes
Main/%.o: ../Main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/tadeze/cppProjects/cunitDemo/contrib" -I"/home/tadeze/cppProjects/Demo/Include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


