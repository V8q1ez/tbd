#ifndef SYSTEM_HEALTH_MONITOR
#define SYSTEM_HEALTH_MONITOR

typedef enum
{
    FALSE = 0,
    TRUE = 1,

}BOOLEAN_E;

BOOLEAN_E SHM_AreMovingParametersValid( unsigned short speed,
                                        signed char gear,
                                        unsigned short rpm,
                                        unsigned char isHandbrakeActive );

#endif /* SYSTEM_HEALTH_MONITOR */
