#include <stdio.h>
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx.h"
#include "Driver\DrvADC.h"
void main()
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);
    while (1)
    {
        DrvGPIO_ClrBit(E_GPB, 11);
        DrvSYS_Delay(1000000);
        DrvGPIO_SetBit(E_GPB, 11);
        DrvSYS_Delay(1000000);
    }
}
