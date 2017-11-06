#include <lpc214x.h>
 char temp , temp1 = 0x00 ;
unsigned char rx_flag = 0 , tx_flag = 0 ;
void delay()
{
   unsigned int del;
	for(del=0;del<10000;del++);
}

int main(void)
{
	PINSEL0 |= 0X00050000;  	//select TXD1 and RXD1 lines
	U1LCR  = 0X00000083;		//enable baud rate divisor loading and
	          					//select the data format
    U1DLM = 0X00; 
	U1DLL = 0x13;      			//select baud rate 9600 bps
	U1LCR  = 0X00000003;
	U1FCR = 0x01;
	U1IER = 0X03;	   			//select Transmit and Recieve interrupt
					//select Transmit and Recieve interrupt
	IODIR0=0x00ff0000;    ///po.16 to p0.23 are made output common anode leds
     IOCLR0=0x00ff0000;
                
    while(1)
    {
  
	temp=U1RBR;
	//temp = UART0_RxChar();	/* Receive data from bluetooth */	
		if(	temp=='1')
		{
		IOSET0=0x00ff0000;
	//	UART0_SendString("LED ON\n");
	//	U0THR=temp;
	//	delay();
	//	delay();
		 }

		 else if(temp == '0')
		 {
		   	IOCLR0=0x00ff0000;
	//		UART0_SendString("LED OFF\n");
		//	U0THR=temp;
		//	delay();
		delay();
		 }

    }
}
