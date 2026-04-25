/**
 * 任務 2: C語言調用匯編函數計算平均分
 * 文件名: Task2.cpp
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <chrono>

using namespace std;

// 強制 1 字節對齊，結構體大小必須是 37，否則匯編算偏移量會錯
#pragma pack(1)
struct Student {
    char name[8];      // 8 bytes  
    char sid[11];      // 11 bytes
    short scores[8];   // 16 bytes
    short average;     // 2 bytes
};
#pragma pack()

const int N = 30; // 學生人數

// ==========================================
// 關鍵修改：聲明外部匯編函數
// extern "C" 告訴編譯器不要修改函數名，方便匯編調用
// ==========================================
extern "C" void CalcAvg_ASM(Student* s, int count);

// 初始化數據 (保持不變)
void InitData(vector<Student>& students) {
    strcpy_s(students[0].name, "ywh"); // 名字改短防止崩潰
    strcpy_s(students[0].sid, "U202490035");
    for (int k = 0; k < 8; ++k) students[0].scores[k] = 95;
    students[0].average = 0;

    srand((unsigned)time(NULL));
    for (int i = 1; i < N; ++i) {
        sprintf_s(students[i].name, "S_%d", i);
        sprintf_s(students[i].sid, "U2024%05d", i);
        for (int k = 0; k < 8; ++k) students[i].scores[k] = 50 + rand() % 51;
        students[i].average = 0;
    }
}

// 排序函數 (任務2要求只替換平均分計算，所以排序還是用C寫)
void Sort_C(Student* s, int count) {
    for (int i = 0; i < count - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < count - 1 - i; ++j) {
            if (s[j].average < s[j + 1].average) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void PrintStudents(const vector<Student>& s) {
    cout << left << setw(10) << "Name" << setw(12) << "SID" << setw(30) << "Scores" << "Avg" << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < N; ++i) {
        cout << left << setw(10) << s[i].name << setw(12) << s[i].sid << " ";
        for (int k = 0; k < 8; ++k) cout << s[i].scores[k] << " ";
        cout << " | " << s[i].average << endl;
    }
    cout << endl;
}

int main() {
    vector<Student> students(N);
    InitData(students);

    cout << ">>> Task 2: Mixed C++ and Assembly (CalcAvg in ASM)" << endl << endl;

    // 計時：調用匯編函數
    auto start = chrono::high_resolution_clock::now();

    // 這裡調用的是匯編寫的函數！
    CalcAvg_ASM(students.data(), N);

    auto end = chrono::high_resolution_clock::now();
    double timeAvg = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000.0;
    cout << "[Timing] ASM CalcAvg Cost: " << timeAvg << " us" << endl;

    // 排序 (C語言)
    Sort_C(students.data(), N);

    cout << "\n--- Final Result ---" << endl;
    PrintStudents(students);

    return 0;
}