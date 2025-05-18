#include <intrins.h>

void Delay(char xms)	//@11.0592MHz
{
	int k;
	for(k=0;k<xms;k++)
	{
		unsigned char data i, j;
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}


