#include "LED.h"
#include "IO.h"

void LED_Create(void) {
    IO_Write(RCGCGPIO_R, RCGCGPIO_PORTF);
    IO_Write(GPIOF_DEN_R, LED_PIN);
    IO_Write(GPIOF_DIR_R, LED_PIN);
}

void LED_Destroy(void) {

}

int LED_GetState(void) {
    int LEDState = IO_Read(GPIOF_DATA_R);
    return LEDState;
}