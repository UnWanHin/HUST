.686P               ; 允許使用 Pentium Pro 指令集
.model flat, C      ; 使用 C 語言調用約定 (參數從右往左入棧)

; 定義結構體偏移量 (必須與 C++ 對齊)
; Name(8) + Sid(11) = 19
OFFSET_SCORES equ 19
; 19 + 8*2 = 35
OFFSET_AVG    equ 35
; 結構體總大小 = 37
STRUCT_SIZE   equ 37

.code

; -------------------------------------------------------------
; 函數名: CalcAvg_ASM
; 參數: [ebp+8] = 結構體數組指針 (s)
;       [ebp+12] = 學生人數 (count)
; -------------------------------------------------------------
CalcAvg_ASM PROC
    push ebp
    mov ebp, esp
    push ebx            ; 保存被調用者保存寄存器
    push esi
    push edi

    mov esi, [ebp + 8]  ; ESI = s (當前學生指針)
    mov ecx, [ebp + 12] ; ECX = count (循環計數器)
    
    ; 如果人數 <= 0，直接退出
    test ecx, ecx
    jz _Exit

_Loop_Student:
    push ecx            ; 保存外層循環計數 (因為內層也要用 ECX)

    ; --- 計算總分 ---
    xor eax, eax        ; EAX = sum = 0
    lea ebx, [esi + OFFSET_SCORES] ; EBX 指向 scores 數組
    mov ecx, 8          ; 內層循環 8 次

_Loop_Score:
    movsx edx, word ptr [ebx] ; 讀取一個 short 分數，並符號擴展到 32 位
    add eax, edx              ; sum += score
    add ebx, 2                ; 移動到下一個分數 (short 是 2 字節)
    dec ecx
    jnz _Loop_Score     ; 繼續內層循環

    ; --- 計算平均分 ---
    ; sum / 8 等同於 sum 右移 3 位
    sar eax, 3          ; EAX = average
    
    ; --- 存回結構體 ---
    mov word ptr [esi + OFFSET_AVG], ax

    ; --- 移動到下一個學生 ---
    add esi, STRUCT_SIZE
    
    pop ecx             ; 恢復外層循環計數
    dec ecx
    jnz _Loop_Student   ; 繼續外層循環

_Exit:
    pop edi
    pop esi
    pop ebx
    pop ebp
    ret
CalcAvg_ASM ENDP

END