#ifndef CAN_INT_H_
#define CAN_INT_H_

#include "Can_Ext.h"

const Can_ConfigType can_Config=
{
    .initParams=
    {
        .fdMode         = 0x0U,
        .brsEnable      = 0x0U,
    },
    .msgRAMConfigParams=
    {
        .flesa          = MCAN_EXT_ID_FILT_START_ADDR,
        .lse            = MCAN_EXT_ID_FILTER_NUM,

        .txStartAddr          = MCAN_TX_BUFF_START_ADDR,
        .txBufNum             = MCAN_TX_BUFF_SIZE,
        .txBufMode            = 0U,
        .txBufElemSize        = MCAN_TX_BUFF_ELEM_SIZE,

        
        .rxBufStartAddr = MCAN_RX_BUFF_START_ADDR,
        .rxBufElemSize  = MCAN_RX_BUFF_ELEM_SIZE,
    },
    .bitTimes=
    {
        .nomRatePrescalar   = 0xBU, // Nominal Baud Rate Pre-scaler
        .nomTimeSeg1        = 0x2U, // Nominal Time segment before SP
        .nomTimeSeg2        = 0x0U,// Nominal Time segment after SP
        .nomSynchJumpWidth  = 0x0U, // Nominal SJW
        .dataRatePrescalar  = 0x1U, // Data Baud Rate Pre-scaler
        .dataTimeSeg1       = 0xAU, // Data Time segment before SP
        .dataTimeSeg2       = 0x2U, // Data Time segment after SP
        .dataSynchJumpWidth = 0x2U, // Data SJW
    }

};

const MCAN_ExtMsgIDFilterElement Can_FiltEle[NUM_OF_MSG]=
{
    [0]=
    {
        .efec   = 0x7U,
        .efid1  = 0x1U,
        .efid2  = 0x0U/*EFID2[28:6] → Filtering purpose (mask / range end / ID2) EFID2[5:0]  → RX Buffer index*/

    },
    [1] =
    {
        .efec   = 0x7U,
        .efid1  = 0x2U,
        .efid2  = 0x1U
    },
    [2] =
    {
        .efec   = 0x7U,
        .efid1  = 0x3U,
        .efid2  = 0x2U
    },
    [3] = 
    {
        .efec   = 0x7U,
        .efid1  = 0x4U,
        .efid2  = 0x3U
    }
};
#endif