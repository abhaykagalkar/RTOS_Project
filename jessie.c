#include <lpc214x.h>
#include<stdio.h>
#include<string.h>
unsigned char i;
char temp[]="";
 char str[]="1";
   char t;
void delay()
   {
   unsigned int del;

   for(del=0;del<10000;del++);
   }

  int main(void)
{
	PINSEL0=0X0000005;  				//select TXD0 and RXD0 lines		
    
	U0LCR = 0X00000083;					//enable baud rate divisor loading and
	U0DLM = 0X00;          				//select the data format
    U0DLL = 0x13;      					//select baud rate 9600 bps
    U0LCR = 0X00000003;
	U0IER = 0X03;	   					//select Transmit and Recieve interrupt
	IODIR0=0x00ff0000;    ///po.16 to p0.23 are made output common anode leds
     IOCLR0=0x00ff0000; 
 	   i=0;

//	 while(U0RBR!='0')
  //  {
//	    temp[i]=U0RBR;
//		delay();
	//	U0THR=temp[i];
 //       i++;
//	}


    
//	if(strcmp(temp,str)==0)
   t=U0RBR;
if(t=='0')
	{  while(1)
	{
	   IOSET0=0x00ff0000;
	  	delay();
		delay();
		delay();
		delay();
		IOCLR0=0x00ff0000;
	  	delay();
		delay();
		delay();
		delay();
	 } 
	}

 	 }
 

