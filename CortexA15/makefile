AS = arm-none-eabi-as
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
QEMU = qemu-system-arm

OBJ_DIR = obj
COMMON_DIR = common

START_AS = _start.arm
START_C = start.c
PRINTF_C = $(COMMON_DIR)/printf.c

START_O = $(OBJ_DIR)/_start.o
START_OBJ = $(OBJ_DIR)/start.o
PRINTF_OBJ = $(OBJ_DIR)/printf.o
KERNEL_ELF = kernel.elf

CFLAGS = -ffreestanding -Wall -Wextra -Werror
ASFLAGS = -march=armv7-a -mcpu=cortex-a15
LDFLAGS = -T linker.ld

all: $(KERNEL_ELF)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(START_O): $(START_AS) | $(OBJ_DIR)
	$(AS) $(ASFLAGS) $(START_AS) -o $(START_O)

$(START_OBJ): $(START_C) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(START_C) -o $(START_OBJ)

$(PRINTF_OBJ): $(PRINTF_C) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(PRINTF_C) -o $(PRINTF_OBJ)

$(KERNEL_ELF): $(START_O) $(START_OBJ) $(PRINTF_OBJ)
	$(LD) $(LDFLAGS) $(START_O) $(START_OBJ) $(PRINTF_OBJ) -o $(KERNEL_ELF)

run: $(KERNEL_ELF)
	$(QEMU) -M vexpress-a15 -cpu cortex-a15 -kernel $(KERNEL_ELF) -nographic

clean:
	rm -rf $(OBJ_DIR) $(KERNEL_ELF)

.PHONY: clean run
