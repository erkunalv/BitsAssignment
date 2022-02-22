################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F4VgTx_Simple4LedScheduler.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F4VgTx_Simple4LedScheduler.list \

OBJCOPY_BIN += \
STM32F4VgTx_Simple4LedScheduler.bin \


# All Target
all: STM32F4VgTx_Simple4LedScheduler.elf secondary-outputs

# Tool invocations
STM32F4VgTx_Simple4LedScheduler.elf: $(OBJS) $(USER_OBJS) C:\Users\Kunal\ Verma\Desktop\BitsPilani\Semester1\Project\BitsAssignment\BitsProjectWorkspace\STM32F4VgTx_Simple4LedScheduler\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "STM32F4VgTx_Simple4LedScheduler.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Kunal Verma\Desktop\BitsPilani\Semester1\Project\BitsAssignment\BitsProjectWorkspace\STM32F4VgTx_Simple4LedScheduler\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F4VgTx_Simple4LedScheduler.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F4VgTx_Simple4LedScheduler.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F4VgTx_Simple4LedScheduler.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F4VgTx_Simple4LedScheduler.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F4VgTx_Simple4LedScheduler.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
