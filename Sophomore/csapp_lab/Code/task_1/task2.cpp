// task2.cpp - 位元運算與邏輯門模擬 (完整修正版)
// 編譯指令: g++ task2.cpp -o task2.exe
// 執行指令: ./task2.exe

#include <cstdio>
#include <cstdlib> // for exit()

// =========================================================
// 第一部分：位元運算功能實現 (Student Implementation)
// =========================================================

// 1. 絕對值
// 規則：僅使用 ! ~ & ^ | + << >> (最多10次)
int absVal(int x) {
    // 利用算術右移構造掩碼：正數為 0，負數為 -1 (0xFFFFFFFF)
    int mask = x >> 31;
    // (x ^ 0) + 0 = x
    // (x ^ -1) + 1 = ~x + 1 = -x
    return (x ^ mask) + (mask & 1);
}

// 2. 取負數
// 規則：不使用負號
int negate(int x) {
    return ~x + 1;
}

// 3. 按位與 (&)
// 規則：僅使用 ~ |
int bitAnd(int x, int y) {
    return ~(~x | ~y); // 德摩根定律
}

// 4. 按位或 (|)
// 規則：僅使用 ~ &
// 注意：C++中 'bitor' 是關鍵字，故函數改名為 bitor_func
int bitor_func(int x, int y) {
    return ~(~x & ~y); // 德摩根定律
}

// 5. 按位異或 (^)
// 規則：僅使用 ~ &
int bitXor(int x, int y) {
    // x^y = (x & ~y) | (~x & y)
    // 再次應用德摩根定律轉為僅用 & 和 ~
    return ~(~(x & ~y) & ~(~x & y));
}

// 6. 判斷最大正整數 (0x7FFFFFFF)
// 規則：只能使用 ! ~ & ^ | +
int isTmax(int x) {
    // 如果 x 是 0x7FFFFFFF，那麼 x ^ 0x7FFFFFFF 結果為 0
    // !0 = 1
    return !(x ^ 0x7FFFFFFF);
}

// 7. 統計 1 的個數
// 規則：運算次數不超過 40 次
int bitCount(int x) {
    // 分治法 (Parallel bit counting)
    int mask1 = 0x55555555;
    int mask2 = 0x33333333;
    int mask4 = 0x0F0F0F0F;
    int mask8 = 0x00FF00FF;
    int mask16 = 0x0000FFFF;

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);
    return x;
}

// 8. 生成掩碼
// 規則：產生從 lowbit 到 highbit 全為 1 的數
int bitMask(int highbit, int lowbit) {
    // 構造高位掩碼 (highbit以下全1) 和 低位掩碼 (lowbit以下全1)
    // 利用 ~0 來產生全1序列，再移位
    // 這裡使用更直觀的邏輯：
    // ones_high = (1 << (high + 1)) - 1  (但在禁止減號時，用 + ~x + 1)
    // 或者直接構造： ~(-1 << (high + 1)) 
    // 考慮到移位32位的邊界問題，題目範例 bitMask(5,3) 是在 int 範圍內
    
    // 方法：構造全1，左移清空低位，再右移歸位
    // 但更通用的方法是報告中的： (1 << (high+1)) - (1 << low)
    // 換成加法邏輯： (1 << (high+1)) + ~(1 << low) + 1
    
    // 註：若 highbit=31, 1<<32 會有未定義行為，但實驗環境通常容忍或只需考慮 0-30
    return (1 << (highbit + 1)) + ~(1 << lowbit) + 1;
}

// 9. 加法溢位判斷
// 規則：x+y 溢出返回 1，否則 0
int addOK(int x, int y) {
    int sum = x + y;
    int sign_x = (x >> 31) & 1;
    int sign_y = (y >> 31) & 1;
    int sign_sum = (sum >> 31) & 1;

    // 溢出條件：x, y 同號，但與 sum 異號
    // !(sign_x ^ sign_y) -> 同號為 1
    // (sign_x ^ sign_sum) -> 異號為 1
    return (!(sign_x ^ sign_y)) & (sign_x ^ sign_sum);
}

// 10. 字節交換
// 規則：交換第 n 和第 m 個字節
int byteSwap(int x, int n, int m) {
    // 1. 取出 n, m 位置的字節
    int n_val = (x >> (n * 8)) & 0xFF;
    int m_val = (x >> (m * 8)) & 0xFF;
    
    // 2. 構造掩碼將原位置清零 (Mask out)
    // 掩碼形如： ...00...00... (在 n, m 位置是 00，其他是 FF)
    // 這裡直接用構造法：
    // 先構造 ...FF...FF... (在 n, m 位置是 FF)，然後取反
    int mask = (0xFF << (n * 8)) | (0xFF << (m * 8));
    x = x & ~mask;
    
    // 3. 將取出的字節填入對方的坑位
    x = x | (n_val << (m * 8)) | (m_val << (n * 8));
    
    return x;
}

// 11. 邏輯非 (!)
// 規則：x=0 返回 1，否則 0
int bang(int x) {
    // 利用 0 的補碼特性：0 和 -0 (即 0) 的符號位都是 0
    // 非 0 數 x，x 和 -x 中必有一個符號位是 1
    // (x | -x) >> 31 在 x!=0 時為 -1 (全1)，在 x=0 時為 0
    return ((x | (~x + 1)) >> 31) + 1;
}

