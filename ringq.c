#include <stdio.h>
#include "string.h"
#include "ringq.h"



//初始化队列
void initQueue(QUEUE* queue_q)
{
    memset(queue_q->BUF, 0, BUF_SIZE);
    queue_q->front = queue_q->rear = 0;
}
//插入成功返回1,否则返回0
unsigned char  In_Queue(QUEUE* queue_q, unsigned char value)
{
    if (Is_FullQueue(queue_q) != 1)
    {
        queue_q->BUF[queue_q->rear] = value;
        queue_q->rear = (queue_q->rear + 1) % BUF_SIZE;
        return 1;
    }
    else return 0;
}
//满了返回1,反正返回0
unsigned char Is_FullQueue(QUEUE* queue_q)
{
    if ((queue_q->rear + 1) % BUF_SIZE == queue_q->front) return 1;

    else  return 0;
}

//空队列返回1,否则返回0
unsigned char Is_EmptyQueue(QUEUE* queue_q)
{
    if (queue_q->front == queue_q->rear)return 1;
    else return 0;
}
//成功返回1,否则返回0
unsigned char Out_Queue(QUEUE* queue_q,unsigned char  *value)
{
    if (Is_EmptyQueue(queue_q) != 1)
    {
        *value = queue_q->BUF[queue_q->front];
        queue_q->BUF[queue_q->front] = 0;
        queue_q->front = (queue_q->front + 1) % BUF_SIZE;
        return 1;
    }
    else
    {
        return 0;
    }
}
//成功返回1,否则返回0，在调用此函数前，最好将对应的str参数清0
unsigned char Get_Line(QUEUE* queue_q,unsigned char *str)
{
    unsigned char temp;
    unsigned char i = 0 ;
    if(Is_EmptyQueue(queue_q))return 0;
//    for(i = 0 ; i < BUF_SIZE; i++)
//    {
//        if (Out_Queue(queue_q, &temp) == 1)
//        {
//            str[i] = temp;
//        }
//        else break;
//    }
//    return 1;
    if (Out_Queue(queue_q, &temp) == 1)
    {
        *str++ = temp;
        while (temp != '\n')
        {
            if (Out_Queue(queue_q, &temp) == 1)*str++ = temp;
            else break;
        }
        return 1;
    }
    return 0;

}
