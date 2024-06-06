#include "unity.h"
#include "FakeSW1.h"

void testFakeSW1Open(void) {
    FakeSW1_Create();
    FakeSW1_Open();
    TEST_ASSERT_EQUAL_INT32(SW1_OPEN, SW1_GetState());

    FakeSW1_Destroy();
}