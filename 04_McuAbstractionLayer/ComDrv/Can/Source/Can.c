#include "Can_Int.h"
int32_t error = 0;
MCAN_RxBufElement rxMsg[NUM_OF_MSG], rxMsg1;
MCAN_TxBufElement txMsg[NUM_OF_MSG];
MCAN_RxFIFOStatus RxFS;
int32_t loopCnt = 0U;
uint32_t  flagtx=0;
uint32_t intrStatus=0;
uint16_t flag=0;

MCAN_RxNewDataStatus newData;
__interrupt void MCANIntr1ISR_Tx(void);
static void MCANIntrConfig(void);
__interrupt void MCANIntr1ISR(void);

void can_Frame(void)
{
    uint32_t i=0,dataBytes=8;
     for(loopCnt=0;loopCnt<NUM_OF_MSG;loopCnt++)
        {
       
            txMsg[loopCnt].id       = ((loopCnt + 1536) <<18U ) ;
            txMsg[loopCnt].rtr      = 0U;
            txMsg[loopCnt].xtd      = 0U;
            txMsg[loopCnt].esi      = 0U;
            txMsg[loopCnt].dlc      = 8U;
            txMsg[loopCnt].brs      = 0U;
            txMsg[loopCnt].fdf      = 0U;
            txMsg[loopCnt].efc      = 1U;
            txMsg[loopCnt].mm       = 0xAAU;
            txMsg[loopCnt].data[i]  = 0x1;
            for(i = 1; i < dataBytes; i++)
            {
                txMsg[loopCnt].data[i]  = txMsg[loopCnt].data[i-1] + 1;
            }
             
        }
        



}
void can_Transmit(void)
{
    
    for(loopCnt=0;loopCnt<NUM_OF_MSG;loopCnt++)
        {
            MCAN_writeMsgRam(MCANA_DRIVER_BASE, MCAN_MEM_TYPE_BUF, loopCnt,
                        &txMsg[loopCnt]);
            MCAN_txBufAddReq(MCANA_DRIVER_BASE, loopCnt);
            
            
        }
    
}

static void MCANConfig(void)
{
    const Can_ConfigType* Can_Config_s = &can_Config;
    const MCAN_ExtMsgIDFilterElement* Can_ExtdFiltConfig_s = &Can_FiltEle;
    uint32_t i=0;
    while(FALSE == MCAN_isMemInitDone(MCANA_DRIVER_BASE))
    {
    }
    MCAN_setOpMode(MCANA_DRIVER_BASE, MCAN_OPERATION_MODE_SW_INIT);

    while (MCAN_OPERATION_MODE_SW_INIT != MCAN_getOpMode(MCANA_DRIVER_BASE))
    {}

    MCAN_init(MCANA_DRIVER_BASE, &Can_Config_s->initParams);
    MCAN_setBitTime(MCANA_DRIVER_BASE, &Can_Config_s->bitTimes);
    MCAN_msgRAMConfig(MCANA_DRIVER_BASE, &Can_Config_s->msgRAMConfigParams);

    for(i=0; i <NUM_OF_MSG ;i++)
    {
        MCAN_addExtMsgIDFilter(MCANA_DRIVER_BASE, i, &Can_ExtdFiltConfig_s[i]);
    }
    MCAN_setOpMode(MCANA_DRIVER_BASE, MCAN_OPERATION_MODE_NORMAL);

}
void can_Init(void)
 {
    int i = 0;
    volatile uint32_t mode = 0U;
    uint32_t dataBytes = 8;

    SysCtl_setMCANClk(SYSCTL_MCANA, SYSCTL_MCANCLK_DIV_5);

    MCANIntrConfig();
    GPIO_setPinConfig(GPIO_5_MCANA_RX);
    GPIO_setPinConfig(GPIO_4_MCANA_TX);
    for(loopCnt =0; loopCnt<NUM_OF_MSG;loopCnt++)
    {
        rxMsg[loopCnt].id = 0U;
        rxMsg[loopCnt].rtr = 0U;
        rxMsg[loopCnt].xtd = 1U;
        rxMsg[loopCnt].esi = 0U;
        rxMsg[loopCnt].rxts = 0U;
        rxMsg[loopCnt].dlc = 0U;
        rxMsg[loopCnt].brs = 0U;
        rxMsg[loopCnt].fdf = 0U;
        rxMsg[loopCnt].fidx = 0U;
        rxMsg[loopCnt].anmf = 0U;
        for(i = 0; i < dataBytes; i++)
        {
            rxMsg[loopCnt].data[i]  = 0;
        }

    }
    
    can_Frame();
    MCANConfig();
   
    MCAN_enableIntr(MCANA_DRIVER_BASE, MCAN_INTR_MASK_ALL, 1U);
    MCAN_selectIntrLine(MCANA_DRIVER_BASE, MCAN_INTR_MASK_ALL, MCAN_INTR_LINE_NUM_1);
    MCAN_enableIntrLine(MCANA_DRIVER_BASE, MCAN_INTR_LINE_NUM_1, 1U);

    // MCANIntrConfig_Tx();
    // MCAN_enableIntr(MCANA_DRIVER_BASE, MCAN_INTR_MASK_ALL, 1U);
    // MCAN_selectIntrLine(MCANA_DRIVER_BASE, MCAN_INTR_MASK_ALL, MCAN_INTR_LINE_NUM_0);
    // MCAN_enableIntrLine(MCANA_DRIVER_BASE, MCAN_INTR_LINE_NUM_0, 1U);
     
}

static void MCANIntrConfig(void)
{
    Interrupt_register(INT_MCANA_1,&MCANIntr1ISR);
    Interrupt_enable(INT_MCANA_1);
    Interrupt_enableGlobal();

}
// This is Interrupt Service Routine for MCAN interrupt 1.
__interrupt void MCANIntr1ISR(void)
{
   
    uint8_t i=0;
   

    intrStatus = MCAN_getIntrStatus(MCANA_DRIVER_BASE);

    //
    // Clear the interrupt Status.
    //
      MCAN_clearIntrStatus(MCANA_DRIVER_BASE, intrStatus);

    
    //  Clearing the interrupt lineNum
    
   MCAN_clearInterrupt(MCANA_DRIVER_BASE, 0x2);

    //
    //  Check to see if the interrupt is caused by a message being
    //  received in dedicated RX Buffers
    //
    if((MCAN_IR_DRX_MASK & intrStatus) == MCAN_IR_DRX_MASK)
    {
        //
        // Read the NewData registers
        //
        MCAN_getNewDataStatus(MCANA_DRIVER_BASE, &newData);
        for(i=0 ;i<1 ;i++ )
        {
            if((newData.statusLow & (1UL << i)) != 0)
            {
                MCAN_readMsgRam(MCANA_DRIVER_BASE, MCAN_MEM_TYPE_BUF, i,
                          0, &rxMsg[i]);
            }
        }

        MCAN_clearNewDataStatus(MCANA_DRIVER_BASE, &newData);
    }
    else
    {
        error++;
        //  Interrupt handling for other interrupt sources goes here
    }
    if(flagtx==1)
   {
    for(loopCnt=0;loopCnt<NUM_OF_MSG;loopCnt++)
        {
            MCAN_writeMsgRam(MCANA_DRIVER_BASE, MCAN_MEM_TYPE_BUF, loopCnt,
                        &txMsg[loopCnt]);
            for(i=0;i<10000;i++);
            MCAN_txBufAddReq(MCANA_DRIVER_BASE, loopCnt); 
             for(i=0;i<10000;i++); 
        }
        flagtx=0;

    }
    // Acknowledge this interrupt located in group 9
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}


