################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/ASF/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/boards/user_board/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/ASF/common/utils/make/ \
../src/ASF/mega/ \
../src/ASF/mega/utils/ \
../src/ASF/mega/utils/assembler/ \
../src/ASF/mega/utils/preprocessor/ \
../src/config/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/USART.c \
../src/ASF/common/boards/user_board/init.c \
../src/main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
src/USART.o \
src/ASF/common/boards/user_board/init.o \
src/main.o

OBJS_AS_ARGS +=  \
src/USART.o \
src/ASF/common/boards/user_board/init.o \
src/main.o

C_DEPS +=  \
src/USART.d \
src/ASF/common/boards/user_board/init.d \
src/main.d

C_DEPS_AS_ARGS +=  \
src/USART.d \
src/ASF/common/boards/user_board/init.d \
src/main.d

OUTPUT_FILE_PATH +=LabExc01-HelloUSART.elf

OUTPUT_FILE_PATH_AS_ARGS +=LabExc01-HelloUSART.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler







src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD  -I"../common/applications/user_application/user_board/config" -I"../src/config" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src/ASF/mega/utils/preprocessor" -I"../src" -I"../src/ASF/common/boards/user_board"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega162 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/boards/user_board/%.o: ../src/ASF/common/boards/user_board/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD  -I"../common/applications/user_application/user_board/config" -I"../src/config" -I"../src/ASF/common/boards" -I"../src/ASF/mega/utils" -I"../src/ASF/common/utils" -I"../src/ASF/mega/utils/preprocessor" -I"../src" -I"../src/ASF/common/boards/user_board"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atmega162 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="LabExc01-HelloUSART.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega162 -Wl,--relax  
	@echo Finished building target: $@
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "LabExc01-HelloUSART.elf" "LabExc01-HelloUSART.hex"
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "LabExc01-HelloUSART.elf" "LabExc01-HelloUSART.eep" || exit 0
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "LabExc01-HelloUSART.elf" > "LabExc01-HelloUSART.lss"
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "LabExc01-HelloUSART.elf" "LabExc01-HelloUSART.srec"
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-size.exe" "LabExc01-HelloUSART.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "LabExc01-HelloUSART.elf" "LabExc01-HelloUSART.a" "LabExc01-HelloUSART.hex" "LabExc01-HelloUSART.lss" "LabExc01-HelloUSART.eep" "LabExc01-HelloUSART.map" "LabExc01-HelloUSART.srec" "LabExc01-HelloUSART.usersignatures"
	