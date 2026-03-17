/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2026 iSyriuS engineering Germany Pvt. Ltd. - All Rights Reserved.

Module Name: Enhanced Versatile Analog-to-Digital Converter Driver.

File Name  : Adc.c

Description: This is the  Adc source file.

Version    : 1.0

Date       : 03/02/2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include "Adc_Int.h"
uint16_t AdcResult_U16[ADC_MAX_MODULES];
Adc_StatusType Adc_Status = ADC_IDLE;

uint16_t AdcACounter_U16 = 0;
uint16_t AdcCCounter_U16 = 0;
uint16_t AdcDcounter_U16 = 0;
uint16_t AdcEcounter_U16 = 0;


const Adc_ConfigStruct_t *Adc_Config_s = ADC_Config_S;
void Adc_Init(void)
{
    uint16_t i, j;

    EALLOW;
    GPIO_setAnalogMode(226, GPIO_ANALOG_ENABLED);
    GPIO_setAnalogMode(11, GPIO_ANALOG_ENABLED);
    GPIO_setAnalogMode(17, GPIO_ANALOG_ENABLED);

    for(i = 0; i < ADC_MAX_MODULES; i++)
    {
        /* Enable Clock Based on Module */
        if(Adc_Config_s[i].module == ADCA_BASE)
            SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCA);
        else if(Adc_Config_s[i].module == ADCB_BASE)
            SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCB);
        else if(Adc_Config_s[i].module == ADCC_BASE)
            SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCC);
        else if(Adc_Config_s[i].module == ADCD_BASE)
            SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCD);
        else if(Adc_Config_s[i].module == ADCE_BASE)
            SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCE);


        /* Basic ADC Config */
        ADC_setVREF(Adc_Config_s[i].module,
                    ADC_REFERENCE_INTERNAL,
                    ADC_REFERENCE_3_3V);

        ADC_setPrescaler(Adc_Config_s[i].module,
                         ADC_CLK_DIV_4_0);

        ADC_setInterruptPulseMode(Adc_Config_s[i].module,
                                  ADC_PULSE_END_OF_CONV);

        ADC_enableConverter(Adc_Config_s[i].module);
    }

    DEVICE_DELAY_US(1000);

    /* Configure SOC for each module */
    for(i = 0; i < ADC_MAX_MODULES; i++)
    {
        for(j = 0; j < Adc_Config_s[i].numChannels; j++)
        {
            ADC_setupSOC(Adc_Config_s[i].module,
                         Adc_Config_s[i].ch[j].socNum,
                         Adc_Config_s[i].ch[j].trigger,
                         Adc_Config_s[i].ch[j].channel,
                         80);
        }
        
        /* Interrupt linked to last SOC of that module */
        ADC_setInterruptSource(Adc_Config_s[i].module, ADC_INT_NUMBER1,
                                                       Adc_Config_s[i].ch[Adc_Config_s[i].numChannels - 1].socNum);

        ADC_clearInterruptStatus(Adc_Config_s[i].module, ADC_INT_NUMBER1);

        ADC_enableInterrupt(Adc_Config_s[i].module, ADC_INT_NUMBER1);
    }

    /* Register ISRs */
    Interrupt_register(INT_ADCA1, &AdcA_ISR);
    Interrupt_register(INT_ADCB1, &AdcB_ISR);
    Interrupt_register(INT_ADCC1, &AdcC_ISR);
    Interrupt_register(INT_ADCD1, &AdcD_ISR);
    Interrupt_register(INT_ADCE1, &AdcE_ISR);


    Interrupt_enable(INT_ADCA1);
    Interrupt_enable(INT_ADCB1);
    Interrupt_enable(INT_ADCC1);
    Interrupt_enable(INT_ADCD1);
    Interrupt_enable(INT_ADCE1);

    EDIS;
    Adc_Status = ADC_IDLE;
}

void Adc_StartConversion(void)
{
    uint16_t i, j;

    for(i = 0; i < ADC_MAX_MODULES; i++)
    {
        for(j = 0; j < Adc_Config_s[i].numChannels; j++)
        {
            ADC_forceSOC(Adc_Config_s[i].module,
                         Adc_Config_s[i].ch[j].socNum);
        }
    }
}



__interrupt void AdcA_ISR(void)
{
    AdcResult_U16[0] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    AdcACounter_U16++;
    Adc_Status = ADC_COMPLETED;

    ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

__interrupt void AdcB_ISR(void)
{
    AdcResult_U16[1] = ADC_readResult(ADCBRESULT_BASE, ADC_SOC_NUMBER0);

    ADC_clearInterruptStatus(ADCB_BASE, ADC_INT_NUMBER1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}


__interrupt void AdcC_ISR(void)
{
    AdcResult_U16[2] = ADC_readResult(ADCCRESULT_BASE, ADC_SOC_NUMBER0);

    AdcCCounter_U16++;
    Adc_Status = ADC_COMPLETED;

    ADC_clearInterruptStatus(ADCC_BASE, ADC_INT_NUMBER1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}




__interrupt void AdcD_ISR(void)
{
    AdcResult_U16[3] = ADC_readResult(ADCDRESULT_BASE, ADC_SOC_NUMBER0);

    AdcDcounter_U16++;
    Adc_Status = ADC_COMPLETED;

    ADC_clearInterruptStatus(ADCD_BASE, ADC_INT_NUMBER1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}



__interrupt void AdcE_ISR(void)
{
    AdcResult_U16[4] = ADC_readResult(ADCERESULT_BASE, ADC_SOC_NUMBER0);

    AdcEcounter_U16++;
    Adc_Status = ADC_COMPLETED;

    ADC_clearInterruptStatus(ADCE_BASE, ADC_INT_NUMBER1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}