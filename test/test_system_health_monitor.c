#include "unity.h"
#include "system_health_monitor.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/**
 * Given all parameters are in range
 * When vehicle speed becomes equal to 0
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_001( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(0, 1, 2000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When vehicle speed becomes equal to 180
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_002( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(180, 1, 2000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When vehicle speed becomes equal to 181
 * Then SHM_AreMovingParametersValid() shall return INVALID
 */
void test_SHM_AreMovingParametersValid_003( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(181, 1, 2000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
/**
 * Given all parameters are in range
 * When selected gear becomes equal to -2
 * Then SHM_AreMovingParametersValid() shall return INVALID
 */
void test_SHM_AreMovingParametersValid_004( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(30, -2, 2000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
/**
 * Given all parameters are in range
 * When selected gear becomes equal to -1
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_005( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(10, -1, 2000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When selected gear becomes equal to 5
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_006( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(30, 5, 2000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When selected gear becomes equal to 6
 * Then SHM_AreMovingParametersValid() shall return INVALID
 */
void test_SHM_AreMovingParametersValid_007( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(30, 6, 2000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
/**
 * Given all parameters are in range
 * When engine speed becomes equal to 0
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_008( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(100, 1, 0, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When engine speed becomes equal to 6000
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_009( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(100, 1, 6000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When engine speed becomes equal to 6001
 * Then SHM_AreMovingParametersValid() shall return INVALID
 */
void test_SHM_AreMovingParametersValid_010( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(100, 1, 6001, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
/**
 * Given all parameters are in range
 * When handbrake becomes not activated
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_011( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(100, 1, 2000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When handbrake becomes activated
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_012( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(100, 0, 2000, 1);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * When handbrake state becomes equal to 2
 * Then SHM_AreMovingParametersValid() shall return INVALID
 */
void test_SHM_AreMovingParametersValid_013( void )
{
    BOOLEAN_E actual = INVALID;
    actual = SHM_AreMovingParametersValid(100, 2, 2000, 2);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
/**
 * Given all parameters are in range
 * When Reverse Gear becomes selected
 * And vehicle speed becomes equal to 21
 * Then SHM_AreMovingParametersValid() shall return INVALID
 */
void test_SHM_AreMovingParametersValid_014( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(21, -1, 1000, 0);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
/**
 * Given all parameters are in range
 * When Reverse Gear becomes selected
 * And vehicle speed becomes equal to 20
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_015( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(20, -1, 1000, 0);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
/**
 * Given all parameters are in range
 * And selected gear is equal to 1
 * But handbrake is activated
 * When vehicle speed becomes equal to 1
 * Then SHM_AreMovingParametersValid() shall return INVALID
 */
void test_SHM_AreMovingParametersValid_016( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(1, 1, 1000, 1);
    TEST_ASSERT_EQUAL_INT (INVALID, actual);
}
/**
 * Given all parameters are in range
 * And selected gear is equal to 1
 * But handbrake is activated
 * When vehicle speed becomes equal to 0
 * Then SHM_AreMovingParametersValid() shall return VALID
 */
void test_SHM_AreMovingParametersValid_017( void )
{
    BOOLEAN_E actual = INVALID;

    actual = SHM_AreMovingParametersValid(0, 1, 1000, 1);
    TEST_ASSERT_EQUAL_INT (VALID, actual);
}
