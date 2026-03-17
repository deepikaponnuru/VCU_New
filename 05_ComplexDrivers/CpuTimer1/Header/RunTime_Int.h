#ifndef RUNTIME_INT_H_
#define RUNTIME_INT_H_
void CpuTimer1_init(void);
float32_t ticks_to_us(uint32_t ticks);
uint32_t read_timerValue(void);
uint32_t elapsedTicks(uint32_t startTicks);
#endif
