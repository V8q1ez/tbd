#include "KeyGenerator.h"
#include "kg_osal.h"


typedef struct KG_DATA
{
	unsigned int lastGeneratedkey;

}KG_DATA_S;


static KG_DATA_S gKgData;


OSAL_RESULT_E KG_Init(void)
{
	OSAL_RESULT_E status = OSAL_FAIL;

	gKgData.lastGeneratedkey = 0;

	status = KG_OsalCreateMutex();

	return status;
}

OSAL_RESULT_E KG_GenerateKey(uint32_t * pKey)
{
	OSAL_RESULT_E status = OSAL_FAIL;

	status = KG_OsalGetMutex();

	if (status == OSAL_OK)
	{
		gKgData.lastGeneratedkey += 1;

		*pKey = gKgData.lastGeneratedkey;

		status = KG_OsalPutMutex();
	}

	return status;
}