#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct C_NODE {
    char data;
    struct C_NODE *next;
} C_NODE;
void createLinkList(C_NODE **headp, char s[]) 
{
    C_NODE *tail;
    *headp = NULL;
    tail = NULL;
    for(int i = 0; i < strlen(s); i++) {
        C_NODE *temp = (C_NODE *)malloc(sizeof(C_NODE));
        temp->data = s[i];
        temp->next = NULL;
        if (*headp == NULL) {
            *headp = temp; 
        } else {
            tail->next = temp; 
        }
        tail = temp; 
    }
}
void judgePalindrome(C_NODE *head)
{
    char c[1000];
    int l = 0;
    while(head != NULL) {
        c[l++] = head->data;
        head = head->next;
    }
    for (int i = 0; i < l / 2; i++) {
        if (c[i] != c[l - i - 1]) {
            printf("false\n");
            return;
        }
    }
    printf("true\n");
}
int main() {
    C_NODE *head = NULL;
    char inputString[1000];
    fgets(inputString, sizeof(inputString), stdin);
    size_t len = strlen(inputString);
    if (len > 0 && inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
    }
    createLinkList(&head, inputString);
    judgePalindrome(head);
    C_NODE *current = head;
    while (current != NULL) {
        C_NODE *next = current->next;
        free(current);
        current = next;
    }
    return 0;
}
