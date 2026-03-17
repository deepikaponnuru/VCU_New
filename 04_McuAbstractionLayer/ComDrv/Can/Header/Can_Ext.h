#ifndef CAN_EXT_H_
#define CAN_EXT_H_

#include "driverlib.h"
#include "device.h"
#include "inc/stw_types.h"
#include "inc/stw_dataTypes.h"
#include <string.h>

#define NUM_OF_MSG                      (4U)
#define MCAN_STD_ID_FILTER_NUM          (0U)
#define MCAN_EXT_ID_FILTER_NUM          (4U)
#define MCAN_FIFO_0_NUM                 (0U)
#define MCAN_FIFO_0_ELEM_SIZE           (MCAN_ELEM_SIZE_8BYTES)
#define MCAN_FIFO_1_NUM                 (0U)
#define MCAN_FIFO_1_WATERMARK           (0U)
#define MCAN_FIFO_1_ELEM_SIZE           (MCAN_ELEM_SIZE_8BYTES)
#define MCAN_RX_BUFF_NUM                (4U)
#define MCAN_RX_BUFF_ELEM_SIZE          (MCAN_ELEM_SIZE_8BYTES)
#define MCAN_TX_BUFF_SIZE               (NUM_OF_MSG)
#define MCAN_TX_FQ_SIZE                 (0U)
#define MCAN_TX_BUFF_ELEM_SIZE          (MCAN_ELEM_SIZE_8BYTES)
#define MCAN_TX_EVENT_SIZE              (0U)


#define MCAN_STD_ID_FILT_START_ADDR     (0x0U)
#define MCAN_EXT_ID_FILT_START_ADDR     (MCAN_STD_ID_FILT_START_ADDR + ((MCAN_STD_ID_FILTER_NUM * MCANSS_STD_ID_FILTER_SIZE_WORDS * 4U)))
#define MCAN_FIFO_0_START_ADDR          (MCAN_EXT_ID_FILT_START_ADDR + ((MCAN_EXT_ID_FILTER_NUM * MCANSS_EXT_ID_FILTER_SIZE_WORDS * 4U)))
#define MCAN_FIFO_1_START_ADDR          (MCAN_FIFO_0_START_ADDR + (4 * 4U * MCAN_FIFO_0_NUM))
#define MCAN_RX_BUFF_START_ADDR         (MCAN_FIFO_1_START_ADDR + (4 * 4U * MCAN_FIFO_1_NUM))
#define MCAN_TX_BUFF_START_ADDR         (MCAN_RX_BUFF_START_ADDR + (4 * 4U * MCAN_RX_BUFF_NUM))
#define MCAN_TX_EVENT_START_ADDR        (MCAN_TX_BUFF_START_ADDR + 4 * 4U * (MCAN_TX_BUFF_SIZE + MCAN_TX_FQ_SIZE))
typedef struct
{
MCAN_InitParams            initParams;
MCAN_MsgRAMConfigParams    msgRAMConfigParams;
MCAN_BitTimingParams       bitTimes;
}Can_ConfigType;
void can_Transmit(void);
void can_Init(void);
void can_Transmit(void);

#endif
