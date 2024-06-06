#ifndef __LED_H__
#define __LED_H__

typedef enum {
    LED_OFF = 0, LED_ON
} LED_STATE;

void LED_Create(void);
void LED_Destroy(void);
LED_STATE LED_GetState(void); 
void LED_On();
void LED_Off();

#endif // __LED_H__