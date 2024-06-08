#include "LED.h"
#include "IO.h"

void LED_Create(void) {
    IO_Write(RCGCGPIO_R, RCGCGPIO_PORTF);
    for (int i = 0; i < 3; i++) {} // delay
    IO_Write(GPIOF_DEN_R, LED_PIN);
    IO_Write(GPIOF_DIR_R, LED_PIN);
}

void LED_Destroy(void) {

}

int LED_GetState(void) {
    return IO_Read(GPIOF_DATA_R) & LED_PIN;
}

void LED_On(void) {
    IO_Write(GPIOF_DATA_R, LED_PIN);
}

void LED_Off(void) {
    IO_Write(GPIOF_DATA_R, (ioData)~LED_PIN);
}
