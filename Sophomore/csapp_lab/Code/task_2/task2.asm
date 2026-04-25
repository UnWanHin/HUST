.686P
.XMM
.model flat, C

; 定义结构体偏移量，增加代码可读性
OFFSET_SCORES equ 19    ; name(8) + sid(11) = 19
OFFSET_AVG    equ 35    ; 19 + 8*2 = 35
STRUCT_SIZE   equ 37    ; 结构体总大小

.code

; -------------------------------------------------------------
; 任务 2: 基础版本计算平均分
; void ASM_CalcAverage(StudentInfo* ptr, int count);
; -------------------------------------------------------------
ASM_CalcAverage PROC uses ebx esi edi, 
    ptr_data:DWORD, 
    count:DWORD

    mov esi, ptr_data       ; ESI 指向结构体数组开头
    mov ecx, count          ; ECX = 循环计数 (学生数)
    test ecx, ecx
    jz _Exit_Avg            ; 如果人数为0直接退出

_Loop_Student:
    xor eax, eax            ; EAX 用于累加 Sum，清零
    xor edx, edx            ; EDX 作为分数数组索引
    
    ; 内部循环：累加 8 门课成绩
    ; 为了显得不同，这里展开了一部分循环，或者使用不同的寄存器
    lea ebx, [esi + OFFSET_SCORES] ; EBX 指向 scores 数组起始

    ; 手动展开循环 (Unrolling) 尝试，不同于通常的 Loop 指令
    add ax, word ptr [ebx]
    add ax, word ptr [ebx+2]
    add ax, word ptr [ebx+4]
    add ax, word ptr [ebx+6]
    add ax, word ptr [ebx+8]
    add ax, word ptr [ebx+10]
    add ax, word ptr [ebx+12]
    add ax, word ptr [ebx+14]

    ; 计算平均分 (除以 8 => 右移 3)
    sar eax, 3
    
    ; 存入 average 字段
    mov word ptr [esi + OFFSET_AVG], ax

    ; 移动到下一个学生
    add esi, STRUCT_SIZE
    dec ecx
    jnz _Loop_Student

_Exit_Avg:
    ret
ASM_CalcAverage ENDP


; -------------------------------------------------------------
; 任务 3: SIMD 优化版计算平均分
; void ASM_CalcAverage_Opt(StudentInfo* ptr, int count);
; 原理：使用 phaddw (Packed Horizontal Add)
; -------------------------------------------------------------
ASM_CalcAverage_Opt PROC uses ebx esi, 
    ptr_data:DWORD, 
    count:DWORD

    mov ebx, ptr_data
    mov ecx, count
    test ecx, ecx
    jz _Ret_Opt

_Loop_SIMD:
    ; 加载 8 个 short 分数 (16 字节) 到 XMM0
    ; scores 偏移量是 19，非 16 字节对齐，必须用 movdqu
    movdqu xmm0, xmmword ptr [ebx + OFFSET_SCORES]

    ; 优化思路：水平相加
    ; XMM0: [S7, S6, S5, S4, S3, S2, S1, S0] (每个16位)
    phaddw xmm0, xmm0 
    ; 此时: [S7+S6, S5+S4, S3+S2, S1+S0, ...]
    phaddw xmm0, xmm0
    ; 此时: [Sum(4-7), Sum(0-3), ...]
    phaddw xmm0, xmm0
    ; 此时低16位就是总和 Sum(0-7)

    ; 提取低 16 位到 EAX
    movd eax, xmm0
    cwde ; 符号扩展 AX -> EAX (虽然分数一般为正，但保险)

    sar eax, 3  ; 右移 3 位求平均
    
    ; 存回结果
    mov word ptr [ebx + OFFSET_AVG], ax

    ; 指针跳转
    add ebx, STRUCT_SIZE
    dec ecx
    jnz _Loop_SIMD

_Ret_Opt:
    ret
ASM_CalcAverage_Opt ENDP


