#include "Key.h"
/************************************************************
Function Name:  Key_Init
Inputs: none
Outputs: none
Description:    �����˿ڳ�ʼ��
Writer: WZY
*************************************************************/
void Key_Init(void)
{
    DDRD &= ~((1 << 2) | ( 1 << 3));     ///��D�˿�2��3��Ϊ����
}

/************************************************************
Function Name:  LED_Switch_0_7
Inputs: none
Outputs: 0
Description:    ��������LED��,K1����LED0��K2����LED7
Writer: WH,MaxMarth
*************************************************************/
//int LED_Switch_0_7(void)
//{
//    LED_IO_Init();
//    Key_Init();
//    while (1)
//    {
//        if (~PIND & ( 1 << 2))               ///�жϰ���K1�Ƿ񴥷���
//        {
//            PORTC &= ~(1 << 0);           ///����K1���£�LED0����
//            Delay_ms(500);              ///�ӳ�
//            PORTC = 0xff;               ///LED0Ϩ��
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
Description:    ��ʼʱLEDi��������K1�����ƶ�������K2�����ƶ�
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
        if (~PIND & ( 1<< 2))   ///PD2����
        {
            i = i-1;
            if (i < 0)
                i = 7;
                PORTC = ~( 1<< i);
                Delay_ms(300);
        }
        if(~PIND & ( 1<< 3))   ///PD3����
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
Description:    ��������������ˮ
Writer: WH��WZY,MaxMarth
*************************************************************/
int  Key_Flow_Tube(void)
{
    int m = 0, n = 0;
    Key_Init();                             ///��PD2��PD3��Ϊ�͵�ƽ
    HC595_Init();
    while(1)
        {
            if ((PIND & ( 1<< 2))==0 )                         ///�жϰ���K1�Ƿ񴥷�
            {
                for (m=0; m<8; m++)                       ///����K2������������ʾ0~7
                {
                    Display_74HC595(m,m);
                    Delay_ms(250);
                }
            }
            if ((PIND & (1 << 3))==0 )
            {
                for (n=7; n>-1; n--)                      ///����K3������������ʾ7~0
                {
                    Display_74HC595(n,n);
                    Delay_ms(250);
                }
            }
        }
   return 0;
}
