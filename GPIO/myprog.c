#include <bcm2835.h>
#include <stdio.h>
#define PIN RPI_GPIO_P1_03

int main()
{	
	if(!bcm2835_init())
	{
		printf("Error init");
		return 1;
	}
	int pin = 1;
	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
	while(pin != 40)
	{
	bcm2835_gpio_write(PIN, HIGH);
	bcm2835_delay(1000);
	bcm2835_gpio_write(PIN, LOW);
	bcm2835_delay(1000);	
	printf("Pin: %d\n", pin);
	pin++;	
}
	printf("END PROG !\n");
	//bcm2835_gpio_write(PIN, HIGH);
	return 0;
}

