#include "LED.h"
#include "IO.h"

#define RCGCGPIO_PORTF_ENABLE (1 << 5)

void LED_Create(void) {
    IO_SetBits(SYSCTL->RCGCGPIO, RCGCGPIO_PORTF_ENABLE);
    for (int i = 0; i < 3; i++) {} // delay
    IO_SetBits(GPIOF->DEN, LED_PIN);
    IO_SetBits(GPIOF->DIR, LED_PIN);
}

void LED_Destroy(void) {

}

int LED_GetState(void) {
    return IO_Read(GPIOF->DATA) & LED_PIN;
}

void LED_On(void) {
    IO_SetBits(GPIOF->DATA, LED_PIN);
}

void LED_Off(void) {
    IO_ClearBits(GPIOF->DATA, (ioData)~LED_PIN);
}
