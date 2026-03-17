#include "driverlib.h"
#include "device.h"
float32_t elapsed_us =0;
uint32_t toatl_elapsed_T=0;
uint32_t start_ticks = 0;
uint32_t read_timerValue()
{
    return CPUTimer_getTimerCount(CPUTIMER1_BASE);
}
uint32_t elapsedTicks(uint32_t startTicks)
{
    uint32_t currentTicks = read_timerValue();

    // Handle wrap-around
    if(currentTicks <= startTicks)
        return startTicks - currentTicks;
    else
        return 0xFFFFFFFF - startTicks + currentTicks + 1;
}
float32_t ticks_to_us(uint32_t ticks)
{
    return (float32_t)ticks / 150000000.0f;  // float division
}
void CpuTimer1_init(void)
{ 
    initCpuTimer1FreeRun();
    CPUTimer_startTimer(CPUTIMER1_BASE);  
}
void initCpuTimer1FreeRun(void)
{
    // Stop the timer first
    CPUTimer_stopTimer(CPUTIMER1_BASE);

    // Set pre-scaler to 0 → timer counts at SYSCLK
    CPUTimer_setPreScaler(CPUTIMER1_BASE, 0);

    // Set timer period to maximum for free-running
    CPUTimer_setPeriod(CPUTIMER1_BASE, 0xFFFFFFFF);

    // Reload counter to period
    CPUTimer_reloadTimerCounter(CPUTIMER1_BASE);

    // Set emulation mode to free-run (timer continues even in debug)
    CPUTimer_setEmulationMode(CPUTIMER1_BASE,
        CPUTIMER_EMULATIONMODE_RUNFREE);

    // Start the timer
    
}  