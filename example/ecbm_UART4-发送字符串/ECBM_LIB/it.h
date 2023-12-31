#ifndef _IT_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _IT_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2020 奈特

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

免责说明：
	本软件库以MIT开源协议免费向大众提供。作者只保证原始版本是由作者在维护修BUG，
其他通过网络传播的版本也许被二次修改过，由此出现的BUG与作者无关。而当您使用原始
版本出现BUG时，请联系作者解决。
                             **************************
                             * 联系方式：进群778916610 *
							 ************************** 
------------------------------------------------------------------------------------*///这是开源协议，下面是图形界面选项。
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>中断权重调整
//<i>该选项中的数值被称为“权重值”，一个中断的权重越大，它的优先级就越高。
//<o>外部中断0_____INT0
//<i>权重值越大，优先级越高。
//<0=>21
//<1=>51
//<2=>81
//<3=>111
#define ECBM_IT_INT0_PRIORITY 0
//<o>定时器0_______Timer0
//<i>权重值越大，优先级越高。
//<0=>20
//<1=>50
//<2=>80
//<3=>110
#define ECBM_IT_TIMER0_PRIORITY 0
//<o>外部中断1_____INT1
//<i>权重值越大，优先级越高。
//<0=>19
//<1=>49
//<2=>79
//<3=>109
#define ECBM_IT_INT1_PRIORITY 0
//<o>定时器1_______Timer1
//<i>权重值越大，优先级越高。
//<0=>18
//<1=>48
//<2=>78
//<3=>108
#define ECBM_IT_TIMER1_PRIORITY 0
//<o>串口1_________UART1
//<i>权重值越大，优先级越高。
//<0=>17
//<1=>47
//<2=>77
//<3=>107
#define ECBM_IT_UART1_PRIORITY 0
//<o>模数转换______ADC
//<i>权重值越大，优先级越高。
//<0=>16
//<1=>46
//<2=>76
//<3=>106
#define ECBM_IT_ADC_PRIORITY 0
//<o>低压检测______LVD
//<i>权重值越大，优先级越高。
//<0=>15
//<1=>45
//<2=>75
//<3=>105
#define ECBM_IT_LVD_PRIORITY 0
//<o>编程计数器____PCA
//<i>权重值越大，优先级越高。
//<0=>14
//<1=>44
//<2=>74
//<3=>104
#define ECBM_IT_PCA_PRIORITY 0
//<o>串口2_________UART2
//<i>权重值越大，优先级越高。
//<0=>13
//<1=>43
//<2=>73
//<3=>103
#define ECBM_IT_UART2_PRIORITY 0
//<o>串行外设接口_SPI
//<i>权重值越大，优先级越高。
//<0=>12
//<1=>42
//<2=>72
//<3=>102
#define ECBM_IT_SPI_PRIORITY 0
//<o>外部中断2_____INT2
//<i>权重值越大，优先级越高。
//<0=>11
#define ECBM_IT_INT2_PRIORITY 0
//<o>外部中断3_____INT3
//<i>权重值越大，优先级越高。
//<0=>10
#define ECBM_IT_INT3_PRIORITY 0
//<o>定时器2_______Timer2
//<i>权重值越大，优先级越高。
//<0=>9
#define ECBM_IT_TIMER2_PRIORITY 0
//<o>外部中断4_____INT4
//<i>权重值越大，优先级越高。
//<0=>8
//<1=>38
//<2=>68
//<3=>98
#define ECBM_IT_INT4_PRIORITY 0
//<o>串口3_________UART3
//<i>权重值越大，优先级越高。
//<0=>7
#define ECBM_IT_UART3_PRIORITY 0
//<o>串口4_________UART4
//<i>权重值越大，优先级越高。
//<0=>6
#define ECBM_IT_UART4_PRIORITY 0
//<o>定时器3_______Timer3
//<i>权重值越大，优先级越高。
//<0=>5
#define ECBM_IT_TIMER3_PRIORITY 0
//<o>定时器4_______Timer4
//<i>权重值越大，优先级越高。
//<0=>4
#define ECBM_IT_TIMER4_PRIORITY 0
//<o>比较器________CMP
//<i>权重值越大，优先级越高。
//<0=>3
//<1=>33
//<2=>63
//<3=>93
#define ECBM_IT_CMP_PRIORITY 0
//<o>脉宽调制______PWM
//<i>权重值越大，优先级越高。
//<0=>2
//<1=>32
//<2=>62
//<3=>92
#define ECBM_IT_PWM_PRIORITY 0
//<o>脉宽调制异常_PWMFD
//<i>权重值越大，优先级越高。
//<0=>1
//<1=>31
//<2=>61
//<3=>91
#define ECBM_IT_PWMFD_PRIORITY 0
//<o>集成电路总线_IIC
//<i>权重值越大，优先级越高。
//<0=>0
//<1=>30
//<2=>60
//<3=>90
#define ECBM_IT_IIC_PRIORITY 0
//</h>
//<q>中断优先级检测函数
//<i>上面的设置对于小白来说，可能看了就蒙圈了。但是使能该函数并调用的话，就能在串口上打印出中断优先级。
//<i>在串口助手显示的内容里，越排前面（或者说越排上面）的中断，优先级越高。
#define ECBM_IT_CHECK_EN 1
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define IT_RANGE_2 60
#define IT_RANGE_1 30
#if ECBM_IT_CHECK_EN == 1
#define IT_LIST STC8A_IT_LIST
#endif
/*--------------------------------------变量定义-----------------------------------*/
extern u8 STC8A_IT_LIST[22][9];
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：it_priority_check
描  述：中断优先级检测函数。在串口上打印出中断优先级。
		但是只有使能了中断开关的中断才会被打印出来。因此推荐在调试阶段，
		先把所有中断打开，然后调用本函数。检测无误后再按正常需求使能中断。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_priority_check(void);
