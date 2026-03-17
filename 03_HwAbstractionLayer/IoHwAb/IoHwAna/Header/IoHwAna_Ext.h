/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : IO Hardware Analog Driver

File Name   : IoHwAna_Ext.h

Description : This is the IoHwAna public header.

Version     : 1.0

Date        : 8 February 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef IOHWANA_EXT_H_
#define IOHWANA_EXT_H_

/*------------------------------------------------------------------ Standard Types Include ---------------------------------------------------------------*/
#include "Adc_Ext.h" 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++ Configuration +++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* Analog Sensors List */
typedef enum
{
    eIoHwAna_Ths1Mon = 0,     
    eIoHwAna_Ths2Mon, 
    // eIoHwAna_AnaIN1,
    
    eIoHwAna_NumAnaSensors 

}eIoHwAnaSensorType;
#define IoHwAna_ADC_VREF (5.0F)
#define IoHwAna_ADC_MAX_COUNT (4095.0F)
 

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*------------------------------------------------------- Global Interface Functions Declaration ----------------------------------------------------------*/
/* Initializes all Analog Inputs and ADC hardware */
void IoHwAdc_Init(void);

/* Periodic processing to read ADC values */
void IoHwAna_Proc(void);

/* Gets the latest ADC value for a specific analog signal */
void IoHwAdc_GetValue(eIoHwAnaSensorType sensor, uint16_t *value);

#endif /* IOHWANA_H_EXT */