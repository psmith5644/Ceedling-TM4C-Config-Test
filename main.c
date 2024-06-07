#include "LEDController.h"

int main(void) {
    LEDController_Create();
    while (1) {
        LEDController_UpdateLED();
    }
}
