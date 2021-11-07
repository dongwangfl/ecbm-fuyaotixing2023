/*
***********************************************************************************************
*例程名    ：获取芯片内部信息
*作者      ：奈特
*库函数版本：V3.0.3-3
*限定芯片  ：无，STC8系列都行。本例使用STC8F2K32S2。
*限定频率  ：无，STCISP提供的频率都行。本例使用24MHz。
*例程说明  ：1.可以在ecbm_core.h里设置你使用的单片机型号，只有设置正确才能获取到信息，然后编译并下载。
			2.本例程使用ecbm_core.c，使能UART库只是为了提供自动下载功能和发送信息到串口助手。
			3.在uart.h里可以设置串口的波特率，推荐使用可视化界面来设置。即点击代码编辑串口左下角的
			Configuration Wizard标签（只在.h文件才会有）。本例使用115200，8位，无校验，一位停止位。
*BUG反馈   ：进Q群778916610，@群主并提供完整代码截图。
***********************************************************************************************
*/
#include "ecbm_core.h"	//加载库函数的头文件。
void main(){			//main函数，必须的。
	u8 i;
	u8 LOCKID[7];
	system_init();		//系统初始化函数，也是必须的。
	//默认开启了自动下载功能，所以串口会在system_init函数里初始化。
	//芯片检查功能也是在system_init函数里执行，因此只需要在STCISP的串口助手上设置好115200，8位，无校验，一位停止位。
	//再勾选“编程完成后自动打开串口”就行，下载程序之后，串口助手会自动开，于是会看到如下信息：
	//ECBM V3.0.3 on STC8F2K32S2
	//Checking MCU ID.......OK
	//ID    :F644462D00F2A4
	//DATA  :128	Byte
	//IDATA :128	Byte
	//XDATA :2048	Byte
	//FLASH :32768	Byte
	//EEPROM:512	Byte
	//SYSCLK:24000000	Hz
	//LSI   :34800	Hz
	//BGV   :1340	mV
	//ENDIAN:big	endian
	
	
	//考虑到要读内部ID的人都是用来加密代码或者为了限定单片机跑它专用的HEX。
	//下面提供了读ID的判断例程：
	
	
	LOCKID[0]=0xF6;//首先这里的ID是我用的单片机ID。
	LOCKID[1]=0x44;//你下载到你的单片机之后，
	LOCKID[2]=0x46;//肯定就不是这个值了。
	LOCKID[3]=0x2D;//所以在下面的判断之后就会报错。
	LOCKID[4]=0x00;
	LOCKID[5]=0xF2;
	LOCKID[6]=0xA4;
	while(1){
		for(i=0;i<7;i++){//因为唯一ID有7位，所以循环7次。
			if((MCUID[i])!=LOCKID[i]){//比对算法就是最简单的判断数组每个元素相不相等而已。
				debug("\r\n\r\nError MCU,stop running\r\n");//不相等就显示错误。
				while(1);//然后死循环。
			}
		}
		delay_ms(1000);
	}
}

