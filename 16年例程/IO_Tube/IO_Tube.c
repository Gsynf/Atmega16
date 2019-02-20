#include "IO_Tube.h"
int tube[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};  ///���������0~9

/************************************************************
Function Name: Tube_Init
Inputs: none
Outputs: 0
Description:    ����ܳ�ʼ����P3��a~p��PD0~7���������ƶ�ѡ��P4��0~7��PB��0~7����������λѡ
Writer: WZY,MaxMarth
*************************************************************/
void Tube_Init(void)
{
    DDRB  = 0xFF;
    DDRD  = 0xFF;  //�Ĵ�������Ϊ���
    PORTB = 0xFF;  //����ܹ���������ߵ�ƽ������ͨ
}
/************************************************************
Function Name: Tube_On
Inputs: int t
Outputs: none
Description:    8λ�������ʾͬһ������0~9֮��ĸ���intֵt
Writer: WZY,MaxMarth
*************************************************************/
void Tube_On(int t)
{
    Tube_Init();
    PORTB = 0x00;   ///������ƽ����
    PORTD = tube[t];    ///�����ߵ�ƽʱ��ͨ
    Delay_ms(1000);
}
/************************************************************
Function Name: Tube_Loop
Inputs: int c
Outputs: none
Description:    8λ����ܴ�������ѭ����ʾ0~7,ѭ��c��
Writer: WZY,MaxMarth
*************************************************************/
void Tube_Loop(int c)
{
    int i, j;
    Tube_Init();
    for(i=0; i<c; i++)  ///����ѭ������
    {
        for(j=0; j<8; j++)
        {
            PORTB = ~(1<<j);   ///��λ��ͨ������
            PORTD = tube[j];
            Delay_ms(300);
        }
    }
    PORTB = 0xff;
}
