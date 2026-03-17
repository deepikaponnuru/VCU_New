/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2026 iSyriuS engineering Germany Pvt. Ltd. - All Rights Reserved.

Module Name: Enhanced Versatile Analog-to-Digital Converter Driver.

File Name  : Adc_Ext.h

Description: This is the Ana public header.

Version    : 1.0

Date       : 03/02/2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef ADC_EXT_H_
#define ADC_EXT_H_

#include "driverlib.h"
#include "device.h"


 
#define ADC_MAX_MODULES        5U
#define ADC_CHANNELS_PER_MOD   1U


typedef enum
{
    ADC_IDLE = 0,  /**< ADC is idle. */
    ADC_BUSY,      /**< ADC is busy. */
    ADC_COMPLETED, /**< ADC conversion is completed. */
    ADC_NOT_AVAILABLE /**< ADC is not available. */
} Adc_StatusType;

typedef struct
{
    ADC_SOCNumber socNum;   /* SOC number */
    ADC_Trigger trigger;    /* Trigger source */
    ADC_Channel channel;    /* ADCINx */
} Adc_ChannelConfigType;

typedef enum
{
    ADCA = ADCA_BASE,
    ADCB = ADCB_BASE,  
    ADCC = ADCC_BASE,
    ADCD = ADCD_BASE,
    ADCE = ADCE_BASE     
} ADC_Modules;
typedef struct
{
    ADC_Modules module;
    uint16_t numChannels;
    Adc_ChannelConfigType ch[ADC_CHANNELS_PER_MOD];
} Adc_ConfigStruct_t;



void Adc_Init(void);

void Adc_StartConversion(void);

__interrupt void AdcA_ISR(void);
__interrupt void AdcB_ISR(void);
__interrupt void AdcC_ISR(void);
__interrupt void AdcD_ISR(void);
__interrupt void AdcE_ISR(void);


extern uint16_t AdcResult_U16[ADC_MAX_MODULES]; 
extern Adc_StatusType Adc_Status;
#endif /* ADC_EXT_H_ */
