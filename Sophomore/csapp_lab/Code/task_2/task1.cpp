// Task1.cpp - 任务1：C语言实现成绩管理与排序
// 编译环境：Visual Studio 2022 (x86 Debug/Release)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> // 用于高精度计时 QueryPerformanceCounter

#pragma pack(1) // 强制1字节对齐，确保结构体紧凑
struct Student {
    char name[8];
    char sid[11];
    short scores[8];
    short average;
};
#pragma pack()

const int STUDENT_NUM = 10000; // 学生数量，设大一点以观察时间差异

// 计时器变量
LARGE_INTEGER frequency;
LARGE_INTEGER startVal, endVal;

void startTimer() {
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&startVal);
}

double stopTimer() {
    QueryPerformanceCounter(&endVal);
    return (double)(endVal.QuadPart - startVal.QuadPart) * 1000.0 / frequency.QuadPart;
}

// 初始化数据
void initData(Student* s, int n) {
    // 1. 设置第0个学生为自己
    strcpy_s(s[0].name, "阮雲軒");
    strcpy_s(s[0].sid, "U202490035");
    for (int k = 0; k < 8; k++) s[0].scores[k] = 90 + (k % 10);
    s[0].average = 0;

    // 2. 随机生成其余学生
    srand((unsigned)time(NULL));
    for (int i = 1; i < n; i++) {
        sprintf_s(s[i].name, "S_%d", i);
        sprintf_s(s[i].sid, "U2024%05d", i);
        for (int k = 0; k < 8; k++) {
            s[i].scores[k] = 50 + rand() % 51; // 50-100分
        }
        s[i].average = 0;
    }
}

// 打印前几名学生
void printStudents(Student* s, int n, int limit = 10) {
    printf("%-10s %-12s %-8s\n", "Name", "ID", "Avg");
    printf("--------------------------------\n");
    for (int i = 0; i < n && i < limit; i++) {
        printf("%-10s %-12s %-4d\n", s[i].name, s[i].sid, s[i].average);
    }
    printf("...\n\n");
}

// 【C语言版】计算平均分
void calc_average_c(Student* s, int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int k = 0; k < 8; k++) {
            sum += s[i].scores[k];
        }
        // 除以8可以用右移3位代替，但为了对比优化，这里先写除法也行，或者直接移位
        s[i].average = (short)(sum >> 3); 
    }
}

// 【C语言版】冒泡排序 (按平均分降序)
void sort_students_c(Student* s, int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (s[j].average < s[j + 1].average) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    // 使用堆内存，防止栈溢出
    Student* students = (Student*)malloc(sizeof(Student) * STUDENT_NUM);
    if (!students) return -1;

    printf(">>> Task 1: C Implementation (N=%d)\n", STUDENT_NUM);
    
    // 初始化
    initData(students, STUDENT_NUM);
    
    // 计时：计算平均分
    startTimer();
    calc_average_c(students, STUDENT_NUM);
    double timeAvg = stopTimer();
    printf("[Time] Calc Average: %.4f ms\n", timeAvg);

    // 打印排序前
    printf("\n--- Before Sort ---\n");
    printStudents(students, STUDENT_NUM, 5);

    // 计时：排序
    startTimer();
    sort_students_c(students, STUDENT_NUM);
    double timeSort = stopTimer();
    printf("[Time] Bubble Sort:  %.4f ms\n", timeSort);

    // 打印排序后
    printf("\n--- After Sort ---\n");
    printStudents(students, STUDENT_NUM, 5);

    free(students);
    return 0;
}