#include <stdio.h>
#include <string.h>
#include <metal/machine.h>
#include <metal/uart.h>

#define BAUD_RATE_115200 115200

int main(void)
{
    // Initialize UART
    struct metal_uart *uart0;
    uart0 = metal_uart_get_device(0);
    metal_uart_init(uart0, BAUD_RATE_115200);

    // Print a message
    const char *message = "Hello, HiFive1! with love from @Balaji303\r\n";
    size_t len = strlen(message);

    for (size_t i = 0; i < len; i++){
        // Wait until UART is ready to transmit
        while (metal_uart_txready(uart0)) {
            /* Wait */
        }
       	// Send character
        metal_uart_putc(uart0, message[i]);

    }

    return 0;
}
