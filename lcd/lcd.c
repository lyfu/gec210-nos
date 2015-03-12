#include "stdio.h"
#include "s5pv210.h"
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
	//设置LCD RGB接口的24个管脚为lcd工作模式
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

void  lcd_draw_pixel(int x,int y,int color)
{
	if(x<0 || x >HOZVAL ||y<0 || y>LINEVAL)  return;
	(*p_buf)[y][x]=color;
}

void lcd_draw_line(int startx,int starty,int endx,int endy,int color)
{
	  ;
}

void lcd_draw_bitmap(unsigned char *p_color)
{
	int i,j;
	int w=800;
	int h=480;
	int blue,green,red;
	int color;
	for(j=0;j<h;j++)
	{
		for(i=0;i<w;i++)
		{
			  blue=*p_color++;
			  green=*p_color++;
			  red=*p_color++;
			  color=blue+(green<<8)+(red<<16);
			  lcd_draw_pixel(i,j,color);
		}
	}	
}



void lcd_draw_headerbitmap(int x,int y,unsigned char *p_color)
{
	HEADCOLOR *p_header=(HEADCOLOR*)p_color;
	int w=p_header->w;
	int h=p_header->h;
	int i,j;
	int red,green,blue,color;
	p_color+=8;
	for(j=0;j<h;j++)
	{
		for(i=0;i<w;i++)
		{
			blue=*p_color++;
			green=*p_color++;
			red=*p_color++;
			color=blue+(green<<8)+(red<<16);
			lcd_draw_pixel(x+i,y+j,color);
				
	
		}
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
	  lcd_init();
	printf("1\n");
	  lcd_clear_screen(0x0);
	  delay_lcd(0x10000);
	printf("2\n");
	  lcd_clear_screen(0xff);
	  delay_lcd(0x10000);
	printf("3\n");
	  lcd_clear_screen(0xff00);
	  delay_lcd(0x10000);
	printf("4\n");
	  lcd_clear_screen(0xff0000);
	  delay_lcd(0x10000);
	printf("5\n");
	  //lcd_draw_bitmap(gImage_testbmp);
	  lcd_draw_headerbitmap(100 ,50,gImage_testbmp1);
}
