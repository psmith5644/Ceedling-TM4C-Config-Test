#include "unity.h"
#include "mock_IO.h"
#include "TM4C123GH6PM.h"
#include "LED.h"

void setUp(void)
{
    mock_IO_Init();
}

void tearDown(void)
{
    mock_IO_Verify();
    mock_IO_Destroy();
}

void testLEDInit(void) {
    IO_Write_Expect(RCGCGPIO_R, RCGCGPIO_PORTF);
    IO_Write_Expect(GPIOF_DEN_R, LED_PIN);
    IO_Write_Expect(GPIOF_DIR_R, LED_PIN);

    LED_Create();
    LED_Destroy();
}