#include "ecbm_core.h"	//加载库函数的头文件。
#include "string.h"
#include "ringq.h"
#include "ds1302.h"
#include <stdlib.h>

unsigned char   FUYAOSHIJIAN =3;
unsigned char FUYAOSHIJIANFENZHONG = 3;
unsigned char  DUISHISHIJIAN =3;
unsigned char  QINGSHUJUSHIJIAN = 3;
unsigned char YIFUYAOCUNCHU = 0;

sbit BEEP= P3^7;
unsigned char line1[128]= {0};
unsigned char line2[128]= {0};

unsigned char flag = 0;
unsigned char flag2 = 0 ;
QUEUE queue1,*ptrqueue1;
QUEUE queue2,*ptrqueue2;
int i = 0 ;

unsigned char  find_string(unsigned char *line, char* p)
{
    if(strstr(line,p)!=NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* 功  能：将str字符串中的oldstr字符串替换为newstr字符串
 * 参  数：str：操作目标 oldstr：被替换者 newstr：替换者
 * 返回值：返回替换之后的字符串
 * 版  本： V0.2
 */
char *strrpc(char *str,char *oldstr,char *newstr) {
    char bstr[32];//转换缓冲区
    unsigned char i = 0 ;
    memset(bstr,0,sizeof(bstr));

    for(i = 0; i < strlen(str); i++) {
        if(!strncmp(str+i,oldstr,strlen(oldstr))) { //查找目标字符串
            strcat(bstr,newstr);
            i += strlen(oldstr) - 1;
        } else {
            strncat(bstr,str + i,1);//保存一字节进缓冲区
        }
    }

    strcpy(str,bstr);
    return str;
}
char *SubString(char *p,char *dst,index)
{
    char bstr[32];
    char i = 0 ;
    memset(bstr,0,sizeof(bstr));

    for(i = index ; i < strlen(p); i++)
    {
        bstr[i-index] = *(p+i);
    }

    strcpy(dst,bstr);
    return dst;


}

unsigned char ESP8266_send_cmd(char *b,char *a,unsigned char times,unsigned int wait_time)
{
    unsigned char  i=0;
    while(i < times)
    {
        uart_printf(2,b);
        uart_printf(2,"\r\n");	         // 回车换行

        delay_ms(wait_time);
        Get_Line(ptrqueue2,line2);
        if(find_string(line2,a))
        {
            return 1;
        }
        i++;
    }
    return 0;
}
unsigned int tick =0,tickflag=0;
void fun1(void)TIMER0_IT_NUM { //这是定时器0的中断处理函数。10ms

    tick++;
    if(tick%100==0)
    {
        tickflag=1;
    }




}
void main() {			//main函数，必须的。

    int times = 0 ;
    int len = 0 ;
    unsigned char     yifuyao=0;
    bit    yiduishi=0;
    unsigned char time[2]= {0};
    unsigned char  volatile beep = 0;
    unsigned int year=0;
    BYTE BYTEYEAR = 0 ;
    unsigned int secondstick = 0 ;


    P37 = 0 ;
    P3M0 = 0X80;
    P3M1 = 0;
    beep = 0 ;

    /**********************
    	可以降低功耗
    ******************/
    P0M0 = 0xff ;
    P0M1 = 0xff ;
    P1M0 = 0xff;
    P1M1 = 0xff;
    P2M0 = 0xff;
    P2M1 = 0xff;
    P3M0 = 0xff;
    P3M1 = 0xff;
    P4M0 = 0xff;
    P4M1 = 0xff;
    P5M0 = 0xff ;
    P5M1 = 0xff;

    P1M0 &= 0XF0;  //P10 1 2 3串口二为准双向
    P1M1 &=0XF0;

    P3M1 &=0X7F; //P37 设置成推挽输出驱动蜂鸣器  M0 = 1 M1 = 0
    P3M0 |= 0X80;

    P3M1 &= 0XFB;//将P32设置成准双向模式
    P3M0 &= 0XFB;

    P2M1 &= 0X0F;//将P24,5,6,7设置成准双向模式，其它的为开漏
    P2M0 &= 0X0F;

    P3M1 &=0XFC; //串口P30 1 为准双向
    P3M0 &=0XFC;







    system_init();		//系统初始化函数，也是必须的。
    timer_init();
    eeprom_init();
    timer_start(0);//再打开定时器0。
    timer_set_timer_mode(0,10000);
    DS1302_Initial();

    FUYAOSHIJIAN = eeprom_read(0);
    FUYAOSHIJIANFENZHONG = eeprom_read(1);
    DUISHISHIJIAN = eeprom_read(2);
    QINGSHUJUSHIJIAN = eeprom_read(3);
    if(FUYAOSHIJIAN == 3 || FUYAOSHIJIAN == 0XFF)FUYAOSHIJIAN = 7;
    if(FUYAOSHIJIANFENZHONG==3 || FUYAOSHIJIANFENZHONG == 0XFF)FUYAOSHIJIANFENZHONG=0;
    if(DUISHISHIJIAN==3)DUISHISHIJIAN = 8;
    if(QINGSHUJUSHIJIAN==3)QINGSHUJUSHIJIAN = 0;


    //两个串口的环形队列初始化
    ptrqueue1 = &queue1;
    ptrqueue2 = &queue2;
    initQueue(ptrqueue1);
    initQueue(ptrqueue2);

    uart_printf(1,"——————————————————————————————————————————————————\r\n");
    uart_printf(1,"———————————————————————服药提醒————————————————————\r\n");
    uart_printf(1,"实现的命令:\r\n");
    uart_printf(1,"           1. 设置报警时间: SETATIME#07:00\r\n");
    uart_printf(1,"——————————————————————————————————————————————————\r\n");

    uart_printf(1,"starting..\r\n");
    uart_set_baud(2,115200);
    delay_ms(3000);
    while(Get_Line(ptrqueue2,line2));//清除UART2的缓冲区
    memset(line2,0,BUF_SIZE);



    if(ESP8266_send_cmd("AT+CIPSNTPCFG=1,8","OK",3,300))
    {
        uart_printf(1,"send command AT+CIPSNTPCFG=1,8  OK\r\n");
    }
    else
    {
        uart_printf(1,"send command AT+CIPSNTPCFG=1,8 failed\r\n");
    }

    delay_ms(3000);

    uart_printf(2,"AT+CIPSNTPTIME?\r\n");

    eeprom_read_ex(20,&yifuyao,1);

    while(1)
    {

        if(tickflag) //1s时间到
        {
            tickflag=0;
            DS1302_GetTime(now);
            uart_printf(1,"%bd: %bd: %bd   ATIME：%bd   %bd \r\n",now[2],now[1],now[0],FUYAOSHIJIAN,FUYAOSHIJIANFENZHONG);
            secondstick++;
            if(secondstick%5==0)P12=0;
            else P12 = 1;
            if(secondstick % 3600==0)//每个小时对一次时，避免偶尔对时失败，导致时间永远不能对时
            {
                uart_printf(2,"AT+CIPSNTPTIME?\r\n");
            }


//            if(now[2] == DUISHISHIJIAN && now[1] ==1 && now[0] == 1 && yiduishi == 0)  // 8：1:1时，连接服器器对时
//            {
//
//
//            }
            if(now[2] != FUYAOSHIJIAN )//时清fifuyao和 
            {
                yifuyao=0;
                eeprom_read_ex(20,&yifuyao,1);
                if(yifuyao!= 0 )
                {
                    yifuyao = 0;
                    eeprom_write_ex(20,&yifuyao,1);delay_ms(50);
                }

            }
            if(now[2] == FUYAOSHIJIAN &&now[1] >= FUYAOSHIJIANFENZHONG  )
            {
								eeprom_read_ex(20,&yifuyao,1);
                if(yifuyao==0)
                {
                    beep = 1;
                    //判断是否已取瓶，已取瓶就将yifuyao置1
                    P24 = 0 ;//打开光电管的电源，

                    delay_ms(1);
                    if(P32 == 1) //检测药瓶是否在上面
                    {
                        delay_ms(20);
                        if(P32 == 1)
                        {
                            _nop_();
                            yifuyao = 1;
                            eeprom_write_ex(20,&yifuyao,1);delay_ms(50);
                        }
                    }
                    P24 = 1 ;

                }
                else beep = 0;
            }
            if(beep)
            {
                BEEP= !BEEP;
            }
            else BEEP = 0 ;

        }
        //以下是串口处理程序
        if(flag>0)
        {
            flag-=1;
            uart_printf(1,"uart1 received:");
            Get_Line(ptrqueue1,line1);
            if(strlen(line1)>0)
            {
                if(line1[0]=='A' && line1[1] == 'T')	uart_printf(2,line1); //如果是AT指令，则转发串口2
                else if(strncmp(line1,"SETATIME",8)==0)//如果接收到的是SETATIME，则是设置提醒服药时间，SETATIME#07:00;
                {
                    i=strpos(line1,'#');
                    if(i!=-1)
                    {
                        time[0]=line1[i+1];
                        time[1]=line1[i+2];
                        FUYAOSHIJIAN = atoi(time);
                        time[0] = line1[i+4],time[1] = line1[i+5];
                        FUYAOSHIJIANFENZHONG = atoi(time);
                        time[0] = FUYAOSHIJIAN;
                        time[1] = FUYAOSHIJIANFENZHONG;
                        eeprom_write_ex(0,time,2);
                        delay_ms(50);
                        time[0]=0;
                        time[1] = 0;
                        eeprom_read_ex(0,time,2);
                        if(time[0] ==FUYAOSHIJIAN && time[1] == FUYAOSHIJIANFENZHONG) uart_printf(1,"SETATIME AT %bd：%bd  ....OK!\r\n",time[0],time[1]);
                        else uart_printf(1,"SETATIME FAILED!\r\n");
                    }
                }
            }

            memset(line1,0,BUF_SIZE);
        }
        if(flag2>0)
        {
            flag2-=1;
            Get_Line(ptrqueue2,line2);
            uart_string(1,line2);

            if(find_string(line2,"+CIPSNTPTIME:"))
            {
                uart_printf(1,"time:");
                uart_printf(1,line2);
                len = strlen(line2);
                time[0]=line2[len-9];
                time[1]=line2[len-8];
                init[0] = atoi(time);

                time[0]=line2[len-12];
                time[1]=line2[len-11];
                init[1] = atoi(time);

                time[0]=line2[len-15];
                time[1]=line2[len-14];
                init[2] = atoi(time);

                time[0]=line2[len-4];  //+CIPSNTPTIME:Mon Nov 08 19:49:26 2021  最后的21,保存到init中，
                time[1] = line2[len-3];
                init[6] = atoi(time);


                time[0] = line2[len-6];//+CIPSNTPTIME:Mon Nov 08 19:49:26 2021  最后的20,和21组合，检测是否获取正确的时间
                time[1] = line2[len-5];
                BYTEYEAR = atoi(time);

                init[3] = 1;
                init[4] = 1,init[5] = 1;

                year=(int)(BYTEYEAR*100)+init[6];
                uart_printf(1,"--    %d\r\n",year);

                if(year>= 2021)
                {
                    if(init[0]!=0&&init[1]!=0&&init[2]!=0)
                    {
                        DS1302_SetTime(init);
                        uart_printf(1,"set time ok\r\n");
                    }
                }
                //秒    分    时    日    月  星期    年
                //extern BYTE data init[7] ;
            }
            memset(line2,0,BUF_SIZE);
        }
        //以上是串口处理程序
    }
}
unsigned char temp1 = 0 ;
void uart1_receive_callback(void)
{
    temp1 = SBUF;
    In_Queue(ptrqueue1,temp1);

    if(temp1 == '\n')
    {
        flag++;
    }
}
unsigned char temp2=0;
void uart2_receive_callback(void)
{
    temp2 = S2BUF;
    In_Queue(ptrqueue2,temp2);

    if(temp2 == '\n')
    {
        flag2++;
    }
}
