#include <lpc214x.h>
voidpwm_init(void)
{
    PINSEL0 |= 0x00000002;
    PWMPR = 0x2;
    PWMPCR = 0x00000200;
    PWMMR0 = 0xC37F;
    PWMMCR = 0x00000002;
    PWMTCR = 0x00000009;
}
int main()
{
    int i;
    pwm_init();
    while (1)
    {
        for (i = 0; i < 10; i++)
        {
            PWMMR1 = 0xFFF + (0xFF5 * i);
            PWMLER = 0x02;
        }
    }
}