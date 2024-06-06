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
    SW1_Destroy();
}

static void expectSW1Init(void) {
    IO_Write_Expect(RCGCGPIO_R, RCGCGPIO_PORTF);
    IO_Write_Expect(GPIOF_PUR_R, SW1_PIN);
    IO_Write_Expect(GPIOF_DEN_R, SW1_PIN);
    IO_Write_Expect(GPIOF_DIR_R, ~SW1_PIN);
}

void testSW1InitCorrect(void) {
    expectSW1Init();
    SW1_Create();
}

void testGetSW1StateClose(void) {
    expectSW1Init();
    IO_Read_ExpectAndReturn(GPIOF_DATA_R, ~SW1_PIN);

    SW1_Create();
    TEST_ASSERT_EQUAL_INT32(SW1_CLOSED, SW1_GetState());
}

void testGetSW1StateOpen(void) {
    expectSW1Init();
    IO_Read_ExpectAndReturn(GPIOF_DATA_R, SW1_PIN);

    SW1_Create();
    TEST_ASSERT_EQUAL_INT32(SW1_OPEN, SW1_GetState());
}