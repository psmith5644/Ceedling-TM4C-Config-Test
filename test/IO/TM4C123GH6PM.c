#include "TM4C123GH6PM.h"
#include <stdlib.h>

// Initializes simulated registers for testing
void TM4C_init(void) {
    SYSCTL = (SYSCTL_Type*)malloc(sizeof(SYSCTL_Type));
    SYSCTL_Type sysctlstruct = {.RCGCGPIO = 0x4000EFF0};
    SYSCTL = &sysctlstruct;

    GPIOF = (GPIOA_Type *)malloc(sizeof(GPIOA_Type));
    GPIOA_Type gpiofstruct = 
    {
        .DIR = GPIOF_BASE+1,
        .DEN = GPIOF_BASE+2,
        .PUR = GPIOF_BASE+3,
        .DATA = GPIOF_BASE+4
    };
    GPIOF = &gpiofstruct;
}


