#include <lpc214x.h>


    void delay()
   {
   unsigned int del;

   for(del=0;del<10000;del++);
   }
char UART0_RxChar(void) /* A function to receive a byte on UART0 */
{
	while( (U0LSR & 0x01) == 0);	/* Wait till RDR bit becomes 1 which tells that receiver contains valid data */
		return U0RBR;
}
int main(void)
{
char data_in;
	PINSEL0=0X0000005;  				//select TXD0 and RXD0 lines		
    IODIR0=0x00ff0000;    ///po.16 to p0.23 are made output common anode leds
     IOCLR0=0x00ff0000;

	U0LCR = 0X00000083;					//enable baud rate divisor loading and
	U0DLM = 0X00;          				//select the data format
    U0DLL = 0x13;      					//select baud rate 9600 bps
    U0LCR = 0X00000003;
	U0IER = 0X03;	   					//select Transmit and Recieve interrupt
   while(1)
	{
		data_in = UART0_RxChar();	/* Receive data from bluetooth */
		if ( data_in == '1' )	/* If data received is 1 */
		{
			 IOSET0=0x00ff0000;
			 delay();
		
	
		}
		else if ( data_in == '0' )	/* If data received is 0 */
		{
		
		  IOCLR0=0x00ff0000;
	
			  
		}
		else
		{
		 IOSET0=0x00ff0000;
			delay();
IOCLR0=0x00ff0000;
delay();

		
		}
	}
  
}

