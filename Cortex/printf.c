#include <stdarg.h>
#include <stdint.h>

// Define memory-mapped I/O address for UART0, used for printing
#define UART0_BASE 0x3F201000
#define UART0_DR   *(volatile uint32_t*)(UART0_BASE + 0x00)
#define UART0_FR   *(volatile uint32_t*)(UART0_BASE + 0x18)

// Helper function to send a character to the UART
void uart_putc(char c) {
    // Wait for the UART to be ready to transmit (check the FR register)
    while (UART0_FR & (1 << 5)) { // Check if TXFF (transmit FIFO full)
        // Busy-wait until the UART is ready
    }
    UART0_DR = c; // Send character
}

// Helper function to print a string
void uart_puts(const char* str) {
    while (*str) {
        uart_putc(*str++);
    }
}

// Helper function to convert an integer to a string (itoa-like)
void uart_puti(int num) {
    if (num < 0) {
        uart_putc('-');
        num = -num;
    }

    char buf[10]; // Assuming 32-bit integer
    int i = 0;
    if (num == 0) {
        uart_putc('0');
        return;
    }

    while (num > 0) {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    // Print the digits in reverse order
    for (int j = i - 1; j >= 0; j--) {
        uart_putc(buf[j]);
    }
}

// Basic printf implementation
void uart_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; // Move to the next character after '%'

            if (*format == 'd') { // Integer
                int num = va_arg(args, int);
                uart_puti(num);
            }
            else if (*format == 's') { // String
                char* str = va_arg(args, char*);
                uart_puts(str);
            }
            // Add more format specifiers as needed
        } else {
            uart_putc(*format); // Regular character
        }

        format++;
    }

    va_end(args);
}

int main() {
    uart_printf("Hello, World!\n");
    uart_printf("Integer: %d\n", 12345);
    uart_printf("String: %s\n", "Test string");

    return 0;
}
