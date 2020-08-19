#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk


TARGET = c1m2

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

DFLAGS = -D$(PLATFORM)
CPPFLAGS = -E

ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) \
		 -m$(ARCH) -march=armv7e-m -mfloat-abi=hard \
		 -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(DFLAGS)
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	OBJDUMP = arm-eabi-none-objdump
endif

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(DFLAGS)
	LD = ld
	LDFLAGS = -Wl,Map=$(TARGET).map -T
	OBJDUMP = objdump
endif

OBJS = $(SOURCES:.c=.o)

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@
##	$(OBJDUMP) $@

%.d : %.c
	$(CC) -M -MP $< $(CFLAGS) -o $@

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) $(INCLUDES) -c $(CFLAGS) $^

.PHONY: build
build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.d *.asm *.i
