CC = arm-none-eabi-gcc
CPU = cortex-a7

CFLAGS = -mcpu=$(CPU) -fpic -ffreestanding
CSRCFLAGS = -O2 -Wall -Wextra
LFLAGS = -ffreestanding -O2 -nostdlib

KER_SRC = ../src/kernel
KER_HEAD = ../include
COMMON_SRC = ../src/common
OBJ_DIR = objects

KEYSOURCES = $(wildcard $(KER_SRC0)/*.c)
COMMONSOURCES = $(wildcard $(COMMON_SRC)/*.c)
ASMSOURCES = $(wildcard $(KEY_SRC)/*.s)
HEADERS = $(wildcard $(KER_HEAD)/*.h)

OBJECTS = $(patsubst $(KER_SRC)/%.c, $(OBJ_DIR)/%.o, $(KERSOURCES))
OBJECTS += $(patsubst $(COMMON_SRC)/%.c, $(OBJ_DIR)/%.o, $(COMMONSOURCES)
OBJECTS += $(patsubst $(KER_SRC)/%.c, $(OBJ_DIR)/%.o, $(ASMSOURCES)