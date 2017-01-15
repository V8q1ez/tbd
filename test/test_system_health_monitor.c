#include "unity.h"
#include "system_health_monitor.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_SHM_AreMovingParametersValid( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(20, 1, 2000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);

    actual = SHM_AreMovingParametersValid(190, 1, 2000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);

    actual = SHM_AreMovingParametersValid(30, 6, 2000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);

    actual = SHM_AreMovingParametersValid(100, 1, 7000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);

    actual = SHM_AreMovingParametersValid(100, 2, 2000, 1);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);

    /* ((gear < -1) && (speed > 20)) */
    actual = SHM_AreMovingParametersValid(30, -2, 1000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);

    /* ((gear != 0) && (isHandbrakeActive == 1) && (speed > 0)) */
    actual = SHM_AreMovingParametersValid(30, -2, 1000, 1);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
