#include "main.h"

void clk_enable(void) {
    CCM_CCGR0 = 0xFFFFFFFF;
    CCM_CCGR1 = 0xFFFFFFFF;
    CCM_CCGR2 = 0xFFFFFFFF;
    CCM_CCGR3 = 0xFFFFFFFF;
    CCM_CCGR4 = 0xFFFFFFFF;
    CCM_CCGR5 = 0xFFFFFFFF;
    CCM_CCGR6 = 0xFFFFFFFF;
}

void led_init(void) {
    SW_MUX_GPIO1_IO03 = 0x5;    //复用为GPIO1_IO03
    SW_PAD_GPIO1_IO03 = 0x10b0;
    GPIO1_GDIR = 0x8;
    GPIO1_DR = 0x0;
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
    GPIO1_DR &= ~(0x1<<3);
}

void led_off() {
    GPIO1_DR |= (0x1<<3);
}

int main(void) {
    clk_enable();
    led_init();
    while(1) {
        led_on();
        delay(1000);
        led_off();
        delay(1000);
    }
    return 0;
}