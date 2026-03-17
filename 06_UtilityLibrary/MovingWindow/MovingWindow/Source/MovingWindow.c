/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2018 Atharva Embedded Ingenious Systems Pvt. Ltd. - All Rights Reserved.

Module Name: MovingWindow

File Name  : MovingWindow.c

Description: This is the MovingWindow source file.

Version    : 1.0

Date       : 23/10/2025 

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------- Include Section -----------------------------------------------------------------*/
#include "MovingWindow_Int.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void MovingWindow_Init(void)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : MovingWindow_Init

Description     : This function initializes the internal variables 

In Parameter    : N/A

Out Parameter   : N/A

In-Out Parameter: N/A

Return          : void 
  			  
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{

}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void MovingWindow1D(uint32 *MovingWindow_FaultBuffer_a, uint16 MovingWindow_FaultBufferSize_u8, uint8 *MovingWindow_FaultWriteIndex_u8,
	 boolean MovingWindow_FaultReportIn_b,boolean *MovingWindow_FaultStatusOut_b,uint8 MovingWindow_FaultCountThd_u8)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------

Function Name   : MovingWindow1D

Description     : This function  monitors the data and returns the status if the event is qualified or not.

In Parameter    : MovingWindow_FaultBufferSize_u8,MovingWindow_FaultReportIn_b,MovingWindow_FaultCountThd_u8.

Out Parameter   : N/A

In-Out Parameter: MovingWindow_FaultBuffer_a,MovingWindow_FaultWriteIndex_u8,MovingWindow_FaultStatusOut_b.

Return          : void 
  			  
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
	/* Local variable declaration */
	uint8 MovingWindow_Index_u8;
    uint8 MovingWindow_FaultCounter_u8 = 0;
	
	/* Write fault status to fault buffer */
    MovingWindow_FaultBuffer_a[*MovingWindow_FaultWriteIndex_u8] = MovingWindow_FaultReportIn_b;
	
    /* Move Window in circular fashion */
    *MovingWindow_FaultWriteIndex_u8 = (*MovingWindow_FaultWriteIndex_u8 + 1) % MovingWindow_FaultBufferSize_u8;

	/* Count number of set bits in fault buffer */ 
    for (MovingWindow_Index_u8 = 0; MovingWindow_Index_u8 < MovingWindow_FaultBufferSize_u8; MovingWindow_Index_u8++)
	{
        if (MovingWindow_FaultBuffer_a[MovingWindow_Index_u8] == 1)
		{
			/* Increment the count */
            MovingWindow_FaultCounter_u8++;
        }
    }
     /* Set MovingWindow_FaultStatusOut_b if threshold reached */     
	if(MovingWindow_FaultCounter_u8 >= MovingWindow_FaultCountThd_u8)
		*MovingWindow_FaultStatusOut_b = TRUE;
	else
		*MovingWindow_FaultStatusOut_b = FALSE;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
void MovingWindow2D(uint16 MovingWindow_SensorSize_u8,uint16 MovingWindow_FaultBufferSize_u8 ,uint32 MovingWindow_FaultBuffer_a[MovingWindow_SensorSize_u8][MovingWindow_FaultBufferSize_u8],
	 uint8 MovingWindow_FaultSensorIndex_u8,uint8 *MovingWindow_FaultWriteIndex_u8,boolean MovingWindow_FaultReportIn_b,boolean *MovingWindow_FaultStatusOut_b,uint8 MovingWindow_FaultCountThd_u8)
/*---------------------------------------------------------------------------------------------------------------------------------------------------------
Function Name   : MovingWindow2D

Description     : ( Moving window for senosrs in loop monitoring)
				  This function  monitors the data and returns the status if the event is qualified or not.

In Parameter    : MovingWindow_FaultSensorIndex_u8,MovingWindow_FaultReportIn_b,MovingWindow_FaultCountThd_u8.

Out Parameter   : N/A

In-Out Parameter: MovingWindow_FaultBuffer_a,MovingWindow_FaultWriteIndex_u8,MovingWindow_FaultStatusOut_b.

Return          : void 
  			  
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
{
	/* Local variable declaration */
	uint8 MovingWindow_Index_u8;
    uint8 MovingWindow_FaultCounter_u8 = 0;
	
	/* Write fault status to fault buffer */   
    MovingWindow_FaultBuffer_a[MovingWindow_FaultSensorIndex_u8][*MovingWindow_FaultWriteIndex_u8] = MovingWindow_FaultReportIn_b ? 1 : 0;

    /* Move Window in circular fashion */
    *MovingWindow_FaultWriteIndex_u8 = (*MovingWindow_FaultWriteIndex_u8 + 1) % MovingWindow_FaultBufferSize_u8;

    /* Count number of set bits in fault buffer */ 
    for ( MovingWindow_Index_u8 = 0; MovingWindow_Index_u8 < MovingWindow_FaultBufferSize_u8; MovingWindow_Index_u8++)
    {
        if (MovingWindow_FaultBuffer_a[MovingWindow_FaultSensorIndex_u8][MovingWindow_Index_u8] == 1)
		{
			/* Increment the count */
            MovingWindow_FaultCounter_u8++;
		}
    }

    /* Set MovingWindow_FaultStatusOut_b if threshold reached */
	if(MovingWindow_FaultCounter_u8 >= MovingWindow_FaultCountThd_u8)
		*MovingWindow_FaultStatusOut_b = TRUE;
	else
		*MovingWindow_FaultStatusOut_b = FALSE;
}
