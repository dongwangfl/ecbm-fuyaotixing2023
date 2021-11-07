#include "ecbm_core.h"	//加载库函数的头文件。
#include "string.h"
#include "ringq.h"
#include "ds1302.h"
#include <stdlib.h>

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
void fun1(void)TIMER0_IT_NUM{//这是定时器0的中断处理函数。10ms

    tick++;
    if(tick%100==0)
    {
        tickflag=1;
    }




}
void main() {			//main函数，必须的。
    int times = 0 ;
    int len = 0 ;
    unsigned char time[2]= {0};

    system_init();		//系统初始化函数，也是必须的。
    timer_init();
    timer_start(0);//再打开定时器0。
    timer_set_timer_mode(0,10000);
    DS1302_Initial();

    //两个串口的环形队列初始化
    ptrqueue1 = &queue1;
    ptrqueue2 = &queue2;
    initQueue(ptrqueue1);
    initQueue(ptrqueue2);

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

    delay_ms(500);
    uart_printf(2,"AT+CIPSNTPTIME?\r\n");



    while(1)
    {

        if(tickflag) //1s时间到
        {
            tickflag=0;
            DS1302_GetTime(now);
            uart_printf(1,"%bd: %bd: %bd\r\n",now[2],now[1],now[0]);
			
        }

        if(flag>0)
        {
            flag-=1;
            uart_printf(1,"uart1  %bd received:",flag);

            Get_Line(ptrqueue1,line1);
            uart_printf(2,line1);

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

                init[3] = 1;
                init[4] = 1,init[5] = 1,init[6]=21;

                if(init[0]!=0&&init[1]!=0&&init[2]!=0)
                {
                    DS1302_SetTime(init);
                    uart_printf(1,"set time ok\r\n");
                }

                //秒    分    时    日    月  星期    年
                //extern BYTE data init[7] ;


                // uart_printf(1,"%s\r\n",time);
                // uart_printf(1,"-------\r\n");
            }

            memset(line2,0,BUF_SIZE);
        }


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
