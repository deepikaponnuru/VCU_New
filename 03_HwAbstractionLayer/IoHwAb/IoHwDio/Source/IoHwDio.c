/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : Analog  Input Output Hardware  Driver

File Name   : IoHwDio.c

Description : This is the IoHwDio source file.

Version     : 1.0

Date        : 28 January 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------- Include Section -----------------------------------------------------------------*/
#include "IoHwDio_Int.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/ 

/*------------------------------------------------------------------ Global Variable Definitions ----------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------- Static Global Variable Definitions -------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
uint8_t IoHwDio_Read(uint16_t ChannelId)
{
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : IoHwDio_Read

Description     : Reads the current logical state (HIGH or LOW) of the specified digital input channel.

In Parameter    : ChannelId – Identifier for the digital channel to be read.

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : Returns the digital level of the specified channel (0 = LOW, 1 = HIGH).

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
    return Dio_ReadChannel(IoHwDio_ChaMappingConfig[ChannelId]);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void IoHwDio_Write(uint16_t ChannelId, uint8_t value)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : IoHwDio_Write

Description     : Writes a logical state (HIGH or LOW) to the specified digital output channel.

In Parameter    :
                  ChannelId – Identifier for the digital channel to be written.
                  value – Logical state to be set on the channel (0 = LOW, 1 = HIGH).

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : N/A

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    Dio_WriteChannel(IoHwDio_ChaMappingConfig[ChannelId], value);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void IoHwDio_Proc(void)
 {
    IoHwDio_Dig8DIN_U8  = IoHwDio_Read(eIoHwDio_Dig8DIN);
    IoHwDio_Dig1DIN_U8  = IoHwDio_Read(eIoHwDio_Dig1DIN);
    IoHwDio_Dig4DIN_U8  = IoHwDio_Read(eIoHwDio_Dig4DIN);        
    IoHwDio_Dig5DIN_U8  = IoHwDio_Read(eIoHwDio_Dig5DIN);         
    IoHwDio_Dig6DIN_U8  = IoHwDio_Read(eIoHwDio_Dig6DIN);         
    IoHwDio_Dig7DIN_U8  = IoHwDio_Read(eIoHwDio_Dig7DIN);  
    IoHwDio_Dig18DIN_U8 = IoHwDio_Read(eIoHwDio_Dig18DIN);
    IoHwDio_Dig3DIN_U8  = IoHwDio_Read(eIoHwDio_Dig3DIN);
    IoHwDio_Dig2DIN_U8  = IoHwDio_Read(eIoHwDio_Dig2DIN);
    IoHwDio_Dig17DIN_U8 = IoHwDio_Read(eIoHwDio_Dig17DIN);
    IoHwDio_Dig10DIN_U8 = IoHwDio_Read(eIoHwDio_Dig10DIN);
    IoHwDio_Dig9DIN_U8  = IoHwDio_Read(eIoHwDio_Dig9DIN);
     
     
   
    
   
    // IoHwDio_Write(eIoHwDio_Hs3DOUT,       IoHwDio_Hs3DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs2DOUT,       IoHwDio_Hs2DOUT_U8);
    // IoHwDio_Write(eIoHwDio_HsI1DOUT,      IoHwDio_HsI1DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs15DOUT,      IoHwDio_Hs15DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs16DOUT,      IoHwDio_Hs16DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs12DOUT,      IoHwDio_Hs12DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs11DOUT,      IoHwDio_Hs11DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs10DOUT,      IoHwDio_Hs10DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs9DOUT,       IoHwDio_Hs9DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs8DOUT,       IoHwDio_Hs8DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs6_DOUT,       IoHwDio_Hs6DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs4_DOUT,       IoHwDio_Hs4DOUT_U8);
    





    // /* Read inputs */
   
    // IoHwDio_Dig4DIN_U8 = IoHwDio_Read(eIoHwDio_Dig4DIN);        
    // IoHwDio_Dig5DIN_U8 = IoHwDio_Read(eIoHwDio_Dig5DIN);         
    // IoHwDio_Dig6DIN_U8 = IoHwDio_Read(eIoHwDio_Dig6DIN);         
    // IoHwDio_Dig7DIN_U8 = IoHwDio_Read( eIoHwDio_Dig7DIN);  


    // /* Write outputs */
    
    // IoHwDio_Write(eIoHwDio_Dig8DOUT,       IoHwDio_Dig8DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig11DOUT,      IoHwDio_Dig11DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig13DOUT,      IoHwDio_Dig13DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig14DOUT,      IoHwDio_Dig14DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig15DOUT,      IoHwDio_Dig15DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig16DOUT,      IoHwDio_Dig16DOUT_U8);

    // IoHwDio_Write(eIoHwDio_CANA_nSTBYDOUT, IoHwDio_CANA_nSTBYDOUT_U8);
    // IoHwDio_Write(eIoHwDio_CANA_ENDOUT,    IoHwDio_CANA_ENDOUT_U8);
    // IoHwDio_Write(eIoHwDio_CANA_nFLTDOUT,  IoHwDio_CANA_nFLTDOUT_U8);

    // IoHwDio_Write(eIoHwDio_Ls1DOUT,        IoHwDio_Ls1DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Ls23DOUT,       IoHwDio_Ls23DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Ls33DOUT,       IoHwDio_Ls33DOUT_U8);

    // IoHwDio_Write(eIoHwDio_Hs43DOUT,       IoHwDio_Hs43DOUT_U8);
    // IoHwDio_Write(eIoHwDio_dig1DOUT,       IoHwDio_dig1DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs3DOUT,        IoHwDio_Hs3DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs2DOUT,        IoHwDio_Hs2DOUT_U8);
    // IoHwDio_Write(eIoHwDio_HsI12DOUT,      IoHwDio_HsI12DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs16DOUT,       IoHwDio_Hs16DOUT_U8);

    // IoHwDio_Write(eIoHwDio_Hs15DOUT,       IoHwDio_Hs15DOUT_U8);
    // IoHwDio_Write(eIoHwDio_CANB_nSTBDOUT,  IoHwDio_CANB_nSTBDOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs14DOUT,       IoHwDio_Hs14DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs13DOUT,       IoHwDio_Hs13DOUT_U8);

    // IoHwDio_Write(eIoHwDio_Dig18DOUT,      IoHwDio_Dig18DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs12DOUT,       IoHwDio_Hs12DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs11DOUT,       IoHwDio_Hs11DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig3DOUT,       IoHwDio_Dig3DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs10DOUT,       IoHwDio_Hs10DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig2DOUT,       IoHwDio_Dig2DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig17DOUT,      IoHwDio_Dig17DOUT_U8);

    // IoHwDio_Write(eIoHwDio_Hs9DOUT,        IoHwDio_Hs9DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs8DOUT,        IoHwDio_Hs8DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs7DOUT,        IoHwDio_Hs7DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs6DOUT,        IoHwDio_Hs6DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Hs4DOUT,        IoHwDio_Hs4DOUT_U8);

    // IoHwDio_Write(eIoHwDio_Dig10DOUT,      IoHwDio_Dig10DOUT_U8);
    // IoHwDio_Write(eIoHwDio_Dig9DOUT,       IoHwDio_Dig9DOUT_U8);
}
