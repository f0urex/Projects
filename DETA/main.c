#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <errno.h>

int send(int slave_adr, int n_func, int adr, int n_flags);
int readWord(int fd);


int main()
{
	send(4, 0, 2, 3);
	return 0;
}

int send(int slave_adr, int n_func, int adr, int n_flags)
{
	int data[5];
	int fd = -1;
	errno = 0;
	fd = wiringPiI2CSetup(slave_adr);
	if(fd/*fd = wiringPiI2CSetup(slave_adr) */ == -1)
		{ printf("Initilization error: %d\n", errno); return -1; }
	printf("FD: %d\n", fd);
	if(n_func == 0)
	{
		wiringPiI2CWrite(fd, slave_adr);
		delay(100);
		n_func = 1;
		wiringPiI2CWrite(fd, n_func);
		delay(100);
		wiringPiI2CWrite(fd, adr);
		delay(100);
		wiringPiI2CWrite(fd, n_flags);
		delay(100);
		int temp_slave_adr = wiringPiI2CRead(fd);		
		printf("temp_slave_adr: %d\n", temp_slave_adr);
		if(temp_slave_adr != slave_adr)
			{ printf("Error: Intervention of another device!\n"); return -1; }
		delay(100);
		int temp_n_func = wiringPiI2CRead(fd);
		printf("temp_n_func: %d\n", temp_n_func);
		if(temp_n_func/*wiringPiI2CRead(fd)*/ == 1)
		{
			for(int j = 0; j < n_flags; j++)
				{
					data[j] = readWord(fd);
					printf("Adress #%d: %d\n", (adr+j), data[j]);
				}
		}
	}

}

int readWord(int fd)
{
	int high;
	int low;
	delay(100);
	high = wiringPiI2CRead(fd);
	delay(100);
	low = wiringPiI2CRead(fd);
	return (high * 256 + low);
}
