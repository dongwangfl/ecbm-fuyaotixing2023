#ifndef _ECBM_REG_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_REG_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*----------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2021 奈特

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
---------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置---------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>STC8系列型号选择
//<i>列表提供的芯片类型都是在数据手册中出现的，仅根据理论进行设置，若有兼容性问题请入群告知我。
//<i>ROM容量留空，在下一个选项中选择。
//<0x110301=>STC8F1Kxx_8PIN 
//<0x110302=>STC8F1KxxS2_16PIN_20PIN 
//<0x120502=>STC8F2KxxS2_ALL 
//<0x120504=>STC8F2KxxS4_ALL 
//<0x2405C2=>STC8A4KxxS2A12_ALL 
//<0x2805C4=>STC8A8KxxS4A12_ALL 
//<0x2815C4=>STC8A8KxxD4_ALL
//<0x3103A2=>STC8G1Kxx_16PIN_20PIN 
//<0x310201=>STC8G1Kxx_8PIN 
//<0x3102A1=>STC8G1KxxA_8PIN 
//<0x3103A1=>STC8G1KxxT_20PIN 
//<0x3205A2=>STC8G2KxxS2_ALL 
//<0x3205A4=>STC8G2KxxS4_ALL 
//<0x4103A2=>STC8H1Kxx_20PIN 
//<0x4105A2=>STC8H1Kxx_32PIN  
//<0x4205C4=>STC8H2KxxT_48PIN 
//<0x4305C2=>STC8H3KxxS2_48PIN  
//<0x4305C4=>STC8H3KxxS4_48PIN  
//<0x4805C4=>STC8H8KxxU_48PIN_64PIN 
#define ECBM_MCU 0x2805C4
//<o>ROM选择
//<i>选择单片机的flash容量大小，主要影响唯一ID的读取。
//<8=>08 <12=>12 <16=>16 <17=>17 <28=>28 
//<32=>32 <60=>60 <64=>64
#define ECBM_MCU_ROM_SIZE 64
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置---------------
/*----------------------------------变量类型重映射--------------------------------*/
#define __IO     volatile  //防止优化的声明，目的是让编译器每次使用的时候都得去内存拿值。
typedef unsigned char u8;  //无符号的 8位变量，在C51里就是无符号字符型变量。
typedef unsigned int  u16; //无符号的16位变量，在C51里就是无符号  整型变量。
typedef unsigned long u32; //无符号的32位变量，在C51里就是无符号长整型变量。
typedef   signed char s8;  //有符号的 8位变量，在C51里就是有符号字符型变量。
typedef   signed int  s16; //有符号的16位变量，在C51里就是有符号  整型变量。
typedef   signed long s32; //有符号的32位变量，在C51里就是有符号长整型变量。
#define REG_IN_MASK(reg,mask,value)  do{reg=((reg&(~mask))|((u8)(value)&mask));}while(0)//以掩码的形式向在指定寄存器存入一个值。
#define read_idata_u8(x)  (*((u8  volatile idata *)x))//从idata区读取一个u8 变量。
#define read_idata_u16(x) (*((u16 volatile idata *)x))//从idata区读取一个u16变量。
#define read_idata_u32(x) (*((u32 volatile idata *)x))//从idata区读取一个u32变量。
#define read_xdata_u8(x)  (*((u8  volatile xdata *)x))//从xdata区读取一个u8 变量。
#define read_xdata_u16(x) (*((u16 volatile xdata *)x))//从xdata区读取一个u16变量。
#define read_xdata_u32(x) (*((u32 volatile xdata *)x))//从xdata区读取一个u32变量。
#define read_idata_s8(x)  (*((s8  volatile idata *)x))//从idata区读取一个s8 变量。
#define read_idata_s16(x) (*((s16 volatile idata *)x))//从idata区读取一个s16变量。
#define read_idata_s32(x) (*((s32 volatile idata *)x))//从idata区读取一个s32变量。
#define read_xdata_s8(x)  (*((s8  volatile xdata *)x))//从xdata区读取一个s8 变量。
#define read_xdata_s16(x) (*((s16 volatile xdata *)x))//从xdata区读取一个s16变量。
#define read_xdata_s32(x) (*((s32 volatile xdata *)x))//从xdata区读取一个s32变量。
//#define sfr         u8
//#define sbit        u8
//#define sfr16       u16
#if 1//以下是SFR区寄存器定义。通过这个宏定义快速折叠。
/*------------------------------------80H~87H------------------------------------*/
sfr P0          =0x80;//P0端口
sfr SP          =0x81;//堆栈指针
sfr DPL         =0x82;//数据指针（低字节）
sfr DPH         =0x83;//数据指针（高字节）
sfr S4CON       =0x84;//串口4控制寄存器
sfr S4BUF       =0x85;//串口4数据寄存器

sfr PCON        =0x87;//电源控制寄存器
/*------------------------------------88H~8FH------------------------------------*/
sfr TCON        =0x88;//定时器控制寄存器
sfr TMOD        =0x89;//定时器0/1模式寄存器
sfr TL0         =0x8A;//定时器0计数寄存器（低8位）
sfr TL1         =0x8B;//定时器1计数寄存器（低8位）
sfr TH0         =0x8C;//定时器0计数寄存器（高8位）
sfr TH1         =0x8D;//定时器1计数寄存器（高8位）
sfr AUXR        =0x8E;//辅助寄存器1
sfr INTCLKO     =0x8F;//外部中断与时钟输出控制寄存器
/*------------------------------------90H~97H------------------------------------*/
sfr P1          =0x90;//P1端口
sfr P1M1        =0x91;//P1口配置寄存器1
sfr P1M0        =0x92;//P1口配置寄存器0
sfr P0M1        =0x93;//P0口配置寄存器1
sfr P0M0        =0x94;//P0口配置寄存器0
sfr P2M1        =0x95;//P2口配置寄存器1
sfr P2M0        =0x96;//P2口配置寄存器0

/*------------------------------------98H~9FH------------------------------------*/
sfr SCON        =0x98;//串口1控制寄存器
sfr SBUF        =0x99;//串口1数据寄存器
sfr S2CON       =0x9A;//串口2控制寄存器
sfr S2BUF       =0x9B;//串口2数据寄存器

sfr IRCBAND     =0x9D;//IRC频段选择寄存器
sfr LIRTRIM     =0x9E;//内部高精度IRC频率微调寄存器
sfr IRTRIM      =0x9F;//内部高精度IRC频率调整寄存器
/*------------------------------------A0H~A7H------------------------------------*/
sfr P2          =0xA0;//P2端口
sfr BUS_SPEED   =0xA1;//总线速度控制寄存器
sfr P_SW1       =0xA2;//外设端口切换寄存器1





/*------------------------------------A8H~AFH------------------------------------*/
sfr IE          =0xA8;//中断允许寄存器
sfr SADDR       =0xA9;//串口1从机地址寄存器
sfr WKTCL       =0xAA;//掉电唤醒定时器（低8位）
sfr WKTCH       =0xAB;//掉电唤醒定时器（高8位）
sfr16   WKTC    =0xAA;//掉电唤醒定时器（16位）
sfr S3CON       =0xAC;//串口3控制寄存器
sfr S3BUF       =0xAD;//串口3数据寄存器
sfr TA          =0xAE;//DPTR时序控制寄存器
sfr IE2         =0xAF;//中断允许寄存器2
/*------------------------------------B0H~B7H------------------------------------*/
sfr P3          =0xB0;//P3端口
sfr P3M1        =0xB1;//P3口配置寄存器1
sfr P3M0        =0xB2;//P3口配置寄存器0
sfr P4M1        =0xB3;//P4口配置寄存器1
sfr P4M0        =0xB4;//P4口配置寄存器0
sfr IP2         =0xB5;//中断优先级控制寄存器2
sfr IP2H        =0xB6;//高中断优先级控制寄存器2
sfr IPH         =0xB7;//高中断优先级控制寄存器
/*------------------------------------B8H~BFH------------------------------------*/
sfr IP          =0xB8;//中断优先级控制寄存器
sfr SADEN       =0xB9;//串口1从机地址屏蔽寄存器
sfr P_SW2       =0xBA;//外设端口切换寄存器2
sfr VOCTRL      =0xBB;//电压控制寄存器
sfr ADC_CONTR   =0xBC;//ADC控制寄存器
sfr ADC_RES     =0xBD;//ADC转换结果寄存器（高）
sfr ADC_RESL    =0xBE;//ADC转换结果寄存器（低）

/*------------------------------------C0H~C7H------------------------------------*/
sfr P4          =0xC0;//P4端口
sfr WDT_CONTR   =0xC1;//看门狗控制寄存器
sfr IAP_DATA    =0xC2;//IAP数据寄存器
sfr IAP_ADDRH   =0xC3;//IAP高地址寄存器
sfr IAP_ADDRL   =0xC4;//IAP低地址寄存器
sfr IAP_CMD     =0xC5;//IAP命令寄存器
sfr IAP_TRIG    =0xC6;//IAP触发寄存器
sfr IAP_CONTR   =0xC7;//IAP控制寄存器
/*------------------------------------C8H~CFH------------------------------------*/
sfr P5          =0xC8;//P5端口
sfr P5M1        =0xC9;//P5口配置寄存器1
sfr P5M0        =0xCA;//P5口配置寄存器0
sfr P6M1        =0xCB;//P6口配置寄存器1
sfr P6M0        =0xCC;//P6口配置寄存器0
sfr SPSTAT      =0xCD;//SPI状态寄存器
sfr SPCTL       =0xCE;//SPI控制寄存器
sfr SPDAT       =0xCF;//SPI数据寄存器
/*------------------------------------D0H~D7H------------------------------------*/
sfr PSW         =0xD0;//程序状态字寄存器
sfr T4T3M       =0xD1;//定时器4/3控制寄存器
sfr T4H         =0xD2;//定时器4计数寄存器（高8位）
sfr T4L         =0xD3;//定时器4计数寄存器（低8位）
sfr T3H         =0xD4;//定时器3计数寄存器（高8位）
sfr T3L         =0xD5;//定时器3计数寄存器（低8位）
sfr T2H         =0xD6;//定时器2计数寄存器（高8位）
sfr T2L         =0xD7;//定时器2计数寄存器（低8位）
/*------------------------------------D8H~DFH------------------------------------*/
sfr CCON        =0xD8;//PCA控制寄存器
sfr CMOD        =0xD9;//PCA模式寄存器
sfr CCAPM0      =0xDA;//PCA模块0模式控制寄存器
sfr CCAPM1      =0xDB;//PCA模块1模式控制寄存器
#if (ECBM_MCU!=0x4805C4)//STC8带U的版本比较特殊
sfr CCAPM2      =0xDC;//PCA模块2模式控制寄存器
#else
sfr USBCLK      =0xDC;//USB时钟控制寄存器
#endif
#if (ECBM_MCU!=0x2815C4)//STC带D的版本比较特殊
sfr CCAPM3      =0xDD;//PCA模块3模式控制寄存器
#else
#define CCAPM3  (*(u8 volatile xdata *)0xFD54)//PCA模块3模式控制寄存器
#endif
sfr ADC_CFG     =0xDE;//ADC配置寄存器
sfr IP3         =0xDF;//中断优先级控制寄存器3
/*------------------------------------E0H~E7H------------------------------------*/
sfr ACC         =0xE0;//累加器
sfr P7M1        =0xE1;//P7口配置寄存器1
sfr P7M0        =0xE2;//P7口配置寄存器0
sfr DPS         =0xE3;//DPTR指针选择器
sfr DPL1        =0xE4;//第二组数据指针（低字节）
sfr DPH1        =0xE5;//第二组数据指针（高字节）
sfr CMPCR1      =0xE6;//比较器控制寄存器1
sfr CMPCR2      =0xE7;//比较器控制寄存器2
/*------------------------------------E8H~EFH------------------------------------*/
sfr P6          =0xE8;//P6端口
sfr CL          =0xE9;//PCA计数器低8位
sfr CCAP0L      =0xEA;//PCA模块0低8位
sfr CCAP1L      =0xEB;//PCA模块1低8位
#if (ECBM_MCU!=0x4805C4)//STC8带U的版本比较特殊
sfr CCAP2L      =0xEC;//PCA模块2低8位
#else
sfr USBDAT      =0xEC;//USB数据寄存器
#endif
#if (ECBM_MCU!=0x2815C4)//STC带D的版本比较特殊
sfr CCAP3L      =0xED;//PCA模块3低8位
#else
#define CCAP3L  (*(u8 volatile xdata *)0xFD55)//PCA模块3低8位
#endif
sfr IP3H        =0xEE;//高中断优先级控制寄存器3
sfr AUXINTIF    =0xEF;//扩展中断标志位寄存器
/*------------------------------------F0H~F7H------------------------------------*/
sfr B           =0xF0;//B寄存器
#if (ECBM_MCU==0x3205A4)||(ECBM_MCU==0x2815C4)
sfr PWMSET      =0xF1;//增强型PWM全局配置寄存器
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMCFG      =0xF1;//增强型PWM配置寄存器
#endif
sfr PCA_PWM0    =0xF2;//PCA0的PWM模式寄存器
sfr PCA_PWM1    =0xF3;//PCA1的PWM模式寄存器
#if (ECBM_MCU!=0x4805C4)//STC8带U的版本比较特殊
sfr PCA_PWM2    =0xF4;//PCA2的PWM模式寄存器
#else
sfr USBCON      =0xF4;//USB控制寄存器
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PCA_PWM3    =0xF5;//PCA3的PWM模式寄存器
#else
sfr IAP_TPS     =0xF5;//EEPROM擦除等待时间控制寄存器
#endif
#if (ECBM_MCU==0x2815C4)//STC带D的版本比较特殊
#define PCA_PWM3    (*(u8 volatile xdata *)0xFD57)//PCA3的PWM模式寄存器
#endif
#if (ECBM_MCU==0x2815C4)//STC带D的版本比较特殊
sfr PWMCFG      =0xF6;//增强型PWM配置寄存器
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMIF       =0xF6;//增强型PWM中断标志寄存器
sfr PWMFDCR     =0xF7;//异常检测控制器
#endif
#if (ECBM_MCU==0x3205A4)
sfr PWMCFG01    =0xF6;//增强型PWM配置寄存器
sfr PWMCFG23    =0xF7;//增强型PWM配置寄存器
#endif
/*------------------------------------F8H~FFH------------------------------------*/
sfr P7          =0xF8;//P7端口
sfr CH          =0xF9;//PCA计数器高8位
sfr CCAP0H      =0xFA;//PCA模块0高8位
sfr CCAP1H      =0xFB;//PCA模块1高8位
#if (ECBM_MCU!=0x4805C4)//STC8带U的版本比较特殊
sfr CCAP2H      =0xFC;//PCA模块2高8位
#else
sfr USBADR      =0xFC;//USB地址寄存器
#endif
#if (ECBM_MCU!=0x2815C4)//STC带D的版本比较特殊
sfr CCAP3H      =0xFD;//PCA模块3高8位
#else
#define CCAP3H  (*(u8 volatile xdata *)0xFD56)//PCA模块3高8位
#endif
#if (ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)
sfr PWMCR       =0xFE;//PWM控制寄存器
#endif
#if (ECBM_MCU==0x3205A4)
sfr PWMCFG45    =0xFE;//增强型PWM配置寄存器
#endif
sfr RSTCFG      =0xFF;//复位配置寄存器
/*-------------------------------------------------------------------------------*/
#endif
#if 1//以下是XDATA区寄存器定义。通过这个宏定义快速折叠。
/*----------------------------------FA00H~FA0FH----------------------------------*/
#define BMM_M2M_CFG                 (*(u8  volatile xdata *)0xFA00)//MEM_MEM配置寄存器
#define BMM_M2M_CR                  (*(u8  volatile xdata *)0xFA01)//MEM_MEM控制寄存器
#define BMM_M2M_STA                 (*(u8  volatile xdata *)0xFA02)//MEM_MEM状态寄存器
#define BMM_M2M_AMT                 (*(u8  volatile xdata *)0xFA03)//MEM_MEM传输总字节寄存器
#define BMM_M2M_DONE                (*(u8  volatile xdata *)0xFA04)//MEM_MEM传输完成字节寄存器
#define BMM_M2M_TXA                 (*(u16 volatile xdata *)0xFA05)//MEM_MEM发送地址寄存器（16位）
#define BMM_M2M_TXAH                (*(u8  volatile xdata *)0xFA05)//MEM_MEM发送地址寄存器（高8位）
#define BMM_M2M_TXAL                (*(u8  volatile xdata *)0xFA06)//MEM_MEM发送地址寄存器（低8位）
#define BMM_M2M_RXA                 (*(u16 volatile xdata *)0xFA07)//MEM_MEM接收地址寄存器（16位）
#define BMM_M2M_RXAH                (*(u8  volatile xdata *)0xFA07)//MEM_MEM接收地址寄存器（高8位）
#define BMM_M2M_RXAL                (*(u8  volatile xdata *)0xFA08)//MEM_MEM接收地址寄存器（低8位）
/*----------------------------------FA10H~FA1FH----------------------------------*/
#define BMM_ADC_CFG                 (*(u8  volatile xdata *)0xFA10)//ADC_MEM配置寄存器
#define BMM_ADC_CR                  (*(u8  volatile xdata *)0xFA11)//ADC_MEM控制寄存器
#define BMM_ADC_STA                 (*(u8  volatile xdata *)0xFA12)//ADC_MEM状态寄存器
#define BMM_ADC_RXA                 (*(u16 volatile xdata *)0xFA17)//ADC_MEM接收地址寄存器（16位）
#define BMM_ADC_RXAH                (*(u8  volatile xdata *)0xFA17)//ADC_MEM接收地址寄存器（高8位）
#define BMM_ADC_RXAL                (*(u8  volatile xdata *)0xFA18)//ADC_MEM接收地址寄存器（低8位）
#define BMM_ADC_CFG2                (*(u8  volatile xdata *)0xFA19)//ADC_MEM配置寄存器2
#define BMM_ADC_CHSW0               (*(u8  volatile xdata *)0xFA1A)//ADC_MEM通道使能寄存器0
#define BMM_ADC_CHSW1               (*(u8  volatile xdata *)0xFA1B)//ADC_MEM通道使能寄存器1
/*----------------------------------FA20H~FA2FH----------------------------------*/
#define BMM_SPI_CFG                 (*(u8  volatile xdata *)0xFA20)//SPI_MEM配置寄存器
#define BMM_SPI_CR                  (*(u8  volatile xdata *)0xFA21)//SPI_MEM控制寄存器
#define BMM_SPI_STA                 (*(u8  volatile xdata *)0xFA22)//SPI_MEM状态寄存器
#define BMM_SPI_AMT                 (*(u8  volatile xdata *)0xFA23)//SPI_MEM传输总字节寄存器
#define BMM_SPI_DONE                (*(u8  volatile xdata *)0xFA24)//SPI_MEM传输完成字节寄存器
#define BMM_SPI_TXA                 (*(u16 volatile xdata *)0xFA25)//SPI_MEM发送地址寄存器（16位）
#define BMM_SPI_TXAH                (*(u8  volatile xdata *)0xFA25)//SPI_MEM发送地址寄存器（高8位）
#define BMM_SPI_TXAL                (*(u8  volatile xdata *)0xFA26)//SPI_MEM发送地址寄存器（低8位）
#define BMM_SPI_RXA                 (*(u16 volatile xdata *)0xFA27)//SPI_MEM接收地址寄存器（16位）
#define BMM_SPI_RXAH                (*(u8  volatile xdata *)0xFA27)//SPI_MEM接收地址寄存器（高8位）
#define BMM_SPI_RXAL                (*(u8  volatile xdata *)0xFA28)//SPI_MEM接收地址寄存器（低8位）
#define BMM_SPI_CFG2                (*(u8  volatile xdata *)0xFA29)//SPI_MEM配置寄存器2
/*----------------------------------FA30H~FA3FH----------------------------------*/
#define BMM_UR1T_CFG                (*(u8  volatile xdata *)0xFA30)//UART12MEM发送配置寄存器
#define BMM_UR1T_CR                 (*(u8  volatile xdata *)0xFA31)//UART12MEM发送控制寄存器
#define BMM_UR1T_STA                (*(u8  volatile xdata *)0xFA32)//UART12MEM发送状态寄存器
#define BMM_UR1T_AMT                (*(u8  volatile xdata *)0xFA33)//UART12MEM发送总字节寄存器
#define BMM_UR1T_DONE               (*(u8  volatile xdata *)0xFA34)//UART12MEM发送完成字节寄存器
#define BMM_UR1T_TXA                (*(u16 volatile xdata *)0xFA35)//UART12MEM发送地址寄存器（16位）
#define BMM_UR1T_TXAH               (*(u8  volatile xdata *)0xFA35)//UART12MEM发送地址寄存器（高8位）
#define BMM_UR1T_TXAL               (*(u8  volatile xdata *)0xFA36)//UART12MEM发送地址寄存器（低8位）
#define BMM_UR1R_CFG                (*(u8  volatile xdata *)0xFA38)//UART12MEM接收配置寄存器
#define BMM_UR1R_CR                 (*(u8  volatile xdata *)0xFA39)//UART12MEM接收控制寄存器
#define BMM_UR1R_STA                (*(u8  volatile xdata *)0xFA3A)//UART12MEM接收状态寄存器
#define BMM_UR1R_AMT                (*(u8  volatile xdata *)0xFA3B)//UART12MEM接收总字节寄存器
#define BMM_UR1R_DONE               (*(u8  volatile xdata *)0xFA3C)//UART12MEM接收完成字节寄存器
#define BMM_UR1R_RXA                (*(u16 volatile xdata *)0xFA3D)//UART12MEM接收发送地址寄存器（16位）
#define BMM_UR1R_RXAH               (*(u8  volatile xdata *)0xFA3D)//UART12MEM接收地址寄存器（高8位）
#define BMM_UR1R_RXAL               (*(u8  volatile xdata *)0xFA3E)//UART12MEM接收地址寄存器（低8位）
/*----------------------------------FA40H~FA4FH----------------------------------*/
#define BMM_UR2T_CFG                (*(u8  volatile xdata *)0xFA40)//UART22MEM发送配置寄存器
#define BMM_UR2T_CR                 (*(u8  volatile xdata *)0xFA41)//UART22MEM发送控制寄存器
#define BMM_UR2T_STA                (*(u8  volatile xdata *)0xFA42)//UART22MEM发送状态寄存器
#define BMM_UR2T_AMT                (*(u8  volatile xdata *)0xFA43)//UART22MEM发送总字节寄存器
#define BMM_UR2T_DONE               (*(u8  volatile xdata *)0xFA44)//UART22MEM发送完成字节寄存器
#define BMM_UR2T_TXA                (*(u16 volatile xdata *)0xFA45)//UART22MEM发送地址寄存器（16位）
#define BMM_UR2T_TXAH               (*(u8  volatile xdata *)0xFA45)//UART22MEM发送地址寄存器（高8位）
#define BMM_UR2T_TXAL               (*(u8  volatile xdata *)0xFA46)//UART22MEM发送地址寄存器（低8位）
#define BMM_UR2R_CFG                (*(u8  volatile xdata *)0xFA48)//UART22MEM接收配置寄存器
#define BMM_UR2R_CR                 (*(u8  volatile xdata *)0xFA49)//UART22MEM接收控制寄存器
#define BMM_UR2R_STA                (*(u8  volatile xdata *)0xFA4A)//UART22MEM接收状态寄存器
#define BMM_UR2R_AMT                (*(u8  volatile xdata *)0xFA4B)//UART22MEM接收总字节寄存器
#define BMM_UR2R_DONE               (*(u8  volatile xdata *)0xFA4C)//UART22MEM接收完成字节寄存器
#define BMM_UR2R_RXA                (*(u16 volatile xdata *)0xFA4D)//UART22MEM接收发送地址寄存器（16位）
#define BMM_UR2R_RXAH               (*(u8  volatile xdata *)0xFA4D)//UART22MEM接收地址寄存器（高8位）
#define BMM_UR2R_RXAL               (*(u8  volatile xdata *)0xFA4E)//UART22MEM接收地址寄存器（低8位）
/*----------------------------------FA50H~FA5FH----------------------------------*/
#define BMM_UR3T_CFG                (*(u8  volatile xdata *)0xFA50)//UART32MEM发送配置寄存器
#define BMM_UR3T_CR                 (*(u8  volatile xdata *)0xFA51)//UART32MEM发送控制寄存器
#define BMM_UR3T_STA                (*(u8  volatile xdata *)0xFA52)//UART32MEM发送状态寄存器
#define BMM_UR3T_AMT                (*(u8  volatile xdata *)0xFA53)//UART32MEM发送总字节寄存器
#define BMM_UR3T_DONE               (*(u8  volatile xdata *)0xFA54)//UART32MEM发送完成字节寄存器
#define BMM_UR3T_TXA                (*(u16 volatile xdata *)0xFA55)//UART32MEM发送地址寄存器（16位）
#define BMM_UR3T_TXAH               (*(u8  volatile xdata *)0xFA55)//UART32MEM发送地址寄存器（高8位）
#define BMM_UR3T_TXAL               (*(u8  volatile xdata *)0xFA56)//UART32MEM发送地址寄存器（低8位）
#define BMM_UR3R_CFG                (*(u8  volatile xdata *)0xFA58)//UART32MEM接收配置寄存器
#define BMM_UR3R_CR                 (*(u8  volatile xdata *)0xFA59)//UART32MEM接收控制寄存器
#define BMM_UR3R_STA                (*(u8  volatile xdata *)0xFA5A)//UART32MEM接收状态寄存器
#define BMM_UR3R_AMT                (*(u8  volatile xdata *)0xFA5B)//UART32MEM接收总字节寄存器
#define BMM_UR3R_DONE               (*(u8  volatile xdata *)0xFA5C)//UART32MEM接收完成字节寄存器
#define BMM_UR3R_RXA                (*(u16 volatile xdata *)0xFA5D)//UART32MEM接收发送地址寄存器（16位）
#define BMM_UR3R_RXAH               (*(u8  volatile xdata *)0xFA5D)//UART32MEM接收地址寄存器（高8位）
#define BMM_UR3R_RXAL               (*(u8  volatile xdata *)0xFA5E)//UART32MEM接收地址寄存器（低8位）
/*----------------------------------FA60H~FA6FH----------------------------------*/
#define BMM_UR4T_CFG                (*(u8  volatile xdata *)0xFA60)//UART42MEM发送配置寄存器
#define BMM_UR4T_CR                 (*(u8  volatile xdata *)0xFA61)//UART42MEM发送控制寄存器
#define BMM_UR4T_STA                (*(u8  volatile xdata *)0xFA62)//UART42MEM发送状态寄存器
#define BMM_UR4T_AMT                (*(u8  volatile xdata *)0xFA63)//UART42MEM发送总字节寄存器
#define BMM_UR4T_DONE               (*(u8  volatile xdata *)0xFA64)//UART42MEM发送完成字节寄存器
#define BMM_UR4T_TXA                (*(u16 volatile xdata *)0xFA65)//UART42MEM发送地址寄存器（16位）
#define BMM_UR4T_TXAH               (*(u8  volatile xdata *)0xFA65)//UART42MEM发送地址寄存器（高8位）
#define BMM_UR4T_TXAL               (*(u8  volatile xdata *)0xFA66)//UART42MEM发送地址寄存器（低8位）
#define BMM_UR4R_CFG                (*(u8  volatile xdata *)0xFA68)//UART42MEM接收配置寄存器
#define BMM_UR4R_CR                 (*(u8  volatile xdata *)0xFA69)//UART42MEM接收控制寄存器
#define BMM_UR4R_STA                (*(u8  volatile xdata *)0xFA6A)//UART42MEM接收状态寄存器
#define BMM_UR4R_AMT                (*(u8  volatile xdata *)0xFA6B)//UART42MEM接收总字节寄存器
#define BMM_UR4R_DONE               (*(u8  volatile xdata *)0xFA6C)//UART42MEM接收完成字节寄存器
#define BMM_UR4R_RXA                (*(u16 volatile xdata *)0xFA6D)//UART42MEM接收发送地址寄存器（16位）
#define BMM_UR4R_RXAH               (*(u8  volatile xdata *)0xFA6D)//UART42MEM接收地址寄存器（高8位）
#define BMM_UR4R_RXAL               (*(u8  volatile xdata *)0xFA6E)//UART42MEM接收地址寄存器（低8位）
/*----------------------------------FA70H~FA7FH----------------------------------*/
#define BMM_LCM_CFG                 (*(u8  volatile xdata *)0xFA70)//LCM_MEM配置寄存器
#define BMM_LCM_CR                  (*(u8  volatile xdata *)0xFA71)//LCM_MEM控制寄存器
#define BMM_LCM_STA                 (*(u8  volatile xdata *)0xFA72)//LCM_MEM状态寄存器
#define BMM_LCM_AMT                 (*(u8  volatile xdata *)0xFA73)//LCM_MEM总字节寄存器
#define BMM_LCM_DONE                (*(u8  volatile xdata *)0xFA74)//LCM_MEM传输完成字节寄存器
#define BMM_LCM_TXA                 (*(u16 volatile xdata *)0xFA75)//LCM_MEM发送地址寄存器（16位）
#define BMM_LCM_TXAH                (*(u8  volatile xdata *)0xFA75)//LCM_MEM发送地址寄存器（高8位）
#define BMM_LCM_TXAL                (*(u8  volatile xdata *)0xFA76)//LCM_MEM发送地址寄存器（低8位）
#define BMM_LCM_RXA                 (*(u16 volatile xdata *)0xFA77)//LCM_MEM接收发送地址寄存器（16位）
#define BMM_LCM_RXAH                (*(u8  volatile xdata *)0xFA77)//LCM_MEM接收地址寄存器（高8位）
#define BMM_LCM_RXAL                (*(u8  volatile xdata *)0xFA78)//LCM_MEM接收地址寄存器（低8位）
/*----------------------------------FC00H~FCEFH----------------------------------*/
#define PWM_P3_C                    (*(u16 volatile xdata *)0xFC00)
#define PWM_P3_CH                   (*(u8  volatile xdata *)0xFC00)
#define PWM_P3_CL                   (*(u8  volatile xdata *)0xFC01)
#define PWM_P3_CKS                  (*(u8  volatile xdata *)0xFC02)
#define PWM_P3_IF                   (*(u8  volatile xdata *)0xFC05)
#define PWM_P3_FDCR                 (*(u8  volatile xdata *)0xFC06)
#define PWM_P30_T1                  (*(u16 volatile xdata *)0xFC10)
#define PWM_P30_T1H                 (*(u8  volatile xdata *)0xFC10)
#define PWM_P30_T1L                 (*(u8  volatile xdata *)0xFC11)
#define PWM_P30_T2                  (*(u16 volatile xdata *)0xFC12)
#define PWM_P30_T2H                 (*(u8  volatile xdata *)0xFC12)
#define PWM_P30_T2L                 (*(u8  volatile xdata *)0xFC13)
#define PWM_P30_CR                  (*(u8  volatile xdata *)0xFC14)
#define PWM_P30_HLD                 (*(u8  volatile xdata *)0xFC15)
#define PWM_P31_T1                  (*(u16 volatile xdata *)0xFC18)
#define PWM_P31_T1H                 (*(u8  volatile xdata *)0xFC18)
#define PWM_P31_T1L                 (*(u8  volatile xdata *)0xFC19)
#define PWM_P31_T2                  (*(u16 volatile xdata *)0xFC1A)
#define PWM_P31_T2H                 (*(u8  volatile xdata *)0xFC1A)
#define PWM_P31_T2L                 (*(u8  volatile xdata *)0xFC1B)
#define PWM_P31_CR                  (*(u8  volatile xdata *)0xFC1C)
#define PWM_P31_HLD                 (*(u8  volatile xdata *)0xFC1D)
#define PWM_P32_T1                  (*(u16 volatile xdata *)0xFC20)
#define PWM_P32_T1H                 (*(u8  volatile xdata *)0xFC20)
#define PWM_P32_T1L                 (*(u8  volatile xdata *)0xFC21)
#define PWM_P32_T2                  (*(u16 volatile xdata *)0xFC22)
#define PWM_P32_T2H                 (*(u8  volatile xdata *)0xFC22)
#define PWM_P32_T2L                 (*(u8  volatile xdata *)0xFC23)
#define PWM_P32_CR                  (*(u8  volatile xdata *)0xFC24)
#define PWM_P32_HLD                 (*(u8  volatile xdata *)0xFC25)
#define PWM_P33_T1                  (*(u16 volatile xdata *)0xFC28)
#define PWM_P33_T1H                 (*(u8  volatile xdata *)0xFC28)
#define PWM_P33_T1L                 (*(u8  volatile xdata *)0xFC29)
#define PWM_P33_T2                  (*(u16 volatile xdata *)0xFC2A)
#define PWM_P33_T2H                 (*(u8  volatile xdata *)0xFC2A)
#define PWM_P33_T2L                 (*(u8  volatile xdata *)0xFC2B)
#define PWM_P33_CR                  (*(u8  volatile xdata *)0xFC2C)
#define PWM_P33_HLD                 (*(u8  volatile xdata *)0xFC2D)
#define PWM_P34_T1                  (*(u16 volatile xdata *)0xFC30)
#define PWM_P34_T1H                 (*(u8  volatile xdata *)0xFC30)
#define PWM_P34_T1L                 (*(u8  volatile xdata *)0xFC31)
#define PWM_P34_T2                  (*(u16 volatile xdata *)0xFC32)
#define PWM_P34_T2H                 (*(u8  volatile xdata *)0xFC32)
#define PWM_P34_T2L                 (*(u8  volatile xdata *)0xFC33)
#define PWM_P34_CR                  (*(u8  volatile xdata *)0xFC34)
#define PWM_P34_HLD                 (*(u8  volatile xdata *)0xFC35)
#define PWM_P35_T1                  (*(u16 volatile xdata *)0xFC38)
#define PWM_P35_T1H                 (*(u8  volatile xdata *)0xFC38)
#define PWM_P35_T1L                 (*(u8  volatile xdata *)0xFC39)
#define PWM_P35_T2                  (*(u16 volatile xdata *)0xFC3A)
#define PWM_P35_T2H                 (*(u8  volatile xdata *)0xFC3A)
#define PWM_P35_T2L                 (*(u8  volatile xdata *)0xFC3B)
#define PWM_P35_CR                  (*(u8  volatile xdata *)0xFC3C)
#define PWM_P35_HLD                 (*(u8  volatile xdata *)0xFC3D)
#define PWM_P36_T1                  (*(u16 volatile xdata *)0xFC40)
#define PWM_P36_T1H                 (*(u8  volatile xdata *)0xFC40)
#define PWM_P36_T1L                 (*(u8  volatile xdata *)0xFC41)
#define PWM_P36_T2                  (*(u16 volatile xdata *)0xFC42)
#define PWM_P36_T2H                 (*(u8  volatile xdata *)0xFC42)
#define PWM_P36_T2L                 (*(u8  volatile xdata *)0xFC43)
#define PWM_P36_CR                  (*(u8  volatile xdata *)0xFC44)
#define PWM_P36_HLD                 (*(u8  volatile xdata *)0xFC45)
#define PWM_P37_T1                  (*(u16 volatile xdata *)0xFC48)
#define PWM_P37_T1H                 (*(u8  volatile xdata *)0xFC48)
#define PWM_P37_T1L                 (*(u8  volatile xdata *)0xFC49)
#define PWM_P37_T2                  (*(u16 volatile xdata *)0xFC4A)
#define PWM_P37_T2H                 (*(u8  volatile xdata *)0xFC4A)
#define PWM_P37_T2L                 (*(u8  volatile xdata *)0xFC4B)
#define PWM_P37_CR                  (*(u8  volatile xdata *)0xFC4C)
#define PWM_P37_HLD                 (*(u8  volatile xdata *)0xFC4D)
#define PWM_P4_C                    (*(u16 volatile xdata *)0xFC50)
#define PWM_P4_CH                   (*(u8  volatile xdata *)0xFC50)
#define PWM_P4_CL                   (*(u8  volatile xdata *)0xFC51)
#define PWM_P4_CKS                  (*(u8  volatile xdata *)0xFC52)
#define PWM_P4_TADC                 (*(u16 volatile xdata *)0xFC53)
#define PWM_P4_TADCH                (*(u8  volatile xdata *)0xFC53)
#define PWM_P4_TADCL                (*(u8  volatile xdata *)0xFC54)
#define PWM_P4_IF                   (*(u8  volatile xdata *)0xFC55)
#define PWM_P4_FDCR                 (*(u8  volatile xdata *)0xFC56)
#define PWM_P40_T1                  (*(u16 volatile xdata *)0xFC60)
#define PWM_P40_T1H                 (*(u8  volatile xdata *)0xFC60)
#define PWM_P40_T1L                 (*(u8  volatile xdata *)0xFC61)
#define PWM_P40_T2                  (*(u16 volatile xdata *)0xFC62)
#define PWM_P40_T2H                 (*(u8  volatile xdata *)0xFC62)
#define PWM_P40_T2L                 (*(u8  volatile xdata *)0xFC63)
#define PWM_P40_CR                  (*(u8  volatile xdata *)0xFC64)
#define PWM_P40_HLD                 (*(u8  volatile xdata *)0xFC65)
#define PWM_P41_T1                  (*(u16 volatile xdata *)0xFC68)
#define PWM_P41_T1H                 (*(u8  volatile xdata *)0xFC68)
#define PWM_P41_T1L                 (*(u8  volatile xdata *)0xFC69)
#define PWM_P41_T2                  (*(u16 volatile xdata *)0xFC6A)
#define PWM_P41_T2H                 (*(u8  volatile xdata *)0xFC6A)
#define PWM_P41_T2L                 (*(u8  volatile xdata *)0xFC6B)
#define PWM_P41_CR                  (*(u8  volatile xdata *)0xFC6C)
#define PWM_P41_HLD                 (*(u8  volatile xdata *)0xFC6D)
#define PWM_P42_T1                  (*(u16 volatile xdata *)0xFC70)
#define PWM_P42_T1H                 (*(u8  volatile xdata *)0xFC70)
#define PWM_P42_T1L                 (*(u8  volatile xdata *)0xFC71)
#define PWM_P42_T2                  (*(u16 volatile xdata *)0xFC72)
#define PWM_P42_T2H                 (*(u8  volatile xdata *)0xFC72)
#define PWM_P42_T2L                 (*(u8  volatile xdata *)0xFC73)
#define PWM_P42_CR                  (*(u8  volatile xdata *)0xFC74)
#define PWM_P42_HLD                 (*(u8  volatile xdata *)0xFC75)
#define PWM_P43_T1                  (*(u16 volatile xdata *)0xFC78)
#define PWM_P43_T1H                 (*(u8  volatile xdata *)0xFC78)
#define PWM_P43_T1L                 (*(u8  volatile xdata *)0xFC79)
#define PWM_P43_T2                  (*(u16 volatile xdata *)0xFC7A)
#define PWM_P43_T2H                 (*(u8  volatile xdata *)0xFC7A)
#define PWM_P43_T2L                 (*(u8  volatile xdata *)0xFC7B)
#define PWM_P43_CR                  (*(u8  volatile xdata *)0xFC7C)
#define PWM_P43_HLD                 (*(u8  volatile xdata *)0xFC7D)
#define PWM_P44_T1                  (*(u16 volatile xdata *)0xFC80)
#define PWM_P44_T1H                 (*(u8  volatile xdata *)0xFC80)
#define PWM_P44_T1L                 (*(u8  volatile xdata *)0xFC81)
#define PWM_P44_T2                  (*(u16 volatile xdata *)0xFC82)
#define PWM_P44_T2H                 (*(u8  volatile xdata *)0xFC82)
#define PWM_P44_T2L                 (*(u8  volatile xdata *)0xFC83)
#define PWM_P44_CR                  (*(u8  volatile xdata *)0xFC84)
#define PWM_P44_HLD                 (*(u8  volatile xdata *)0xFC85)
#define PWM_P45_T1                  (*(u16 volatile xdata *)0xFC88)
#define PWM_P45_T1H                 (*(u8  volatile xdata *)0xFC88)
#define PWM_P45_T1L                 (*(u8  volatile xdata *)0xFC89)
#define PWM_P45_T2                  (*(u16 volatile xdata *)0xFC8A)
#define PWM_P45_T2H                 (*(u8  volatile xdata *)0xFC8A)
#define PWM_P45_T2L                 (*(u8  volatile xdata *)0xFC8B)
#define PWM_P45_CR                  (*(u8  volatile xdata *)0xFC8C)
#define PWM_P45_HLD                 (*(u8  volatile xdata *)0xFC8D)
#define PWM_P46_T1                  (*(u16 volatile xdata *)0xFC90)
#define PWM_P46_T1H                 (*(u8  volatile xdata *)0xFC90)
#define PWM_P46_T1L                 (*(u8  volatile xdata *)0xFC91)
#define PWM_P46_T2                  (*(u16 volatile xdata *)0xFC92)
#define PWM_P46_T2H                 (*(u8  volatile xdata *)0xFC92)
#define PWM_P46_T2L                 (*(u8  volatile xdata *)0xFC93)
#define PWM_P46_CR                  (*(u8  volatile xdata *)0xFC94)
#define PWM_P46_HLD                 (*(u8  volatile xdata *)0xFC95)
#define PWM_P47_T1                  (*(u16 volatile xdata *)0xFC98)
#define PWM_P47_T1H                 (*(u8  volatile xdata *)0xFC98)
#define PWM_P47_T1L                 (*(u8  volatile xdata *)0xFC99)
#define PWM_P47_T2                  (*(u16 volatile xdata *)0xFC9A)
#define PWM_P47_T2H                 (*(u8  volatile xdata *)0xFC9A)
#define PWM_P47_T2L                 (*(u8  volatile xdata *)0xFC9B)
#define PWM_P47_CR                  (*(u8  volatile xdata *)0xFC9C)
#define PWM_P47_HLD                 (*(u8  volatile xdata *)0xFC9D)
#define PWM_P5_C                    (*(u16 volatile xdata *)0xFCA0)
#define PWM_P5_CH                   (*(u8  volatile xdata *)0xFCA0)
#define PWM_P5_CL                   (*(u8  volatile xdata *)0xFCA1)
#define PWM_P5_CKS                  (*(u8  volatile xdata *)0xFCA2)
#define PWM_P5_IF                   (*(u8  volatile xdata *)0xFCA5)
#define PWM_P5_FDCR                 (*(u8  volatile xdata *)0xFCA6)
#define PWM_P50_T1                  (*(u16 volatile xdata *)0xFCB0)
#define PWM_P50_T1H                 (*(u8  volatile xdata *)0xFCB0)
#define PWM_P50_T1L                 (*(u8  volatile xdata *)0xFCB1)
#define PWM_P50_T2                  (*(u16 volatile xdata *)0xFCB2)
#define PWM_P50_T2H                 (*(u8  volatile xdata *)0xFCB2)
#define PWM_P50_T2L                 (*(u8  volatile xdata *)0xFCB3)
#define PWM_P50_CR                  (*(u8  volatile xdata *)0xFCB4)
#define PWM_P50_HLD                 (*(u8  volatile xdata *)0xFCB5)
#define PWM_P51_T1                  (*(u16 volatile xdata *)0xFCB8)
#define PWM_P51_T1H                 (*(u8  volatile xdata *)0xFCB8)
#define PWM_P51_T1L                 (*(u8  volatile xdata *)0xFCB9)
#define PWM_P51_T2                  (*(u16 volatile xdata *)0xFCBA)
#define PWM_P51_T2H                 (*(u8  volatile xdata *)0xFCBA)
#define PWM_P51_T2L                 (*(u8  volatile xdata *)0xFCBB)
#define PWM_P51_CR                  (*(u8  volatile xdata *)0xFCBC)
#define PWM_P51_HLD                 (*(u8  volatile xdata *)0xFCBD)
#define PWM_P52_T1                  (*(u16 volatile xdata *)0xFCC0)
#define PWM_P52_T1H                 (*(u8  volatile xdata *)0xFCC0)
#define PWM_P52_T1L                 (*(u8  volatile xdata *)0xFCC1)
#define PWM_P52_T2                  (*(u16 volatile xdata *)0xFCC2)
#define PWM_P52_T2H                 (*(u8  volatile xdata *)0xFCC2)
#define PWM_P52_T2L                 (*(u8  volatile xdata *)0xFCC3)
#define PWM_P52_CR                  (*(u8  volatile xdata *)0xFCC4)
#define PWM_P52_HLD                 (*(u8  volatile xdata *)0xFCC5)
#define PWM_P53_T1                  (*(u16 volatile xdata *)0xFCC8)
#define PWM_P53_T1H                 (*(u8  volatile xdata *)0xFCC8)
#define PWM_P53_T1L                 (*(u8  volatile xdata *)0xFCC9)
#define PWM_P53_T2                  (*(u16 volatile xdata *)0xFCCA)
#define PWM_P53_T2H                 (*(u8  volatile xdata *)0xFCCA)
#define PWM_P53_T2L                 (*(u8  volatile xdata *)0xFCCB)
#define PWM_P53_CR                  (*(u8  volatile xdata *)0xFCCC)
#define PWM_P53_HLD                 (*(u8  volatile xdata *)0xFCCD)
#define PWM_P54_T1                  (*(u16 volatile xdata *)0xFCD0)
#define PWM_P54_T1H                 (*(u8  volatile xdata *)0xFCD0)
#define PWM_P54_T1L                 (*(u8  volatile xdata *)0xFCD1)
#define PWM_P54_T2                  (*(u16 volatile xdata *)0xFCD2)
#define PWM_P54_T2H                 (*(u8  volatile xdata *)0xFCD2)
#define PWM_P54_T2L                 (*(u8  volatile xdata *)0xFCD3)
#define PWM_P54_CR                  (*(u8  volatile xdata *)0xFCD4)
#define PWM_P54_HLD                 (*(u8  volatile xdata *)0xFCD5)
#define PWM_P55_T1                  (*(u16 volatile xdata *)0xFCD8)
#define PWM_P55_T1H                 (*(u8  volatile xdata *)0xFCD8)
#define PWM_P55_T1L                 (*(u8  volatile xdata *)0xFCD9)
#define PWM_P55_T2                  (*(u16 volatile xdata *)0xFCDA)
#define PWM_P55_T2H                 (*(u8  volatile xdata *)0xFCDA)
#define PWM_P55_T2L                 (*(u8  volatile xdata *)0xFCDB)
#define PWM_P55_CR                  (*(u8  volatile xdata *)0xFCDC)
#define PWM_P55_HLD                 (*(u8  volatile xdata *)0xFCDD)
#define PWM_P56_T1                  (*(u16 volatile xdata *)0xFCE0)
#define PWM_P56_T1H                 (*(u8  volatile xdata *)0xFCE0)
#define PWM_P56_T1L                 (*(u8  volatile xdata *)0xFCE1)
#define PWM_P56_T2                  (*(u16 volatile xdata *)0xFCE2)
#define PWM_P56_T2H                 (*(u8  volatile xdata *)0xFCE2)
#define PWM_P56_T2L                 (*(u8  volatile xdata *)0xFCE3)
#define PWM_P56_CR                  (*(u8  volatile xdata *)0xFCE4)
#define PWM_P56_HLD                 (*(u8  volatile xdata *)0xFCE5)
#define PWM_P57_T1                  (*(u16 volatile xdata *)0xFCE8)
#define PWM_P57_T1H                 (*(u8  volatile xdata *)0xFCE8)
#define PWM_P57_T1L                 (*(u8  volatile xdata *)0xFCE9)
#define PWM_P57_T2                  (*(u16 volatile xdata *)0xFCEA)
#define PWM_P57_T2H                 (*(u8  volatile xdata *)0xFCEA)
#define PWM_P57_T2L                 (*(u8  volatile xdata *)0xFCEB)
#define PWM_P57_CR                  (*(u8  volatile xdata *)0xFCEC)
#define PWM_P57_HLD                 (*(u8  volatile xdata *)0xFCED)
/*----------------------------------FCF0H~FCF7H----------------------------------*/
#define MD3MD2MD1MD0                (*(u32 volatile xdata *)0xFCF0)//一般用来存放32位被除数、32位商、积。
#define MD1MD0                      (*(u16 volatile xdata *)0xFCF2)//一般用来存放16位被除数、16位商、16位被乘数。
#define MD5MD4                      (*(u16 volatile xdata *)0xFCF4)//一般用来存放除数、余数、乘数。
#define ARCON                       (*(u8  volatile xdata *)0xFCF6)//MDU模式控制寄存器
#define OPCON                       (*(u8  volatile xdata *)0xFCF7)//MDU操作控制寄存器
/*----------------------------------FE00H~FE07H----------------------------------*/
#define CKSEL                       (*(u8  volatile xdata *)0xFE00)//时钟选择寄存器
#define CLKDIV                      (*(u8  volatile xdata *)0xFE01)//时钟分频寄存器
#define HIRCCR                      (*(u8  volatile xdata *)0xFE02)//内部高速振荡器控制寄存器
#define XOSCCR                      (*(u8  volatile xdata *)0xFE03)//外部晶振控制寄存器
#define IRC32KCR                    (*(u8  volatile xdata *)0xFE04)//内部32K振荡器控制寄存器
#define MCLKOCR                     (*(u8  volatile xdata *)0xFE05)//主时钟输出控制寄存器
#define IRCDB                       (*(u8  volatile xdata *)0xFE06)//内部高速振荡器去抖控制寄存器
#define IRC48MCR                    (*(u8  volatile xdata *)0xFE07)//内部48M振荡器控制寄存器
/*----------------------------------FE08H~FE0FH----------------------------------*/
#define X32KCR                      (*(u8  volatile xdata *)0xFE08)//外部32K振荡器控制寄存器
/*----------------------------------FE10H~FE17H----------------------------------*/
#define P0PU                        (*(u8  volatile xdata *)0xFE10)//P0口上拉电阻控制寄存器
#define P1PU                        (*(u8  volatile xdata *)0xFE11)//P1口上拉电阻控制寄存器
#define P2PU                        (*(u8  volatile xdata *)0xFE12)//P2口上拉电阻控制寄存器
#define P3PU                        (*(u8  volatile xdata *)0xFE13)//P3口上拉电阻控制寄存器
#define P4PU                        (*(u8  volatile xdata *)0xFE14)//P4口上拉电阻控制寄存器
#define P5PU                        (*(u8  volatile xdata *)0xFE15)//P5口上拉电阻控制寄存器
#define P6PU                        (*(u8  volatile xdata *)0xFE16)//P6口上拉电阻控制寄存器
#define P7PU                        (*(u8  volatile xdata *)0xFE17)//P7口上拉电阻控制寄存器
/*----------------------------------FE18H~FE1FH----------------------------------*/
#define P0NCS                       (*(u8  volatile xdata *)0xFE18)//P0口施密特触发控制寄存器
#define P1NCS                       (*(u8  volatile xdata *)0xFE19)//P1口施密特触发控制寄存器
#define P2NCS                       (*(u8  volatile xdata *)0xFE1A)//P2口施密特触发控制寄存器
#define P3NCS                       (*(u8  volatile xdata *)0xFE1B)//P3口施密特触发控制寄存器
#define P4NCS                       (*(u8  volatile xdata *)0xFE1C)//P4口施密特触发控制寄存器
#define P5NCS                       (*(u8  volatile xdata *)0xFE1D)//P5口施密特触发控制寄存器
#define P6NCS                       (*(u8  volatile xdata *)0xFE1E)//P6口施密特触发控制寄存器
#define P7NCS                       (*(u8  volatile xdata *)0xFE1F)//P7口施密特触发控制寄存器
/*----------------------------------FE20H~FE27H----------------------------------*/
#define P0SR                        (*(u8  volatile xdata *)0xFE20)//P0口电平转换速度控制寄存器
#define P1SR                        (*(u8  volatile xdata *)0xFE21)//P1口电平转换速度控制寄存器
#define P2SR                        (*(u8  volatile xdata *)0xFE22)//P2口电平转换速度控制寄存器
#define P3SR                        (*(u8  volatile xdata *)0xFE23)//P3口电平转换速度控制寄存器
#define P4SR                        (*(u8  volatile xdata *)0xFE24)//P4口电平转换速度控制寄存器
#define P5SR                        (*(u8  volatile xdata *)0xFE25)//P5口电平转换速度控制寄存器
#define P6SR                        (*(u8  volatile xdata *)0xFE26)//P6口电平转换速度控制寄存器
#define P7SR                        (*(u8  volatile xdata *)0xFE27)//P7口电平转换速度控制寄存器
/*----------------------------------FE28H~FE2FH----------------------------------*/
#define P0DR                        (*(u8  volatile xdata *)0xFE28)//P0口驱动电流控制寄存器
#define P1DR                        (*(u8  volatile xdata *)0xFE29)//P1口驱动电流控制寄存器
#define P2DR                        (*(u8  volatile xdata *)0xFE2A)//P2口驱动电流控制寄存器
#define P3DR                        (*(u8  volatile xdata *)0xFE2B)//P3口驱动电流控制寄存器
#define P4DR                        (*(u8  volatile xdata *)0xFE2C)//P4口驱动电流控制寄存器
#define P5DR                        (*(u8  volatile xdata *)0xFE2D)//P5口驱动电流控制寄存器
#define P6DR                        (*(u8  volatile xdata *)0xFE2E)//P6口驱动电流控制寄存器
#define P7DR                        (*(u8  volatile xdata *)0xFE2F)//P7口驱动电流控制寄存器
/*----------------------------------FE30H~FE37H----------------------------------*/
#define P0IE                        (*(u8  volatile xdata *)0xFE30)//P0口数字信号输入使能控制寄存器
#define P1IE                        (*(u8  volatile xdata *)0xFE31)//P1口数字信号输入使能控制寄存器
#define P2IE                        (*(u8  volatile xdata *)0xFE32)//P2口数字信号输入使能控制寄存器
#define P3IE                        (*(u8  volatile xdata *)0xFE33)//P3口数字信号输入使能控制寄存器
#define P4IE                        (*(u8  volatile xdata *)0xFE34)//P4口数字信号输入使能控制寄存器
#define P5IE                        (*(u8  volatile xdata *)0xFE35)//P5口数字信号输入使能控制寄存器
#define P6IE                        (*(u8  volatile xdata *)0xFE36)//P6口数字信号输入使能控制寄存器
#define P7IE                        (*(u8  volatile xdata *)0xFE37)//P7口数字信号输入使能控制寄存器

/*----------------------------------FE50H~FE57H----------------------------------*/
#define LCMIFCFG                    (*(u8  volatile xdata *)0xFE50)//LCM接口配置寄存器
#define LCMIFCFG2                   (*(u8  volatile xdata *)0xFE51)//LCM接口配置寄存器2
#define LCMIFCR                     (*(u8  volatile xdata *)0xFE52)//LCM接口控制寄存器
#define LCMIFSTA                    (*(u8  volatile xdata *)0xFE53)//LCM接口状态寄存器
#define LCMIFDATL                   (*(u8  volatile xdata *)0xFE54)//LCM接口低字节数据
#define LCMIFDATH                   (*(u8  volatile xdata *)0xFE55)//LCM接口高字节数据

/*----------------------------------FE60H~FE77H----------------------------------*/
#define RTCCR                       (*(u8  volatile xdata *)0xFE60)
#define RTCCFG                      (*(u8  volatile xdata *)0xFE61)
#define RTCIEN                      (*(u8  volatile xdata *)0xFE62)
#define RTCIF                       (*(u8  volatile xdata *)0xFE63)
#define ALAHOUR                     (*(u8  volatile xdata *)0xFE64)
#define ALAMIN                      (*(u8  volatile xdata *)0xFE65)
#define ALASEC                      (*(u8  volatile xdata *)0xFE66)
#define ALASSEC                     (*(u8  volatile xdata *)0xFE67)
#define INIYEAR                     (*(u8  volatile xdata *)0xFE68)
#define INIMONTH                    (*(u8  volatile xdata *)0xFE69)
#define INIDAY                      (*(u8  volatile xdata *)0xFE6A)
#define INIHOUR                     (*(u8  volatile xdata *)0xFE6B)
#define INIMIN                      (*(u8  volatile xdata *)0xFE6C)
#define INISEC                      (*(u8  volatile xdata *)0xFE6D)
#define INISSEC                     (*(u8  volatile xdata *)0xFE6E)
#define YEAR                        (*(u8  volatile xdata *)0xFE70)
#define MONTH                       (*(u8  volatile xdata *)0xFE71)
#define DAY                         (*(u8  volatile xdata *)0xFE72)
#define HOUR                        (*(u8  volatile xdata *)0xFE73)
#define MIN                         (*(u8  volatile xdata *)0xFE74)
#define SEC                         (*(u8  volatile xdata *)0xFE75)
#define SSEC                        (*(u8  volatile xdata *)0xFE76)

/*----------------------------------FE80H~FE8FH----------------------------------*/
#define I2CCFG                      (*(u8  volatile xdata *)0xFE80)//IIC配置寄存器
#define I2CMSCR                     (*(u8  volatile xdata *)0xFE81)//IIC主机控制寄存器
#define I2CMSST                     (*(u8  volatile xdata *)0xFE82)//IIC主机状态寄存器
#define I2CSLCR                     (*(u8  volatile xdata *)0xFE83)//IIC从机控制寄存器
#define I2CSLST                     (*(u8  volatile xdata *)0xFE84)//IIC从机状态寄存器
#define I2CSLADR                    (*(u8  volatile xdata *)0xFE85)//IIC从机地址寄存器
#define I2CTXD                      (*(u8  volatile xdata *)0xFE86)//IIC发送数据寄存器
#define I2CRXD                      (*(u8  volatile xdata *)0xFE87)//IIC接收数据寄存器
#define I2CMSAUX                    (*(u8  volatile xdata *)0xFE88)//IIC主机辅助控制寄存器
/*----------------------------------FEA8H~FEAFH----------------------------------*/
#define ADC_TIM                     (*(u8  volatile xdata *)0xFEA8)//ADC时序控制寄存器
#define ADCEXCFG                    (*(u8  volatile xdata *)0xFEAD)//ADC扩展配置寄存器
#define CMPEXCFG                    (*(u8  volatile xdata *)0xFEAE)//CMP扩展配置寄存器
/*----------------------------------FEB0H~FEFFH----------------------------------*/
#define PWMA_ETRPS                  (*(u8  volatile xdata *)0xFEB0)
#define PWMA_ENO                    (*(u8  volatile xdata *)0xFEB1)
#define PWMA_PS                     (*(u8  volatile xdata *)0xFEB2)
#define PWMA_IOAUX                  (*(u8  volatile xdata *)0xFEB3)
#define PWMB_ETRPS                  (*(u8  volatile xdata *)0xFEB4)
#define PWMB_ENO                    (*(u8  volatile xdata *)0xFEB5)
#define PWMB_PS                     (*(u8  volatile xdata *)0xFEB6)
#define PWMB_IOAUX                  (*(u8  volatile xdata *)0xFEB7)
#define PWMA_CR1                    (*(u8  volatile xdata *)0xFEC0)
#define PWMA_CR2                    (*(u8  volatile xdata *)0xFEC1)
#define PWMA_SMCR                   (*(u8  volatile xdata *)0xFEC2)
#define PWMA_ETR                    (*(u8  volatile xdata *)0xFEC3)
#define PWMA_IER                    (*(u8  volatile xdata *)0xFEC4)
#define PWMA_SR1                    (*(u8  volatile xdata *)0xFEC5)
#define PWMA_SR2                    (*(u8  volatile xdata *)0xFEC6)
#define PWMA_EGR                    (*(u8  volatile xdata *)0xFEC7)
#define PWMA_CCMR1                  (*(u8  volatile xdata *)0xFEC8)
#define PWMA_CCMR2                  (*(u8  volatile xdata *)0xFEC9)
#define PWMA_CCMR3                  (*(u8  volatile xdata *)0xFECA)
#define PWMA_CCMR4                  (*(u8  volatile xdata *)0xFECB)
#define PWMA_CCER1                  (*(u8  volatile xdata *)0xFECC)
#define PWMA_CCER2                  (*(u8  volatile xdata *)0xFECD)
#define PWMA_CNTR                   (*(u16 volatile xdata *)0xFECE)
#define PWMA_CNTRH                  (*(u8  volatile xdata *)0xFECE)
#define PWMA_CNTRL                  (*(u8  volatile xdata *)0xFECF)
#define PWMA_PSCR                   (*(u16 volatile xdata *)0xFED0)
#define PWMA_PSCRH                  (*(u8  volatile xdata *)0xFED0)
#define PWMA_PSCRL                  (*(u8  volatile xdata *)0xFED1)
#define PWMA_ARR                    (*(u16 volatile xdata *)0xFED2)
#define PWMA_ARRH                   (*(u8  volatile xdata *)0xFED2)
#define PWMA_ARRL                   (*(u8  volatile xdata *)0xFED3)
#define PWMA_RCR                    (*(u8  volatile xdata *)0xFED4)
#define PWMA_CCR1                   (*(u16 volatile xdata *)0xFED5)
#define PWMA_CCR1H                  (*(u8  volatile xdata *)0xFED5)
#define PWMA_CCR1L                  (*(u8  volatile xdata *)0xFED6)
#define PWMA_CCR2                   (*(u16 volatile xdata *)0xFED7)
#define PWMA_CCR2H                  (*(u8  volatile xdata *)0xFED7)
#define PWMA_CCR2L                  (*(u8  volatile xdata *)0xFED8)
#define PWMA_CCR3                   (*(u16 volatile xdata *)0xFED9)
#define PWMA_CCR3H                  (*(u8  volatile xdata *)0xFED9)
#define PWMA_CCR3L                  (*(u8  volatile xdata *)0xFEDA)
#define PWMA_CCR4                   (*(u16 volatile xdata *)0xFEDB)
#define PWMA_CCR4H                  (*(u8  volatile xdata *)0xFEDB)
#define PWMA_CCR4L                  (*(u8  volatile xdata *)0xFEDC)
#define PWMA_BKR                    (*(u8  volatile xdata *)0xFEDD)
#define PWMA_DTR                    (*(u8  volatile xdata *)0xFEDE)
#define PWMA_OISR                   (*(u8  volatile xdata *)0xFEDF)
#define PWMB_CR1                    (*(u8  volatile xdata *)0xFEE0)
#define PWMB_CR2                    (*(u8  volatile xdata *)0xFEE1)
#define PWMB_SMCR                   (*(u8  volatile xdata *)0xFEE2)
#define PWMB_ETR                    (*(u8  volatile xdata *)0xFEE3)
#define PWMB_IER                    (*(u8  volatile xdata *)0xFEE4)
#define PWMB_SR1                    (*(u8  volatile xdata *)0xFEE5)
#define PWMB_SR2                    (*(u8  volatile xdata *)0xFEE6)
#define PWMB_EGR                    (*(u8  volatile xdata *)0xFEE7)
#define PWMB_CCMR1                  (*(u8  volatile xdata *)0xFEE8)
#define PWMB_CCMR2                  (*(u8  volatile xdata *)0xFEE9)
#define PWMB_CCMR3                  (*(u8  volatile xdata *)0xFEEA)
#define PWMB_CCMR4                  (*(u8  volatile xdata *)0xFEEB)
#define PWMB_CCER1                  (*(u8  volatile xdata *)0xFEEC)
#define PWMB_CCER2                  (*(u8  volatile xdata *)0xFEED)
#define PWMB_CNTR                   (*(u16 volatile xdata *)0xFEEE)
#define PWMB_CNTRH                  (*(u8  volatile xdata *)0xFEEE)
#define PWMB_CNTRL                  (*(u8  volatile xdata *)0xFEEF)
#define PWMB_PSCR                   (*(u16 volatile xdata *)0xFEF0)
#define PWMB_PSCRH                  (*(u8  volatile xdata *)0xFEF0)
#define PWMB_PSCRL                  (*(u8  volatile xdata *)0xFEF1)
#define PWMB_ARR                    (*(u16 volatile xdata *)0xFEF2)
#define PWMB_ARRH                   (*(u8  volatile xdata *)0xFEF2)
#define PWMB_ARRL                   (*(u8  volatile xdata *)0xFEF3)
#define PWMB_RCR                    (*(u8  volatile xdata *)0xFEF4)
#define PWMB_CCR5                   (*(u16 volatile xdata *)0xFEF5)
#define PWMB_CCR5H                  (*(u8  volatile xdata *)0xFEF5)
#define PWMB_CCR5L                  (*(u8  volatile xdata *)0xFEF6)
#define PWMB_CCR6                   (*(u16 volatile xdata *)0xFEF7)
#define PWMB_CCR6H                  (*(u8  volatile xdata *)0xFEF7)
#define PWMB_CCR6L                  (*(u8  volatile xdata *)0xFEF8)
#define PWMB_CCR7                   (*(u16 volatile xdata *)0xFEF9)
#define PWMB_CCR7H                  (*(u8  volatile xdata *)0xFEF9)
#define PWMB_CCR7L                  (*(u8  volatile xdata *)0xFEFA)
#define PWMB_CCR8                   (*(u16 volatile xdata *)0xFEFB)
#define PWMB_CCR8H                  (*(u8  volatile xdata *)0xFEFB)
#define PWMB_CCR8L                  (*(u8  volatile xdata *)0xFEFC)
#define PWMB_BKR                    (*(u8  volatile xdata *)0xFEFD)
#define PWMB_DTR                    (*(u8  volatile xdata *)0xFEFE)
#define PWMB_OISR                   (*(u8  volatile xdata *)0xFEFF)
/*----------------------------------FF00H~FE37H----------------------------------*/
#define PWM_P0_C                    (*(u16 volatile xdata *)0xFF00)
#define PWM_P0_CH                   (*(u8  volatile xdata *)0xFF00)
#define PWM_P0_CL                   (*(u8  volatile xdata *)0xFF01)
#define PWM_P0_CKS                  (*(u8  volatile xdata *)0xFF02)
#define PWM_P0_TADC                 (*(u16 volatile xdata *)0xFF03)
#define PWM_P0_TADCH                (*(u8  volatile xdata *)0xFF03)
#define PWM_P0_TADCL                (*(u8  volatile xdata *)0xFF04)
#define PWM_P0_IF                   (*(u8  volatile xdata *)0xFF05)
#define PWM_P0_FDCR                 (*(u8  volatile xdata *)0xFF06)
#define PWM_P00_T1                  (*(u16 volatile xdata *)0xFF10)
#define PWM_P00_T1H                 (*(u8  volatile xdata *)0xFF10)
#define PWM_P00_T1L                 (*(u8  volatile xdata *)0xFF11)
#define PWM_P00_T2                  (*(u16 volatile xdata *)0xFF12)
#define PWM_P00_T2H                 (*(u8  volatile xdata *)0xFF12)
#define PWM_P00_T2L                 (*(u8  volatile xdata *)0xFF13)
#define PWM_P00_CR                  (*(u8  volatile xdata *)0xFF14)
#define PWM_P00_HLD                 (*(u8  volatile xdata *)0xFF15)
#define PWM_P01_T1                  (*(u16 volatile xdata *)0xFF18)
#define PWM_P01_T1H                 (*(u8  volatile xdata *)0xFF18)
#define PWM_P01_T1L                 (*(u8  volatile xdata *)0xFF19)
#define PWM_P01_T2                  (*(u16 volatile xdata *)0xFF1A)
#define PWM_P01_T2H                 (*(u8  volatile xdata *)0xFF1A)
#define PWM_P01_T2L                 (*(u8  volatile xdata *)0xFF1B)
#define PWM_P01_CR                  (*(u8  volatile xdata *)0xFF1C)
#define PWM_P01_HLD                 (*(u8  volatile xdata *)0xFF1D)
#define PWM_P02_T1                  (*(u16 volatile xdata *)0xFF20)
#define PWM_P02_T1H                 (*(u8  volatile xdata *)0xFF20)
#define PWM_P02_T1L                 (*(u8  volatile xdata *)0xFF21)
#define PWM_P02_T2                  (*(u16 volatile xdata *)0xFF22)
#define PWM_P02_T2H                 (*(u8  volatile xdata *)0xFF22)
#define PWM_P02_T2L                 (*(u8  volatile xdata *)0xFF23)
#define PWM_P02_CR                  (*(u8  volatile xdata *)0xFF24)
#define PWM_P02_HLD                 (*(u8  volatile xdata *)0xFF25)
#define PWM_P03_T1                  (*(u16 volatile xdata *)0xFF28)
#define PWM_P03_T1H                 (*(u8  volatile xdata *)0xFF28)
#define PWM_P03_T1L                 (*(u8  volatile xdata *)0xFF29)
#define PWM_P03_T2                  (*(u16 volatile xdata *)0xFF2A)
#define PWM_P03_T2H                 (*(u8  volatile xdata *)0xFF2A)
#define PWM_P03_T2L                 (*(u8  volatile xdata *)0xFF2B)
#define PWM_P03_CR                  (*(u8  volatile xdata *)0xFF2C)
#define PWM_P03_HLD                 (*(u8  volatile xdata *)0xFF2D)
#define PWM_P04_T1                  (*(u16 volatile xdata *)0xFF30)
#define PWM_P04_T1H                 (*(u8  volatile xdata *)0xFF30)
#define PWM_P04_T1L                 (*(u8  volatile xdata *)0xFF31)
#define PWM_P04_T2                  (*(u16 volatile xdata *)0xFF32)
#define PWM_P04_T2H                 (*(u8  volatile xdata *)0xFF32)
#define PWM_P04_T2L                 (*(u8  volatile xdata *)0xFF33)
#define PWM_P04_CR                  (*(u8  volatile xdata *)0xFF34)
#define PWM_P04_HLD                 (*(u8  volatile xdata *)0xFF35)
#define PWM_P05_T1                  (*(u16 volatile xdata *)0xFF38)
#define PWM_P05_T1H                 (*(u8  volatile xdata *)0xFF38)
#define PWM_P05_T1L                 (*(u8  volatile xdata *)0xFF39)
#define PWM_P05_T2                  (*(u16 volatile xdata *)0xFF3A)
#define PWM_P05_T2H                 (*(u8  volatile xdata *)0xFF3A)
#define PWM_P05_T2L                 (*(u8  volatile xdata *)0xFF3B)
#define PWM_P05_CR                  (*(u8  volatile xdata *)0xFF3C)
#define PWM_P05_HLD                 (*(u8  volatile xdata *)0xFF3D)
#define PWM_P06_T1                  (*(u16 volatile xdata *)0xFF40)
#define PWM_P06_T1H                 (*(u8  volatile xdata *)0xFF40)
#define PWM_P06_T1L                 (*(u8  volatile xdata *)0xFF41)
#define PWM_P06_T2                  (*(u16 volatile xdata *)0xFF42)
#define PWM_P06_T2H                 (*(u8  volatile xdata *)0xFF42)
#define PWM_P06_T2L                 (*(u8  volatile xdata *)0xFF43)
#define PWM_P06_CR                  (*(u8  volatile xdata *)0xFF44)
#define PWM_P06_HLD                 (*(u8  volatile xdata *)0xFF45)
#define PWM_P07_T1                  (*(u16 volatile xdata *)0xFF48)
#define PWM_P07_T1H                 (*(u8  volatile xdata *)0xFF48)
#define PWM_P07_T1L                 (*(u8  volatile xdata *)0xFF49)
#define PWM_P07_T2                  (*(u16 volatile xdata *)0xFF4A)
#define PWM_P07_T2H                 (*(u8  volatile xdata *)0xFF4A)
#define PWM_P07_T2L                 (*(u8  volatile xdata *)0xFF4B)
#define PWM_P07_CR                  (*(u8  volatile xdata *)0xFF4C)
#define PWM_P07_HLD                 (*(u8  volatile xdata *)0xFF4D)
#define PWM_P1_C                    (*(u16 volatile xdata *)0xFF50)
#define PWM_P1_CH                   (*(u8  volatile xdata *)0xFF50)
#define PWM_P1_CL                   (*(u8  volatile xdata *)0xFF51)
#define PWM_P1_CKS                  (*(u8  volatile xdata *)0xFF52)
#define PWM_P1_IF                   (*(u8  volatile xdata *)0xFF55)
#define PWM_P1_FDCR                 (*(u8  volatile xdata *)0xFF56)
#define PWM_P10_T1                  (*(u16 volatile xdata *)0xFF60)
#define PWM_P10_T1H                 (*(u8  volatile xdata *)0xFF60)
#define PWM_P10_T1L                 (*(u8  volatile xdata *)0xFF61)
#define PWM_P10_T2                  (*(u16 volatile xdata *)0xFF62)
#define PWM_P10_T2H                 (*(u8  volatile xdata *)0xFF62)
#define PWM_P10_T2L                 (*(u8  volatile xdata *)0xFF63)
#define PWM_P10_CR                  (*(u8  volatile xdata *)0xFF64)
#define PWM_P10_HLD                 (*(u8  volatile xdata *)0xFF65)
#define PWM_P11_T1                  (*(u16 volatile xdata *)0xFF68)
#define PWM_P11_T1H                 (*(u8  volatile xdata *)0xFF68)
#define PWM_P11_T1L                 (*(u8  volatile xdata *)0xFF69)
#define PWM_P11_T2                  (*(u16 volatile xdata *)0xFF6A)
#define PWM_P11_T2H                 (*(u8  volatile xdata *)0xFF6A)
#define PWM_P11_T2L                 (*(u8  volatile xdata *)0xFF6B)
#define PWM_P11_CR                  (*(u8  volatile xdata *)0xFF6C)
#define PWM_P11_HLD                 (*(u8  volatile xdata *)0xFF6D)
#define PWM_P12_T1                  (*(u16 volatile xdata *)0xFF70)
#define PWM_P12_T1H                 (*(u8  volatile xdata *)0xFF70)
#define PWM_P12_T1L                 (*(u8  volatile xdata *)0xFF71)
#define PWM_P12_T2                  (*(u16 volatile xdata *)0xFF72)
#define PWM_P12_T2H                 (*(u8  volatile xdata *)0xFF72)
#define PWM_P12_T2L                 (*(u8  volatile xdata *)0xFF73)
#define PWM_P12_CR                  (*(u8  volatile xdata *)0xFF74)
#define PWM_P12_HLD                 (*(u8  volatile xdata *)0xFF75)
#define PWM_P13_T1                  (*(u16 volatile xdata *)0xFF78)
#define PWM_P13_T1H                 (*(u8  volatile xdata *)0xFF78)
#define PWM_P13_T1L                 (*(u8  volatile xdata *)0xFF79)
#define PWM_P13_T2                  (*(u16 volatile xdata *)0xFF7A)
#define PWM_P13_T2H                 (*(u8  volatile xdata *)0xFF7A)
#define PWM_P13_T2L                 (*(u8  volatile xdata *)0xFF7B)
#define PWM_P13_CR                  (*(u8  volatile xdata *)0xFF7C)
#define PWM_P13_HLD                 (*(u8  volatile xdata *)0xFF7D)
#define PWM_P14_T1                  (*(u16 volatile xdata *)0xFF80)
#define PWM_P14_T1H                 (*(u8  volatile xdata *)0xFF80)
#define PWM_P14_T1L                 (*(u8  volatile xdata *)0xFF81)
#define PWM_P14_T2                  (*(u16 volatile xdata *)0xFF82)
#define PWM_P14_T2H                 (*(u8  volatile xdata *)0xFF82)
#define PWM_P14_T2L                 (*(u8  volatile xdata *)0xFF83)
#define PWM_P14_CR                  (*(u8  volatile xdata *)0xFF84)
#define PWM_P14_HLD                 (*(u8  volatile xdata *)0xFF85)
#define PWM_P15_T1                  (*(u16 volatile xdata *)0xFF88)
#define PWM_P15_T1H                 (*(u8  volatile xdata *)0xFF88)
#define PWM_P15_T1L                 (*(u8  volatile xdata *)0xFF89)
#define PWM_P15_T2                  (*(u16 volatile xdata *)0xFF8A)
#define PWM_P15_T2H                 (*(u8  volatile xdata *)0xFF8A)
#define PWM_P15_T2L                 (*(u8  volatile xdata *)0xFF8B)
#define PWM_P15_CR                  (*(u8  volatile xdata *)0xFF8C)
#define PWM_P15_HLD                 (*(u8  volatile xdata *)0xFF8D)
#define PWM_P16_T1                  (*(u16 volatile xdata *)0xFF90)
#define PWM_P16_T1H                 (*(u8  volatile xdata *)0xFF90)
#define PWM_P16_T1L                 (*(u8  volatile xdata *)0xFF91)
#define PWM_P16_T2                  (*(u16 volatile xdata *)0xFF92)
#define PWM_P16_T2H                 (*(u8  volatile xdata *)0xFF92)
#define PWM_P16_T2L                 (*(u8  volatile xdata *)0xFF93)
#define PWM_P16_CR                  (*(u8  volatile xdata *)0xFF94)
#define PWM_P16_HLD                 (*(u8  volatile xdata *)0xFF95)
#define PWM_P17_T1                  (*(u16 volatile xdata *)0xFF98)
#define PWM_P17_T1H                 (*(u8  volatile xdata *)0xFF98)
#define PWM_P17_T1L                 (*(u8  volatile xdata *)0xFF99)
#define PWM_P17_T2                  (*(u16 volatile xdata *)0xFF9A)
#define PWM_P17_T2H                 (*(u8  volatile xdata *)0xFF9A)
#define PWM_P17_T2L                 (*(u8  volatile xdata *)0xFF9B)
#define PWM_P17_CR                  (*(u8  volatile xdata *)0xFF9C)
#define PWM_P17_HLD                 (*(u8  volatile xdata *)0xFF9D)
#define PWM_P2_C                    (*(u16 volatile xdata *)0xFFA0)
#define PWM_P2_CH                   (*(u8  volatile xdata *)0xFFA0)
#define PWM_P2_CL                   (*(u8  volatile xdata *)0xFFA1)
#define PWM_P2_CKS                  (*(u8  volatile xdata *)0xFFA2)
#define PWM_P2_TADC                 (*(u16 volatile xdata *)0xFFA3)
#define PWM_P2_TADCH                (*(u8  volatile xdata *)0xFFA3)
#define PWM_P2_TADCL                (*(u8  volatile xdata *)0xFFA4)
#define PWM_P2_IF                   (*(u8  volatile xdata *)0xFFA5)
#define PWM_P2_FDCR                 (*(u8  volatile xdata *)0xFFA6)
#define PWM_P20_T1                  (*(u16 volatile xdata *)0xFFB0)
#define PWM_P20_T1H                 (*(u8  volatile xdata *)0xFFB0)
#define PWM_P20_T1L                 (*(u8  volatile xdata *)0xFFB1)
#define PWM_P20_T2                  (*(u16 volatile xdata *)0xFFB2)
#define PWM_P20_T2H                 (*(u8  volatile xdata *)0xFFB2)
#define PWM_P20_T2L                 (*(u8  volatile xdata *)0xFFB3)
#define PWM_P20_CR                  (*(u8  volatile xdata *)0xFFB4)
#define PWM_P20_HLD                 (*(u8  volatile xdata *)0xFFB5)
#define PWM_P21_T1                  (*(u16 volatile xdata *)0xFFB8)
#define PWM_P21_T1H                 (*(u8  volatile xdata *)0xFFB8)
#define PWM_P21_T1L                 (*(u8  volatile xdata *)0xFFB9)
#define PWM_P21_T2                  (*(u16 volatile xdata *)0xFFBA)
#define PWM_P21_T2H                 (*(u8  volatile xdata *)0xFFBA)
#define PWM_P21_T2L                 (*(u8  volatile xdata *)0xFFBB)
#define PWM_P21_CR                  (*(u8  volatile xdata *)0xFFBC)
#define PWM_P21_HLD                 (*(u8  volatile xdata *)0xFFBD)
#define PWM_P22_T1                  (*(u16 volatile xdata *)0xFFC0)
#define PWM_P22_T1H                 (*(u8  volatile xdata *)0xFFC0)
#define PWM_P22_T1L                 (*(u8  volatile xdata *)0xFFC1)
#define PWM_P22_T2                  (*(u16 volatile xdata *)0xFFC2)
#define PWM_P22_T2H                 (*(u8  volatile xdata *)0xFFC2)
#define PWM_P22_T2L                 (*(u8  volatile xdata *)0xFFC3)
#define PWM_P22_CR                  (*(u8  volatile xdata *)0xFFC4)
#define PWM_P22_HLD                 (*(u8  volatile xdata *)0xFFC5)
#define PWM_P23_T1                  (*(u16 volatile xdata *)0xFFC8)
#define PWM_P23_T1H                 (*(u8  volatile xdata *)0xFFC8)
#define PWM_P23_T1L                 (*(u8  volatile xdata *)0xFFC9)
#define PWM_P23_T2                  (*(u16 volatile xdata *)0xFFCA)
#define PWM_P23_T2H                 (*(u8  volatile xdata *)0xFFCA)
#define PWM_P23_T2L                 (*(u8  volatile xdata *)0xFFCB)
#define PWM_P23_CR                  (*(u8  volatile xdata *)0xFFCC)
#define PWM_P23_HLD                 (*(u8  volatile xdata *)0xFFCD)
#define PWM_P24_T1                  (*(u16 volatile xdata *)0xFFD0)
#define PWM_P24_T1H                 (*(u8  volatile xdata *)0xFFD0)
#define PWM_P24_T1L                 (*(u8  volatile xdata *)0xFFD1)
#define PWM_P24_T2                  (*(u16 volatile xdata *)0xFFD2)
#define PWM_P24_T2H                 (*(u8  volatile xdata *)0xFFD2)
#define PWM_P24_T2L                 (*(u8  volatile xdata *)0xFFD3)
#define PWM_P24_CR                  (*(u8  volatile xdata *)0xFFD4)
#define PWM_P24_HLD                 (*(u8  volatile xdata *)0xFFD5)
#define PWM_P25_T1                  (*(u16 volatile xdata *)0xFFD8)
#define PWM_P25_T1H                 (*(u8  volatile xdata *)0xFFD8)
#define PWM_P25_T1L                 (*(u8  volatile xdata *)0xFFD9)
#define PWM_P25_T2                  (*(u16 volatile xdata *)0xFFDA)
#define PWM_P25_T2H                 (*(u8  volatile xdata *)0xFFDA)
#define PWM_P25_T2L                 (*(u8  volatile xdata *)0xFFDB)
#define PWM_P25_CR                  (*(u8  volatile xdata *)0xFFDC)
#define PWM_P25_HLD                 (*(u8  volatile xdata *)0xFFDD)
#define PWM_P26_T1                  (*(u16 volatile xdata *)0xFFE0)
#define PWM_P26_T1H                 (*(u8  volatile xdata *)0xFFE0)
#define PWM_P26_T1L                 (*(u8  volatile xdata *)0xFFE1)
#define PWM_P26_T2                  (*(u16 volatile xdata *)0xFFE2)
#define PWM_P26_T2H                 (*(u8  volatile xdata *)0xFFE2)
#define PWM_P26_T2L                 (*(u8  volatile xdata *)0xFFE3)
#define PWM_P26_CR                  (*(u8  volatile xdata *)0xFFE4)
#define PWM_P26_HLD                 (*(u8  volatile xdata *)0xFFE5)
#define PWM_P27_T1                  (*(u16 volatile xdata *)0xFFE8)
#define PWM_P27_T1H                 (*(u8  volatile xdata *)0xFFE8)
#define PWM_P27_T1L                 (*(u8  volatile xdata *)0xFFE9)
#define PWM_P27_T2                  (*(u16 volatile xdata *)0xFFEA)
#define PWM_P27_T2H                 (*(u8  volatile xdata *)0xFFEA)
#define PWM_P27_T2L                 (*(u8  volatile xdata *)0xFFEB)
#define PWM_P27_CR                  (*(u8  volatile xdata *)0xFFEC)
#define PWM_P27_HLD                 (*(u8  volatile xdata *)0xFFED)

#if     (ECBM_MCU==0x2815C4)        //STC8A8K64D4
#define PWM_C                       (*(u16 volatile xdata *)0xFF00)
#define PWM_CH                      (*(u8  volatile xdata *)0xFF00)
#define PWM_CL                      (*(u8  volatile xdata *)0xFF01)
#define PWM_CKS                     (*(u8  volatile xdata *)0xFF02)
#define PWM_TADC                    (*(u16 volatile xdata *)0xFF03)
#define PWM_TADCH                   (*(u8  volatile xdata *)0xFF03)
#define PWM_TADCL                   (*(u8  volatile xdata *)0xFF04)
#define PWM_IF                      (*(u8  volatile xdata *)0xFF05)
#define PWM_FDCR                    (*(u8  volatile xdata *)0xFF06)
#define PWM_DELSEL                  (*(u8  volatile xdata *)0xFF07)
#define PWM_CH0_T1                  (*(u16 volatile xdata *)0xFF10)
#define PWM_CH0_T1H                 (*(u8  volatile xdata *)0xFF10)
#define PWM_CH0_T1L                 (*(u8  volatile xdata *)0xFF11)
#define PWM_CH0_T2                  (*(u16 volatile xdata *)0xFF12)
#define PWM_CH0_T2H                 (*(u8  volatile xdata *)0xFF12)
#define PWM_CH0_T2L                 (*(u8  volatile xdata *)0xFF13)
#define PWM_CH0_CR                  (*(u8  volatile xdata *)0xFF14)
#define PWM_CH0_HLD                 (*(u8  volatile xdata *)0xFF15)
#define PWM_CH1_T1                  (*(u16 volatile xdata *)0xFF18)
#define PWM_CH1_T1H                 (*(u8  volatile xdata *)0xFF18)
#define PWM_CH1_T1L                 (*(u8  volatile xdata *)0xFF19)
#define PWM_CH1_T2                  (*(u16 volatile xdata *)0xFF1A)
#define PWM_CH1_T2H                 (*(u8  volatile xdata *)0xFF1A)
#define PWM_CH1_T2L                 (*(u8  volatile xdata *)0xFF1B)
#define PWM_CH1_CR                  (*(u8  volatile xdata *)0xFF1C)
#define PWM_CH1_HLD                 (*(u8  volatile xdata *)0xFF1D)
#define PWM_CH2_T1                  (*(u16 volatile xdata *)0xFF20)
#define PWM_CH2_T1H                 (*(u8  volatile xdata *)0xFF20)
#define PWM_CH2_T1L                 (*(u8  volatile xdata *)0xFF21)
#define PWM_CH2_T2                  (*(u16 volatile xdata *)0xFF22)
#define PWM_CH2_T2H                 (*(u8  volatile xdata *)0xFF22)
#define PWM_CH2_T2L                 (*(u8  volatile xdata *)0xFF23)
#define PWM_CH2_CR                  (*(u8  volatile xdata *)0xFF24)
#define PWM_CH2_HLD                 (*(u8  volatile xdata *)0xFF25)
#define PWM_CH3_T1                  (*(u16 volatile xdata *)0xFF28)
#define PWM_CH3_T1H                 (*(u8  volatile xdata *)0xFF28)
#define PWM_CH3_T1L                 (*(u8  volatile xdata *)0xFF29)
#define PWM_CH3_T2                  (*(u16 volatile xdata *)0xFF2A)
#define PWM_CH3_T2H                 (*(u8  volatile xdata *)0xFF2A)
#define PWM_CH3_T2L                 (*(u8  volatile xdata *)0xFF2B)
#define PWM_CH3_CR                  (*(u8  volatile xdata *)0xFF2C)
#define PWM_CH3_HLD                 (*(u8  volatile xdata *)0xFF2D)
#define PWM_CH4_T1                  (*(u16 volatile xdata *)0xFF30)
#define PWM_CH4_T1H                 (*(u8  volatile xdata *)0xFF30)
#define PWM_CH4_T1L                 (*(u8  volatile xdata *)0xFF31)
#define PWM_CH4_T2                  (*(u16 volatile xdata *)0xFF32)
#define PWM_CH4_T2H                 (*(u8  volatile xdata *)0xFF32)
#define PWM_CH4_T2L                 (*(u8  volatile xdata *)0xFF33)
#define PWM_CH4_CR                  (*(u8  volatile xdata *)0xFF34)
#define PWM_CH4_HLD                 (*(u8  volatile xdata *)0xFF35)
#define PWM_CH5_T1                  (*(u16 volatile xdata *)0xFF38)
#define PWM_CH5_T1H                 (*(u8  volatile xdata *)0xFF38)
#define PWM_CH5_T1L                 (*(u8  volatile xdata *)0xFF39)
#define PWM_CH5_T2                  (*(u16 volatile xdata *)0xFF3A)
#define PWM_CH5_T2H                 (*(u8  volatile xdata *)0xFF3A)
#define PWM_CH5_T2L                 (*(u8  volatile xdata *)0xFF3B)
#define PWM_CH5_CR                  (*(u8  volatile xdata *)0xFF3C)
#define PWM_CH5_HLD                 (*(u8  volatile xdata *)0xFF3D)
#define PWM_CH6_T1                  (*(u16 volatile xdata *)0xFF40)
#define PWM_CH6_T1H                 (*(u8  volatile xdata *)0xFF40)
#define PWM_CH6_T1L                 (*(u8  volatile xdata *)0xFF41)
#define PWM_CH6_T2                  (*(u16 volatile xdata *)0xFF42)
#define PWM_CH6_T2H                 (*(u8  volatile xdata *)0xFF42)
#define PWM_CH6_T2L                 (*(u8  volatile xdata *)0xFF43)
#define PWM_CH6_CR                  (*(u8  volatile xdata *)0xFF44)
#define PWM_CH6_HLD                 (*(u8  volatile xdata *)0xFF45)
#define PWM_CH7_T1                  (*(u16 volatile xdata *)0xFF48)
#define PWM_CH7_T1H                 (*(u8  volatile xdata *)0xFF48)
#define PWM_CH7_T1L                 (*(u8  volatile xdata *)0xFF49)
#define PWM_CH7_T2                  (*(u16 volatile xdata *)0xFF4A)
#define PWM_CH7_T2H                 (*(u8  volatile xdata *)0xFF4A)
#define PWM_CH7_T2L                 (*(u8  volatile xdata *)0xFF4B)
#define PWM_CH7_CR                  (*(u8  volatile xdata *)0xFF4C)
#define PWM_CH7_HLD                 (*(u8  volatile xdata *)0xFF4D)
#endif
#if     ((ECBM_MCU&0xF0F000)==0x200000)   //除STC8A8K64D4以外的STC8A
#define PWM_C                       (*(u16 volatile xdata *)0xFFF0)
#define PWM_CH                      (*(u8  volatile xdata *)0xFFF0)
#define PWM_CL                      (*(u8  volatile xdata *)0xFFF1)
#define PWM_CKS                     (*(u8  volatile xdata *)0xFFF2)
#define PWM_TADCP                   (*(u8  volatile xdata *)0xFFF3)
#define PWM_TADCPH                  (*(u8  volatile xdata *)0xFFF3)
#define PWM_TADCPL                  (*(u8  volatile xdata *)0xFFF4)
#define PWM_CH0_T1                  (*(u16 volatile xdata *)0xFF00)
#define PWM_CH0_T1H                 (*(u8  volatile xdata *)0xFF00)
#define PWM_CH0_T1L                 (*(u8  volatile xdata *)0xFF01)
#define PWM_CH0_T2                  (*(u16 volatile xdata *)0xFF02)
#define PWM_CH0_T2H                 (*(u8  volatile xdata *)0xFF02)
#define PWM_CH0_T2L                 (*(u8  volatile xdata *)0xFF03)
#define PWM_CH0_CR                  (*(u8  volatile xdata *)0xFF04)
#define PWM_CH0_HLD                 (*(u8  volatile xdata *)0xFF05)
#define PWM_CH1_T1                  (*(u16 volatile xdata *)0xFF10)
#define PWM_CH1_T1H                 (*(u8  volatile xdata *)0xFF10)
#define PWM_CH1_T1L                 (*(u8  volatile xdata *)0xFF11)
#define PWM_CH1_T2                  (*(u16 volatile xdata *)0xFF12)
#define PWM_CH1_T2H                 (*(u8  volatile xdata *)0xFF12)
#define PWM_CH1_T2L                 (*(u8  volatile xdata *)0xFF13)
#define PWM_CH1_CR                  (*(u8  volatile xdata *)0xFF14)
#define PWM_CH1_HLD                 (*(u8  volatile xdata *)0xFF15)
#define PWM_CH2_T1                  (*(u16 volatile xdata *)0xFF20)
#define PWM_CH2_T1H                 (*(u8  volatile xdata *)0xFF20)
#define PWM_CH2_T1L                 (*(u8  volatile xdata *)0xFF21)
#define PWM_CH2_T2                  (*(u16 volatile xdata *)0xFF22)
#define PWM_CH2_T2H                 (*(u8  volatile xdata *)0xFF22)
#define PWM_CH2_T2L                 (*(u8  volatile xdata *)0xFF23)
#define PWM_CH2_CR                  (*(u8  volatile xdata *)0xFF24)
#define PWM_CH2_HLD                 (*(u8  volatile xdata *)0xFF25)
#define PWM_CH3_T1                  (*(u16 volatile xdata *)0xFF30)
#define PWM_CH3_T1H                 (*(u8  volatile xdata *)0xFF30)
#define PWM_CH3_T1L                 (*(u8  volatile xdata *)0xFF31)
#define PWM_CH3_T2                  (*(u16 volatile xdata *)0xFF32)
#define PWM_CH3_T2H                 (*(u8  volatile xdata *)0xFF32)
#define PWM_CH3_T2L                 (*(u8  volatile xdata *)0xFF33)
#define PWM_CH3_CR                  (*(u8  volatile xdata *)0xFF34)
#define PWM_CH3_HLD                 (*(u8  volatile xdata *)0xFF35)
#define PWM_CH4_T1                  (*(u16 volatile xdata *)0xFF40)
#define PWM_CH4_T1H                 (*(u8  volatile xdata *)0xFF40)
#define PWM_CH4_T1L                 (*(u8  volatile xdata *)0xFF41)
#define PWM_CH4_T2                  (*(u16 volatile xdata *)0xFF42)
#define PWM_CH4_T2H                 (*(u8  volatile xdata *)0xFF42)
#define PWM_CH4_T2L                 (*(u8  volatile xdata *)0xFF43)
#define PWM_CH4_CR                  (*(u8  volatile xdata *)0xFF44)
#define PWM_CH4_HLD                 (*(u8  volatile xdata *)0xFF45)
#define PWM_CH5_T1                  (*(u16 volatile xdata *)0xFF50)
#define PWM_CH5_T1H                 (*(u8  volatile xdata *)0xFF50)
#define PWM_CH5_T1L                 (*(u8  volatile xdata *)0xFF51)
#define PWM_CH5_T2                  (*(u16 volatile xdata *)0xFF52)
#define PWM_CH5_T2H                 (*(u8  volatile xdata *)0xFF52)
#define PWM_CH5_T2L                 (*(u8  volatile xdata *)0xFF53)
#define PWM_CH5_CR                  (*(u8  volatile xdata *)0xFF54)
#define PWM_CH5_HLD                 (*(u8  volatile xdata *)0xFF55)
#define PWM_CH6_T1                  (*(u16 volatile xdata *)0xFF60)
#define PWM_CH6_T1H                 (*(u8  volatile xdata *)0xFF60)
#define PWM_CH6_T1L                 (*(u8  volatile xdata *)0xFF61)
#define PWM_CH6_T2                  (*(u16 volatile xdata *)0xFF62)
#define PWM_CH6_T2H                 (*(u8  volatile xdata *)0xFF62)
#define PWM_CH6_T2L                 (*(u8  volatile xdata *)0xFF63)
#define PWM_CH6_CR                  (*(u8  volatile xdata *)0xFF64)
#define PWM_CH6_HLD                 (*(u8  volatile xdata *)0xFF65)
#define PWM_CH7_T1                  (*(u16 volatile xdata *)0xFF70)
#define PWM_CH7_T1H                 (*(u8  volatile xdata *)0xFF70)
#define PWM_CH7_T1L                 (*(u8  volatile xdata *)0xFF71)
#define PWM_CH7_T2                  (*(u16 volatile xdata *)0xFF72)
#define PWM_CH7_T2H                 (*(u8  volatile xdata *)0xFF72)
#define PWM_CH7_T2L                 (*(u8  volatile xdata *)0xFF73)
#define PWM_CH7_CR                  (*(u8  volatile xdata *)0xFF74)
#define PWM_CH7_HLD                 (*(u8  volatile xdata *)0xFF75)
#endif
#endif
//以下是寄存器位定义和功能实现指令。
/*-------------------------------看门狗特殊功能寄存器-----------------------------*/
#define WDT_FLAG                    0x80//看门狗溢出标志位
#define EN_WDT                      0x20//看门狗使能位
#define CLR_WDT                     0x10//看门狗定时器清零
#define IDL_WDT                     0x08//看门狗在空闲模式下的控制位
//-------------功能指令------------//
#define WDT_POWER_ON                do{WDT_CONTR|= EN_WDT; }while(0) //打开看门狗
#define WDT_CLR                     do{WDT_CONTR|= CLR_WDT;}while(0) //喂狗
#define WDT_SET_IDLE_ENABLE         do{WDT_CONTR|= IDL_WDT;}while(0) //看门狗在空闲模式下继续计数
#define WDT_SET_IDLE_DISABLE        do{WDT_CONTR&=~IDL_WDT;}while(0) //看门狗在空闲模式下停止计数
#define WDT_SET_SCALE(value)        REG_IN_MASK(WDT_CONTR,0x07,value)//设置看门狗的预分频系数
#define WDT_GET_FLAG                (WDT_CONTR & WDT_FLAG)           //获取看门狗溢出标志位
//-------------寄存器读取----------//
#define WDT_SET_REG_CONTR(value)    do{WDT_CONTR=(u8)(value);}while(0)//设置WDT_CONTR寄存器
#define WDT_GET_REG_CONTR           (WDT_CONTR)                      //获取WDT_CONTR寄存器的值
/*------------------------------------外部中断0----------------------------------*/
sbit    EX0                         =IE^0;  //外部中断0允许位
sbit    IT0                         =TCON^0;//外部中断0触发控制位
sbit    PX0                         =IP^0;  //外部中断0中断优先级控制位（低）
#define PX0H                        0x01    //外部中断0中断优先级控制位（高）
//-------------功能指令------------//
#define EXTI0_ENABLE                do{EX0=1;}while(0)//打开外部中断0
#define EXTI0_DISABLE               do{EX0=0;}while(0)//关闭外部中断0
#define EXTI0_SET_MODE_UP_DOWM      do{IT0=0;}while(0)//外部中断0通过上升沿和下降沿触发
#define EXTI0_SET_MODE_DOWM         do{IT0=1;}while(0)//外部中断0通过下降沿触发
#define EXTI0_SET_IO_HIGH           do{P32=1;}while(0)//设置IO的默认电平为高电平
#define EXTI0_GET_IO                (P32)             //通过读IO的电平能知道是上升沿触发还是下降沿触发
#define EXTI0_SET_IT_PRIORITY_0     do{IPH&=~PX0H;PX0=0;}while(0)//设置外部中断0的优先级为0
#define EXTI0_SET_IT_PRIORITY_1     do{IPH&=~PX0H;PX0=1;}while(0)//设置外部中断0的优先级为1
#define EXTI0_SET_IT_PRIORITY_2     do{IPH|= PX0H;PX0=0;}while(0)//设置外部中断0的优先级为2
#define EXTI0_SET_IT_PRIORITY_3     do{IPH|= PX0H;PX0=1;}while(0)//设置外部中断0的优先级为3
//-------------功能定义------------//
#define EXTI0_IT_NUM                interrupt 0//外部中断0中断号
/*------------------------------------外部中断1----------------------------------*/
sbit    EX1                         =IE^2;  //外部中断1允许位
sbit    IT1                         =TCON^2;//外部中断1触发控制位
sbit    PX1                         =IP^2;  //外部中断1中断优先级控制位（低）
#define PX1H                        0x04    //外部中断1中断优先级控制位（高）
//-------------功能指令------------//
#define EXTI1_ENABLE                do{EX1=1;}while(0)//打开外部中断1
#define EXTI1_DISABLE               do{EX1=0;}while(0)//关闭外部中断1
#define EXTI1_SET_MODE_UP_DOWM      do{IT1=0;}while(0)//外部中断1通过上升沿和下降沿触发
#define EXTI1_SET_MODE_DOWM         do{IT1=1;}while(0)//外部中断1通过下降沿触发
#define EXTI1_SET_IO_HIGH           do{P33=1;}while(0)//设置IO的默认电平为高电平
#define EXTI1_GET_IO                (P33)             //通过读IO的电平能知道是上升沿触发还是下降沿触发
#define EXTI1_SET_IT_PRIORITY_0     do{IPH&=~PX1H;PX1=0;}while(0)//设置外部中断1的优先级为0
#define EXTI1_SET_IT_PRIORITY_1     do{IPH&=~PX1H;PX1=1;}while(0)//设置外部中断1的优先级为1
#define EXTI1_SET_IT_PRIORITY_2     do{IPH|= PX1H;PX1=0;}while(0)//设置外部中断1的优先级为2
#define EXTI1_SET_IT_PRIORITY_3     do{IPH|= PX1H;PX1=1;}while(0)//设置外部中断1的优先级为3
//-------------功能定义------------//
#define EXTI1_IT_NUM                interrupt 2//外部中断1中断号
/*------------------------------------外部中断2----------------------------------*/
#define EX2                         0x10//外部中断2中断允许位
#define INT2IF                      0x10//外部中断2的中断标志位
//-------------功能指令------------//
#define EXTI2_ENABLE                do{INTCLKO|= EX2;}while(0)//打开外部中断2
#define EXTI2_DISABLE               do{INTCLKO&=~EX2;}while(0)//关闭外部中断2
#define EXTI2_SET_IO_HIGH           do{P36=1;}while(0)//设置IO的默认电平为高电平
#define EXTI2_GET_IO                (P36) 
#define EXTI2_IT_CLS                do{AUXINTIF&=~INT2IF;}while(0)//清除外部中断2的中断标志位
//-------------功能定义------------//
#define EXTI2_IT_NUM                interrupt 10//外部中断2中断号
/*------------------------------------外部中断3----------------------------------*/
#define EX3                         0x20//外部中断3中断允许位
#define INT3IF                      0x20//外部中断3的中断标志位
//-------------功能指令------------//
#define EXTI3_ENABLE                do{INTCLKO|= EX3;}while(0)//打开外部中断3
#define EXTI3_DISABLE               do{INTCLKO&=~EX3;}while(0)//关闭外部中断3
#define EXTI3_SET_IO_HIGH           do{P37=1;}while(0)//设置IO的默认电平为高电平
#define EXTI3_GET_IO                (P37) 
#define EXTI3_IT_CLS                do{AUXINTIF&=~INT3IF;}while(0)//清除外部中断3的中断标志位
//-------------功能定义------------//
#define EXTI3_IT_NUM                interrupt 11//外部中断3中断号
/*------------------------------------外部中断4----------------------------------*/
#define EX4                         0x40//外部中断4中断允许位
#define INT4IF                      0x40//外部中断4的中断标志位
#define PX4                         0x10//外部中断4中断优先级控制位（低）
#define PX4H                        0x10//外部中断4中断优先级控制位（高）
//-------------功能指令------------//
#define EXTI4_ENABLE                do{INTCLKO|= EX4;}while(0)//打开外部中断4
#define EXTI4_DISABLE               do{INTCLKO&=~EX4;}while(0)//关闭外部中断4
#define EXTI4_SET_IO_HIGH           do{P30=1;}while(0)//设置IO的默认电平为高电平
#define EXTI4_GET_IO                P30 
#define EXTI4_IT_CLS                do{AUXINTIF&=~INT4IF;}while(0)//清除外部中断4的中断标志位
#define EXTI4_SET_IT_PRIORITY_0     do{IP2H&=~PX4H;IP2&=~PX4;}while(0)//设置外部中断4的优先级为0
#define EXTI4_SET_IT_PRIORITY_1     do{IP2H&=~PX4H;IP2|= PX4;}while(0)//设置外部中断4的优先级为1
#define EXTI4_SET_IT_PRIORITY_2     do{IP2H|= PX4H;IP2&=~PX4;}while(0)//设置外部中断4的优先级为2
#define EXTI4_SET_IT_PRIORITY_3     do{IP2H|= PX4H;IP2|= PX4;}while(0)//设置外部中断4的优先级为3
//-------------功能定义------------//
#define EXTI4_IT_NUM                interrupt 16//外部中断4中断号
/*------------------------------IAP/ISP特殊功能寄存器-----------------------------*/
#define IAP_IDL                     0x00//EEPROM空闲指令
#define IAP_READ                    0x01//EEPROM读指令
#define IAP_WRITE                   0x02//EEPROM写指令
#define IAP_ERASE                   0x03//EEPROM清除指令
#define IAP_EN                      0x80//EEPROM操作使能控制位
#define IAP_FAIL                    0x10//EEPROM操作失败状态位
//-------------功能指令------------//
#define IAP_POWER_ON                do{IAP_CONTR|= IAP_EN;}while(0)//打开IAP功能
#define IAP_POWER_OFF               do{IAP_CONTR&=~IAP_EN;}while(0)//关闭IAP功能
#define IAP_CMD_NOP                 do{IAP_CMD=IAP_IDL;   }while(0)//空操作
#define IAP_CMD_READ                do{IAP_CMD=IAP_READ;  }while(0)//读一个字节
#define IAP_CMD_WRITE               do{IAP_CMD=IAP_WRITE; }while(0)//写一个字节
#define IAP_CMD_ERASE               do{IAP_CMD=IAP_ERASE; }while(0)//擦除一个扇区
#define IAP_TRIG_ON                 do{IAP_TRIG=0x5A;IAP_TRIG=0xA5;}while(0)//触发一次EEPROM操作
#define IAP_TRIG_CLS                do{IAP_TRIG=0;}while(0)//清空触发寄存器
#define IAP_GET_FAIL                (IAP_CONTR & IAP_FAIL)
//-------------寄存器读取----------//
#define IAP_SET_REG_DATA(value)     do{IAP_DATA=(u8)(value);}while(0)//写一个数据到IAP_DATA
#define IAP_GET_REG_DATA            (IAP_DATA)//从IAP_DATA读一个数据
#define IAP_SET_REG_ADDR_HL(value)  do{IAP_ADDRL=(u8)(value);IAP_ADDRH=(u8)(value>>8);}while(0)//写一个地址到IAP_ADDRH和IAP_ADDRL中
#define IAP_GET_REG_ADDR_HL         ((((u16)IAP_ADDRH)<<8)|(u16)IAP_ADDRL)//读一个地址IAP_ADDR
#define IAP_SET_REG_ADDR_H8(value)  do{IAP_ADDRH=(u8)(value);}while(0)//写一个地址到IAP_ADDRH中
#define IAP_GET_REG_ADDR_H8         (IAP_ADDRH)//读IAP_ADDRH
#define IAP_SET_REG_ADDR_L8(value)  do{IAP_ADDRL=(u8)(value);}while(0)//写一个地址到IAP_ADDRL中
#define IAP_GET_REG_ADDR_L8         (IAP_ADDRL)//读IAP_ADDRL
#define IAP_SET_REG_CONTR(value)    do{IAP_CONTR=(u8)(value);}while(0)//写入一个数据到IAP_CONTR寄存器
#define IAP_GET_REG_CONTR           (IAP_CONTR)//读取IAP_CONTR寄存器
#define IAP_SET_REG_TPS(value)      do{IAP_TPS=(u8)(value);}while(0)//写一个数据到IAP_TPS寄存器
#define IAP_GET_REG_TPS             (IAP_TPS)//读IAP_TPS寄存器
/*--------------------------------SPI特殊功能寄存器-------------------------------*/
#define SPIF                        0x80//SPI中断标志位
#define WCOL                        0x40//SPI写冲突标志位
#define SSIG                        0x80//SPI的SS引脚功能控制位
#define SPEN                        0x40//SPI使能控制位
#define DORD                        0x20//SPI数据位发送/接收顺序位
#define MSTR                        0x10//SPI主/从模式选择位
#define CPOL                        0x08//SPI时钟极性控制
#define CPHA                        0x04//SPI时钟相位控制
#define ESPI                        0x02//SPI中断允许位
//-------------功能指令------------//
#define SPI_POWER_ON                do{SPCTL|= SPEN;}while(0)//打开SPI
#define SPI_POWER_OFF               do{SPCTL&=~SPEN;}while(0)//关闭SPI
#define SPI_SET_CS_ENABLE           do{SPCTL&=~SSIG;}while(0)//打开CS脚的使能
#define SPI_SET_CS_DISABLE          do{SPCTL|= SSIG;}while(0)//关闭CS脚的使能
#define SPI_SET_DATA_MSB            do{SPCTL&=~DORD;}while(0)//设置先发/收数据的高位
#define SPI_SET_DATA_LSB            do{SPCTL|= DORD;}while(0)//设置先发/收数据的低位
#define SPI_SET_MODE_MASTER         do{SPCTL|= MSTR;}while(0)//设置SPI为主机模式
#define SPI_SET_MODE_SLAVE          do{SPCTL&=~MSTR;}while(0)//设置SPI为从机模式
#define SPI_SET_CPOL_1              do{SPCTL|= CPOL;}while(0)//设置CPOL位为1
#define SPI_SET_CPOL_0              do{SPCTL&=~CPOL;}while(0)//设置CPOL位为0
#define SPI_SET_CPHA_1              do{SPCTL|= CPHA;}while(0)//设置CPHA位为1
#define SPI_SET_CPHA_0              do{SPCTL&=~CPHA;}while(0)//设置CPHA位为0
#define SPI_SET_PIN(value)          REG_IN_MASK(P_SW1,0x0C,value)//设置串口1的输出引脚
#define SPI_IT_CLS                  do{SPSTAT|=(SPIF|WCOL);}while(0)//清SPI中断标志位
#define SPI_WCOL_CLS                do{SPSTAT|=WCOL;}while(0)//清SPI写冲突标志位
#define SPI_GET_IT_FLAG             (SPSTAT & SPIF)
#define SPI_IT_ENABLE               do{IE2|= ESPI;}while(0)//开SPI中断
#define SPI_IT_DISABLE              do{IE2&=~ESPI;}while(0)//关SPI中断
#define SPI_SET_SPR(value)          REG_IN_MASK(SPCTL,0x03,value)//设置SPI时钟分频
#define SPI_GET_SPR                 (SPCTL & 0x03)         //读取SPI时钟分频
//-------------寄存器读取----------//
#define SPI_SET_REG_SPSTAT(value)   do{SPSTAT=(u8)(value);}while(0)//写一个数据到SPCTL寄存器
#define SPI_GET_REG_SPSTAT          (SPSTAT)//获取SPCTL寄存器的值
#define SPI_SET_REG_SPCTL(value)    do{SPCTL=(u8)(value);}while(0)//写一个数据到SPCTL寄存器
#define SPI_GET_REG_SPCTL           (SPCTL) //获取SPCTL寄存器的值
#define SPI_SET_REG_SPDAT(value)    do{SPDAT=(u8)(value);}while(0)//写一个数据到SPDAT寄存器
#define SPI_GET_REG_SPDAT           (SPDAT) //获取SPDAT寄存器的值
//-------------功能定义------------//
#define SPI_IT_NUM                  interrupt 9//SPI的中断号
/*-------------------------------比较器特殊功能寄存器-----------------------------*/
#define CMPEN                       0x80//比较器使能位
#define CMPIF                       0x40//比较器中断标志位
#define PIE                         0x20//比较器上升沿中断使能位
#define NIE                         0x10//比较器下降沿中断使能位
#define PIS                         0x08//比较器正极选择位
#define NIS                         0x04//比较器负极选择位
#define CMPOE                       0x02//比较器结果输出控制位
#define CMPRES                      0x01//比较器结果
#define INVCMPO                     0x80//比较器结果输出控制
#define DISFLT                      0x40//比较器模拟滤波功能控制
#define PCMP                        0x20//比较器中断优先级控制位（低）
#define PCMPH                       0x20//比较器中断优先级控制位（高）
//-------------功能指令------------//
#define CMP_POWER_ON                do{CMPCR1|= CMPEN;}while(0)//开启比较器
#define CMP_POWER_OFF               do{CMPCR1&=~CMPEN;}while(0)//关闭比较器
#define CMP_IT_CLS                  do{CMPCR1&=~CMPIF;}while(0)//清除比较器中断标志位
#define CMP_IT_POSITIVE_ENABLE      do{CMPCR1|= PIE;  }while(0)//开启上升沿中断
#define CMP_IT_POSITIVE_DISABLE     do{CMPCR1&=~PIE;  }while(0)//关闭上升沿中断
#define CMP_IT_NEGATIVE_ENABLE      do{CMPCR1|= NIE;  }while(0)//开启上升沿中断
#define CMP_IT_NEGATIVE_DISABLE     do{CMPCR1&=~NIE;  }while(0)//关闭上升沿中断
#if     ECBM_MCU == 0x2815C4
#define CMP_SET_POSITIVE_ADC        REG_IN_MASK(CMPEXCFG,0x03,0x03)//比较器的+端为ADC输入脚
#define CMP_SET_POSITIVE_P51        REG_IN_MASK(CMPEXCFG,0x03,0x02)//比较器的+端为P3.7脚
#define CMP_SET_POSITIVE_A50        REG_IN_MASK(CMPEXCFG,0x03,0x01)//比较器的+端为ADC输入脚
#define CMP_SET_POSITIVE_P37        REG_IN_MASK(CMPEXCFG,0x03,0x00)//比较器的+端为P3.7脚
#else
#define CMP_SET_POSITIVE_ADC        do{CMPCR1|= PIS;  }while(0)//比较器的+端为ADC输入脚
#define CMP_SET_POSITIVE_P37        do{CMPCR1&=~PIS;  }while(0)//比较器的+端为P3.7脚
#endif
#if     ECBM_MCU == 0x2815C4
#define CMP_SET_NEGATIVE_P36        do{CMPEXCFG&=~NIS;}while(0)//比较器的-端为P3.6脚
#define CMP_SET_NEGATIVE_BGV        do{CMPEXCFG|= NIS;}while(0)//比较器的-端为内部1.9V电压
#else
#define CMP_SET_NEGATIVE_P36        do{CMPCR1|= NIS;  }while(0)//比较器的-端为P3.6脚
#define CMP_SET_NEGATIVE_BGV        do{CMPCR1&=~NIS;  }while(0)//比较器的-端为内部1.9V电压
#endif
#define CMP_SET_OUT_ENABLE          do{CMPCR1|= CMPOE;}while(0)//开启比较器结果输出
#define CMP_SET_OUT_DISABLE         do{CMPCR1&=~CMPOE;}while(0)//关闭比较器结果输出
#define CMP_GET_RESULT              (CMPCR1 & CMPRES)//获取比较器结果
#define CMP_SET_OUT_NEGATIVE        do{CMPCR2|= INVCMPO;}while(0)//比较器结果反向输出
#define CMP_SET_OUT_POSITIVE        do{CMPCR2&=~INVCMPO;}while(0)//比较器结果正向输出
#define CMP_SET_ANALOG_FILTER_ENABLE    do{CMPCR2|= DISFLT;}while(0)//开启比较器模拟滤波
#define CMP_SET_ANALOG_FILTER_DISABLE   do{CMPCR2&=~DISFLT;}while(0)//关闭比较器模拟滤波
#define CMP_SET_DIGITAL_FILTER(value)   REG_IN_MASK(CMPCR2,0x3F,value)//设置比较器数字滤波
#define CMP_SET_PIN(value)          REG_IN_MASK(P_SW2,0x08,value)     //设置比较器的输出引脚
#define CMP_SET_IT_PRIORITY_0       do{IP2H&=~PCMPH;IP2&=~PCMP;}while(0)//设置比较器的优先级为0
#define CMP_SET_IT_PRIORITY_1       do{IP2H&=~PCMPH;IP2|= PCMP;}while(0)//设置比较器的优先级为1
#define CMP_SET_IT_PRIORITY_2       do{IP2H|= PCMPH;IP2&=~PCMP;}while(0)//设置比较器的优先级为2
#define CMP_SET_IT_PRIORITY_3       do{IP2H|= PCMPH;IP2|= PCMP;}while(0)//设置比较器的优先级为3
//-------------寄存器读取----------//
#define CMP_SET_REG_CMPCR1(value)   do{CMPCR1=(u8)(value);}while(0)//设置CMPCR1寄存器
#define CMP_GET_REG_CMPCR1          (CMPCR1)//读取CMPCR1寄存器
#define CMP_SET_REG_CMPCR2(value)   do{CMPCR2=(u8)(value);}while(0)//设置CMPCR2寄存器
#define CMP_GET_REG_CMPCR2          (CMPCR2)//读取CMPCR1寄存器
#define CMP_SET_REG_CMPEXCFG(value) do{CMPEXCFG=(u8)(value);}while(0)//设置CMPEXCFG寄存器
#define CMP_GET_REG_CMPEXCFG        (CMPEXCFG)//读取CMPEXCFG寄存器
//-------------功能定义------------//
#define CMP_IT_NUM                  interrupt 21//比较器中断号
/*------------------------------系统管理特殊功能寄存器----------------------------*/
#define SWBS                        0x40//软件复位选择控制位
#define SWRST                       0x20//软件复位操作
#define PD                          0x02//掉电模式控制位
#define IDL                         0x01//空闲模式控制位
#define EAXFR                       0x80//XFR访问控制位
//-------------功能指令------------//
#define POWER_RESET                 do{IAP_CONTR=(SWRST|SWBS);}while(0)//相当于上电重启(数据会丢失)
#define MCU_RESET                   do{IAP_CONTR=(SWRST);     }while(0)//相当于按键复位(数据不会丢失)
#define POWER_DOWN                  do{PCON    |= PD;         }while(0)//掉电模式
#define POWER_IDLE                  do{PCON    |= IDL;        }while(0)//空闲模式
#define EX_SFR_ENABLE               do{P_SW2   |= EAXFR;      }while(0)//打开额外的寄存器地址。
#define EX_SFR_DISABLE              do{P_SW2   &=~EAXFR;      }while(0)//关闭额外的寄存器地址。
//-------------寄存器读取----------//
#define SYS_SET_REG_RSTCFG(value)   do{RSTCFG=(u8)(value);}while(0)//设置RSTCFG寄存器
#define SYS_GET_REG_RSTCFG          (RSTCFG)//读取RSTCFG寄存器
/*-------------------------------掉电定时器功能寄存器-----------------------------*/
#define WKTEN                       0x80//掉电唤醒使能
//-------------功能指令------------//
#define WKT_ON                      do{WKTCH|= WKTEN;}while(0)//打开掉电定时器
#define WKT_OFF                     do{WKTCH&=~WKTEN;}while(0)//关闭掉电定时器
//-------------寄存器读取----------//
#define WKT_SET_REG_COUNT(value)    do{WKTC=(u16)(value);}while(0)//设置掉电定时器
#define WKT_GET_REG_COUNT           (WKTC)//读取掉电定时器
/*--------------------------------定时器0功能寄存器-------------------------------*/
sbit    TF0                         =TCON^5;//定时器0溢出中断标志位
sbit    TR0                         =TCON^4;//定时器0运行控制位
sbit    ET0                         =IE^1;  //定时器0中断允许位
#define T0_GATE                     0x08    //定时器0门控位
#define T0CLKO                      0x01    //定时器0时钟输出控制
#define T0_CT                       0x04    //定时器0计数控制位
#define T0_M1                       0x02    //定时器0模式选择位1
#define T0_M0                       0x01    //定时器0模式选择位0
#define T0x12                       0x80    //定时器0速度控制位 
sbit    PT0                         =IP^1;  //定时器0中断优先级控制位（低）
#define PT0H                        0x02    //定时器0中断优先级控制位（高）
//-------------功能指令------------//
#define TIMER0_POWER_ON             do{TF0=0;TR0=1;}while(0)//开定时器0
#define TIMER0_POWER_OFF            do{TR0=0;}while(0)      //关定时器0
#define TIMER0_IT_ENABLE            do{ET0=1;}while(0)      //开定时器0中断使能
#define TIMER0_IT_DISABLE           do{ET0=0;}while(0)      //关定时器0中断使能
#define TIMER0_GATE_ENABLE          do{TMOD   |= T0_GATE;  }while(0)//开定时器0的门控位
#define TIMER0_GATE_DISABLE         do{TMOD   &=~T0_GATE;  }while(0)//关定时器0的门控位
#define TIMER0_OUT_ON               do{INTCLKO|= T0CLKO;   }while(0)//开定时器0的时钟输出
#define TIMER0_OUT_OFF              do{INTCLKO&=~T0CLKO;   }while(0)//关定时器0的时钟输出
#define TIMER0_SET_MODE_COUNT       do{TMOD   |= T0_CT;    }while(0)//设定定时器0为计数器
#define TIMER0_SET_MODE_TIMER       do{TMOD   &=~T0_CT;    }while(0)//设定定时器0为定时器
#define TIMER0_SET_MODE_AUTO16      do{TMOD=(TMOD&(~0x03));}while(0)//定时器0运行于16位模式
#define TIMER0_SET_MODE_16BIT       do{TMOD=(TMOD&(~0x03))|T0_M0;}while(0)//定时器0运行于16位模式
#define TIMER0_SET_MODE_8BIT        do{TMOD=(TMOD&(~0x03))|T0_M1;}while(0)//定时器0运行于8位自动重载
#define TIMER0_SET_MODE_1T          do{AUXR|= T0x12;}while(0)//设定定时器0为1T模式
#define TIMER0_SET_MODE_12T         do{AUXR&=~T0x12;}while(0)//设定定时器0为12T模式
#define TIMER0_GET_FLAG             (TF0)//定时器0的溢出标志位
#define TIMER0_FLAG_CLS             do{TF0=0;}while(0)//清定时器0的溢出标志位
#define TIMER0_SET_IT_PRIORITY_0    do{IPH&=~PT0H;PT0=0;}while(0)//设置定时器0的优先级为0
#define TIMER0_SET_IT_PRIORITY_1    do{IPH&=~PT0H;PT0=1;}while(0)//设置定时器0的优先级为1
#define TIMER0_SET_IT_PRIORITY_2    do{IPH|= PT0H;PT0=0;}while(0)//设置定时器0的优先级为2
#define TIMER0_SET_IT_PRIORITY_3    do{IPH|= PT0H;PT0=1;}while(0)//设置定时器0的优先级为3
//-------------寄存器读取----------//
#define TIMER0_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x80,value) //设置AUXR寄存器的定时器0部分
#define TIMER0_GET_REG_AUXR         (AUXR & 0x80)                //读取AUXR寄存器的定时器0部分
#define TIMER0_SET_REG_TMOD(value)  REG_IN_MASK(TMOD,0x0F,value) //设置定时器0的工作模式
#define TIMER0_GET_REG_TMOD         (TMOD & 0x0F)                //读取定时器0的工作模式
#define TIMER0_SET_REG_HL(value)    do{TL0=(u8)(value);TH0=(u8)(value>>8);}while(0)//设置定时器0的计数值
#define TIMER0_GET_REG_HL           ((((u16)TH0)<<8)|(u16)TL0)  //获取定时器0的计数值
#define TIMER0_SET_REG_H8(value)    do{TH0=(u8)(value);}while(0)//设置定时器0的计数值的高8位
#define TIMER0_GET_REG_H8           (TH0)                       //获取定时器0的计数值的高8位
#define TIMER0_SET_REG_L8(value)    do{TL0=(u8)(value);}while(0)//设置定时器0的计数值的低8位
#define TIMER0_GET_REG_L8           (TL0)                       //获取定时器0的计数值的低8位
//-------------功能定义------------//
#define TIMER0_IT_NUM               interrupt 1//定时器0的中断号
/*--------------------------------定时器1功能寄存器-------------------------------*/
sbit    TF1                         =TCON^7;//定时器1溢出中断标志位
sbit    TR1                         =TCON^6;//定时器1运行控制位
sbit    ET1                         =IE^3;  //定时器1中断允许位
#define T1_GATE                     0x80    //定时器1门控位
#define T1CLKO                      0x02    //定时器1时钟输出控制
#define T1_CT                       0x40    //定时器1计数控制位
#define T1_M1                       0x20    //定时器1模式选择位1
#define T1_M0                       0x10    //定时器1模式选择位0
#define T1x12                       0x40    //定时器1速度控制位
sbit    PT1                         =IP^3;  //定时器1中断优先级控制位（低）
#define PT1H                        0x08    //定时器1中断优先级控制位（高）
//-------------功能指令------------//
#define TIMER1_POWER_ON             do{TF1=0;TR1=1;}while(0)//开定时器1
#define TIMER1_POWER_OFF            do{TR1=0;}while(0)      //关定时器1
#define TIMER1_IT_ENABLE            do{ET1=1;}while(0)      //开定时器1中断使能
#define TIMER1_IT_DISABLE           do{ET1=0;}while(0)      //关定时器1中断使能
#define TIMER1_GATE_ENABLE          do{TMOD   |= T1_GATE;  }while(0)//开定时器1的门控位
#define TIMER1_GATE_DISABLE         do{TMOD   &=~T1_GATE;  }while(0)//关定时器1的门控位
#define TIMER1_OUT_ON               do{INTCLKO|= T1CLKO;   }while(0)//开定时器1的时钟输出
#define TIMER1_OUT_OFF              do{INTCLKO&=~T1CLKO;   }while(0)//关定时器1的时钟输出
#define TIMER1_SET_MODE_COUNT       do{TMOD   |= T1_CT;    }while(0)//设定定时器1为计数器
#define TIMER1_SET_MODE_TIMER       do{TMOD   &=~T1_CT;    }while(0)//设定定时器1为定时器
#define TIMER1_SET_MODE_AUTO16      do{TMOD=(TMOD&(~0x30));}while(0)//定时器1运行于16位模式
#define TIMER1_SET_MODE_16BIT       do{TMOD=(TMOD&(~0x30))|T1_M0;}while(0)//定时器1运行于16位模式
#define TIMER1_SET_MODE_8BIT        do{TMOD=(TMOD&(~0x30))|T1_M1;}while(0)//定时器1运行于8位自动重载
#define TIMER1_SET_MODE_1T          do{AUXR|= T1x12;}while(0)//设定定时器1为1T模式
#define TIMER1_SET_MODE_12T         do{AUXR&=~T1x12;}while(0)//设定定时器1为12T模式
#define TIMER1_GET_FLAG             (TF1)//定时器1的溢出标志位
#define TIMER1_FLAG_CLS             do{TF1=0;}while(0)//清定时器1的溢出标志位
#define TIMER1_SET_IT_PRIORITY_0    do{IPH&=~PT1H;PT1=0;}while(0)//设置定时器1的优先级为0
#define TIMER1_SET_IT_PRIORITY_1    do{IPH&=~PT1H;PT1=1;}while(0)//设置定时器1的优先级为1
#define TIMER1_SET_IT_PRIORITY_2    do{IPH|= PT1H;PT1=0;}while(0)//设置定时器1的优先级为2
#define TIMER1_SET_IT_PRIORITY_3    do{IPH|= PT1H;PT1=1;}while(0)//设置定时器1的优先级为3
//-------------寄存器读取----------//
#define TIMER1_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x40,value)//设置AUXR寄存器的定时器1部分
#define TIMER1_GET_REG_AUXR         (AUXR & 0x40)               //读取AUXR寄存器的定时器1部分
#define TIMER1_SET_REG_TMOD(value)  REG_IN_MASK(TMOD,0xF0,value)//设置定时器1的工作模式
#define TIMER1_GET_REG_TMOD         (TMOD & 0xF0)               //读取定时器1的工作模式
#define TIMER1_SET_REG_HL(value)    do{TL1=(u8)(value);TH1=(u8)(value>>8);}while(0)//设置定时器1的计数值
#define TIMER1_GET_REG_HL           ((((u16)TH1)<<8)|(u16)TL1)  //获取定时器1的计数值
#define TIMER1_SET_REG_H8(value)    do{TH1=(u8)(value);}while(0)//设置定时器1的计数值的高8位
#define TIMER1_GET_REG_H8           (TH1)                       //获取定时器1的计数值的高8位
#define TIMER1_SET_REG_L8(value)    do{TL1=(u8)(value);}while(0)//设置定时器1的计数值的低8位
#define TIMER1_GET_REG_L8           (TL1)                       //获取定时器1的计数值的低8位
//-------------功能定义------------//
#define TIMER1_IT_NUM               interrupt 3//定时器1的中断号
/*--------------------------------定时器2功能寄存器-------------------------------*/
#define T2R                         0x10//定时器2运行控制位
#define ET2                         0x04//定时器2中断允许位
#define T2CLKO                      0x04//定时器2时钟输出控制
#define T2_CT                       0x08//定时器2计数控制位
#define T2x12                       0x04//定时器2速度控制位
#define T2IF                        0x01//定时器2的中断标志位
//-------------功能指令------------//
#define TIMER2_POWER_ON             do{AUXR|= T2R;}while(0) //打开定时器2
#define TIMER2_POWER_OFF            do{AUXR&=~T2R;}while(0) //关闭定时器2
#define TIMER2_IT_ENABLE            do{IE2 |= ET2;}while(0) //打开定时器2中断
#define TIMER2_IT_DISABLE           do{IE2 &=~ET2;}while(0) //关闭定时器2中断
#define TIMER2_OUT_ON               do{INTCLKO|= T2CLKO;}while(0)//开定时器2的时钟输出
#define TIMER2_OUT_OFF              do{INTCLKO&=~T2CLKO;}while(0)//关定时器2的时钟输出
#define TIMER2_SET_MODE_COUNT       do{AUXR|= T2_CT;}while(0)   //设定定时器2为计数器
#define TIMER2_SET_MODE_TIMER       do{AUXR&=~T2_CT;}while(0)   //设定定时器2为定时器
#define TIMER2_SET_MODE_1T          do{AUXR|= T2x12;}while(0)   //设定定时器2为1T模式
#define TIMER2_SET_MODE_12T         do{AUXR&=~T2x12;}while(0)   //设定定时器2为12T模式
#define TIMER2_IT_CLS               do{AUXINTIF&=~T2IF;}while(0)//清定时器2中断标志
//-------------寄存器读取----------//
#define TIMER2_SET_REG_AUXR(value)  REG_IN_MASK(AUXR,0x0C,value)//设置AUXR寄存器的定时器2部分
#define TIMER2_GET_REG_AUXR         (AUXR&0x0C)//读取AUXR寄存器的定时器2部分
#define TIMER2_SET_REG_HL(value)    do{T2L=(u8)(value);T2H=(u8)(value>>8);}while(0)//设置定时器2的计数值
#define TIMER2_GET_REG_HL           ((((u16)T2H)<<8)|(u16)T2L)//获取定时器2的计数值
#define TIMER2_SET_REG_H8(value)    do{T2H=(u8)(value);}while(0)//设置定时器2的计数值的高8位
#define TIMER2_GET_REG_H8           (T2H)                       //获取定时器2的计数值的高8位
#define TIMER2_SET_REG_L8(value)    do{T2L=(u8)(value);}while(0)//设置定时器2的计数值的低8位
#define TIMER2_GET_REG_L8           (T2L)                       //获取定时器2的计数值的低8位
//-------------功能定义------------//
#define TIMER2_IT_NUM               interrupt 12//定时器2的中断服务号
/*--------------------------------定时器3功能寄存器-------------------------------*/
#define T3R                         0x08//定时器3允许控制位
#define ET3                         0x20//定时器3中断允许位
#define T3CLKO                      0x01//定时器3时钟输出控制
#define T3_CT                       0x04//定时器3计数控制位
#define T3x12                       0x02//定时器3速度控制位
#define T3IF                        0x02//定时器3的中断标志位
//-------------功能指令------------//
#define TIMER3_POWER_ON             do{T4T3M|= T3R;    }while(0)//打开定时器3
#define TIMER3_POWER_OFF            do{T4T3M&=~T3R;    }while(0)//关闭定时器3
#define TIMER3_IT_ENABLE            do{IE2  |= ET3;    }while(0)//打开定时器3中断
#define TIMER3_IT_DISABLE           do{IE2  &=~ET3;    }while(0)//关闭定时器3中断
#define TIMER3_OUT_ON               do{T4T3M|= T3CLKO; }while(0)//开定时器3的时钟输出
#define TIMER3_OUT_OFF              do{T4T3M&=~T3CLKO; }while(0)//关定时器3的时钟输出
#define TIMER3_SET_MODE_COUNT       do{T4T3M|= T3_CT;  }while(0)//设定定时器3为计数器
#define TIMER3_SET_MODE_TIMER       do{T4T3M&=~T3_CT;  }while(0)//设定定时器3为定时器
#define TIMER3_SET_MODE_1T          do{T4T3M|= T3x12;  }while(0)//设定定时器3为1T模式
#define TIMER3_SET_MODE_12T         do{T4T3M&=~T3x12;  }while(0)//设定定时器3为12T模式
#define TIMER3_IT_CLS               do{AUXINTIF&=~T3IF;}while(0)//清定时器3中断标志
//-------------寄存器读取----------//
#define TIMER3_SET_REG_T4T3M(value) REG_IN_MASK(T4T3M,0x0F,value)//设置T4T3M寄存器的定时器3部分
#define TIMER3_GET_REG_T4T3M        (T4T3M & 0x0F)//读取T4T3M寄存器的定时器3部分
#define TIMER3_SET_REG_HL(value)    do{T3L=(u8)(value);T3H=(u8)(value>>8);}while(0)//设置定时器3的计数值
#define TIMER3_GET_REG_HL           ((((u16)T3H)<<8)|(u16)T3L)  //获取定时器3的计数值
#define TIMER3_SET_REG_H8(value)    do{T3H=(u8)(value);}while(0)//设置定时器3的计数值的高8位
#define TIMER3_GET_REG_H8           (T3H)                       //获取定时器3的计数值的高8位
#define TIMER3_SET_REG_L8(value)    do{T3L=(u8)(value);}while(0)//设置定时器3的计数值的低8位
#define TIMER3_GET_REG_L8           (T3L)
//-------------功能定义------------//
#define TIMER3_IT_NUM               interrupt 19//定时器3的中断服务号
/*--------------------------------定时器4功能寄存器-------------------------------*/
#define T4R                         0x80//定时器4允许控制位
#define ET4                         0x40//定时器4中断允许位
#define T4CLKO                      0x10//定时器4时钟输出控制
#define T4_CT                       0x40//定时器4计数控制位
#define T4x12                       0x20//定时器4速度控制位
#define T4IF                        0x04//定时器4的中断标志位
//-------------功能指令------------//
#define TIMER4_POWER_ON             do{T4T3M|= T4R;    }while(0)//打开定时器4
#define TIMER4_POWER_OFF            do{T4T3M&=~T4R;    }while(0)//关闭定时器4
#define TIMER4_IT_ENABLE            do{IE2  |= ET4;    }while(0)//打开定时器4中断
#define TIMER4_IT_DISABLE           do{IE2  &=~ET4;    }while(0)//关闭定时器4中断
#define TIMER4_OUT_ON               do{T4T3M|= T4CLKO; }while(0)//开定时器4的时钟输出
#define TIMER4_OUT_OFF              do{T4T3M&=~T4CLKO; }while(0)//关定时器4的时钟输出
#define TIMER4_SET_MODE_COUNT       do{T4T3M|= T4_CT;  }while(0)//设定定时器4为计数器
#define TIMER4_SET_MODE_TIMER       do{T4T3M&=~T4_CT;  }while(0)//设定定时器4为定时器
#define TIMER4_SET_MODE_1T          do{T4T3M|= T4x12;  }while(0)//设定定时器4为1T模式
#define TIMER4_SET_MODE_12T         do{T4T3M&=~T4x12;  }while(0)//设定定时器4为12T模式
#define TIMER4_IT_CLS               do{AUXINTIF&=~T4IF;}while(0)//清定时器4中断标志
//-------------寄存器读取----------//
#define TIMER4_SET_REG_T4T3M(value) REG_IN_MASK(T4T3M,0xF0,value)//设置T4T3M寄存器的定时器4部分
#define TIMER4_GET_REG_T4T3M        (T4T3M & 0xF0)//读取T4T3M寄存器的定时器4部分
#define TIMER4_SET_REG_HL(value)    do{T4L=(u8)(value);T4H=(u8)(value>>8);}while(0)//设置定时器4的计数值
#define TIMER4_GET_REG_HL           ((((u16)T4H)<<8)|(u16)T4L)  //获取定时器4的计数值
#define TIMER4_SET_REG_H8(value)    do{T4H=(u8)(value);}while(0)//设置定时器4的计数值的高8位
#define TIMER4_GET_REG_H8           (T4H)                       //获取定时器4的计数值的高8位
#define TIMER4_SET_REG_L8(value)    do{T4L=(u8)(value);}while(0)//设置定时器4的计数值的低8位
#define TIMER4_GET_REG_L8           (T4L)
//-------------功能定义------------//
#define TIMER4_IT_NUM               interrupt 20//定时器4的中断服务号
/*-------------------------------串口1特殊功能寄存器------------------------------*/
sbit    ES                          =IE^4;  //串口1中断允许位
sbit    SM0                         =SCON^7;//串口1工作模式选择位0
sbit    SM1                         =SCON^6;//串口1工作模式选择位1
sbit    SM2                         =SCON^5;//串口1多机通信控制位
sbit    REN                         =SCON^4;//串口1接收控制位
sbit    TB8                         =SCON^3;//串口1发送的第9位
sbit    RB8                         =SCON^2;//串口1接收的第9位
sbit    TI                          =SCON^1;//串口1发送中断请求标志位
sbit    RI                          =SCON^0;//串口1接收中断请求标志位
#define SMOD                        0x80    //串口1波特率控制位
#define SMOD0                       0x40    //串口1帧错误检测控制位
#define UART_M0x6                   0x20    //串口1模式0的通讯速度控制位
#define S1ST2                       0x01    //串口1波特率发生器选择位
sbit    PS                          =IP^4;  //串口1中断优先级控制位（低）
#define PSH                         0x10    //串口1中断优先级控制位（高）
//-------------功能指令------------//
#define UART1_IT_ENABLE             do{ES=1;}while(0)   //打开串口1中断
#define UART1_IT_DISABLE            do{ES=0;}while(0)   //关闭串口1中断
#define UART1_TI_CLR                do{TI=0;}while(0)   //清除串口1的发送标志位
#define UART1_GET_TI_FLAG           (TI)                //读取串口1的发送标志位
#define UART1_RI_CLR                do{RI=0;}while(0)   //清除串口1的接受标志位
#define UART1_GET_RI_FLAG           (RI)                //读取串口1的接受标志位
#define UART1_SET_TXD_BYTE9_0       do{TB8=0;TB8=0;}while(0)    //设置串口1发送的第9位为0
#define UART1_SET_TXD_BYTE9_1       do{TB8=1;TB8=1;}while(0)    //设置串口1发送的第9位为1
#define UART1_GET_RXD_BYTE9         (RB8)                       //读取串口1接收的第9位 
#define UART1_SET_PIN(value)        REG_IN_MASK(P_SW1,0xC0,value)//设置串口1的输出引脚
#define UART1_SET_BAUD_1            do{PCON&=~SMOD; }while(0)//设置波特率不倍速
#define UART1_SET_BAUD_2            do{PCON|= SMOD; }while(0)//设置波特率二倍速
#define UART1_SET_CLK_TIMER1        do{AUXR&=~S1ST2;}while(0)//设置串口1的时钟由定时器1产生
#define UART1_SET_CLK_TIMER2        do{AUXR|= S1ST2;}while(0)//设置串口1的时钟由定时器2产生
#define UART1_SET_RXD_ENABLE        do{REN=1;}while(0)  //串口1的接受功能开启
#define UART1_SET_RXD_DISABLE       do{REN=0;}while(0)  //串口1的接受功能关闭
#define UART1_SET_MUX_ENABLE        do{SM2=1;}while(0)  //串口1的多机通信开启
#define UART1_SET_MUX_DISABLE       do{SM2=0;}while(0)  //串口1的多机通信关闭
#define UART1_SET_MODE_S_8          do{SCON=(SCON&(~0xC0))|0x00;}while(0)//串口1的工作模式为同步模式
#define UART1_SET_MODE_A_8_BAUD     do{SCON=(SCON&(~0xC0))|0x40;}while(0)//串口1的工作模式为异步8位模式，可变波特率
#define UART1_SET_MODE_A_9          do{SCON=(SCON&(~0xC0))|0x80;}while(0)//串口1的工作模式为异步9位模式
#define UART1_SET_MODE_A_9_BAUD     do{SCON=(SCON&(~0xC0))|0xC0;}while(0)//串口1的工作模式为异步9位模式，可变波特率
#define UART1_SET_IT_PRIORITY_0     do{IPH&=~PSH;PS=0;}while(0)//设置串口1的优先级为0
#define UART1_SET_IT_PRIORITY_1     do{IPH&=~PSH;PS=1;}while(0)//设置串口1的优先级为1
#define UART1_SET_IT_PRIORITY_2     do{IPH|= PSH;PS=0;}while(0)//设置串口1的优先级为2
#define UART1_SET_IT_PRIORITY_3     do{IPH|= PSH;PS=1;}while(0)//设置串口1的优先级为3
//-------------寄存器读取----------//
#define UART1_SET_REG_SADDR(value)  do{SADDR=(u8)(value);}while(0)//设置串口1的地址
#define UART1_GET_REG_SADDR         (SADDR)                       //读取串口1的地址
#define UART1_SET_REG_SADEN(value)  do{SADEN=(u8)(value);}while(0)//设置串口1的地址掩码
#define UART1_GET_REG_SADEN         (SADEN)                       //读取串口1的地址掩码
#define UART1_SET_REG_SBUF(value)   do{SBUF =(u8)(value);}while(0)//设置串口1要发送的数据
#define UART1_GET_REG_SBUF          (SBUF)                        //读取串口1接收到的数据
#define UART1_SET_REG_SCON(value)   do{SCON =(u8)(value);}while(0)//设置SCON寄存器
#define UART1_GET_REG_SCON          (SCON)                        //读取SCON寄存器
#define UART1_SET_REG_PCON(value)   REG_IN_MASK(PCON,0xC0,value)  //设置PCON寄存器的串口1部分
#define UART1_GET_REG_PCON          (PCON & 0xC0)                 //读取PCON寄存器的串口1部分
#define UART1_SET_REG_AUXR(value)   REG_IN_MASK(AUXR,0x21,value)//设置AUXR寄存器的串口1部分
#define UART1_GET_REG_AUXR          (AUXR & 0x21)                 //读取AUXR寄存器的串口1部分
//-------------功能定义------------//
#define UART1_IT_NUM                interrupt 4//串口1中断号
/*-------------------------------串口2特殊功能寄存器------------------------------*/
#define ES2                         0x01//串口2中断允许位
#define S2SM0                       0x80//串口2工作模式选择位
#define S2SM2                       0x20//串口2多机通信控制位
#define S2REN                       0x10//串口2接收控制位
#define S2TB8                       0x08//串口2发送的第9位
#define S2RB8                       0x04//串口2接收的第9位
#define S2TI                        0x02//串口2发送中断请求标志位
#define S2RI                        0x01//串口2接收中断请求标志位
#define PS2                         0x01//串口2中断优先级控制位（低）
#define PS2H                        0x01//串口2中断优先级控制位（高）
//-------------功能指令------------//
#define UART2_IT_ENABLE             do{IE2  |= ES2; }while(0)//打开串口2中断
#define UART2_IT_DISABLE            do{IE2  &=~ES2; }while(0)//关闭串口2中断
#define UART2_TI_CLR                do{S2CON&=~S2TI;}while(0)//清除串口2的发送标志位
#define UART2_GET_TI_FLAG           (S2CON & S2TI)           //读取串口2的发送标志位
#define UART2_RI_CLR                do{S2CON&=~S2RI;}while(0)//清除串口2的接受标志位
#define UART2_GET_RI_FLAG           (S2CON & S2RI)           //读取串口2的接受标志位
#define UART2_SET_TXD_BYTE9_0       do{S2CON&=~S2TB8;S2CON&=~S2TB8;}while(0)//设置串口2发送的第9位为0
#define UART2_SET_TXD_BYTE9_1       do{S2CON|= S2TB8;S2CON|= S2TB8;}while(0)//设置串口2发送的第9位为1
#define UART2_GET_RXD_BYTE9         (S2CON & S2RB8)                         //读取串口2接收的第9位 
#define UART2_SET_PIN(value)        REG_IN_MASK(P_SW2,0x01,value)//设置串口2的输出引脚
#define UART2_SET_RXD_ENABLE        do{S2CON|= S2REN;}while(0)//串口2的接受功能开启
#define UART2_SET_RXD_DISABLE       do{S2CON&=~S2REN;}while(0)//串口2的接受功能关闭
#define UART2_SET_MUX_ENABLE        do{S2CON|= S2SM2;}while(0)//串口2的多机通信开启
#define UART2_SET_MUX_DISABLE       do{S2CON&=~S2SM2;}while(0)//串口2的多机通信关闭
#define UART2_SET_MODE_A_8_BAUD     do{S2CON&=~S2SM0;}while(0)//串口2的工作模式为异步8位模式，可变波特率
#define UART2_SET_MODE_A_9_BAUD     do{S2CON|= S2SM0;}while(0)//串口2的工作模式为异步9位模式，可变波特率
#define UART2_SET_IT_PRIORITY_0     do{IP2H&=~PS2H;IP2&=~PS2;}while(0)//设置串口2的优先级为0
#define UART2_SET_IT_PRIORITY_1     do{IP2H&=~PS2H;IP2|= PS2;}while(0)//设置串口2的优先级为1
#define UART2_SET_IT_PRIORITY_2     do{IP2H|= PS2H;IP2&=~PS2;}while(0)//设置串口2的优先级为2
#define UART2_SET_IT_PRIORITY_3     do{IP2H|= PS2H;IP2|= PS2;}while(0)//设置串口2的优先级为3
//-------------寄存器读取----------//
#define UART2_SET_REG_S2BUF(value)  do{S2BUF =(u8)(value);}while(0)//设置串口2要发送的数据
#define UART2_GET_REG_S2BUF         (S2BUF)                        //读取串口2接收到的数据
#define UART2_SET_REG_S2CON(value)  do{S2CON =(u8)(value);}while(0)//设置S2CON寄存器
#define UART2_GET_REG_S2CON         (S2CON)                        //读取S2CON寄存器
//-------------功能定义------------//
#define UART2_IT_NUM                interrupt 8//串口2中断号
/*-------------------------------串口3特殊功能寄存器------------------------------*/
#define ES3                         0x08//串口3中断允许位
#define S3SM0                       0x80//串口3工作模式选择位
#define S3ST3                       0x40//串口3波特率发生器选择位
#define S3SM2                       0x20//串口3多机通信控制位
#define S3REN                       0x10//串口3接收控制位
#define S3TB8                       0x08//串口3发送的第9位
#define S3RB8                       0x04//串口3接收的第9位
#define S3TI                        0x02//串口3发送中断请求标志位
#define S3RI                        0x01//串口3接收中断请求标志位
//-------------功能指令------------//
#define UART3_IT_ENABLE             do{IE2  |= ES3; }while(0)//打开串口3中断
#define UART3_IT_DISABLE            do{IE2  &=~ES3; }while(0)//关闭串口3中断
#define UART3_TI_CLR                do{S3CON&=~S3TI;}while(0)//清除串口3的发送标志位
#define UART3_GET_TI_FLAG           (S3CON & S3TI)           //读取串口3的发送标志位
#define UART3_RI_CLR                do{S3CON&=~S3RI;}while(0)//清除串口3的接受标志位
#define UART3_GET_RI_FLAG           (S3CON & S3RI)           //读取串口3的接受标志位
#define UART3_SET_TXD_BYTE9_0       do{S3CON&=~S3TB8;S3CON&=~S3TB8;}while(0)//设置串口3发送的第9位为0
#define UART3_SET_TXD_BYTE9_1       do{S3CON|= S3TB8;S3CON|= S3TB8;}while(0)//设置串口3发送的第9位为1
#define UART3_GET_RXD_BYTE9         (S3CON & S3RB8)//读取串口3接收的第9位 
#define UART3_SET_PIN(value)        REG_IN_MASK(P_SW2,0x02,value)//设置串口3的输出引脚
#define UART3_SET_CLK_TIMER2        do{S3CON&=~S3ST3;}while(0)//设置串口3的时钟由定时器2产生
#define UART3_SET_CLK_TIMER3        do{S3CON|= S3ST3;}while(0)//设置串口3的时钟由定时器3产生
#define UART3_SET_RXD_ENABLE        do{S3CON|= S3REN;}while(0)//串口3的接受功能开启
#define UART3_SET_RXD_DISABLE       do{S3CON&=~S3REN;}while(0)//串口3的接受功能关闭
#define UART3_SET_MUX_ENABLE        do{S3CON|= S3SM2;}while(0)//串口3的多机通信开启
#define UART3_SET_MUX_DISABLE       do{S3CON&=~S3SM2;}while(0)//串口3的多机通信关闭
#define UART3_SET_MODE_A_8_BAUD     do{S3CON&=~S3SM0;}while(0)//串口3的工作模式为异步8位模式，可变波特率
#define UART3_SET_MODE_A_9_BAUD     do{S3CON|= S3SM0;}while(0)//串口3的工作模式为异步9位模式，可变波特率
//-------------寄存器读取----------//
#define UART3_SET_REG_S3BUF(value)  do{S3BUF =((u8)(value));}while(0)//设置串口3要发送的数据
#define UART3_GET_REG_S3BUF         (S3BUF)                          //读取串口3接收到的数据
#define UART3_SET_REG_S3CON(value)  do{S3CON =((u8)(value));}while(0)//设置S3CON寄存器
#define UART3_GET_REG_S3CON         (S3CON)                          //读取S3CON寄存器
//-------------功能定义------------//
#define UART3_IT_NUM                interrupt 17//串口3中断号
/*-------------------------------串口4特殊功能寄存器------------------------------*/
#define ES4                         0x10//串口4中断允许位
#define S4SM0                       0x80//串口4工作模式选择位
#define S4ST4                       0x40//串口4波特率发生器选择位
#define S4SM2                       0x20//串口4多机通信控制位
#define S4REN                       0x10//串口4接收控制位
#define S4TB8                       0x08//串口4发送的第9位
#define S4RB8                       0x04//串口4接收的第9位
#define S4TI                        0x02//串口4发送中断请求标志位
#define S4RI                        0x01//串口4接收中断请求标志位
//-------------功能指令------------//
#define UART4_IT_ENABLE             do{IE2  |= ES4; }while(0)//打开串口4中断
#define UART4_IT_DISABLE            do{IE2  &=~ES4; }while(0)//关闭串口4中断
#define UART4_TI_CLR                do{S4CON&=~S4TI;}while(0)//清除串口4的发送标志位
#define UART4_GET_TI_FLAG           (S4CON & S4TI)           //读取串口4的发送标志位
#define UART4_RI_CLR                do{S4CON&=~S4RI;}while(0)//清除串口4的接受标志位
#define UART4_GET_RI_FLAG           (S4CON & S4RI)           //读取串口4的接受标志位
#define UART4_SET_TXD_BYTE9_0       do{S4CON&=~S4TB8;S4CON&=~S4TB8;}while(0)//设置串口4发送的第9位为0
#define UART4_SET_TXD_BYTE9_1       do{S4CON|= S4TB8;S4CON|= S4TB8;}while(0)//设置串口4发送的第9位为1
#define UART4_GET_RXD_BYTE9         (S4CON & S4RB8)//读取串口4接收的第9位 
#define UART4_SET_PIN(value)        REG_IN_MASK(P_SW2,0x04,value)//设置串口4的输出引脚
#define UART4_SET_CLK_TIMER2        do{S4CON&=~S4ST4;}while(0)//设置串口4的时钟由定时器2产生
#define UART4_SET_CLK_TIMER4        do{S4CON|= S4ST4;}while(0)//设置串口4的时钟由定时器4产生
#define UART4_SET_RXD_ENABLE        do{S4CON|= S4REN;}while(0)//串口4的接受功能开启
#define UART4_SET_RXD_DISABLE       do{S4CON&=~S4REN;}while(0)//串口4的接受功能关闭
#define UART4_SET_MUX_ENABLE        do{S4CON|= S4SM2;}while(0)//串口4的多机通信开启
#define UART4_SET_MUX_DISABLE       do{S4CON&=~S4SM2;}while(0)//串口4的多机通信关闭
#define UART4_SET_MODE_A_8_BAUD     do{S4CON&=~S4SM0;}while(0)//串口4的工作模式为异步8位模式，可变波特率
#define UART4_SET_MODE_A_9_BAUD     do{S4CON|= S4SM0;}while(0)//串口4的工作模式为异步9位模式，可变波特率
//-------------寄存器读取----------//
#define UART4_SET_REG_S4BUF(value)  do{S4BUF =(u8)(value);}while(0)//设置串口4要发送的数据
#define UART4_GET_REG_S4BUF         (S4BUF)                        //读取串口4接收到的数据
#define UART4_SET_REG_S4CON(value)  do{S4CON =(u8)(value);}while(0)//设置S4CON寄存器
#define UART4_GET_REG_S4CON         (S4CON)                        //读取S4CON寄存器
//-------------功能定义------------//
#define UART4_IT_NUM                interrupt 18//串口4中断号
/*-------------------------------MDU16特殊功能寄存器------------------------------*/
#define MDOV                        0x40//MDU溢出标志位
#define MDRST                       0x02//MDU复位控制位
#define ENOP                        0x01//MDU使能与状态位
//-------------功能指令------------//
#define MDU16_RESET                 do{OPCON=MDRST;}while(0)//复位乘除单元
#define MDU16_START                 do{OPCON=ENOP; }while(0)//开始计算
#define MDU16_GET_END_FLAG          (OPCON & ENOP)          //获取计算结束标志位
#define MDU16_GET_MDOV_FLAG         (OPCON & MDOV)          //获取计算结果溢出位
#define MDU16_SET_16MUL             do{ARCON=0x80; }while(0)//16位乘法
#define MDU16_SET_16DIV             do{ARCON=0xa0; }while(0)//16位除法
#define MDU16_SET_32DIV             do{ARCON=0xc0; }while(0)//32位除法
//-------------寄存器读取----------//
#define MDU16_SET_REG_ARCON(value)  do{ARCON=(u8)(value);}while(0)//设置ARCON寄存器
#define MDU16_GET_REG_ARCON         (ARCON)//读取ARCON寄存器
#define MDU16_SET_REG_OPCON(value)  do{OPCON=(u8)(value);}while(0)//设置OPCON寄存器
#define MDU16_GET_REG_OPCON         (OPCON)//读取OPCON寄存器
/*--------------------------------IIC特殊功能寄存器-------------------------------*/
#define ENI2C                       0x80//IIC电源使能位
#define MSSL                        0x40//IIC主从机选择
#define EMSI                        0x80//IIC主机中断使能位
#define MSBUSY                      0x80//IIC主机模式时状态位
#define MSIF                        0x40//IIC主机模式时的中断请求位
#define MSACKI                      0x02//IIC主机模式时接收到的ACK
#define MSACKO                      0x01//IIC主机模式时要发送的ACK
#define WDTA                        0x01//IIC自动发送ack控制位
#define ESTAI                       0x40//IIC从机模式时接收START信号中断允许位
#define ERXI                        0x20//IIC从机模式时接收到1字节数据后中断允许位
#define ETXI                        0x10//IIC从机模式时发送完1字节数据后中断允许位
#define ESTOI                       0x08//IIC从机模式时接收STOP信号中断允许位
#define SLRST                       0x01//IIC复位从机模式
#define SLBUSY                      0x80//IIC从机模式时IIC控制器状态位
#define STAIF                       0x40//IIC从机模式时接收START信号中断请求位
#define RXIF                        0x20//IIC从机模式时接收到1字节数据后中断请求位
#define TXIF                        0x10//IIC从机模式时发送完1字节数据后中断请求位
#define STOIF                       0x08//IIC从机模式时接收STOP信号中断请求位
#define SLACKI                      0x02//IIC从机模式时接收到的ACK
#define SLACKO                      0x01//IIC从机模式时将要发送的ACK
#define PI2C                        0x40//IIC中断优先级控制位（低）
#define PI2CH                       0x40//IIC中断优先级控制位（高）
//-------------功能指令------------//
#define IIC_POWER_ON                do{I2CCFG  |= ENI2C;}while(0)//打开IIC电源
#define IIC_POWER_OFF               do{I2CCFG  &=~ENI2C;}while(0)//关闭IIC电源
#define IIC_SET_MODE_MASTER         do{I2CCFG  |= MSSL; }while(0)//设置IIC为主机模式
#define IIC_SET_MODE_SLAVE          do{I2CCFG  &=~MSSL; }while(0)//设置IIC为从机模式
#define IIC_SET_AUTOACK_ENABLE      do{I2CMSAUX|= WDTA; }while(0)//设置自动发送ACK
#define IIC_SET_AUTOACK_DISABLE     do{I2CMSAUX&=~WDTA; }while(0)//取消自动发送ACK
#define IIC_SET_SPEED(value)        REG_IN_MASK(I2CCFG,0x3F,value)//设置IIC的输出速度
#define IIC_GET_IT_FLAG             (I2CMSST & MSIF)             //获取IIC中断标志位
#define IIC_IT_CLS                  do{I2CMSST&=~MSIF;}while(0)  //清除IIC中断标志位
#define IIC_GET_ACK                 (I2CMSST & MSACKI)           //获取收到的ACK信号
#define IIC_SET_PIN(value)          REG_IN_MASK(P_SW2,0x30,value)//设置IIC的输出引脚
#define IIC_SET_IT_PRIORITY_0       do{IP2H&=~PI2CH;IP2&=~PI2C;}while(0)//设置IIC的优先级为0
#define IIC_SET_IT_PRIORITY_1       do{IP2H&=~PI2CH;IP2|= PI2C;}while(0)//设置IIC的优先级为1
#define IIC_SET_IT_PRIORITY_2       do{IP2H|= PI2CH;IP2&=~PI2C;}while(0)//设置IIC的优先级为2
#define IIC_SET_IT_PRIORITY_3       do{IP2H|= PI2CH;IP2|= PI2C;}while(0)//设置IIC的优先级为3
#define IIC_CMD_START               do{I2CMSCR=(EMSI|0x01);}while(0)//发送一个START信号
#define IIC_CMD_TX_DATA             do{I2CMSCR=(EMSI|0x02);}while(0)//发送一个字节数据
#define IIC_CMD_RX_ACK              do{I2CMSCR=(EMSI|0x03);}while(0)//接收一个ACK信号
#define IIC_CMD_RX_DATA             do{I2CMSCR=(EMSI|0x04);}while(0)//接收一个字节数据
#define IIC_CMD_TX_ACK              do{I2CMSST=0x00;I2CMSCR=(EMSI|0x05);}while(0)//发送一个ACK信号
#define IIC_CMD_TX_NACK             do{I2CMSST=0x01;I2CMSCR=(EMSI|0x05);}while(0)//发送一个nACK信号
#define IIC_CMD_STOP                do{I2CMSCR=(EMSI|0x06);}while(0)//发送一个STOP信号
//-------------寄存器读取----------//
#define IIC_SET_REG_CFG(value)      do{I2CCFG=(u8)(value);}while(0)//设置IICCFG寄存器
#define IIC_GET_REG_CFG             (I2CCFG)//读取IICCFG寄存器
#define IIC_SET_REG_MSCR(value)     do{I2CMSCR=(u8)(value);}while(0)//设置IICMSCR寄存器
#define IIC_GET_REG_MSCR            (I2CMSCR)//读取IICMSCR寄存器
#define IIC_SET_REG_MSST(value)     do{I2CMSST=(u8)(value);}while(0)//设置I2CMSST寄存器
#define IIC_GET_REG_MSST            (I2CMSST)//读取I2CMSST寄存器
#define IIC_SET_REG_MSAUX(value)    do{I2CMSAUX=(u8)(value);}while(0)//设置I2CMSAUX寄存器
#define IIC_GET_REG_MSAUX           (I2CMSAUX)//读取I2CMSAUX寄存器
#define IIC_SET_REG_DATA(value)     do{I2CTXD=(u8)(value);}while(0)//设置发送数据寄存器
#define IIC_GET_REG_DATA            (I2CRXD)  //读取接收数据寄存器
//-------------功能定义------------//
#define IIC_IT_NUM                  interrupt 24//IIC中断号
/*--------------------------------ADC特殊功能寄存器------------------------------*/
sbit    EADC                        =IE^5;//ADC转换中断允许位
#define ADC_POWER                   0x80  //ADC电源控制位
#define ADC_START                   0x40  //ADC转换启动控制位
#define ADC_FLAG                    0x20  //ADC转换结束标志位
#define ADC_EPWMT                   0x10  //ADC与PWM协同控制标志位
#define ADC_RESFMT                  0x20  //ADC转换结果格式控制位
sbit    PADC                        =IP^5;//ADC中断优先级控制位（低）
#define PADCH                       0x20  //ADC中断优先级控制位（高）
//-------------功能指令------------//
#define ADC_POWER_ON                do{ADC_CONTR|= ADC_POWER;}while(0)//打开ADC的电源
#define ADC_POWER_OFF               do{ADC_CONTR&=~ADC_POWER;}while(0)//关闭ADC的电源
#define ADC_IT_ENABLE               do{EADC=1;}while(0)               //打开ADC中断
#define ADC_IT_DISABLE              do{EADC=0;}while(0)               //关闭ADC中断
#define ADC_PWM_ENABLE               do{ADC_CONTR|= ADC_EPWMT;}while(0)//打开ADC与PWM关联
#define ADC_PWM_DISABLE              do{ADC_CONTR&=~ADC_EPWMT;}while(0)//关闭ADC与PWM关联
#define ADC_GET_IT_FLAG             (ADC_CONTR & ADC_FLAG)            //获取AD转换结束标志位
#define ADC_IT_CLS                  do{ADC_CONTR&=~ADC_FLAG;}while(0) //清除AD转换结束标志位
#define ADC_MEASURE_ON              do{ADC_CONTR|=ADC_START;}while(0) //开始AD转换
#define ADC_SET_CHANNELS(value)     REG_IN_MASK(ADC_CONTR,0x0F,value)//设置ADC的转换通道
#define ADC_SET_ALIGN_LEFT          do{ADC_CFG&=~ADC_RESFMT;}while(0)//设置ADC的结果左对齐排列
#define ADC_SET_ALIGN_RIGHT         do{ADC_CFG|= ADC_RESFMT;}while(0)//设置ADC的结果右对齐排列
#define ADC_SET_SPEED(value)        REG_IN_MASK(ADC_CFG,0x0F,value)//设置ADC的转换速度
#define ADC_SET_IT_PRIORITY_0       do{IPH&=~PADCH;PADC=0;}while(0)//设置ADC的优先级为0
#define ADC_SET_IT_PRIORITY_1       do{IPH&=~PADCH;PADC=1;}while(0)//设置ADC的优先级为1
#define ADC_SET_IT_PRIORITY_2       do{IPH|= PADCH;PADC=0;}while(0)//设置ADC的优先级为2
#define ADC_SET_IT_PRIORITY_3       do{IPH|= PADCH;PADC=1;}while(0)//设置ADC的优先级为3
//-------------寄存器读取----------//
#define ADC_SET_REG_CONTR(value)    do{ADC_CONTR=(u8)(value);}while(0)//设置ADC_CONTR寄存器
#define ADC_GET_REG_CONTR           (ADC_CONTR)                       //获取ADC_CONTR寄存器的值
#define ADC_SET_REG_CFG(value)      do{ADC_CFG=(u8)(value);}while(0)  //设置ADC_CFG寄存器
#define ADC_GET_REG_CFG             (ADC_CFG)                         //获取ADC_CFG寄存器的值
#define ADC_SET_REG_EXCFG(value)    do{ADCEXCFG=(u8)(value);}while(0) //设置ADC_EXCFG寄存器
#define ADC_GET_REG_EXCFG           (ADCEXCFG)                        //获取ADC_EXCFG寄存器的值
#define ADC_SET_REG_TIM(value)      do{ADC_TIM=(u8)(value);}while(0)  //设置ADC_TIM寄存器
#define ADC_GET_REG_TIM             (ADC_TIM)                         //获取ADC_TIM寄存器的值
#define ADC_GET_REG_RES_HL          ((((u16)ADC_RES)<<8)|(u16)ADC_RESL)//获取ADC结果寄存器的全部
#define ADC_GET_REG_RES_H8          (ADC_RES )  //获取ADC结果寄存器的高8位
#define ADC_GET_REG_RES_L8          (ADC_RESL)  //获取ADC结果寄存器的低8位
//-------------功能定义------------//
#define ADC_IT_NUM                  interrupt 5//ADC的中断号
/*-------------------------------I/O口特殊功能寄存器-----------------------------*/
sbit    P00                         =P0^0;  //P0.0口
sbit    P01                         =P0^1;  //P0.1口
sbit    P02                         =P0^2;  //P0.2口
sbit    P03                         =P0^3;  //P0.3口
sbit    P04                         =P0^4;  //P0.4口
sbit    P05                         =P0^5;  //P0.5口
sbit    P06                         =P0^6;  //P0.6口
sbit    P07                         =P0^7;  //P0.7口
sbit    P10                         =P1^0;  //P1.0口
sbit    P11                         =P1^1;  //P1.1口
sbit    P12                         =P1^2;  //P1.2口
sbit    P13                         =P1^3;  //P1.3口
sbit    P14                         =P1^4;  //P1.4口
sbit    P15                         =P1^5;  //P1.5口
sbit    P16                         =P1^6;  //P1.6口
sbit    P17                         =P1^7;  //P1.7口
sbit    P20                         =P2^0;  //P2.0口
sbit    P21                         =P2^1;  //P2.1口
sbit    P22                         =P2^2;  //P2.2口
sbit    P23                         =P2^3;  //P2.3口
sbit    P24                         =P2^4;  //P2.4口
sbit    P25                         =P2^5;  //P2.5口
sbit    P26                         =P2^6;  //P2.6口
sbit    P27                         =P2^7;  //P2.7口
sbit    P30                         =P3^0;  //P3.0口
sbit    P31                         =P3^1;  //P3.1口
sbit    P32                         =P3^2;  //P3.2口
sbit    P33                         =P3^3;  //P3.3口
sbit    P34                         =P3^4;  //P3.4口
sbit    P35                         =P3^5;  //P3.5口
sbit    P36                         =P3^6;  //P3.6口
sbit    P37                         =P3^7;  //P3.7口
sbit    P40                         =P4^0;  //P4.0口
sbit    P41                         =P4^1;  //P4.1口
sbit    P42                         =P4^2;  //P4.2口
sbit    P43                         =P4^3;  //P4.3口
sbit    P44                         =P4^4;  //P4.4口
sbit    P45                         =P4^5;  //P4.5口
sbit    P46                         =P4^6;  //P4.6口
sbit    P47                         =P4^7;  //P4.7口
sbit    P50                         =P5^0;  //P5.0口
sbit    P51                         =P5^1;  //P5.1口
sbit    P52                         =P5^2;  //P5.2口
sbit    P53                         =P5^3;  //P5.3口
sbit    P54                         =P5^4;  //P5.4口
sbit    P55                         =P5^5;  //P5.5口
sbit    P56                         =P5^6;  //P5.6口
sbit    P57                         =P5^7;  //P5.7口
sbit    P60                         =P6^0;  //P6.0口
sbit    P61                         =P6^1;  //P6.1口
sbit    P62                         =P6^2;  //P6.2口
sbit    P63                         =P6^3;  //P6.3口
sbit    P64                         =P6^4;  //P6.4口
sbit    P65                         =P6^5;  //P6.5口
sbit    P66                         =P6^6;  //P6.6口
sbit    P67                         =P6^7;  //P6.7口
sbit    P70                         =P7^0;  //P7.0口
sbit    P71                         =P7^1;  //P7.1口
sbit    P72                         =P7^2;  //P7.2口
sbit    P73                         =P7^3;  //P7.3口
sbit    P74                         =P7^4;  //P7.4口
sbit    P75                         =P7^5;  //P7.5口
sbit    P76                         =P7^6;  //P7.6口
sbit    P77                         =P7^7;  //P7.7口
/*--------------------------------内核特殊功能寄存器------------------------------*/
sbit    CY                          =PSW^7; //进位标志位
sbit    AC                          =PSW^6; //辅助进位标志位
sbit    F0                          =PSW^5; //留给用户的标志位
sbit    RS1                         =PSW^4; //工作寄存器选择位（高位）
sbit    RS0                         =PSW^3; //工作寄存器选择位（低位）
sbit    OV                          =PSW^2; //溢出标志位
sbit    P                           =PSW^0; //奇偶校验位
#define IF_ODD(_OE_)                ACC=_OE_;if(P)//判断是不是奇数
/*------------------------------时钟管理特殊功能寄存器----------------------------*/
//-------------功能指令------------//
#define CLK_SET_SOURCE_HSI          do{CKSEL=((CKSEL&(~0x03))|0x00);}while(0)//设置时钟源为内部高速IRC
#define CLK_SET_SOURCE_HSE          do{CKSEL=((CKSEL&(~0x03))|0x01);}while(0)//设置时钟源为外部高速晶振
#define CLK_SET_SOURCE_LSE          do{CKSEL=((CKSEL&(~0x03))|0x02);}while(0)//设置时钟源为外部低速晶振
#define CLK_SET_SOURCE_LSI          do{CKSEL=((CKSEL&(~0x03))|0x03);}while(0)//设置时钟源为内部低速IRC
#define CLK_HSI_POWER_ON            do{HIRCCR=((HIRCCR&(~0x81))|0x80);}while(!(HIRCCR&0x01))//开启HSI电源
#define CLK_HSI_POWER_OFF           do{HIRCCR=0x00;}while(0)//关闭HSI电源
#define CLK_HSE_A_POWER_ON          do{XOSCCR=((XOSCCR&(~0xC1))|0x80);}while(!(XOSCCR&0x01))//开启HSE电源，并设置成有源晶振
#define CLK_HSE_P_POWER_ON          do{XOSCCR=((XOSCCR&(~0xC1))|0xC0);}while(!(XOSCCR&0x01))//开启HSE电源，并设置成无源晶振
#define CLK_HSE_POWER_OFF           do{XOSCCR=0x00;}while(0)//关闭HSE电源
#define CLK_HSE_GAIN_ENABLE         do{XOSCCR|= 0x20;}while(0)//打开外部高速晶振增益
#define CLK_HSE_GAIN_DISABLE        do{XOSCCR&=~0x20;}while(0)//关闭外部高速晶振增益
#define CLK_LSE_POWER_ON            do{X32KCR=((X32KCR&(~0x81))|0x80);}while(!(X32KCR&0x01))//开启LSE电源
#define CLK_LSE_POWER_OFF           do{X32KCR  = 0x00;}while(0)//关闭LSE电源
#define CLK_LSE_GAIN_ENABLE         do{X32KCR |= 0x40;}while(0)//打开外部低速晶振增益
#define CLK_LSE_GAIN_DISABLE        do{X32KCR &=~0x40;}while(0)//关闭外部低速晶振增益
#define CLK_LSI_POWER_ON            do{IRC32KCR=((IRC32KCR&(~0x81))|0x80);}while(!(IRC32KCR&0x01))//开启LSI电源
#define CLK_LSI_POWER_OFF           do{IRC32KCR= 0x00;}while(0)//关闭LSI电源
#define CLK_SET_OUT_TO_P54_FA       do{CKSEL  &=~0x08;}while(0)//设置时钟输出脚为P5.4(适用于STC8F和STC8A)
#define CLK_SET_OUT_TO_P16_FA       do{CKSEL  |= 0x08;}while(0)//设置时钟输出脚为P1.6(适用于STC8F和STC8A)
#define CLK_OUT_SET_DIV_FA(value)   REG_IN_MASK(CKSEL,0xF0,value)//设置时钟输出分频(适用于STC8F和STC8A)
#define CLK_SET_OUT_TO_P54_GH       do{MCLKOCR&=~0x80;}while(0)//设置时钟输出脚为P5.4(适用于STC8G和STC8H)
#define CLK_SET_OUT_TO_P16_GH       do{MCLKOCR|= 0x80;}while(0)//设置时钟输出脚为P1.6(适用于STC8G和STC8H)
#define CLK_OUT_SET_DIV_GH(value)   REG_IN_MASK(MCLKOCR,0x7F,value)//设置时钟输出分频(适用于STC8G和STC8H)
//-------------寄存器读取----------//
#define CLK_SET_REG_CLKDIV(value)   do{CLKDIV=(u8)value;}while(0)//设置CLKDIV寄存器
#define CLK_GET_REG_CLKDIV          (CLKDIV)//获取CLKDIV寄存器
/*--------------------------------中断特殊功能寄存器-----------------------------*/
sbit    EA                          =IE^7;//总中断允许控制位
sbit    ELVD                        =IE^6;//低压检测中断允许位
#define LVDF                        0x20  //低压检测中断请求标志
//-------------功能指令------------//
#define EA_ENABLE                   do{EA=1;}while(0)//打开总中断开关
#define EA_DISABLE                  do{EA=0;}while(0)//关闭总中断开关
#define LVD_IT_ENABLE               do{ELVD=1;}while(0)//打开低压中断开关
#define LVD_IT_DISABLE              do{ELVD=0;}while(0)//关闭低压中断开关
#define LVD_GET_FLAG                ( & LVDF)
/*--------------------------------LCM特殊功能寄存器------------------------------*/
#define LCMIFIE                     0x80//LCM接口中断使能控制位
#define D16_D8                      0x02//LCM接口数据宽度控制位
#define M68_I80                     0x01//LCM接口模式选择位
#define ELCMIF                      0x80//LCM接口使能控制位
#define LCMIFIF                     0x01//LCM接口中断请求标志位
//-------------功能指令------------//
#define LCM_IT_ENABLE               do{LCMIFCFG|= LCMIFIE;}while(0)//打开LCM接口中断
#define LCM_IT_DISABLE              do{LCMIFCFG&=~LCMIFIE;}while(0)//关闭LCM接口中断
#define LCM_SET_IT_PRIORITY_0       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x00;}while(0)//设置LCM中断的优先级为0
#define LCM_SET_IT_PRIORITY_1       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x10;}while(0)//设置LCM中断的优先级为1
#define LCM_SET_IT_PRIORITY_2       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x20;}while(0)//设置LCM中断的优先级为2
#define LCM_SET_IT_PRIORITY_3       do{LCMIFCFG=(LCMIFCFG&(~0x30))|0x30;}while(0)//设置LCM中断的优先级为3
#define LCM_SET_DATABUS_NA_P2       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x00;}while(0)//设置LCM的数据线为P2
#define LCM_SET_DATABUS_NA_P6       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x04;}while(0)//设置LCM的数据线为P6
#define LCM_SET_DATABUS_P2_P0       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x02;}while(0)//设置LCM的数据线为P2~P0
#define LCM_SET_DATABUS_P6_P2       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x06;}while(0)//设置LCM的数据线为P6~P2
#define LCM_SET_DATABUS_P2_P7       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x0A;}while(0)//设置LCM的数据线为P2~P7
#define LCM_SET_DATABUS_P6_P7       do{LCMIFCFG=(LCMIFCFG&(~0x0E))|0x0E;}while(0)//设置LCM的数据线为P6~P7
#define LCM_SET_MODE_I8080          do{LCMIFCFG&=~M68_I80;}while(0)//设置LCM的工作模式是8080
#define LCM_SET_MODE_M6800          do{LCMIFCFG|= M68_I80;}while(0)//设置LCM的工作模式是6800
#define LCM_SET_P41_P44_P43         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x00;}while(0)//设置RS、RD、WR分别为P41、P44、P43
#define LCM_SET_P41_P37_P46         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x20;}while(0)//设置RS、RD、WR分别为P41、P37、P46
#define LCM_SET_P41_P42_P40         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x40;}while(0)//设置RS、RD、WR分别为P41、P42、P40
#define LCM_SET_P40_P37_P36         do{LCMIFCFG2=(LCMIFCFG2&(~0x60))|0x60;}while(0)//设置RS、RD、WR分别为P40、P37、P36
#define LCM_WRITE_CMD               do{LCMIFCR=(ELCMIF|0x04);}while(0)//向LCM接口发送一个指令
#define LCM_WRITE_DATA              do{LCMIFCR=(ELCMIF|0x05);}while(0)//向LCM接口发送一个数据
#define LCM_READ_CMD                do{LCMIFCR=(ELCMIF|0x06);}while(0)//向LCM接口接收一个指令
#define LCM_READ_DATA               do{LCMIFCR=(ELCMIF|0x07);}while(0)//向LCM接口接收一个数据
#define LCM_GET_FLAG                (LCMIFSTA & LCMIFIF)              //获取LCM接口中断标志位
#define LCM_CLS_FLAG                do{LCMIFSTA&=~LCMIFIF;}while(0)   //清除LCM接口中断标志位
/*------------------------------PCA/PWM特殊功能寄存器----------------------------*/
sbit    CF                          =CCON^7;//PCA计数器溢出标志位	
sbit    CR                          =CCON^6;//PCA计数运行控制位
sbit    CCF3                        =CCON^3;//PCA3模块中断标志位
sbit    CCF2                        =CCON^2;//PCA2模块中断标志位
sbit    CCF1                        =CCON^1;//PCA1模块中断标志位
sbit    CCF0                        =CCON^0;//PCA0模块中断标志位
#define CIDL                        0x80    //空闲模式下是否停止PCA计数
#define ECF                         0x01    //PCA计数器溢出中断允许位
#define ECOM0_3                     0x40    //允许PCA模块0~3的比较功能
#define CCAPP0_3                    0x20    //允许PCA模块0~3进行上升沿捕获
#define CCAPN0_3                    0x10    //允许PCA模块0~3进行下降沿捕获
#define MAT0_3                      0x08    //允许PCA模块0~3的匹配功能
#define TOG0_3                      0x04    //允许PCA模块0~3的高速脉冲输出功能
#define PWM0_3                      0x02    //允许PCA模块0~3的脉宽调制输出功能
#define ECCF0_3                     0x01    //允许PCA模块0~3的匹配/捕获中断
//-------------功能指令------------//
#define PCA_POWER_ON                do{CR=1;}while(0)//打开PCA模块
#define PCA_POWER_OFF               do{CR=0;}while(0)//关闭PCA模块
#define PCA_IT_ENABLE               do{CMOD|= ECF;}while(0)//打开PCA计数器的溢出中断
#define PCA_IT_DISABLE              do{CMOD&=~ECF;}while(0)//关闭PCA计数器的溢出中断
#define PCA_GET_IT_FLAG             (CF)                   //获取PCA计数器溢出中断标志位
#define PCA_IT_CLS                  do{CF=0;}while(0)      //清除PCA计数器溢出中断标志位
#define PCA_SET_IDLE_ENABLE         do{CMOD&=~CIDL;}while(0)//PCA在空闲模式下继续计数
#define PCA_SET_IDLE_DISABLE        do{CMOD|= CIDL;}while(0)//PCA在空闲模式下停止计数
#define PCA_SET_CPS(value)          REG_IN_MASK(CMOD,0x0E,value)//设置PCA计数脉冲来源
#define PCA_SET_PIN(value)          REG_IN_MASK(P_SW1,0x30,value)//设置PCA的输出引脚
#define PCA0_GET_IT_FLAG            (CCF0)                        //获取PCA0捕获中断标志位
#define PCA0_IT_CLS                 do{CCF0=0;}while(0)           //清除PCA0捕获中断标志位
#define PCA0_SET_ECOM_ENABLE        do{CCAPM0|= ECOM0_3; }while(0)//打开PCA模块0的比较功能
#define PCA0_SET_ECOM_DISABLE       do{CCAPM0&=~ECOM0_3; }while(0)//关闭PCA模块0的比较功能
#define PCA0_SET_CCAPP_ENABLE       do{CCAPM0|= CCAPP0_3;}while(0)//打开PCA模块0的上升沿捕获功能
#define PCA0_SET_CCAPP_DISABLE      do{CCAPM0&=~CCAPP0_3;}while(0)//关闭PCA模块0的上升沿捕获功能
#define PCA0_SET_CCAPN_ENABLE       do{CCAPM0|= CCAPN0_3;}while(0)//打开PCA模块0的下降沿捕获功能
#define PCA0_SET_CCAPN_DISABLE      do{CCAPM0&=~CCAPN0_3;}while(0)//关闭PCA模块0的下降沿捕获功能
#define PCA0_SET_MAT_ENABLE         do{CCAPM0|= MAT0_3;  }while(0)//打开PCA模块0的匹配功能
#define PCA0_SET_MAT_DISABLE        do{CCAPM0&=~MAT0_3;  }while(0)//关闭PCA模块0的匹配功能
#define PCA0_SET_TOG_ENABLE         do{CCAPM0|= TOG0_3;  }while(0)//打开PCA模块0的高速脉冲输出功能
#define PCA0_SET_TOG_DISABLE        do{CCAPM0&=~TOG0_3;  }while(0)//关闭PCA模块0的高速脉冲输出功能
#define PCA0_SET_PWM_ENABLE         do{CCAPM0|= PWM0_3;  }while(0)//打开PCA模块0的脉宽调制输出功能
#define PCA0_SET_PWM_DISABLE        do{CCAPM0&=~PWM0_3;  }while(0)//关闭PCA模块0的脉宽调制输出功能
#define PCA0_SET_ECCF_ENABLE        do{CCAPM0|= ECCF0_3; }while(0)//打开PCA模块0的匹配/捕获中断
#define PCA0_SET_ECCF_DISABLE       do{CCAPM0&=~ECCF0_3; }while(0)//关闭PCA模块0的匹配/捕获中断
#define PCA1_GET_IT_FLAG            (CCF1)                        //获取PCA1捕获中断标志位
#define PCA1_IT_CLS                 do{CCF1=0;}while(0)           //清除PCA1捕获中断标志位
#define PCA1_SET_ECOM_ENABLE        do{CCAPM1|= ECOM0_3; }while(0)//打开PCA模块1的比较功能
#define PCA1_SET_ECOM_DISABLE       do{CCAPM1&=~ECOM0_3; }while(0)//关闭PCA模块1的比较功能
#define PCA1_SET_CCAPP_ENABLE       do{CCAPM1|= CCAPP0_3;}while(0)//打开PCA模块1的上升沿捕获功能
#define PCA1_SET_CCAPP_DISABLE      do{CCAPM1&=~CCAPP0_3;}while(0)//关闭PCA模块1的上升沿捕获功能
#define PCA1_SET_CCAPN_ENABLE       do{CCAPM1|= CCAPN0_3;}while(0)//打开PCA模块1的下降沿捕获功能
#define PCA1_SET_CCAPN_DISABLE      do{CCAPM1&=~CCAPN0_3;}while(0)//关闭PCA模块1的下降沿捕获功能
#define PCA1_SET_MAT_ENABLE         do{CCAPM1|= MAT0_3;  }while(0)//打开PCA模块1的匹配功能
#define PCA1_SET_MAT_DISABLE        do{CCAPM1&=~MAT0_3;  }while(0)//关闭PCA模块1的匹配功能
#define PCA1_SET_TOG_ENABLE         do{CCAPM1|= TOG0_3;  }while(0)//打开PCA模块1的高速脉冲输出功能
#define PCA1_SET_TOG_DISABLE        do{CCAPM1&=~TOG0_3;  }while(0)//关闭PCA模块1的高速脉冲输出功能
#define PCA1_SET_PWM_ENABLE         do{CCAPM1|= PWM0_3;  }while(0)//打开PCA模块1的脉宽调制输出功能
#define PCA1_SET_PWM_DISABLE        do{CCAPM1&=~PWM0_3;  }while(0)//关闭PCA模块1的脉宽调制输出功能
#define PCA1_SET_ECCF_ENABLE        do{CCAPM1|= ECCF0_3; }while(0)//打开PCA模块1的匹配/捕获中断
#define PCA1_SET_ECCF_DISABLE       do{CCAPM1&=~ECCF0_3; }while(0)//关闭PCA模块1的匹配/捕获中断
#define PCA2_GET_IT_FLAG            (CCF2)                        //获取PCA2捕获中断标志位
#define PCA2_IT_CLS                 do{CCF2=0;}while(0)           //清除PCA2捕获中断标志位
#define PCA2_SET_ECOM_ENABLE        do{CCAPM2|= ECOM0_3; }while(0)//打开PCA模块2的比较功能
#define PCA2_SET_ECOM_DISABLE       do{CCAPM2&=~ECOM0_3; }while(0)//关闭PCA模块2的比较功能
#define PCA2_SET_CCAPP_ENABLE       do{CCAPM2|= CCAPP0_3;}while(0)//打开PCA模块2的上升沿捕获功能
#define PCA2_SET_CCAPP_DISABLE      do{CCAPM2&=~CCAPP0_3;}while(0)//关闭PCA模块2的上升沿捕获功能
#define PCA2_SET_CCAPN_ENABLE       do{CCAPM2|= CCAPN0_3;}while(0)//打开PCA模块2的下降沿捕获功能
#define PCA2_SET_CCAPN_DISABLE      do{CCAPM2&=~CCAPN0_3;}while(0)//关闭PCA模块2的下降沿捕获功能
#define PCA2_SET_MAT_ENABLE         do{CCAPM2|= MAT0_3;  }while(0)//打开PCA模块2的匹配功能
#define PCA2_SET_MAT_DISABLE        do{CCAPM2&=~MAT0_3;  }while(0)//关闭PCA模块2的匹配功能
#define PCA2_SET_TOG_ENABLE         do{CCAPM2|= TOG0_3;  }while(0)//打开PCA模块2的高速脉冲输出功能
#define PCA2_SET_TOG_DISABLE        do{CCAPM2&=~TOG0_3;  }while(0)//关闭PCA模块2的高速脉冲输出功能
#define PCA2_SET_PWM_ENABLE         do{CCAPM2|= PWM0_3;  }while(0)//打开PCA模块2的脉宽调制输出功能
#define PCA2_SET_PWM_DISABLE        do{CCAPM2&=~PWM0_3;  }while(0)//关闭PCA模块2的脉宽调制输出功能
#define PCA2_SET_ECCF_ENABLE        do{CCAPM2|= ECCF0_3; }while(0)//打开PCA模块2的匹配/捕获中断
#define PCA2_SET_ECCF_DISABLE       do{CCAPM2&=~ECCF0_3; }while(0)//关闭PCA模块2的匹配/捕获中断
#define PCA3_GET_IT_FLAG            (CCF3)                        //获取PCA3捕获中断标志位
#define PCA3_IT_CLS                 do{CCF3=0;}while(0)           //清除PCA3捕获中断标志位
#define PCA3_SET_ECOM_ENABLE        do{CCAPM3|= ECOM0_3;  }while(0)//打开PCA模块3的比较功能
#define PCA3_SET_ECOM_DISABLE       do{CCAPM3&=~ECOM0_3;  }while(0)//关闭PCA模块3的比较功能
#define PCA3_SET_CCAPP_ENABLE       do{CCAPM3|= CCAPP0_3; }while(0)//打开PCA模块3的上升沿捕获功能
#define PCA3_SET_CCAPP_DISABLE      do{CCAPM3&=~CCAPP0_3; }while(0)//关闭PCA模块3的上升沿捕获功能
#define PCA3_SET_CCAPN_ENABLE       do{CCAPM3|= CCAPN0_3; }while(0)//打开PCA模块3的下降沿捕获功能
#define PCA3_SET_CCAPN_DISABLE      do{CCAPM3&=~CCAPN0_3; }while(0)//关闭PCA模块3的下降沿捕获功能
#define PCA3_SET_MAT_ENABLE         do{CCAPM3|= MAT0_3;   }while(0)//打开PCA模块3的匹配功能
#define PCA3_SET_MAT_DISABLE        do{CCAPM3&=~MAT0_3;   }while(0)//关闭PCA模块3的匹配功能
#define PCA3_SET_TOG_ENABLE         do{CCAPM3|= TOG0_3;   }while(0)//打开PCA模块3的高速脉冲输出功能
#define PCA3_SET_TOG_DISABLE        do{CCAPM3&=~TOG0_3;   }while(0)//关闭PCA模块3的高速脉冲输出功能
#define PCA3_SET_PWM_ENABLE         do{CCAPM3|= PWM0_3;   }while(0)//打开PCA模块3的脉宽调制输出功能
#define PCA3_SET_PWM_DISABLE        do{CCAPM3&=~PWM0_3;   }while(0)//关闭PCA模块3的脉宽调制输出功能
#define PCA3_SET_ECCF_ENABLE        do{CCAPM3|= ECCF0_3;  }while(0)//打开PCA模块3的匹配/捕获中断
#define PCA3_SET_ECCF_DISABLE       do{CCAPM3&=~ECCF0_3;  }while(0)//关闭PCA模块3的匹配/捕获中断
//-------------寄存器读取----------//
#define PCA_SET_REG_CCON(value)     do{CCON=(u8)(value);}while(0)//设置CCON寄存器
#define PCA_GET_REG_CCON            (CCON)                       //读取CCON寄存器
#define PCA_SET_REG_CMOD(value)     do{CMOD=(u8)(value);}while(0)//设置CMOD寄存器
#define PCA_GET_REG_CMOD            (CMOD)                       //读取CMOD寄存器
#define PCA_SET_REG_CL(value)       do{CL=(u8)(value);}while(0)  //设置CL寄存器
#define PCA_GET_REG_CL              (CL)                         //读取CL寄存器
#define PCA_SET_REG_CH(value)       do{CH=(u8)(value);}while(0)  //设置CH寄存器
#define PCA_GET_REG_CH              (CH)                         //读取CH寄存器
#define PCA_SET_REG_CHL(value)      do{CL=(u8)(value);CH=(u8)(value>>8);}while(0)//设置PCA的计数值
#define PCA_GET_REG_CHL             ((((u16)CH)<<8)|(u16)CL)       //获取PCA的计数值
#define PCA_SET_REG_CCAPM0(value)   do{CCAPM0=(u8)value;}while(0)  //设置CCAPM0寄存器
#define PCA_GET_REG_CCAPM0          (CCAPM0)                       //读取CCAPM0寄存器
#define PCA_SET_REG_CCAP0L(value)   do{CCAP0L=(u8)(value);}while(0)//设置CCAP0L寄存器
#define PCA_GET_REG_CCAP0L          (CCAP0L)                       //读取CCAP0L寄存器
#define PCA_SET_REG_CCAP0H(value)   do{CCAP0H=(u8)(value);}while(0)//设置CCAP0H寄存器
#define PCA_GET_REG_CCAP0H          (CCAP0H)                       //读取CCAP0H寄存器
#define PCA_SET_REG_CCAP0HL(value)  do{CCAP0L=(u8)(value);CCAP0H=(u8)(value>>8);}while(0)//设置PCA0的捕获值
#define PCA_GET_REG_CCAP0HL         ((((u16)CCAP0H)<<8)|(u16)CCAP0L) //获取PCA0的捕获值
#define PCA_SET_REG_PWM0(value)     do{PCA_PWM0=(u8)(value);}while(0)//设置PCA_PWM0寄存器
#define PCA_GET_REG_PWM0            (PCA_PWM0)                       //读取PCA_PWM0寄存器
#define PCA_SET_REG_CCAPM1(value)   do{CCAPM1=(u8)value;}while(0)    //设置CCAPM1寄存器
#define PCA_GET_REG_CCAPM1          (CCAPM1)                         //读取CCAPM1寄存器
#define PCA_SET_REG_CCAP1L(value)   do{CCAP1L=(u8)(value);}while(0)  //设置CCAP1L寄存器
#define PCA_GET_REG_CCAP1L          (CCAP1L)                         //读取CCAP1L寄存器
#define PCA_SET_REG_CCAP1H(value)   do{CCAP1H=(u8)(value);}while(0)  //设置CCAP1H寄存器
#define PCA_GET_REG_CCAP1H          (CCAP1H)                         //读取CCAP1H寄存器
#define PCA_SET_REG_CCAP1HL(value)  do{CCAP1L=(u8)(value);CCAP1H=(u8)(value>>8);}while(0)//设置PCA1的捕获值
#define PCA_GET_REG_CCAP1HL         ((((u16)CCAP1H)<<8)|(u16)CCAP1L) //获取PCA1的捕获值
#define PCA_SET_REG_PWM1(value)     do{PCA_PWM1=(u8)(value);}while(0)//设置PCA_PWM1寄存器
#define PCA_GET_REG_PWM1            (PCA_PWM1)                       //读取PCA_PWM1寄存器
#define PCA_SET_REG_CCAPM2(value)   do{CCAPM2=(u8)value;}while(0)    //设置CCAPM2寄存器
#define PCA_GET_REG_CCAPM2          (CCAPM2)                         //读取CCAPM2寄存器
#define PCA_SET_REG_CCAP2L(value)   do{CCAP2L=(u8)(value);}while(0)  //设置CCAP2L寄存器
#define PCA_GET_REG_CCAP2L          (CCAP2L)                         //读取CCAP2L寄存器
#define PCA_SET_REG_CCAP2H(value)   do{CCAP2H=(u8)(value);}while(0)  //设置CCAP2H寄存器
#define PCA_GET_REG_CCAP2H          (CCAP2H)                         //读取CCAP2H寄存器
#define PCA_SET_REG_CCAP2HL(value)  do{CCAP2L=(u8)(value);CCAP2H=(u8)(value>>8);}while(0)//设置PCA2的捕获值
#define PCA_GET_REG_CCAP2HL         ((((u16)CCAP2H)<<8)|(u16)CCAP2L) //获取PCA2的捕获值
#define PCA_SET_REG_PWM2(value)     do{PCA_PWM2=(u8)(value);}while(0)//设置PCA_PWM2寄存器
#define PCA_GET_REG_PWM2            (PCA_PWM2)                       //读取PCA_PWM2寄存器
#define PCA_SET_REG_CCAPM3(value)   do{CCAPM3=(u8)value;}while(0)    //设置CCAPM3寄存器
#define PCA_GET_REG_CCAPM3          (CCAPM3)                         //读取CCAPM3寄存器
#define PCA_SET_REG_CCAP3L(value)   do{CCAP3L=(u8)value;}while(0)    //设置CCAP3L寄存器
#define PCA_GET_REG_CCAP3L          (CCAP3L)                         //读取CCAP3L寄存器
#define PCA_SET_REG_CCAP3H(value)   do{CCAP3H=(u8)value;}while(0)    //设置CCAP3H寄存器
#define PCA_GET_REG_CCAP3H          (CCAP3H)                         //读取CCAP3H寄存器
#define PCA_SET_REG_CCAP3HL(value)  do{CCAP3L=(u8)(value);CCAP3H=(u8)(value>>8);}while(0)//设置PCA3的捕获值
#define PCA_GET_REG_CCAP3HL         ((((u16)CCAP3H)<<8)|(u16)CCAP3L) //获取PCA3的捕获值
#define PCA_SET_REG_PWM3(value)     do{PCA_PWM3=(u8)value;}while(0)  //设置PCA_PWM3寄存器
#define PCA_GET_REG_PWM3            (PCA_PWM3)                       //读取PCA_PWM3寄存器
//-------------功能定义------------//
#define PCA_IT_NUM                  interrupt 7//PCA中断号
/*------------------------------BMM/DMA特殊功能寄存器----------------------------*/
#define M2MIE                       0x80//BMM_MEM_MEM中断使能控制位
#define TXACO                       0x40//BMM_MEM_MEM源地址方向控制位
#define RXACO                       0x20//BMM_MEM_MEM目标地址方向控制位
#define ENM2M                       0x80//BMM_MEM_MEM功能使能位
#define M2MTRIG                     0x40//BMM_MEM_MEM功能触发位
#define ADCIE                       0x80//BMM_ADC_MEM中断使能控制位
#define ENADC                       0x80//BMM_ADC_MEM功能使能位
#define A2MTRIG                     0x40//BMM_ADC_MEM功能触发位
#define SPIIE                       0x80//BMM_SPI_MEM中断使能控制位
#define ACT_TX                      0x40//BMM_SPI_MEM发送数据控制位
#define ACT_RX                      0x20//BMM_SPI_MEM接收数据控制位
#define ENSPI                       0x80//BMM_SPI_MEM功能使能位
#define S2MTRIG_M                   0x40//BMM_SPI_MEM主机功能触发位
#define S2MTRIG_S                   0x20//BMM_SPI_MEM从机功能触发位
#define CLRFIFO                     0x01//BMM_SPI_MEM清除FIFO位
#define SPIIF                       0x01//BMM_SPI_MEM中断请求标志位
#define SPIRXLOSS                   0x02//BMM_SPI_MEM接收数据丢弃标志位
#define SPITXOVW                    0x04//BMM_SPI_MEM数据覆盖标志位
#define WRPSS                       0x04//BMM_SPI_MEM使能SS脚控制位
#define URTIE                       0x80//BMM_UART_MEM发送中断使能控制位
#define ENURT                       0x80//BMM_UART_MEM发送功能使能位
#define URTTRIG                     0x40//BMM_UART_MEM发送触发控制位
#define URTIF                       0x01//BMM_UART_MEM发送中断请求标志位
#define URTXOVW                     0x04//BMM_UART_MEM发送数据覆盖标志位
#define URRIE                       0x80//BMM_UART_MEM接收中断使能控制位
#define ENURR                       0x80//BMM_UART_MEM接收功能使能位
#define URRTRIG                     0x40//BMM_UART_MEM接收触发控制位
#define URRIF                       0x01//BMM_UART_MEM接收中断请求标志位
#define URRXOVW                     0x04//BMM_UART_MEM接收数据覆盖标志位
#define LCMIE                       0x80//BMM_LCM_MEM中断使能控制位
#define ENLCM                       0x80//BMM_LCM_MEM功能使能位
#define TRIGWC                      0x40//BMM_LCM_MEM发送命令模式触发控制位
#define TRIGWD                      0x20//BMM_LCM_MEM发送数据模式触发控制位
#define TRIGRC                      0x10//BMM_LCM_MEM接收指令模式触发控制位
#define TRIGRD                      0x08//BMM_LCM_MEM接收数据模式触发控制位
#define LCMIF                       0x01//BMM_LCM_MEM中断请求标志位
#define LCMTXOVW                    0x02//BMM_LCM_MEM数据覆盖标志位
//-------------功能指令------------//
#define MEM_MEM_IT_ENABLE               do{BMM_M2M_CFG|= M2MIE;}while(0)//打开MEM到MEM的中断使能
#define MEM_MEM_IT_DISABLE              do{BMM_M2M_CFG&=~M2MIE;}while(0)//改变MEM到MEM的中断使能
#define MEM_MEM_SET_TX_ADD              do{BMM_M2M_CFG&=~TXACO;}while(0)//MEM到MEM的源地址递增
#define MEM_MEM_SET_TX_DEC              do{BMM_M2M_CFG|= TXACO;}while(0)//MEM到MEM的源地址递减
#define MEM_MEM_SET_RX_ADD              do{BMM_M2M_CFG&=~RXACO;}while(0)//MEM到MEM的目标地址递增
#define MEM_MEM_SET_RX_DEC              do{BMM_M2M_CFG|= RXACO;}while(0)//MEM到MEM的目标地址递减
#define MEM_MEM_SET_IT_PRIORITY_0       do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x0C))|0x00);}while(0)//设置MEM到MEM的中断优先级为0
#define MEM_MEM_SET_IT_PRIORITY_1       do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x0C))|0x04);}while(0)//设置MEM到MEM的中断优先级为1
#define MEM_MEM_SET_IT_PRIORITY_2       do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x0C))|0x08);}while(0)//设置MEM到MEM的中断优先级为2
#define MEM_MEM_SET_IT_PRIORITY_3       do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到MEM的中断优先级为3
#define MEM_MEM_SET_BUS_PRIORITY_0      do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x03))|0x00);}while(0)//设置MEM到MEM的总线优先级为0
#define MEM_MEM_SET_BUS_PRIORITY_1      do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x03))|0x01);}while(0)//设置MEM到MEM的总线优先级为1
#define MEM_MEM_SET_BUS_PRIORITY_2      do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x03))|0x02);}while(0)//设置MEM到MEM的总线优先级为2
#define MEM_MEM_SET_BUS_PRIORITY_3      do{BMM_M2M_CFG=((BMM_M2M_CFG&(~0x03))|0x03);}while(0)//设置MEM到MEM的总线优先级为3
#define MEM_MEM_ENABLE                  do{BMM_M2M_CR|= ENM2M;}while(0)  //打开MEM到MEM功能
#define MEM_MEM_DISABLE                 do{BMM_M2M_CR&=~ENM2M;}while(0)  //关闭MEM到MEM功能
#define MEM_MEM_START                   do{BMM_M2M_CR|= M2MTRIG;}while(0)//开始一次MEM到MEM的传输
#define MEM_MEM_GET_FLAG                (BMM_M2M_STA)                    //获取MEM到MEM传输的状态
#define MEM_MEM_CLS_FLAG                do{BMM_M2M_STA=0;}while(0)       //清除MEM到MEM的状态值
#define MEM_MEM_SET_COUNT_MAX(value)    do{BMM_M2M_AMT=(u8)(value);}while(0)//设置MEM到MEM传输的总字节数
#define MEM_MEM_GET_COUNT_DONE          (BMM_M2M_DONE)                   //获取MEM到MEM已经传输完成的字节数
#define MEM_MEM_SET_TX_ADDR(value)      do{BMM_M2M_TXA=(u16)(value);}while(0)//设置MEM到MEM的源地址
#define MEM_MEM_SET_RX_ADDR(value)      do{BMM_M2M_RXA=(u16)(value);}while(0)//设置MEM到MEM的目标地址
#define ADC_MEM_IT_ENABLE               do{BMM_ADC_CFG|= ADCIE;}while(0)//打开ADC到MEM的中断使能
#define ADC_MEM_IT_DISABLE              do{BMM_ADC_CFG&=~ADCIE;}while(0)//关闭ADC到MEM的中断使能
#define ADC_MEM_SET_IT_PRIORITY_0       do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x0C))|0x00);}while(0)//设置ADC到MEM的中断优先级为0
#define ADC_MEM_SET_IT_PRIORITY_1       do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x0C))|0x04);}while(0)//设置ADC到MEM的中断优先级为1
#define ADC_MEM_SET_IT_PRIORITY_2       do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x0C))|0x08);}while(0)//设置ADC到MEM的中断优先级为2
#define ADC_MEM_SET_IT_PRIORITY_3       do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x0C))|0x0C);}while(0)//设置ADC到MEM的中断优先级为3
#define ADC_MEM_SET_BUS_PRIORITY_0      do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x03))|0x00);}while(0)//设置ADC到MEM的总线优先级为0
#define ADC_MEM_SET_BUS_PRIORITY_1      do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x03))|0x01);}while(0)//设置ADC到MEM的总线优先级为1
#define ADC_MEM_SET_BUS_PRIORITY_2      do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x03))|0x02);}while(0)//设置ADC到MEM的总线优先级为2
#define ADC_MEM_SET_BUS_PRIORITY_3      do{BMM_ADC_CFG=((BMM_ADC_CFG&(~0x03))|0x03);}while(0)//设置ADC到MEM的总线优先级为3
#define ADC_MEM_ENABLE                  do{BMM_ADC_CR|= ENADC;}while(0)  //打开ADC到MEM功能
#define ADC_MEM_DISABLE                 do{BMM_ADC_CR&=~ENADC;}while(0)  //关闭ADC到MEM功能
#define ADC_MEM_START                   do{BMM_ADC_CR|= A2MTRIG;}while(0)//开始一次ADC到MEM的传输
#define ADC_MEM_GET_FLAG                (BMM_ADC_STA)                    //获取ADC到MEM传输的状态
#define ADC_MEM_CLS_FLAG                do{BMM_ADC_STA=0;}while(0)       //清除ADC到MEM的状态值
#define ADC_MEM_SET_RX_ADDR(value)      do{BMM_ADC_RXA=(u16)(value);}while(0)//设置接收ADC数据的地址
#define ADC_MEM_SET_CH_COUNT(value)     do{BMM_ADC_CFG2=((u8)(value)&0x0F);}while(0)//设置每个通道采集多少次
#define ADC_MEM_SET_CH_0_7_EN(value)    do{BMM_ADC_CHSW1=(u8)(value);}while(0)//设置参与ADC_MEM传输的通道（0~7）
#define ADC_MEM_SET_CH_8_15_EN(value)   do{BMM_ADC_CHSW0=(u8)(value);}while(0)//设置参与ADC_MEM传输的通道（8~15）
#define SPI_MEM_IT_ENABLE               do{BMM_SPI_CFG|= SPIIE;}while(0)//打开SPI到MEM的中断使能
#define SPI_MEM_IT_DISABLE              do{BMM_SPI_CFG&=~SPIIE;}while(0)//关闭SPI到MEM的中断使能
#define SPI_MEM_SET_TX_ENABLE           do{BMM_SPI_CFG|= ACT_TX;}while(0)//允许SPI_MEM发送数据
#define SPI_MEM_SET_TX_DISABLE          do{BMM_SPI_CFG&=~ACT_TX;}while(0)//禁止SPI_MEM发送数据
#define SPI_MEM_SET_RX_ENABLE           do{BMM_SPI_CFG|= ACT_RX;}while(0)//允许SPI_MEM接收数据
#define SPI_MEM_SET_RX_DISABLE          do{BMM_SPI_CFG&=~ACT_RX;}while(0)//禁止SPI_MEM接收数据
#define SPI_MEM_SET_IT_PRIORITY_0       do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x0C))|0x00);}while(0)//设置SPI到MEM的中断优先级为0
#define SPI_MEM_SET_IT_PRIORITY_1       do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x0C))|0x04);}while(0)//设置SPI到MEM的中断优先级为1
#define SPI_MEM_SET_IT_PRIORITY_2       do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x0C))|0x08);}while(0)//设置SPI到MEM的中断优先级为2
#define SPI_MEM_SET_IT_PRIORITY_3       do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x0C))|0x0C);}while(0)//设置SPI到MEM的中断优先级为3
#define SPI_MEM_SET_BUS_PRIORITY_0      do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x03))|0x00);}while(0)//设置SPI到MEM的总线优先级为0
#define SPI_MEM_SET_BUS_PRIORITY_1      do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x03))|0x01);}while(0)//设置SPI到MEM的总线优先级为1
#define SPI_MEM_SET_BUS_PRIORITY_2      do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x03))|0x02);}while(0)//设置SPI到MEM的总线优先级为2
#define SPI_MEM_SET_BUS_PRIORITY_3      do{BMM_SPI_CFG=((BMM_SPI_CFG&(~0x03))|0x03);}while(0)//设置SPIC到MEM的总线优先级为3
#define SPI_MEM_ENABLE                  do{BMM_SPI_CR|= ENSPI;}while(0)     //打开SPI到MEM功能
#define SPI_MEM_DISABLE                 do{BMM_SPI_CR&=~ENSPI;}while(0)     //关闭SPI到MEM功能
#define SPI_MEM_MODE_M_START            do{BMM_SPI_CR|= S2MTRIG_M;}while(0) //开始一次SPI到MEM的主机传输
#define SPI_MEM_MODE_S_START            do{BMM_SPI_CR|= S2MTRIG_S;}while(0) //开始一次SPI到MEM的从机传
#define SPI_MEM_CLS_FIFO                do{BMM_SPI_CR|= CLRFIFO;}while(0)   //清空SPI到MEM的FIFO
#define SPI_MEM_GET_FLAG                (BMM_SPI_STA & SPIIF)               //读取SPI到MEM中断标志位
#define SPI_MEM_GET_FLAG_RXLOSS         (BMM_SPI_STA & SPIRXLOSS)           //读取SPI到MEM数据丢失标志位
#define SPI_MEM_GET_FLAG_TXOVW          (BMM_SPI_STA & SPITXOVW)            //读取SPI到MEM数据覆盖标志位
#define SPI_MEM_CLS_FLAG                do{BMM_SPI_STA&=~SPIIF;}while(0)    //清除SPI到MEM中断标志位
#define SPI_MEM_CLS_FLAG_RXLOSS         do{BMM_SPI_STA&=~SPIRXLOSS;}while(0)//清除SPI到MEM数据丢失标志位
#define SPI_MEM_CLS_FLAG_TXOVW          do{BMM_SPI_STA&=~SPITXOVW;}while(0) //清除SPI到MEM数据覆盖标志位
#define SPI_MEM_SET_COUNT_MAX(value)    do{BMM_SPI_AMT=(u8)(value);}while(0)//设置SPI到MEM的发送/接收总字节数
#define SPI_MEM_GET_COUNT_DONE          (BMM_SPI_DONE)                      //读取SPI到MEM已经传输的字节数
#define SPI_MEM_SET_TX_ADDR(value)      do{BMM_SPI_TXA=(u16)(value);}while(0)//设置SPI到MEM的发送地址
#define SPI_MEM_SET_RX_ADDR(value)      do{BMM_SPI_RXA=(u16)(value);}while(0)//设置SPI到MEM的接收地址
#define SPI_MEM_SET_SS_AUTO_ENABLE      do{BMM_SPI_CFG2|= WRPSS;}while(0)    //设置SPI到MEM的SS脚自动控制
#define SPI_MEM_SET_SS_AUTO_DISABLE     do{BMM_SPI_CFG2&=~WRPSS;}while(0)    //设置SPI到MEM的SS脚手动控制
#define SPI_MEM_SET_SS_P12              do{BMM_SPI_CFG2=(BMM_SPI_CFG2&(~0x03))|0x00;}while(0)//设置自动控制的SS脚为P12脚
#define SPI_MEM_SET_SS_P22              do{BMM_SPI_CFG2=(BMM_SPI_CFG2&(~0x03))|0x01;}while(0)//设置自动控制的SS脚为P22脚
#define SPI_MEM_SET_SS_P74              do{BMM_SPI_CFG2=(BMM_SPI_CFG2&(~0x03))|0x02;}while(0)//设置自动控制的SS脚为P74脚
#define SPI_MEM_SET_SS_P35              do{BMM_SPI_CFG2=(BMM_SPI_CFG2&(~0x03))|0x03;}while(0)//设置自动控制的SS脚为P35脚
#define UR1_MEM_TX_IT_ENABLE            do{BMM_UR1T_CFG|= URTIE;}while(0)//打开MEM到UART1的发送中断使能
#define UR1_MEM_TX_IT_DISABLE           do{BMM_UR1T_CFG|= URTIE;}while(0)//关闭MEM到UART1的发送中断使能
#define UR1_MEM_RX_IT_ENABLE            do{BMM_UR1R_CFG|= URRIE;}while(0)//打开UART1到MEM的接收中断使能
#define UR1_MEM_RX_IT_DISABLE           do{BMM_UR1R_CFG|= URRIE;}while(0)//关闭UART1到MEM的接收中断使能
#define UR1_MEM_SET_TX_IT_PRIORITY_0    do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART1的发送中断优先级为0
#define UR1_MEM_SET_TX_IT_PRIORITY_1    do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART1的发送中断优先级为1
#define UR1_MEM_SET_TX_IT_PRIORITY_2    do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART1的发送中断优先级为2
#define UR1_MEM_SET_TX_IT_PRIORITY_3    do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART1的发送中断优先级为3
#define UR1_MEM_SET_RX_IT_PRIORITY_0    do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x0C))|0x00);}while(0)//设置UART1到MEM的接收中断优先级为0
#define UR1_MEM_SET_RX_IT_PRIORITY_1    do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x0C))|0x04);}while(0)//设置UART1到MEM的接收中断优先级为1
#define UR1_MEM_SET_RX_IT_PRIORITY_2    do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x0C))|0x08);}while(0)//设置UART1到MEM的接收中断优先级为2
#define UR1_MEM_SET_RX_IT_PRIORITY_3    do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x0C))|0x0C);}while(0)//设置UART1到MEM的接收中断优先级为3
#define UR1_MEM_SET_TX_BUS_PRIORITY_0   do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART1的发送总线优先级为0
#define UR1_MEM_SET_TX_BUS_PRIORITY_1   do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART1的发送总线优先级为1
#define UR1_MEM_SET_TX_BUS_PRIORITY_2   do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART1的发送总线优先级为2
#define UR1_MEM_SET_TX_BUS_PRIORITY_3   do{BMM_UR1T_CFG=((BMM_UR1T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART1的发送总线优先级为3
#define UR1_MEM_SET_RX_BUS_PRIORITY_0   do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x03))|0x00);}while(0)//设置UART1到MEM的接收总线优先级为0
#define UR1_MEM_SET_RX_BUS_PRIORITY_1   do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x03))|0x01);}while(0)//设置UART1到MEM的接收总线优先级为1
#define UR1_MEM_SET_RX_BUS_PRIORITY_2   do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x03))|0x02);}while(0)//设置UART1到MEM的接收总线优先级为2
#define UR1_MEM_SET_RX_BUS_PRIORITY_3   do{BMM_UR1R_CFG=((BMM_UR1R_CFG&(~0x03))|0x03);}while(0)//设置UART1到MEM的接收总线优先级为3
#define UR1_MEM_TX_ENABLE               do{BMM_UR1T_CR|= ENURT;}while(0)   //打开MEM到UART1的发送使能
#define UR1_MEM_TX_DISABLE              do{BMM_UR1T_CR&=~ENURT;}while(0)   //关闭MEM到UART1的发送使能
#define UR1_MEM_RX_ENABLE               do{BMM_UR1R_CR|= ENURR;}while(0)   //打开UART1到MEM的接收使能
#define UR1_MEM_RX_DISABLE              do{BMM_UR1R_CR&=~ENURR;}while(0)   //关闭UART1到MEM的接收使能
#define UR1_MEM_TX_START                do{BMM_UR1T_CR|= URTTRIG;}while(0) //开始一次MEM到UART1的传输
#define UR1_MEM_RX_START                do{BMM_UR1R_CR|= URRTRIG;}while(0) //开始一次UART1到MEM的传输
#define UR1_MEM_GET_TX_FLAG             (BMM_UR1T_STA & URTIF)             //读取MEM到UART1的中断标志位
#define UR1_MEM_GET_TX_FLAG_TXOVW       (BMM_UR1T_STA & URTXOVW)           //读取MEM到UART1的覆盖标志位
#define UR1_MEM_GET_RX_FLAG             (BMM_UR1R_STA & URRIF)             //读取UART1到MEM的中断标志位
#define UR1_MEM_GET_RX_FLAG_RXOVW       (BMM_UR1R_STA & URRXOVW)           //读取UART1到MEM的覆盖标志位
#define UR1_MEM_CLS_TX_FLAG             do{BMM_UR1T_STA&=~URTIF;}while(0)  //清除MEM到UART1的中断标志位
#define UR1_MEM_CLS_TX_FLAG_TXOVW       do{BMM_UR1T_STA&=~URTXOVW;}while(0)//清除MEM到UART1的覆盖标志位
#define UR1_MEM_CLS_RX_FLAG             do{BMM_UR1R_STA&=~URRIF;}while(0)  //清除UART1到MEM的中断标志位
#define UR1_MEM_CLS_RX_FLAG_RXOVW       do{BMM_UR1R_STA&=~URRXOVW;}while(0)//清除UART1到MEM的覆盖标志位
#define UR1_MEM_SET_TX_COUNT_MAX(value) do{BMM_UR1T_AMT=(u8)(value);}while(0)//设置MEM到UART1发送总字节数
#define UR1_MEM_GET_TX_COUNT_DONE       (BMM_UR1T_DONE)                 //读取MEM到UART1已经发送的字节数
#define UR1_MEM_SET_RX_COUNT_MAX(value) do{BMM_UR1R_AMT=(u8)(value);}while(0)//设置UART1到MEM接收总字节数
#define UR1_MEM_GET_RX_COUNT_DONE       (BMM_UR1R_DONE)                 //读取UART1到MEM已经接收的字节数
#define UR1_MEM_SET_TX_ADDR(value)      do{BMM_UR1T_TXA=(u16)(value);}while(0)//设置MEM到UART1的发送地址
#define UR1_MEM_SET_RX_ADDR(value)      do{BMM_UR1R_RXA=(u16)(value);}while(0)//设置UART1到MEM的接收地址
#define UR2_MEM_TX_IT_ENABLE            do{BMM_UR2T_CFG|= URTIE;}while(0)//打开MEM到UART2的发送中断使能
#define UR2_MEM_TX_IT_DISABLE           do{BMM_UR2T_CFG|= URTIE;}while(0)//关闭MEM到UART2的发送中断使能
#define UR2_MEM_RX_IT_ENABLE            do{BMM_UR2R_CFG|= URRIE;}while(0)//打开UART2到MEM的接收中断使能
#define UR2_MEM_RX_IT_DISABLE           do{BMM_UR2R_CFG|= URRIE;}while(0)//关闭UART2到MEM的接收中断使能
#define UR2_MEM_SET_TX_IT_PRIORITY_0    do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART2的发送中断优先级为0
#define UR2_MEM_SET_TX_IT_PRIORITY_1    do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART2的发送中断优先级为1
#define UR2_MEM_SET_TX_IT_PRIORITY_2    do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART2的发送中断优先级为2
#define UR2_MEM_SET_TX_IT_PRIORITY_3    do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART2的发送中断优先级为3
#define UR2_MEM_SET_RX_IT_PRIORITY_0    do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x0C))|0x00);}while(0)//设置UART2到MEM的接收中断优先级为0
#define UR2_MEM_SET_RX_IT_PRIORITY_1    do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x0C))|0x04);}while(0)//设置UART2到MEM的接收中断优先级为1
#define UR2_MEM_SET_RX_IT_PRIORITY_2    do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x0C))|0x08);}while(0)//设置UART2到MEM的接收中断优先级为2
#define UR2_MEM_SET_RX_IT_PRIORITY_3    do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x0C))|0x0C);}while(0)//设置UART2到MEM的接收中断优先级为3
#define UR2_MEM_SET_TX_BUS_PRIORITY_0   do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART2的发送总线优先级为0
#define UR2_MEM_SET_TX_BUS_PRIORITY_1   do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART2的发送总线优先级为1
#define UR2_MEM_SET_TX_BUS_PRIORITY_2   do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART2的发送总线优先级为2
#define UR2_MEM_SET_TX_BUS_PRIORITY_3   do{BMM_UR2T_CFG=((BMM_UR2T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART2的发送总线优先级为3
#define UR2_MEM_SET_RX_BUS_PRIORITY_0   do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x03))|0x00);}while(0)//设置UART2到MEM的接收总线优先级为0
#define UR2_MEM_SET_RX_BUS_PRIORITY_1   do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x03))|0x01);}while(0)//设置UART2到MEM的接收总线优先级为1
#define UR2_MEM_SET_RX_BUS_PRIORITY_2   do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x03))|0x02);}while(0)//设置UART2到MEM的接收总线优先级为2
#define UR2_MEM_SET_RX_BUS_PRIORITY_3   do{BMM_UR2R_CFG=((BMM_UR2R_CFG&(~0x03))|0x03);}while(0)//设置UART2到MEM的接收总线优先级为3
#define UR2_MEM_TX_ENABLE               do{BMM_UR2T_CR|= ENURT;}while(0)   //打开MEM到UART2的发送使能
#define UR2_MEM_TX_DISABLE              do{BMM_UR2T_CR&=~ENURT;}while(0)   //关闭MEM到UART2的发送使能
#define UR2_MEM_RX_ENABLE               do{BMM_UR2R_CR|= ENURR;}while(0)   //打开UART2到MEM的接收使能
#define UR2_MEM_RX_DISABLE              do{BMM_UR2R_CR&=~ENURR;}while(0)   //关闭UART2到MEM的接收使能
#define UR2_MEM_TX_START                do{BMM_UR2T_CR|= URTTRIG;}while(0) //开始一次MEM到UART2的传输
#define UR2_MEM_RX_START                do{BMM_UR2R_CR|= URRTRIG;}while(0) //开始一次UART2到MEM的传输
#define UR2_MEM_GET_TX_FLAG             (BMM_UR2T_STA & URTIF)             //读取MEM到UART2的中断标志位
#define UR2_MEM_GET_TX_FLAG_TXOVW       (BMM_UR2T_STA & URTXOVW)           //读取MEM到UART2的覆盖标志位
#define UR2_MEM_GET_RX_FLAG             (BMM_UR2R_STA & URRIF)             //读取UART2到MEM的中断标志位
#define UR2_MEM_GET_RX_FLAG_RXOVW       (BMM_UR2R_STA & URRXOVW)           //读取UART2到MEM的覆盖标志位
#define UR2_MEM_CLS_TX_FLAG             do{BMM_UR2T_STA&=~URTIF;}while(0)  //清除MEM到UART2的中断标志位
#define UR2_MEM_CLS_TX_FLAG_TXOVW       do{BMM_UR2T_STA&=~URTXOVW;}while(0)//清除MEM到UART2的覆盖标志位
#define UR2_MEM_CLS_RX_FLAG             do{BMM_UR2R_STA&=~URRIF;}while(0)  //清除UART2到MEM的中断标志位
#define UR2_MEM_CLS_RX_FLAG_RXOVW       do{BMM_UR2R_STA&=~URRXOVW;}while(0)//清除UART2到MEM的覆盖标志位
#define UR2_MEM_SET_TX_COUNT_MAX(value) do{BMM_UR2T_AMT=(u8)(value);}while(0)//设置MEM到UART2发送总字节数
#define UR2_MEM_GET_TX_COUNT_DONE       (BMM_UR2T_DONE)                //读取MEM到UART2已经发送的字节数
#define UR2_MEM_SET_RX_COUNT_MAX(value) do{BMM_UR2R_AMT=(u8)(value);}while(0)//设置UART2到MEM接收总字节数
#define UR2_MEM_GET_RX_COUNT_DONE       (BMM_UR2R_DONE)                //读取UART2到MEM已经接收的字节数
#define UR2_MEM_SET_TX_ADDR(value)      do{BMM_UR2T_TXA=(u16)(value);}while(0)//设置MEM到UART2的发送地址
#define UR2_MEM_SET_RX_ADDR(value)      do{BMM_UR2R_RXA=(u16)(value);}while(0)//设置UART2到MEM的接收地址
#define UR3_MEM_TX_IT_ENABLE            do{BMM_UR3T_CFG|= URTIE;}while(0)//打开MEM到UART3的发送中断使能
#define UR3_MEM_TX_IT_DISABLE           do{BMM_UR3T_CFG|= URTIE;}while(0)//关闭MEM到UART3的发送中断使能
#define UR3_MEM_RX_IT_ENABLE            do{BMM_UR3R_CFG|= URRIE;}while(0)//打开UART3到MEM的接收中断使能
#define UR3_MEM_RX_IT_DISABLE           do{BMM_UR3R_CFG|= URRIE;}while(0)//关闭UART3到MEM的接收中断使能
#define UR3_MEM_SET_TX_IT_PRIORITY_0    do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART3的发送中断优先级为0
#define UR3_MEM_SET_TX_IT_PRIORITY_1    do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART3的发送中断优先级为1
#define UR3_MEM_SET_TX_IT_PRIORITY_2    do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART3的发送中断优先级为2
#define UR3_MEM_SET_TX_IT_PRIORITY_3    do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART3的发送中断优先级为3
#define UR3_MEM_SET_RX_IT_PRIORITY_0    do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x0C))|0x00);}while(0)//设置UART3到MEM的接收中断优先级为0
#define UR3_MEM_SET_RX_IT_PRIORITY_1    do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x0C))|0x04);}while(0)//设置UART3到MEM的接收中断优先级为1
#define UR3_MEM_SET_RX_IT_PRIORITY_2    do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x0C))|0x08);}while(0)//设置UART3到MEM的接收中断优先级为2
#define UR3_MEM_SET_RX_IT_PRIORITY_3    do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x0C))|0x0C);}while(0)//设置UART3到MEM的接收中断优先级为3
#define UR3_MEM_SET_TX_BUS_PRIORITY_0   do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART3的发送总线优先级为0
#define UR3_MEM_SET_TX_BUS_PRIORITY_1   do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART3的发送总线优先级为1
#define UR3_MEM_SET_TX_BUS_PRIORITY_2   do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART3的发送总线优先级为2
#define UR3_MEM_SET_TX_BUS_PRIORITY_3   do{BMM_UR3T_CFG=((BMM_UR3T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART3的发送总线优先级为3
#define UR3_MEM_SET_RX_BUS_PRIORITY_0   do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x03))|0x00);}while(0)//设置UART3到MEM的接收总线优先级为0
#define UR3_MEM_SET_RX_BUS_PRIORITY_1   do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x03))|0x01);}while(0)//设置UART3到MEM的接收总线优先级为1
#define UR3_MEM_SET_RX_BUS_PRIORITY_2   do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x03))|0x02);}while(0)//设置UART3到MEM的接收总线优先级为2
#define UR3_MEM_SET_RX_BUS_PRIORITY_3   do{BMM_UR3R_CFG=((BMM_UR3R_CFG&(~0x03))|0x03);}while(0)//设置UART3到MEM的接收总线优先级为3
#define UR3_MEM_TX_ENABLE               do{BMM_UR3T_CR|= ENURT;}while(0)   //打开MEM到UART3的发送使能
#define UR3_MEM_TX_DISABLE              do{BMM_UR3T_CR&=~ENURT;}while(0)   //关闭MEM到UART3的发送使能
#define UR3_MEM_RX_ENABLE               do{BMM_UR3R_CR|= ENURR;}while(0)   //打开UART3到MEM的接收使能
#define UR3_MEM_RX_DISABLE              do{BMM_UR3R_CR&=~ENURR;}while(0)   //关闭UART3到MEM的接收使能
#define UR3_MEM_TX_START                do{BMM_UR3T_CR|= URTTRIG;}while(0) //开始一次MEM到UART3的传输
#define UR3_MEM_RX_START                do{BMM_UR3R_CR|= URRTRIG;}while(0) //开始一次UART3到MEM的传输
#define UR3_MEM_GET_TX_FLAG             (BMM_UR3T_STA & URTIF)             //读取MEM到UART3的中断标志位
#define UR3_MEM_GET_TX_FLAG_TXOVW       (BMM_UR3T_STA & URTXOVW)           //读取MEM到UART3的覆盖标志位
#define UR3_MEM_GET_RX_FLAG             (BMM_UR3R_STA & URRIF)             //读取UART3到MEM的中断标志位
#define UR3_MEM_GET_RX_FLAG_RXOVW       (BMM_UR3R_STA & URRXOVW)           //读取UART3到MEM的覆盖标志位
#define UR3_MEM_CLS_TX_FLAG             do{BMM_UR3T_STA&=~URTIF;}while(0)  //清除MEM到UART3的中断标志位
#define UR3_MEM_CLS_TX_FLAG_TXOVW       do{BMM_UR3T_STA&=~URTXOVW;}while(0)//清除MEM到UART3的覆盖标志位
#define UR3_MEM_CLS_RX_FLAG             do{BMM_UR3R_STA&=~URRIF;}while(0)  //清除UART3到MEM的中断标志位
#define UR3_MEM_CLS_RX_FLAG_RXOVW       do{BMM_UR3R_STA&=~URRXOVW;}while(0)//清除UART3到MEM的覆盖标志位
#define UR3_MEM_SET_TX_COUNT_MAX(value) do{BMM_UR3T_AMT=(u8)(value);}while(0)//设置MEM到UART3发送总字节数
#define UR3_MEM_GET_TX_COUNT_DONE       (BMM_UR3T_DONE)                //读取MEM到UART3已经发送的字节数
#define UR3_MEM_SET_RX_COUNT_MAX(value) do{BMM_UR3R_AMT=(u8)(value);}while(0)//设置UART3到MEM接收总字节数
#define UR3_MEM_GET_RX_COUNT_DONE       (BMM_UR3R_DONE)                //读取UART3到MEM已经接收的字节数
#define UR3_MEM_SET_TX_ADDR(value)      do{BMM_UR3T_TXA=(u16)(value);}while(0)//设置MEM到UART3的发送地址
#define UR3_MEM_SET_RX_ADDR(value)      do{BMM_UR3R_RXA=(u16)(value);}while(0)//设置UART3到MEM的接收地址
#define UR4_MEM_TX_IT_ENABLE            do{BMM_UR4T_CFG|= URTIE;}while(0)//打开MEM到UART4的发送中断使能
#define UR4_MEM_TX_IT_DISABLE           do{BMM_UR4T_CFG|= URTIE;}while(0)//关闭MEM到UART4的发送中断使能
#define UR4_MEM_RX_IT_ENABLE            do{BMM_UR4R_CFG|= URRIE;}while(0)//打开UART4到MEM的接收中断使能
#define UR4_MEM_RX_IT_DISABLE           do{BMM_UR4R_CFG|= URRIE;}while(0)//关闭UART4到MEM的接收中断使能
#define UR4_MEM_SET_TX_IT_PRIORITY_0    do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x0C))|0x00);}while(0)//设置MEM到UART4的发送中断优先级为0
#define UR4_MEM_SET_TX_IT_PRIORITY_1    do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x0C))|0x04);}while(0)//设置MEM到UART4的发送中断优先级为1
#define UR4_MEM_SET_TX_IT_PRIORITY_2    do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x0C))|0x08);}while(0)//设置MEM到UART4的发送中断优先级为2
#define UR4_MEM_SET_TX_IT_PRIORITY_3    do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到UART4的发送中断优先级为3
#define UR4_MEM_SET_RX_IT_PRIORITY_0    do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x0C))|0x00);}while(0)//设置UART4到MEM的接收中断优先级为0
#define UR4_MEM_SET_RX_IT_PRIORITY_1    do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x0C))|0x04);}while(0)//设置UART4到MEM的接收中断优先级为1
#define UR4_MEM_SET_RX_IT_PRIORITY_2    do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x0C))|0x08);}while(0)//设置UART4到MEM的接收中断优先级为2
#define UR4_MEM_SET_RX_IT_PRIORITY_3    do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x0C))|0x0C);}while(0)//设置UART4到MEM的接收中断优先级为3
#define UR4_MEM_SET_TX_BUS_PRIORITY_0   do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x03))|0x00);}while(0)//设置MEM到UART4的发送总线优先级为0
#define UR4_MEM_SET_TX_BUS_PRIORITY_1   do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x03))|0x01);}while(0)//设置MEM到UART4的发送总线优先级为1
#define UR4_MEM_SET_TX_BUS_PRIORITY_2   do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x03))|0x02);}while(0)//设置MEM到UART4的发送总线优先级为2
#define UR4_MEM_SET_TX_BUS_PRIORITY_3   do{BMM_UR4T_CFG=((BMM_UR4T_CFG&(~0x03))|0x03);}while(0)//设置MEM到UART4的发送总线优先级为3
#define UR4_MEM_SET_RX_BUS_PRIORITY_0   do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x03))|0x00);}while(0)//设置UART4到MEM的接收总线优先级为0
#define UR4_MEM_SET_RX_BUS_PRIORITY_1   do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x03))|0x01);}while(0)//设置UART4到MEM的接收总线优先级为1
#define UR4_MEM_SET_RX_BUS_PRIORITY_2   do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x03))|0x02);}while(0)//设置UART4到MEM的接收总线优先级为2
#define UR4_MEM_SET_RX_BUS_PRIORITY_3   do{BMM_UR4R_CFG=((BMM_UR4R_CFG&(~0x03))|0x03);}while(0)//设置UART4到MEM的接收总线优先级为3
#define UR4_MEM_TX_ENABLE               do{BMM_UR4T_CR|= ENURT;}while(0)   //打开MEM到UART4的发送使能
#define UR4_MEM_TX_DISABLE              do{BMM_UR4T_CR&=~ENURT;}while(0)   //关闭MEM到UART4的发送使能
#define UR4_MEM_RX_ENABLE               do{BMM_UR4R_CR|= ENURR;}while(0)   //打开UART4到MEM的接收使能
#define UR4_MEM_RX_DISABLE              do{BMM_UR4R_CR&=~ENURR;}while(0)   //关闭UART4到MEM的接收使能
#define UR4_MEM_TX_START                do{BMM_UR4T_CR|= URTTRIG;}while(0) //开始一次MEM到UART4的传输
#define UR4_MEM_RX_START                do{BMM_UR4R_CR|= URRTRIG;}while(0) //开始一次UART4到MEM的传输
#define UR4_MEM_GET_TX_FLAG             (BMM_UR4T_STA & URTIF)             //读取MEM到UART4的中断标志位
#define UR4_MEM_GET_TX_FLAG_TXOVW       (BMM_UR4T_STA & URTXOVW)           //读取MEM到UART4的覆盖标志位
#define UR4_MEM_GET_RX_FLAG             (BMM_UR4R_STA & URRIF)             //读取UART4到MEM的中断标志位
#define UR4_MEM_GET_RX_FLAG_RXOVW       (BMM_UR4R_STA & URRXOVW)           //读取UART4到MEM的覆盖标志位
#define UR4_MEM_CLS_TX_FLAG             do{BMM_UR4T_STA&=~URTIF;}while(0)  //清除MEM到UART4的中断标志位
#define UR4_MEM_CLS_TX_FLAG_TXOVW       do{BMM_UR4T_STA&=~URTXOVW;}while(0)//清除MEM到UART4的覆盖标志位
#define UR4_MEM_CLS_RX_FLAG             do{BMM_UR4R_STA&=~URRIF;}while(0)  //清除UART4到MEM的中断标志位
#define UR4_MEM_CLS_RX_FLAG_RXOVW       do{BMM_UR4R_STA&=~URRXOVW;}while(0)//清除UART4到MEM的覆盖标志位
#define UR4_MEM_SET_TX_COUNT_MAX(value) do{BMM_UR4T_AMT=(u8)(value);}while(0)//设置MEM到UART4发送总字节数
#define UR4_MEM_GET_TX_COUNT_DONE       (BMM_UR4T_DONE)                //读取MEM到UART4已经发送的字节数
#define UR4_MEM_SET_RX_COUNT_MAX(value) do{BMM_UR4R_AMT=(u8)(value);}while(0)//设置UART4到MEM接收总字节数
#define UR4_MEM_GET_RX_COUNT_DONE       (BMM_UR4R_DONE)                //读取UART4到MEM已经接收的字节数
#define UR4_MEM_SET_TX_ADDR(value)      do{BMM_UR4T_TXA=(u16)(value);}while(0)//设置MEM到UART4的发送地址
#define UR4_MEM_SET_RX_ADDR(value)      do{BMM_UR4R_RXA=(u16)(value);}while(0)//设置UART4到MEM的接收地址
#define LCM_MEM_IT_ENABLE               do{BMM_LCM_CFG|= LCMIE;}while(0)   //打开MEM到LCM的中断
#define LCM_MEM_IT_DISABLE              do{BMM_LCM_CFG&=~LCMIE;}while(0)   //关闭MEM到LCM的中断
#define LCM_MEM_SET_IT_PRIORITY_0       do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x0C))|0x00);}while(0)//设置MEM到LCM的中断优先级为0
#define LCM_MEM_SET_IT_PRIORITY_1       do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x0C))|0x04);}while(0)//设置MEM到LCM的中断优先级为1
#define LCM_MEM_SET_IT_PRIORITY_2       do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x0C))|0x08);}while(0)//设置MEM到LCM的中断优先级为2
#define LCM_MEM_SET_IT_PRIORITY_3       do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x0C))|0x0C);}while(0)//设置MEM到LCM的中断优先级为3
#define LCM_MEM_SET_BUS_PRIORITY_0      do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x03))|0x00);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_SET_BUS_PRIORITY_1      do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x03))|0x01);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_SET_BUS_PRIORITY_2      do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x03))|0x02);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_SET_BUS_PRIORITY_3      do{BMM_LCM_CFG=((BMM_LCM_CFG&(~0x03))|0x03);}while(0)//设置MEM到LCM的总线优先级为0
#define LCM_MEM_ENABLE                  do{BMM_LCM_CR|= ENLCM;}while(0)   //打开MEM到LCM功能
#define LCM_MEM_DISABLE                 do{BMM_LCM_CR&=~ENLCM;}while(0)   //关闭MEM到LCM功能
#define LCM_MEM_START_TX_CMD            do{BMM_LCM_CR|= TRIGWC;}while(0)  //开始从MEM发送指令到LCM
#define LCM_MEM_START_TX_DAT            do{BMM_LCM_CR|= TRIGWD;}while(0)  //开始从MEM发送数据到LCM
#define LCM_MEM_START_RX_CMD            do{BMM_LCM_CR|= TRIGRC;}while(0)  //开始从LCM读取指令到MEM
#define LCM_MEM_START_RX_DAT            do{BMM_LCM_CR|= TRIGRD;}while(0)  //开始从LCM读取数据到MEM
#define LCM_MEM_GET_FLAG                (BMM_LCM_STA & LCMIF)             //读取MEM到LCM的中断标志位
#define LCM_MEM_GET_FLAG_TXOVW          (BMM_LCM_STA & LCMTXOVW)          //读取MEM到LCM的数据覆盖标志位
#define LCM_MEM_CLS_FLAG                (BMM_LCM_STA&=~LCMIF)             //清除MEM到LCM的中断标志位
#define LCM_MEM_CLS_FLAG_TXOVW          (BMM_LCM_STA&=~LCMTXOVW)          //清除MEM到LCM的数据覆盖标志位
#define LCM_MEM_SET_COUNT_MAX(value)    do{BMM_LCM_AMT=(u8)(value);}while(0)//设置MEM到LCM传输的字节数
#define LCM_MEM_GET_COUNT_DONE          (BMM_LCM_DONE)                   //读取MEM到LCM的已传输完成字节数
#define LCM_MEM_SET_TX_ADDR(value)      do{BMM_LCM_TXA=(u16)(value);}while(0)//设置MEM到LCM的发送地址
#define LCM_MEM_SET_RX_ADDR(value)      do{BMM_LCM_RXA=(u16)(value);}while(0)//设置LCM到MEM的接收地址
/*------------------------------15位PWM特殊功能寄存器----------------------------*/
#define PWMRST                      0x40//PWM重置位
#define ENPWM                       0x01//PWM使能位
#define PWMCBIF                     0x08//PWM计数器归零中断标志位
#define EPWMCBI                     0x04//PWM计数器归零中断使能位 
#define EPWMTA                      0x02//PWM与ADC关联位
#define PWMCEN                      0x01//PWM计数开始位
#define INVCMP                      0x80//PWM异常检测中比较器结果控制位
#define INVIO                       0x40//PWM异常检测中IO信号控制位
#define ENFD                        0x20//PWM异常检测控制位
#define FLTFLIO                     0x10//PWM发生异常时对PWM输出口控制位
#define EFDI                        0x08//PWM异常检测中断使能位
#define FDCMP                       0x04//PWM异常检测使用比较器检测使能位
#define FDIO                        0x02//PWM异常检测使用IO检测使能位
#define FDIF                        0x01//PWM异常检测中断标志位
#define SELT2                       0x10//PWM时钟源选择
#define ENO                         0x80//PWM输出使能位
#define INI                         0x40//PWM初始电平控制位
#define ENI                         0x04//PWM通道中断使能位
#define ENT2I                       0x02//PWM通道在第二个点中断使能位
#define ENT1I                       0x01//PWM通道在第一个点中断使能位
#define PWM_EN                      0x80//PWM使能并开始计数（STC8A普通版）
//-------------功能指令------------//
#if     ((ECBM_MCU&0xF00000)==0x200000)   //STC8A全系列
#define PWM15_SET_CLK_TIMER2        do{PWMCKS=SELT2;}while(0)
#define PWM15_SET_CLK_SYS(value)    do{PWMCKS=((u8)(value)&0x0F);}while(0)

#define PWM15_SET_CH0_IO_P20        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x00);}while(0)//PWM通道0的引脚切换到P20
#define PWM15_SET_CH0_IO_P10        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x08);}while(0)//PWM通道0的引脚切换到P10
#define PWM15_SET_CH0_IO_P60        do{PWM_CH0_CR=((PWM_CH0_CR&(~0x18))|0x10);}while(0)//PWM通道0的引脚切换到P60
#define PWM15_SET_CH1_IO_P21        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x00);}while(0)//PWM通道1的引脚切换到P21
#define PWM15_SET_CH1_IO_P11        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x08);}while(0)//PWM通道1的引脚切换到P11
#define PWM15_SET_CH1_IO_P61        do{PWM_CH1_CR=((PWM_CH1_CR&(~0x18))|0x10);}while(0)//PWM通道1的引脚切换到P61
#define PWM15_SET_CH2_IO_P22        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x00);}while(0)//PWM通道2的引脚切换到P22
#define PWM15_SET_CH2_IO_P12        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x08);}while(0)//PWM通道2的引脚切换到P12
#define PWM15_SET_CH2_IO_P62        do{PWM_CH2_CR=((PWM_CH2_CR&(~0x18))|0x10);}while(0)//PWM通道2的引脚切换到P62
#define PWM15_SET_CH3_IO_P23        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x00);}while(0)//PWM通道3的引脚切换到P23
#define PWM15_SET_CH3_IO_P13        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x08);}while(0)//PWM通道3的引脚切换到P13
#define PWM15_SET_CH3_IO_P63        do{PWM_CH3_CR=((PWM_CH3_CR&(~0x18))|0x10);}while(0)//PWM通道3的引脚切换到P63
#define PWM15_SET_CH4_IO_P24        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x00);}while(0)//PWM通道4的引脚切换到P24
#define PWM15_SET_CH4_IO_P14        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x08);}while(0)//PWM通道4的引脚切换到P14
#define PWM15_SET_CH4_IO_P64        do{PWM_CH4_CR=((PWM_CH4_CR&(~0x18))|0x10);}while(0)//PWM通道4的引脚切换到P64
#define PWM15_SET_CH5_IO_P25        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x00);}while(0)//PWM通道5的引脚切换到P25
#define PWM15_SET_CH5_IO_P15        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x08);}while(0)//PWM通道5的引脚切换到P15
#define PWM15_SET_CH5_IO_P65        do{PWM_CH5_CR=((PWM_CH5_CR&(~0x18))|0x10);}while(0)//PWM通道5的引脚切换到P65
#define PWM15_SET_CH6_IO_P26        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x00);}while(0)//PWM通道6的引脚切换到P26
#define PWM15_SET_CH6_IO_P16        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x08);}while(0)//PWM通道6的引脚切换到P16
#define PWM15_SET_CH6_IO_P66        do{PWM_CH6_CR=((PWM_CH6_CR&(~0x18))|0x10);}while(0)//PWM通道6的引脚切换到P66
#define PWM15_SET_CH7_IO_P27        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x00);}while(0)//PWM通道7的引脚切换到P27
#define PWM15_SET_CH7_IO_P17        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x08);}while(0)//PWM通道7的引脚切换到P17
#define PWM15_SET_CH7_IO_P67        do{PWM_CH7_CR=((PWM_CH7_CR&(~0x18))|0x10);}while(0)//PWM通道7的引脚切换到P67

#define PWM15_GET_CH0_IT_FLAG       (PWMIF & 0x01)
#define PWM15_GET_CH1_IT_FLAG       (PWMIF & 0x02)
#define PWM15_GET_CH2_IT_FLAG       (PWMIF & 0x04)
#define PWM15_GET_CH3_IT_FLAG       (PWMIF & 0x08)
#define PWM15_GET_CH4_IT_FLAG       (PWMIF & 0x10)
#define PWM15_GET_CH5_IT_FLAG       (PWMIF & 0x20)
#define PWM15_GET_CH6_IT_FLAG       (PWMIF & 0x40)
#define PWM15_GET_CH7_IT_FLAG       (PWMIF & 0x80)

#define PWM15_CLS_CH0_IT_FLAG       do{PWMIF&=~0x01}while(0)
#define PWM15_CLS_CH1_IT_FLAG       do{PWMIF&=~0x02}while(0)
#define PWM15_CLS_CH2_IT_FLAG       do{PWMIF&=~0x04}while(0)
#define PWM15_CLS_CH3_IT_FLAG       do{PWMIF&=~0x08}while(0)
#define PWM15_CLS_CH4_IT_FLAG       do{PWMIF&=~0x10}while(0)
#define PWM15_CLS_CH5_IT_FLAG       do{PWMIF&=~0x20}while(0)
#define PWM15_CLS_CH6_IT_FLAG       do{PWMIF&=~0x40}while(0)
#define PWM15_CLS_CH7_IT_FLAG       do{PWMIF&=~0x80}while(0)

#define PWM15_SET_CH0_OUT_ENABLE    do{PWM_CH0_CR|= ENO;}while(0)
#define PWM15_SET_CH0_OUT_DISABLE   do{PWM_CH0_CR&=~ENO;}while(0)
#define PWM15_SET_CH0_INIT_H        do{PWM_CH0_CR|= INI;}while(0)
#define PWM15_SET_CH0_INIT_L        do{PWM_CH0_CR&=~INI;}while(0)
#define PWM15_SET_CH0_IT_ENABLE     do{PWM_CH0_CR|= ENI;}while(0)
#define PWM15_SET_CH0_IT_DISABLE    do{PWM_CH0_CR&=~ENI;}while(0)
#define PWM15_SET_CH0_T1_IT_ENABLE  do{PWM_CH0_CR|= ENT1I;}while(0)
#define PWM15_SET_CH0_T1_IT_DISABLE do{PWM_CH0_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH0_T2_IT_ENABLE  do{PWM_CH0_CR|= ENT2I;}while(0)
#define PWM15_SET_CH0_T2_IT_DISABLE do{PWM_CH0_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH0_HOLD_H        do{PWM_CH0_HLD=0x02;}while(0)
#define PWM15_SET_CH0_HOLD_L        do{PWM_CH0_HLD=0x01;}while(0)
#define PWM15_SET_CH0_HOLD_OFF      do{PWM_CH0_HLD=0x00;}while(0)
#define PWM15_SET_CH1_OUT_ENABLE    do{PWM_CH1_CR|= ENO;}while(0)
#define PWM15_SET_CH1_OUT_DISABLE   do{PWM_CH1_CR&=~ENO;}while(0)
#define PWM15_SET_CH1_INIT_H        do{PWM_CH1_CR|= INI;}while(0)
#define PWM15_SET_CH1_INIT_L        do{PWM_CH1_CR&=~INI;}while(0)
#define PWM15_SET_CH1_IT_ENABLE     do{PWM_CH1_CR|= ENI;}while(0)
#define PWM15_SET_CH1_IT_DISABLE    do{PWM_CH1_CR&=~ENI;}while(0)
#define PWM15_SET_CH1_T1_IT_ENABLE  do{PWM_CH1_CR|= ENT1I;}while(0)
#define PWM15_SET_CH1_T1_IT_DISABLE do{PWM_CH1_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH1_T2_IT_ENABLE  do{PWM_CH1_CR|= ENT2I;}while(0)
#define PWM15_SET_CH1_T2_IT_DISABLE do{PWM_CH1_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH1_HOLD_H        do{PWM_CH1_HLD=0x02;}while(0)
#define PWM15_SET_CH1_HOLD_L        do{PWM_CH1_HLD=0x01;}while(0)
#define PWM15_SET_CH1_HOLD_OFF      do{PWM_CH1_HLD=0x00;}while(0)
#define PWM15_SET_CH2_OUT_ENABLE    do{PWM_CH2_CR|= ENO;}while(0)
#define PWM15_SET_CH2_OUT_DISABLE   do{PWM_CH2_CR&=~ENO;}while(0)
#define PWM15_SET_CH2_INIT_H        do{PWM_CH2_CR|= INI;}while(0)
#define PWM15_SET_CH2_INIT_L        do{PWM_CH2_CR&=~INI;}while(0)
#define PWM15_SET_CH2_IT_ENABLE     do{PWM_CH2_CR|= ENI;}while(0)
#define PWM15_SET_CH2_IT_DISABLE    do{PWM_CH2_CR&=~ENI;}while(0)
#define PWM15_SET_CH2_T1_IT_ENABLE  do{PWM_CH2_CR|= ENT1I;}while(0)
#define PWM15_SET_CH2_T1_IT_DISABLE do{PWM_CH2_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH2_T2_IT_ENABLE  do{PWM_CH2_CR|= ENT2I;}while(0)
#define PWM15_SET_CH2_T2_IT_DISABLE do{PWM_CH2_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH2_HOLD_H        do{PWM_CH2_HLD=0x02;}while(0)
#define PWM15_SET_CH2_HOLD_L        do{PWM_CH2_HLD=0x01;}while(0)
#define PWM15_SET_CH2_HOLD_OFF      do{PWM_CH2_HLD=0x00;}while(0)
#define PWM15_SET_CH3_OUT_ENABLE    do{PWM_CH3_CR|= ENO;}while(0)
#define PWM15_SET_CH3_OUT_DISABLE   do{PWM_CH3_CR&=~ENO;}while(0)
#define PWM15_SET_CH3_INIT_H        do{PWM_CH3_CR|= INI;}while(0)
#define PWM15_SET_CH3_INIT_L        do{PWM_CH3_CR&=~INI;}while(0)
#define PWM15_SET_CH3_IT_ENABLE     do{PWM_CH3_CR|= ENI;}while(0)
#define PWM15_SET_CH3_IT_DISABLE    do{PWM_CH3_CR&=~ENI;}while(0)
#define PWM15_SET_CH3_T1_IT_ENABLE  do{PWM_CH3_CR|= ENT1I;}while(0)
#define PWM15_SET_CH3_T1_IT_DISABLE do{PWM_CH3_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH3_T2_IT_ENABLE  do{PWM_CH3_CR|= ENT2I;}while(0)
#define PWM15_SET_CH3_T2_IT_DISABLE do{PWM_CH3_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH3_HOLD_H        do{PWM_CH3_HLD=0x02;}while(0)
#define PWM15_SET_CH3_HOLD_L        do{PWM_CH3_HLD=0x01;}while(0)
#define PWM15_SET_CH3_HOLD_OFF      do{PWM_CH3_HLD=0x00;}while(0)
#define PWM15_SET_CH4_OUT_ENABLE    do{PWM_CH4_CR|= ENO;}while(0)
#define PWM15_SET_CH4_OUT_DISABLE   do{PWM_CH4_CR&=~ENO;}while(0)
#define PWM15_SET_CH4_INIT_H        do{PWM_CH4_CR|= INI;}while(0)
#define PWM15_SET_CH4_INIT_L        do{PWM_CH4_CR&=~INI;}while(0)
#define PWM15_SET_CH4_IT_ENABLE     do{PWM_CH4_CR|= ENI;}while(0)
#define PWM15_SET_CH4_IT_DISABLE    do{PWM_CH4_CR&=~ENI;}while(0)
#define PWM15_SET_CH4_T1_IT_ENABLE  do{PWM_CH4_CR|= ENT1I;}while(0)
#define PWM15_SET_CH4_T1_IT_DISABLE do{PWM_CH4_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH4_T2_IT_ENABLE  do{PWM_CH4_CR|= ENT2I;}while(0)
#define PWM15_SET_CH4_T2_IT_DISABLE do{PWM_CH4_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH4_HOLD_H        do{PWM_CH4_HLD=0x02;}while(0)
#define PWM15_SET_CH4_HOLD_L        do{PWM_CH4_HLD=0x01;}while(0)
#define PWM15_SET_CH4_HOLD_OFF      do{PWM_CH4_HLD=0x00;}while(0)
#define PWM15_SET_CH5_OUT_ENABLE    do{PWM_CH5_CR|= ENO;}while(0)
#define PWM15_SET_CH5_OUT_DISABLE   do{PWM_CH5_CR&=~ENO;}while(0)
#define PWM15_SET_CH5_INIT_H        do{PWM_CH5_CR|= INI;}while(0)
#define PWM15_SET_CH5_INIT_L        do{PWM_CH5_CR&=~INI;}while(0)
#define PWM15_SET_CH5_IT_ENABLE     do{PWM_CH5_CR|= ENI;}while(0)
#define PWM15_SET_CH5_IT_DISABLE    do{PWM_CH5_CR&=~ENI;}while(0)
#define PWM15_SET_CH5_T1_IT_ENABLE  do{PWM_CH5_CR|= ENT1I;}while(0)
#define PWM15_SET_CH5_T1_IT_DISABLE do{PWM_CH5_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH5_T2_IT_ENABLE  do{PWM_CH5_CR|= ENT2I;}while(0)
#define PWM15_SET_CH5_T2_IT_DISABLE do{PWM_CH5_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH5_HOLD_H        do{PWM_CH5_HLD=0x02;}while(0)
#define PWM15_SET_CH5_HOLD_L        do{PWM_CH5_HLD=0x01;}while(0)
#define PWM15_SET_CH5_HOLD_OFF      do{PWM_CH5_HLD=0x00;}while(0)
#define PWM15_SET_CH6_OUT_ENABLE    do{PWM_CH6_CR|= ENO;}while(0)
#define PWM15_SET_CH6_OUT_DISABLE   do{PWM_CH6_CR&=~ENO;}while(0)
#define PWM15_SET_CH6_INIT_H        do{PWM_CH6_CR|= INI;}while(0)
#define PWM15_SET_CH6_INIT_L        do{PWM_CH6_CR&=~INI;}while(0)
#define PWM15_SET_CH6_IT_ENABLE     do{PWM_CH6_CR|= ENI;}while(0)
#define PWM15_SET_CH6_IT_DISABLE    do{PWM_CH6_CR&=~ENI;}while(0)
#define PWM15_SET_CH6_T1_IT_ENABLE  do{PWM_CH6_CR|= ENT1I;}while(0)
#define PWM15_SET_CH6_T1_IT_DISABLE do{PWM_CH6_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH6_T2_IT_ENABLE  do{PWM_CH6_CR|= ENT2I;}while(0)
#define PWM15_SET_CH6_T2_IT_DISABLE do{PWM_CH6_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH6_HOLD_H        do{PWM_CH6_HLD=0x02;}while(0)
#define PWM15_SET_CH6_HOLD_L        do{PWM_CH6_HLD=0x01;}while(0)
#define PWM15_SET_CH6_HOLD_OFF      do{PWM_CH6_HLD=0x00;}while(0)
#define PWM15_SET_CH7_OUT_ENABLE    do{PWM_CH7_CR|= ENO;}while(0)
#define PWM15_SET_CH7_OUT_DISABLE   do{PWM_CH7_CR&=~ENO;}while(0)
#define PWM15_SET_CH7_INIT_H        do{PWM_CH7_CR|= INI;}while(0)
#define PWM15_SET_CH7_INIT_L        do{PWM_CH7_CR&=~INI;}while(0)
#define PWM15_SET_CH7_IT_ENABLE     do{PWM_CH7_CR|= ENI;}while(0)
#define PWM15_SET_CH7_IT_DISABLE    do{PWM_CH7_CR&=~ENI;}while(0)
#define PWM15_SET_CH7_T1_IT_ENABLE  do{PWM_CH7_CR|= ENT1I;}while(0)
#define PWM15_SET_CH7_T1_IT_DISABLE do{PWM_CH7_CR&=~ENT1I;}while(0)
#define PWM15_SET_CH7_T2_IT_ENABLE  do{PWM_CH7_CR|= ENT2I;}while(0)
#define PWM15_SET_CH7_T2_IT_DISABLE do{PWM_CH7_CR&=~ENT2I;}while(0)
#define PWM15_SET_CH7_HOLD_H        do{PWM_CH7_HLD=0x02;}while(0)
#define PWM15_SET_CH7_HOLD_L        do{PWM_CH7_HLD=0x01;}while(0)
#define PWM15_SET_CH7_HOLD_OFF      do{PWM_CH7_HLD=0x00;}while(0)
#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2K系列
#define PWM15_SET_G0_CLK_TIMER2     do{PWM_P0_CKS=SELT2;}while(0)
#define PWM15_SET_G1_CLK_TIMER2     do{PWM_P1_CKS=SELT2;}while(0)
#define PWM15_SET_G2_CLK_TIMER2     do{PWM_P2_CKS=SELT2;}while(0)
#define PWM15_SET_G3_CLK_TIMER2     do{PWM_P3_CKS=SELT2;}while(0)
#define PWM15_SET_G4_CLK_TIMER2     do{PWM_P4_CKS=SELT2;}while(0)
#define PWM15_SET_G5_CLK_TIMER2     do{PWM_P5_CKS=SELT2;}while(0)

#define PWM15_SET_G0_CLK_SYS(value) do{PWM_P0_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G1_CLK_SYS(value) do{PWM_P1_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G2_CLK_SYS(value) do{PWM_P2_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G3_CLK_SYS(value) do{PWM_P3_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G4_CLK_SYS(value) do{PWM_P4_CKS=((u8)(value)&0x0F);}while(0)
#define PWM15_SET_G5_CLK_SYS(value) do{PWM_P5_CKS=((u8)(value)&0x0F);}while(0)

#define PWM15_GET_G0_CH0_IT_FLAG    (PWM_P0_IF & 0x01)
#define PWM15_GET_G0_CH1_IT_FLAG    (PWM_P0_IF & 0x02)
#define PWM15_GET_G0_CH2_IT_FLAG    (PWM_P0_IF & 0x04)
#define PWM15_GET_G0_CH3_IT_FLAG    (PWM_P0_IF & 0x08)
#define PWM15_GET_G0_CH4_IT_FLAG    (PWM_P0_IF & 0x10)
#define PWM15_GET_G0_CH5_IT_FLAG    (PWM_P0_IF & 0x20)
#define PWM15_GET_G0_CH6_IT_FLAG    (PWM_P0_IF & 0x40)
#define PWM15_GET_G0_CH7_IT_FLAG    (PWM_P0_IF & 0x80)
#define PWM15_GET_G1_CH0_IT_FLAG    (PWM_P1_IF & 0x01)
#define PWM15_GET_G1_CH1_IT_FLAG    (PWM_P1_IF & 0x02)
#define PWM15_GET_G1_CH2_IT_FLAG    (PWM_P1_IF & 0x04)
#define PWM15_GET_G1_CH3_IT_FLAG    (PWM_P1_IF & 0x08)
#define PWM15_GET_G1_CH4_IT_FLAG    (PWM_P1_IF & 0x10)
#define PWM15_GET_G1_CH5_IT_FLAG    (PWM_P1_IF & 0x20)
#define PWM15_GET_G1_CH6_IT_FLAG    (PWM_P1_IF & 0x40)
#define PWM15_GET_G1_CH7_IT_FLAG    (PWM_P1_IF & 0x80)
#define PWM15_GET_G2_CH0_IT_FLAG    (PWM_P2_IF & 0x01)
#define PWM15_GET_G2_CH1_IT_FLAG    (PWM_P2_IF & 0x02)
#define PWM15_GET_G2_CH2_IT_FLAG    (PWM_P2_IF & 0x04)
#define PWM15_GET_G2_CH3_IT_FLAG    (PWM_P2_IF & 0x08)
#define PWM15_GET_G2_CH4_IT_FLAG    (PWM_P2_IF & 0x10)
#define PWM15_GET_G2_CH5_IT_FLAG    (PWM_P2_IF & 0x20)
#define PWM15_GET_G2_CH6_IT_FLAG    (PWM_P2_IF & 0x40)
#define PWM15_GET_G2_CH7_IT_FLAG    (PWM_P2_IF & 0x80)
#define PWM15_GET_G3_CH0_IT_FLAG    (PWM_P3_IF & 0x01)
#define PWM15_GET_G3_CH1_IT_FLAG    (PWM_P3_IF & 0x02)
#define PWM15_GET_G3_CH2_IT_FLAG    (PWM_P3_IF & 0x04)
#define PWM15_GET_G3_CH3_IT_FLAG    (PWM_P3_IF & 0x08)
#define PWM15_GET_G3_CH4_IT_FLAG    (PWM_P3_IF & 0x10)
#define PWM15_GET_G3_CH5_IT_FLAG    (PWM_P3_IF & 0x20)
#define PWM15_GET_G3_CH6_IT_FLAG    (PWM_P3_IF & 0x40)
#define PWM15_GET_G3_CH7_IT_FLAG    (PWM_P3_IF & 0x80)
#define PWM15_GET_G4_CH0_IT_FLAG    (PWM_P4_IF & 0x01)
#define PWM15_GET_G4_CH1_IT_FLAG    (PWM_P4_IF & 0x02)
#define PWM15_GET_G4_CH2_IT_FLAG    (PWM_P4_IF & 0x04)
#define PWM15_GET_G4_CH3_IT_FLAG    (PWM_P4_IF & 0x08)
#define PWM15_GET_G4_CH4_IT_FLAG    (PWM_P4_IF & 0x10)
#define PWM15_GET_G4_CH5_IT_FLAG    (PWM_P4_IF & 0x20)
#define PWM15_GET_G4_CH6_IT_FLAG    (PWM_P4_IF & 0x40)
#define PWM15_GET_G4_CH7_IT_FLAG    (PWM_P4_IF & 0x80)
#define PWM15_GET_G5_CH0_IT_FLAG    (PWM_P5_IF & 0x01)
#define PWM15_GET_G5_CH1_IT_FLAG    (PWM_P5_IF & 0x02)
#define PWM15_GET_G5_CH2_IT_FLAG    (PWM_P5_IF & 0x04)
#define PWM15_GET_G5_CH3_IT_FLAG    (PWM_P5_IF & 0x08)
#define PWM15_GET_G5_CH4_IT_FLAG    (PWM_P5_IF & 0x10)
#define PWM15_GET_G5_CH5_IT_FLAG    (PWM_P5_IF & 0x20)
#define PWM15_GET_G5_CH6_IT_FLAG    (PWM_P5_IF & 0x40)
#define PWM15_GET_G5_CH7_IT_FLAG    (PWM_P5_IF & 0x80)

#define PWM15_CLS_G0_CH0_IT_FLAG    do{PWM_P0_IF&=~0x01}while(0)
#define PWM15_CLS_G0_CH1_IT_FLAG    do{PWM_P0_IF&=~0x02}while(0)
#define PWM15_CLS_G0_CH2_IT_FLAG    do{PWM_P0_IF&=~0x04}while(0)
#define PWM15_CLS_G0_CH3_IT_FLAG    do{PWM_P0_IF&=~0x08}while(0)
#define PWM15_CLS_G0_CH4_IT_FLAG    do{PWM_P0_IF&=~0x10}while(0)
#define PWM15_CLS_G0_CH5_IT_FLAG    do{PWM_P0_IF&=~0x20}while(0)
#define PWM15_CLS_G0_CH6_IT_FLAG    do{PWM_P0_IF&=~0x40}while(0)
#define PWM15_CLS_G0_CH7_IT_FLAG    do{PWM_P0_IF&=~0x80}while(0)
#define PWM15_CLS_G1_CH0_IT_FLAG    do{PWM_P1_IF&=~0x01}while(0)
#define PWM15_CLS_G1_CH1_IT_FLAG    do{PWM_P1_IF&=~0x02}while(0)
#define PWM15_CLS_G1_CH2_IT_FLAG    do{PWM_P1_IF&=~0x04}while(0)
#define PWM15_CLS_G1_CH3_IT_FLAG    do{PWM_P1_IF&=~0x08}while(0)
#define PWM15_CLS_G1_CH4_IT_FLAG    do{PWM_P1_IF&=~0x10}while(0)
#define PWM15_CLS_G1_CH5_IT_FLAG    do{PWM_P1_IF&=~0x20}while(0)
#define PWM15_CLS_G1_CH6_IT_FLAG    do{PWM_P1_IF&=~0x40}while(0)
#define PWM15_CLS_G1_CH7_IT_FLAG    do{PWM_P1_IF&=~0x80}while(0)
#define PWM15_CLS_G2_CH0_IT_FLAG    do{PWM_P2_IF&=~0x01}while(0)
#define PWM15_CLS_G2_CH1_IT_FLAG    do{PWM_P2_IF&=~0x02}while(0)
#define PWM15_CLS_G2_CH2_IT_FLAG    do{PWM_P2_IF&=~0x04}while(0)
#define PWM15_CLS_G2_CH3_IT_FLAG    do{PWM_P2_IF&=~0x08}while(0)
#define PWM15_CLS_G2_CH4_IT_FLAG    do{PWM_P2_IF&=~0x10}while(0)
#define PWM15_CLS_G2_CH5_IT_FLAG    do{PWM_P2_IF&=~0x20}while(0)
#define PWM15_CLS_G2_CH6_IT_FLAG    do{PWM_P2_IF&=~0x40}while(0)
#define PWM15_CLS_G2_CH7_IT_FLAG    do{PWM_P2_IF&=~0x80}while(0)
#define PWM15_CLS_G3_CH0_IT_FLAG    do{PWM_P3_IF&=~0x01}while(0)
#define PWM15_CLS_G3_CH1_IT_FLAG    do{PWM_P3_IF&=~0x02}while(0)
#define PWM15_CLS_G3_CH2_IT_FLAG    do{PWM_P3_IF&=~0x04}while(0)
#define PWM15_CLS_G3_CH3_IT_FLAG    do{PWM_P3_IF&=~0x08}while(0)
#define PWM15_CLS_G3_CH4_IT_FLAG    do{PWM_P3_IF&=~0x10}while(0)
#define PWM15_CLS_G3_CH5_IT_FLAG    do{PWM_P3_IF&=~0x20}while(0)
#define PWM15_CLS_G3_CH6_IT_FLAG    do{PWM_P3_IF&=~0x40}while(0)
#define PWM15_CLS_G3_CH7_IT_FLAG    do{PWM_P3_IF&=~0x80}while(0)
#define PWM15_CLS_G4_CH0_IT_FLAG    do{PWM_P4_IF&=~0x01}while(0)
#define PWM15_CLS_G4_CH1_IT_FLAG    do{PWM_P4_IF&=~0x02}while(0)
#define PWM15_CLS_G4_CH2_IT_FLAG    do{PWM_P4_IF&=~0x04}while(0)
#define PWM15_CLS_G4_CH3_IT_FLAG    do{PWM_P4_IF&=~0x08}while(0)
#define PWM15_CLS_G4_CH4_IT_FLAG    do{PWM_P4_IF&=~0x10}while(0)
#define PWM15_CLS_G4_CH5_IT_FLAG    do{PWM_P4_IF&=~0x20}while(0)
#define PWM15_CLS_G4_CH6_IT_FLAG    do{PWM_P4_IF&=~0x40}while(0)
#define PWM15_CLS_G4_CH7_IT_FLAG    do{PWM_P4_IF&=~0x80}while(0)
#define PWM15_CLS_G5_CH0_IT_FLAG    do{PWM_P5_IF&=~0x01}while(0)
#define PWM15_CLS_G5_CH1_IT_FLAG    do{PWM_P5_IF&=~0x02}while(0)
#define PWM15_CLS_G5_CH2_IT_FLAG    do{PWM_P5_IF&=~0x04}while(0)
#define PWM15_CLS_G5_CH3_IT_FLAG    do{PWM_P5_IF&=~0x08}while(0)
#define PWM15_CLS_G5_CH4_IT_FLAG    do{PWM_P5_IF&=~0x10}while(0)
#define PWM15_CLS_G5_CH5_IT_FLAG    do{PWM_P5_IF&=~0x20}while(0)
#define PWM15_CLS_G5_CH6_IT_FLAG    do{PWM_P5_IF&=~0x40}while(0)
#define PWM15_CLS_G5_CH7_IT_FLAG    do{PWM_P5_IF&=~0x80}while(0)

#define PWM15_SET_G0_CH0_OUT_ENABLE    do{PWM_P00_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH0_OUT_DISABLE   do{PWM_P00_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH0_INIT_H        do{PWM_P00_CR|= INI;}while(0)
#define PWM15_SET_G0_CH0_INIT_L        do{PWM_P00_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH0_IT_ENABLE     do{PWM_P00_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH0_IT_DISABLE    do{PWM_P00_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH0_T1_IT_ENABLE  do{PWM_P00_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH0_T1_IT_DISABLE do{PWM_P00_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH0_T2_IT_ENABLE  do{PWM_P00_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH0_T2_IT_DISABLE do{PWM_P00_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH0_HOLD_H        do{PWM_P00_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH0_HOLD_L        do{PWM_P00_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH0_HOLD_OFF      do{PWM_P00_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH1_OUT_ENABLE    do{PWM_P01_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH1_OUT_DISABLE   do{PWM_P01_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH1_INIT_H        do{PWM_P01_CR|= INI;}while(0)
#define PWM15_SET_G0_CH1_INIT_L        do{PWM_P01_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH1_IT_ENABLE     do{PWM_P01_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH1_IT_DISABLE    do{PWM_P01_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH1_T1_IT_ENABLE  do{PWM_P01_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH1_T1_IT_DISABLE do{PWM_P01_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH1_T2_IT_ENABLE  do{PWM_P01_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH1_T2_IT_DISABLE do{PWM_P01_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH1_HOLD_H        do{PWM_P01_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH1_HOLD_L        do{PWM_P01_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH1_HOLD_OFF      do{PWM_P01_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH2_OUT_ENABLE    do{PWM_P02_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH2_OUT_DISABLE   do{PWM_P02_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH2_INIT_H        do{PWM_P02_CR|= INI;}while(0)
#define PWM15_SET_G0_CH2_INIT_L        do{PWM_P02_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH2_IT_ENABLE     do{PWM_P02_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH2_IT_DISABLE    do{PWM_P02_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH2_T1_IT_ENABLE  do{PWM_P02_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH2_T1_IT_DISABLE do{PWM_P02_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH2_T2_IT_ENABLE  do{PWM_P02_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH2_T2_IT_DISABLE do{PWM_P02_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH2_HOLD_H        do{PWM_P02_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH2_HOLD_L        do{PWM_P02_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH2_HOLD_OFF      do{PWM_P02_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH3_OUT_ENABLE    do{PWM_P03_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH3_OUT_DISABLE   do{PWM_P03_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH3_INIT_H        do{PWM_P03_CR|= INI;}while(0)
#define PWM15_SET_G0_CH3_INIT_L        do{PWM_P03_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH3_IT_ENABLE     do{PWM_P03_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH3_IT_DISABLE    do{PWM_P03_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH3_T1_IT_ENABLE  do{PWM_P03_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH3_T1_IT_DISABLE do{PWM_P03_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH3_T2_IT_ENABLE  do{PWM_P03_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH3_T2_IT_DISABLE do{PWM_P03_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH3_HOLD_H        do{PWM_P03_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH3_HOLD_L        do{PWM_P03_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH3_HOLD_OFF      do{PWM_P03_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH4_OUT_ENABLE    do{PWM_P04_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH4_OUT_DISABLE   do{PWM_P04_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH4_INIT_H        do{PWM_P04_CR|= INI;}while(0)
#define PWM15_SET_G0_CH4_INIT_L        do{PWM_P04_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH4_IT_ENABLE     do{PWM_P04_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH4_IT_DISABLE    do{PWM_P04_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH4_T1_IT_ENABLE  do{PWM_P04_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH4_T1_IT_DISABLE do{PWM_P04_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH4_T2_IT_ENABLE  do{PWM_P04_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH4_T2_IT_DISABLE do{PWM_P04_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH4_HOLD_H        do{PWM_P04_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH4_HOLD_L        do{PWM_P04_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH4_HOLD_OFF      do{PWM_P04_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH5_OUT_ENABLE    do{PWM_P05_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH5_OUT_DISABLE   do{PWM_P05_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH5_INIT_H        do{PWM_P05_CR|= INI;}while(0)
#define PWM15_SET_G0_CH5_INIT_L        do{PWM_P05_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH5_IT_ENABLE     do{PWM_P05_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH5_IT_DISABLE    do{PWM_P05_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH5_T1_IT_ENABLE  do{PWM_P05_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH5_T1_IT_DISABLE do{PWM_P05_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH5_T2_IT_ENABLE  do{PWM_P05_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH5_T2_IT_DISABLE do{PWM_P05_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH5_HOLD_H        do{PWM_P05_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH5_HOLD_L        do{PWM_P05_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH5_HOLD_OFF      do{PWM_P05_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH6_OUT_ENABLE    do{PWM_P06_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH6_OUT_DISABLE   do{PWM_P06_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH6_INIT_H        do{PWM_P06_CR|= INI;}while(0)
#define PWM15_SET_G0_CH6_INIT_L        do{PWM_P06_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH6_IT_ENABLE     do{PWM_P06_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH6_IT_DISABLE    do{PWM_P06_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH6_T1_IT_ENABLE  do{PWM_P06_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH6_T1_IT_DISABLE do{PWM_P06_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH6_T2_IT_ENABLE  do{PWM_P06_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH6_T2_IT_DISABLE do{PWM_P06_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH6_HOLD_H        do{PWM_P06_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH6_HOLD_L        do{PWM_P06_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH6_HOLD_OFF      do{PWM_P06_HLD=0x00;}while(0)
#define PWM15_SET_G0_CH7_OUT_ENABLE    do{PWM_P07_CR|= ENO;}while(0)
#define PWM15_SET_G0_CH7_OUT_DISABLE   do{PWM_P07_CR&=~ENO;}while(0)
#define PWM15_SET_G0_CH7_INIT_H        do{PWM_P07_CR|= INI;}while(0)
#define PWM15_SET_G0_CH7_INIT_L        do{PWM_P07_CR&=~INI;}while(0)
#define PWM15_SET_G0_CH7_IT_ENABLE     do{PWM_P07_CR|= ENI;}while(0)
#define PWM15_SET_G0_CH7_IT_DISABLE    do{PWM_P07_CR&=~ENI;}while(0)
#define PWM15_SET_G0_CH7_T1_IT_ENABLE  do{PWM_P07_CR|= ENT1I;}while(0)
#define PWM15_SET_G0_CH7_T1_IT_DISABLE do{PWM_P07_CR&=~ENT1I;}while(0)
#define PWM15_SET_G0_CH7_T2_IT_ENABLE  do{PWM_P07_CR|= ENT2I;}while(0)
#define PWM15_SET_G0_CH7_T2_IT_DISABLE do{PWM_P07_CR&=~ENT2I;}while(0)
#define PWM15_SET_G0_CH7_HOLD_H        do{PWM_P07_HLD=0x02;}while(0)
#define PWM15_SET_G0_CH7_HOLD_L        do{PWM_P07_HLD=0x01;}while(0)
#define PWM15_SET_G0_CH7_HOLD_OFF      do{PWM_P07_HLD=0x00;}while(0)

#define PWM15_SET_G1_CH0_OUT_ENABLE    do{PWM_P10_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH0_OUT_DISABLE   do{PWM_P10_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH0_INIT_H        do{PWM_P10_CR|= INI;}while(0)
#define PWM15_SET_G1_CH0_INIT_L        do{PWM_P10_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH0_IT_ENABLE     do{PWM_P10_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH0_IT_DISABLE    do{PWM_P10_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH0_T1_IT_ENABLE  do{PWM_P10_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH0_T1_IT_DISABLE do{PWM_P10_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH0_T2_IT_ENABLE  do{PWM_P10_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH0_T2_IT_DISABLE do{PWM_P10_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH0_HOLD_H        do{PWM_P10_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH0_HOLD_L        do{PWM_P10_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH0_HOLD_OFF      do{PWM_P10_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH1_OUT_ENABLE    do{PWM_P11_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH1_OUT_DISABLE   do{PWM_P11_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH1_INIT_H        do{PWM_P11_CR|= INI;}while(0)
#define PWM15_SET_G1_CH1_INIT_L        do{PWM_P11_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH1_IT_ENABLE     do{PWM_P11_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH1_IT_DISABLE    do{PWM_P11_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH1_T1_IT_ENABLE  do{PWM_P11_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH1_T1_IT_DISABLE do{PWM_P11_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH1_T2_IT_ENABLE  do{PWM_P11_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH1_T2_IT_DISABLE do{PWM_P11_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH1_HOLD_H        do{PWM_P11_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH1_HOLD_L        do{PWM_P11_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH1_HOLD_OFF      do{PWM_P11_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH2_OUT_ENABLE    do{PWM_P12_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH2_OUT_DISABLE   do{PWM_P12_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH2_INIT_H        do{PWM_P12_CR|= INI;}while(0)
#define PWM15_SET_G1_CH2_INIT_L        do{PWM_P12_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH2_IT_ENABLE     do{PWM_P12_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH2_IT_DISABLE    do{PWM_P12_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH2_T1_IT_ENABLE  do{PWM_P12_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH2_T1_IT_DISABLE do{PWM_P12_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH2_T2_IT_ENABLE  do{PWM_P12_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH2_T2_IT_DISABLE do{PWM_P12_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH2_HOLD_H        do{PWM_P12_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH2_HOLD_L        do{PWM_P12_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH2_HOLD_OFF      do{PWM_P12_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH3_OUT_ENABLE    do{PWM_P13_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH3_OUT_DISABLE   do{PWM_P13_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH3_INIT_H        do{PWM_P13_CR|= INI;}while(0)
#define PWM15_SET_G1_CH3_INIT_L        do{PWM_P13_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH3_IT_ENABLE     do{PWM_P13_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH3_IT_DISABLE    do{PWM_P13_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH3_T1_IT_ENABLE  do{PWM_P13_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH3_T1_IT_DISABLE do{PWM_P13_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH3_T2_IT_ENABLE  do{PWM_P13_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH3_T2_IT_DISABLE do{PWM_P13_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH3_HOLD_H        do{PWM_P13_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH3_HOLD_L        do{PWM_P13_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH3_HOLD_OFF      do{PWM_P13_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH4_OUT_ENABLE    do{PWM_P14_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH4_OUT_DISABLE   do{PWM_P14_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH4_INIT_H        do{PWM_P14_CR|= INI;}while(0)
#define PWM15_SET_G1_CH4_INIT_L        do{PWM_P14_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH4_IT_ENABLE     do{PWM_P14_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH4_IT_DISABLE    do{PWM_P14_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH4_T1_IT_ENABLE  do{PWM_P14_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH4_T1_IT_DISABLE do{PWM_P14_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH4_T2_IT_ENABLE  do{PWM_P14_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH4_T2_IT_DISABLE do{PWM_P14_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH4_HOLD_H        do{PWM_P14_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH4_HOLD_L        do{PWM_P14_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH4_HOLD_OFF      do{PWM_P14_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH5_OUT_ENABLE    do{PWM_P15_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH5_OUT_DISABLE   do{PWM_P15_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH5_INIT_H        do{PWM_P15_CR|= INI;}while(0)
#define PWM15_SET_G1_CH5_INIT_L        do{PWM_P15_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH5_IT_ENABLE     do{PWM_P15_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH5_IT_DISABLE    do{PWM_P15_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH5_T1_IT_ENABLE  do{PWM_P15_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH5_T1_IT_DISABLE do{PWM_P15_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH5_T2_IT_ENABLE  do{PWM_P15_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH5_T2_IT_DISABLE do{PWM_P15_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH5_HOLD_H        do{PWM_P15_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH5_HOLD_L        do{PWM_P15_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH5_HOLD_OFF      do{PWM_P15_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH6_OUT_ENABLE    do{PWM_P16_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH6_OUT_DISABLE   do{PWM_P16_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH6_INIT_H        do{PWM_P16_CR|= INI;}while(0)
#define PWM15_SET_G1_CH6_INIT_L        do{PWM_P16_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH6_IT_ENABLE     do{PWM_P16_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH6_IT_DISABLE    do{PWM_P16_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH6_T1_IT_ENABLE  do{PWM_P16_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH6_T1_IT_DISABLE do{PWM_P16_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH6_T2_IT_ENABLE  do{PWM_P16_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH6_T2_IT_DISABLE do{PWM_P16_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH6_HOLD_H        do{PWM_P16_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH6_HOLD_L        do{PWM_P16_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH6_HOLD_OFF      do{PWM_P16_HLD=0x00;}while(0)
#define PWM15_SET_G1_CH7_OUT_ENABLE    do{PWM_P17_CR|= ENO;}while(0)
#define PWM15_SET_G1_CH7_OUT_DISABLE   do{PWM_P17_CR&=~ENO;}while(0)
#define PWM15_SET_G1_CH7_INIT_H        do{PWM_P17_CR|= INI;}while(0)
#define PWM15_SET_G1_CH7_INIT_L        do{PWM_P17_CR&=~INI;}while(0)
#define PWM15_SET_G1_CH7_IT_ENABLE     do{PWM_P17_CR|= ENI;}while(0)
#define PWM15_SET_G1_CH7_IT_DISABLE    do{PWM_P17_CR&=~ENI;}while(0)
#define PWM15_SET_G1_CH7_T1_IT_ENABLE  do{PWM_P17_CR|= ENT1I;}while(0)
#define PWM15_SET_G1_CH7_T1_IT_DISABLE do{PWM_P17_CR&=~ENT1I;}while(0)
#define PWM15_SET_G1_CH7_T2_IT_ENABLE  do{PWM_P17_CR|= ENT2I;}while(0)
#define PWM15_SET_G1_CH7_T2_IT_DISABLE do{PWM_P17_CR&=~ENT2I;}while(0)
#define PWM15_SET_G1_CH7_HOLD_H        do{PWM_P17_HLD=0x02;}while(0)
#define PWM15_SET_G1_CH7_HOLD_L        do{PWM_P17_HLD=0x01;}while(0)
#define PWM15_SET_G1_CH7_HOLD_OFF      do{PWM_P17_HLD=0x00;}while(0)

#define PWM15_SET_G2_CH0_OUT_ENABLE    do{PWM_P20_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH0_OUT_DISABLE   do{PWM_P20_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH0_INIT_H        do{PWM_P20_CR|= INI;}while(0)
#define PWM15_SET_G2_CH0_INIT_L        do{PWM_P20_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH0_IT_ENABLE     do{PWM_P20_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH0_IT_DISABLE    do{PWM_P20_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH0_T1_IT_ENABLE  do{PWM_P20_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH0_T1_IT_DISABLE do{PWM_P20_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH0_T2_IT_ENABLE  do{PWM_P20_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH0_T2_IT_DISABLE do{PWM_P20_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH0_HOLD_H        do{PWM_P20_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH0_HOLD_L        do{PWM_P20_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH0_HOLD_OFF      do{PWM_P20_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH1_OUT_ENABLE    do{PWM_P21_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH1_OUT_DISABLE   do{PWM_P21_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH1_INIT_H        do{PWM_P21_CR|= INI;}while(0)
#define PWM15_SET_G2_CH1_INIT_L        do{PWM_P21_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH1_IT_ENABLE     do{PWM_P21_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH1_IT_DISABLE    do{PWM_P21_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH1_T1_IT_ENABLE  do{PWM_P21_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH1_T1_IT_DISABLE do{PWM_P21_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH1_T2_IT_ENABLE  do{PWM_P21_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH1_T2_IT_DISABLE do{PWM_P21_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH1_HOLD_H        do{PWM_P21_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH1_HOLD_L        do{PWM_P21_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH1_HOLD_OFF      do{PWM_P21_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH2_OUT_ENABLE    do{PWM_P22_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH2_OUT_DISABLE   do{PWM_P22_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH2_INIT_H        do{PWM_P22_CR|= INI;}while(0)
#define PWM15_SET_G2_CH2_INIT_L        do{PWM_P22_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH2_IT_ENABLE     do{PWM_P22_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH2_IT_DISABLE    do{PWM_P22_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH2_T1_IT_ENABLE  do{PWM_P22_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH2_T1_IT_DISABLE do{PWM_P22_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH2_T2_IT_ENABLE  do{PWM_P22_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH2_T2_IT_DISABLE do{PWM_P22_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH2_HOLD_H        do{PWM_P22_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH2_HOLD_L        do{PWM_P22_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH2_HOLD_OFF      do{PWM_P22_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH3_OUT_ENABLE    do{PWM_P23_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH3_OUT_DISABLE   do{PWM_P23_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH3_INIT_H        do{PWM_P23_CR|= INI;}while(0)
#define PWM15_SET_G2_CH3_INIT_L        do{PWM_P23_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH3_IT_ENABLE     do{PWM_P23_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH3_IT_DISABLE    do{PWM_P23_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH3_T1_IT_ENABLE  do{PWM_P23_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH3_T1_IT_DISABLE do{PWM_P23_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH3_T2_IT_ENABLE  do{PWM_P23_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH3_T2_IT_DISABLE do{PWM_P23_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH3_HOLD_H        do{PWM_P23_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH3_HOLD_L        do{PWM_P23_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH3_HOLD_OFF      do{PWM_P23_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH4_OUT_ENABLE    do{PWM_P24_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH4_OUT_DISABLE   do{PWM_P24_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH4_INIT_H        do{PWM_P24_CR|= INI;}while(0)
#define PWM15_SET_G2_CH4_INIT_L        do{PWM_P24_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH4_IT_ENABLE     do{PWM_P24_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH4_IT_DISABLE    do{PWM_P24_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH4_T1_IT_ENABLE  do{PWM_P24_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH4_T1_IT_DISABLE do{PWM_P24_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH4_T2_IT_ENABLE  do{PWM_P24_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH4_T2_IT_DISABLE do{PWM_P24_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH4_HOLD_H        do{PWM_P24_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH4_HOLD_L        do{PWM_P24_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH4_HOLD_OFF      do{PWM_P24_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH5_OUT_ENABLE    do{PWM_P25_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH5_OUT_DISABLE   do{PWM_P25_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH5_INIT_H        do{PWM_P25_CR|= INI;}while(0)
#define PWM15_SET_G2_CH5_INIT_L        do{PWM_P25_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH5_IT_ENABLE     do{PWM_P25_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH5_IT_DISABLE    do{PWM_P25_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH5_T1_IT_ENABLE  do{PWM_P25_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH5_T1_IT_DISABLE do{PWM_P25_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH5_T2_IT_ENABLE  do{PWM_P25_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH5_T2_IT_DISABLE do{PWM_P25_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH5_HOLD_H        do{PWM_P25_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH5_HOLD_L        do{PWM_P25_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH5_HOLD_OFF      do{PWM_P25_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH6_OUT_ENABLE    do{PWM_P26_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH6_OUT_DISABLE   do{PWM_P26_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH6_INIT_H        do{PWM_P26_CR|= INI;}while(0)
#define PWM15_SET_G2_CH6_INIT_L        do{PWM_P26_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH6_IT_ENABLE     do{PWM_P26_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH6_IT_DISABLE    do{PWM_P26_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH6_T1_IT_ENABLE  do{PWM_P26_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH6_T1_IT_DISABLE do{PWM_P26_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH6_T2_IT_ENABLE  do{PWM_P26_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH6_T2_IT_DISABLE do{PWM_P26_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH6_HOLD_H        do{PWM_P26_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH6_HOLD_L        do{PWM_P26_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH6_HOLD_OFF      do{PWM_P26_HLD=0x00;}while(0)
#define PWM15_SET_G2_CH7_OUT_ENABLE    do{PWM_P27_CR|= ENO;}while(0)
#define PWM15_SET_G2_CH7_OUT_DISABLE   do{PWM_P27_CR&=~ENO;}while(0)
#define PWM15_SET_G2_CH7_INIT_H        do{PWM_P27_CR|= INI;}while(0)
#define PWM15_SET_G2_CH7_INIT_L        do{PWM_P27_CR&=~INI;}while(0)
#define PWM15_SET_G2_CH7_IT_ENABLE     do{PWM_P27_CR|= ENI;}while(0)
#define PWM15_SET_G2_CH7_IT_DISABLE    do{PWM_P27_CR&=~ENI;}while(0)
#define PWM15_SET_G2_CH7_T1_IT_ENABLE  do{PWM_P27_CR|= ENT1I;}while(0)
#define PWM15_SET_G2_CH7_T1_IT_DISABLE do{PWM_P27_CR&=~ENT1I;}while(0)
#define PWM15_SET_G2_CH7_T2_IT_ENABLE  do{PWM_P27_CR|= ENT2I;}while(0)
#define PWM15_SET_G2_CH7_T2_IT_DISABLE do{PWM_P27_CR&=~ENT2I;}while(0)
#define PWM15_SET_G2_CH7_HOLD_H        do{PWM_P27_HLD=0x02;}while(0)
#define PWM15_SET_G2_CH7_HOLD_L        do{PWM_P27_HLD=0x01;}while(0)
#define PWM15_SET_G2_CH7_HOLD_OFF      do{PWM_P27_HLD=0x00;}while(0)

#define PWM15_SET_G3_CH0_OUT_ENABLE    do{PWM_P30_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH0_OUT_DISABLE   do{PWM_P30_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH0_INIT_H        do{PWM_P30_CR|= INI;}while(0)
#define PWM15_SET_G3_CH0_INIT_L        do{PWM_P30_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH0_IT_ENABLE     do{PWM_P30_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH0_IT_DISABLE    do{PWM_P30_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH0_T1_IT_ENABLE  do{PWM_P30_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH0_T1_IT_DISABLE do{PWM_P30_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH0_T2_IT_ENABLE  do{PWM_P30_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH0_T2_IT_DISABLE do{PWM_P30_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH0_HOLD_H        do{PWM_P30_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH0_HOLD_L        do{PWM_P30_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH0_HOLD_OFF      do{PWM_P30_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH1_OUT_ENABLE    do{PWM_P31_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH1_OUT_DISABLE   do{PWM_P31_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH1_INIT_H        do{PWM_P31_CR|= INI;}while(0)
#define PWM15_SET_G3_CH1_INIT_L        do{PWM_P31_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH1_IT_ENABLE     do{PWM_P31_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH1_IT_DISABLE    do{PWM_P31_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH1_T1_IT_ENABLE  do{PWM_P31_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH1_T1_IT_DISABLE do{PWM_P31_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH1_T2_IT_ENABLE  do{PWM_P31_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH1_T2_IT_DISABLE do{PWM_P31_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH1_HOLD_H        do{PWM_P31_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH1_HOLD_L        do{PWM_P31_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH1_HOLD_OFF      do{PWM_P31_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH2_OUT_ENABLE    do{PWM_P32_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH2_OUT_DISABLE   do{PWM_P32_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH2_INIT_H        do{PWM_P32_CR|= INI;}while(0)
#define PWM15_SET_G3_CH2_INIT_L        do{PWM_P32_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH2_IT_ENABLE     do{PWM_P32_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH2_IT_DISABLE    do{PWM_P32_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH2_T1_IT_ENABLE  do{PWM_P32_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH2_T1_IT_DISABLE do{PWM_P32_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH2_T2_IT_ENABLE  do{PWM_P32_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH2_T2_IT_DISABLE do{PWM_P32_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH2_HOLD_H        do{PWM_P32_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH2_HOLD_L        do{PWM_P32_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH2_HOLD_OFF      do{PWM_P32_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH3_OUT_ENABLE    do{PWM_P33_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH3_OUT_DISABLE   do{PWM_P33_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH3_INIT_H        do{PWM_P33_CR|= INI;}while(0)
#define PWM15_SET_G3_CH3_INIT_L        do{PWM_P33_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH3_IT_ENABLE     do{PWM_P33_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH3_IT_DISABLE    do{PWM_P33_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH3_T1_IT_ENABLE  do{PWM_P33_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH3_T1_IT_DISABLE do{PWM_P33_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH3_T2_IT_ENABLE  do{PWM_P33_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH3_T2_IT_DISABLE do{PWM_P33_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH3_HOLD_H        do{PWM_P33_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH3_HOLD_L        do{PWM_P33_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH3_HOLD_OFF      do{PWM_P33_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH4_OUT_ENABLE    do{PWM_P34_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH4_OUT_DISABLE   do{PWM_P34_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH4_INIT_H        do{PWM_P34_CR|= INI;}while(0)
#define PWM15_SET_G3_CH4_INIT_L        do{PWM_P34_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH4_IT_ENABLE     do{PWM_P34_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH4_IT_DISABLE    do{PWM_P34_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH4_T1_IT_ENABLE  do{PWM_P34_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH4_T1_IT_DISABLE do{PWM_P34_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH4_T2_IT_ENABLE  do{PWM_P34_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH4_T2_IT_DISABLE do{PWM_P34_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH4_HOLD_H        do{PWM_P34_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH4_HOLD_L        do{PWM_P34_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH4_HOLD_OFF      do{PWM_P34_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH5_OUT_ENABLE    do{PWM_P35_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH5_OUT_DISABLE   do{PWM_P35_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH5_INIT_H        do{PWM_P35_CR|= INI;}while(0)
#define PWM15_SET_G3_CH5_INIT_L        do{PWM_P35_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH5_IT_ENABLE     do{PWM_P35_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH5_IT_DISABLE    do{PWM_P35_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH5_T1_IT_ENABLE  do{PWM_P35_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH5_T1_IT_DISABLE do{PWM_P35_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH5_T2_IT_ENABLE  do{PWM_P35_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH5_T2_IT_DISABLE do{PWM_P35_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH5_HOLD_H        do{PWM_P35_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH5_HOLD_L        do{PWM_P35_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH5_HOLD_OFF      do{PWM_P35_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH6_OUT_ENABLE    do{PWM_P36_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH6_OUT_DISABLE   do{PWM_P36_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH6_INIT_H        do{PWM_P36_CR|= INI;}while(0)
#define PWM15_SET_G3_CH6_INIT_L        do{PWM_P36_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH6_IT_ENABLE     do{PWM_P36_CR|= ENI;}while(0)
#define PWM15_SET_G3_CH6_IT_DISABLE    do{PWM_P36_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH6_T1_IT_ENABLE  do{PWM_P36_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH6_T1_IT_DISABLE do{PWM_P36_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH6_T2_IT_ENABLE  do{PWM_P36_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH6_T2_IT_DISABLE do{PWM_P36_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH6_HOLD_H        do{PWM_P36_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH6_HOLD_L        do{PWM_P36_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH6_HOLD_OFF      do{PWM_P36_HLD=0x00;}while(0)
#define PWM15_SET_G3_CH7_OUT_ENABLE    do{PWM_P37_CR|= ENO;}while(0)
#define PWM15_SET_G3_CH7_OUT_DISABLE   do{PWM_P37_CR&=~ENO;}while(0)
#define PWM15_SET_G3_CH7_INIT_H        do{PWM_P37_CR|= INI;}while(0)
#define PWM15_SET_G3_CH7_INIT_L        do{PWM_P37_CR&=~INI;}while(0)
#define PWM15_SET_G3_CH7_IT_ENABLE     do{PWM_P37_CR|= ENI;}while(0) 
#define PWM15_SET_G3_CH7_IT_DISABLE    do{PWM_P37_CR&=~ENI;}while(0)
#define PWM15_SET_G3_CH7_T1_IT_ENABLE  do{PWM_P37_CR|= ENT1I;}while(0)
#define PWM15_SET_G3_CH7_T1_IT_DISABLE do{PWM_P37_CR&=~ENT1I;}while(0)
#define PWM15_SET_G3_CH7_T2_IT_ENABLE  do{PWM_P37_CR|= ENT2I;}while(0)
#define PWM15_SET_G3_CH7_T2_IT_DISABLE do{PWM_P37_CR&=~ENT2I;}while(0)
#define PWM15_SET_G3_CH7_HOLD_H        do{PWM_P37_HLD=0x02;}while(0)
#define PWM15_SET_G3_CH7_HOLD_L        do{PWM_P37_HLD=0x01;}while(0)
#define PWM15_SET_G3_CH7_HOLD_OFF      do{PWM_P37_HLD=0x00;}while(0)

#define PWM15_SET_G4_CH0_OUT_ENABLE    do{PWM_P40_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH0_OUT_DISABLE   do{PWM_P40_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH0_INIT_H        do{PWM_P40_CR|= INI;}while(0)
#define PWM15_SET_G4_CH0_INIT_L        do{PWM_P40_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH0_IT_ENABLE     do{PWM_P40_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH0_IT_DISABLE    do{PWM_P40_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH0_T1_IT_ENABLE  do{PWM_P40_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH0_T1_IT_DISABLE do{PWM_P40_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH0_T2_IT_ENABLE  do{PWM_P40_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH0_T2_IT_DISABLE do{PWM_P40_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH0_HOLD_H        do{PWM_P40_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH0_HOLD_L        do{PWM_P40_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH0_HOLD_OFF      do{PWM_P40_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH1_OUT_ENABLE    do{PWM_P41_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH1_OUT_DISABLE   do{PWM_P41_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH1_INIT_H        do{PWM_P41_CR|= INI;}while(0)
#define PWM15_SET_G4_CH1_INIT_L        do{PWM_P41_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH1_IT_ENABLE     do{PWM_P41_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH1_IT_DISABLE    do{PWM_P41_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH1_T1_IT_ENABLE  do{PWM_P41_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH1_T1_IT_DISABLE do{PWM_P41_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH1_T2_IT_ENABLE  do{PWM_P41_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH1_T2_IT_DISABLE do{PWM_P41_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH1_HOLD_H        do{PWM_P41_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH1_HOLD_L        do{PWM_P41_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH1_HOLD_OFF      do{PWM_P41_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH2_OUT_ENABLE    do{PWM_P42_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH2_OUT_DISABLE   do{PWM_P42_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH2_INIT_H        do{PWM_P42_CR|= INI;}while(0)
#define PWM15_SET_G4_CH2_INIT_L        do{PWM_P42_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH2_IT_ENABLE     do{PWM_P42_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH2_IT_DISABLE    do{PWM_P42_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH2_T1_IT_ENABLE  do{PWM_P42_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH2_T1_IT_DISABLE do{PWM_P42_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH2_T2_IT_ENABLE  do{PWM_P42_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH2_T2_IT_DISABLE do{PWM_P42_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH2_HOLD_H        do{PWM_P42_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH2_HOLD_L        do{PWM_P42_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH2_HOLD_OFF      do{PWM_P42_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH3_OUT_ENABLE    do{PWM_P43_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH3_OUT_DISABLE   do{PWM_P43_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH3_INIT_H        do{PWM_P43_CR|= INI;}while(0)
#define PWM15_SET_G4_CH3_INIT_L        do{PWM_P43_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH3_IT_ENABLE     do{PWM_P43_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH3_IT_DISABLE    do{PWM_P43_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH3_T1_IT_ENABLE  do{PWM_P43_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH3_T1_IT_DISABLE do{PWM_P43_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH3_T2_IT_ENABLE  do{PWM_P43_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH3_T2_IT_DISABLE do{PWM_P43_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH3_HOLD_H        do{PWM_P43_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH3_HOLD_L        do{PWM_P43_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH3_HOLD_OFF      do{PWM_P43_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH4_OUT_ENABLE    do{PWM_P44_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH4_OUT_DISABLE   do{PWM_P44_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH4_INIT_H        do{PWM_P44_CR|= INI;}while(0)
#define PWM15_SET_G4_CH4_INIT_L        do{PWM_P44_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH4_IT_ENABLE     do{PWM_P44_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH4_IT_DISABLE    do{PWM_P44_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH4_T1_IT_ENABLE  do{PWM_P44_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH4_T1_IT_DISABLE do{PWM_P44_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH4_T2_IT_ENABLE  do{PWM_P44_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH4_T2_IT_DISABLE do{PWM_P44_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH4_HOLD_H        do{PWM_P44_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH4_HOLD_L        do{PWM_P44_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH4_HOLD_OFF      do{PWM_P44_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH5_OUT_ENABLE    do{PWM_P45_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH5_OUT_DISABLE   do{PWM_P45_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH5_INIT_H        do{PWM_P45_CR|= INI;}while(0)
#define PWM15_SET_G4_CH5_INIT_L        do{PWM_P45_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH5_IT_ENABLE     do{PWM_P45_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH5_IT_DISABLE    do{PWM_P45_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH5_T1_IT_ENABLE  do{PWM_P45_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH5_T1_IT_DISABLE do{PWM_P45_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH5_T2_IT_ENABLE  do{PWM_P45_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH5_T2_IT_DISABLE do{PWM_P45_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH5_HOLD_H        do{PWM_P45_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH5_HOLD_L        do{PWM_P45_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH5_HOLD_OFF      do{PWM_P45_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH6_OUT_ENABLE    do{PWM_P46_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH6_OUT_DISABLE   do{PWM_P46_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH6_INIT_H        do{PWM_P46_CR|= INI;}while(0)
#define PWM15_SET_G4_CH6_INIT_L        do{PWM_P46_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH6_IT_ENABLE     do{PWM_P46_CR|= ENI;}while(0)
#define PWM15_SET_G4_CH6_IT_DISABLE    do{PWM_P46_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH6_T1_IT_ENABLE  do{PWM_P46_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH6_T1_IT_DISABLE do{PWM_P46_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH6_T2_IT_ENABLE  do{PWM_P46_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH6_T2_IT_DISABLE do{PWM_P46_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH6_HOLD_H        do{PWM_P46_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH6_HOLD_L        do{PWM_P46_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH6_HOLD_OFF      do{PWM_P46_HLD=0x00;}while(0)
#define PWM15_SET_G4_CH7_OUT_ENABLE    do{PWM_P47_CR|= ENO;}while(0)
#define PWM15_SET_G4_CH7_OUT_DISABLE   do{PWM_P47_CR&=~ENO;}while(0)
#define PWM15_SET_G4_CH7_INIT_H        do{PWM_P47_CR|= INI;}while(0)
#define PWM15_SET_G4_CH7_INIT_L        do{PWM_P47_CR&=~INI;}while(0)
#define PWM15_SET_G4_CH7_IT_ENABLE     do{PWM_P47_CR|= ENI;}while(0) 
#define PWM15_SET_G4_CH7_IT_DISABLE    do{PWM_P47_CR&=~ENI;}while(0)
#define PWM15_SET_G4_CH7_T1_IT_ENABLE  do{PWM_P47_CR|= ENT1I;}while(0)
#define PWM15_SET_G4_CH7_T1_IT_DISABLE do{PWM_P47_CR&=~ENT1I;}while(0)
#define PWM15_SET_G4_CH7_T2_IT_ENABLE  do{PWM_P47_CR|= ENT2I;}while(0)
#define PWM15_SET_G4_CH7_T2_IT_DISABLE do{PWM_P47_CR&=~ENT2I;}while(0)
#define PWM15_SET_G4_CH7_HOLD_H        do{PWM_P47_HLD=0x02;}while(0)
#define PWM15_SET_G4_CH7_HOLD_L        do{PWM_P47_HLD=0x01;}while(0)
#define PWM15_SET_G4_CH7_HOLD_OFF      do{PWM_P47_HLD=0x00;}while(0)

#define PWM15_SET_G5_CH0_OUT_ENABLE    do{PWM_P50_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH0_OUT_DISABLE   do{PWM_P50_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH0_INIT_H        do{PWM_P50_CR|= INI;}while(0)
#define PWM15_SET_G5_CH0_INIT_L        do{PWM_P50_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH0_IT_ENABLE     do{PWM_P50_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH0_IT_DISABLE    do{PWM_P50_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH0_T1_IT_ENABLE  do{PWM_P50_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH0_T1_IT_DISABLE do{PWM_P50_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH0_T2_IT_ENABLE  do{PWM_P50_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH0_T2_IT_DISABLE do{PWM_P50_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH0_HOLD_H        do{PWM_P50_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH0_HOLD_L        do{PWM_P50_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH0_HOLD_OFF      do{PWM_P50_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH1_OUT_ENABLE    do{PWM_P51_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH1_OUT_DISABLE   do{PWM_P51_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH1_INIT_H        do{PWM_P51_CR|= INI;}while(0)
#define PWM15_SET_G5_CH1_INIT_L        do{PWM_P51_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH1_IT_ENABLE     do{PWM_P51_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH1_IT_DISABLE    do{PWM_P51_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH1_T1_IT_ENABLE  do{PWM_P51_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH1_T1_IT_DISABLE do{PWM_P51_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH1_T2_IT_ENABLE  do{PWM_P51_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH1_T2_IT_DISABLE do{PWM_P51_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH1_HOLD_H        do{PWM_P51_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH1_HOLD_L        do{PWM_P51_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH1_HOLD_OFF      do{PWM_P51_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH2_OUT_ENABLE    do{PWM_P52_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH2_OUT_DISABLE   do{PWM_P52_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH2_INIT_H        do{PWM_P52_CR|= INI;}while(0)
#define PWM15_SET_G5_CH2_INIT_L        do{PWM_P52_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH2_IT_ENABLE     do{PWM_P52_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH2_IT_DISABLE    do{PWM_P52_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH2_T1_IT_ENABLE  do{PWM_P52_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH2_T1_IT_DISABLE do{PWM_P52_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH2_T2_IT_ENABLE  do{PWM_P52_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH2_T2_IT_DISABLE do{PWM_P52_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH2_HOLD_H        do{PWM_P52_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH2_HOLD_L        do{PWM_P52_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH2_HOLD_OFF      do{PWM_P52_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH3_OUT_ENABLE    do{PWM_P53_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH3_OUT_DISABLE   do{PWM_P53_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH3_INIT_H        do{PWM_P53_CR|= INI;}while(0)
#define PWM15_SET_G5_CH3_INIT_L        do{PWM_P53_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH3_IT_ENABLE     do{PWM_P53_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH3_IT_DISABLE    do{PWM_P53_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH3_T1_IT_ENABLE  do{PWM_P53_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH3_T1_IT_DISABLE do{PWM_P53_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH3_T2_IT_ENABLE  do{PWM_P53_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH3_T2_IT_DISABLE do{PWM_P53_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH3_HOLD_H        do{PWM_P53_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH3_HOLD_L        do{PWM_P53_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH3_HOLD_OFF      do{PWM_P53_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH4_OUT_ENABLE    do{PWM_P54_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH4_OUT_DISABLE   do{PWM_P54_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH4_INIT_H        do{PWM_P54_CR|= INI;}while(0)
#define PWM15_SET_G5_CH4_INIT_L        do{PWM_P54_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH4_IT_ENABLE     do{PWM_P54_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH4_IT_DISABLE    do{PWM_P54_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH4_T1_IT_ENABLE  do{PWM_P54_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH4_T1_IT_DISABLE do{PWM_P54_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH4_T2_IT_ENABLE  do{PWM_P54_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH4_T2_IT_DISABLE do{PWM_P54_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH4_HOLD_H        do{PWM_P54_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH4_HOLD_L        do{PWM_P54_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH4_HOLD_OFF      do{PWM_P54_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH5_OUT_ENABLE    do{PWM_P55_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH5_OUT_DISABLE   do{PWM_P55_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH5_INIT_H        do{PWM_P55_CR|= INI;}while(0)
#define PWM15_SET_G5_CH5_INIT_L        do{PWM_P55_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH5_IT_ENABLE     do{PWM_P55_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH5_IT_DISABLE    do{PWM_P55_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH5_T1_IT_ENABLE  do{PWM_P55_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH5_T1_IT_DISABLE do{PWM_P55_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH5_T2_IT_ENABLE  do{PWM_P55_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH5_T2_IT_DISABLE do{PWM_P55_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH5_HOLD_H        do{PWM_P55_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH5_HOLD_L        do{PWM_P55_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH5_HOLD_OFF      do{PWM_P55_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH6_OUT_ENABLE    do{PWM_P56_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH6_OUT_DISABLE   do{PWM_P56_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH6_INIT_H        do{PWM_P56_CR|= INI;}while(0)
#define PWM15_SET_G5_CH6_INIT_L        do{PWM_P56_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH6_IT_ENABLE     do{PWM_P56_CR|= ENI;}while(0)
#define PWM15_SET_G5_CH6_IT_DISABLE    do{PWM_P56_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH6_T1_IT_ENABLE  do{PWM_P56_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH6_T1_IT_DISABLE do{PWM_P56_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH6_T2_IT_ENABLE  do{PWM_P56_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH6_T2_IT_DISABLE do{PWM_P56_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH6_HOLD_H        do{PWM_P56_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH6_HOLD_L        do{PWM_P56_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH6_HOLD_OFF      do{PWM_P56_HLD=0x00;}while(0)
#define PWM15_SET_G5_CH7_OUT_ENABLE    do{PWM_P57_CR|= ENO;}while(0)
#define PWM15_SET_G5_CH7_OUT_DISABLE   do{PWM_P57_CR&=~ENO;}while(0)
#define PWM15_SET_G5_CH7_INIT_H        do{PWM_P57_CR|= INI;}while(0)
#define PWM15_SET_G5_CH7_INIT_L        do{PWM_P57_CR&=~INI;}while(0)
#define PWM15_SET_G5_CH7_IT_ENABLE     do{PWM_P57_CR|= ENI;}while(0) 
#define PWM15_SET_G5_CH7_IT_DISABLE    do{PWM_P57_CR&=~ENI;}while(0)
#define PWM15_SET_G5_CH7_T1_IT_ENABLE  do{PWM_P57_CR|= ENT1I;}while(0)
#define PWM15_SET_G5_CH7_T1_IT_DISABLE do{PWM_P57_CR&=~ENT1I;}while(0)
#define PWM15_SET_G5_CH7_T2_IT_ENABLE  do{PWM_P57_CR|= ENT2I;}while(0)
#define PWM15_SET_G5_CH7_T2_IT_DISABLE do{PWM_P57_CR&=~ENT2I;}while(0)
#define PWM15_SET_G5_CH7_HOLD_H        do{PWM_P57_HLD=0x02;}while(0)
#define PWM15_SET_G5_CH7_HOLD_L        do{PWM_P57_HLD=0x01;}while(0)
#define PWM15_SET_G5_CH7_HOLD_OFF      do{PWM_P57_HLD=0x00;}while(0)
#endif



#if     ((ECBM_MCU&0xF0F000)==0x201000)   //STC8A8K64D4
#define PWM15_RESET                 do{PWMSET|= PWMRST;}while(0)
#define PWM15_POWER_ON              do{PWMSET|= ENPWM; }while(0)
#define PWM15_POWER_OFF             do{PWMSET&=~ENPWM; }while(0)
#define PWM15_START                 do{PWMCFG|= PWMCEN;}while(0)
#define PWM15_STOP                  do{PWMCFG&=~PWMCEN;}while(0)
#elif   ((ECBM_MCU&0xF0F000)==0x200000)   //除STC8A8K64D4以外的STC8A
#define PWM15_RESET                 do{}while(0)
#define PWM15_POWER_ON              do{}while(0)
#define PWM15_POWER_OFF             do{}while(0)
#define PWM15_START                 do{PWMCR|= PWM_EN;}while(0)
#define PWM15_STOP                  do{PWMCR&=~PWM_EN;}while(0)
#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2K系列
#define PWM15_RESET                 do{PWMSET|= PWMRST;}while(0)

#define PWM15_G0_POWER_ON           do{PWMSET|= 0x01;}while(0)
#define PWM15_G1_POWER_ON           do{PWMSET|= 0x02;}while(0)
#define PWM15_G2_POWER_ON           do{PWMSET|= 0x04;}while(0)
#define PWM15_G3_POWER_ON           do{PWMSET|= 0x08;}while(0)
#define PWM15_G4_POWER_ON           do{PWMSET|= 0x10;}while(0)
#define PWM15_G5_POWER_ON           do{PWMSET|= 0x20;}while(0)

#define PWM15_G0_POWER_OFF          do{PWMSET&=~0x01;}while(0)
#define PWM15_G1_POWER_OFF          do{PWMSET&=~0x02;}while(0)
#define PWM15_G2_POWER_OFF          do{PWMSET&=~0x04;}while(0)
#define PWM15_G3_POWER_OFF          do{PWMSET&=~0x08;}while(0)
#define PWM15_G4_POWER_OFF          do{PWMSET&=~0x10;}while(0)
#define PWM15_G5_POWER_OFF          do{PWMSET&=~0x20;}while(0)

#define PWM15_G0_START              do{PWMCFG01|= 0x01;}while(0)
#define PWM15_G1_START              do{PWMCFG01|= 0x10;}while(0)
#define PWM15_G2_START              do{PWMCFG23|= 0x01;}while(0)
#define PWM15_G3_START              do{PWMCFG23|= 0x10;}while(0)
#define PWM15_G4_START              do{PWMCFG45|= 0x01;}while(0)
#define PWM15_G5_START              do{PWMCFG45|= 0x10;}while(0)

#define PWM15_G0_STOP               do{PWMCFG01&=~0x01;}while(0)
#define PWM15_G1_STOP               do{PWMCFG01&=~0x10;}while(0)
#define PWM15_G2_STOP               do{PWMCFG23&=~0x01;}while(0)
#define PWM15_G3_STOP               do{PWMCFG23&=~0x10;}while(0)
#define PWM15_G4_STOP               do{PWMCFG45&=~0x01;}while(0)
#define PWM15_G5_STOP               do{PWMCFG45&=~0x10;}while(0)
#endif


/*

#define PWM15_CBIT_ENABLE           do{PWMCFG|= EPWMCBI;}while(0)
#define PWM15_CBIT_DISABLE          do{PWMCFG&=~EPWMCBI;}while(0)
#define PWM15_GET_CBIT_FLAG         (PWMCFG & PWMCBIF)
#define PWM15_CLS_CBIT_FLAG         do{PWMCFG&=~PWMCBIF;}while(0)
#define PWM15_SET_ADC_ENABLE        do{PWMCFG|= EPWMTA; }while(0)
#define PWM15_SET_ADC_DISABLE       do{PWMCFG|=~EPWMTA; }while(0)

#define PWM15_SET_CMP_SIG_H_L       do{PWMFDCR|= INVCMP;}while(0)
#define PWM15_SET_CMP_SIG_L_H       do{PWMFDCR&=~INVCMP;}while(0)
#define PWM15_SET_IO_SIG_H_L        do{PWMFDCR|= INVIO;}while(0)
#define PWM15_SET_IO_SIG_L_H        do{PWMFDCR&=~INVIO;}while(0)
#define PWM15_FD_ENABLE             do{PWMFDCR|= ENFD;}while(0)
#define PWM15_FD_DISABLE            do{PWMFDCR&=~ENFD;}while(0)
#define PWM15_SET_PWMFD_IO_HZ       do{PWMFDCR|= FLTFLIO;}while(0)
#define PWM15_SET_PWMFD_IO_OUT      do{PWMFDCR&=~FLTFLIO;}while(0)
#define PWM15_FD_IT_ENABLE          do{PWMFDCR|= EFDI;}while(0)
#define PWM15_FD_IT_DISABLE         do{PWMFDCR&=~EFDI;}while(0)
#define PWM15_SET_FD_CMP_ENABLE     do{PWMFDCR|= FDCMP;}while(0)
#define PWM15_SET_FD_CMP_DISABLE    do{PWMFDCR&=~FDCMP;}while(0)
#define PWM15_SET_FD_IO_ENABLE      do{PWMFDCR|= FDIO;}while(0)
#define PWM15_SET_FD_IO_DISABLE     do{PWMFDCR&=~FDIO;}while(0)
#define PWM15_GET_FD_IT_FLAG        (PWMFDCR & FDIF)
#define PWM15_CLS_FD_IT_FLAG        do{PWMFDCR&=~FDIF;}while(0)

*/


//-------------寄存器读取----------//
#if     ((ECBM_MCU&0xF00000)==0x200000)   //STC8A全系列
#define PWM15_SET_REG_CLK(value)    do{PWM_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_CLK           (PWM_CKS) 
#define PWM15_SET_REG_COUNT(value)  do{PWM_C=(u16)(value);}while(0)
#define PWM15_GET_REG_COUNT         (PWM_C) 

#define PWM15_SET_REG_CH0_T1(value) do{PWM_CH0_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH1_T1(value) do{PWM_CH1_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH2_T1(value) do{PWM_CH2_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH3_T1(value) do{PWM_CH3_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH4_T1(value) do{PWM_CH4_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH5_T1(value) do{PWM_CH5_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH6_T1(value) do{PWM_CH6_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_CH7_T1(value) do{PWM_CH7_T1=(u16)(value);}while(0)

#define PWM15_SET_REG_CH0_T2(value) do{PWM_CH0_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH1_T2(value) do{PWM_CH1_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH2_T2(value) do{PWM_CH2_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH3_T2(value) do{PWM_CH3_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH4_T2(value) do{PWM_CH4_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH5_T2(value) do{PWM_CH5_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH6_T2(value) do{PWM_CH6_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_CH7_T2(value) do{PWM_CH7_T2=(u16)(value);}while(0)

#define PWM15_SET_REG_CH0_CR(value) do{PWM_CH0_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH1_CR(value) do{PWM_CH1_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH2_CR(value) do{PWM_CH2_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH3_CR(value) do{PWM_CH3_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH4_CR(value) do{PWM_CH4_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH5_CR(value) do{PWM_CH5_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH6_CR(value) do{PWM_CH6_CR=(u8)(value);}while(0)
#define PWM15_SET_REG_CH7_CR(value) do{PWM_CH7_CR=(u8)(value);}while(0)

#define PWM15_GET_REG_CH0_T1        (PWM_CH0_T1)
#define PWM15_GET_REG_CH1_T1        (PWM_CH1_T1)
#define PWM15_GET_REG_CH2_T1        (PWM_CH2_T1)
#define PWM15_GET_REG_CH3_T1        (PWM_CH3_T1)
#define PWM15_GET_REG_CH4_T1        (PWM_CH4_T1)
#define PWM15_GET_REG_CH5_T1        (PWM_CH5_T1)
#define PWM15_GET_REG_CH6_T1        (PWM_CH6_T1)
#define PWM15_GET_REG_CH7_T1        (PWM_CH7_T1)

#define PWM15_GET_REG_CH0_T2        (PWM_CH0_T2)
#define PWM15_GET_REG_CH1_T2        (PWM_CH1_T2)
#define PWM15_GET_REG_CH2_T2        (PWM_CH2_T2)
#define PWM15_GET_REG_CH3_T2        (PWM_CH3_T2)
#define PWM15_GET_REG_CH4_T2        (PWM_CH4_T2)
#define PWM15_GET_REG_CH5_T2        (PWM_CH5_T2)
#define PWM15_GET_REG_CH6_T2        (PWM_CH6_T2)
#define PWM15_GET_REG_CH7_T2        (PWM_CH7_T2)

#define PWM15_GET_REG_CH0_CR        (PWM_CH0_CR)
#define PWM15_GET_REG_CH1_CR        (PWM_CH1_CR)
#define PWM15_GET_REG_CH2_CR        (PWM_CH2_CR)
#define PWM15_GET_REG_CH3_CR        (PWM_CH3_CR)
#define PWM15_GET_REG_CH4_CR        (PWM_CH4_CR)
#define PWM15_GET_REG_CH5_CR        (PWM_CH5_CR)
#define PWM15_GET_REG_CH6_CR        (PWM_CH6_CR)
#define PWM15_GET_REG_CH7_CR        (PWM_CH7_CR)

#elif   ((ECBM_MCU&0xFF0000)==0x320000)   //STC8G2K系列
#define PWM15_SET_REG_G0_CLK(value)    do{PWM_P0_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G0_CLK           (PWM_P0_CKS) 
#define PWM15_SET_REG_G0_COUNT(value)  do{PWM_P0_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G0_COUNT         (PWM_P0_C) 
#define PWM15_SET_REG_G1_CLK(value)    do{PWM_P1_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G1_CLK           (PWM_P1_CKS) 
#define PWM15_SET_REG_G1_COUNT(value)  do{PWM_P1_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G1_COUNT         (PWM_P1_C) 
#define PWM15_SET_REG_G2_CLK(value)    do{PWM_P2_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G2_CLK           (PWM_P2_CKS) 
#define PWM15_SET_REG_G2_COUNT(value)  do{PWM_P2_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G2_COUNT         (PWM_P2_C) 
#define PWM15_SET_REG_G3_CLK(value)    do{PWM_P3_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G3_CLK           (PWM_P3_CKS) 
#define PWM15_SET_REG_G3_COUNT(value)  do{PWM_P3_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G3_COUNT         (PWM_P3_C) 
#define PWM15_SET_REG_G4_CLK(value)    do{PWM_P4_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G4_CLK           (PWM_P4_CKS) 
#define PWM15_SET_REG_G4_COUNT(value)  do{PWM_P4_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G4_COUNT         (PWM_P4_C) 
#define PWM15_SET_REG_G5_CLK(value)    do{PWM_P5_CKS=(u8)(value);}while(0)
#define PWM15_GET_REG_G5_CLK           (PWM_P5_CKS) 
#define PWM15_SET_REG_G5_COUNT(value)  do{PWM_P5_C=(u16)(value);}while(0)
#define PWM15_GET_REG_G5_COUNT         (PWM_P5_C) 

#define PWM15_SET_REG_G0_CH0_T1(value) do{PWM_P00_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH1_T1(value) do{PWM_P01_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH2_T1(value) do{PWM_P02_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH3_T1(value) do{PWM_P03_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH4_T1(value) do{PWM_P04_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH5_T1(value) do{PWM_P05_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH6_T1(value) do{PWM_P06_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH7_T1(value) do{PWM_P07_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH0_T1(value) do{PWM_P10_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH1_T1(value) do{PWM_P11_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH2_T1(value) do{PWM_P12_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH3_T1(value) do{PWM_P13_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH4_T1(value) do{PWM_P14_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH5_T1(value) do{PWM_P15_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH6_T1(value) do{PWM_P16_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH7_T1(value) do{PWM_P17_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH0_T1(value) do{PWM_P20_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH1_T1(value) do{PWM_P21_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH2_T1(value) do{PWM_P22_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH3_T1(value) do{PWM_P23_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH4_T1(value) do{PWM_P24_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH5_T1(value) do{PWM_P25_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH6_T1(value) do{PWM_P26_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH7_T1(value) do{PWM_P27_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH0_T1(value) do{PWM_P30_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH1_T1(value) do{PWM_P31_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH2_T1(value) do{PWM_P32_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH3_T1(value) do{PWM_P33_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH4_T1(value) do{PWM_P34_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH5_T1(value) do{PWM_P35_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH6_T1(value) do{PWM_P36_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH7_T1(value) do{PWM_P37_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH0_T1(value) do{PWM_P40_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH1_T1(value) do{PWM_P41_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH2_T1(value) do{PWM_P42_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH3_T1(value) do{PWM_P43_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH4_T1(value) do{PWM_P44_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH5_T1(value) do{PWM_P45_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH6_T1(value) do{PWM_P46_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH7_T1(value) do{PWM_P47_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH0_T1(value) do{PWM_P50_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH1_T1(value) do{PWM_P51_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH2_T1(value) do{PWM_P52_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH3_T1(value) do{PWM_P53_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH4_T1(value) do{PWM_P54_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH5_T1(value) do{PWM_P55_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH6_T1(value) do{PWM_P56_T1=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH7_T1(value) do{PWM_P57_T1=(u16)(value);}while(0)

#define PWM15_SET_REG_G0_CH0_T2(value) do{PWM_P00_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH1_T2(value) do{PWM_P01_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH2_T2(value) do{PWM_P02_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH3_T2(value) do{PWM_P03_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH4_T2(value) do{PWM_P04_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH5_T2(value) do{PWM_P05_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH6_T2(value) do{PWM_P06_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH7_T2(value) do{PWM_P07_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH0_T2(value) do{PWM_P10_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH1_T2(value) do{PWM_P11_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH2_T2(value) do{PWM_P12_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH3_T2(value) do{PWM_P13_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH4_T2(value) do{PWM_P14_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH5_T2(value) do{PWM_P15_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH6_T2(value) do{PWM_P16_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH7_T2(value) do{PWM_P17_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH0_T2(value) do{PWM_P20_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH1_T2(value) do{PWM_P21_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH2_T2(value) do{PWM_P22_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH3_T2(value) do{PWM_P23_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH4_T2(value) do{PWM_P24_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH5_T2(value) do{PWM_P25_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH6_T2(value) do{PWM_P26_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH7_T2(value) do{PWM_P27_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH0_T2(value) do{PWM_P30_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH1_T2(value) do{PWM_P31_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH2_T2(value) do{PWM_P32_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH3_T2(value) do{PWM_P33_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH4_T2(value) do{PWM_P34_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH5_T2(value) do{PWM_P35_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH6_T2(value) do{PWM_P36_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH7_T2(value) do{PWM_P37_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH0_T2(value) do{PWM_P40_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH1_T2(value) do{PWM_P41_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH2_T2(value) do{PWM_P42_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH3_T2(value) do{PWM_P43_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH4_T2(value) do{PWM_P44_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH5_T2(value) do{PWM_P45_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH6_T2(value) do{PWM_P46_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH7_T2(value) do{PWM_P47_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH0_T2(value) do{PWM_P50_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH1_T2(value) do{PWM_P51_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH2_T2(value) do{PWM_P52_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH3_T2(value) do{PWM_P53_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH4_T2(value) do{PWM_P54_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH5_T2(value) do{PWM_P55_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH6_T2(value) do{PWM_P56_T2=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH7_T2(value) do{PWM_P57_T2=(u16)(value);}while(0)

#define PWM15_SET_REG_G0_CH0_CR(value) do{PWM_P00_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH1_CR(value) do{PWM_P01_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH2_CR(value) do{PWM_P02_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH3_CR(value) do{PWM_P03_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH4_CR(value) do{PWM_P04_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH5_CR(value) do{PWM_P05_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH6_CR(value) do{PWM_P06_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G0_CH7_CR(value) do{PWM_P07_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH0_CR(value) do{PWM_P10_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH1_CR(value) do{PWM_P11_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH2_CR(value) do{PWM_P12_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH3_CR(value) do{PWM_P13_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH4_CR(value) do{PWM_P14_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH5_CR(value) do{PWM_P15_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH6_CR(value) do{PWM_P16_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G1_CH7_CR(value) do{PWM_P17_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH0_CR(value) do{PWM_P20_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH1_CR(value) do{PWM_P21_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH2_CR(value) do{PWM_P22_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH3_CR(value) do{PWM_P23_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH4_CR(value) do{PWM_P24_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH5_CR(value) do{PWM_P25_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH6_CR(value) do{PWM_P26_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G2_CH7_CR(value) do{PWM_P27_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH0_CR(value) do{PWM_P30_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH1_CR(value) do{PWM_P31_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH2_CR(value) do{PWM_P32_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH3_CR(value) do{PWM_P33_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH4_CR(value) do{PWM_P34_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH5_CR(value) do{PWM_P35_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH6_CR(value) do{PWM_P36_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G3_CH7_CR(value) do{PWM_P37_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH0_CR(value) do{PWM_P40_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH1_CR(value) do{PWM_P41_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH2_CR(value) do{PWM_P42_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH3_CR(value) do{PWM_P43_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH4_CR(value) do{PWM_P44_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH5_CR(value) do{PWM_P45_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH6_CR(value) do{PWM_P46_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G4_CH7_CR(value) do{PWM_P47_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH0_CR(value) do{PWM_P50_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH1_CR(value) do{PWM_P51_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH2_CR(value) do{PWM_P52_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH3_CR(value) do{PWM_P53_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH4_CR(value) do{PWM_P54_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH5_CR(value) do{PWM_P55_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH6_CR(value) do{PWM_P56_CR=(u16)(value);}while(0)
#define PWM15_SET_REG_G5_CH7_CR(value) do{PWM_P57_CR=(u16)(value);}while(0)

#define PWM15_GET_REG_G0_CH0_T1        (PWM_P00_T1)
#define PWM15_GET_REG_G0_CH1_T1        (PWM_P01_T1)
#define PWM15_GET_REG_G0_CH2_T1        (PWM_P02_T1)
#define PWM15_GET_REG_G0_CH3_T1        (PWM_P03_T1)
#define PWM15_GET_REG_G0_CH4_T1        (PWM_P04_T1)
#define PWM15_GET_REG_G0_CH5_T1        (PWM_P05_T1)
#define PWM15_GET_REG_G0_CH6_T1        (PWM_P06_T1)
#define PWM15_GET_REG_G0_CH7_T1        (PWM_P07_T1)
#define PWM15_GET_REG_G1_CH0_T1        (PWM_P10_T1)
#define PWM15_GET_REG_G1_CH1_T1        (PWM_P11_T1)
#define PWM15_GET_REG_G1_CH2_T1        (PWM_P12_T1)
#define PWM15_GET_REG_G1_CH3_T1        (PWM_P13_T1)
#define PWM15_GET_REG_G1_CH4_T1        (PWM_P14_T1)
#define PWM15_GET_REG_G1_CH5_T1        (PWM_P15_T1)
#define PWM15_GET_REG_G1_CH6_T1        (PWM_P16_T1)
#define PWM15_GET_REG_G1_CH7_T1        (PWM_P17_T1)
#define PWM15_GET_REG_G2_CH0_T1        (PWM_P20_T1)
#define PWM15_GET_REG_G2_CH1_T1        (PWM_P21_T1)
#define PWM15_GET_REG_G2_CH2_T1        (PWM_P22_T1)
#define PWM15_GET_REG_G2_CH3_T1        (PWM_P23_T1)
#define PWM15_GET_REG_G2_CH4_T1        (PWM_P24_T1)
#define PWM15_GET_REG_G2_CH5_T1        (PWM_P25_T1)
#define PWM15_GET_REG_G2_CH6_T1        (PWM_P26_T1)
#define PWM15_GET_REG_G2_CH7_T1        (PWM_P27_T1)
#define PWM15_GET_REG_G3_CH0_T1        (PWM_P30_T1)
#define PWM15_GET_REG_G3_CH1_T1        (PWM_P31_T1)
#define PWM15_GET_REG_G3_CH2_T1        (PWM_P32_T1)
#define PWM15_GET_REG_G3_CH3_T1        (PWM_P33_T1)
#define PWM15_GET_REG_G3_CH4_T1        (PWM_P34_T1)
#define PWM15_GET_REG_G3_CH5_T1        (PWM_P35_T1)
#define PWM15_GET_REG_G3_CH6_T1        (PWM_P36_T1)
#define PWM15_GET_REG_G3_CH7_T1        (PWM_P37_T1)
#define PWM15_GET_REG_G4_CH0_T1        (PWM_P40_T1)
#define PWM15_GET_REG_G4_CH1_T1        (PWM_P41_T1)
#define PWM15_GET_REG_G4_CH2_T1        (PWM_P42_T1)
#define PWM15_GET_REG_G4_CH3_T1        (PWM_P43_T1)
#define PWM15_GET_REG_G4_CH4_T1        (PWM_P44_T1)
#define PWM15_GET_REG_G4_CH5_T1        (PWM_P45_T1)
#define PWM15_GET_REG_G4_CH6_T1        (PWM_P46_T1)
#define PWM15_GET_REG_G4_CH7_T1        (PWM_P47_T1)
#define PWM15_GET_REG_G5_CH0_T1        (PWM_P50_T1)
#define PWM15_GET_REG_G5_CH1_T1        (PWM_P51_T1)
#define PWM15_GET_REG_G5_CH2_T1        (PWM_P52_T1)
#define PWM15_GET_REG_G5_CH3_T1        (PWM_P53_T1)
#define PWM15_GET_REG_G5_CH4_T1        (PWM_P54_T1)
#define PWM15_GET_REG_G5_CH5_T1        (PWM_P55_T1)
#define PWM15_GET_REG_G5_CH6_T1        (PWM_P56_T1)
#define PWM15_GET_REG_G5_CH7_T1        (PWM_P57_T1)

#define PWM15_GET_REG_G0_CH0_T2        (PWM_P00_T2)
#define PWM15_GET_REG_G0_CH1_T2        (PWM_P01_T2)
#define PWM15_GET_REG_G0_CH2_T2        (PWM_P02_T2)
#define PWM15_GET_REG_G0_CH3_T2        (PWM_P03_T2)
#define PWM15_GET_REG_G0_CH4_T2        (PWM_P04_T2)
#define PWM15_GET_REG_G0_CH5_T2        (PWM_P05_T2)
#define PWM15_GET_REG_G0_CH6_T2        (PWM_P06_T2)
#define PWM15_GET_REG_G0_CH7_T2        (PWM_P07_T2)
#define PWM15_GET_REG_G1_CH0_T2        (PWM_P10_T2)
#define PWM15_GET_REG_G1_CH1_T2        (PWM_P11_T2)
#define PWM15_GET_REG_G1_CH2_T2        (PWM_P12_T2)
#define PWM15_GET_REG_G1_CH3_T2        (PWM_P13_T2)
#define PWM15_GET_REG_G1_CH4_T2        (PWM_P14_T2)
#define PWM15_GET_REG_G1_CH5_T2        (PWM_P15_T2)
#define PWM15_GET_REG_G1_CH6_T2        (PWM_P16_T2)
#define PWM15_GET_REG_G1_CH7_T2        (PWM_P17_T2)
#define PWM15_GET_REG_G2_CH0_T2        (PWM_P20_T2)
#define PWM15_GET_REG_G2_CH1_T2        (PWM_P21_T2)
#define PWM15_GET_REG_G2_CH2_T2        (PWM_P22_T2)
#define PWM15_GET_REG_G2_CH3_T2        (PWM_P23_T2)
#define PWM15_GET_REG_G2_CH4_T2        (PWM_P24_T2)
#define PWM15_GET_REG_G2_CH5_T2        (PWM_P25_T2)
#define PWM15_GET_REG_G2_CH6_T2        (PWM_P26_T2)
#define PWM15_GET_REG_G2_CH7_T2        (PWM_P27_T2)
#define PWM15_GET_REG_G3_CH0_T2        (PWM_P30_T2)
#define PWM15_GET_REG_G3_CH1_T2        (PWM_P31_T2)
#define PWM15_GET_REG_G3_CH2_T2        (PWM_P32_T2)
#define PWM15_GET_REG_G3_CH3_T2        (PWM_P33_T2)
#define PWM15_GET_REG_G3_CH4_T2        (PWM_P34_T2)
#define PWM15_GET_REG_G3_CH5_T2        (PWM_P35_T2)
#define PWM15_GET_REG_G3_CH6_T2        (PWM_P36_T2)
#define PWM15_GET_REG_G3_CH7_T2        (PWM_P37_T2)
#define PWM15_GET_REG_G4_CH0_T2        (PWM_P40_T2)
#define PWM15_GET_REG_G4_CH1_T2        (PWM_P41_T2)
#define PWM15_GET_REG_G4_CH2_T2        (PWM_P42_T2)
#define PWM15_GET_REG_G4_CH3_T2        (PWM_P43_T2)
#define PWM15_GET_REG_G4_CH4_T2        (PWM_P44_T2)
#define PWM15_GET_REG_G4_CH5_T2        (PWM_P45_T2)
#define PWM15_GET_REG_G4_CH6_T2        (PWM_P46_T2)
#define PWM15_GET_REG_G4_CH7_T2        (PWM_P47_T2)
#define PWM15_GET_REG_G5_CH0_T2        (PWM_P50_T2)
#define PWM15_GET_REG_G5_CH1_T2        (PWM_P51_T2)
#define PWM15_GET_REG_G5_CH2_T2        (PWM_P52_T2)
#define PWM15_GET_REG_G5_CH3_T2        (PWM_P53_T2)
#define PWM15_GET_REG_G5_CH4_T2        (PWM_P54_T2)
#define PWM15_GET_REG_G5_CH5_T2        (PWM_P55_T2)
#define PWM15_GET_REG_G5_CH6_T2        (PWM_P56_T2)
#define PWM15_GET_REG_G5_CH7_T2        (PWM_P57_T2)

#define PWM15_GET_REG_G0_CH0_CR        (PWM_P00_CR)
#define PWM15_GET_REG_G0_CH1_CR        (PWM_P01_CR)
#define PWM15_GET_REG_G0_CH2_CR        (PWM_P02_CR)
#define PWM15_GET_REG_G0_CH3_CR        (PWM_P03_CR)
#define PWM15_GET_REG_G0_CH4_CR        (PWM_P04_CR)
#define PWM15_GET_REG_G0_CH5_CR        (PWM_P05_CR)
#define PWM15_GET_REG_G0_CH6_CR        (PWM_P06_CR)
#define PWM15_GET_REG_G0_CH7_CR        (PWM_P07_CR)
#define PWM15_GET_REG_G1_CH0_CR        (PWM_P10_CR)
#define PWM15_GET_REG_G1_CH1_CR        (PWM_P11_CR)
#define PWM15_GET_REG_G1_CH2_CR        (PWM_P12_CR)
#define PWM15_GET_REG_G1_CH3_CR        (PWM_P13_CR)
#define PWM15_GET_REG_G1_CH4_CR        (PWM_P14_CR)
#define PWM15_GET_REG_G1_CH5_CR        (PWM_P15_CR)
#define PWM15_GET_REG_G1_CH6_CR        (PWM_P16_CR)
#define PWM15_GET_REG_G1_CH7_CR        (PWM_P17_CR)
#define PWM15_GET_REG_G2_CH0_CR        (PWM_P20_CR)
#define PWM15_GET_REG_G2_CH1_CR        (PWM_P21_CR)
#define PWM15_GET_REG_G2_CH2_CR        (PWM_P22_CR)
#define PWM15_GET_REG_G2_CH3_CR        (PWM_P23_CR)
#define PWM15_GET_REG_G2_CH4_CR        (PWM_P24_CR)
#define PWM15_GET_REG_G2_CH5_CR        (PWM_P25_CR)
#define PWM15_GET_REG_G2_CH6_CR        (PWM_P26_CR)
#define PWM15_GET_REG_G2_CH7_CR        (PWM_P27_CR)
#define PWM15_GET_REG_G3_CH0_CR        (PWM_P30_CR)
#define PWM15_GET_REG_G3_CH1_CR        (PWM_P31_CR)
#define PWM15_GET_REG_G3_CH2_CR        (PWM_P32_CR)
#define PWM15_GET_REG_G3_CH3_CR        (PWM_P33_CR)
#define PWM15_GET_REG_G3_CH4_CR        (PWM_P34_CR)
#define PWM15_GET_REG_G3_CH5_CR        (PWM_P35_CR)
#define PWM15_GET_REG_G3_CH6_CR        (PWM_P36_CR)
#define PWM15_GET_REG_G3_CH7_CR        (PWM_P37_CR)
#define PWM15_GET_REG_G4_CH0_CR        (PWM_P40_CR)
#define PWM15_GET_REG_G4_CH1_CR        (PWM_P41_CR)
#define PWM15_GET_REG_G4_CH2_CR        (PWM_P42_CR)
#define PWM15_GET_REG_G4_CH3_CR        (PWM_P43_CR)
#define PWM15_GET_REG_G4_CH4_CR        (PWM_P44_CR)
#define PWM15_GET_REG_G4_CH5_CR        (PWM_P45_CR)
#define PWM15_GET_REG_G4_CH6_CR        (PWM_P46_CR)
#define PWM15_GET_REG_G4_CH7_CR        (PWM_P47_CR)
#define PWM15_GET_REG_G5_CH0_CR        (PWM_P50_CR)
#define PWM15_GET_REG_G5_CH1_CR        (PWM_P51_CR)
#define PWM15_GET_REG_G5_CH2_CR        (PWM_P52_CR)
#define PWM15_GET_REG_G5_CH3_CR        (PWM_P53_CR)
#define PWM15_GET_REG_G5_CH4_CR        (PWM_P54_CR)
#define PWM15_GET_REG_G5_CH5_CR        (PWM_P55_CR)
#define PWM15_GET_REG_G5_CH6_CR        (PWM_P56_CR)
#define PWM15_GET_REG_G5_CH7_CR        (PWM_P57_CR)
#endif
/*
#define PWM15_SET_REG_TADC(value)   do{PWM_TADCP=(u16)(value);}while(0)
#define PWM15_GET_REG_TADC          (PWM_TADCP) 
#define PWM15_SET_REG_FDCR(value)   do{PWM_FDCR=(u8)(value);}while(0)
#define PWM15_GET_REG_FDCR          (PWM_FDCR)
*/

#endif