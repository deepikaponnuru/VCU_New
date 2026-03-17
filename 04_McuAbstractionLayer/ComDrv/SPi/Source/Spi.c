#include "Spi_Int.h"
uint16_t rxa=0;
uint16_t rxb=0;
uint16_t txa = 0x97;
uint16_t txb = 0x55;
uint16_t tx_isr=0;
void TransmitB(void)
{
    SPI_writeDataBlockingNonFIFO(SPIB_BASE,txb);
}
void readB(void)
{
   rxb = SPI_readDataBlockingNonFIFO(SPIB_BASE);
  
   
}
void TransmitA(void)
{
   
    SPI_writeDataBlockingFIFO(SPIA_BASE,txa);
    

}  
void readA(void)
{
   rxa = SPI_readDataBlockingFIFO(SPIB_BASE);
  
   
}

__interrupt void spiARxISR(void)
{
    rxa = SPI_readDataBlockingFIFO(SPIA_BASE);
    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
    // rxb = SPI_readDataBlockingNonFIFO(SPIB_BASE);
  
}

__interrupt void spiATxISR(void)
{
    //Keep TX FIFO filled to maintain clock
    if(SPI_getTxFIFOStatus(SPIA_BASE) < 16) // FIFO not full
    {
         SPI_writeDataBlockingFIFO(SPIA_BASE, txa);
         tx_isr++;
        
    }

    // Clear TX interrupt flag and acknowledge PIE group
    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}
void spi_Init()
{
    SPI_setConfig(SPIA_BASE,DEVICE_LSPCLK_FREQ,SPI_PROT_POL0PHA0,SPI_MODE_CONTROLLER,1000000U,16);
    SPI_enableFIFO(SPIA_BASE);
    SPI_setFIFOInterruptLevel(SPIA_BASE,
                              SPI_FIFO_TX1,
                              SPI_FIFO_RX1);
     SPI_clearInterruptStatus(SPIA_BASE,
                             SPI_INT_TXFF | SPI_INT_RXFF);
    SPI_enableModule(SPIA_BASE);
    SPI_enableInterrupt(SPIA_BASE,
                          SPI_INT_TXFF | SPI_INT_RXFF);  

}
void spi_InitB()
{
    SPI_setConfig(SPIB_BASE,DEVICE_LSPCLK_FREQ,SPI_PROT_POL0PHA0,SPI_MODE_PERIPHERAL,1000000U,16);
    SPI_disableFIFO(SPIB_BASE);
    SPI_enableModule(SPIB_BASE);

}


void Spi_Config(void)
{
    GPIO_setPinConfig(GPIO_8_SPIA_PICO); 
    GPIO_setPinConfig(GPIO_17_SPIA_POCI);
    GPIO_setPinConfig(GPIO_9_SPIA_CLK);
    GPIO_setPinConfig(GPIO_57_SPIA_PTE);

    GPIO_setPinConfig(GPIO_60_SPIB_PICO);
    GPIO_setPinConfig(GPIO_61_SPIB_POCI);
    GPIO_setPinConfig(GPIO_14_SPIB_CLK);
    GPIO_setPinConfig(GPIO_27_SPIB_PTE);
    spi_Init();
    spi_InitB();
    Interrupt_register(INT_SPIA_TX, &spiATxISR);
    Interrupt_register(INT_SPIA_RX, &spiARxISR);

    Interrupt_enable(INT_SPIA_TX);
    Interrupt_enable(INT_SPIA_RX);
    Interrupt_enableGlobal();
    TransmitA();
    
}

void SPIB_Process(void)
{
    // Check if SPIB received a word
    if(SPI_getRxFIFOStatus(SPIB_BASE) != SPI_FIFO_RX0)
    {
        // Read the word received from SPIA
        rxb = SPI_readDataNonBlocking(SPIB_BASE);

        // Immediately load TX FIFO with response
        SPI_writeDataNonBlocking(SPIB_BASE, txb);
    }
}