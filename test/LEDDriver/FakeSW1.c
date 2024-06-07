#include "FakeSW1.h"

static SW1_STATE SW1State;

void SW1_Create(void) {
}

void SW1_Destroy(void) {

}

void FakeSW1_Open(void) {
    SW1State = SW1_OPEN;
}

void FakeSW1_Close(void) {
    SW1State = SW1_CLOSED;
}


SW1_STATE SW1_GetState(void) {
    return SW1State;
}