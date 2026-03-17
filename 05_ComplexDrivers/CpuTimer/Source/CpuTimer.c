
#include "driverlib.h"
#include "device.h"

uint16_t cpuTimer0IntCount;
__interrupt void cpuTimer0ISR(void);
void initCPUTimers(void);
void configCPUTimer(uint32_t, float, float);
void sch_1ms(void);
void sch_1s(void);
uint8_t MsFlag=0;
uint32_t counter=0;
void CpuTimer_init(void)
{ 
    Interrupt_register(INT_TIMER0, &cpuTimer0ISR);
    initCPUTimers();
    configCPUTimer(CPUTIMER0_BASE, DEVICE_SYSCLK_FREQ, 100);
    CPUTimer_enableInterrupt(CPUTIMER0_BASE);
    Interrupt_enable(INT_TIMER0);
    CPUTimer_startTimer(CPUTIMER0_BASE);
}
void initCPUTimers(void)
{
    
    CPUTimer_setPeriod(CPUTIMER0_BASE, 0xFFFFFFFF);
    CPUTimer_setPreScaler(CPUTIMER0_BASE, 0);
    CPUTimer_stopTimer(CPUTIMER0_BASE);
    CPUTimer_reloadTimerCounter(CPUTIMER0_BASE);
    cpuTimer0IntCount = 0;
   
}
void configCPUTimer(uint32_t cpuTimer, float freq, float period)
{
    uint32_t temp;
    temp = (uint32_t)((freq / 1000000) * period);
    CPUTimer_setPeriod(cpuTimer, temp - 1);
    CPUTimer_setPreScaler(cpuTimer, 0);
    CPUTimer_stopTimer(cpuTimer);
    CPUTimer_reloadTimerCounter(cpuTimer);
    CPUTimer_setEmulationMode(cpuTimer,
                              CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
    CPUTimer_enableInterrupt(cpuTimer);
    if (cpuTimer == CPUTIMER0_BASE)
    {
        cpuTimer0IntCount = 0;
    }
    
}     
__interrupt void cpuTimer0ISR(void)
{
    MsFlag=1;
    counter++;
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

void ResetTimerFlag(void)
{
    MsFlag=0;
}

uint8_t getTimerFlag(void)
{
    return (MsFlag);
}