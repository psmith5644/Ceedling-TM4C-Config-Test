#include "unity.h"
#define EXTERN
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
    SW1_Destroy();
}

static void expectSW1Init(void) {
    TM4C_init();
    IO_SetBits_Expect(&SYSCTL->RCGCGPIO, (1 << 5));
    IO_SetBits_Expect(&GPIOF->PUR, SW1_PIN);
    IO_SetBits_Expect(&GPIOF->DEN, SW1_PIN);
    IO_ClearBits_Expect(&GPIOF->DIR, ~SW1_PIN);
}

void testSW1InitCorrect(void) {
    expectSW1Init();
    SW1_Create();
}

void testGetSW1StateClose(void) {
    expectSW1Init();
    IO_Read_ExpectAndReturn(&GPIOF->DATA, ~SW1_PIN);

    SW1_Create();
    TEST_ASSERT_EQUAL_INT32(SW1_CLOSED, SW1_GetState());
}

void testGetSW1StateOpen(void) {
    expectSW1Init();
    IO_Read_ExpectAndReturn(&GPIOF->DATA, SW1_PIN);

    SW1_Create();
    TEST_ASSERT_EQUAL_INT32(SW1_OPEN, SW1_GetState());
}