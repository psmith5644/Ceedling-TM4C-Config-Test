#include "unity.h"
#include "IO.h"
#include <stdlib.h>

void testIORead(void) {
    IO_Create();

    int * offset = malloc(sizeof(uint32_t));
    *offset = 0xDEADBEEF;

    TEST_ASSERT_EQUAL_INT32(0xDEADBEEF, IO_Read((ioAddress)offset));

    IO_Destroy();
}

void testIOWrite(void) {
    IO_Create();

    int * offset = malloc(sizeof(uint32_t));
    IO_Write((ioAddress)offset, 0xDEADBEEF);

    TEST_ASSERT_EQUAL_INT32(0xDEADBEEF, IO_Read((ioAddress)offset));

    IO_Destroy();
}