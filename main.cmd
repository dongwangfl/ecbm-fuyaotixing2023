#include "ecbm_core.h"	//加载库函数的头文件。
#define LCD_RES  P52
#define LCD_BLK  P53
#define LCD_CS   P42





/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2){
	u8 h1,l1,h2,l2;
	h1=(u8)((x1+52)>>8);
	l1=(u8)((x1+52));
	h2=(u8)((x2+52)>>8);
	l2=(u8)((x2+52));
	lcm_write_8cmd(0x2a);//列地址设置
	lcm_write_8data(h1);
	lcm_write_8data(l1);
	lcm_write_8data(h2);
	lcm_write_8data(l2);
	h1=(u8)((y1+40)>>8);
	l1=(u8)((y1+40));
	h2=(u8)((y2+40)>>8);
	l2=(u8)((y2+40));
	lcm_write_8cmd(0x2b);//行地址设置
	lcm_write_8data(h1);
	lcm_write_8data(l1);
	lcm_write_8data(h2);
	lcm_write_8data(l2);
	lcm_write_8cmd(0x2c);//储存器写

}


/******************************************************************************
      函数说明：LCD初始化函数
      入口数据：无
      返回值：  无
******************************************************************************/
void Lcd_Init(void)
{
	gpio_mode(D52,GPIO_OUT);
	gpio_mode(D53,GPIO_OUT);
	gpio_mode(D42,GPIO_OUT);
	LCD_CS=0;
	LCD_BLK=1;//打开背光
	
	
	LCD_RES=0;
	delay_ms(100);
	LCD_RES=1;
	delay_ms(100);
	
	lcm_write_8cmd(0x11); 
	 
	lcm_write_8cmd(0x36); 
	lcm_write_8data(0x00);

	lcm_write_8cmd(0x3A);
	lcm_write_8data(0x05);

	lcm_write_8cmd(0xB2);
	lcm_write_8data(0x0C);
	lcm_write_8data(0x0C);
	lcm_write_8data(0x00);
	lcm_write_8data(0x33);
	lcm_write_8data(0x33); 

	lcm_write_8cmd(0xB7); 
	lcm_write_8data(0x35);  

	lcm_write_8cmd(0xBB);
	lcm_write_8data(0x19);

	lcm_write_8cmd(0xC0);
	lcm_write_8data(0x2C);

	lcm_write_8cmd(0xC2);
	lcm_write_8data(0x01);

	lcm_write_8cmd(0xC3);
	lcm_write_8data(0x12);   

	lcm_write_8cmd(0xC4);
	lcm_write_8data(0x20);  

	lcm_write_8cmd(0xC6); 
	lcm_write_8data(0x0F);    

	lcm_write_8cmd(0xD0); 
	lcm_write_8data(0xA4);
	lcm_write_8data(0xA1);

	lcm_write_8cmd(0xE0);
	lcm_write_8data(0xD0);
	lcm_write_8data(0x04);
	lcm_write_8data(0x0D);
	lcm_write_8data(0x11);
	lcm_write_8data(0x13);
	lcm_write_8data(0x2B);
	lcm_write_8data(0x3F);
	lcm_write_8data(0x54);
	lcm_write_8data(0x4C);
	lcm_write_8data(0x18);
	lcm_write_8data(0x0D);
	lcm_write_8data(0x0B);
	lcm_write_8data(0x1F);
	lcm_write_8data(0x23);

	lcm_write_8cmd(0xE1);
	lcm_write_8data(0xD0);
	lcm_write_8data(0x04);
	lcm_write_8data(0x0C);
	lcm_write_8data(0x11);
	lcm_write_8data(0x13);
	lcm_write_8data(0x2C);
	lcm_write_8data(0x3F);
	lcm_write_8data(0x44);
	lcm_write_8data(0x51);
	lcm_write_8data(0x2F);
	lcm_write_8data(0x1F);
	lcm_write_8data(0x1F);
	lcm_write_8data(0x20);
	lcm_write_8data(0x23);

	lcm_write_8cmd(0x21); 

	lcm_write_8cmd(0x29); 
}
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			lcm_write_8data((u8)(color>>8));
			lcm_write_8data((u8)(color));
		}
	}
}


void main(){			//main函数，必须的。

	system_init();		//系统初始化函数，也是必须的。
	lcm_init();
	Lcd_Init();
	LCD_Fill(0,0,135,240,0x1156);
	while(1){
		
	}
}   
