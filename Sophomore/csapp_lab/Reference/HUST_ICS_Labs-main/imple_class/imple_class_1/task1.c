#include <stdio.h>
#include <string.h>

const int N = 5;
const int N1 = 2;
const int N2 = 3;

typedef struct {
    char name[8];
    short age;
    float score;
    char remark[200];
} student;

int pack_student_bytebybyte(student*, int, char*);
int pack_student_whole(student*, int, char*);

int restore_student(char*, int, student*);

int main() {
    student old_s[N], new_s[N];
    for (int i = 0; i < N; ++i) {
        scanf("%s", old_s[i].name);
        scanf("%hd", &old_s[i].age);
        if (i == 0) {
            int nlen = strlen(old_s[i].name);
            char* a = &old_s[i].name[nlen - 2];
            old_s[i].score = ((*a) ^ 48) * 10 + ((*(a + 1)) ^ 48);
        }
        else scanf("%f", &old_s[i].score);
        scanf("%s", old_s[i].remark);
    }
    char info[3000], message[3000];
    int len_bbb = pack_student_bytebybyte(&old_s[0], N1, info);
    int len_w   = pack_student_whole(&old_s[2], N2, info + len_bbb);

    printf("total length:> %d + %d == %d\n", len_bbb, len_w, len_bbb + len_w);
    for (int i = 0; i < len_bbb + len_w; ++i) {
        if (info[i] == '\0')
            printf("\0 ");
        else {
            if (info[i] < 10)
                printf("\*%d ", info[i]);
            else printf("%c ", info[i]);
        }
    }
    puts("");

    strncpy(message, info, 20);

    restore_student(info, len_bbb + len_w, new_s);
    return 0;
}

int pack_student_bytebybyte(student* s, int sno, char* buf) {
    char* p = buf;
    int tmp;
    for (int i = 0; i < sno; ++i) {

        for (int j = 0; j < 8; ++j) {
            *(p++) = s[i].name[j];
            if (s[i].name[j] == '\0')
                break;
        }
        tmp = s[i].age;
        for (int j = 0; j < 2; ++j) {
            *(p++) = tmp % 10;
            tmp /= 10;
        }

        int integ = (int)(s[i].score);
        for (int j = 0; j < 3; ++j) {
            *(p++) = integ % 10;
            integ /= 10;
        }
        *(p++) = '.';
        float res = s[i].score - (int)(s[i].score);
        for (int j = 0; j < 4; ++j) {
            *(p++) = (int)(res * 10);
            printf("get number %d\n", (int)(res * 10));
            res = res * 10 - (int)(res * 10);
        }

        for (int j = 0; j < 200; ++j) {
            *(p++) = s[i].remark[j];
            if (s[i].remark[j] == '\0') break;
        }
    }
    return p - buf;
}

int pack_student_whole(student* s, int sno, char* buf) {
    char* p = buf;
    char str[500]; int len;
    int tmp;
    for (int i = 0; i < sno; ++i) {

        for (int j = 0; j < 8; ++j) {
            *(p++) = s[i].name[j];
            if (s[i].name[j] == '\0')
                break;
        }

        len = 0; tmp = s[i].age;
        for (int j = 0; j < 2; ++j) {
            str[len++] = tmp % 10;
            tmp /= 10;
        }
        strncpy(p, str, len);
        p += len;
        
        len = 0;
        int integ = (int)(s[i].score);
        for (int j = 0; j < 3; ++j) {
            str[len++] = integ % 10;
            integ /= 10;
        }
        str[len++] = '.';
        float res = s[i].score - (int)(s[i].score);
        for (int j = 0; j < 4; ++j) {
            str[len++] = (int)(res * 10);
            res = res * 10 - (int)(res * 10);
        }
        strncpy(p, str, len);
        p += len;

        for (int j = 0; j < 200; ++j) {
            *(p++) = s[i].remark[j];
            if (s[i].remark[j] == '\0')
                break;
        }
    }
    return p - buf;
}

int restore_student(char* buf, int len, student* s) {
    char* p = buf; int i = -1;
    while (p - buf < len) {
        ++i;

        for (int j = 0; j < 8; ++j) {
            s[i].name[j] = *(p++);
            if (s[i].name[j] == '\0')
                break;
        }

        s[i].score = 0;
        for (int j = 0; j < 2; ++j)
            s[i].score = s[i].score * 10 + *(p++);
        ++p; // for char '.'
        float pw = 0.1;
        for (int j = 0; j < 4; ++j) {
            s[i].score += (*(p++)) * pw;
            pw *= 0.1;
        }

        for (int j = 0; j < 200; ++j) {
            s[i].remark[j] = *(p++);
            if (s[i].remark[j] == '\0')
                break;
        }
    }
    return i + 1;
}