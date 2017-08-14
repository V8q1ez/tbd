#include "unity.h"
#include "sf_drv.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/**
 * Given
 * When
 * Then
 */
void test_001( void )
{
    SF_DRV_RESULT_E result;

    result = SF_DrvInit();

    TEST_ASSERT_EQUAL_INT (SF_DRV_OK, result);
}
