.global _start

_start:
    MRS R0, CPSR
    BIC R0, R0, #0x1f   @bit4:0清零
    ORR R0, R0, #0x13   @bit4:0 = 10011, SVC模式
    MSR CPSR, R0

    /*sp */
    LDR SP, =0x80200000
    b main