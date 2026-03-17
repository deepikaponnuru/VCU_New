/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2018 iSyriuS engineering Germany Pvt. Ltd. - All Rights Reserved.

Module Name: HazardM manager

File Name  : HazardM.c

Description: This is the HazardM manager source file.

Version    : 1.0

Date       : 08/01/2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------- Include Section -----------------------------------------------------------------*/
#include "HazardM_Int.h"

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
uint8 HazardM_HazardMStatusDigIn_E = HazardM_DISABLE;
uint16 HazardM_BlinkCounter = 0u;
uint8  HazardM_BlinkState   = 0u;
eHazardM_HazardManagerState HazardM_HazardMode = eHazardM_Disable;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void HazardM_Init(void)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : HazardM_Init

Description     : This function initializes the internal variables

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{

}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void HazardM_Proc10ms(void)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : HazardM_Proc10ms

Description     :

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    /* TO DO : Get Hazard Button status from Dio(Yet to implement) */
    HazardM_HazardMStatusDigIn_E = IoHwDio_Read(eIoHwDio_Dig4DIN);
    /* When Hazard Button Status is Enabled */
    if(HazardM_HazardMStatusDigIn_E == HazardM_ENABLE)
    {
        HazardM_HazardMode = eHazardM_Enable;
        HazardM_BlinkCounter++;

        if(HazardM_BlinkCounter >= HazardM_FREQ_1_67HZ)
        {
            HazardM_BlinkCounter -= HazardM_FREQ_1_67HZ;
            HazardM_BlinkState ^= 1u;
        }
        /* TO DO : Left and right blinker On for Continuous with 1.5Hz Frequency */
        IoHwDio_Write(eIoHwDio_Hs4_DOUT,  HazardM_BlinkState);
        IoHwDio_Write(eIoHwDio_Hs6_DOUT,  HazardM_BlinkState);

    }
    /* When Hazard Button Status is Disabled */
    else if((HazardM_HazardMStatusDigIn_E == HazardM_DISABLE) && (HazardM_HazardMode == HazardM_ENABLE))
    {
        HazardM_BlinkCounter = 0u;
        HazardM_BlinkState   = 0u;
        IoHwDio_Write(eIoHwDio_Hs4_DOUT,  HazardM_BlinkState);
        IoHwDio_Write(eIoHwDio_Hs6_DOUT,  HazardM_BlinkState);
        HazardM_HazardMode = eHazardM_Disable;
    }

}


/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void HazardM_SetHazardMState(eHazardM_HazardManagerState HazardMState_E)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : HazardM_IsSensorErrorSet

Description     : This function returns True if error is set else return False .

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : boolean

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    HazardM_HazardMStatusDigIn_E = HazardMState_E;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
eHazardM_HazardManagerState HazardM_GetHazardManagerState(void)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : HazardM_GetHazardManagerState

Description     : This function returns HazardManagerState.

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : eHazardM_HazardManagerState

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    return HazardM_HazardMode;
}



