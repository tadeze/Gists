################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/Addition_test.cpp \
../test/Multiply_test.cpp \
../test/test_factorial.cpp 

OBJS += \
./test/Addition_test.o \
./test/Multiply_test.o \
./test/test_factorial.o 

CPP_DEPS += \
./test/Addition_test.d \
./test/Multiply_test.d \
./test/test_factorial.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/tadeze/cppProjects/cunitDemo/contrib" -I"/home/tadeze/cppProjects/Demo/Include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


