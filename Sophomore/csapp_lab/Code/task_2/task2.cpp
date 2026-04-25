// Task2.cpp - 任务2：使用基础汇编替换平均分计算
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#pragma pack(1)
struct Student {
    char name[8];
    char sid[11];
    short scores[8];
    short average;
};
#pragma pack()

// 结构体偏移量定义，方便汇编使用
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
    srand((unsigned)time(NULL));
    for (int i = 1; i < n; i++) {
        sprintf_s(s[i].name, "S_%d", i);
        sprintf_s(s[i].sid, "U2023%05d", i);
        for (int k = 0; k < 8; k++) s[i].scores[k] = 50 + rand() % 51;
        s[i].average = 0;
    }
}

// 【汇编版】基础计算平均分
// 使用 __declspec(naked) 可以让函数不生成 prolog/epilog，完全由汇编控制
// 但为了简单，这里用普通的内联汇编
void calc_average_asm(Student* s, int n) {
    __asm {
        mov esi, s          ; esi 指向结构体数组首地址
        mov ecx, n          ; ecx 作为循环计数器
        test ecx, ecx
        jz EXIT_ASM         ; 如果人数为0，直接退出

    LOOP_STUDENT:
        push ecx            ; 保存外层循环计数
        
        ; 计算当前学生8门课总分
        xor eax, eax        ; sum = 0
        xor edx, edx        ; 分数索引
        lea ebx, [esi + OFF_SCORES] ; ebx 指向 scores 数组

        ; 简单的循环累加 8 次
        mov ecx, 8
    LOOP_SCORE:
        add ax, word ptr [ebx]
        add ebx, 2          ; short 占 2 字节
        dec ecx
        jnz LOOP_SCORE

        ; 计算平均值 (sum / 8) -> 右移 3 位
        sar eax, 3
        
        ; 存入 average 字段
        mov word ptr [esi + OFF_AVG], ax

        ; 移动到下一个学生结构体
        add esi, STRUCT_SIZE
        
        pop ecx             ; 恢复外层计数
        dec ecx
        jnz LOOP_STUDENT

    EXIT_ASM:
    }
}

int main() {
    Student* students = (Student*)malloc(sizeof(Student) * STUDENT_NUM);
    initData(students, STUDENT_NUM);

    printf(">>> Task 2: ASM Basic Implementation\n");

    startTimer();
    calc_average_asm(students, STUDENT_NUM);
    double time = stopTimer();

    printf("[Time] ASM Calc Average: %.4f ms\n", time);
    
    // 简单验证一下第0个算对没
    printf("Check: %s Avg=%d\n", students[0].name, students[0].average);

    free(students);
    return 0;
}