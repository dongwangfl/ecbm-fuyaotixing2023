#include "ecbm_core.h"
#if ECBM_CMP_EN
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
比较器初始化函数。
-------------------------------------------------------*/
void cmp_init(void){
	CMPCR2 = ECBM_CMP_CMPCR2;//写入比较器前端控制信息。
	CMPCR1 = ECBM_CMP_CMPCR1;//写入比较器后端控制信息。
	P_SW2 &= 0xF7;           //先清空该位。
	P_SW2 |= ECBM_CMP_IO;    //再写入IO输出控制位。
	#if ECBM_CMP_INIT_ON     //如果设定了初始化开启，
	CMP_ON;                  //就开启比较器。
	#endif
}
/*-------------------------------------------------------
比较器读取结果函数。
-------------------------------------------------------*/
bit cmp_read(void){
	if(CMPCR1&0x01){//判断结果寄存器，
		return 1;   //有结果就返回1，
	}else{
		return 0;	//否则返回0。
	}
}
/*-------------------------------------------------------
比较器开启函数。
-------------------------------------------------------*/
void cmp_start(void){
	CMP_ON;
}
/*-------------------------------------------------------
比较器关闭函数。
-------------------------------------------------------*/
void cmp_stop(void){
	CMP_OFF;
}
#endif
