#ifndef __DS1302__
#define __DS1302__

typedef unsigned char BYTE;
void DS1302_Initial();
void DS1302_SetTime(BYTE *p);
void DS1302_GetTime(BYTE *p);

//��    ��    ʱ    ��    ��  ����    ��
extern BYTE data init[7] ;
extern BYTE data now[7];


#endif