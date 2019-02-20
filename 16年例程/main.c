#include "./Headers/Global.h"  //包含所有头文件

void main(void)
{

    CLI();
    MCUCSR = 0x80;
    MCUCSR = 0x80;       //取消复用
    DDRC = 0xff;         //C端口输出-
    PORTC = 0xff;        //LED共阳，高电平全灭
    //LED_IO_Init();
    ADC_Init();
    Interrupt_Init();
    //Timer0_Init();
    HC595_Init();
    USART_Init(12);

    HC595_Display_Bit(0,1,0);
    Delay_ms(100);
    HC595_Display_Bit(1,2,0);
    Delay_ms(100);
    HC595_Display_Bit(2,3,0);
    Delay_ms(100);
    HC595_Display_Bit(3,4,0);
    Delay_ms(100);
    HC595_Display_Bit(4,5,0);
    Delay_ms(100);
    HC595_Display_Bit(5,6,0);
    Delay_ms(100);
    HC595_Display_Bit(6,7,0);
    Delay_ms(100);
    HC595_Display_Bit(7,8,0);
    Delay_ms(100);
//    while(1)
//    {
//        ;
//    }
//    HC595_Display_Bit(7,17,0);
//
//    SEI();

    while(1)
    {
        start();
        //Display_ADC(4,7);
    }


}

void start(void)
{
    UINT8 mode=0;
    while(1)
    {
        if(receive_flag == 1)
        {
            if(buf[0] == 'A' && buf[1] == 'D')
                mode = 1;
            else if(buf[0] == 'S' && buf[1] == 'P')
                mode = 2;
            else if(buf[0] == 'W' && buf[1] == 'A')
                mode = 3;
            else
                mode = 50;

            switch(mode)
            {
            case 1 :
                {
                    Display_ADC(4,7);
                    break;
                }
            case 2 :
                {
                    CLI();
                    InitTimer0();
                    receive_flag =0;
                    SEI();
                    MaiBaoGe();
                    break;
                }
            case 3 :
                {
                    CLI();
                    Timer0_Init();
                    receive_flag =0;
                    SEI();
                    break;
                }
            case 50 :
                {
                    USART_send("your char are   :");
                    USART_send(buf);
                    receive_flag =0;

                    break;
                }

            default :
                {
                    break;
                }
            }
        }
    }
}

