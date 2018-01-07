#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

//#define PIN 2
int PIN = 0;
void light_led(int tt);

int main()
{
	if(!fork())
	{
		char *ss;
		printf("Privet my friend ");
		//gets(ss);
		//printf(ss);	
	}
	else
	{
		
		while(PIN != 27)
{
		wiringPiSetup();
		pinMode(PIN, OUTPUT);
		digitalWrite(PIN, LOW);
		delay(10);
		printf("PIN: %d\n", PIN);
		light_led(500);
		PIN++;
}		/*while(1)
		{
			light_led(1000);
			light_led(1000);
			light_led(500);
			light_led(500);
			light_led(500);
		}*/
	}
	return 0;
}

void light_led(int tt)
{
	digitalWrite(PIN, HIGH);
	delay(tt);
	digitalWrite(PIN, LOW);
	delay(tt);

}

