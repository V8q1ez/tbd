#include "unity.h"
#include "traffic_light_fsm.h"
#include "lamp_driver.h"

typedef struct TEST_DATA
{
    int ldrvInitCalls;

    int ldrvEwweRedLampOnCalls;
    int ldrvEwweYellowLampOnCalls;
    int ldrvEwweGreenLampOnCalls;
    int ldrvEwweRedLampFlashingCalls;

    int ldrvEwweDontWalkLampOnCalls;
    int ldrvEwweWalkLampOnCalls;
    int ldrvEwweDontWalkLampFlashingCalls;

    int ldrvNssnRedLampOnCalls;
    int ldrvNssnYellowLampOnCalls;
    int ldrvNssnGreenLampOnCalls;
    int ldrvNssnRedLampFlashingCalls;

    int ldrvNssnDontWalkLampOnCalls;
    int ldrvNssnWalkLampOnCalls;
    int ldrvNssnDontWalkLampFlashingCalls;

}TEST_DATA_S;

static TEST_DATA_S gTestData;

/*** Mocks ********************************************************************/
void LDRV_Init( void )
{
    gTestData.ldrvInitCalls++;
}

void LDRV_EwweRedLampOn( void )
{
    gTestData.ldrvEwweRedLampOnCalls++;
}

void LDRV_EwweYellowLampOn( void )
{
    gTestData.ldrvEwweYellowLampOnCalls++;
}

void LDRV_EwweGreenLampOn( void )
{
    gTestData.ldrvEwweGreenLampOnCalls++;
}

void LDRV_EwweRedLampFlashing( void )
{
    gTestData.ldrvEwweRedLampFlashingCalls++;
}

void LDRV_EwweDontWalkLampOn( void )
{
    gTestData.ldrvEwweDontWalkLampOnCalls++;
}

void LDRV_EwweWalkLampOn( void )
{
    gTestData.ldrvEwweWalkLampOnCalls++;
}

void LDRV_EwweDontWalkLampFlashing( void )
{
    gTestData.ldrvEwweDontWalkLampFlashingCalls++;
}

void LDRV_NssnRedLampOn( void )
{
    gTestData.ldrvNssnRedLampOnCalls++;
}


void LDRV_NssnYellowLampOn( void )
{
    gTestData.ldrvNssnYellowLampOnCalls++;
}

void LDRV_NssnGreenLampOn( void )
{
    gTestData.ldrvNssnGreenLampOnCalls++;
}

void LDRV_NssnRedLampFlashing( void )
{
    gTestData.ldrvNssnRedLampFlashingCalls++;
}

void LDRV_NssnDontWalkLampOn( void )
{
    gTestData.ldrvNssnDontWalkLampOnCalls++;
}

void LDRV_NssnWalkLampOn( void )
{
    gTestData.ldrvNssnWalkLampOnCalls++;
}

void LDRV_NssnDontWalkLampFlashing( void )
{
    gTestData.ldrvNssnDontWalkLampFlashingCalls++;
}

#include "traffic_light_fsm.c"

/*** Tests ********************************************************************/
//extern gTlfsmData;

void setUp(void) {

    memset(&gTestData, 0, sizeof(gTestData));
    //memset(&gTlfsmData, 0, sizeof(gTlfsmData));
}

void tearDown(void) {
    // clean stuff up here
}
/**
 * Given Traffic Light FSM is not initialized
 * When TLFSM_Init() is called
 * Then activePhase shall be equal to TLFSM_DEFAULT_PHASE
 * And previousPhase shall be equal to TLFSM_DEFAULT_PHASE
 * And LDRV_EwweRedLampFlashing() shall be called
 * And LDRV_NssnRedLampFlashing() shall be called
 * And LDRV_EwweDontWalkLampOn() shall be called
 * And LDRV_NssnDontWalkLampOn() shall be called
 */
void test_Initialization(void)
{
    // arrange

    // act
    TLFSM_Init();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_DEFAULT_PHASE, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_DEFAULT_PHASE, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweRedLampFlashingCalls);
    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnRedLampFlashingCalls);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweDontWalkLampOnCalls);
    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnDontWalkLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_DEFAULT_PHASE
 * And previousPhase is equal to TLFSM_DEFAULT_PHASE
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_1
 * And previousPhase shall be equal to TLFSM_DEFAULT_PHASE
 * And LDRV_EwweGreenLampOn() shall be called
 * And LDRV_EwweWalkLampOn() shall be called
 */
