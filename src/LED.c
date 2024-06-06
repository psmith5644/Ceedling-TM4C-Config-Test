#include "LED.h"

static LED_STATE LEDState;

void LED_Create(void) {

}

void LED_Destroy(void) {
    
}

LED_STATE LED_GetState(void) {
    return LEDState;
}

void LED_On() {
    LEDState = LED_ON;
}

void LED_Off() {
    LEDState = LED_OFF;
}