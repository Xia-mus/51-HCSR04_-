#include <REGX52.H>
#include <LCD1602.H>
#include <HCSR04.H>

void main()
{
	//long Dis_value[6];
	int value = 0;
	
	LCD_Init();
	HCSR04_init();
	
	LCD_ShowString(1,1,"Distance:");
	LCD_ShowString(2,8,"MM");
	while(1)
	{
		value = HCSR04_cm() * 10;
//		Dis_value[0] = value/1000+0X30;
//		Dis_value[1] = value%1000/100+0X30;
//		Dis_value[2] = value%1000&1000/10+0X30;
//		Dis_value[3] = '.';
//		Dis_value[4] = value%1000%100%10%10+0X30;
//		Dis_value[5] = '\0';
		LCD_ShowNum(2,1,value,4);
		
	}
}