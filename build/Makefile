CC = arm-none-eabi-gcc
CPU = cortex-a7

CFLAGS = -mcpu=$(CPU) -fpic -ffreestanding
CSRCFLAGS = -O2 -Wall -Wextra
LFLAGS = -ffreestanding -O2 -nostdlib

KER_SRC = ../src/kernel
KER_HEAD = ../include
COMMON_SRC = ../src/common
OBJ_DIR = objects

KEYSOURCES = $(wildcard $(KER_SRC)/*.c)
COMMONSOURCES = $(wildcard $(COMMON_SRC)/*.c)
ASMSOURCES = $(wildcard $(KEY_SRC)/*.s)
HEADERS = $(wildcard $(KER_HEAD)/*.h)

OBJECTS = $(wildcard $(OBJ_DIR)/*.o)

HEADERS = $(wildcard $(KER_HEAD)/*.h)
IMG_NAME = AhmadSamyOS.img

.PHONY : $(OBJECTS) build

$(OBJ_DIR)/%.o: $(KER_SRC)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -I$(KER_SRC) -I$(KER_HEAD) -c $< -o $@ $(CSRCFLAGS)

$(OBJ_DIR)/%.o:	$(KER_SRC)/%.s
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -I$(KER_SRC) -c $< -o $@

$(OBJ_DIR)/%.o:	$(COMMON_SRC)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -I$(KER_SRC) -I$(KER_HEAD) -c $< -o $@ $(CSRCFLAGS)


build:	$(OBJECTS) $(HEADERS)
		echo $(OBJECTS)
		$(CC) -T linker.ld -o $(IMG_NAME) $(LFLAGS) $(OBJECTS)


clean:
		rm -rf $(OBJ_DIR)
		rm $(IMG_NAME)

run:	build
		qemu-system-arm -m 256 -M raspi2 -serial stdio -kernel $(IMG_NAME)
