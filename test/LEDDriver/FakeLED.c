#include "FakeLED.h"

static LED_STATES LEDState;

void FakeLED_Create(void) {

}


void FakeLED_Destroy(void) {

}

void FakeLED_Off(void) {
    LEDState = LED_OFF;
}

void FakeLED_On(void) {
    LEDState = LED_ON;
}


int LED_GetState(void) {
    return LEDState;
}
