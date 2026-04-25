#include <stdio.h>

// 1. 定義我們自己的打印函數
void print_my_id() {
    printf("U202490035\n");
}

// 2. 定義強符號 myprint
// 關鍵點：這是一個函數指針變量，並初始化指向我們的 print_my_id 函數。
// 因為它被初始化了，所以它是強符號 (Strong Symbol)。
// 鏈接器會優先使用這個 myprint，忽略 phase6.o 裡那個弱的 myprint。
void (*myprint)() = print_my_id;