# Compiler and tools
AS = arm-none-eabi-as
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
QEMU = qemu-system-arm

# Flags
CFLAGS = -ffreestanding -Wall -Wextra -Werror
ASFLAGS = -march=armv7-a -mcpu=cortex-a15
LDFLAGS = -T linker.ld

# Sources and objects
START_AS = _start.arm
START_O = _start.o
START_C = start.c
START_OBJ = start.o
KERNEL_ELF = kernel.elf

# Default target
all: $(KERNEL_ELF)

# Assemble the _start.arm to _start.o
$(START_O): $(START_AS)
	$(AS) $(ASFLAGS) $(START_AS) -o $(START_O)

# Compile start.c to start.o
$(START_OBJ): $(START_C)
	$(CC) $(CFLAGS) -c $(START_C) -o $(START_OBJ)

# Link _start.o and start.o to create kernel.elf
$(KERNEL_ELF): $(START_O) $(START_OBJ)
	$(LD) $(LDFLAGS) $(START_O) $(START_OBJ) -o $(KERNEL_ELF)

# Run the kernel using QEMU
run: $(KERNEL_ELF)
	$(QEMU) -M vexpress-a15 -cpu cortex-a15 -kernel $(KERNEL_ELF) -nographic

# Clean up object files and kernel
clean:
	rm -f $(START_O) $(START_OBJ) $(KERNEL_ELF)

