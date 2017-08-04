#include "KeyGenerator.h"
#include "osal.h"


typedef struct KG_DATA
{
	OSAL_MUTEX	mutex;
	unsigned int lastGeneratedkey;

}KG_DATA_S;


static KG_DATA_S gKgData;


OSAL_RESULT_E KG_Init(void)
{
	OSAL_RESULT_E status = OSAL_FAIL;

	gKgData.lastGeneratedkey = 0;

	status = Osal_CreateMutex(&gKgData.mutex);

	return status;
}

OSAL_RESULT_E KG_GenerateKey(uint32_t * pKey)
{
	OSAL_RESULT_E status = OSAL_FAIL;

	status = Osal_GetMutex(gKgData.mutex, 10);

	if (status == OSAL_OK)
	{
		gKgData.lastGeneratedkey += 1;

		*pKey = gKgData.lastGeneratedkey;

		status = Osal_PutMutex(gKgData.mutex);
	}

	return status;
}