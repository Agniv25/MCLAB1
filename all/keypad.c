#include <stdio.h>
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "scankey.h"
#include "NUC1xx.h"
#include "NUC1xx-LB_002\LCD_Driver.h"
int32_t main(void)
{
    int8_t number;
    char text0[16] = "LCD_keypad_spml";
    char text1[16] = "keypad:        ";
    UNLOCKREG();
    DrvSYS_Open(48000000);
    Initial_panel();
    clr_all_panel();
    OpenKeyPad();
    while (1)
    {
        number = Scankey();
        sprintf(text1 + 8, "%d", number);
        print_lcd(0, text1);
        DrvSYS_Delay(5000)
    }
}