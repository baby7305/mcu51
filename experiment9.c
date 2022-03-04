/*********************************************
**					 普中科技				**
**					 点阵实验				**
** 说明：P0控制行，输出低电平有效；			**
**		 595输出控制列，输出高点平有效。	**
*********************************************/

#include"reg51.h"
#include<intrins.h>

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

/*******************************************************************************
* 函数名         : Hc595SendByte(unsigned char dat)
* 函数功能		   : 想74H595发送一个字节的数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void Hc595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}

void main(void)
{ 	
	Hc595SendByte(0x00);
   	while(1)
   	{		
		P0=0x7F;
		Hc595SendByte(0x80);		
   	}
}