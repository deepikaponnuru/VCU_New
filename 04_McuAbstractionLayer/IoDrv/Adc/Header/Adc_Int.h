/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2026 iSyriuS engineering Germany Pvt. Ltd. - All Rights Reserved.

Module Name: Enhanced Versatile Analog-to-Digital Converter Driver.

File Name  : Adc_Int.h

Description: This is the Ana public header.

Version    : 1.0

Date       : 03/02/2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef ADC_INT_H_
#define ADC_INT_H_

/*------------------------------------------------------------------ Standard Types Include ---------------------------------------------------------------*/
#include "Adc_Ext.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------ Configurable Global Macros -----------------------------------------------------------*/

static const Adc_ConfigStruct_t ADC_Config_S[ADC_MAX_MODULES] =
{
    {
        .module = ADCA,
        .numChannels = 1,
        .ch =
        {
            [0]=
            {
                .socNum  = ADC_SOC_NUMBER0,
                .trigger = ADC_TRIGGER_SW_ONLY,
                .channel = ADC_CH_ADCIN0
            }
            
        }  
    },
    {
        .module = ADCB,
        .numChannels = 1,
        .ch =
        {
            [0]=
            {
                .socNum  = ADC_SOC_NUMBER0,
                .trigger = ADC_TRIGGER_EPWM2_SOCA,
                .channel = ADC_CH_ADCIN2
            }
        }  
    },
    {
        .module = ADCC,
        .numChannels = 1,
        .ch =
        {
            [0]=
            {
                .socNum  = ADC_SOC_NUMBER0,
                .trigger = ADC_TRIGGER_SW_ONLY,
                .channel = ADC_CH_ADCIN0
            }
        }  
    },
    
    {
        .module = ADCD,
        .numChannels = 1,
        .ch =
        {
            [0]=
            {
                .socNum  = ADC_SOC_NUMBER0,
                .trigger = ADC_TRIGGER_SW_ONLY,
                .channel = ADC_CH_ADCIN0
            }
           
        }  
    },
    {
        .module = ADCE,
        .numChannels = 1,
        .ch =
        {
            [0]=
            {
                .socNum  = ADC_SOC_NUMBER0,
                .trigger = ADC_TRIGGER_SW_ONLY,
                .channel = ADC_CH_ADCIN3
            }
           
        }  
    }
};


#endif /* ADC_INT_H_ */