void test_Phase1(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_DEFAULT_PHASE;
    //gTlfsmData.previousPhase = TLFSM_DEFAULT_PHASE;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_1, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_DEFAULT_PHASE, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweGreenLampOnCalls);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweWalkLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_1
 * And previousPhase is equal to TLFSM_DEFAULT_PHASE
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_2
 * And previousPhase shall be equal to TLFSM_PHASE_1
 * And LDRV_EwweDontWalkLampFlashing() shall be called
 */
void test_Phase2(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_1;
    //gTlfsmData.previousPhase = TLFSM_DEFAULT_PHASE;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_2, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_1, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweDontWalkLampFlashingCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_2
 * And previousPhase is equal to TLFSM_PHASE_1
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_3
 * And previousPhase shall be equal to TLFSM_PHASE_2
 * And LDRV_EwweYellowLampOn() shall be called
 * And LDRV_EwweDontWalkLampOn() shall be called
 */
void test_Phase3(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_2;
    //gTlfsmData.previousPhase = TLFSM_PHASE_1;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_3, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_2, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweYellowLampOnCalls);
    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweDontWalkLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_3
 * And previousPhase is equal to TLFSM_PHASE_2
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_4_8
 * And previousPhase shall be equal to TLFSM_PHASE_3
 * And LDRV_EwweRedLampOn() shall be called
 */
void test_Phase4(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_3;
    //gTlfsmData.previousPhase = TLFSM_PHASE_2;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_4_8, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_3, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweRedLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_4_8
 * And previousPhase is equal to TLFSM_PHASE_3
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_5
 * And previousPhase shall be equal to TLFSM_PHASE_4_8
 * And LDRV_NssnGreenLampOn() shall be called
 * And LDRV_NssnWalkLampOn() shall be called
 */
void test_Phase5(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_4_8;
    //gTlfsmData.previousPhase = TLFSM_PHASE_3;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_5, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_4_8, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnGreenLampOnCalls);
    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnWalkLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_5
 * And previousPhase is equal to TLFSM_PHASE_4_8
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_6
 * And previousPhase shall be equal to TLFSM_PHASE_5
 * And LDRV_NssnDontWalkLampFlashing() shall be called
 */
void test_Phase6(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_5;
    //gTlfsmData.previousPhase = TLFSM_PHASE_4_8;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_6, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_5, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnDontWalkLampFlashingCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_6
 * And previousPhase is equal to TLFSM_PHASE_5
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_7
 * And previousPhase shall be equal to TLFSM_PHASE_6
 * And LDRV_NssnNssnYellowLampOn() shall be called
 */
void test_Phase7(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_6;
    //gTlfsmData.previousPhase = TLFSM_PHASE_5;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_7, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_6, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnYellowLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_7
 * And previousPhase is equal to TLFSM_PHASE_6
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_4_8
 * And previousPhase shall be equal to TLFSM_PHASE_7
 * And LDRV_NssnNssnYellowLampOn() shall be called
 */
void test_Phase8(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_7;
    //gTlfsmData.previousPhase = TLFSM_PHASE_6;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_4_8, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_7, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnRedLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_4_8
 * And previousPhase is equal to TLFSM_PHASE_7
 * When TLFSM_SwitchToNextPhase() is called
 * Then activePhase shall be equal to TLFSM_PHASE_1
 * And previousPhase shall be equal to TLFSM_PHASE_4_8
 * And LDRV_EwweGreenLampOn() shall be called
 * And LDRV_EwweWalkLampOn() shall be called
 */
void test_Phase8_Phase1(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_4_8;
    //gTlfsmData.previousPhase = TLFSM_PHASE_7;

    // act
    TLFSM_SwitchToNextPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_1, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_PHASE_4_8, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweGreenLampOnCalls);
    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweWalkLampOnCalls);
}

/**
 * Given Traffic Light FSM is initialized
 * And activePhase is equal to TLFSM_PHASE_1
 * And previousPhase is equal to TLFSM_PHASE_4_8
 * When TLFSM_SwitchToDefaultPhase() is called
 * Then activePhase shall be equal to TLFSM_DEFAULT_PHASE
 * And previousPhase shall be equal to TLFSM_DEFAULT_PHASE
 * And LDRV_EwweRedLampFlashing() shall be called
 * And LDRV_NssnRedLampFlashing() shall be called
 * And LDRV_EwweDontWalkLampOn() shall be called
 * And LDRV_NssnDontWalkLampOn() shall be called
 */
void test_Phase1_Default(void)
{
    // arrange
    //gTlfsmData.activePhase = TLFSM_PHASE_1;
    //gTlfsmData.previousPhase = TLFSM_PHASE_4_8;

    // act
    TLFSM_SwitchToDefaultPhase();

    // assert
    TEST_ASSERT_EQUAL_INT(TLFSM_DEFAULT_PHASE, gTlfsmData.activePhase);
    TEST_ASSERT_EQUAL_INT(TLFSM_DEFAULT_PHASE, gTlfsmData.previousPhase);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweRedLampFlashingCalls);
    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnRedLampFlashingCalls);

    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvEwweDontWalkLampOnCalls);
    TEST_ASSERT_EQUAL_INT(1, gTestData.ldrvNssnDontWalkLampOnCalls);
}
