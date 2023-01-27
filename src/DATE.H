#include<string.h>
#include<stdlib.h>

struct date
{
	int day;
	int month;
	int year;
	
	char* tostring()
	{
		char *str = "00 - 00 - 0000";
		int base = '0';
		str[0] = base + day/10;
		str[1] = base + day%10;
		str[5] = base + month/10;
		str[6] = base + month%10;
		unsigned int temp = year;
		str[13] = base + temp%10;
		temp /= 10;
		str[12] = base + temp%10;
		temp /= 10;
		str[11] = base + temp%10;
		temp /= 10;
		str[10] = base + temp%10;		
		return str;
	}
};