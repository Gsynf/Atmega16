#include "Interrupt.h"

int turn_flag = 1;
/************************************************************
Function Name: Interrupt_Init
Inputs: none
Outputs: none
Description:    ��ʼ���ⲿ�ж�INT0
Writer: XZ��WZY
*************************************************************/
void Interrupt_Init(void)
{
   // CLI();                        ///�ر�ȫ���жϣ�����������ʱ�ܵ���������
    //����0λ��0����1λ��1����ѡ�����½��ش����ж�INT0
    MCUCR &= ~(1 << ISC00);      ///���Ĵ���MCUCR�ĵ�0λ��0
    MCUCR |=  (1 << ISC01);      ///���Ĵ���MCUCR�ĵ�1λ��1
    GICR  |= (1 << INT0);         ///����6λINT0��1��ʹ��INT0
    //����2λ��0����3λ��1����ѡ���������ش����ж�INT1
    MCUCR &= ~(1 << ISC10);      ///���Ĵ���MCUCR�ĵ�2λ��0
    MCUCR |=  (1 << ISC11);      ///���Ĵ���MCUCR�ĵ�3λ��1
    GICR  |= (1 << INT1);         ///����7λINT1��1��ʹ��INT1
   // SEI();                        ///��ȫ���жϣ������жϵ��ܿ���
}

#pragma interrupt_handler Int0_isr:iv_INT0
void Int0_isr(void)
{
   turn_flag = -1; //LED_All_On();
}

#pragma interrupt_handler Int1_isr:iv_INT1
void Int1_isr(void)
{
   turn_flag = 1; //Flow_LED_Test();  //�ⲿ�жϲ��ܷ���ѭ��
}
