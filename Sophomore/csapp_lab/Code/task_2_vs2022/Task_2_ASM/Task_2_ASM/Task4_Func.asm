.686P
.xmm                ; 【關鍵】允許使用 XMM 指令集 (SSE)
.model flat, C

OFFSET_AVG    equ 35
STRUCT_SIZE   equ 37

.code

; -------------------------------------------------------------
; 函數名: Sort_ASM_Opt
; 優化 1: 使用 XMM 寄存器一次搬運 16 字節，加速 Swap
; 優化 2: 增加 swapped 標誌位，若一趟無交換則提前退出
; -------------------------------------------------------------
Sort_ASM_Opt PROC uses ebx esi edi,
    ptr_data:DWORD, ; [ebp+8]
    count:DWORD     ; [ebp+12]

    mov esi, ptr_data       ; ESI = 數組首地址
    mov ecx, count          ; ECX = N
    dec ecx                 ; 外層循環次數 N-1
    js _Exit                ; 若 N <= 0 退出

_Outer_Loop:
    push ecx                ; 保存外層計數
    mov edi, esi            ; EDI = 當前掃描指針
    xor edx, edx            ; EDX = swapped 標誌 (0: false)

    ; 內層循環次數 = 當前 ECX (冒泡特性)
_Inner_Loop:
    ; --- 比較 average (偏移 35) ---
    mov ax, word ptr [edi + OFFSET_AVG]
    cmp ax, word ptr [edi + STRUCT_SIZE + OFFSET_AVG]
    jge _No_Swap            ; 如果 前 >= 後 (降序)，不需要交換

    ; === 【核心優化】 極速交換 (SIMD Swap) ===
    ; 結構體大小 37 字節
    ; 方案: 搬運 16 + 16 + 5 字節
    
    ; 1. 交換前 16 字節 (0-15)
    movups xmm0, xmmword ptr [edi]               ; 把 A 放入 xmm0
    movups xmm1, xmmword ptr [edi + STRUCT_SIZE] ; 把 B 放入 xmm1
    movups xmmword ptr [edi], xmm1               ; B -> A
    movups xmmword ptr [edi + STRUCT_SIZE], xmm0 ; A -> B

    ; 2. 交換中 16 字節 (16-31)
    movups xmm0, xmmword ptr [edi + 16]
    movups xmm1, xmmword ptr [edi + STRUCT_SIZE + 16]
    movups xmmword ptr [edi + 16], xmm1
    movups xmmword ptr [edi + STRUCT_SIZE + 16], xmm0

    ; 3. 交換最後 5 字節 (32-36)
    ; 用普通寄存器搬運這最後一點點
    mov eax, dword ptr [edi + 32]
    mov ebx, dword ptr [edi + STRUCT_SIZE + 32]
    mov dword ptr [edi + 32], ebx
    mov dword ptr [edi + STRUCT_SIZE + 32], eax

    mov al, byte ptr [edi + 36]
    mov bl, byte ptr [edi + STRUCT_SIZE + 36]
    mov byte ptr [edi + 36], bl
    mov byte ptr [edi + STRUCT_SIZE + 36], al

    ; 設置交換標誌
    mov edx, 1

_No_Swap:
    add edi, STRUCT_SIZE    ; 指針後移
    dec ecx
    jnz _Inner_Loop

    pop ecx                 ; 恢復外層計數
    
    ; --- 優化：檢查標誌位 ---
    test edx, edx           ; 檢查 swapped 是否為 0
    jz _Exit                ; 如果這一輪完全沒交換，說明已經排好了，直接退出！

    dec ecx
    jnz _Outer_Loop

_Exit:
    ret
Sort_ASM_Opt ENDP

END