/*
***********************************************************************************************
*例程名    ：掉电模式
*作者      ：奈特
*库函数版本：V3.0.3-3
*限定芯片  ：无，STC8系列都行。本例使用STC8A8K64S4A12。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程主要用了GPIO库和POWER库，使能UART库是为了提供自动下载功能。
			3.本例程将会用到一个LED来指示工作状态，因此如果用的不是ECBM的开发板的话，需要自己定义一个
			LED引脚。在本例中，LED定义到P5.5脚，低电平点亮。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	system_init();		//系统初始化函数，也是必须的。
	while(1){
		//掉电唤醒定时器的设置在power.h里，打开图形化界面后，
		//找到“优化和功能使能”，先使能“单片机电源控制函数”。然后找到“掉电唤醒定时器使能”。使能该功能后可以选择定时时间。
		//比如本例中，定时时间为4095。那么唤醒时间为1000000*16*4095/32000=2047500us=2秒左右。
		LED_ON;//点亮LED。
		delay_ms(2000);//将延时设置为2000毫秒，也就是2秒。
		LED_OFF;//熄灭LED。
		power_powerdown();//进入掉电模式。
		//在没有万用表的情况下，通过观察LED就能知道单片机是否处于掉电模式。
		//如果单片机没有进入掉电模式，那么power_powerdown函数执行后会立马回到循环开头执行LED_ON。
		//从现象上来说就看不到LED熄灭。但是要是看到LED在闪烁了，说明单片机在执行power_powerdown函数后进入了掉电模式。
		//然后等掉电唤醒定时器溢出了才唤醒。因此LED才会闪烁。
		//可以回到power.h修改定时时间为1000，那么唤醒时间为1000000*16*1000/32000=500000us=500ms左右。
		//掉电时间从2秒左右减短到0.5秒，可以看到LED闪烁频率比原来快一些，准确的说是熄灭的时间短一些。
	}
}