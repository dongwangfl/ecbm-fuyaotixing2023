/**************************************
--- STC MCU Limited -------------------
--- 宏晶科技        设计 2010-6-2 -----
--- Mobile: 13922805190 ---------------
--- Fax: 0755-82944243 ----------------
--- Tel: 0755-82948412 ----------------
--- Web: www.STCMCU.com ---------------
--- 演示STC 1TMCU控制DS1302 -----------
--- 工作频率: 12MHz -------------------
如果要在程序中使用或在文章中引用该程序
请在其中注明使用了宏晶科技的资料及程序
**************************************/

#include "REG51.H"
#include "INTRINS.H"
#include "ds1302.h"


sbit SCLK = P2^7;                   //DS1302时钟口P1.0
sbit IO = P2^6;                     //DS1302数据口P1.1
sbit RST = P2^5;                    //DS1302片选口P1.2

//秒    分    时    日    月  星期    年
BYTE data init[] = {00, 1, 10,4, 1, 0x05, 20};
BYTE data now[7];
int IntToBcd(BYTE d);

/**************************************
延时X微秒(STC12C5A60S2@12M)
不同的工作环境,需要调整此函数
此延时函数是使用1T的指令周期进行计算,与传统的12T的MCU不同
**************************************/
void Delay()
{
    _nop_();
    _nop_();
}

/**************************************
从DS1302读1字节数据
**************************************/
BYTE DS1302_ReadByte()
{
    BYTE i;
    BYTE dat = 0;

    for (i=0; i<8; i++)             //8位计数器
    {
        SCLK = 0;                   //时钟线拉低
        Delay();                //延时等待
        dat >>= 1;	                //数据右移一位
        if (IO) dat |= 0x80;        //读取数据
        SCLK = 1;                   //时钟线拉高
        Delay();                //延时等待
    }

    return dat;
}

/**************************************
向DS1302写1字节数据
**************************************/
void DS1302_WriteByte(BYTE dat)
{
    char i;

    for (i=0; i<8; i++)             //8位计数器
    {
        SCLK = 0;                   //时钟线拉低
        Delay();                //延时等待
        dat >>= 1;                  //移出数据
        IO = CY;                    //送出到端口
        SCLK = 1;                   //时钟线拉高
        Delay();                //延时等待
    }
}

/**************************************
读DS1302某地址的的数据
**************************************/
BYTE DS1302_ReadData(BYTE addr)
{
    BYTE dat;

    RST = 0;
    Delay();
    SCLK = 0;
    Delay();
    RST = 1;
    Delay();
    DS1302_WriteByte(addr);         //写地址
    dat = DS1302_ReadByte();        //读数据
    SCLK = 1;
    RST = 0;

    return dat;
}

/**************************************
往DS1302的某个地址写入数据
**************************************/
void DS1302_WriteData(BYTE addr, BYTE dat)
{
    RST = 0;
    Delay();
    SCLK = 0;
    Delay();
    RST = 1;
    Delay();
    DS1302_WriteByte(addr);         //写地址
    DS1302_WriteByte(dat);          //写数据
    SCLK = 1;
    RST = 0;
}

/**************************************
写入初始时间
**************************************/
void DS1302_SetTime(BYTE *p)
{
    BYTE addr = 0x80;
    BYTE n = 7;

    DS1302_WriteData(0x8e, 0x00);   //允许写操作
    while (n--)
    {
        DS1302_WriteData(addr, IntToBcd(*p++));
        addr += 2;
    }
    DS1302_WriteData(0x8e, 0x80);   //写保护
}
int BcdToInt(BYTE bcd)
{
    int k = 0 ;
    k = bcd>>4;
    k = k*10;
    k = k+(bcd&0x0f);
    return k;
}

int IntToBcd(BYTE d)
{
    BYTE c = 0 ;
    c = (d/10)<<4;
    c|=(d%10);
    return c;
}
/**************************************
读取当前时间
**************************************/
void DS1302_GetTime(BYTE *p)
{
    BYTE addr = 0x81;
    BYTE n = 7;

    while (n--)
    {
        *p++ = BcdToInt(DS1302_ReadData(addr));
        addr += 2;
    }
}

/**************************************
初始化DS1302
**************************************/
void DS1302_Initial()
{
    RST = 0;
    SCLK = 0;
    DS1302_WriteData(0x8e, 0x00);   //允许写操作
    DS1302_WriteData(0x80, 0x00);   //时钟启动
    DS1302_WriteData(0x90, 0xa6);   //一个二极管＋4K电阻充电
    DS1302_WriteData(0x8e, 0x80);   //写保护
}
