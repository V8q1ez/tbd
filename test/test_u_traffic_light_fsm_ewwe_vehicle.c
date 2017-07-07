#include "unity.h"
#include "traffic_light_fsm.h"
#include "mock_lamp_driver.h"

void setUp(void)
{
    LDRV_EwweDontWalkLampOn_Ignore();
    LDRV_EwweWalkLampOn_Ignore();
    LDRV_EwweDontWalkLampFlashing_Ignore();

    LDRV_NssnRedLampOn_Ignore();
    LDRV_NssnYellowLampOn_Ignore();
    LDRV_NssnGreenLampOn_Ignore();
    LDRV_NssnRedLampFlashing_Ignore();
    LDRV_NssnDontWalkLampOn_Ignore();
    LDRV_NssnWalkLampOn_Ignore();
    LDRV_NssnDontWalkLampFlashing_Ignore();
}

void tearDown(void) {
    // clean stuff up here
}

/**
 * Given Traffic Light FSM is not initialized
 * When FSM initialization occurs
 * Then Lamp Driver shall be initialized
 * And Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Initialization(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
}

/**
 * Given Traffic Light FSM is initialized
 * When transition to the Phase 1 is triggered
 * Then Green Lamp shall be switched on for the EW-WE direction
 */
void test_Init_Phase1(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 1
 * When transition to the Phase 2 is triggered
 * Then vehicle traffic light state shall not be changed for the EW-WE direction
 */
void test_Phase1_Phase2(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 2
 * When transition to the Phase 3 is triggered
 * Then Yellow Lamp shall be switched on for the EW-WE direction
 */
void test_Phase2_Phase3(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 3
 * When transition to the Phase 4 is triggered
 * Then Red Lamp shall be switched on for the EW-WE direction
 */
void test_Phase3_Phase4(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 4
 * When transition to the Phase 5 is triggered
 * Then vehicle traffic light state shall not be changed for the EW-WE direction
 */
void test_Phase4_Phase5(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 5
 * When transition to the Phase 6 is triggered
 * Then vehicle traffic light state shall not be changed for the EW-WE direction
 */
void test_Phase5_Phase6(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 6
 * When transition to the Phase 7 is triggered
 * Then vehicle traffic light state shall not be changed for the EW-WE direction
 */
void test_Phase6_Phase7(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 7
 * When transition to the Phase 8 is triggered
 * Then vehicle traffic light state shall not be changed for the EW-WE direction
 */
void test_Phase7_Phase8(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 8
 * When transition to the Phase 1 is triggered
 * Then Green Lamp shall be switched on for the EW-WE direction
 */
void test_Phase8_Phase1(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 1
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Init_Phase1_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 2
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase2_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 3
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase3_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 4
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase4_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 5
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase5_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 6
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase6_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 7
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase7_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 8
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase8_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 1
 * But it was in the Phase 8 before
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for EW-WE direction
 */
void test_Phase8_Phase1_Default(void)
{
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given FSM is in the Default Phase
 * But it was in the Phase 1 before
 * When transition to the Phase 1 is triggered
 * Then Green Lamp shall be switched on for the EW-WE direction
 */
void test_Phase1_Default_Phase1(void)
{
    // arrange
    LDRV_Init_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_EwweGreenLampOn_Expect();

    TLFSM_Init();
    TLFSM_SwitchToNextPhase();
    TLFSM_SwitchToDefaultPhase();
    TLFSM_SwitchToNextPhase();
}
