#include "stdio.h"
#include "ascii_hz.h"
#include "s5pv210.h"
#include"1.h"
#define CLKVAL_F 4  //vclk=(HCKL_DSYS)/(CLKVAL_F+1)=33.3M
#define VSPW 9
#define VBPD 12
#define  VFPD 21
#define HSPW 19
#define HBPD 25
#define HFPD 209
#define XSIZE 800
#define YSIZE 480
#define LINEVAL (YSIZE-1)
#define HOZVAL (XSIZE-1)
#define LEFTTOPX 0
#define LEFTTOPY 0
#define RIGHTBOTX (XSIZE-1)
#define RIGHTBOTY (YSIZE-1)




/////////////////////////////////////////////


// FB¿¿
#define FB_ADDR			(0x32000000)
#define WIDTHEIGHT	800
#define HEIGHT	480
//¿¿¿¿¿ 480¿×800¿
#define ROW				(480)
#define COL				(800)
#define HOZVAL			(COL-1)
#define LINEVAL			(ROW-1)

#define LeftTopX     0
#define LeftTopY     0
#define RightBotX   (COL-1)
#define RightBotY   (ROW-1)


//////////////////////////////////////////////



//unsigned int vbuf[480][800];
#define FRAMEBUFFER 0X32000000
typedef struct _HEADCOLOR
{
   unsigned char scan;
   unsigned char gray;
   unsigned short w;
   unsigned short h;
   unsigned char is565;
   unsigned char rgb;
}HEADCOLOR;

volatile unsigned (*p_buf)[480][800]=(volatile unsigned (*)[480][800])FRAMEBUFFER;
extern unsigned char gImage_testbmp1[];
void delay_lcd(unsigned long i)
{
	volatile unsigned long j=i;
	while(j--);
}
void lcd_init(void)
{
	//ÉèÖÃLCD RGB½Ó¿ÚµÄ24¸ö¹Ü½ÅÎªlcd¹¤×÷Ä£Ê½
	rGPF0CON=0x22222222;
	rGPF1CON=0x22222222;
	rGPF2CON=0x22222222;
	rGPF3CON=0x22222222;

	rDISPLAY_CONTROL=0x3;

	rVIDCON0=(CLKVAL_F<<6)|(1<<4)|(0X3<<0);
	rVIDCON1=(1<<6)|(1<<5);
	rVIDCON2=0x0;
	rVIDCON3=0x0;

	rVIDTCON0=(VBPD<<16)|(VFPD<<8)|(VSPW<<0);
	rVIDTCON1=(HBPD<<16)|(HFPD<<8)|(HSPW<<0);
	rVIDTCON2= (LINEVAL<<11)|(HOZVAL<<0);

	rVIDTCON3=0X0;

	rWINCON0=(1<<15)|(0XB<<2)|(1<<0);
	rWINCON2&=~1;
	rVIDOSD0A=(LEFTTOPX<<11)|LEFTTOPY;
	rVIDOSD0B=(RIGHTBOTX<<11)|RIGHTBOTY;
	rVIDOSD0C=XSIZE*YSIZE;

	rVIDW00ADD0B0=FRAMEBUFFER;
	rVIDW00ADD1B0=FRAMEBUFFER+XSIZE*YSIZE*4;

	rSHADOWCON=1; 

}

// ¿¿
void lcd_draw_pixel(int row, int col, int color)
{
	unsigned long * pixel = (unsigned long  *)FB_ADDR;
//	   ¿¿ + ¿¿ *¿¿pix +¿¿¿
	*(pixel + row * COL + col) = color;

}


// ¿¿¿
void lcd_draw_cross(int row, int col, int halflen, int color)
{
	lcd_draw_hline(row, col-halflen, col+halflen, color);
	lcd_draw_vline(col, row-halflen, row+halflen, color);
}

void lcd_draw_hline(int row, int col1, int col2, int color)
{
	int j;

	// ¿¿row¿¿¿j¿
	for (j = col1; j <= col2; j++)
		lcd_draw_pixel(row, j, color);

}

// ¿¿¿
void lcd_draw_vline(int col, int row1, int row2, int color)
{
	int i;
	// ¿¿i¿¿¿col¿
	for (i = row1; i <= row2; i++)
		lcd_draw_pixel(i, col, color);

}
//¿¿
void lcd_draw_circle(int centerX, int centerY, int radius, int color)
{
	int x, y;
	for(y = 0; y < ROW; y++)
	{
		for(x = 0; x < COL; x++)
		{
			if(((x-centerX)*(x-centerX) + (y-centerY)*(y-centerY))>=radius*radius &&((x-centerX)*(x-centerX) + (y-centerY)*(y-centerY))<=(radius+2)*(radius+2))
				lcd_draw_pixel(x, y, color);
		}
	}
}
// ¿¿
void lcd_draw_bmp(const unsigned char gImage_bmp[])
{
	int i, j;
	unsigned char *p = (unsigned char *)gImage_bmp;
	int blue, green, red;
	int color;

	// ¿¿¿¿800x480¿¿
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
		{
			blue  = *p++;
			green = *p++;
			red   = *p++;
		
			color = red << 16 | green << 8 | blue << 0;
			lcd_draw_pixel(i, j, color);
		}

}

