#include "LED.h"
/************************************************************
Function Name: LED_IO_Init
Inputs: none
Outputs: none
Description:    ��ʼ��LED��IO��
Writer: WH
*************************************************************/
void LED_IO_Init(void)
{
    MCUCSR = 0x80;
    MCUCSR = 0x80;       //ȡ������
    DDRC = 0xff;         //C�˿����-
    PORTC = 0xff;        //LED�������ߵ�ƽȫ��
}

/************************************************************
Function Name: Led_All_On
Inputs: none
Outputs: none
Description:    8λLED��ȫ������ʱ��Ϩ��
Writer: WZY
*************************************************************/
void LED_All_On(void)
{
    LED_IO_Init();
    PORTC = 0x00;       ///LED�����ӷ����������Ϊ�͵�ƽ
    Delay_ms(1000);
    PORTC = 0xFF;
}

/************************************************************
Function Name:  Flow_LED_Test
Inputs: none
Outputs: none
Description:    LED��ˮ���Գ���
Writer: MaxMarth
*************************************************************/
void Flow_LED_Test(void)
{
    int i;
    LED_IO_Init();
    while(1)
   {
       for (i=0; i<8; i++)
       {
           PORTC &= ~(1 << i);//˳������
           Delay_ms(100);
       }
       for (i=0; i<8; i++)
       {
           PORTC |= (1<<i);
           Delay_ms(100);
       }
   }
}

/************************************************************
Function Name:  LED_Change
Inputs: none
Outputs: none
Description:    ʵ��LED0246��1357������˸
Writer: WZY
*************************************************************/
void LED_Change(void)
{
    LED_IO_Init();
    while (1)
    {
        PORTC = ((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7));   ///ż��λLED����
        Delay_ms(600);
        PORTC = ((1 << 0) | (1 << 2) | (1 << 4) | (1 << 6));   ///����λLED����
        Delay_ms(600);
        PORTC = 0xFF;
    }
}

/************************************************************
Function Name:  Breathe_LED
Inputs:   PC4
Outputs:  PB3
Description:   ����PWMģʽ�ı�P��ռ�ձȵ���LED����
Writer: MaxMarth
*************************************************************/
void Breathe_LED(void)
{
   int j = 0;
   MCUCSR = 0x80;
   MCUCSR = 0x80;
   DDRC &= ~(1 << 4);   //ѡ��4�ŵ�
   DDRB |= (1 << 3);    //PB3�˿����
   TCCR0 &= ~(1 << FOC0);
   TCCR0 |= ((1 << WGM00) | (1 << WGM01));//����PWM
   TCCR0 |= ((1 << COM01) | (1 << COM00));
   //�Ƚ�ƥ�䷢��OC0A��λ��������TOPʱOC0����
   TCCR0 &= ~((1 << CS02) | (1 << CS01));
   TCCR0 |= (1 << CS00);//�޷�Ƶ
   OCR0 = 0;
   TIMSK |= (1 << OCIE0);

   while(1)
  {

    Delay_ms(100);
    if(j==0)
    {
      OCR0 += 5;
    }

    if(OCR0>240)
    {
      j = 1;
    }
    if(j==1)
    {
      OCR0 = OCR0-5;
    }
    if(OCR0 < 10)
    {
        j = 0;
    }

//     OCR0  =249;
//     TIMSK|=(1<<OCIE0);
//     OCR0  =149;
//     TIMSK|=(1<<OCIE0);
   }
}
