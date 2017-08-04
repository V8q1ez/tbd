#ifndef KEY_GENERATOR_H
#define KEY_GENERATOR_H

#include "osal_types.h"

OSAL_RESULT_E KG_Init(void);

OSAL_RESULT_E KG_GenerateKey(uint32_t * pKey);

#endif // KEY_GENERATOR_H

