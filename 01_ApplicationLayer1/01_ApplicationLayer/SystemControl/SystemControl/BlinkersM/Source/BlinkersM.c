/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2018 iSyriuS engineering Germany Pvt. Ltd. - All Rights Reserved.

Module Name: Blinkers manager

File Name  : BlinkersM.c

Description: This is the Blinkers manager source file.

Version    : 1.0

Date       : 07/01/2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
// uint32_t eIoHwDio_Hs7_DOUT =0;
/*----------------------------------------------------------------------- Include Section -----------------------------------------------------------------*/
#include "BlinkersM_Int.h"

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
uint8 HighBeamM_HighBeamStatusDigIn_E      = IoHwDio_LOW;
uint8 PassingBeamSwitchStatusDigIn_U8 = 0U;
float32 HighBeamM_PassingBeamPressTimer_F32 = 0.0F;
eHighBeamM_HighBeamManagerState HighBeamM_HighBeamMState_E = eHighBeamM_Disable;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void BlinkersM_Init(void)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : BlinkersM_Init

Description     : This function initializes the internal variables

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void BlinkersM_Proc10ms(void)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : BlinkersM_Proc10ms

Description     : This function is called for every 10ms.

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
 
    /* TO DO : Get High Beam status from Dio(Yet to implement)  */
    HighBeamM_HighBeamStatusDigIn_E = IoHwDio_Read(eIoHwDio_Dig1DIN);

    /* TO DO : Get Passing Beam status from Dio(Yet to implement)  */
    PassingBeamSwitchStatusDigIn_U8 = IoHwDio_Read(eIoHwDio_Dig17DIN);

    if(PassingBeamSwitchStatusDigIn_U8 == IoHwDio_HIGH)
    {
        HighBeamM_PassingBeamPressTimer_F32 += HighBeamM_SAMPLINGRATE;
    }
    else if(PassingBeamSwitchStatusDigIn_U8 == IoHwDio_LOW)
    {
        HighBeamM_PassingBeamPressTimer_F32 = 0.0;
    }

    /* When HighBeamStatusDigIn_E is Enabled or PassingBeamSwitch is pressed more than Threshold */
    if((HighBeamM_HighBeamStatusDigIn_E == IoHwDio_HIGH) || (HighBeamM_PassingBeamPressTimer_F32 > HighBeamM_HIGHBEAM_PRESS_THRESHOLD))
    {
        /* TO DO : High Beam = ON ==> HighBeamActuatorDigOut = On*/
        IoHwDio_Write(eIoHwDio_Hs2_DOUT,  1);
        HighBeamM_HighBeamMState_E = eHighBeamM_Enable;

    }
    /* When HighBeamStatusDigIn_E is Disabled and PassingBeamSwitch is Not pressed */
    else if((HighBeamM_HighBeamStatusDigIn_E == IoHwDio_LOW) && (PassingBeamSwitchStatusDigIn_U8 == IoHwDio_LOW))
    {
        /* TO DO : High Beam = OFF ==> HighBeamActuatorDigOut = OFF*/
        IoHwDio_Write(eIoHwDio_Hs2_DOUT,  0);
        HighBeamM_HighBeamMState_E = eHighBeamM_Disable;
    }

    /*   DRLActuatorDigOut = ON */
    IoHwDio_Write(eIoHwDio_Hs3_DOUT,  1);

}


/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void HighBeamM_SetHighBeamMState(eHighBeamM_HighBeamManagerState HighBeamMState_E)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : HighBeamM_IsSensorErrorSet

Description     : This function returns True if error is set else return False .

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : boolean

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    HighBeamM_HighBeamMState_E = HighBeamMState_E;
}


/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
eHighBeamM_HighBeamManagerState HighBeamM_GetHighBeamManagerState(void)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : HighBeamM_GetHighBeamManagerState

Description     : This function returns HighBeamManagerState.

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : eHighBeamM_HighBeamManagerState

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    return HighBeamM_HighBeamMState_E;
}