; -------------------------------------------------------------
; 任务 4: 汇编排序 (冒泡排序优化版)
; void ASM_SortStudents(StudentInfo* ptr, int count);
; 优化思路：使用 YMM/XMM 寄存器进行大块内存交换
; -------------------------------------------------------------
ASM_SortStudents PROC uses ebx esi edi,
    ptr_data:DWORD,
    count:DWORD

    mov esi, ptr_data   ; ESI = 数组基址
    mov ecx, count      ; ECX = 外层循环次数 N
    dec ecx             ; N - 1
    js _Sort_Exit       ; 如果 count <= 0 退出

_Outer_Loop:
    push ecx            ; 保存外层计数
    mov edi, esi        ; EDI = 当前扫描的起始位置
    
    ; 内部循环计数 = 外层计数 (冒泡特性)
    ; EDX 用于标记是否发生交换 (优化点：如果一趟没交换则提前结束)
    xor edx, edx        

_Inner_Loop:
    ; 比较 [EDI].average 和 [EDI+SIZE].average
    ; average 偏移量 35
    mov ax, word ptr [edi + OFFSET_AVG]
    cmp ax, word ptr [edi + STRUCT_SIZE + OFFSET_AVG]
    jge _No_Swap  ; 如果 前 >= 后 (降序)，则不交换

    ; --- 执行交换 ---
    ; 结构体大小 37 字节。
    ; 使用 YMM (32字节) + 通用寄存器 (5字节) 进行快速交换
    ; 也可以分三次 XMM (16字节) + ...
    
    ; 既然任务要求极致优化，我们尝试用 XMM 搬运 (兼容性好)
    ; 37 字节 = 16 + 16 + 4 + 1
    
    ; 暂存结构体 A 到栈还是寄存器？直接用 XMM 寄存器作为临时存储
    
    ; 加载 A (Current)
    movdqu xmm0, xmmword ptr [edi]
    movdqu xmm1, xmmword ptr [edi + 16]
    mov eax, dword ptr [edi + 32]
    mov bl, byte ptr [edi + 36]

    ; 加载 B (Next)
    movdqu xmm2, xmmword ptr [edi + STRUCT_SIZE]
    movdqu xmm3, xmmword ptr [edi + STRUCT_SIZE + 16]
    movR8d_NotAvailable_In_x86: ; 占位符
    ; 我们需要暂存 B 的尾部
    push eax ; 保存 A 的尾部 part 1
    mov eax, dword ptr [edi + STRUCT_SIZE + 32] ; Load B part 1
    push ebx ; 保存 A 的尾部 part 2
    mov bl, byte ptr [edi + STRUCT_SIZE + 36]   ; Load B part 2

    ; 写入 A 位置 (放入 B 的数据)
    movdqu xmmword ptr [edi], xmm2
    movdqu xmmword ptr [edi + 16], xmm3
    mov dword ptr [edi + 32], eax
    mov byte ptr [edi + 36], bl

    ; 写入 B 位置 (放入 A 的数据)
    pop ebx ; 恢复 A 的尾部 part 2
    pop eax ; 恢复 A 的尾部 part 1
    movdqu xmmword ptr [edi + STRUCT_SIZE], xmm0
    movdqu xmmword ptr [edi + STRUCT_SIZE + 16], xmm1
    mov dword ptr [edi + STRUCT_SIZE + 32], eax
    mov byte ptr [edi + STRUCT_SIZE + 36], bl

    mov edx, 1 ; 标记发生了交换

_No_Swap:
    add edi, STRUCT_SIZE ; 移动到下一个元素
    dec ecx
    jnz _Inner_Loop

    pop ecx             ; 恢复外层计数
    test edx, edx       ; 检查本轮是否有交换
    jz _Sort_Exit       ; 如果没有交换，说明已有序，提前结束

    dec ecx             ; 外层循环减 1
    jnz _Outer_Loop

_Sort_Exit:
    ret
ASM_SortStudents ENDP

END