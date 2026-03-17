/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : Digital Input Output Driver

File Name   : Dio_Ext.h

Description : This is the Dio public header.

Version     : 1.0

Date        : 27 January 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef DIO_EXT_H_
#define DIO_EXT_H_

/*------------------------------------------------------------------ Standard Types Include ---------------------------------------------------------------*/
#include "driverlib.h"
#include "device.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------- Global Typedefs -----------------------------------------------------------------*/
/* Type definition for DIO channel identifier  */
typedef uint16_t Dio_ChannelType;

/* Type definition for DIO signal level (HIGH or LOW) */
typedef uint16_t Dio_LevelType;

/*------------------------------------------------------------------ Configurable Global Macros -----------------------------------------------------------*/
#define STD_LOW   0U
#define STD_HIGH  1U

/*mapping*/
#define DIO_CH28  28
#define DIO_CH21  21
#define DIO_CH24  24
#define DIO_CH25  25
#define DIO_CH26  26
#define DIO_CH27  27
#define DIO_CH8   8
#define DIO_CH23  23
#define DIO_CH22  22
#define DIO_CH7   7
#define DIO_CH31  31
#define DIO_CH29  29

#define DIO_CH13  13
#define DIO_CH12  12
#define DIO_CH11  11
#define DIO_CH16  16
#define DIO_CH17  17
#define DIO_CH4   4
#define DIO_CH40  40
#define DIO_CH41  41
#define DIO_CH44  44
#define DIO_CH9   9
#define DIO_CH10  10
#define DIO_CH34  34






// #define DIO_CH24  24
// #define DIO_CH25  25
// #define DIO_CH26  26
// #define DIO_CH27  27

// #define DIO_CH28  28
// #define DIO_CH47  47
// #define DIO_CH48  48
// #define DIO_CH49  49
// #define DIO_CH50  50
// #define DIO_CH51  51
// #define DIO_CH52  52
// #define DIO_CH54  54
// #define DIO_CH228 228
// #define DIO_CH226 226
// #define DIO_CH253 253
// #define DIO_CH247 247
// #define DIO_CH55  55
// #define DIO_CH60  60
// #define DIO_CH21  21
// #define DIO_CH13  13
// #define DIO_CH12  12
// #define DIO_CH11  11
// #define DIO_CH16  16
// #define DIO_CH37  37
// #define DIO_CH56  56
// #define DIO_CH57  57
// #define DIO_CH58  58
// #define DIO_CH8   8
// #define DIO_CH4   4
// #define DIO_CH40  40
// #define DIO_CH23  23
// #define DIO_CH41  41
// #define DIO_CH22  22
// #define DIO_CH7   7
// #define DIO_CH44  44
// #define DIO_CH9   9
// #define DIO_CH61  61
// #define DIO_CH10  10
// #define DIO_CH34  34
// #define DIO_CH31  31
// #define DIO_CH29  29

/*------------------------------------------------------- Global Interface Functions Declaration ----------------------------------------------------------*/

/* Reads the level of a specified DIO channel */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* To write the Level to Digital ChannelId */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

#endif /* DIO_EXT_H_ */
