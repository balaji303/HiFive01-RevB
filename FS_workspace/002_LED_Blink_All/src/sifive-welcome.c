/**
 * @file sifive-welcome.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief All LED blink code
 * @version 1
 * @date 09-11-2023
 *
 * Copyright (c) 2023 @balaji303
 *
 */
#include <stdio.h>
#include <metal/led.h>

void delay(void);

int main(void)
{
	// Declaration
	int rc;
	struct metal_led *ledRed;
	struct metal_led *ledBlue;
	struct metal_led *ledGreen;
	/**
	 * @brief Get the handle for the RedLed
	 *
	 */
	ledRed = metal_led_get_rgb("LD0", "red");
	ledGreen = metal_led_get_rgb("LD0", "green");
	ledBlue = metal_led_get_rgb("LD0", "blue");
	/**
	 * @brief Construct a new metal led enable object
	 *
	 */
	metal_led_enable(ledRed);
	metal_led_enable(ledGreen);
	metal_led_enable(ledBlue);
	//led_on -> Turns OFF the LED
	//led_off -> Turns ON the LED
	metal_led_on(ledRed);
	metal_led_on(ledGreen);
	metal_led_on(ledBlue);
	while(1)
	{
		//Red alone ON
		metal_led_off(ledRed);
		metal_led_on(ledGreen);
		metal_led_on(ledBlue);
		delay();
		//Green alone ON
		metal_led_off(ledGreen);
		metal_led_on(ledRed);
		metal_led_on(ledBlue);
		delay();
		//Blue alone ON
		metal_led_off(ledBlue);
		metal_led_on(ledGreen);
		metal_led_on(ledRed);
		delay();
	}
}

void delay(void)
{

//uint64_t ticks = sec * RTC_FREQ;
//mtime_wait(ticks);

	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<300;j++);
	}
}
