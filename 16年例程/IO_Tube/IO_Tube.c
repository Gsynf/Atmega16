#include "IO_Tube.h"
int tube[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};  ///数码管数字0~9

/************************************************************
Function Name: Tube_Init
Inputs: none
Outputs: 0
Description:    数码管初始化，P3的a~p接PD0~7，阳极控制段选；P4的0~7接PB的0~7，阴极控制位选
Writer: WZY,MaxMarth
*************************************************************/
void Tube_Init(void)
{
    DDRB  = 0xFF;
    DDRD  = 0xFF;  //寄存器设置为输出
    PORTB = 0xFF;  //数码管共阴，输出高电平，不导通
}
/************************************************************
Function Name: Tube_On
Inputs: int t
Outputs: none
Description:    8位数码管显示同一个数字0~9之间的给定int值t
Writer: WZY,MaxMarth
*************************************************************/
void Tube_On(int t)
{
    Tube_Init();
    PORTB = 0x00;   ///阴极电平拉低
    PORTD = tube[t];    ///阳极高电平时导通
    Delay_ms(1000);
}
/************************************************************
Function Name: Tube_Loop
Inputs: int c
Outputs: none
Description:    8位数码管从左至右循环显示0~7,循环c次
Writer: WZY,MaxMarth
*************************************************************/
void Tube_Loop(int c)
{
    int i, j;
    Tube_Init();
    for(i=0; i<c; i++)  ///控制循环次数
    {
        for(j=0; j<8; j++)
        {
            PORTB = ~(1<<j);   ///移位导通二极管
            PORTD = tube[j];
            Delay_ms(300);
        }
    }
    PORTB = 0xff;
}
