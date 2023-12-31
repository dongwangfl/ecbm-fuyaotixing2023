/*
***********************************************************************************************
*例程名    ：OLED-IIC驱动屏幕显示
*作者      ：奈特
*库函数版本：V3.0.3-5
*限定芯片  ：无，STC8系列都行。本例使用STC8F2K32S2。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程使用了GPIO库、UART库和SOFTIIC库。UART库用于自动下载。SOFTIIC库用于和OLED屏通信。
			3.在uart.h里可以设置串口的波特率，推荐使用可视化界面来设置。即点击代码编辑串口左下角的
			Configuration Wizard标签（只在.h文件才会有）。本例使用115200，8位，无校验，一位停止位。
			4.在工程中的DEVICE文件夹中添加oled.c。
			5.在oled.h里可以设置OLED屏的参数，推荐使用可视化界面来设置。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
#include "oled.h"		//加载OLED库的头文件。
oled_def oled1;			//定义一个OLED对象。
void main(){			//main函数，必须的。
	system_init();		//系统初始化函数，也是必须的。
	oled_auto_init(&oled1,"scl=p36,sda=p37");//将连接信息输入到初始化函数内,比如现在就是将屏幕的scl脚接到了P36脚，sda接到了P37脚。
	oled_printf(&oled1,0,0,"Hi,oled!");//在左上角显示HI，OLED！
	while(1){
		
	}
}