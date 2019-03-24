# path to STM32F103 standard peripheral library
STD_PERIPH_LIBS ?= ../an3268/stm32vldiscovery_package

LIB_DIR          = $(STD_PERIPH_LIBS)/Libraries
UTILITIES_DIR    = $(STD_PERIPH_LIBS)/Utilities
CMSIS_DIR        = $(LIB_DIR)/CMSIS
CM3_DIR          = $(CMSIS_DIR)/CM3
CORE_SUPPORT_DIR = $(CM3_DIR)/CoreSupport
DEV_SUPPORT_DIR  = $(CM3_DIR)/DeviceSupport/ST/STM32F10x
DRIVER_INC_DIR   = $(LIB_DIR)/STM32F10x_StdPeriph_Driver/inc
DRIVER_SRC_DIR   = $(LIB_DIR)/STM32F10x_StdPeriph_Driver/src
STARTUP_DIR      = $(DEV_SUPPORT_DIR)/startup/gcc_ride7

PROJECT_TEMPLATE_DIR = $(STD_PERIPH_LIBS)/Project/Examples/GPIOToggle
LD_DIR = $(PROJECT_TEMPLATE_DIR)/TrueSTUDIO

# list of source files
SOURCES  = main.c
SOURCES += $(DEV_SUPPORT_DIR)/system_stm32f10x.c
SOURCES += $(DRIVER_SRC_DIR)/*.c
SOURCES += $(STARTUP_DIR)/startup_stm32f10x_md.s
SOURCES += $(UTILITIES_DIR)/STM32vldiscovery.c

# name for output binary files
PROJECT ?= led

# compiler, objcopy (should be in PATH)
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# path to st-flash (or should be specified in PATH)
ST_FLASH ?= st-flash

FIRMWARE_OPTS = -DUSE_STDPERIPH_DRIVER

BOARD_OPTS = -DHSE_VALUE=0x8000000 -DSTM32F10X_MD_VL -DUSE_STM32_VLD -DSYSCLK_FREQ_24MHz=24000000

# specify compiler flags
CFLAGS  = -g -O2 -Wall
CFLAGS += -T $(LD_DIR)/stm32_flash.ld
CFLAGS += -mcpu=cortex-m3 -mtune=cortex-m3 -mthumb
CFLAGS += -Wl,--gc-sections
CFLAGS += -I.
CFLAGS += -I $(PROJECT_TEMPLATE_DIR)
CFLAGS += -I $(DEV_SUPPORT_DIR)
CFLAGS += -I $(CORE_SUPPORT_DIR)
CFLAGS += -I $(DRIVER_INC_DIR)
CFLAGS += -I $(UTILITIES_DIR)
CFLAGS += $(BOARD_OPTS)
CFLAGS += $(FIRMWARE_OPTS)

OBJS = $(SOURCES:.c=.o)

all: $(PROJECT).elf

# compile
$(PROJECT).elf: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@
	$(OBJCOPY) -O ihex $(PROJECT).elf $(PROJECT).hex
	$(OBJCOPY) -O binary $(PROJECT).elf $(PROJECT).bin

# remove binary files
clean:
	rm -f *.o *.elf *.hex *.bin

# flash
burn:
	sudo $(ST_FLASH) write $(PROJECT).bin 0x8000000
