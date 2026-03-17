/*-----------------------------------------------------------------------------------------------------------------------------------------------------------

Copyright (c) 2026 iSyriuS Engineering GmbH, Germany - All Rights Reserved.

Module Name : Port Input Output Configuration

File Name   : Port_Int.h

Description : This is the Port private header.

Version     : 1.0

Date        : 23 January 2026

-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef PORT_INT_H_
#define PORT_INT_H_

/*------------------------------------------------------------- Import Module Include Section -------------------------------------------------------------*/
#include "Port_Ext.h"
/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define PORT_NUMBER_OF_PINS 24

/*------------------------------------------------------------------------ Local Macros -------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------- Local Typedefs ------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------Static Global Variable Definitions -------------------------------------------------------------*/


/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++ Configuration +++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* Array holding the configuration for each individual pin, including direction, pintype, output state settings  */
static const Port_PinConfigStruct_t Port_PinConfig_S[PORT_NUMBER_OF_PINS] = {

     [0] =
        {/* GPIO28 =  Dig8*/
            .idx = 28,
            .pinConfig = GPIO_28_GPIO28,
            .direction = GPIO_DIR_MODE_IN,
            .pintype =  PIO_PIN_TYPE_PULLUP,
            
        },

    [1] =
        {/* GPIO21 = Dig1 */
         .idx = 21,
         .pinConfig = GPIO_21_GPIO21,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_STD,
         },

    [2] =
        {/* GPIO24 = Dig4 */
         .idx = 24,
         .pinConfig = GPIO_24_GPIO24,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_STD,
         },

    [3] =
        {/* GPIO25 = Dig5 */
         .idx = 25,
         .pinConfig = GPIO_25_GPIO25,
         .direction = GPIO_DIR_MODE_IN,
         .pintype =  PIO_PIN_TYPE_PULLUP,
        },

    [4] =
        {/* GPIO26 = Dig6 */
         .idx = 26,
         .pinConfig = GPIO_26_GPIO26,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_PULLUP,
         },

    [5] =
        {/* GPIO27 =Dig7 */
         .idx = 27,
         .pinConfig = GPIO_27_GPIO27,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_PULLUP,
         },

    [6] =
        {/* GPIO8 = Dig18 */
         .idx = 8,
         .pinConfig = GPIO_8_GPIO8,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_STD,
        },

    [7] =
        {/* GPIO23 = Dig3 */
         .idx = 23,
         .pinConfig = GPIO_23_GPIO23,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_PULLUP,
        },

    [8] =
        {/* GPIO22 = Dig2 */
         .idx = 22,
         .pinConfig = GPIO_22_GPIO22,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_STD,
        },

    [9] =
        {/* GPIO7 = Dig17 */
         .idx = 7,
         .pinConfig = GPIO_7_GPIO7,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_PULLUP,
        },

    [10] =
        {/* GPIO31 = Dig10 */
         .idx = 31,
         .pinConfig = GPIO_31_GPIO31,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_PULLUP,
        },

    [11] =
        {/* GPIO29 = Dig9 */
         .idx = 29,
         .pinConfig = GPIO_29_GPIO29,
         .direction = GPIO_DIR_MODE_IN,
         .pintype = PIO_PIN_TYPE_PULLUP,
         
        },

    [12] =
        {/* GPIO13 = Hs3 */
         .idx = 13,
         .pinConfig = GPIO_13_GPIO13,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [13] =
        {/* GPIO12 = Hs2 */
         .idx = 12,
         .pinConfig = GPIO_12_GPIO12,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [14] =
        {/* GPIO11 = HsI1 */
         .idx = 11,
         .pinConfig = GPIO_11_GPIO11,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [15] =
        {/* GPIO16 = Hs15 */
         .idx = 16,
         .pinConfig = GPIO_16_GPIO16,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [16] =
        {/* GPIO16 = Hs16 */
         .idx = 17,
         .pinConfig = GPIO_17_GPIO17,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [17] =
        {/* GPIO4 = Hs12 */
         .idx = 4,
         .pinConfig = GPIO_4_GPIO4,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [18] =
        {/* GPIO40 = Hs11 */
         .idx = 40,
         .pinConfig = GPIO_40_GPIO40,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [19] =
        {/* GPIO41 = Hs10 */
         .idx = 41,
         .pinConfig = GPIO_41_GPIO41,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [20] =
        {/* GPIO44 = Hs9 */
         .idx = 44,
         .pinConfig = GPIO_44_GPIO44,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [21] =
        {/* GPIO9 = Hs8 */
         .idx = 9,
         .pinConfig = GPIO_9_GPIO9,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [22] =
        {/* GPIO10 = Hs6 */
         .idx = 10,
         .pinConfig = GPIO_10_GPIO10,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        },

    [23] =
        {/* GPIO34 = Hs4 */
         .idx = 34,
         .pinConfig = GPIO_34_GPIO34,
         .direction = GPIO_DIR_MODE_OUT,
         .pintype = PIO_PIN_TYPE_STD,
         .state = PIN_STATE_LOW
        }
};

#endif
