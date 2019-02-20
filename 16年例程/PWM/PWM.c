#include "PWM.h"
/************************************************************
Function Name: Fast_PWM
Inputs: int Percent
Outputs: none
Description:    快速PWM模式，占空比可调
Writer: WZY, MaxMarth
*************************************************************/
void Fast_PWM(int Percent)
{
    DDRB  |= (1 << 3); //PB3输出
    TCCR0 |= ((1 << WGM00) | (1 << WGM01)); //快速PWM
    TCCR0 &= ~(1 << FOC0); //兼容性
    TCCR0 |= (1 << COM01);
    TCCR0 &= ~(1<<COM00); //比较匹配清零
    TCCR0 |= (1 << CS00);
    TCCR0 &= ~((1 << CS01) | (1 << CS02)); //无预分频
    TCNT0  = 0x00;
    OCR0   = Percent*255/100;

}
