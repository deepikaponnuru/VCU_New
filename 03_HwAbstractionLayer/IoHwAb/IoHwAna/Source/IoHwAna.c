/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : Analog  Input Output Hardware  Driver

File Name   : IoHwAna.c

Description : This is the IoHwAna source file.

Version     : 1.0

Date        : 8 February 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------- Include Section -----------------------------------------------------------------*/
#include "IoHwAna_Int.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Data buffer to capture measured values */
static uint16_t IoHwAna_Value[eIoHwAna_NumAnaSensors];

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void IoHwAna_Init(void)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Function Name   : IoHwAna_Init

Description     : Initializes the analog input hardware driver.This function sets up the ADC result buffers for all configured ADC groups
                 and prepares the internal data structures for reading analog sensor values.

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : N/A

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    uint16_t i;
    for (i = 0; i < eIoHwAna_NumAnaSensors; i++)
    {
        IoHwAna_Value[i] = 0U;
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
void IoHwAna_Proc(void)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : IoHwAna_Proc

Description     : Periodically processes the analog input hardware driver.
                 This function checks the status of all configured ADC groups, triggers new conversions
                 if a group is idle or completed, and ensures continuous scanning of analog signals.

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : N/A

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    uint16_t i;

    switch (Adc_Status)
    {
        case ADC_IDLE:
           // Adc_StartGroupConversion();
           Adc_StartConversion();
            break;

        case ADC_BUSY:
            /* ADC is converting – do nothing */
            break;

        case ADC_COMPLETED:
            /* Copy latest ADC snapshot */ 
            for (i = 0; i < eIoHwAna_NumAnaSensors; i++)
            {
               // IoHwAna_Value[i] = g_AdcResult[chaIndexSensorsConfig[i]];
               IoHwAna_Value[i] = AdcResult_U16[ChaIndexSensorsConfig_U16[i]];
            }

            /* Restart ADC immediately (software streaming) */
            Adc_Status = ADC_IDLE;
            break;

        default:
            break;
    }
}


void IoHwAna_GetValue(eIoHwAnaSensorType sensor, uint16_t *value)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Function Name   : IoHwAna_GetValue

Description     : Retrieves the latest converted value of a specified analog signal.
                  The function accesses the internal ADC result buffer and returns the value corresponding
                  to the requested signal ID.

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : N/A

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
     /* Return signal value from buffer (if valid) */
    if ((sensor < eIoHwAna_NumAnaSensors) && (value != NULL))
    {
        *value = IoHwAna_Value[sensor];
    }
}