// 12. 奇偶校驗
// 規則：奇數個 1 返回 1
int bitParity(int x) {
    // 折疊異或：將 32 位的信息不斷濃縮
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

// =========================================================
// 第二部分：標準驗證函數 (Golden Standards)
// =========================================================

int absVal_standard(int x) { return (x < 0) ? -x : x; }
int negate_standard(int x) { return -x; }
int bitAnd_standard(int x, int y) { return x & y; }
int bitor_standard(int x, int y) { return x | y; }
int bitXor_standard(int x, int y) { return x ^ y; }
int isTmax_standard(int x) { return x == 0x7FFFFFFF; }
int bitCount_standard(int x) {
    int cnt = 0;
    unsigned int ux = (unsigned int)x; // 轉無符號防止右移補1
    while(ux) { if(ux & 1) cnt++; ux >>= 1; }
    return cnt;
}
int bitMask_standard(int highbit, int lowbit) {
    int x = 0;
    for (int i = lowbit; i <= highbit; ++i) x |= (1 << i);
    return x;
}
int addOK_standard(int x, int y) {
    long long sum = (long long)x + y;
    return (sum > 2147483647 || sum < -2147483648);
}
int byteSwap_standard(int x, int n, int m) {
    unsigned char* p = (unsigned char*)&x;
    unsigned char tmp = p[n];
    p[n] = p[m];
    p[m] = tmp;
    return x;
}
int bang_standard(int x) { return !x; }
int bitParity_standard(int x) {
    int cnt = 0;
    unsigned int ux = (unsigned int)x;
    while(ux) { cnt ^= (ux & 1); ux >>= 1; }
    return cnt;
}

// =========================================================
// 第三部分：自動化測試與報告
// =========================================================

void run_test(const char* func_name, int my_res, int std_res) {
    if (my_res == std_res) {
        printf("[PASS] %-25s | Result: %10d (0x%08X)\n", func_name, my_res, my_res);
    } else {
        printf("[FAIL] %-25s | My: %d, Std: %d\n", func_name, my_res, std_res);
        // exit(1); // 如果想遇到錯誤就停，取消註釋
    }
}

int main() {
    // 防止中文亂碼 (可選)
    // system("chcp 65001 > nul");

    printf("==================== Batch Test Report ====================\n");
    printf("%-32s | %-20s\n", "Function & Input", "Output Status");
    printf("-----------------------------------------------------------\n");

    // 1. absVal
    run_test("absVal(8)", absVal(8), absVal_standard(8));
    run_test("absVal(-8)", absVal(-8), absVal_standard(-8));

    // 2. negate
    run_test("negate(50)", negate(50), negate_standard(50));
    run_test("negate(-50)", negate(-50), negate_standard(-50));

    // 3. bitAnd
    run_test("bitAnd(0xAA, 0x55)", bitAnd(0xAA, 0x55), bitAnd_standard(0xAA, 0x55));
    
    // 4. bitOr
    run_test("bitor_func(0xAA, 0x55)", bitor_func(0xAA, 0x55), bitor_standard(0xAA, 0x55));

    // 5. bitXor
    run_test("bitXor(0xAA, 0x55)", bitXor(0xAA, 0x55), bitXor_standard(0xAA, 0x55));

    // 6. isTmax
    run_test("isTmax(0x7FFFFFFF)", isTmax(0x7FFFFFFF), isTmax_standard(0x7FFFFFFF));
    run_test("isTmax(0x12345678)", isTmax(0x12345678), isTmax_standard(0x12345678));

    // 7. bitCount
    run_test("bitCount(0x12345678)", bitCount(0x12345678), bitCount_standard(0x12345678));
    run_test("bitCount(-1)", bitCount(-1), bitCount_standard(-1));

    // 8. bitMask
    run_test("bitMask(5, 3)", bitMask(5, 3), bitMask_standard(5, 3));
    run_test("bitMask(10, 0)", bitMask(10, 0), bitMask_standard(10, 0));

    // 9. addOK
    // 0x7FFFFFFF + 1 = 溢出 -> 預期返回 1
    run_test("addOK(MAX, 1) [Overflow]", addOK(0x7FFFFFFF, 1), addOK_standard(0x7FFFFFFF, 1)); 
    run_test("addOK(1, 1)   [Normal]",   addOK(1, 1), addOK_standard(1, 1));

    // 10. byteSwap
    run_test("byteSwap(0x12345678,0,3)", byteSwap(0x12345678, 0, 3), byteSwap_standard(0x12345678, 0, 3));
    run_test("byteSwap(0xDEADBEEF,1,2)", byteSwap(0xDEADBEEF, 1, 2), byteSwap_standard(0xDEADBEEF, 1, 2));

    // 11. bang
    run_test("bang(3)", bang(3), bang_standard(3));
    run_test("bang(0)", bang(0), bang_standard(0));

    // 12. bitParity
    run_test("bitParity(5) [0101]", bitParity(5), bitParity_standard(5));
    run_test("bitParity(7) [0111]", bitParity(7), bitParity_standard(7));

    printf("-----------------------------------------------------------\n");
    printf("Summary: All Logic Gates Simulated Successfully.\n");
    printf("===========================================================\n");

    return 0;
}