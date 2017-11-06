#include <lpc214x.h>
#include<stdio.h>
#include<string.h>
 char temp[]="";
 char abhay; 
 char temp1 = 0x00,i ;
unsigned char rx_flag = 0 , tx_flag = 0 ;
   void delay()
   {
   unsigned int del;

   for(del=0;del<10000;del++);
   }

int main(void)
{
	 char data1[]="turn on led";
	 char data2[]="turn on LED";
	 char data3[]="turn off led";
	 char data4[]="turn off LED";
	PINSEL0=0X0000005;  				//select TXD0 and RXD0 lines		
    
	U0LCR = 0X00000083;					//enable baud rate divisor loading and
	U0DLM = 0X00;          				//select the data format
    U0DLL = 0x13;      					//select baud rate 9600 bps
    U0LCR = 0X00000003;
	   					//select Transmit and Recieve interrupt
	IODIR0=0x00ff0000;    ///po.16 to p0.23 are made output common anode leds
     IOCLR0=0x00ff0000; 

    while(1)
    {
//	strcpy(temp,U0RBR);
	//temp=U0RBR;
	
	//abhay=U0RBR;
	//U0THR=abhay;
	

	//temp[i]=U0RBR;
//	U0THR=U0RBR;
     while(U0RBR!='0')
    {
	    temp[i]=U0RBR;
		U0THR=temp[i];
        i++;
	}
     	
		if((strcmp(data1,temp)==0)| (strcmp(data2,temp)==0))
		{
		IOSET0=0x00ff0000;
		if(temp[i]!='\n')
		{
		U0THR=temp[i];
		i++;
		}
		//strcpy(temp,U0THR);
		delay();
		delay();
		 }

		 else if((strcmp(data3,temp)==0)| (strcmp(data4,temp)==0))
		 {
		   	IOCLR0=0x00ff0000;
		//	U0THR=temp;
		//	strcpy(U0THR,temp);
			if(temp[i]!='\n')
		{
		U0THR=temp[i];
		i++;
		}
			delay();
		delay();
		 }
		 
	i++;
    }
}

