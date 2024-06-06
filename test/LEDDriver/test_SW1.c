#include "unity.h"
#include "TM4C123GH6PM.h"
#include "SW1.h"
#include "mock_IO.h"
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

void testSW1InitCorrect(void) {
    IO_Write_Expect(RCGCGPIO_R, RCGCGPIO_PORTF);
    IO_Write_Expect(GPIOF_PUR_R, SW1_PIN);
    IO_Write_Expect(GPIOF_DEN_R, SW1_PIN);
    IO_Write_Expect(GPIOF_DIR_R, ~SW1_PIN);
    SW1_Create();
    SW1_Destroy();
}