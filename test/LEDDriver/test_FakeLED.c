#include "unity.h"
#include "FakeLED.h"

void testFakeLEDOff(void) {
    FakeLED_Create();
    FakeLED_Off();

    TEST_ASSERT_EQUAL_INT(LED_OFF, LED_GetState());

    FakeLED_Destroy();
}

void testFakeLEDOn(void) {
    FakeLED_Create();
    FakeLED_On();

    TEST_ASSERT_EQUAL_INT(LED_ON, LED_GetState());
    FakeLED_Destroy();
}