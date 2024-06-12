#include "LED.h"
#include "IO.h"

#define RCGCGPIO_PORTF_ENABLE (1 << 5)

void LED_Create(void) {
    IO_SetBits(RCGCGPIO_R, RCGCGPIO_PORTF);
    for (int i = 0; i < 3; i++) {} // delay
    IO_SetBits(GPIOF_DEN_R, LED_PIN);
    IO_SetBits(GPIOF_DIR_R, LED_PIN);
}

void LED_Destroy(void) {

}

int LED_GetState(void) {
    return IO_Read(GPIOF_DATABITS_R) & LED_PIN;
}

void LED_On(void) {
    IO_SetBits(GPIOF_DATABITS_R, LED_PIN);
}

void LED_Off(void) {
    IO_ClearBits(GPIOF_DATABITS_R, (ioData)~LED_PIN);
}
