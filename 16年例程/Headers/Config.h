#ifndef _Config_H_
#define _Config_H_

typedef signed char SINT8;
typedef unsigned char UINT8;
typedef unsigned int UINT16;
typedef signed int SINT16;
typedef unsigned long UINT32;
typedef signed long SINT32;

/* Const Define */
#ifndef ON
#define ON                             (1)
#endif

#ifndef OFF
#define OFF                            (0)
#endif

#ifndef TRUE
#define TRUE                           (1)
#endif

#ifndef FALSE
#define FALSE                          (0)
#endif

#ifndef OK
#define OK                             (1)
#endif

#ifndef ERROR
#define ERROR                          (0)
#endif

/* Constants */
#define PI                             3.14159265359
/* MIN/MAX/ABS macros */
#define MIN(a, b)                      (((a) < (b))?(a):(b))
#define MAX(a, b)                      (((a) > (b))?(a):(b))
#define ABS(x)                         (((x) > 0)?(x):(-(x)))

/* Function Define */
#ifndef ClrBit
#define ClrBit(reg, bit)               reg &= ~(1 << bit)
#endif

#ifndef SetBit
#define SetBit(reg, bit)               reg |= (1 << bit)
#endif

#ifndef ReverseBit
#define ReverseBit(reg, bit)           reg ^= (1 << bit)
#endif

#ifndef BitIsSet
#define BitIsSet(reg, bit)             (reg & (1 << bit))
#endif

#endif
