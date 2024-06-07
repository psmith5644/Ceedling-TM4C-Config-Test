#include "LEDController.h"
#include "SW1.h"
#include "LED.h"

void LEDController_Create(void) {

}

void LEDController_Destroy(void) {
    
}

void LED_Controller_UpdateLED(void) {
    switch(SW1_GetState()) {
        case SW1_OPEN:
            LED_Off();
            break;
        case SW1_CLOSED:
            LED_On();
            break;
        default:
            break;
    }
}