#ifndef __LED_H__
#define __LED_H__

#include "TM4C123GH6PM.h"

typedef enum {
    LED_PIN = PIN1
} LED_PINS;

typedef enum {
    LED_OFF = 0, LED_ON = LED_PIN
} LED_STATES;

void LED_Create(void);
void LED_Destroy(void);
int LED_GetState(void);
void LED_On(void);

#endif // __LED_H__