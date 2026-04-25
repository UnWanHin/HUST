.686P
.model flat, C

; 定義偏移量 (與 C++ 對齊)
OFFSET_SCORES equ 19
OFFSET_AVG    equ 35
STRUCT_SIZE   equ 37

.code

; -------------------------------------------------------------
; 函數名: CalcAvg_ASM_Opt
; 優化手段: 循環展開 (Loop Unrolling) + 寄存器尋址
; -------------------------------------------------------------
CalcAvg_ASM_Opt PROC uses esi,
    ptr_data:DWORD, ; [ebp+8]
    count:DWORD     ; [ebp+12]

    mov esi, ptr_data       ; ESI = 當前學生指針
    mov ecx, count          ; ECX = 學生總數
    
    test ecx, ecx
    jz _Exit

_Loop_Student:
    ; --- 優化核心：循環展開 ---
    ; 不再使用 loop 指令，而是直接寫 8 次加法
    ; 這樣消除了循環控制指令 (dec, jnz) 的開銷，流水線更順暢
    
    xor eax, eax            ; sum = 0

    ; 分數是 short (2字節)，偏移量依次 +2
    ; OFFSET_SCORES = 19
    
    add ax, word ptr [esi + 19] ; 第1門課
    add ax, word ptr [esi + 21] ; 第2門課
    add ax, word ptr [esi + 23] ; 第3門課
    add ax, word ptr [esi + 25] ; 第4門課
    add ax, word ptr [esi + 27] ; 第5門課
    add ax, word ptr [esi + 29] ; 第6門課
    add ax, word ptr [esi + 31] ; 第7門課
    add ax, word ptr [esi + 33] ; 第8門課

    ; --- 計算平均分 ---
    sar eax, 3              ; 右移 3 位 (除以 8)
    
    ; --- 存回結構體 ---
    mov word ptr [esi + OFFSET_AVG], ax

    ; --- 下一個學生 ---
    add esi, STRUCT_SIZE
    dec ecx
    jnz _Loop_Student

_Exit:
    ret
CalcAvg_ASM_Opt ENDP

END