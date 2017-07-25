#include <stdio.h>


void SHM_AreMovingParametersValid(unsigned short speed,
									signed char gear,
									unsigned short rpm,
									unsigned char isHandbrakeActive)
{
	if ((gear != 0) && (isHandbrakeActive == 1) && (speed > 0))
	{
		printf("Parameters are inconsistent");
	}
}

void main(void)
{
	SHM_AreMovingParametersValid( 1, 1, 0, 1);

	printf("Complete");
}