#include "KeyGenerator.h"

#include "semphr.h"


typedef struct KG_DATA
{
	QueueHandle_t mutex;
	unsigned int lastGeneratedkey;

}KG_DATA_S;


static KG_DATA_S gKgData;


BaseType_t KG_Init(void)
{
	BaseType_t status = pdFALSE;

	gKgData.lastGeneratedkey = 0;

	gKgData.mutex = xSemaphoreCreateMutex();

	if (gKgData.mutex != NULL)
	{
		status = pdTRUE;
	}
	return status;
}

BaseType_t KG_GenerateKey(uint32_t * pKey)
{
	BaseType_t status = pdFALSE;

	status = xSemaphoreTake(gKgData.mutex, (TickType_t)10);

	if (status == pdTRUE)
	{
		gKgData.lastGeneratedkey += 1;

		*pKey = gKgData.lastGeneratedkey;

		status = xSemaphoreGive(gKgData.mutex);
	}

	return status;
}