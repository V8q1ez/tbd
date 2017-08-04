#include "osal.h"

#include "FreeRTOS.h"
#include "semphr.h"

OSAL_RESULT_E Osal_CreateMutex(OSAL_MUTEX * pMutex)
{
	*pMutex = xSemaphoreCreateMutex();

	if (*pMutex != NULL)
	{
		return OSAL_OK;
	}
	return OSAL_FAIL;
}


OSAL_RESULT_E Osal_GetMutex(OSAL_MUTEX mutex, uint32_t ticks)
{
	BaseType_t status = pdFAIL;

	status = xSemaphoreTake(mutex, (TickType_t)ticks);

	if (status == pdTRUE)
	{
		return OSAL_OK;
	}

	return OSAL_FAIL;
}

OSAL_RESULT_E Osal_PutMutex(OSAL_MUTEX mutex)
{
	BaseType_t status = pdFAIL;

	status = xSemaphoreGive(mutex);

	if (status == pdTRUE)
	{
		return OSAL_OK;
	}

	return OSAL_FAIL;
}