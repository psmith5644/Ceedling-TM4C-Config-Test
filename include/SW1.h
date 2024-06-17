#ifndef __SW1_H__
#define __SW1_H__

#include <stdint.h>
#include "TM4C123GH6PM.h"

#define SW1_PIN (1 << 4)

typedef enum {
    SW1_CLOSED = 0, SW1_OPEN = (1 << 4)
} SW1_STATE;

void SW1_Create(void);
void SW1_Destroy(void);
SW1_STATE SW1_GetState(void);

#endif // __SW1_H__
