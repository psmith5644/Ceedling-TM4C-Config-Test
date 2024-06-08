#include "LEDController.h"
#include "LED.h"
#include "SW1.h"

int main(void) {
    LED_Create();
    SW1_Create();
    LEDController_Create();
    while (1) {
        LEDController_UpdateLED();
        for (int i = 0; i < 1000000; i++) {}
    }
}
