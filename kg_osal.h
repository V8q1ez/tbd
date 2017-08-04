#ifndef KG_OSAL_H
#define KG_OSAL_H

#include "osal_types.h"

OSAL_RESULT_E KG_OsalCreateMutex(void);

OSAL_RESULT_E KG_OsalGetMutex(void);

OSAL_RESULT_E KG_OsalPutMutex(void);

#endif // KG_OSAL_H

