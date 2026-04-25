#include "stdio.h"

void print() {
    puts("U2023*****");
    return ;
}

void (*myprint)() = print;

// char myprint[15] = {"U2023*****"};