
#include <stdio.h>
#include <metal/led.h>

void delay(void);
int main(void)
{
	// Declaration
	struct metal_led *ledRed;
	ledRed = metal_led_get_rgb("LD0", "red");
	metal_led_enable(ledRed);
	while(1)
	{
		metal_led_off(ledRed);
		delay();
		metal_led_on(ledRed);
		delay();
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
