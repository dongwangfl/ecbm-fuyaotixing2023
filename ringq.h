#ifndef __RINGQ_H__
#define __RINGQ_H__

#define  BUF_SIZE  128
typedef struct {
    unsigned char BUF[BUF_SIZE];
    int front;
    int rear;
} QUEUE;

extern QUEUE queue,*ptrqueue;
extern void initQueue(QUEUE* queue_q);
extern unsigned char  In_Queue(QUEUE* queue_q, unsigned char  value);
extern unsigned char Is_FullQueue(QUEUE* queue_q);
extern unsigned char Is_EmptyQueue(QUEUE* queue_q);
extern unsigned char Out_Queue(QUEUE* queue_q, unsigned char* value);
extern unsigned char Get_Line(QUEUE* queue_q, unsigned char* str);

#endif

