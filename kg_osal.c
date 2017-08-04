#include "kg_osal.h"

#include "FreeRTOS.h"
#include "semphr.h"


typedef struct KG_OSAL_DATA
{
	QueueHandle_t mutex;

}KG_OSAL_DATA_S;


static KG_OSAL_DATA_S gKgOsalData;


OSAL_RESULT_E KG_OsalCreateMutex()
{
	gKgOsalData.mutex = xSemaphoreCreateMutex();

	if (gKgOsalData.mutex != NULL)
	{
		return OSAL_OK;
	}
	return OSAL_FAIL;
}


OSAL_RESULT_E KG_OsalGetMutex()
{
	BaseType_t status = pdFAIL;

	status = xSemaphoreTake(gKgOsalData.mutex, (TickType_t)10);

	if (status == pdTRUE)
	{
		return OSAL_OK;
	}

	return OSAL_FAIL;
}

OSAL_RESULT_E KG_OsalPutMutex()
{
	BaseType_t status = pdFAIL;

	status = xSemaphoreGive(gKgOsalData.mutex);

	if (status == pdTRUE)
	{
		return OSAL_OK;
	}

	return OSAL_FAIL;
}