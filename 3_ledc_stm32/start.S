.global _start
.global _bss_start

_bss_start:
    .word __bss_start

.global _bss_end
_bss_end:
    .word __bss_end

_start:
    MRS R0, CPSR
    BIC R0, R0, #0x1f   @bit4:0清零
    ORR R0, R0, #0x13   @bit4:0 = 10011, SVC模式
    MSR CPSR, R0

    /*清除BSS段 */
    LDR R0, _bss_start
    LDR R1, _bss_end
    mov R2, #0
bss_loop:
    stmia R0!, {R2}
    cmp R0, R1
    ble bss_loop    @R0<=R1时执行跳转

    /*sp */
    LDR SP, =0x80200000
    b main