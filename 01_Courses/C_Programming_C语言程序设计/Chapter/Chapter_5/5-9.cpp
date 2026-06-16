#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strnins(char t[], char s[], int n);
int main() {
    char t[100], s[100];
    int n;
    scanf("%s", t);
    scanf("%s", s);
    scanf("%d", &n);
    strnins(t, s, n);
    printf("%s\n", t);
    return 0;
}
void strnins(char t[], char s[], int n) {
    int len_t = strlen(t);
    int len_s = strlen(s);
    int i, j;
    char temp[len_t + len_s + 1];
    for (i = 0; i < n; i++) {
        temp[i] = t[i];
    }
    for (j = 0; j < len_s; j++) {
        temp[i++] = s[j];
    }
    for (j = n; j < len_t; j++) {
        temp[i + (j - n)] = t[j];
    }
	temp[i + (j - n)] = '\0';
    strcpy(t, temp);
}
