#include "SchM_Int.h"
float32_t time;
uint32_t start;
uint32_t elapsed;
uint32_t ms1=0;
uint32_t flag2=0;
uint32_t  current;
uint32_t counterrr=0;
uint32_t dutyCycle1=0;

void SchM_Init(void)
{
    volatile uint32_t i = 0;
    EcuM_Init();
    start = read_timerValue();
    for(i = 0;i < 50000; i++);
    elapsed=elapsedTicks(start);
    // GPIO_setDirectionMode(1, GPIO_DIR_MODE_OUT);
    // GPIO_setDirectionMode(2, GPIO_DIR_MODE_OUT);
    Adc_Init();
    Port_Init();
    can_Init();
    Spi_Config();
    PWM_GlobalInit();
    // Pwm_Init();
    // Pwm_Init2();
    IoHwAna_Init();
    Uart_Init();
}

void SchM_Task1ms(void)
{
    ms1++;
    setdutycycle(dutyCycle1);
    // GPIO_togglePin(1);
     IoHwAna_Proc();
      IoHwDio_Proc();
}
void SchM_Task10ms(void)
{
    if(flag2 == 1)
    {
        //can_Transmit();
        flag2 = 0;

    }
    // GPIO_togglePin(2);
    //  TransmitA();
    // TransmitB();
    // readA();
    // readB();
    counterrr++;   
}
void SchM_Task100ms(void)
{
    BlinkersM_Proc10ms();
    HazardM_Proc10ms(); 
}
void SchM_Start(void)
{
    uint8_t TimerTrig1msTask = 0;
    uint8_t Count1msTask = 0;
    uint8_t Count10msTask = 0u;
   SchM_Init();
   
    while(1u)
    {
        TimerTrig1msTask=getTimerFlag();
        if(TimerTrig1msTask)
        {
            Count1msTask += 1u;
            SchM_Task1ms();
            ResetTimerFlag();
            if(Count1msTask == 10u)
            {
                SchM_Task10ms();
                Count1msTask = 0u;
                Count10msTask++;
                if(Count10msTask == 10u)
                {
                    current=read_timerValue();
                    elapsed=elapsedTicks(start);
                    //time=ticks_to_us(elapsed);
                    SchM_Task100ms();
                    Count10msTask = 0;
                }
            }
        }
    }
}
