#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int

#define WDT 0X34
sfr WDT_CONTR = 0XC1;	//ø¥√≈π∑
sfr CLK_DIV = 0x97; // ±÷”
sbit DQ=P3^0;

void Delay100ms()		//@11.0592MHz
{
	uchar i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void Delay1min()
{
	uint i=600;
	do
	{
		WDT_CONTR = WDT;
		Delay100ms();
	}while(--i);
}
void Delay1hour()
{
	uint i=60;
	do
	{
		Delay1min();
	}while(--i);
}

void main()
{
	uchar open=2;
	uchar close=6;
	uchar i,j;
	DQ=1;
	while(1)
	{
		DQ=1;
		i=open,j=close;
		do
		{
			Delay1hour();
		}while(--i);
		DQ=0;
		do
		{
			Delay1hour();
		}while(--j);
	}
}