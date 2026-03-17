/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2018 Atharva Embedded Ingenious Systems Pvt. Ltd. - All Rights Reserved.

Module Name : Look up table

File Name   : LookUpTable.c

Description : This is the LookUpTable source file.

Version     : 1.0

Date        : 15 October 2025
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------- Include Section -----------------------------------------------------------------*/
#include "LookUpTable_Int.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void LookUpTable_Init(void)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : LookUpTable_Init

Description     : This function initializes the internal variables 

In Parameter    : void

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void 
  			              
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
	
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
float LookUpTable_GetLookUpTableValue( const float *xTable,const float *yTable,int TableSize,float RawValue)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : LookUpTable_GetLookUpTableValue

Description     : This function returns the  calculated physical value to the caller function

In Parameter    : xTable,yTable,TableSize,RawValue

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void 
  			  
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
    float x0 = 0.0F;
    float x1 = 0.0F;
    float y0 = 0.0F;
    float y1 = 0.0F;
	 /* Safety checks */
    if (xTable == '\0' || yTable == '\0' || TableSize < 2)
        return -1;

    /* Check if RawValue exactly matches a table point */
    if (RawValue == xTable[0])
        return yTable[0];
    if (RawValue == xTable[TableSize - 1])
        return yTable[TableSize - 1];

    int i=0;

    /* Find interval for interpolation */
    for (i = 0; i < TableSize - 1; i++)
    {

        if (RawValue >= xTable[i] && RawValue <= xTable[i + 1])
        {
            x0 = xTable[i];
            x1 = xTable[i + 1];
            y0 = yTable[i];
            y1 = yTable[i + 1];

            /* Linear interpolation */
            return y0 + ((RawValue - x0) * (y1 - y0)) / (x1 - x0);
        }
    }

    /* Should never reach here */
    return -1;
}

		

