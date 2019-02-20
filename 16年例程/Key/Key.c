#include "Key.h"
/************************************************************
Function Name:  Key_Init
Inputs: none
Outputs: none
Description:    按键端口初始化
Writer: WZY
*************************************************************/
void Key_Init(void)
{
    DDRD &= ~((1 << 2) | ( 1 << 3));     ///将D端口2、3置为输入
}

/************************************************************
Function Name:  LED_Switch_0_7
Inputs: none
Outputs: 0
Description:    按键控制LED灯,K1控制LED0，K2控制LED7
Writer: WH,MaxMarth
*************************************************************/
//int LED_Switch_0_7(void)
//{
//    LED_IO_Init();
//    Key_Init();
//    while (1)
//    {
//        if (~PIND & ( 1 << 2))               ///判断按键K1是否触发。
//        {
//            PORTC &= ~(1 << 0);           ///按键K1按下，LED0亮起。
//            Delay_ms(500);              ///延迟
//            PORTC = 0xff;               ///LED0熄灭
//        }
//        if (~PIND&(1 << 3))
//        {
//            PORTC &= ~(1 << 7);
//            Delay_ms(500);
//            PORTC = 0xff;
//        }
//    }
//    return 0;
//}

/************************************************************
Function Name:  LED_Move
Inputs: none
Outputs: none
Description:    初始时LEDi亮，按下K1向左移动，按下K2向右移动
Writer: WZY,MaxMarth
*************************************************************/
void LED_Move(void)
{
    int i = 5;
    Key_Init();
    LED_IO_Init();
    PORTC = ~( 1<< i);
    while(1)
	{
        if (~PIND & ( 1<< 2))   ///PD2置零
        {
            i = i-1;
            if (i < 0)
                i = 7;
                PORTC = ~( 1<< i);
                Delay_ms(300);
        }
        if(~PIND & ( 1<< 3))   ///PD3置零
        {
            i = i+1;
            if (i > 7)
                i = 0;
                PORTC = ~( 1<< i);
                Delay_ms(300);
        }
	}
}

/************************************************************
Function Name:  Key_Flow_Tube
Inputs: none
Outputs: 0
Description:    按键控制数字流水
Writer: WH，WZY,MaxMarth
*************************************************************/
int  Key_Flow_Tube(void)
{
    int m = 0, n = 0;
    Key_Init();                             ///将PD2，PD3置为低电平
    HC595_Init();
    while(1)
        {
            if ((PIND & ( 1<< 2))==0 )                         ///判断按键K1是否触发
            {
                for (m=0; m<8; m++)                       ///按下K2，从左至右显示0~7
                {
                    Display_74HC595(m,m);
                    Delay_ms(250);
                }
            }
            if ((PIND & (1 << 3))==0 )
            {
                for (n=7; n>-1; n--)                      ///按下K3，从右至左显示7~0
                {
                    Display_74HC595(n,n);
                    Delay_ms(250);
                }
            }
        }
   return 0;
}
