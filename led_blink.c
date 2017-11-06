/*#include<lpc214x.h>
unsigned int delay=0;
int main()
{
	PINSEL1=0x00000000;
	IO0DIR= 0x00000010;
	IO0SET=0x00000010;
	while(1)
	{
	 IO0SET = 0x000F0000;
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	IO0CLR = 0x00000000;
	 	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	 for(delay = 0 ; delay < 100000 ; delay++ );
	}
}

 #include <LPC21xx.h>

unsigned int delay=0 , i = 0 , temp = 0x00 ;

int main ()
{
	PINSEL1 = 0x00000000 ;

	IO0DIR = 0x0000F0000;	// Configure P0.16 to P0.19  as output
	IO0SET = 0x000F0000 ; 	// all LED's turned OFF.

	while(1)
	{
		temp =0x00008000 ; 	
		for( i = 0 ; i < 4 ; i++ )
		{
			temp <<= 1 ;			 	// LED's ON
			IO0CLR = temp ; 	
					
			for(delay = 0 ; delay < 100000 ; delay++ );
		}
		for(delay = 0 ; delay < 100000 ; delay++ );
		for(delay = 0 ; delay < 100000 ; delay++ );

		temp =0x00100000 ; 	
		for( i = 0 ; i < 4 ; i++ )
		{								 // LED's OFF
			temp >>= 1 ;
			IO0SET = temp ; 	
			for(delay = 0 ; delay < 100000 ; delay++ );
		}

		for(delay = 0 ; delay < 100000 ; delay++ );	  
       	for(delay = 0 ; delay < 100000 ; delay++ );
	}  
}	
  */
#include<lpc214x.h>
void delay(void);
int main ()

{
IODIR0=0x00ff0000;    ///po.16 to p0.23 are made output common anode leds
IOCLR0=0x00ff0000;
while(1)
{
IOSET0=0x00ff0000;
delay();
IOCLR0=0x00ff0000;
delay();
}
}
