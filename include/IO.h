#ifndef __IO_H__
#define __IO_H__

#include <stdint.h>

typedef uint32_t ioAddress;
typedef uint16_t ioData;
ioData IO_Read(ioAddress offset);
void IO_Write(ioAddress offset, ioData data);

#endif // __IO_H__
