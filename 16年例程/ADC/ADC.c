#include "ADC.h"
/************************************************************
Function Name:  ADC_Init
Inputs: none
Outputs: none
Description:    ģ��ת���Ĵ�����ʼ��
Writer: MaxMarth
*************************************************************/
void ADC_Init(void)
{
    DDRA   &= ~(1<<0) ;        //PA0����
    ADMUX  &= ~(1<<REFS1);
    ADMUX  |= 1<<REFS0;      //�ο���0ѹѡ��AVCC
    ADMUX  &= ~(1<<ADLAR);   //ת����������
    ADMUX  &= ~( (1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3) | (1<<MUX4) ); //ѡ��ͨ��ADC0
    ADCSRA |= 1<<ADEN;       //ADCʹ��
    ADCSRA |= 1<<ADATE;      //ADC�Զ�����ʹ��
    ADCSRA &= ~(1<<ADPS2);
    ADCSRA |= ( (1<<ADPS0) | (1<<ADPS1) );  //�˷�Ƶ
    SFIOR  &= ~( (1<<ADTS0) | (1<<ADTS1) | (1<<ADTS2) ); //����ת��ģʽ
    SFIOR  &= ~(1<<4);       //Bit4Ϊ����λ
    ADCSRA |= (1<<ADSC);     //ADC��ʼת��
}

/************************************************************
Function Name:  Display_ADC
Inputs: int a,int b
Outputs: none
Description:    ��ADC��ֵ�����������ʾ����
Writer: WH,WZY,MaxMarth
*************************************************************/
void Display_ADC(int a , int b)
{
    int m ,n , i ;
    unsigned long c=0 ;
        if (ADCSRA & ( 1<< 4 ))                 ///ADC�жϱ�־���ж�ADCת���Ƿ���������������λΪ1��
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
