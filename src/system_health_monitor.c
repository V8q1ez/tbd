#include "system_health_monitor.h"

BOOLEAN_E SHM_AreMovingParametersValid( unsigned short speed,
                                        signed char gear,
                                        unsigned short rpm,
                                        unsigned char isHandbrakeActive )
{
    BOOLEAN_E result = TRUE;

    if (speed > 180 )
    {
        result = FALSE;
    }
    if ((gear < -1) || (gear > 5))
    {
        result = FALSE;
    }
    if (rpm > 6000)
    {
        result = FALSE;
    }
    if (isHandbrakeActive > 1)
    {
        result = FALSE;
    }
    if ((gear < -1) && (speed > 20))
    {
        result = FALSE;
    }
    if ((gear != 0) && (isHandbrakeActive == 1) && (speed > 0))
    {
        result = FALSE;
    }

	return result;
}
