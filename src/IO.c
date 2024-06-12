#include "IO.h"

void IO_Create(void) {

}

void IO_Destroy(void) {

}

ioData IO_Read(ioAddress offset) {
    uint32_t * ptr = (uint32_t *)offset;
    return (ioData)*ptr;
}

void IO_Write(ioAddress offset, ioData data) {
    uint32_t * ptr = (uint32_t *)offset;
    *ptr = data;
}

void IO_SetBits(ioAddress offset, ioData data) {
    uint32_t * ptr = (uint32_t *)offset;
    *ptr |= data;
}

void IO_ClearBits(ioAddress offset, ioData data) {
    uint32_t * ptr = (uint32_t *)offset;
    *ptr &= data;
}

// ioData IO_Read(ioAddress offset) {
//     volatile uint32_t * addr = (volatile uint32_t *)offset;
//     return (ioData)*addr;
// }

// void IO_Write(ioAddress offset, ioData data) {
//     volatile uint32_t * addr = (volatile uint32_t *)offset;
//     *addr = data;
// }

// void IO_SetBits(ioAddress offset, ioData data) {
//     volatile uint32_t * addr = (volatile uint32_t *)offset;
//     *addr |= data;
// }

// void IO_ClearBits(ioAddress offset, ioData data) {
//     volatile uint32_t * addr = (volatile uint32_t *)offset;
//     *addr &= data;
// }
