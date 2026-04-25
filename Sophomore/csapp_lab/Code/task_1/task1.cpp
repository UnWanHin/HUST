// task1.cpp - 數據壓縮與解壓
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

// 強制 1 字節對齊，模擬緊湊存儲
#pragma pack(1)

const int N = 5;
const int N1 = 2;
const int N2 = 3;

struct student {
    char name[8];
    short age;
    float score;
    char remark[200];
};

student old_s[N], new_s[N];

// 函數聲明
int pack_student_bytebybyte(student* s, int sno, char*& buf);
int pack_student_whole(student* s, int sno, char*& buf);
int restore_student(char* buf, int len, student* s);

void print_student(student* s, int sno) {
    printf("%-9s %-5s %-7s %-32s\n", "name", "age", "score", "remark");
    for (int i = 0; i < sno; ++i) {
        printf("%-9s %-5hd %-7.1f %-32s\n", s[i].name, s[i].age, s[i].score, s[i].remark);
    }
}

int scan_student(student* s, int sno) {
    printf("Please input %d students' information (name age score remark):\n", sno);
    /* 
       Will 18 96 Excellent
       Jerry 19 88.5 Good
       Rose 20 77.5 Fair
       Jack 21 66.5 Poor
       Lily 22 55.5 Fail
    */
    for (int i = 0; i < sno; ++i) {
        scanf("%s %hd %f %s", s[i].name, &s[i].age, &s[i].score, s[i].remark);
    }
    unsigned size = sizeof(student) * sno;
    printf("\nScanned %d students' information\nRaw size: %u bytes.\n\n", sno, size);
    return size;
}

// ---------------- 核心實現 (源自 PDF 報告) ----------------

// 方法1：逐字節壓縮 (利用 vector 輔助)
int pack_student_bytebybyte(student* s, int sno, char*& buf) {
    std::vector<char> aux;
    char* p;
    // const int size = sizeof(student); // 報告中有定義但未使用的變量
    for (int i = 0; i < sno; ++i) {
        p = (char*)(s + i);
        
        // 1. 處理姓名 (遇到 \0 或滿 8 字節停止)
        for (int k = 0; k < 8; ++k) {
            if (p[k] != 0) {
                aux.push_back(p[k]);
            } else {
                break;
            }
        }
        aux.push_back(0); // 添加分隔符
        p += 8; // 跳過 name 字段的 8 字節

        // 2. 處理年齡(short) + 分數(float)
        // 報告邏輯：跳過年齡的高字節 (假設年齡 < 255)
        // age (short) 佔 2 字節，我們只取第 1 個字節
        aux.push_back(*p); 
        
        // 分數 float 佔 4 字節，緊接在 age 的 2 字節之後
        // 所以從 p[2] 開始讀取接下來的 4 個字節
        for (int k = 2; k < 6; k++) {
            aux.push_back(p[k]);
        }
        p += 6; // 跳過 age(2) + score(4)

        // 3. 處理評語
        for (int k = 0; k < 200; ++k) {
            if (p[k] != 0) {
                aux.push_back(p[k]);
            } else {
                break;
            }
        }
        aux.push_back(0);
    }
    
    int len = aux.size();
    buf = new char[len];
    memcpy(buf, aux.data(), len);
    return len;
}

// 方法2：整體寫入壓縮
int pack_student_whole(student* s, int sno, char*& buf) {
    int len = 0;
    // 第一遍循環：計算需要的總長度
    for (int i = 0; i < sno; ++i) {
        len += strlen(s[i].name) + 1;
        // 年齡判斷：如果高位有值則多佔空間(題目簡化處理只取1字節，但此處保留報告邏輯)
        len += 1 + ((s[i].age & 0xFF00) ? 2 : 1); // 這裡報告的邏輯似乎有筆誤，修正為簡單邏輯：只存低位
        // 實際上報告下方代碼只存了1字節，我們按下方實現代碼為準
        
        len += sizeof(float); // float 不壓縮
        len += strlen(s[i].remark) + 1;
    }
    
    // 修正：依照報告實現代碼，上面長度計算可能不準確，改用動態指針寫入最準
    // 為了安全，我們先分配足夠大的空間，最後再調整
    char* temp_buf = new char[sizeof(student) * sno];
    char* p = temp_buf;

    for (int i = 0; i < sno; ++i) {
        // 姓名
        strcpy(p, s[i].name);
        p += strlen(s[i].name) + 1;
        
        // 年齡 (只拷貝低8位)
        memcpy(p, &s[i].age, 1);
        p++;
        
        // 分數
        memcpy(p, &s[i].score, sizeof(float));
        p += sizeof(float);
        
        // 評語
        strcpy(p, s[i].remark);
        p += strlen(s[i].remark) + 1;
    }
    
    int real_len = p - temp_buf;
    buf = new char[real_len];
    memcpy(buf, temp_buf, real_len);
    delete[] temp_buf;
    
    return real_len;
}

// 解壓函數
int restore_student(char* buf, int len, student* s) {
    char* p = buf;
    int sno = 0;
    
    // 防止指針越界
    while (p < (buf + len)) {
        // 1. 還原姓名
        char* pname = s[sno].name;
        // 報告邏輯：拷貝直到遇到 \0
        // 注意：需防止目標數組越界 (最多7個字符 + \0)
        int char_count = 0;
        while (*p != '\0') {
            if(char_count < 7) {
                *(pname++) = *(p++);
                char_count++;
            } else {
                p++; // 忽略超長部分
            }
        }
        *pname = '\0'; // 補結束符
        // 如果原始長度小於7，報告中有個邏輯 *pname = '0' 似乎是筆誤，應為補0
        // 這裡我們確保結構體剩餘部分清零
        memset(pname + 1, 0, 7 - char_count);
        
        p++; // 跳過壓縮數據中的 \0

        // 2. 還原年齡 (取1字節放到低位，高位補0)
        char* p_age = (char*)&s[sno].age;
        p_age[0] = *(p++);
        p_age[1] = 0;

        // 3. 還原分數 (直接拷貝4字節)
        char* p_score = (char*)&s[sno].score;
        for (int k = 0; k < sizeof(float); ++k) {
            p_score[k] = *(p++);
        }

        // 4. 還原評語
        char* p_remark = s[sno].remark;
        while (*p != '\0') {
            *(p_remark++) = *(p++);
        }
        *p_remark = '\0';
        p++;

        sno++;
    }
    return sno;
}

int main() {
    // 設置控制台輸出為 UTF-8 (避免中文亂碼，配合你的環境)
    // 如果你已經開啟系統 Beta UTF-8，這行可能不需要
    // system("chcp 65001"); 

    int raw_size = scan_student(old_s, N);
    
    char *buf1 = nullptr, *buf2 = nullptr;
    
    // 前 N1 個用方法1壓縮
    int len1 = pack_student_bytebybyte(old_s, N1, buf1);
    // 後 N2 個用方法2壓縮
    int len2 = pack_student_whole(old_s + N1, N2, buf2); // 注意指針偏移
    
    printf("\nCompressed size: %d bytes.\nCompress ratio: %.2f%%\n\n", 
           len1 + len2, 100.0 * (len1 + len2) / raw_size);

    // 解壓
    restore_student(buf1, len1, new_s);
    restore_student(buf2, len2, new_s + N1);
    
    printf("--- Restored Data ---\n");
    print_student(new_s, N);

    delete[] buf1;
    delete[] buf2;
    return 0;
}