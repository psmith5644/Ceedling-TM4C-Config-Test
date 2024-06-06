#ifndef __LED_H__
#define __LED_H__

#include "TM4C123GH6PM.h"

typedef enum {
    LED_PIN = PIN1
} LED_PINS;

void LED_Create(void);
void LED_Destroy(void);

#endif // __LED_H__