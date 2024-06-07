#ifndef __TM4C123GH6PM_H__
#define __TM4C123GH6PM_H__

typedef enum {
    GPIOF_OFFSET = 0x40025000
} TM4C_GPIO_OFFSETS;

typedef enum {
    GPIO_PUR_OFFSET = 0x510
} TM4C_REGISTER_OFFSETS;

typedef enum {
    RCGCGPIO_R = 0x400FE604,
    GPIOF_PUR_R =  0x40025510,
    GPIOF_DEN_R = 0x4002551C,
    GPIOF_DIR_R = 0x40025400,
    GPIOF_DATA_R = 0x40025000
} TM4C_REGISTERS;

typedef enum {
    RCGCGPIO_PORTF = (1 << 5),
    SW1_PIN = (1 << 4)
} TM4C_BITS;

typedef enum {
    PIN1 = (1 << 1) 
} PINS;

#endif // __TM4C123GH6PM_H__
