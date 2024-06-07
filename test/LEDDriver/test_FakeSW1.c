#include "unity.h"
#include "FakeSW1.h"

void testFakeSW1Open(void) {
    SW1_Create();
    FakeSW1_Open();
    TEST_ASSERT_EQUAL_INT32(SW1_OPEN, SW1_GetState());

    SW1_Destroy();
}

void testFakeSW1Close(void) {
    SW1_Create();
    FakeSW1_Close();
    TEST_ASSERT_EQUAL_INT32(SW1_CLOSED, SW1_GetState());

    SW1_Destroy();
}