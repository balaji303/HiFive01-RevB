#include <stdio.h>
#include <string.h>
#include <metal/machine.h>
#include <metal/uart.h>

#define BAUD_RATE_115200 115200

void delay(void);

int main(void)
{
    // Initialize UART
    struct metal_uart *uart0;
    uart0 = metal_uart_get_device(0);
    metal_uart_init(uart0, BAUD_RATE_115200);

    // Initialize LED
    struct metal_led *led_red;
    led_red = metal_led_get_rgb("LD0", "red");
    metal_led_enable(led_red);
    metal_led_on(led_red);

    // Print a message
    int userInput = 0;
    const char *message = "Hello, HiFive1! with love from @Balaji303\r\n";
    size_t len = strlen(message);

    for (size_t i = 0; i < len; i++)
    {
        // Wait until UART is ready to transmit
        while (metal_uart_txready(uart0))
        {
            /* Wait */
        }
       	// Send character
        metal_uart_putc(uart0, message[i]);
    }

    while(1)
    {
    	// If no input then -1 is assigned
    	metal_uart_getc(uart0, &userInput);

    	if(userInput >= 1)
    	{
    		metal_led_off(led_red);
    		delay();
    	}
    	else
    	{
    		metal_led_on(led_red);
    		delay();
    	}
    }

    return 0;
}

void delay(void)
{
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<300;j++);
	}
}
