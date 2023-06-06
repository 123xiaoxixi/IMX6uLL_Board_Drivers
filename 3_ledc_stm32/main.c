#include "imx6u.h"

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
    IOMUX_SW_MUX->GPIO1_IO03 = 0x5;
    IOMUX_SW_PAD->GPIO1_IO03 = 0x10b0;
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
        delay(200);
        led_off();
        delay(200);
    }
    return 0;
}