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
    LED_Destroy();
}

static void expectLEDInit(void) {
    IO_Write_Expect(RCGCGPIO_R, RCGCGPIO_PORTF);
    IO_Write_Expect(GPIOF_DEN_R, LED_PIN);
    IO_Write_Expect(GPIOF_DIR_R, LED_PIN);
}

void testLEDInit(void) {
    expectLEDInit();
    LED_Create();
}

void testLEDGetStateOn(void) {
    expectLEDInit();
    IO_Read_ExpectAndReturn(GPIOF_DATA_R, LED_PIN);

    LED_Create();
    TEST_ASSERT_EQUAL_INT32(LED_ON, LED_GetState());
}

void testLEDGetStateOff(void) {
    expectLEDInit();    
    IO_Read_ExpectAndReturn(GPIOF_DATA_R, ~LED_PIN);

    LED_Create();
    TEST_ASSERT_EQUAL_INT32(LED_OFF, LED_GetState());
}