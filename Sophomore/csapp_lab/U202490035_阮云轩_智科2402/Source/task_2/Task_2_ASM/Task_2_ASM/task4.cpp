// Task4.cpp : 任務4 - 排序算法優化
// 優化手段：使用 SIMD (XMM寄存器) 進行快速內存交換 + 冒泡排序提前退出機制
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

// 為了讓排序時間可見，建議 N 不要太小，也不要太大(因為冒泡是O(N^2))
// 5000 是個不錯的數字，能夠明顯看出差距
const int N = 5000;

// 聲明外部匯編函數 (排序優化版)
extern "C" void Sort_ASM_Opt(Student* s, int count);

// 為了計算平均分 (排序前需要有平均分數據)
// 這裡簡單寫一個 C 版本的輔助函數
void Helper_CalcAvg(Student* s, int count) {
    for (int i = 0; i < count; ++i) {
        int sum = 0;
        for (int k = 0; k < 8; ++k) sum += s[i].scores[k];
        s[i].average = (short)(sum >> 3);
    }
}

void InitData(vector<Student>& students) {
    strcpy(students[0].name, "Ryan");
    strcpy(students[0].sid, "U202490035");

    srand((unsigned)time(NULL));
    for (int i = 0; i < N; ++i) { // 全部隨機生成
        if (i > 0) {
            sprintf(students[i].name, "S_%d", i);
            sprintf(students[i].sid, "U202%05d", i);
        }
        for (int k = 0; k < 8; ++k) students[i].scores[k] = 50 + rand() % 51;
        students[i].average = 0;
    }
}

void PrintStudents(const vector<Student>& s) {
    cout << left << setw(10) << "Name" << setw(12) << "SID" << "Avg" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < 10; ++i) { // 只打印前10個驗證
        cout << left << setw(10) << s[i].name
            << setw(12) << s[i].sid
            << s[i].average << endl;
    }
    cout << "..." << endl;
}

int main() {
    vector<Student> students(N);
    InitData(students);

    // 先把平均分算出來，否則沒法排
    Helper_CalcAvg(students.data(), N);

    cout << ">>> Task 4: ASM Optimized Sort (SIMD Swap)" << endl;
    cout << "Sorting " << N << " students..." << endl;

    // 計時開始
    auto start = chrono::high_resolution_clock::now();

    // 調用優化版排序
    Sort_ASM_Opt(students.data(), N);

    auto end = chrono::high_resolution_clock::now();
    double timeSort = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "[Timing] Optimized Sort Cost: " << timeSort << " ms" << endl;

    cout << "\n--- Result (Top 10) ---" << endl;
    PrintStudents(students);
    return 0;
}