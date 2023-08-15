#include <lpc214x.h>
void init()
{
    PINSEL0 = 0x05;
    U0FCR = 0x07;
    U0LCR = 0x83;
    U0DLL = 0x5D;
    U0DLM = 0x00;
    U0LCR = 0x03;
}

void delay()
{
    int i;
    for (i = 0; i < 1000000; i++)
        ;
}

int main()
{
    unsigned char p[] = "ISE Rocks";
    int z;
    init();
    for (z = 0; z < 9; z++)
    {
        U0THR = p[z];
        while (!(U0LSR & 0x20))
            ;

        delay();
    }
    while (1)
        ;
    rgb
}
