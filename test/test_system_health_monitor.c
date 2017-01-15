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
}
