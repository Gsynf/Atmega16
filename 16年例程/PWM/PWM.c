#include "PWM.h"
/************************************************************
Function Name: Fast_PWM
Inputs: int Percent
Outputs: none
Description:    ����PWMģʽ��ռ�ձȿɵ�
Writer: WZY, MaxMarth
*************************************************************/
void Fast_PWM(int Percent)
{
    DDRB  |= (1 << 3); //PB3���
    TCCR0 |= ((1 << WGM00) | (1 << WGM01)); //����PWM
    TCCR0 &= ~(1 << FOC0); //������
    TCCR0 |= (1 << COM01);
    TCCR0 &= ~(1<<COM00); //�Ƚ�ƥ������
    TCCR0 |= (1 << CS00);
    TCCR0 &= ~((1 << CS01) | (1 << CS02)); //��Ԥ��Ƶ
    TCNT0  = 0x00;
    OCR0   = Percent*255/100;

}
