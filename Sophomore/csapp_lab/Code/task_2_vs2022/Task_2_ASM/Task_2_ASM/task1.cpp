/**
 * 任務 1: C語言學生成績管理 (完整修復版)
 * 功能: 初始化數據、計算平均分、排序、性能計時
 * 作者: 阮雲軒 (U202490035)
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iomanip> // 用于格式化输出
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>  // 【修正】包含 sprintf_s 所需的头文件
#include <chrono>  // 高精度计时

using namespace std;

// 强制 1 字节对齐，确保结构体紧凑 (大小=37字节)
#pragma pack(1)
struct Student {
    char name[12];      // 8 bytes
    char sid[11];      // 11 bytes
    short scores[8];   // 16 bytes
    short average;     // 2 bytes
};
#pragma pack()

// 【修正】按您的要求，将学生人数设为 30
const int N = 30;

// 初始化数据
void InitData(vector<Student>& students) {
    // 1. 第0个学生：阮雲軒
    strcpy_s(students[0].name, "阮云轩");
    strcpy_s(students[0].sid, "U202490035");
    // 给自己设定一个分数
    for (int k = 0; k < 8; ++k) students[0].scores[k] = 95;
    students[0].average = 0;

    // 2. 随机生成其余学生
    srand((unsigned)time(NULL));
    for (int i = 1; i < N; ++i) {
        sprintf_s(students[i].name, "S_%d", i);
        sprintf_s(students[i].sid, "U2024%05d", i);

        // 随机生成 8 门课成绩 (50-100分)
        for (int k = 0; k < 8; ++k) {
            students[i].scores[k] = 50 + rand() % 51;
        }
        students[i].average = 0;
    }
}

// 函数：计算平均成绩 (C语言逻辑)
void CalcAvg_C(Student* s, int count) {
    for (int i = 0; i < count; ++i) {
        int sum = 0;
        for (int k = 0; k < 8; ++k) {
            sum += s[i].scores[k];
        }
      
        s[i].average = (short)(sum >> 3);
    }

}

// 函数：冒泡排序 (C语言逻辑，按平均分从高到低)
void Sort_C(Student* s, int count) {
    for (int i = 0; i < count - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < count - 1 - i; ++j) {
            if (s[j].average < s[j + 1].average) { // 降序排序
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break; // 如果一轮没有交换，说明已经有序，提前退出
    }

}

// 【修正】统一函数名为 PrintStudents
void PrintStudents(const vector<Student>& s) {
    cout << left << setw(10) << "Name"
        << setw(12) << "SID"
        << setw(30) << "Scores (1-8)"
        << "Avg" << endl;
    cout << "-------------------------------------------------------------" << endl;

    // 打印所有学生 (因为 N=30 不多，可以全打印)
    for (int i = 0; i < N; ++i) {
        cout << left << setw(10) << s[i].name
            << setw(12) << s[i].sid << " ";

        // 打印 8 门课分数
        for (int k = 0; k < 8; ++k) {
            cout << s[i].scores[k] << " ";
        }

        // 打印平均分
        cout << " | " << s[i].average << endl;
    }
    cout << endl;
}

int main() {
    // 使用 vector 存储 N 个学生
    vector<Student> students(N);

    // 1. 初始化
    InitData(students);

    cout << ">>> Task 1: Student Management System (N=" << N << ")" << endl << endl;

    // 2. 计时并计算平均分
    auto start = chrono::high_resolution_clock::now();
    CalcAvg_C(students.data(), N);
    auto end = chrono::high_resolution_clock::now();
    double timeAvg = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000.0;

    cout << "[Timing] Calculate Average Cost: " << timeAvg << " us (microseconds)" << endl;

    cout << "\n--- Before Sort (First 5) ---" << endl;
    // 简单打印前5个看看
    for (int i = 0; i < 5; i++) cout << students[i].name << " Avg: " << students[i].average << endl;


    // 3. 计时并排序
    start = chrono::high_resolution_clock::now();
    Sort_C(students.data(), N);
    end = chrono::high_resolution_clock::now();
    double timeSort = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000.0;

    cout << "[Timing] Sort Cost:            " << timeSort << " us (microseconds)" << endl;

    // 4. 显示排序后的结果
    cout << "\n--- Final Result (All Students Sorted) ---" << endl;

    // 【修正】补上了函数调用
    PrintStudents(students);

    // 【修正】补上了 main 函数的结尾
    return 0;
}