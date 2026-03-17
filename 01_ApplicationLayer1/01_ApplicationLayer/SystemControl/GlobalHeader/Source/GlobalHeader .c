/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2018 iSyriuS engineering Germany Pvt. Ltd. - All Rights Reserved.

Module Name : GlobalHeader

File Name   : GlobalHeader.c

Description : This is the GlobalHeader source file.

Version     : 1.0

Date        : 27/11/2025
-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "GlobalHeader.h"

/* ENUM VARIABLE */
SensorId_E Sensor_ID_E = eThrottleSens_1;

/* HIGH ERROR BIT FIELD */
uint32_t GlobalHeader_ToHighErrorBit_U32 = 0U;
/*
Bit - 0  (Valve pressure sensor 1 error bit)
Bit - 1  (Valve pressure sensor 2 error bit)
Bit - 2  (Valve pressure sensor 3 error bit)
Bit - 3  (Valve pressure sensor 4 error bit)
Bit - 4  (Valve pressure sensor 5 error bit)
Bit - 5  (Valve pressure sensor 6 error bit)
Bit - 6  (Valve pressure sensor 7 error bit)
Bit - 7  (Valve pressure sensor 8 error bit)
Bit - 8  (High pressure sensor error bit)
Bit - 9  (Valve Temperature sensor 1 error bit)
Bit - 10 (Valve Temperature sensor 2 error bit)
Bit - 11 (Valve Temperature sensor 3 error bit)
Bit - 12 (Valve Temperature sensor 4 error bit)
Bit - 13 (Valve Temperature sensor 5 error bit)
Bit - 14 (Valve Temperature sensor 6 error bit)
Bit - 15 (Valve Temperature sensor 7 error bit)
Bit - 16 (Valve Temperature sensor 8 error bit)
Bit - 17 (PCB Temperature sensor error bit)
Bit - 18 (HS1 current feedback sensor 1 error bit)
Bit - 19 (HS1 current feedback sensor 2 error bit)
Bit - 20 (HS1 current feedback sensor 3 error bit)
Bit - 21 (HS1 current feedback sensor 4 error bit)
Bit - 22 (HS2 current feedback sensor 1 error bit)
Bit - 23 (HS2 current feedback sensor 2 error bit)
Bit - 24 (HS2 current feedback sensor 3 error bit)
Bit - 25 (HS2 current feedback sensor 4 error bit)
Bit - 26 (DC volt sensor 1 error bit)
Bit - 27 (DC volt sensor 2 error bit)
Bit - 28 (LDO sensor error bit)
*/

/* LOW ERROR BIT FIELD */
uint32_t GlobalHeader_ToLowErrorBit_U32 = 0U;

/* PLAUSIBILITY ERROR BIT FIELD */
uint32_t GlobalHeader_PlausiErrorBit_U32 = 0U;
/*
Bit - 0  (Valve pressure sensor 1 error bit)
Bit - 1  (Valve pressure sensor 2 error bit)
Bit - 2  (Valve pressure sensor 3 error bit)
Bit - 3  (Valve pressure sensor 4 error bit)
Bit - 4  (Valve pressure sensor 5 error bit)
Bit - 5  (Valve pressure sensor 6 error bit)
Bit - 6  (Valve pressure sensor 7 error bit)
Bit - 7  (Valve pressure sensor 8 error bit)
Bit - 8  (High pressure sensor error bit)
Bit - 9  (Valve Temperature sensor 1 error bit)
Bit - 10 (Valve Temperature sensor 2 error bit)
Bit - 11 (Valve Temperature sensor 3 error bit)
Bit - 12 (Valve Temperature sensor 4 error bit)
Bit - 13 (Valve Temperature sensor 5 error bit)
Bit - 14 (Valve Temperature sensor 6 error bit)
Bit - 15 (Valve Temperature sensor 7 error bit)
Bit - 16 (Valve Temperature sensor 8 error bit)
Bit - 17 (PCB Temperature sensor error bit)
Bit - 18 (HS1 current feedback sensor 1 error bit)
Bit - 19 (HS1 current feedback sensor 2 error bit)
Bit - 20 (HS1 current feedback sensor 3 error bit)
Bit - 21 (HS1 current feedback sensor 4 error bit)
Bit - 22 (HS2 current feedback sensor 1 error bit)
Bit - 23 (HS2 current feedback sensor 2 error bit)
Bit - 24 (HS2 current feedback sensor 3 error bit)
Bit - 25 (HS2 current feedback sensor 4 error bit)
Bit - 26 (DC volt sensor 1 error bit)
Bit - 27 (DC volt sensor 2 error bit)
Bit - 28 (LDO sensor error bit)
*/

///* PRESSURE SENSOR ID ARRAY */
//const uint8_t PressureSensorId_A[GlobalHeader_TOT_NUM_OF_TANKS] =
//{
//     eValvePres_1, /* Valve 1 pressure ID */
//     eValvePres_2, /* Valve 2 pressure ID */
//     eValvePres_3, /* Valve 3 pressure ID */
//     eValvePres_4, /* Valve 4 pressure ID */
//     eValvePres_5, /* Valve 5 pressure ID */
//     eValvePres_6, /* Valve 6 pressure ID */
//     eValvePres_7, /* Valve 7 pressure ID */
//     eValvePres_8  /* Valve 8 pressure ID */
//};
//
///* TEMPERATURE SENSOR ID ARRAY */
//const uint8_t TemperatureSensorId_A[GlobalHeader_TOT_NUM_OF_TANKS] =
//{
//    eValveTemp_1, /* Valve 1 Temperature ID */
//    eValveTemp_2,
//    eValveTemp_3,
//    eValveTemp_4,
//    eValveTemp_5,
//    eValveTemp_6,
//    eValveTemp_7,
//    eValveTemp_8  /* Valve 8 Temperature ID */
//};
//
///* CURRENT FEEDBACK SENSOR ARRAY */
//const uint8_t CurrentFBSensorId_A[GlobalHeader_TOT_NUM_OF_TANKS] =
//{
//    eCurrFbHs_1, /* HS1 current feedback ID */
//    eCurrFbHs_2,
//    eCurrFbHs_3,
//    eCurrFbHs_4,
//    eCurrFbHs_5, /* HS2 current feedback ID */
//    eCurrFbHs_6,
//    eCurrFbHs_7,
//    eCurrFbHs_8
//};



