#include <REGX52.H>
#include <intrins.h>

sbit TRIG = P2^1;
sbit ECHO = P2^0;

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

void Delay20us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 6;
	while (--i);
}

void time0_init(void)
{
	TMOD |= 0X01;
	TH0 = 0X00;
	TL0 = 0X00;
	TR0 = 0;
}

void HCSR04_init(void) //HCSR04初始化
{
	TRIG = 0;
	ECHO = 1;
	time0_init();
}

float HCSR04_cm(void)
{
	int temp_buf[10];
	int temp;
	long temp_sum = 0;
	char i = 0,j = 0;
	float ftemp;
	
	for(i = 0;i < 10;i++)
	{
		TRIG = 1;
		Delay20us();
		TRIG = 0;
		
		while(ECHO == 0);
		TH0 = 0X00;
		TL0 = 0X00;
		TR0 = 1;
		while(ECHO == 1);
		TR0 = 0;
		temp_buf[i] = TH0*256 + TL0;
		Delay(80);
	}
	
	for(i = 0;i < 9;i++)
	{
		for(j = i + 1;j < 10;j++)
		{
			if(temp_buf[i] > temp_buf[j])
			{
				temp = temp_buf[i];
				temp_buf[i] = temp_buf[j];
				temp_buf[j] = temp;
			}
		}
	}
	for(i = 2;i < 8;i++)temp_sum += temp_buf[i];   //取平均值
	ftemp = (float)temp_sum/6;										 //去掉最大最小值
	
	return (float)(ftemp * 0.00034/2) * 100;
}