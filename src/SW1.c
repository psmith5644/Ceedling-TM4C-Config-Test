#include "SW1.h"
#include "LED.h"
#include "IO.h"
#include "TM4C123GH6PM.h"

void SW1_Create(void) {
    IO_SetBits(&SYSCTL->RCGCGPIO, (1 << 5));
    for (int i = 0; i < 3; i++) {} // delay
    IO_SetBits(&GPIOF->PUR, SW1_PIN);
    IO_SetBits(&GPIOF->DEN, SW1_PIN);
    IO_ClearBits(&GPIOF->DIR, (ioData)~SW1_PIN);
}

void SW1_Destroy(void) {

}

SW1_STATE SW1_GetState(void) {
    return IO_Read(&GPIOF->DATA) & SW1_PIN;
}
