/**
 * @file sifive-welcome.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Red LED blink code 
 * @version 1
 * @date 17-01-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
#include <stdio.h>
#include <metal/led.h>

void delay(void);

/**
 * @brief Main Funcion
 * 
 * @return int 
 */
int main(void)
{
	// Declaration
	struct metal_led *ledRed;
	/**
	 * @brief Get the handle for the RedLed
	 * 
	 */
	ledRed = metal_led_get_rgb("LD0", "red");
	/**
	 * @brief Construct a new metal led enable object
	 * 
	 */
	metal_led_enable(ledRed);
	while(1)
	{
		/**
		 * @brief Construct a new metal led off object
		 * 
		 */
		metal_led_off(ledRed);
		/**
		 * @brief Construct a new delay object
		 * 
		 */
		delay();
		/**
		 * @brief Construct a new metal led on object
		 * 
		 */
		metal_led_on(ledRed);
		/**
		 * @brief Construct a new delay object
		 * 
		 */
		delay();
	}
	return 0;
}

/**
 * @brief A simple delay function
 * 
 */
void delay(void)
{
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<300;j++);
	}
}
