#ifndef SF_DVC_H
#define SF_DVC_H

#include <stdint.h>

void SF_DvcInit( void );

void SF_DvcWritePage( uint32_t addr, uint8_t * pData, uint8_t size);

void SF_DvcReadData( uint32_t addr, uint8_t * pData, uint16_t size);

void SF_DvcClearSector( uint32_t addr );


#endif // SF_DVC_H
