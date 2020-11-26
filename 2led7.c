#include <REGX51.H>
#include <math.h>
#define LED1 P3_0
#define LED2 P3_1
#define bat 0
#define tat 1
char so[10]={0xFC,0x06,0xDA,0xF2,0x4C,0xB6,0xE0,0xFE,0xF6};
void delay_ms(unsigned long time);
void main()
{
	P2_0=1;
	while(1)
	{
		P2_0=~P2_0;
		delay_ms(1000);
//		P1=0;
//		LED1=bat;
//		LED2=tat;
//		P2=so[1];
//		delay_ms(100);
//		LED1=tat;
//		LED2=bat;
//		P2=so[2];
//		delay_ms(100);
	}
}
void delay_ms(unsigned long time)
{
	TMOD=0x01; 
	while(time!=0)
	{
		TL0=(65535 - 333)%256;
		TH0=(65535 - 333)/256;
		TR0=1; 
		while(TF0==0); 
		TR0=0;
		TF0=0;
		time--;
	}
}