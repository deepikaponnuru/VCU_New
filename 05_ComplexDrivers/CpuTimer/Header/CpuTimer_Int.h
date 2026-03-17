#ifndef CPUTIMER_INT_H_
#define CPUTIMER_INT_H_
#include"device.h"
#include "driverlib.h"

void ResetTimerFlag(void);
uint8_t getTimerFlag(void);
void CpuTimer_init(void);

#endif
