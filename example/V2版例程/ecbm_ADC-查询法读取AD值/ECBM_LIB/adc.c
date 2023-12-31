#include "ecbm_core.h"
#if ECBM_ADC_EN
/*--------------------------------------变量定义-----------------------------------*/
u8 xdata adc_busy;
float xdata adc_ch15;
/*------------------------------------资源冲突警告---------------------------------*/

/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
ADC初始化函数。
-------------------------------------------------------*/
void adc_init(){
	ADCCFG=ECBM_ADC_SPEED;//设置ADC的配置
	adc_ch15=(float)(REG_BGV)/1000.0f;//将内部电压基准取出来，防止之后idata覆盖。
#if ECBM_ADC_IT_EN
	EADC=1;
#endif
#if ECBM_MCU_MAIN_RAM == 1 //STC8A8K__S4A12	
	#if ECBM_T1_ADC_CH0//在链接主库且相应通道使能的情况下，设置IO口为高阻态。下同。
		gpio_mode(A00,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH1
		gpio_mode(A01,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH2
		gpio_mode(A02,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH3
		gpio_mode(A03,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH4
		gpio_mode(A04,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH5
		gpio_mode(A05,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH6
		gpio_mode(A06,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH7
		gpio_mode(A07,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH8
		gpio_mode(A08,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH9
		gpio_mode(A09,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH10
		gpio_mode(A10,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH11
		gpio_mode(A11,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH12
		gpio_mode(A12,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH13
		gpio_mode(A13,GPIO_HZ);
	#endif
	#if ECBM_T1_ADC_CH14
		gpio_mode(A14,GPIO_HZ);
	#endif
#endif
#if ECBM_MCU_MAIN_RAM == 2 //STC8G2K__S4-48PIN	
	#if ECBM_T2_ADC_CH0//在链接主库且相应通道使能的情况下，设置IO口为高阻态。下同。
		gpio_mode(A00,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH1
		gpio_mode(A01,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH2
		gpio_mode(A02,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH3
		gpio_mode(A03,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH4
		gpio_mode(A04,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH5
		gpio_mode(A05,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH6
		gpio_mode(A06,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH7
		gpio_mode(A07,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH8
		gpio_mode(A08,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH9
		gpio_mode(A09,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH10
		gpio_mode(A10,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH11
		gpio_mode(A11,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH12
		gpio_mode(A12,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH13
		gpio_mode(A13,GPIO_HZ);
	#endif
	#if ECBM_T2_ADC_CH14
		gpio_mode(A14,GPIO_HZ);
	#endif
#endif
#if ECBM_MCU_MAIN_RAM == 3 //STC8G1K__A-8Pin
	#if ECBM_T3_ADC_CH0
		gpio_mode(A00,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH1
		gpio_mode(A01,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH2
		gpio_mode(A02,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH3
		gpio_mode(A03,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH4
		gpio_mode(A04,GPIO_HZ);
	#endif
	#if ECBM_T3_ADC_CH5
		gpio_mode(A05,GPIO_HZ);
	#endif
#endif
}
/*-------------------------------------------------------
查询法读取AD值函数。
-------------------------------------------------------*/
u16 adc_read(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//同上
	_nop_();
	_nop_();
	#if ECBM_ADC_IT_EN
	adc_busy=1;
	while(adc_busy);
	#else
	while((ADC_CONTR&0x20)==0);
	ADC_CONTR&=0xDF;
	#endif
	#if ECBM_ADC_8BIT//使能8位数据模式的话，编译8位读取函数。
	return (u16)ADC_RES;  //返回结果寄存器的值。
	#else            //否则编译12位读取函数。
	return (u16)(ADC_RES<<8|ADC_RESL);//将两个结果寄存器的值组合在一起，返回一个12位数据。
	#endif
}
/*-------------------------------------------------------
ADC转换开始函数（中断法）。
-------------------------------------------------------*/
#if ECBM_ADC_IT_EN
void adc_read_start(u8 pin){
	ADC_CONTR=0x80|0x40|(pin&0x0f);//同上
	_nop_();
	_nop_();
}
#endif
/*-------------------------------------------------------
中断法读取AD值函数。
-------------------------------------------------------*/
#if ECBM_ADC_IT_EN
u16 adc_read_it(){
	#if ECBM_ADC_8BIT//使能8位数据模式的话，编译8位读取函数。
	return ADC_RES;//返回结果寄存器的值。
	#else //否则编译12位读取函数。
	return (ADC_RES<<8|ADC_RESL);//将两个结果寄存器的值组合在一起，返回一个12位数据。
	#endif
}
#endif
/*-------------------------------------------------------
读取电压函数。
-------------------------------------------------------*/
float adc_voltage(u8 pin,float vref){
	u16 jg;
	jg=adc_read(pin);//先读取AD值。
	#if ECBM_ADC_8BIT//根据设置，把AD值换算成电压值。
	return (float)jg*vref/256.0f;//8位数据。
	#else
	return (float)jg*vref/(ECBM_MCU_ADC);//12位数据。
	#endif
}
/*-------------------------------------------------------
开启ADC中断函数。
-------------------------------------------------------*/
void adc_it_start(){
	EADC=1;
}
/*-------------------------------------------------------
关闭ADC中断函数。
-------------------------------------------------------*/
void adc_it_stop(){
	EADC=0;
}
/*-------------------------------------------------------
ADC读取Vref函数。
-------------------------------------------------------*/
float adc_read_vref(void){
	u16 jg;
	jg=adc_read(15);//先读取AD值。  
	if(jg==0)return 0.0f;//防止出现NaN
	#if ECBM_ADC_8BIT//根据设置，把AD值换算成电压值。
	return (adc_ch15*256.0f)/((float)jg);//8位数据。
	#else
	return (adc_ch15)*(ECBM_MCU_ADC)/((float)jg);//12位数据。
	#endif
}
#endif
