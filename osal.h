#ifndef OSAL_H
#define OSAL_H

#include "osal_types.h"

OSAL_RESULT_E Osal_CreateMutex(OSAL_MUTEX * pMutex);

OSAL_RESULT_E Osal_GetMutex(OSAL_MUTEX mutex, uint32_t ticks);

OSAL_RESULT_E Osal_PutMutex(OSAL_MUTEX mutex);

#endif // OSAL_H

