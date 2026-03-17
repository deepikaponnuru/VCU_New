/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (c) 2018 iSyriuS engineering Germany Pvt. Ltd. - All Rights Reserved.

Module Name : GlobalHeader

File Name   : GlobalHeader.h

Description : This is the GlobalHeader public header.

Version     : 1.0

Date        : 27/11/2025  laxmi
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

#ifndef _GLOBAL_HEADER_H_
#define _GLOBAL_HEADER_H_

#include <stdint.h>


/*------------------------------------------------------------------ Configurable Global Macros -----------------------------------------------------------*/

//#define GlobalHeader_TOT_NUM_OF_TANKS (8U)

/* ENUM of all sensor IDs */
typedef enum
{
    eThrottleSens_1 = 0U, /* Valve 1 pressure ID */
    eThrottleSens_2,     /* Valve 2 pressure ID */
    eValvePres_3,     /* Valve 3 pressure ID */
    eValvePres_4,     /* Valve 4 pressure ID */
    eValvePres_5,     /* Valve 5 pressure ID */
    eValvePres_6,     /* Valve 6 pressure ID */
    eValvePres_7,     /* Valve 7 pressure ID */
    eValvePres_8,     /* Valve 8 pressure ID */
    eHighPres,        /* High pressure ID */
    eValveTemp_1,     /* Valve 1 Temperature ID */
    eValveTemp_2,     /* Valve 2 Temperature ID */
    eValveTemp_3,     /* Valve 3 Temperature ID */
    eValveTemp_4,     /* Valve 4 Temperature ID */
    eValveTemp_5,     /* Valve 5 Temperature ID */
    eValveTemp_6,     /* Valve 6 Temperature ID */
    eValveTemp_7,     /* Valve 7 Temperature ID */
    eValveTemp_8,     /* Valve 8 Temperature ID */
    ePcbTemp,         /* PCB Temperature ID */
    eCurrFbHs_1, /* HS1 current feedback ID */
    eCurrFbHs_2,
    eCurrFbHs_3,
    eCurrFbHs_4,
    eCurrFbHs_5, /* HS2 current feedback ID */
    eCurrFbHs_6,
    eCurrFbHs_7,
    eCurrFbHs_8,
    eDcVoltSens_1, /* DC volt sensor 1 ID */
    eDcVoltSens_2, /* DC volt sensor 2 ID */
    eLDOSense  ,    /* LDO sense ID */
    Adc_trigger  /*Adc Trigger */
} SensorId_E;

/* GLOBAL VARIABLES (extern) */
extern SensorId_E Sensor_ID_E;
extern uint32_t GlobalHeader_ToHighErrorBit_U32;
extern uint32_t GlobalHeader_ToLowErrorBit_U32;
extern uint32_t GlobalHeader_PlausiErrorBit_U32;
//extern const uint8_t PressureSensorId_A[GlobalHeader_TOT_NUM_OF_TANKS];
//extern const uint8_t TemperatureSensorId_A[GlobalHeader_TOT_NUM_OF_TANKS];
//extern const uint8_t CurrentFBSensorId_A[GlobalHeader_TOT_NUM_OF_TANKS];

#endif /* _GLOBAL_HEADER_H_ */

