#ifndef KEY_GENERATOR_H
#define KEY_GENERATOR_H

#include "FreeRTOS.h"

BaseType_t KG_Init(void);

BaseType_t KG_GenerateKey(uint32_t * pKey);

#endif // KEY_GENERATOR_H

