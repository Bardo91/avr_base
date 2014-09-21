#-------------------------------------------------------------------------------
# Simple makefile to build the library
#-------------------------------------------------------------------------------

# Config
board ?= ArduinoUno
currentOS ?=linux
PRJ_NAME = avr_base

# -- Global variables --
ATMEGA_TOOLCHAIN := $(AVR_HOME)/bin

# -- GNU Tools --
AS := $(ATMEGA_TOOLCHAIN)/avr-as # Assembler
AR := $(ATMEGA_TOOLCHAIN)/avr-ar # Archiver
CC := $(ATMEGA_TOOLCHAIN)/avr-gcc # C Compiler
CXX := $(ATMEGA_TOOLCHAIN)/avr-g++ # C++ Compiler
OBJCOPY := $(ATMEGA_TOOLCHAIN)/avr-objcopy # Obj copy
OBJDUMP := $(ATMEGA_TOOLCHAIN)/avr-objdump # Obj dump
READELF := $(ATMEGA_TOOLCHAIN)/avr-readelf # Read elf
AVRDUDE := $(ATMEGA_TOOLCHAIN)/avrdude

PORT ?= COM4
AVR_DEFINITIONS := -DATMEGA

ifeq ($(board), ArduinoUno)
	MCU ?= m328p
    PLATFORM_DEFINITIONS := $(AVR_DEFINITIONS) -DF_CPU=16000000L
    PLATFORM_FLAGS := -mmcu=atmega328p
	PROG_PROTOCOL ?= arduino
endif

ifeq ($(currentOS), linux)
	CXX_SRC := $(shell find ./src -name '*.cpp')
endif
ifeq ($(currentOS), windows)
	CXX_SRC := 	src/hal/interrupt/InterruptMgr.cpp
				
endif

CXX_OBJ := $(patsubst %.cpp, %.cpp.$(MCU).o, $(CXX_SRC))
TEMP_FILES := $(CXX_OBJ)

# -- Build variables --
PREPROCESSOR_DEFINITIONS := $(PLATFROM_DEFINITIONS)
WARNING_FLAGS := -Wall -Werror
INCLUDE_FLAGS :=  -I$(AVR_BASE_HOME) -I$(AVR_BASE_HOME)/stl
CXX_COMPILE_FLAGS := -std=c++11 \
 			-fno-rtti -fno-exceptions -ffunction-sections -fdata-sections
DEBUG_FLAGS := -g
OPTIMIZATION_FLAGS := -O4
COMMON_C_FLAGS := $(PLATFORM_FLAGS) $(PREPROCESSOR_DEFINITIONS) $(WARNING_FLAGS)\
 			 $(INCLUDE_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS)
CC_FLAGS := $(COMMON_C_FLAGS)
CXX_FLAGS := $(COMMON_C_FLAGS) $(CXX_COMPILE_FLAGS)

OUT_NAME := $(PRJ_NAME)
OUTPUT := lib$(OUT_NAME).a

# -- Rules --
all: $(OUTPUT)
	
clean:
	rm -f $(OUTPUT) $(TEMP_FILES)
	
$(OUTPUT): $(CXX_OBJ)
	$(AR) rcs $(OUTPUT) $(CXX_OBJ)

%.s: %.cpp
	$(CXX) -S -o $@ $^ $(CXX_FLAGS) $(REV_INCLUDE) $(LIB_DIR)

%.cpp.$(MCU).o: %.cpp
	$(CXX) -c -o $@ $^ $(CXX_FLAGS) $(REV_INCLUDE) $(LIB_DIR) -lc -lm -lc

assembly: $(OUT_NAME).S

$(OUT_NAME).S: $(CXX_SRC)
	$(CXX) -S -o $@ $^ $(CXX_FLAGS)

.PHONY: dwarf dump readelf run clean