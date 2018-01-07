#include <stdio.h>
#include <wiringPiI2C.h>
#include <errno.h>
//extern int errno;
//errno = 0;
int main()
{
	errno = 0;
	int fd;
	fd = wiringPiI2CSetup(0x04);
	while(1)
	{
		
//		fd = wiringPiI2CSetup(0x04);
		printf("\n%d Hi, please enter any number (0 - 9): ", fd);
		int n;
		scanf("%d", &n);
		int nWr;
		nWr = -99;
		printf("\nTransmission: %d\n", n);
		nWr = wiringPiI2CWrite(fd, n);
		if(nWr == -1)
			printf("\nERROR: %d;", errno);
		printf("\nZpisal %d b\n", nWr);
		int nAnswer;
		nAnswer = wiringPiI2CRead(fd);	
		printf("\nAnswer: %d", nAnswer);
	}
	return 0;
}
