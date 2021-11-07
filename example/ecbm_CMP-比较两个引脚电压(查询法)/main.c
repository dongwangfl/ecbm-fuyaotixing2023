/*
***********************************************************************************************
*例程名    ：比较两个引脚的电压（查询法）
*作者      ：奈特
*库函数版本：V3.0.3-3
*限定芯片  ：无，STC8系列都行。本例使用STC8F2K32S2。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，然后再次编译并下载。
			2.本例程使用了GPIO库、UART库和CMP库。
			3.在uart.h里可以设置串口的波特率，推荐使用可视化界面来设置。即点击代码编辑串口左下角的
			Configuration Wizard标签（只在.h文件才会有）。本例使用115200，8位，无校验，一位停止位。
			4.前往cmp.h查看比较器的设置，本例中将会设置比较P3.7和P3.6两个引脚的电压。比较结果还会输出
			到P3.4脚上。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	system_init();		//系统初始化函数，也是必须的。
	cmp_init();			//初始化比较器，由于设置了初始化打开，所以这句话里就打开了比较器。
	while(1){
		if(cmp_read()){//读取比较器的结果，
			debug("P3.7>P3.6V\r\n");//结果为1的话，说明P3.7的电压比P3.6的电压大。
			delay_ms(500);//用到了串口发送信息，就要降低一下发送速度，防止电脑串口卡死。
			//当你不慎将串口发送数据间隔设置太小，导致单片机不能正常使用自动下载功能的时候。
			//请使用冷启动来下载程序，即先断电--在STCISP上点击下载--再上电。
		}

	}
}