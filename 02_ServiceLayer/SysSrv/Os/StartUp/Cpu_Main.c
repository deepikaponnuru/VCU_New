#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"

// #include "Port_Ext.h"
// #include "Port_Int.h"
// #include "IoHwDio_Ext.h"


void main(void)
{
    Device_init();
    Device_initGPIO();

    Interrupt_initModule();
    Interrupt_initVectorTable();
  
    Board_init();
    //C2000Ware_libraries_init();
    EINT;
    ERTM;
    SchM_Start();

    
}