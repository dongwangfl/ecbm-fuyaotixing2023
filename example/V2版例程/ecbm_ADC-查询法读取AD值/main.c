/*
***********************************************************************************************
*例程名    ：ADC查询法读取AD值
*作者      ：奈特
*库函数版本：V2.2.7-7
*限定芯片  ：无，STC8系列都行。本例使用STC8A8K64S4A12。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程使用了GPIO库、UART库和ADC库。UART库用于在串口打印出ADC的测量值。
			3.在uart.h里可以设置串口的波特率，推荐使用可视化界面来设置。即点击代码编辑串口左下角的
			Configuration Wizard标签（只在.h文件才会有）。本例使用115200，8位，无校验，一位停止位。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	system_init();		//系统初始化函数，也是必须的。
	adc_init();			//初始化ADC
	while(1){
		//将通道0的AD值和通道1的电压值发送到串口1。同时板子上的Vref为3.287V（万用表实测）。
		uart_printf(1,"CH0=%u,CH1=%0.3fV\r\n",adc_read(0),adc_voltage(1,3.287f));
		delay_ms(1000);//延时一段时间，防止串口数据量太大而卡机。
	}
} 