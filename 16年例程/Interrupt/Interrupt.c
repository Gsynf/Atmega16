#include "Interrupt.h"

int turn_flag = 1;
/************************************************************
Function Name: Interrupt_Init
Inputs: none
Outputs: none
Description:    初始化外部中断INT0
Writer: XZ，WZY
*************************************************************/
void Interrupt_Init(void)
{
   // CLI();                        ///关闭全局中断，避免在设置时受到其他干扰
    //将第0位置0，第1位置1，即选择了下降沿触发中断INT0
    MCUCR &= ~(1 << ISC00);      ///将寄存器MCUCR的第0位置0
    MCUCR |=  (1 << ISC01);      ///将寄存器MCUCR的第1位置1
    GICR  |= (1 << INT0);         ///将第6位INT0置1，使能INT0
    //将第2位置0，第3位置1，即选择了下升沿触发中断INT1
    MCUCR &= ~(1 << ISC10);      ///将寄存器MCUCR的第2位置0
    MCUCR |=  (1 << ISC11);      ///将寄存器MCUCR的第3位置1
    GICR  |= (1 << INT1);         ///将第7位INT1置1，使能INT1
   // SEI();                        ///打开全局中断，就是中断的总开关
}

#pragma interrupt_handler Int0_isr:iv_INT0
void Int0_isr(void)
{
   turn_flag = -1; //LED_All_On();
}

#pragma interrupt_handler Int1_isr:iv_INT1
void Int1_isr(void)
{
   turn_flag = 1; //Flow_LED_Test();  //外部中断不能放死循环
}
