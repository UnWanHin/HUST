#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strcate(char t[], char s[]);
void strdelc(char s[], char c);
int main()
{
    char a[100], b[100];
    char c;
    scanf("%s %s %c", b, a, &c);
    strcate(b, a);
    printf("%s\n", b);
    strdelc(b, c);
    printf("%s\n", b);
    return 0;
}
void strcate(char t[], char s[])
{
    int i = 0, j = 0;
    while (t[i]!= '\0') {
        i++;
    }
    while (s[j]!= '\0') {
        t[i++] = s[j++];
    }
    t[i] = '\0';
}
void strdelc(char s[], char c)
{
    int j, k;
    for (j = k = 0; s[j]!= '\0'; j++) {
        if (s[j]!= c) {
            s[k++] = s[j];
        }
    }
    s[k] = '\0';
}
