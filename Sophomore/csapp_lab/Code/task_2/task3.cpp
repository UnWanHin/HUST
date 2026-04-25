// Task3.cpp - 任务3：汇编计算优化 (循环展开)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#pragma pack(1)
struct Student {
    char name[8];
    char sid[11];
    short scores[8];
    short average;
};
#pragma pack()

#define OFF_SCORES 19
#define OFF_AVG 35
#define STRUCT_SIZE 37

const int STUDENT_NUM = 10000;
LARGE_INTEGER frequency, startVal, endVal;
void startTimer() { QueryPerformanceFrequency(&frequency); QueryPerformanceCounter(&startVal); }
double stopTimer() { QueryPerformanceCounter(&endVal); return (double)(endVal.QuadPart - startVal.QuadPart) * 1000.0 / frequency.QuadPart; }

void initData(Student* s, int n) {
    strcpy_s(s[0].name, "彭冲");
    strcpy_s(s[0].sid, "U202315696");
    for (int k = 0; k < 8; k++) s[0].scores[k] = 90 + (k % 10);
    s[0].average = 0;
    // 其他略... 简化展示
}

// 【汇编优化版】计算平均分
// 优化手段：循环展开 (Loop Unrolling)，减少跳转指令
void calc_average_asm_opt(Student* s, int n) {
    __asm {
        mov esi, s          
        mov ecx, n          
        test ecx, ecx
        jz EXIT_OPT

    LOOP_OPT:
        ; 直接展开 8 次加法，省去内层循环计数和跳转
        ; 使用带偏移量的寻址，减少指针移动
        xor eax, eax
        
        add ax, word ptr [esi + OFF_SCORES]
        add ax, word ptr [esi + OFF_SCORES + 2]
        add ax, word ptr [esi + OFF_SCORES + 4]
        add ax, word ptr [esi + OFF_SCORES + 6]
        add ax, word ptr [esi + OFF_SCORES + 8]
        add ax, word ptr [esi + OFF_SCORES + 10]
        add ax, word ptr [esi + OFF_SCORES + 12]
        add ax, word ptr [esi + OFF_SCORES + 14]

        sar eax, 3
        mov word ptr [esi + OFF_AVG], ax

        add esi, STRUCT_SIZE
        dec ecx
        jnz LOOP_OPT

    EXIT_OPT:
    }
}

int main() {
    Student* students = (Student*)malloc(sizeof(Student) * STUDENT_NUM);
    initData(students, STUDENT_NUM);
    
    printf(">>> Task 3: ASM Optimization (Loop Unrolling)\n");

    startTimer();
    calc_average_asm_opt(students, STUDENT_NUM);
    double time = stopTimer();
    
    printf("[Time] ASM Optimized Avg: %.4f ms\n", time);
    free(students);
    return 0;
}