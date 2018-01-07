#include <stdio.h>
#include <lcd.h>
#include <wiringPi.h>
#include <time.h>

#define LCD_RS 3
#define LCD_E 0
#define LCD_D4 6
#define LCD_D5 1
#define LCD_D6 5
#define LCD_D7 4

int main()
{
	printf("Raspbery Pi LCD test\n");
	if(wiringPiSetup() == -1)
		printf("GPIO Setup failed!\n");
	int fd;
	printf("Start LCD initialization ...\n");
	fd = lcdInit(2,16,4,11,10,1,0,2,3,0,0,0,0);
	
	if(fd == -1)
	{	
		printf("Initialization failed\n");
	}
	else
	{
		time_t tt;
		time(&tt);
		struct tm * ttm;
		ttm = localtime(&tt);
		lcdClear(fd);
		lcdPosition(fd, 0, 0);
		lcdPrintf("%d:%d:%d\n",ttm->tm_hour, ttm->tm_min, ttm->tm_sec);
		lcdPosition(fd, 0, 1);
		lcdPrintf("%d:%d:%d\n", ttm->tm_mday, ttm->tm_mon, ttm->tm_year);
		//lcdClear(fd);
		//lcdPosition(fd, 0, 0);
				
		//lcdPrintf(fd, "Hello Violetta");
		//lcdPosition(fd, 0, 1);
		//lcdPrintf(fd, "How are you ?!");
		      	
}	
	return 0;
}

