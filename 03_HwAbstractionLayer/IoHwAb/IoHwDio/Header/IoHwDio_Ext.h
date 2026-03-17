/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : Digital Input Output Hardware Driver

File Name   : IoHwDio_Ext.h

Description : This is the IohwDio Public header.

Version     : 1.00
Date        : 28 January 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef IOHWDIO_H_
#define IOHWDIO_H_

/*------------------------------------------------------------------ Standard Types Include ---------------------------------------------------------------*/
#include "Dio_Ext.h" 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define IoHwDio_LOW   0U
#define IoHwDio_HIGH  1U

/*--------------------------------------------------------------------- Static Global Macros --------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------- Global Typedefs -----------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++ Configuration +++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
enum
{
    eIoHwDio_Dig8DIN,
    eIoHwDio_Dig1DIN,
    eIoHwDio_Dig4DIN,
    eIoHwDio_Dig5DIN,
    eIoHwDio_Dig6DIN,
    eIoHwDio_Dig7DIN,
    eIoHwDio_Dig18DIN,
    eIoHwDio_Dig3DIN,
    eIoHwDio_Dig2DIN,
    eIoHwDio_Dig17DIN,
    eIoHwDio_Dig10DIN,
    eIoHwDio_Dig9DIN,


    eIoHwDio_Hs3_DOUT,
    eIoHwDio_Hs2_DOUT,
    eIoHwDio_HsI1_DOUT,
    eIoHwDio_Hs15_DOUT,
    eIoHwDio_Hs16_DOUT,
    eIoHwDio_Hs12_DOUT,
    eIoHwDio_Hs11_DOUT,
    eIoHwDio_Hs10_DOUT,
    eIoHwDio_Hs9_DOUT,
    eIoHwDio_Hs8_DOUT,
    eIoHwDio_Hs6_DOUT,
    eIoHwDio_Hs4_DOUT,
    
    eIoHwDio_DigitalSensors









    // eIoHwDio_Dig4DIN,
    // eIoHwDio_Dig5DIN,
    // eIoHwDio_Dig6DIN,
    // eIoHwDio_Dig7DIN,
    
    // eIoHwDio_Dig8_DOUT ,
    // eIoHwDio_Dig11_DOUT,
    // eIoHwDio_Dig13_DOUT,
    // eIoHwDio_Dig14_DOUT,
    // eIoHwDio_Dig15_DOUT,
    // eIoHwDio_Dig16_DOUT,
    // eIoHwDio_CANA_nSTBY_DOUT,
    // eIoHwDio_CANA_EN_DOUT,
    // eIoHwDio_CANA_nFLT_DOUT,
    // eIoHwDio_Ls1_DOUT,
    // eIoHwDio_Ls23_DOUT,
    // eIoHwDio_Ls33_DOUT,
    // eIoHwDio_Ls43_DOUT,
    // eIoHwDio_dig1_DOUT,
    // eIoHwDio_Hs3_DOUT,
    // eIoHwDio_Hs2_DOUT,
    // eIoHwDio_HsI12_DOUT,
    // eIoHwDio_Hs16_DOUT,
    // eIoHwDio_Hs15_DOUT,
    // eIoHwDio_CANB_nSTB_DOUT,
    // eIoHwDio_Hs14_DOUT,
    // eIoHwDio_Hs13_DOUT,
    // eIoHwDio_Dig18_DOUT,
    // eIoHwDio_Hs12_DOUT,
    // eIoHwDio_Hs11_DOUT,
    // eIoHwDio_Dig3_DOUT,
    // eIoHwDio_Hs10_DOUT,
    // eIoHwDio_Dig2_DOUT,
    // eIoHwDio_Dig17_DOUT,
    // eIoHwDio_Hs9_DOUT,
    // eIoHwDio_Hs8_DOUT,
    // eIoHwDio_Hs7_DOUT,
    // eIoHwDio_Hs6_DOUT,
    // eIoHwDio_Hs4_DOUT,
    // eIoHwDio_Dig10_DOUT,
    // eIoHwDio_Dig9_DOUT,
    // eIoHwDio_DigitalSensors
};

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*------------------------------------------------------- Global Interface Functions Declaration ----------------------------------------------------------*/
/* Read the value of a specified digital input channel */
uint8_t IoHwDio_Read(uint16_t ChannelId);
/* Write a value to a specified digital output channel */
void  IoHwDio_Write(uint16_t ChannelId, uint8_t value);

void  IoHwDio_Proc(void);

#endif /* IOHWDIO_H_ */
