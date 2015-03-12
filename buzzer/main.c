#define 	GPJ2CON 	(*(volatile unsigned long *) 0xE0200280)
#define 	GPJ2DAT		(*(volatile unsigned long *) 0xE0200284)
unsigned long delay_time = 0x50000;
// ÑÓÊ±º¯Êý
void delay(unsigned long count)
{
	volatile unsigned long i = count;
	while (i--)
		;
}


void main()
{
	buzzer_init();
	
	while(1)				
	{
		buzzer_on();		
		delay(delay_time);
		buzzer_off();		
		delay(delay_time);
		delay_time += 0x10000;
	}
}


