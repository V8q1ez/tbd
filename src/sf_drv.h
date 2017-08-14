#ifndef SF_DRV_H
#define SF_DRV_H

#include <stdint.h>

typedef enum SF_DRV_RESULT
{
    SF_DRV_OK,

}SF_DRV_RESULT_E;


SF_DRV_RESULT_E SF_DrvInit( void );

SF_DRV_RESULT_E SF_DrvOpenSession( void );

SF_DRV_RESULT_E SF_DrvWriteRecord( uint8_t * pData, uint16_t size );

SF_DRV_RESULT_E SF_DrvReadRecord( uint8_t * pData, uint16_t size );

SF_DRV_RESULT_E SF_DrvCloseSession( void );

#endif  // SF_DRV_H
