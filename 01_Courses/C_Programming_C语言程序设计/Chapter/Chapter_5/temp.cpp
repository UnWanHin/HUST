#include <stdio.h>
#include <stdlib.h>

struct s_list
{
    int data;
    struct s_list *next;
};

void create_list(struct s_list **headp, int *p);
int main(void)
{
    struct s_list *head = NULL;
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    create_list(&head, s);
    struct s_list *p = head;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}

void create_list(struct s_list **headp, int *p)
{
    struct s_list *new_node;
    if (*p == 0)
    {
        return;
    }
    else
    {
        while (*p!= 0)
        {
            new_node = (struct s_list *)malloc(sizeof(struct s_list));
            new_node->data = *p++;
            new_node->next = *headp;
            *headp = new_node;
        }
    }
}
