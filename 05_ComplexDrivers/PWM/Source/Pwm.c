#include "Pwm_Int.h"

#define base EPWM1_BASE
#define base1 EPWM2_BASE
#define period 2500/2
uint32_t Cmpa = 0;
uint32_t dutyCycle=0;
uint32_t counterrrr=0;
uint32_t k=0;
__interrupt void epwm2ISR(void)
{
    GPIO_writePin(7,1);
    // GPIO_writePin(7,1);
       // Debug waveform

    EPWM_clearEventTriggerInterruptFlag(base1);

    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);
    // for(k=0;k<1000;k++);
    GPIO_writePin(7,0);
    counterrrr++;
}
void setdutycycle(uint8_t dutycycle)
{
    if(dutycycle >= 100)
    {
        Cmpa = ((uint32_t)((period ) ) * (100 - dutycycle) ) / 100; // +50 for rounding
    }
    else
    {
         Cmpa = ((uint32_t)((period ) ) *(100 - dutycycle) ) / 100;

    }
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_A,Cmpa);
}
void Pwm_Init(void)
{
    uint16_t i=0;

     // Disable sync(Freeze clock to PWM as well)
    // SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    GPIO_setPinConfig(GPIO_0_EPWM1_A);
    GPIO_setPinConfig(GPIO_1_EPWM1_B);

     // Configure Time Base counter Clock
    EPWM_setClockPrescaler(base, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_6);
    
    // Configure Time Base Counter Mode
    EPWM_setTimeBaseCounterMode(base, EPWM_COUNTER_MODE_UP_DOWN);

    EPWM_setTimeBasePeriod(base, period);

    i=10;

     // Default Configurations.
    //
    EPWM_disablePhaseShiftLoad(base);
    EPWM_setPhaseShift(base, 0U);
    EPWM_setTimeBaseCounter(base, 0U);

    EPWM_setCounterCompareShadowLoadMode(base,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(base,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_A,
                                Cmpa);
    EPWM_setCounterCompareValue(base, EPWM_COUNTER_COMPARE_B,
                                Cmpa);

     //
        // Set PWMxA on Zero
        //
    EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

        //
        // Clear PWMxA on event A, up count
        //
    EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_HIGH,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

     EPWM_setActionQualifierAction(base,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    /********************* Dead Band configuration *****************/
    EPWM_setDeadBandDelayMode(base, EPWM_DB_RED, true);
    EPWM_setDeadBandDelayMode(base, EPWM_DB_FED, true);

    EPWM_setRisingEdgeDeadBandDelayInput(base, EPWM_DB_INPUT_EPWMA);
    EPWM_setFallingEdgeDeadBandDelayInput(base, EPWM_DB_INPUT_EPWMA);

    EPWM_setDeadBandDelayPolarity(base,
                              EPWM_DB_RED,
                              EPWM_DB_POLARITY_ACTIVE_HIGH);

    EPWM_setDeadBandDelayPolarity(base,
                              EPWM_DB_FED,
                              EPWM_DB_POLARITY_ACTIVE_LOW);
    EPWM_setRisingEdgeDelayCount(base, 25);
    EPWM_setFallingEdgeDelayCount(base, 25);
    
    EPWM_setDeadBandCounterClock(base,
                             EPWM_DB_COUNTER_CLOCK_FULL_CYCLE);


    // SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Enable interrupts required for this example
    //
    Interrupt_enable(INT_EPWM1);

    setdutycycle(dutyCycle);
        
}



void Pwm_Init2(void)
{

     // Disable sync(Freeze clock to PWM as well)
    // SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    // GPIO_setPinConfig(GPIO_2_EPWM2_A);
    GPIO_setPinConfig(GPIO_7_GPIO7);
    GPIO_setDirectionMode(7, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);
    GPIO_writePin(7, 0);

     // Configure Time Base counter Clock
    EPWM_setClockPrescaler(base1, EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_6);
    
    // Configure Time Base Counter Mode
    EPWM_setTimeBaseCounterMode(base1, EPWM_COUNTER_MODE_UP_DOWN);

    EPWM_setTimeBasePeriod(base1, period);

     // Default Configurations.
    //
    EPWM_disablePhaseShiftLoad(base1);
    EPWM_setPhaseShift(base1, 0U);
    EPWM_setTimeBaseCounter(base1, 0U);

    EPWM_setCounterCompareShadowLoadMode(base1,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(base1,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setCounterCompareValue(base1, EPWM_COUNTER_COMPARE_A,
                                period/2);
    EPWM_setCounterCompareValue(base1, EPWM_COUNTER_COMPARE_B,
                            period/2);

     //
        // Set PWMxA on Zero
        //
    EPWM_setActionQualifierAction(base1,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

        //
        // Clear PWMxA on event A, up count
        //
    EPWM_setActionQualifierAction(base1,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_HIGH,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

     EPWM_setActionQualifierAction(base1,
                                      EPWM_AQ_OUTPUT_A,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    
     // ==========================
    // ADC Trigger Configuration
    // Trigger at CMPA during UP count
    // ==========================
    EPWM_setADCTriggerSource(base1,
                             EPWM_SOC_A,
                             EPWM_SOC_TBCTR_PERIOD);

    EPWM_setADCTriggerEventPrescale(base1,
                                    EPWM_SOC_A,
                                    1);

    EPWM_enableADCTrigger(base1, EPWM_SOC_A);
    EPWM_setInterruptSource(base1,
                        EPWM_INT_TBCTR_PERIOD);

EPWM_enableInterrupt(base1);

// Trigger interrupt on every event
EPWM_setInterruptEventCount(base1, 1);

// Register ISR
Interrupt_register(INT_EPWM2, &epwm2ISR);

// Enable CPU interrupt
Interrupt_enable(INT_EPWM2);
    // SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Enable interrupts required for this example
    //
     
}
void PWM_GlobalInit(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    Pwm_Init();
    Pwm_Init2();

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

// EPWM_enableADCTrigger
// EPWM_setADCTriggerSource

// EPWM_setADCTriggerEventPrescale

// EPWM_enableADCTriggerEventCountInit
// EPWM_forceADCTriggerEventCountInit
// EPWM_getADCTriggerEventCount
// EPWM_setADCTriggerEventCountInitValue
// EPWM_forceADCTrigger








