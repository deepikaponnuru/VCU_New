/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : Port Input Output Configuration

File Name   : Port.c

Description : This is the Port source file.

Version     : 1.0

Date        : 23 January 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------- Include Section -----------------------------------------------------------------*/
#include "Port_Int.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------ Global Variable Definitions ----------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-------------------------------------------------------------- Static Global Variable Definitions -------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void Port_Init(void)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Function Name   : Port_Init

Description     : Initializes all configured port pins based on the port and pin configuration structure.
                  This function sets the direction, mode (digital or analog), pad driver, and initial state
                  for each pin according to the configuration defined in PortConfigAll.

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    uint16_t i;
    const Port_PinConfigStruct_t  *Port_Config_s  = &Port_PinConfig_S;
    

    for(i = 0; i < PORT_NUMBER_OF_PINS; i++)
    {
        /* Pin multiplexing */
        GPIO_setPinConfig(Port_Config_s[i].pinConfig);

        /* Pad configuration */
        GPIO_setPadConfig(Port_Config_s[i].idx, Port_Config_s[i].pintype);

        /* Direction */
        GPIO_setDirectionMode(Port_Config_s[i].idx, Port_Config_s[i].direction);

        /* Initial output state */
        if(Port_Config_s[i].direction == GPIO_DIR_MODE_OUT)
        {
            GPIO_writePin(Port_Config_s[i].idx, Port_Config_s[i].state);
        }
        if(Port_Config_s[i].direction == GPIO_DIR_MODE_OUT)
        {
            GPIO_setQualificationMode(Port_Config_s[i].idx, GPIO_QUAL_SYNC); 
        }
    }
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


