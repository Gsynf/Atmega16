#include "ADC.h"
/************************************************************
Function Name:  ADC_Init
Inputs: none
Outputs: none
Description:    模数转换寄存器初始化
Writer: MaxMarth
*************************************************************/
void ADC_Init(void)
{
    DDRA   &= ~(1<<0) ;        //PA0输入
    ADMUX  &= ~(1<<REFS1);
    ADMUX  |= 1<<REFS0;      //参考电0压选择AVCC
    ADMUX  &= ~(1<<ADLAR);   //转换结果左对齐
    ADMUX  &= ~( (1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3) | (1<<MUX4) ); //选择通道ADC0
    ADCSRA |= 1<<ADEN;       //ADC使能
    ADCSRA |= 1<<ADATE;      //ADC自动触发使能
    ADCSRA &= ~(1<<ADPS2);
    ADCSRA |= ( (1<<ADPS0) | (1<<ADPS1) );  //八分频
    SFIOR  &= ~( (1<<ADTS0) | (1<<ADTS1) | (1<<ADTS2) ); //连续转换模式
    SFIOR  &= ~(1<<4);       //Bit4为保留位
    ADCSRA |= (1<<ADSC);     //ADC开始转换
}

/************************************************************
Function Name:  Display_ADC
Inputs: int a,int b
Outputs: none
Description:    将ADC的值在数码管上显示出来
Writer: WH,WZY,MaxMarth
*************************************************************/
void Display_ADC(int a , int b)
{
    int m ,n , i ;
    unsigned long c=0 ;
        if (ADCSRA & ( 1<< 4 ))                 ///ADC中断标志，判断ADC转换是否结束，结束则第四位为1。
        {
            n = b;
            c = ADC ;
        for (i=a; i<=b; i++)
            {
                m = c%10 ;
                Display_74HC595(n, m);
                n--;
                c= c/10;
            }
        }

}
