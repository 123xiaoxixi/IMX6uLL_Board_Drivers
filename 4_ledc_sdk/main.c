#include "fsl_common.h"
#include "MCIMX6Y2.h"
#include "fsl_iomuxc.h"

void clk_enable(void) {
    CCM->CCGR0 = 0xFFFFFFFF;
    CCM->CCGR1 = 0xFFFFFFFF;
    CCM->CCGR2 = 0xFFFFFFFF;
    CCM->CCGR3 = 0xFFFFFFFF;
    CCM->CCGR4 = 0xFFFFFFFF;
    CCM->CCGR5 = 0xFFFFFFFF;
    CCM->CCGR6 = 0xFFFFFFFF;
}

void led_init(void) {
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10b0);
    GPIO1->GDIR = 0x8;
    GPIO1->DR = 0x0;
}

void delay_short(volatile unsigned int n) {
    while(n--) {}
}

void delay(volatile unsigned int n) {
    while(n--) {
        delay_short(0x7ff);
    }
}

void led_on(void) {
    GPIO1->DR &= ~(0x1<<3);
}

void led_off() {
    GPIO1->DR |= (0x1<<3);
}

int main(void) {
    clk_enable();
    led_init();
    while(1) {
        led_on();
        delay(700);
        led_off();
        delay(700);
    }
    return 0;
}