/*
***********************************************************************************************
*例程名    ：主时钟分频输出
*作者      ：奈特
*库函数版本：V3.0.3-2
*限定芯片  ：无，STC8系列都行。本例使用STC8F2K32S2。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程只使用了GPIO库和ecbm_core.c，使能UART库只是为了提供自动下载功能。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	system_init();		//系统初始化函数，也是必须的。
	//STC8系列一些型号的IO上电默认是高阻态，要设置成输出（推挽）态。
	gpio_mode(D16,GPIO_OUT);//这里使用了P1.6脚。
	while(1){
		//所有的操作都在system_init里执行了，所以这里是空的。
		//而主时钟输出的设置在ecbm_core.h里，打开图形化界面后，
		//找到“单片机系统设置”，点进去找到“系统时钟输出”。使能该功能后可以选择输出的引脚和分频系数。
		//比如本例中，用的单片机型号是STC8F系列，所以分频系数使用的是“STC8F和STC8A设置输出分频”选项。
		//单片机运行在24MHz下，输出选择16分频到P1.6脚。于是用示波器可以在P1.6脚发现1.5MHz的方波。
	}
}