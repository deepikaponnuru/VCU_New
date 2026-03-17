/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : Digital Input Output Hardware  Driver

File Name   : IoHwDio_Int.h

Description : This is the IoHwDio private header.

Version     : 1.00
Date        : 28 January 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef IOHWDIO_INT_H_
#define IOHWDIO_INT_H_

/*------------------------------------------------------------- Import Module Include Section -------------------------------------------------------------*/
#include "IoHwDio_Ext.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------*/
/*                Digital Inputs - Initialized to 0     */
/*------------------------------------------------------*/

uint8_t IoHwDio_Dig8DIN_U8  = 0U;
uint8_t IoHwDio_Dig1DIN_U8  = 0U;
uint8_t IoHwDio_Dig4DIN_U8  = 0U;
uint8_t IoHwDio_Dig5DIN_U8  = 0U;
uint8_t IoHwDio_Dig6DIN_U8  = 0U;
uint8_t IoHwDio_Dig7DIN_U8  = 0U;
uint8_t IoHwDio_Dig18DIN_U8 = 0U;
uint8_t IoHwDio_Dig3DIN_U8  = 0U;
uint8_t IoHwDio_Dig2DIN_U8  = 0U;
uint8_t IoHwDio_Dig17DIN_U8 = 0U;
uint8_t IoHwDio_Dig10DIN_U8 = 0U;
uint8_t IoHwDio_Dig9DIN_U8  = 0U;





/*------------------------------------------------------*/
/*               Digital Outputs - Initialized to 0     */
/*------------------------------------------------------*/

uint8_t IoHwDio_Hs3DOUT_U8    = 0U;
uint8_t IoHwDio_Hs2DOUT_U8    = 0U;
uint8_t IoHwDio_HsI1DOUT_U8   = 0U;
uint8_t IoHwDio_Hs15DOUT_U8   = 0U;
uint8_t IoHwDio_Hs16DOUT_U8   = 0U;
uint8_t IoHwDio_Hs12DOUT_U8   = 0U;
uint8_t IoHwDio_Hs11DOUT_U8   = 0U;
uint8_t IoHwDio_Hs10DOUT_U8   = 0U;
uint8_t IoHwDio_Hs9DOUT_U8    = 0U;
uint8_t IoHwDio_Hs8DOUT_U8    = 0U;
uint8_t IoHwDio_Hs6DOUT_U8    = 0U;
uint8_t IoHwDio_Hs4DOUT_U8    = 0U;


// /* ---------------- Digital inputs ---------------- */
// uint8_t IoHwDio_Dig4DIN_U8          = 0U;
// uint8_t IoHwDio_Dig5DIN_U8         = 0U;
// uint8_t IoHwDio_Dig6DIN_U8         = 0U;
// uint8_t IoHwDio_Dig7DIN_U8         = 0U;

// /* ---------------- Digital Outputs ---------------- */

// uint8_t IoHwDio_Dig8DOUT_U8        = 0U;
// uint8_t IoHwDio_Dig11DOUT_U8       = 0U;
// uint8_t IoHwDio_Dig13DOUT_U8       = 0U;
// uint8_t IoHwDio_Dig14DOUT_U8       = 0U;
// uint8_t IoHwDio_Dig15DOUT_U8       = 0U;
// uint8_t IoHwDio_Dig16DOUT_U8       = 0U;
// uint8_t IoHwDio_CANA_nSTBYDOUT_U8  = 0U;
// uint8_t IoHwDio_CANA_ENDOUT_U8     = 0U;
// uint8_t IoHwDio_CANA_nFLTDOUT_U8   = 0U;
// uint8_t IoHwDio_Ls1DOUT_U8         = 0U;
// uint8_t IoHwDio_Ls23DOUT_U8        = 0U;
// uint8_t IoHwDio_Ls33DOUT_U8        = 0U;
// uint8_t IoHwDio_Hs43DOUT_U8        = 0U;
// uint8_t IoHwDio_dig1DOUT_U8        = 0U;
// uint8_t IoHwDio_Hs3DOUT_U8         = 0U;
// uint8_t IoHwDio_Hs2DOUT_U8         = 0U;
// uint8_t IoHwDio_HsI12DOUT_U8       = 0U;
// uint8_t IoHwDio_Hs16DOUT_U8        = 0U;
// uint8_t IoHwDio_Hs15DOUT_U8        = 0U;
// uint8_t IoHwDio_CANB_nSTBDOUT_U8   = 0U;
// uint8_t IoHwDio_Hs14DOUT_U8        = 0U;
// uint8_t IoHwDio_Hs13DOUT_U8        = 0U;
// uint8_t IoHwDio_Dig18DOUT_U8       = 0U;
// uint8_t IoHwDio_Hs12DOUT_U8        = 0U;
// uint8_t IoHwDio_Hs11DOUT_U8        = 0U;
// uint8_t IoHwDio_Dig3DOUT_U8        = 0U;
// uint8_t IoHwDio_Hs10DOUT_U8        = 0U;
// uint8_t IoHwDio_Dig2DOUT_U8        = 0U;
// uint8_t IoHwDio_Dig17DOUT_U8       = 0U;
// uint8_t IoHwDio_Hs9DOUT_U8         = 0U;
// uint8_t IoHwDio_Hs8DOUT_U8         = 0U;
// uint8_t IoHwDio_Hs7DOUT_U8         = 0U;
// uint8_t IoHwDio_Hs6DOUT_U8         = 0U;
// uint8_t IoHwDio_Hs4DOUT_U8         = 0U;
// uint8_t IoHwDio_Dig10DOUT_U8       = 0U;
// uint8_t IoHwDio_Dig9DOUT_U8        = 0U;


