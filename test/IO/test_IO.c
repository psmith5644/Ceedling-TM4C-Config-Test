#include "unity.h"
#include "IO.h"
#include <stdlib.h>

static int * offset;

void setup(void) {
    IO_Create();
}

void teardown(void) {
    free(offset);
    IO_Destroy();
}

void testIORead(void) {
    offset = malloc(sizeof(uint32_t));
    *offset = 0xDEADBEEF;

    TEST_ASSERT_EQUAL_INT32(0xDEADBEEF, IO_Read((ioAddress)offset));
}

void testIOWrite(void) {
    offset = malloc(sizeof(uint32_t));
    IO_Write((ioAddress)offset, 0xDEADBEEF);

    TEST_ASSERT_EQUAL_INT32(0xDEADBEEF, IO_Read((ioAddress)offset));
}

void testIOSetBitsZerosDoNotClear(void) {
    offset = malloc(sizeof(uint32_t));
    IO_Write((ioAddress)offset, 0xDEAD0000);
    IO_SetBits((ioAddress)offset, 0x0000BEEF);

    TEST_ASSERT_EQUAL_INT32(0xDEADBEEF, IO_Read((ioAddress)offset));
}
