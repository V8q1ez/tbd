#include "traffic_light_fsm.h"
#include "lamp_driver.h"
#include "string.h"


typedef void (*TLFSM_ENTER_STATE_FP)(void);

#define TLFSM_NUMBER_OF_STATES (9)

typedef struct TLFSM_DATA
{
    const TLFSM_ENTER_STATE_FP  states[ TLFSM_NUMBER_OF_STATES ];
    int                         activeState;
    int                         isTransitionFromDefault;

}TLFSM_DATA_S;


static void tlfsm_DefaultStateEnter(void);
static void tlfsm_Phase1StateEnter(void);
static void tlfsm_Phase2StateEnter(void);
static void tlfsm_Phase3StateEnter(void);
static void tlfsm_Phase4StateEnter(void);
static void tlfsm_Phase5StateEnter(void);
static void tlfsm_Phase6StateEnter(void);
static void tlfsm_Phase7StateEnter(void);
static void tlfsm_Phase8StateEnter(void);


static TLFSM_DATA_S gTlfsmData = {
        .states =
        {
                tlfsm_DefaultStateEnter,
                tlfsm_Phase1StateEnter,
                tlfsm_Phase2StateEnter,
                tlfsm_Phase3StateEnter,
                tlfsm_Phase4StateEnter,
                tlfsm_Phase5StateEnter,
                tlfsm_Phase6StateEnter,
                tlfsm_Phase7StateEnter,
                tlfsm_Phase8StateEnter
        }
};


void TLFSM_Init( void )
{
    gTlfsmData.activeState = 0;
    gTlfsmData.isTransitionFromDefault = 0;

    LDRV_Init();

    TLFSM_SwitchToDefaultPhase();
}

void TLFSM_SwitchToNextPhase( void )
{
    TLFSM_ENTER_STATE_FP stateFp = NULL;

    gTlfsmData.activeState++;

    if (TLFSM_NUMBER_OF_STATES == gTlfsmData.activeState)
    {
        gTlfsmData.activeState = 1;
    }

    stateFp = gTlfsmData.states[ gTlfsmData.activeState ];

    stateFp();
}

void TLFSM_SwitchToDefaultPhase( void )
{
    TLFSM_ENTER_STATE_FP stateFp = NULL;

    gTlfsmData.activeState = 0;
    gTlfsmData.isTransitionFromDefault = 1;

    stateFp = gTlfsmData.states[ gTlfsmData.activeState ];

    stateFp();
}

static void tlfsm_DefaultStateEnter(void)
{
    LDRV_EwweRedLampFlashing();
    LDRV_NssnRedLampFlashing();

    LDRV_EwweDontWalkLampOn();
    LDRV_NssnDontWalkLampOn();
}

static void tlfsm_Phase1StateEnter(void)
{
    LDRV_EwweGreenLampOn();
    if (1 == gTlfsmData.isTransitionFromDefault)
    {
        LDRV_NssnRedLampOn();
        gTlfsmData.isTransitionFromDefault = 0;
    }
    LDRV_EwweWalkLampOn();
}

static void tlfsm_Phase2StateEnter(void)
{
    LDRV_EwweDontWalkLampFlashing();
}

static void tlfsm_Phase3StateEnter(void)
{
    LDRV_EwweYellowLampOn();
    LDRV_EwweDontWalkLampOn();
}

static void tlfsm_Phase4StateEnter(void)
{
    LDRV_EwweRedLampOn();
}

static void tlfsm_Phase5StateEnter(void)
{
    LDRV_NssnGreenLampOn();
    LDRV_NssnWalkLampOn();
}

static void tlfsm_Phase6StateEnter(void)
{
    LDRV_NssnDontWalkLampFlashing();
}

static void tlfsm_Phase7StateEnter(void)
{
    LDRV_NssnYellowLampOn();
    LDRV_NssnDontWalkLampOn();
}

static void tlfsm_Phase8StateEnter(void)
{
    LDRV_NssnRedLampOn();
}
