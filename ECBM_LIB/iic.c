#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
#if ECBM_IIC_LIB_EN   //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
bit iic_busy;
u8 xdata iic_index;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
IIC���������ú�����
-------------------------------------------------------*/
void iic_set_pin(u8 group){
#if (ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1)
    switch(group){
        case IIC_PIN_P32_P33:{//�л���D32��D33
            P3M1|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
            P3M0|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
            P3PU|=0x0C;//0000 1100 IIC��Ҫһ����������       
        }break;
        case IIC_PIN_P54_P55:{//�л���D54��D55
            P5M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
            P5M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
            P5PU|=0x30;//0011 0000 IIC��Ҫһ����������
        }break;
        default:break;
    }    
#else
    switch(group){
        case IIC_PIN_P15_P14:{//�л���D14��D15
            P1M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
            P1M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
            P1PU|=0x30;//0011 0000 IIC��Ҫһ����������       
        }break;
        case IIC_PIN_P25_P24:{//�л���D24��D25
            P2M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
            P2M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
            P2PU|=0x30;//0011 0000 IIC��Ҫһ����������
        }break;
        case IIC_PIN_P77_P76:{//�л���D76��D77
            P7M1|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
            P7M0|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
            P7PU|=0xC0;//1100 0000 IIC��Ҫһ����������
        }break;
        case IIC_PIN_P32_P33:{//�л���D32��D33
            P3M1|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
            P3M0|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
            P3PU|=0x0C;//0000 1100 IIC��Ҫһ����������
        }break;
        default:break;
    }
#endif
    IIC_SET_PIN(group);
}
/*-------------------------------------------------------
IIC���������ú����������棩��
-------------------------------------------------------*/
void iic_set_pin_linkage(u8 group){
    if(iic_index!=group){
        iic_index=group;
        IIC_POWER_OFF;
        IIC_SET_PIN(group);
        IIC_POWER_ON;
    }
}
/*-------------------------------------------------------
IIC�����Ż�ԭ������
-------------------------------------------------------*/
void iic_reset_pin(u8 group){
#if    (ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1)
    switch(group){
        case IIC_PIN_P32_P33:{//��ԭD32��D33
            P3M1&=~0x0C;//1111 0011 ��ԭ����ģʽ
            P3M0&=~0x0C;//1111 0011 ��ԭ����ģʽ
            P3PU&=~0x0C;//1111 0011 ȥ����������       
        }break;
        case IIC_PIN_P54_P55:{//��ԭD54��D55
            P5M1&=~0x30;//1100 1111 ��ԭ����ģʽ
            P5M0&=~0x30;//1100 1111 ��ԭ����ģʽ
            P5PU&=~0x30;//1100 1111 ȥ����������
        }break;
        default:break;
    }    
#else
    switch(group){
        case IIC_PIN_P15_P14:{//��ԭD14��D15
            P1M1&=~0x30;//1100 1111 ��ԭ����ģʽ
            P1M0&=~0x30;//1100 1111 ��ԭ����ģʽ
            P1PU&=~0x30;//1100 1111 ȥ����������      
        }break;
        case IIC_PIN_P25_P24:{//��ԭD24��D25
            P2M1&=~0x30;//1100 1111 ��ԭ����ģʽ
            P2M0&=~0x30;//1100 1111 ��ԭ����ģʽ
            P2PU&=~0x30;//1100 1111 ȥ����������
        }break;
        case IIC_PIN_P77_P76:{//��ԭD76��D77
            P7M1&=~0xC0;//0011 1111 ��ԭ����ģʽ
            P7M0&=~0xC0;//0011 1111 ��ԭ����ģʽ
            P7PU&=~0xC0;//0011 1111 ȥ����������
        }break;
        case IIC_PIN_P32_P33:{//��ԭD32��D33
            P3M1&=~0x0C;//1111 0011 ��ԭ����ģʽ
            P3M0&=~0x0C;//1111 0011 ��ԭ����ģʽ
            P3PU&=~0x0C;//1111 0011 ȥ����������
        }break;
        default:break;
    }
#endif
}
/*-------------------------------------------------------
IIC������ʼ��������
-------------------------------------------------------*/
void iic_master_init(void){
    u8 res=63;
    res=(u8)(((ecbm_sys_clk/2/ECBM_IIC_WAIT)-4)/2)&0x3F;
    IIC_SET_MODE_MASTER;//����Ϊ����
    IIC_SET_SPEED(res);//�ȴ�ʱ��
    IIC_SET_REG_MSST(0);//������б�־λ
    iic_set_pin(ECBM_IIC_IO);//Ĭ��ʹ��0�飬��P14��P15
    iic_index=ECBM_IIC_IO;
    IIC_POWER_ON;//����IIC
}
/*-------------------------------------------------------
IIC�ӻ���ʼ��������
-------------------------------------------------------*/
void iic_slave_init(void){
    u8 res=63;
    res=(u8)(((ecbm_sys_clk/2/ECBM_IIC_WAIT)-4)/2)&0x3F;
    IIC_SET_MODE_SLAVE;//����Ϊ�ӻ�
    IIC_SET_SPEED(res); //�ȴ�ʱ��
    IIC_SET_REG_MSST(0);//������б�־λ
    iic_set_pin(ECBM_IIC_IO);
    iic_index=ECBM_IIC_IO;
    IIC_POWER_ON;
}
/*-------------------------------------------------------
��������iic_isr
��  ����IIC�жϺ���������IIC��Ҫ�����жϣ����Ծ�д�ڿ��У������������������ж����������¡�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣��ޣ�������á�
�������ڣ�2019-8-23
�޸ļ�¼��
-------------------------------------------------------*/
void iic_isr()IIC_IT_NUM{
    if(IIC_GET_IT_FLAG){
       IIC_IT_CLS;//���жϱ�־
        iic_busy=0;
    }
}
/*-------------------------------------------------------
IIC�ĸ��ֲ��������������������Э�����Ų���
iic_start     :��ʼ��������ӦIIC��ʼ֡��
iic_stop      :ֹͣ��������ӦIICֹͣ֡��
iic_write     :д���ݺ�������������д1�ֽ����ݡ�
iic_write_ack :дACK��������������дһ��ACK��
iic_write_nack:дNO ACK��������������дһ��NO ACK��
iic_read      :�����ݺ�������ȡ������һ���ֽڵ����ݡ�
iic_read_ack  :��ACK��������ȡ�������Ƿ���ACK��
-------------------------------------------------------*/
void iic_start(){
    u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    IIC_CMD_START;//����START����
    while(iic_busy&&(timeout--));
}
void iic_stop(){
    u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy = 1;
    IIC_CMD_STOP;//����STOP����
    while(iic_busy&&(timeout--));
}
void iic_write(u8 dat){
    u8 timeout=ECBM_IIC_TIMEOUT;
    IIC_SET_REG_DATA(dat);//д���ݵ����ݻ�����
    iic_busy=1;
    IIC_CMD_TX_DATA;//����SEND����
    while(iic_busy&&(timeout--));
}
void iic_write_ack(){
    u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    IIC_CMD_TX_ACK; //����ACK����
    while(iic_busy&&(timeout--));
}
void iic_write_nack(){
    u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    IIC_CMD_TX_NACK; //����ACK����
    while(iic_busy&&(timeout--));
}
u8 iic_read(){
    u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    IIC_CMD_RX_DATA;  //����RECV����
    while(iic_busy&&(timeout--));
    return IIC_GET_REG_DATA;
}
bit iic_read_ack(){
    u8 timeout=ECBM_IIC_TIMEOUT;
    iic_busy=1;
    IIC_CMD_RX_ACK; //���Ͷ�ACK����
    while(iic_busy&&(timeout--));
    return IIC_GET_ACK>>1;
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��