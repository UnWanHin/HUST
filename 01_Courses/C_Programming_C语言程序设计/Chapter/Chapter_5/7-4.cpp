#include <stdio.h>
struct bits {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
};
void f0(int b) {
    printf("the function %d is called!\n", b);
}

void f1(int b) {
    printf("the function %d is called!\n", b);
}

void f2(int b) {
    printf("the function %d is called!\n", b);
}

void f3(int b) {
    printf("the function %d is called!\n", b);
}

void f4(int b) {
    printf("the function %d is called!\n", b);
}

void f5(int b) {
    printf("the function %d is called!\n", b);
}

void f6(int b) {
    printf("the function %d is called!\n", b);
}

void f7(int b) {
    printf("the function %d is called!\n", b);
}
int main() {
    struct bits byte;
    int num;
    scanf("%d", &num);
    byte.bit0 = num & 1;
    byte.bit1 = (num >> 1) & 1;
    byte.bit2 = (num >> 2) & 1;
    byte.bit3 = (num >> 3) & 1;
    byte.bit4 = (num >> 4) & 1;
    byte.bit5 = (num >> 5) & 1;
    byte.bit6 = (num >> 6) & 1;
    byte.bit7 = (num >> 7) & 1;
    void (*p_fun[8])(int) = {f0, f1, f2, f3, f4, f5, f6, f7};
    for (int i = 0; i < 8; i++) {
        if (byte.bit0 + byte.bit1 + byte.bit2 + byte.bit3 + byte.bit4 + byte.bit5 + byte.bit6 + byte.bit7 > 0) {
            int index = 0;
            while (byte.bit0 + byte.bit1 + byte.bit2 + byte.bit3 + byte.bit4 + byte.bit5 + byte.bit6 + byte.bit7 > 0) {
                if (byte.bit0 == 1) {
                    p_fun[0](0);
                    byte.bit0 = 0;
                }
                else if (byte.bit1 == 1) {
                    p_fun[1](1);
                    byte.bit1 = 0;
                }
                else if (byte.bit2 == 1) {
                    p_fun[2](2);
                    byte.bit2 = 0;
                }
                else if (byte.bit3 == 1) {
                    p_fun[3](3);
                    byte.bit3 = 0;
                }
                else if (byte.bit4 == 1) {
                    p_fun[4](4);
                    byte.bit4 = 0;
                }
                else if (byte.bit5 == 1) {
                    p_fun[5](5);
                    byte.bit5 = 0;
                }
                else if (byte.bit6 == 1) {
                    p_fun[6](6);
                    byte.bit6 = 0;
                }
                else if (byte.bit7 == 1) {
                    p_fun[7](7);
                    byte.bit7 = 0;
                }
            }
            break;
        }
    }
    return 0;
}
