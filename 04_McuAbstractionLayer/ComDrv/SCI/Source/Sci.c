#include "Sci_Int.h"

uint16_t count = 0;
uint16_t rxIndex=0;
char rxData[5]={0};
char txData[6]="hello";

void Uart_Init(void)
{
    GPIO_setPinConfig(GPIO_10_SCIB_TX);
    GPIO_setPinConfig(GPIO_11_SCIB_RX);

    GPIO_setDirectionMode(10, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(11, GPIO_DIR_MODE_IN);

    GPIO_setPadConfig(10, GPIO_PIN_TYPE_STD);
    GPIO_setPadConfig(11, GPIO_PIN_TYPE_STD);

    SCI_performSoftwareReset(SCIB_BASE);

    SCI_setConfig(SCIB_BASE, DEVICE_LSPCLK_FREQ, 9600, (SCI_CONFIG_WLEN_8 |
                                                         SCI_CONFIG_STOP_ONE |
                                                         SCI_CONFIG_PAR_NONE));

    SCI_enableFIFO(SCIB_BASE);

    SCI_resetChannels(SCIB_BASE);
    SCI_resetTxFIFO(SCIB_BASE);
    SCI_resetRxFIFO(SCIB_BASE);

    SCI_setFIFOInterruptLevel(SCIB_BASE, SCI_FIFO_TX0, SCI_FIFO_RX1);

    SCI_enableInterrupt(SCIB_BASE, SCI_INT_RXFF);

    Interrupt_register(INT_SCIB_RX, &Uart_RxISR);

    Interrupt_enable(INT_SCIB_RX);

    SCI_enableModule(SCIB_BASE);
    
}

uint32_t i=0;
void Uart_Transmit(void)
{
    for(i=0;i<5;i++)
    {
        SCI_writeCharBlockingFIFO(SCIB_BASE, txData[i]);
        
    }
}

uint32_t data ;
uint32_t j;
__interrupt void Uart_RxISR(void)
{
    count++;
    uint32_t length = SCI_getRxFIFOStatus(SCIB_BASE);
    for(j = 0; j < 5 ; j++)
    {
        data = SCI_readCharBlockingFIFO(SCIB_BASE);
        rxData[j] = data;
    }
    SCI_clearInterruptStatus(SCIB_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}












// __interrupt void Uart_RxISR(void)
// {
//     count++;

//         char data = SCI_readCharBlockingFIFO(SCIB_BASE);
//         rxData[rxIndex++] = data;
//         SCI_clearInterruptStatus(SCIB_BASE, SCI_INT_RXFF);
//         Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
// }

  




























