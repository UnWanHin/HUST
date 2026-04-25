#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    cout << "=== UTF-8 編碼測試 ===" << endl;
    cout << endl;
    
    // 繁體中文
    cout << "繁體中文：數據、軟體、網絡、資料庫" << endl;
    cout << "Traditional: 學習、開發、程式設計" << endl;
    cout << endl;
    
    // 簡體中文  
    cout << "?体中文：?据、?件、网?、?据?" << endl;
    cout << "Simplified: ??、??、程序??" << endl;
    cout << endl;
    
    // 混合使用
    cout << "混合：繁體的軟體 + ?体的?件 = UTF-8 萬能！" << endl;
    cout << endl;
    
    // 其他語言也可以
    cout << "日文：?????、???????" << endl;
    cout << "韓文：?????, ?????" << endl;
    cout << "英文：Hello, Programming!" << endl;
    
    return 0;
}
