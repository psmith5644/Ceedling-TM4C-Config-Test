#ifndef __SW1_H__
#define __SW1_H__

#include <stdint.h>

void SW1_Create(void);
void SW1_Destroy(void);
int SW1_GetState(void);

#endif // __SW1_H__