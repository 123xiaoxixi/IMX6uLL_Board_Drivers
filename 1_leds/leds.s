.global _start

_start:
    LDR R0, =0x020c4068     @CCGR0
    LDR R1, =0xffffffff
    STR R1, [R0]

    LDR R0, =0x020c406c     @CCGR1
    STR R1, [R0]

    LDR R0, =0x020c4070     @CCGR2
    STR R1, [R0]

    LDR R0, =0x020c4074     @CCGR3
    STR R1, [R0]

    LDR R0, =0x020c4078     @CCGR4
    STR R1, [R0]

    LDR R0, =0x020c407c     @CCGR5
    STR R1, [R0]

    LDR R0, =0x020c4080     @CCGR6
    STR R1, [R0]

    LDR R0, =0x020e0068     @IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03
    LDR R1, =0x5            @ALT5
    STR R1, [R0]

    LDR R0, =0x020e02f4     @IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03
    /*
     * bit0:        0
     * bit5:3       110
     * bit7:6       10
     * bit11        0
     * bit12        1
     * bit13        0
     * bit15:14     00
     * bit16        0
     */
    LDR R1, =0x10b0
    STR R1, [R0]

    LDR R0, =0x0209c004     @GPIO1_GDIR
    LDR R1, =0x8            @gpio1_3 output
    STR R1, [R0]

    LDR R0, =0x0209c000
    LDR R1, =0x0
    STR R1, [R0]

loop:
    b loop

