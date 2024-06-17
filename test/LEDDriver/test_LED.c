#include "unity.h"
#include "mock_IO.h"
#define EXTERN
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
    TM4C_init();
    IO_SetBits_Expect(SYSCTL->RCGCGPIO, (1 << 5));
    IO_SetBits_Expect(GPIOF->DEN, LED_PIN);
    IO_SetBits_Expect(GPIOF->DIR, LED_PIN);
}

void testLEDInit(void) {
    expectLEDInit();
    LED_Create();
}

void testLEDGetStateOn(void) {
    expectLEDInit();
    IO_Read_ExpectAndReturn(GPIOF->DATA, LED_PIN);

    LED_Create();
    TEST_ASSERT_EQUAL_INT32(LED_ON, LED_GetState());
}

void testLEDGetStateOff(void) {
    expectLEDInit();    
    IO_Read_ExpectAndReturn(GPIOF->DATA, ~LED_PIN);

    LED_Create();
    TEST_ASSERT_EQUAL_INT32(LED_OFF, LED_GetState());
}

void testLEDSetStateOn(void) {
    expectLEDInit();
    IO_SetBits_Expect(GPIOF->DATA, LED_PIN);

    LED_Create();
    LED_On();
}

void testLEDSetStateOff(void) {
    expectLEDInit();
    IO_ClearBits_Expect(GPIOF->DATA, ~LED_PIN);

    LED_Create();
    LED_Off();
}