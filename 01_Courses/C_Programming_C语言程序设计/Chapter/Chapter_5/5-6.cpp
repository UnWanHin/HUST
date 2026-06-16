#include <stdio.h>
#include <stdlib.h>
#define BITS 32
void intToBinaryString(int num, char binaryStr[]) {
    int i;
    for (i = BITS - 1; i >= 0; i--) {
        binaryStr[i] = (num & (1 << (BITS - 1 - i)))? '1' : '0';
    }
    binaryStr[BITS] = '\0';
}
int main() {
    int num;
    char binaryStr[BITS + 1];
    scanf("%d", &num);
    intToBinaryString(num, binaryStr);
    for (int i = 0; i < BITS; i++) {
        printf("%c", binaryStr[i]);
        if ((i + 1) % 4 == 0 && i!= BITS - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
