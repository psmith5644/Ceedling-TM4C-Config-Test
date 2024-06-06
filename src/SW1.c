#include "SW1.h"
#include "LED.h"
#include "IO.h"
#include "TM4C123GH6PM.h"
// #include "MockIO.h"

void SW1_Create(void) {
    IO_Write(RCGCGPIO_R, RCGCGPIO_PORTF);
    IO_Write(GPIOF_PUR_R, SW1_PIN);
    IO_Write(GPIOF_DEN_R, SW1_PIN);
    IO_Write(GPIOF_DIR_R, ~SW1_PIN);
}

void SW1_Destroy(void) {

}

void SW1_On(void) {
    LED_On();
}

void SW1_Off(void) {
    LED_Off();
}