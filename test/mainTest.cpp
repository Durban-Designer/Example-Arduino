/*
mainTest.cpp - the main test class for the application
mostly and example of how tests can work
Copywrite Royce Birnbaum 2020
*/

#include <Arduino.h>
#include <unity.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void testLedBuiltinPinNumber(void)
{
    TEST_ASSERT_EQUAL(LED_BUILTIN, 2);
}

void testLedStateHigh(void)
{
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), HIGH);
}

void testLedStateLow(void)
{
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), LOW);
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(testLedBuiltinPinNumber);

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop()
{
    if (i < max_blinks)
    {
        RUN_TEST(testLedStateHigh);
        delay(500);
        RUN_TEST(testLedStateLow);
        delay(500);
        i++;
    }
    else if (i == max_blinks)
    {
        UNITY_END(); // stop unit testing
    }
}