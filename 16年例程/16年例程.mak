CFLAGS =  -e -D__ICC_VERSION=80502 -D__BUILD=74 -DATMega16  -l -A -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -nb:74 -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:20 -beeprom:0.512 -fihx_coff -S2
FILES = 74HC595.o ADC.o Delay.o IO_Tube.o Interrupt.o Key.o LED.o PWM.o Timer.o usart.o main.o 

default:	$(FILES)
	$(CC) -o default $(LFLAGS) @..\16年例程 - 副本\16年例