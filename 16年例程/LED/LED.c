#include "LED.h"
/************************************************************
Function Name: LED_IO_Init
Inputs: none
Outputs: none
Description:    初始化LED灯IO口
Writer: WH
*************************************************************/
void LED_IO_Init(void)
{
    MCUCSR = 0x80;
    MCUCSR = 0x80;       //取消复用
    DDRC = 0xff;         //C端口输出-
    PORTC = 0xff;        //LED共阳，高电平全灭
}

/************************************************************
Function Name: Led_All_On
Inputs: none
Outputs: none
Description:    8位LED灯全亮，延时后熄灭
Writer: WZY
*************************************************************/
void LED_All_On(void)
{
    LED_IO_Init();
    PORTC = 0x00;       ///LED共阳接法，设置输出为低电平
    Delay_ms(1000);
    PORTC = 0xFF;
}

/************************************************************
Function Name:  Flow_LED_Test
Inputs: none
Outputs: none
Description:    LED流水测试程序
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
           PORTC &= ~(1 << i);//顺次置零
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
Description:    实现LED0246，1357交替闪烁
Writer: WZY
*************************************************************/
void LED_Change(void)
{
    LED_IO_Init();
    while (1)
    {
        PORTC = ((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7));   ///偶数位LED灯亮
        Delay_ms(600);
        PORTC = ((1 << 0) | (1 << 2) | (1 << 4) | (1 << 6));   ///奇数位LED灯亮
        Delay_ms(600);
        PORTC = 0xFF;
    }
}

/************************************************************
Function Name:  Breathe_LED
Inputs:   PC4
Outputs:  PB3
Description:   快速PWM模式改变P波占空比调节LED亮度
Writer: MaxMarth
*************************************************************/
void Breathe_LED(void)
{
   int j = 0;
   MCUCSR = 0x80;
   MCUCSR = 0x80;
   DDRC &= ~(1 << 4);   //选用4号灯
   DDRB |= (1 << 3);    //PB3端口输出
   TCCR0 &= ~(1 << FOC0);
   TCCR0 |= ((1 << WGM00) | (1 << WGM01));//快速PWM
   TCCR0 |= ((1 << COM01) | (1 << COM00));
   //比较匹配发生OC0A置位，计数到TOP时OC0清零
   TCCR0 &= ~((1 << CS02) | (1 << CS01));
   TCCR0 |= (1 << CS00);//无分频
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
