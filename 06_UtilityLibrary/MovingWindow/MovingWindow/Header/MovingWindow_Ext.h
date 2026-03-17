/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2018 Atharva Embedded Ingenious Systems Pvt. Ltd. - All Rights Reserved.

Module Name: Moving window external file

File Name  : MovingWindow_Ext.h

Description: This is the MovingWindow public header.

Version    : 1.0

Date       : 23/10/2025

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/




#ifndef _MOVING_WINDOW_EXT_H_
#define _MOVING_WINDOW_EXT_H_



/*------------------------------------------------------------------ Standard Types Include ---------------------------------------------------------------*/
#include "Std_Types.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------ Configurable Global Macros -----------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*--------------------------------------------------------------------- Static Global Macros --------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*----------------------------------------------------------------------- Global Typedefs -----------------------------------------------------------------*/



/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*------------------------------------------------------------- Global Variables Declaration --------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*------------------------------------------------------- Global Interface Functions Declaration ----------------------------------------------------------*/
void MovingWindow_Init(void);
void MovingWindow1D(uint32 *MovingWindow_FaultBuffer_a,uint16 MovingWindow_FaultBufferSize_u8,uint8 *MovingWindow_FaultWriteIndex_u8,
					boolean MovingWindow_FaultReportIn_b,boolean *MovingWindow_FaultStatusOut_b,uint8 MovingWindow_FaultCountThd_u8);
void MovingWindow2D(uint16 MovingWindow_SensorSize_u8,uint16 MovingWindow_FaultBufferSize_u8 ,uint32 MovingWindow_FaultBuffer_a[MovingWindow_SensorSize_u8][MovingWindow_FaultBufferSize_u8],
					uint8 MovingWindow_FaultSensorIndex_u8,uint8 *MovingWindow_FaultWriteIndex_u8,boolean MovingWindow_FaultReportIn_b,boolean *MovingWindow_FaultStatusOut_b,uint8 MovingWindow_FaultCountThd_u8);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/



#endif    /* _VALVE_PRESMON_EXT_H_ */

