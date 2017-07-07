#include "unity.h"
#include "traffic_light_fsm.h"
#include "mock_lamp_driver.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

/**
 * Given Traffic Light FSM is not initialized
 * When FSM initialization occurs
 * Then Lamp Driver shall be initialized
 * And Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Initialization(void)
{
    // arrange

    // assert
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_Init();
}

/**
 * Given Traffic Light FSM is initialized
 * When transition to the Phase 1 is triggered
 * Then Green Lamp shall be switched on for the EW-WE direction
 * And Red Lamp shall be switched on for the NS-SN direction
 * And Walk Lamp shall be switched on for the EW-WE direction
 */
void test_Init_Phase1(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    // assert
    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 1
 * When transition to the Phase 2 is triggered
 * Then Don't Walk lamp flashing mode shall activated for the EW-WE direction
 */
void test_Phase1_Phase2(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweDontWalkLampFlashing_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 2
 * When transition to the Phase 3 is triggered
 * Then Yellow Lamp shall be switched on for the EW-WE direction
 * And Don't Walk Lamp shall be switched on for the EW-WE direction
 */
void test_Phase2_Phase3(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 3
 * When transition to the Phase 4 is triggered
 * Then Red Lamp shall be switched on for the EW-WE direction
 */
void test_Phase3_Phase4(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 4
 * When transition to the Phase 5 is triggered
 * Then Green Lamp shall be switched on for the NS-SN direction
 * And Walk Lamp shall be switched on for the NS-SN direction
 */
void test_Phase4_Phase5(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 5
 * When transition to the Phase 6 is triggered
 * Then Don't Walk Lamp flashing mode shall be activated for the NS-SN direction
 */
void test_Phase5_Phase6(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_NssnDontWalkLampFlashing_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 6
 * When transition to the Phase 7 is triggered
 * Then Yellow Lamp shall be switched on for the NS-SN direction
 * And Don't Walk Lamp shall be switched on for the NS-SN direction
 */
void test_Phase6_Phase7(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_NssnYellowLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 7
 * When transition to the Phase 8 is triggered
 * Then Red Lamp shall be switched on for the NS-SN direction
 */
void test_Phase7_Phase8(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnYellowLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_NssnRedLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 8
 * When transition to the Phase 1 is triggered
 * Then Green Lamp shall be switched on for the EW-WE direction
 * And Walk Lamp shall be switched on for the EW-WE direction
 */
void test_Phase8_Phase1(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnYellowLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 1
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Init_Phase1_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 2
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase2_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 3
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase3_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();


    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 4
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase4_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 5
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase5_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 6
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase6_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();


    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 7
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase7_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnYellowLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 8
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase8_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnYellowLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in the Phase 1
 * But it was in the Phase 8 before
 * When transition to the Default Phase is triggered
 * Then Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */
void test_Phase8_Phase1_Default(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweYellowLampOn_Expect();
    LDRV_EwweDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnGreenLampOn_Expect();
    LDRV_NssnWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnYellowLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_NssnRedLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    // assert
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    // act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given FSM is in the Default Phase
 * But it was in the Phase 1 before
 * When transition to the Phase 1 is triggered
 * Then Green Lamp shall be switched on for the EW-WE direction
 * And Red Lamp shall be switched on for the NS-SN direction
 * And Walk Lamp shall be switched on for the EW-WE direction
 */
void test_Phase1_Default_Phase1(void)
{
    // arrange
    LDRV_Init_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_Init();

    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    TLFSM_SwitchToDefaultPhase();

    // assert
    LDRV_EwweGreenLampOn_Expect();
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    // act
    TLFSM_SwitchToNextPhase();
}
