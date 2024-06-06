#include "unity.h"
#include "LED.h"
#include "LEDController.h"
#include "FakeSW1.h"
#include "IO.h"

void testLEDOffWhenSwitchOpen(void) {
    LEDController_Create();
    FakeSW1_Create();
    FakeSW1_Open();

    LED_Controller_UpdateLED();
    TEST_ASSERT_EQUAL_INT32(LED_OFF, LED_GetState());
    LEDController_Destroy();
    FakeSW1_Destroy();
}