/*------------------------------------------------------------------------ Local Macros -------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------- Local Typedefs ------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++ Configuration +++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
//uint16_t IoHwDio_ChaMappingConfig[eIoHwDio_DigitalSensors];

uint16_t IoHwDio_ChaMappingConfig[eIoHwDio_DigitalSensors] =
{
    DIO_CH28,  /*[IoHwDio_Dig8DIN] */
    DIO_CH21,  /*[IoHwDio_Dig1DIN]*/
    DIO_CH24,  /*[IoHwDio_Dig4DIN]*/
    DIO_CH25,  /*[IoHwDio_Dig5DIN]*/
    DIO_CH26,  /*[IoHwDio_Dig6DIN]*/
    DIO_CH27,  /*[IoHwDio_Dig7DIN]*/
    DIO_CH8,   /*[IoHwDio_Dig18DIN]*/
    DIO_CH23,  /*[IoHwDio_Dig3DIN]*/
    DIO_CH22,  /*[IoHwDio_Dig2DIN]*/
    DIO_CH7,   /*[IoHwDio_Dig17DIN]*/
    DIO_CH31,  /*[IoHwDio_Dig10DIN]*/
    DIO_CH29,  /*[IoHwDio_Dig9DIN]*/
    
   
    DIO_CH13,  /*[IoHwDio_Hs3DOUT]*/
    DIO_CH12,  /*[IoHwDio_Hs2DOUT]*/
    DIO_CH11,  /*[IoHwDio_HsI1DOUT]*/
    DIO_CH16,  /*[IoHwDio_Hs15DOUT]*/
    DIO_CH17,  /*[IoHwDio_Hs16DOUT]*/
    DIO_CH4,   /*[IoHwDio_Hs12DOUT]*/
    DIO_CH40,  /*[IoHwDio_Hs11DOUT]*/
    DIO_CH41,  /*[IoHwDio_Hs10DOUT]*/
    DIO_CH44,  /*[IoHwDio_Hs9DOUT]*/
    DIO_CH9,   /*[IoHwDio_Hs8DOUT]*/
    DIO_CH10,  /*[IoHwDio_Hs6DOUT]*/
    DIO_CH34,  /*[IoHwDio_Hs4DOUT]*/
     





    // DIO_CH24,  
    // DIO_CH25,  
    // DIO_CH26,  
    // DIO_CH27,  

    // DIO_CH28,
    //DIO_CH47 
    // DIO_CH48, 
    // DIO_CH49,
    // DIO_CH50,
    // DIO_CH51,
    // DIO_CH52,
    // DIO_CH54,  
    // DIO_CH228, 
    // DIO_CH226, 
    // DIO_CH253, 
    // DIO_CH247, 
    // DIO_CH55,  
    // DIO_CH60,  
    // DIO_CH21,  
    // DIO_CH13,  
    // DIO_CH12,  
    // DIO_CH11,  
    // DIO_CH16,  
    // DIO_CH37,  
    // DIO_CH56,  
    // DIO_CH57,  
    // DIO_CH58,  
    // DIO_CH8,   
    // DIO_CH4,   
    // DIO_CH40,  
    // DIO_CH23,  
    // DIO_CH41,  
    // DIO_CH22,  
    // DIO_CH7,   
    // DIO_CH44,  
    // DIO_CH9,   
    // DIO_CH61,  
    // DIO_CH10,  
    // DIO_CH34,  
    // DIO_CH31,  
    // DIO_CH29,  
};

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */


/*------------------------------------------------------------------- Static Function Declarations --------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif /* IOHWDIO_INT_H_ */
