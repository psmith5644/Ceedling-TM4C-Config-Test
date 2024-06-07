#include "unity.h"
#include "FakeLED.h"

void testFakeLEDOff(void) {
    LED_Create();
    LED_Off();

    TEST_ASSERT_EQUAL_INT(LED_OFF, LED_GetState());

    LED_Destroy();
}

void testFakeLEDOn(void) {
    LED_Create();
    LED_On();

    TEST_ASSERT_EQUAL_INT(LED_ON, LED_GetState());
    LED_Destroy();
}