#include<lpc214x.h>
void delay(void);
int main ()
{
IODIR0=0x00000010;    ///po.16 to p0.23 are made output common anode leds
IOCLR0=0x00000010;
while(1)
{
IOSET0=0x00000010;
delay();
IOCLR0=0x00000010;
delay();
}
}
   void delay(void)
   {
   int i;
  for(i=0;i<100000;i++);
   }