//¿¿¿ 16×16 = 256pix
void lcd_draw_hz(unsigned int x, unsigned int y, const unsigned char *c)
{
		// ¿¿¿¿¿¿¿
	//static int x = 400;	// ¿¿¿
	//static int y = 240;	// ¿¿¿

	int i ,j;
	unsigned char *p = c;
	int color;

	// ¿¿¿¿16×16¿¿
	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++)
		{
			color = *p++;
			if(color != 0xff) {
				lcd_draw_pixel(y+i, x+j, 0x00ff00);
			}
		}

}
//¿16*16¿¿,¿¿¿¿¿¿¿¿¿
void lcd_draw_hz16x16( const unsigned char *c)
{
	static int x = 0;
	static int y = 0;

	unsigned char *line_dots = c;

	int i, j ; //¿¿¿ ¿¿¿
	int temp;
	
	for(i=0; i<32; i++)
	{
		temp = i/2;
		for(j=0; j<8; j++)
		{
			if(j<8)	
			{
				if ( line_dots[i] & (0x80 >> j))
				{
					lcd_draw_pixel(y+i, x+j, 0xff);
				}
			}
		else 
			{
				if ( line_dots[i] & (0x800 >>(j-8)) )
				{
					lcd_draw_pixel(y+temp+1, x+j, 0xff);
				}
			}
		}
	}

	//¿¿¿¿¿¿¿¿¿¿16*16¿¿
	x +=16;
	if (x > COL)//¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
	{
		x = 0;
		y +=16;
		if (y > ROW)//¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿0¿
		{
			y = 0;
		}
	}
	
}

//¿¿¿
void lcd_draw_juxing(int row, int col1, int col2, int color)
{
	int i ,j;
	for(i=0;i<10;i++)
	{
		for(j=0; j<20;j++)
		{
			lcd_draw_hline(row,col1,col2,color);
			row ++;
		}
		col1 +=50;
		col2 +=50;
		row -=20;
		delay_lcd(0x100000);
	}

}
void lcd_clear_screen(int color)
{
	int i=0,j=0;
	for(j=0;j<YSIZE;j++)
	{
		for(i=0;i<XSIZE;i++)
		{
			 (*p_buf)[j][i]=color;
		}
	}
}

void lcd_test()
{
	  int c=0;          
	  lcd_init();
	  lcd_clear_screen(0x0);
	  delay_lcd(0x10000);
	  lcd_clear_screen(0xff);
	  delay_lcd(0x10000);
	  lcd_clear_screen(0xff00);
	  delay_lcd(0x10000);
	  lcd_clear_screen(0xff0000);
	  delay_lcd(0x10000);
	  while(1)
	  {

		printf("\r\n###############LCD Menu##############\r\n");
		printf("[1] lcd_clear_screen\r\n");
		printf("[2] lcd_draw_cross\r\n");
		printf("[3] lcd_draw_hline\r\n");
		printf("[4] lcd_draw_vline\r\n");
		printf("[5] lcd_draw_circle\r\n");
		printf("[6] lcd_draw_picture\r\n");
		printf("[7] lcd_draw_hz\r\n");
		printf("[8] lcd_draw_juxing\r\n");
		printf("Enter your choice:");
		c = getc();
		printf("%c\r\n",c);

		switch(c)
		{
			case '1':
				// ¿¿
				lcd_clear_screen(0x000000);									// ¿
				break;
			case '2':
				// ¿¿¿
				lcd_draw_cross(50, 50, 20, 0x0000ff);						// ¿
				break;
			case '3':
				// ¿¿¿
				lcd_draw_hline(HEIGHT/2, 100, WIDTHEIGHT-100, 0xff0000);	// ¿
				break;
			case '4':
				// ¿¿¿
				lcd_draw_vline(WIDTHEIGHT/2, 50, HEIGHT-50, 0x00ff00);		// ¿
				break;
			case '5':
				//¿¿
				lcd_draw_circle(240,400, 50, 0xff00);
				break;
			case '6':
				//¿¿¿
					lcd_draw_bmp(gImage_1);
					break;
			case '7':
					// ¿¿¿
					lcd_draw_hz(400, 240, gImage_zhou);
					lcd_draw_hz(416, 240, gImage_zhi);
					lcd_draw_hz(432, 240, gImage_cai);
					break;
			case '8':
					//¿¿¿
					lcd_draw_juxing(340,20,50,0x0000ff);
					break;
			default:
				break;
		}
		/*¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/

	}
	  }