/*-------------------------------------------------------
函数名：it_set_int0
描  述：外部中断0的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_int0(u8 priority);
/*-------------------------------------------------------
函数名：it_set_timer0
描  述：定时器0的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_timer0(u8 priority);
/*-------------------------------------------------------
函数名：it_set_int1
描  述：外部中断1的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_int1(u8 priority);
/*-------------------------------------------------------
函数名：it_set_timer1
描  述：定时器1的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_timer1(u8 priority);
/*-------------------------------------------------------
函数名：it_set_uart1
描  述：串口1的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_uart1(u8 priority);
/*-------------------------------------------------------
函数名：it_set_adc
描  述：ADC的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_adc(u8 priority);
/*-------------------------------------------------------
函数名：it_set_lvd
描  述：LVD的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_lvd(u8 priority);
/*-------------------------------------------------------
函数名：it_set_pca
描  述：PCA的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_pca(u8 priority);
/*-------------------------------------------------------
函数名：it_set_uart2
描  述：串口2的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_uart2(u8 priority);
/*-------------------------------------------------------
函数名：it_set_spi
描  述：SPI的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_spi(u8 priority);
/*-------------------------------------------------------
函数名：it_set_pwm
描  述：PWM的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_pwm(u8 priority);
/*-------------------------------------------------------
函数名：it_set_pwmfd
描  述：PWMFD的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_pwmfd(u8 priority);
/*-------------------------------------------------------
函数名：it_set_int4
描  述：外部中断4的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_int4(u8 priority);
/*-------------------------------------------------------
函数名：it_set_cmp
描  述：CMP的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_cmp(u8 priority);
/*-------------------------------------------------------
函数名：it_set_iic
描  述：IIC的中断优先级设置函数。
输  入：中断优先级，可输入0~3。0为最低，3为最高。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_iic(u8 priority);
/*-------------------------------------------------------
函数名：it_set_all
描  述：全体中断优先级一键设置函数。可以将中断优先级设置成和图形化界面一致的状态。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_set_all(void);
/*-------------------------------------------------------
函数名：it_reset_all
描  述：全体中断优先级一键还原函数。可以将中断优先级设置成上电默认状态。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2020-07-14
修改记录：
-------------------------------------------------------*/
extern void it_reset_all(void);
#endif 
