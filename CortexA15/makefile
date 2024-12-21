AS = arm-none-eabi-as
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
QEMU = qemu-system-arm

CFLAGS = -ffreestanding -Wall -Wextra -Werror
ASFLAGS = -march=armv7-a -mcpu=cortex-a15
LDFLAGS = -T linker.ld

START_AS = _start.arm
START_O = _start.o
START_C = start.c
START_OBJ = start.o
PRINTF_C = printf.c
PRINTF_OBJ = printf.o
KERNEL_ELF = kernel.elf

# Target to build the kernel
all: $(KERNEL_ELF)

# Assemble the start.s file
$(START_O): $(START_AS)
	$(AS) $(ASFLAGS) $(START_AS) -o $(START_O)

# Compile the start.c file
$(START_OBJ): $(START_C)
	$(CC) $(CFLAGS) -c $(START_C) -o $(START_OBJ)

# Compile the printf.c file
$(PRINTF_OBJ): $(PRINTF_C)
	$(CC) $(CFLAGS) -c $(PRINTF_C) -o $(PRINTF_OBJ)

# Link the kernel object files into the final ELF executable
$(KERNEL_ELF): $(START_O) $(START_OBJ) $(PRINTF_OBJ)
	$(LD) $(LDFLAGS) $(START_O) $(START_OBJ) $(PRINTF_OBJ) -o $(KERNEL_ELF)

# Run the kernel using QEMU
run: $(KERNEL_ELF)
	$(QEMU) -M vexpress-a15 -cpu cortex-a15 -kernel $(KERNEL_ELF) -nographic

# Clean up build artifacts
clean:
	rm -f $(START_O) $(START_OBJ) $(PRINTF_OBJ) $(KERNEL_ELF)
