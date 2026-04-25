#include <stdio.h>
#include <stdlib.h>
struct s_list {
    int data;
    struct s_list *next;
};
void create_list(struct s_list **headp, int *p, int n);
int main(void) {
    struct s_list *head = NULL, *p;
    int s[100];  
    int i = 0;
    int num;
    scanf("%d", &num);
    while (num!= 0) {
        s[i++] = num;
        scanf("%d", &num);
    }
    create_list(&head, s, i);
    p = head;
    while (p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
void create_list(struct s_list **headp, int *p, int n) {
    struct s_list *loc_head = NULL, *tail;
    if (n == 0) {  
        return;
    }
    else {
        loc_head = (struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data = *p++;
        tail = loc_head;
        for (int i = 1; i < n; i++) {
            tail->next = (struct s_list *)malloc(sizeof(struct s_list));
            tail = tail->next;
            tail->data = *p++;
        }
        tail->next = NULL;
        *headp = loc_head; 
    }
}
