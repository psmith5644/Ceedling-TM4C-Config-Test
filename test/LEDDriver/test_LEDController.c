#include "unity.h"
#include "LEDController.h"
#include "FakeSW1.h"
#include "FakeLED.h"

void testLEDOffWhenSwitchOpen(void) {
    LEDController_Create();
    SW1_Create();
    LED_Create();
    
    FakeSW1_Open();
    LED_Controller_UpdateLED();
    
    TEST_ASSERT_EQUAL_INT32(LED_OFF, LED_GetState());
    
    LEDController_Destroy();
    SW1_Destroy();
    LED_Destroy();
}

// void testLEDOnWhenSwitchClosed(void) {
//     LEDController_Create();
//     FakeSW1_Create();
//     FakeSW1_Close();    
//     LED_Controller_UpdateLED();
//     TEST_ASSERT_EQUAL_INT32(LED_ON, LED_GetState());
//     LEDController_Destroy();
//     FakeSW1_Destroy();
// }