
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* STD_TYPES Standard types - Standard macros and type definitions */

//#include "Compiler.h"
// #include "Platform_Types.h"
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
typedef unsigned char       boolean;        /* for use with TRUE/FALSE      */
 
/* 8bit unsigned :  0 .. 255 [0X00 .. 0XFF]*/
/* [cover parentID={4269E5AB-7F28-4803-8D60-7B4EC91CB087}] uint8 [/cover] */
typedef unsigned char       uint8;
 
/* 16bit unsigned:  0..65535 [0x0000..0xFFFF]*/
/* [cover parentID={66E964CA-35D5-4013-BB61-1E824636D713}] uint16 [/cover] */
typedef unsigned short      uint16;
 
/* 32bit unsigned:  0..4294967295 [0x00000000..0xFFFFFFFF]*/
/* [cover parentID={DA33B7A0-7CD3-45e7-9C9A-6D63FB8BA3DC}] uint32 [/cover] */
typedef unsigned long       uint32;
 
/* 64bit unsigned
*          0..18446744073709551615   [0x0000000000000000..0xFFFFFFFFFFFFFFFF]*/
/* [cover parentID={3409E2A3-BF2D-44a5-9B00-A72300848166}] uint64 */
typedef unsigned long long  uint64;
 
typedef float               float32;        /* IEEE754-2008 single precision */
 
#define E_OK                    (0U) /**< Macro representing successful execution. */

#define E_NOT_OK                (1U) /**< Macro representing unsuccessful execution. */

#define STD_OFF                 (0) /**< Macro representing an off state. */

#define STD_ON                  (1U) /**< Macro representing an on state. */

#define STD_LOW                 (0U) /**< Macro representing a low state. */

#define STD_HIGH                (1U) /**< Macro representing a high state. */

#endif /* STD_TYPES_H_ */
