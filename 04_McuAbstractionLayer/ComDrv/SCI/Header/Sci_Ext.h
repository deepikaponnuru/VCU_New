#ifndef SCI_EXT_H_
#define SCI_EXT_H_

#include "driverlib.h"
#include "device.h"

char Uart_TxData[] = "Hello";
uint16_t txIndex = 0; 
uint16_t txLength = sizeof(Uart_TxData) - 1;

void Uart_Init(Void);
void Uart_Transmit(void);
void Uart_ReceiveData(void);

__interrupt void Uart_RxISR(void);
__interrupt void Uart_TxISR(void);

#endif