// UART0 Demonstration.
//----------------------------------------------------------------
// CONTROLLER 		: LPC-2148  	
// DATE 			: December - 2015
// Developed By 	: Advanced Electronic Systems Bangalore,India
//----------------------------------------------------------------
// char typed in keyboard will be displayed through serial.
//----------------------------------------------------------------
#include <lpc214x.h>

unsigned char temp , temp1 = 0x00 ;
unsigned char rx_flag = 0 , tx_flag = 0 ;
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
    rx_flag = 0x00;
    tx_flag = 0x00;

    while(1)
    {
	temp=U0RBR;
		
		if(	temp=='1')
		{
		IOSET0=0x00ff0000;
		U0THR=temp;
		delay();
		delay();
		 }

		 else if(temp == '0')
		 {
		   	IOCLR0=0x00ff0000;
			U0THR=temp;
			delay();
		delay();
		 }

    }
}

