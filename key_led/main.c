
// LED
#define 	rGPJ2CON 	(*(volatile unsigned long *) 0xE0200280)
#define 	rGPJ2DAT	(*(volatile unsigned long *) 0xE0200284)
#define  	rGPJ2PUD	(*(volatile unsigned long *) 0xE0200288)
// KEY
#define 	rGPH3CON 	(*(volatile unsigned long *) 0xE0200C60)
#define 	rGPH3DAT	(*(volatile unsigned long *) 0xE0200C64)
#define 	rGPH3PUD	(*(volatile unsigned long *) 0xE0200C68)

void main()
{
	      //led_init
        rGPJ2CON = 0x1111;            //D1-D4 -> output
        rGPJ2DAT = 0xff;
        rGPJ2PUD = 0x55;
        //key_init
        rGPH3CON &=~(0xf<<4);
        rGPH3PUD &=~(0x3<<2);

        while(1)
        {
                if(!(rGPH3DAT & (0x1<<1)))
                {
                        if(!(rGPH3DAT & (0x1<<1)))
                        {
                                while(!(rGPH3DAT & (0x1<<1)));
                                rGPJ2DAT ^= (0xf<<0);
                        }
                }
        }


}


