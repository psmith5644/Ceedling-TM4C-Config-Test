#include "IO.h"

void IO_Create(void) {

}

void IO_Destroy(void) {

}

ioData IO_Read(ioAddress offset) {
    return (ioData)*offset;
}

void IO_Write(ioAddress offset, ioData data) {
    *offset = data;
}

void IO_SetBits(ioAddress offset, ioData data) {
    *offset |= data;
}

void IO_ClearBits(ioAddress offset, ioData data) {
    *offset &= data;
}
