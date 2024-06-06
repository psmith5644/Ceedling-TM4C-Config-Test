#include "FakeLED.h"

static LED_STATES LEDState;

void FakeLED_Create(void) {

}


void FakeLED_Destroy(void) {

}

void LED_Off(void) {
    LEDState = LED_OFF;
}

void LED_On(void) {
    LEDState = LED_ON;
}


int LED_GetState(void) {
    return LEDState;
}
