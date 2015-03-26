################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
<<<<<<< HEAD
../Tree.cpp \
../main.cpp 

OBJS += \
./Tree.o \
./main.o 

CPP_DEPS += \
./Tree.d \
./main.d 
=======
../test.cpp 

OBJS += \
./test.o 

CPP_DEPS += \
./test.d 
>>>>>>> b2bb1fb89e007de7b1e19d605d0d57f36e3627db


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


