#include "Timer.h"
/************************************************************
Function Name:  Timer0_LED_Flow
Inputs: none
Outputs: 0
Description:    200ms流水灯
Writer: XZ,WZY,MaxMarth
*************************************************************/
int LED_Flag = 0;
#pragma interrupt_handler Timer0_Ovf_Isr:iv_TIM0_OVF
void Timer0_Ovf_Isr(void)   ///溢出中断
{
    TCNT0 = 0x3D;           ///reload counter value
    //TCNT0 = 0b00111110; 即 62
    if(turn_flag == 1)
        LED_Flag++;
    if(turn_flag == -1)
        LED_Flag--;

    if(LED_Flag < 0)
        LED_Flag = 7;
    if(LED_Flag > 7)
        LED_Flag = 0;
    PORTC = ~(1 << LED_Flag);
}
void Timer0_Init(void)
{
    TCCR0 = 0x00;           ///stop
    TCNT0 = 0x00;           ///set count
    OCR0  = 0xC3;           ///set compare
    TCCR0 = 0x05;           ///start timer
    //CLI();                  ///领导说不
    TIMSK = 0x01;           ///定时器中断小boss
    //SEI();                  ///领导同意
}
int Timer0_LED_Flow(void)
{
    //LED_IO_Init();
    //Timer0_Init();
    while(1)
        {
            PORTC = ~(1 << LED_Flag);      ///控制相应的灯
        }
    return 0;
}

//--------------------T I M E R 0---------------------------/
void InitTimer0(void)
{
    SetBit(TIMER0_DDR,TIMER0_OCR0);     //设置PB3为输出
    //配置TCCR0寄存器
    //波形产生              CTC模式
    SetBit(TCCR0,WGM01);
    ClrBit(TCCR0,WGM00);
    //比较匹配输出模式      比较匹配时OC0取反
    SetBit(TCCR0,COM00);
    ClrBit(TCCR0,COM01);
    //时钟选择              8分频
    ClrBit(TCCR0,CS02);
    SetBit(TCCR0,CS01);
    ClrBit(TCCR0,CS00);
}
//Timer0 CTC模式
//打开或关闭定时器

void OpenT0CTC(void)
{
    SetBit(TCCR0,COM00);
    ClrBit(TCCR0,COM01);
}
void CloseT0CTC(void)    //不与OC0连接
{
    ClrBit(TCCR0,COM00);
    ClrBit(TCCR0,COM01);
}

void MusicNote(int n)
{
    if(receive_flag == 1)
        start();
    if(0==n)
    {
        CloseT0CTC();
        Delay_ms(500);
    }
    else
    {
        OCR0 = NoteData[n];
        OpenT0CTC();
        Delay_ms(475);
        CloseT0CTC();
        Delay_ms(50);
        if(N<=10)
        {
            PORTC |= (1<<7);
            Delay_ms(150);
            PORTC &= ~(1<<7);
        }
        else
        {
             PORTC |= (1<<7)|(1<<6);
             Delay_ms(150);
             PORTC &=~((1<<7)|(1<<6));
        }

    }

}

void MusicNote2(int n)
{
    if(receive_flag == 1)
        start();
    if(0==n)
    {
        CloseT0CTC();
        Delay_ms(1000);
    }
    else
    {
        OCR0 = NoteData[n];
        OpenT0CTC();
        Delay_ms(950);
        CloseT0CTC();
        Delay_ms(50);
        if(n<=10)
        {
            PORTC |= (1<<7)|(1<<6)|(1<<5);
            Delay_ms(150);
            PORTC &= ~((1<<7)|(1<<6)|(1<<5));
        }
        else
        {
            PORTC |= (1<<7)|(1<<6)|(1<<5)|(1<<4);
            Delay_ms(150);
            PORTC &= ~((1<<7)|(1<<6)|(1<<5)|(1<<4));
        }

    }

}


void MusicNoteHalf(int n)
{
    if(receive_flag == 1)
        start();
    if(0==n)
    {
        CloseT0CTC();
        Delay_ms(250);
    }
    else
    {
        OCR0 = NoteData[n];
        OpenT0CTC();
        Delay_ms(225);
        CloseT0CTC();
        Delay_ms(25);
         if(n<=10)
        {
           PORTC |= (1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3);
            Delay_ms(150);
            PORTC &=~((1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3));
        }
        else
        {
            PORTC |= (1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2);
            Delay_ms(150);
            PORTC &= ~((1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2));
        }

    }

}
void MusicNoteHalfHalf(int n)
{
    if(receive_flag == 1)
        start();
    if(0==n)
    {
        CloseT0CTC();
        Delay_ms(125);
    }
    else
    {
        OCR0 = NoteData[n];
        OpenT0CTC();
        Delay_ms(100);
        CloseT0CTC();
        Delay_ms(25);
        if(n<=10)
        {
            PORTC |= (1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1);
            Delay_ms(150);
            PORTC &=~((1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1));
        }
        else
        {
            PORTC |= (1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);
            Delay_ms(150);
            PORTC &=~((1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0));
        }

    }

}

//歌曲1 卖报歌
void MaiBaoGe(void)
{
    SolH SolH  Sol SolH SolH Sol
    MiH  SolH  LaH SolHH MiHH ReH MiH Sol
    SolH MiH SolH MiHH ReHH DoH MiH Re
    MiH MiH Re _LaH DoH Re
    La LaH SolH MiH LaH Sol SolH MiH ReH MiH Sol _O
    SolH MiH ReH MiH SolH MiH ReH MiH
    _LaH DoH ReH MiH Do _O _O

}



//歌曲2 欢乐颂
 void HuanLeSong(void)
 {
     Mi Mi Fa Sol Sol Fa Mi Re
     Do Do Re Mi  Mi MiH ReH Re Re
     Mi Mi Fa Sol Sol Fa Mi Re
     Do Do Re Mi  Re ReH DoH Do Do
     Re Re Mi Do Re MiH FaH Mi Do
     Re MiH FaH Mi Re Do Re Sol_ Sol
     Mi Mi Fa Sol Sol Fa Mi Re
     Do Do Re Mi  Re ReH DoH Do Do
 }
















