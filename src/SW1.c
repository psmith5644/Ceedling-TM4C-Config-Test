#include "SW1.h"
#include "LED.h"
#include "IO.h"
#include "TM4C123GH6PM.h"

void SW1_Create(void) {
    IO_Write(RCGCGPIO_R, RCGCGPIO_PORTF);
    for (int i = 0; i < 3; i++) {} // delay
    IO_Write(GPIOF_PUR_R, SW1_PIN);
    IO_Write(GPIOF_DEN_R, SW1_PIN);
    IO_Write(GPIOF_DIR_R, (ioData)~SW1_PIN);
}

void SW1_Destroy(void) {

}

SW1_STATE SW1_GetState(void) {
    return IO_Read(GPIOF_DATA_R) & SW1_PIN;
}
