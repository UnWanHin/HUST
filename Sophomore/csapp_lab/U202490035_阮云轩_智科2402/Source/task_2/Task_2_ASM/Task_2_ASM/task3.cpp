// Task3.cpp : 任務3 - 匯編優化版 (循環展開)
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <chrono>

using namespace std;

#pragma pack(1)
struct Student {
    char name[8];      // 8 bytes
    char sid[11];      // 11 bytes
    short scores[8];   // 16 bytes
    short average;     // 2 bytes
};
#pragma pack()

const int N = 30;

// 聲明外部匯編函數 (優化版)
extern "C" void CalcAvg_ASM_Opt(Student* s, int count);

void InitData(vector<Student>& students) {
    strcpy(students[0].name, "Ryan");
    strcpy(students[0].sid, "U202490035");
    for (int k = 0; k < 8; ++k) students[0].scores[k] = 95;
    students[0].average = 0;

    srand((unsigned)time(NULL));
    for (int i = 1; i < N; ++i) {
        sprintf(students[i].name, "S_%d", i);
        sprintf(students[i].sid, "U2024%05d", i);
        for (int k = 0; k < 8; ++k) students[i].scores[k] = 50 + rand() % 51;
        students[i].average = 0;
    }
}

void PrintStudents(const vector<Student>& s) {
    cout << left << setw(10) << "Name" << setw(12) << "SID" << "Avg" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < N; ++i) {
        cout << left << setw(10) << s[i].name
            << setw(12) << s[i].sid
            << s[i].average << endl;
    }
}

int main() {
    vector<Student> students(N);
    InitData(students);

    cout << ">>> Task 3: ASM Optimization (Loop Unrolling)" << endl;

    // 計時開始
    auto start = chrono::high_resolution_clock::now();

    // 調用優化版匯編函數
    CalcAvg_ASM_Opt(students.data(), N);

    auto end = chrono::high_resolution_clock::now();
    double timeAvg = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000.0;

    cout << "[Timing] Optimized ASM Cost: " << timeAvg << " us" << endl;

    PrintStudents(students);
    return 0;
}