#include <stdio.h>

int absVal(int);
int negate(int);
int bitAnd(int, int);
int bitOr(int, int);
int bitXor(int, int);
int isTmax(int);
int bitCount(int);
int bitMask(int, int);
int andOK(int, int);
int byteSwap(int, int, int);

int main() {
    printf("%d\n", absVal(3));
    return 0;
}

int absVal(int x) { return (x >> 31)? negate(x): x; }

int negate(int x) { return (~x) + 1; }

int bitAnd(int x, int y) { return ~((~x) | (~y)); }

int bitOr(int x, int y) { return ~((~x) & (~y)); }

int bitXor(int x, int y) { return bitOr(x, y) & (x & y); }

int isTmax(int x) { return !(x ^ 0x7fffffff); }

int bitCount(int x) {
    int cnt[] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
    int ret = 0;
    while (x) {
        ret = ret + cnt[x & 0xf];
        x >>= 4;
    }
    return ret;
}

int bitMask(int highbit, int lowbit) {
    /* @warning overflow when highbit == 31 */
    return ((1 << highbit + 1) - 1) ^ ((1 << lowbit) - 1);
}

int addOK(int x, int y) {
    return (~((x >> 31) & (y >> 31))) & ((x + y) >> 31);
}

// 24 times of operation
int byteSwap(int x, int n, int m) {
    // ((x >> (1 << n << 2)) & 0xf)
    // ((x >> (1 << m << 2)) & 0xf)
    return (x & (0xf << (1 << (n << 2))) & (0xf << (1 << (m << 2))))
         ^ (((x >> (1 << (n << 2))) & 0xf) << (1 << (m << 2)))
         ^ (((x >> (1 << (m << 2))) & 0xf) << (1 << (n << 2)));
}