/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct LNode {
    char Name[100];
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct TableNode {
    char name[100];
    LinkList L;
    struct TableNode *next;
} TableNode, *TableList;

ElemType count = 0;
LinkList L;
TableList Tables = NULL;

/*-----page 19 on textbook ---------*/
status InitList(LinkList *L);
status DestroyList(LinkList *L);
status ClearList(LinkList *L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType *e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType cur, ElemType *pre_e);
status NextElem(LinkList L, ElemType cur, ElemType *next_e);
status ListInsert(LinkList *L, int i, const char *name, ElemType e);
status ListDelete(LinkList *L, int i, ElemType *e);
status ListTraverse(LinkList L);

// 比?函?，用于 qsort
int compare(const void *a, const void *b) {
    return (*(ElemType *)a - *(ElemType *)b);
}

status sortList(LinkList *L) {
    if (*L == NULL) return INFEASIBLE;
    int len = ListLength(*L);
    ElemType *arr = (ElemType *)malloc(len * sizeof(ElemType));
    LinkList p = (*L)->next;
    int i = 0;
    while (p != NULL) {
        arr[i++] = p->data;
        p = p->next;
    }
    qsort(arr, len, sizeof(ElemType), compare);
    p = (*L)->next;
    i = 0;
    while (p != NULL) {
        p->data = arr[i++];
        p = p->next;
    }
    free(arr);
    return OK;
}

status SaveList(LinkList L, char FileName[]) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    FILE *fp = fopen(FileName, "w");
    if (fp == NULL) {
        return INFEASIBLE;
    }
    LinkList p = L->next;
    while (p != NULL) {
        fprintf(fp, "%s %d\n", p->Name, p->data);
        p = p->next;
    }
    fclose(fp);
    return OK;
}

status LoadList(LinkList *L, char FileName[]) {
    if (*L != NULL) {
        DestroyList(L);
    }
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    FILE *fp = fopen(FileName, "r");
    if (fp == NULL) {
        return INFEASIBLE;
    }
    LinkList tail = *L;
    ElemType elem;
    char name[100];
    while (fscanf(fp, "%s %d", name, &elem) == 2) {
        LinkList newNode = (LinkList)malloc(sizeof(LNode));
        strcpy(newNode->Name, name);
        newNode->data = elem;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    fclose(fp);
    return OK;
}

status AddList(TableList *T, char ListName[]) {
    TableNode *newTable = (TableNode *)malloc(sizeof(TableNode));
    if (!newTable) return OVERFLOW;
    strcpy(newTable->name, ListName);
    InitList(&(newTable->L));
    newTable->next = *T;
    *T = newTable;
    return OK;
}

status RemoveList(TableList *T, char ListName[]) {
    TableNode *prev = NULL;
    TableNode *curr = *T;
    while (curr != NULL) {
        if (strcmp(curr->name, ListName) == 0) {
            if (prev == NULL) {
                *T = curr->next;
            } else {
                prev->next = curr->next;
            }
            DestroyList(&(curr->L));
            free(curr);
            return OK;
        }
        prev = curr;
        curr = curr->next;
    }
    return ERROR;
}

int LocateList(TableList T, char ListName[]) {
    TableNode *p = T;
    int i = 1;
    while (p != NULL) {
        if (strcmp(p->name, ListName) == 0) {
            count = i;
            if (L != NULL) {
                DestroyList(&L);
            }
            InitList(&L);
            LinkList temp = p->L->next;
            int j = 1;
            while (temp != NULL) {
                ListInsert(&L, j++, temp->Name, temp->data);
                temp = temp->next;
            }
            return i;
        }
        p = p->next;
        i++;
    }
    return 0;
}

status reverseList(LinkList *L) {
    if (*L == NULL) return INFEASIBLE;
    LinkList prev = NULL;
    LinkList current = (*L)->next;
    LinkList next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*L)->next = prev;
    return OK;
}

status RemoveNthFromEnd(LinkList *L, int n) {
    if (*L == NULL) return INFEASIBLE;
    LinkList slow = *L;
    LinkList fast = *L;
    int i;
    for (i = 0; i < n; i++) {
        if (fast->next == NULL) {
            if (i == n - 1) {
                LinkList temp = *L;
                *L = (*L)->next;
                free(temp);
                return OK;
            }
            return ERROR;
        }
        fast = fast->next;
    }
    LinkList prev = *L;
    while (fast->next != NULL) {
        prev = prev->next;
        fast = fast->next;
    }
    LinkList temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return OK;
}

int main() {
    int op = 1, op1 = 1, op0 = 4, result, tp, e, n;
    char name[100];
    char s1[100];
    char nodeName[100];

op0:
    while (op0) {
        system("cls");
        printf("\n\n");
        printf("\t      Menu for Linear Table On Sequence Structure \n");
        printf("\t-------------------------------------------------\n");
        printf("\t    	  1. 多表管理       \t2. 對當前表操作\n");
        printf("\t    	  0.結束\n       ");
        printf("\t-------------------------------------------------\n");

        printf("    請選擇你的操作[0~2]:");
        scanf("%d", &op0);
        switch (op0) {
            case 1:
                op1 = 100;
                goto op1;
                break;
            case 2:
                op = 100;
                goto op;
                break;
            case 0:
                printf("GG\n");
                return 0;
            default:
                printf("無效輸入請重新輸入\n");
        }
        system("pause");
    }
op1:
    while (op1) {
        system("cls");
        printf("\n\n");
        printf("\t      Menu for Linear Table On Sequence Structure \n");
        printf("\t-------------------------------------------------\n");
        printf("\t    	  1. 創立表      \t3. 刪除表\n");
        printf("\t    	  2. 查找表      \t0. 返回\n");
        printf("\t------------------------------------------------\n");

        printf("    請選擇你的操作[0~3]:\n");
        scanf("%d", &op1);
        switch (op1) {
            case 1:
                printf("Name for the new list\n");
                scanf("%s", name);
                result = AddList(&Tables, name);
                if (result == OK) printf("success\n");
                break;
            case 2:
                printf("Name for the list\n");
                scanf("%s", name);
                result = LocateList(Tables, name);
                if (result != 0) printf("success\n");
                if (result == 0) printf("查無此表\n");
                break;
            case 3:
                printf("Delete the List:(input list's name)\n");
                scanf("%s", name);
                result = RemoveList(&Tables, name);
                if (result == OK) {
                    printf("OK\n");
                } else {
                    printf("刪除失敗\n");
                }
                break;
            case 0:
                op0 = 4;
                goto op0;
                break;
            default:
                printf("輸入有誤，請重新輸入\n");
                break;
        }
        system("pause");
    }
op:
    while (op) {
        system("cls");
        printf("\n\n");
        printf("\t      Menu for Linear Table On Sequence Structure \n");
        printf("\t-------------------------------------------------\n");
        printf("\t    	  1. InitList       \t7. LocateElem\n");
        printf("\t    	  2. DestroyList    \t8. PriorElem\n");
        printf("\t    	  3. ClearList       \t9. NextElem \n");
        printf("\t    	  4. ListEmpty     \t10. ListInsert\n");
        printf("\t    	  5. ListLength     \t11. ListDelete\n");
        printf("\t    	  6. GetElem       \t12. ListTraverse\n\n");
        printf("\t    	  13. ReverseList  \t14. RemoveNthFromEnd\n");
        printf("\t    	  15. sortList      \t16. SaveList\n");
        printf("\t    	  17. LoadList");
        printf("\t          0. turn back\n");
        printf("\t-------------------------------------------------\n");
        printf("    請選擇你的操作[0~18]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                result = InitList(&L);
                if (result == OK) printf("OK\n");
                if (result == INFEASIBLE) printf("線性表已存在！\n");
                break;
            case 2:
                result = DestroyList(&L);
                if (result == OK) printf("OK\n");
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                break;
            case 3:
                result = ClearList(&L);
                if (result == OK) printf("OK\n");
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                break;
            case 4:
                result = ListEmpty(L);
                if (result == TRUE) printf("線性表為空！\n");
                if (result == FALSE) printf("線性表不為空！\n");
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                break;
            case 5:
                result = ListLength(L);
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("線性表長度為%d\n", result);
                break;
            case 6:
                printf("獲取線性表的第i個元素：");
                scanf("%d", &tp);
                result = GetElem(L, tp, &e);
                if (result == ERROR) printf("查找失敗！\n");
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                if (result == OK) printf("第%d個元素為%d\n", tp, e);
                break;
            case 7:
                printf("輸入你要查找的元素：");
                scanf("%d", &tp);
                result = LocateElem(L, tp);
                if (result == ERROR) printf("查找失敗！\n");
                else if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("元素%d 在第%d個位置\n", tp, result);
                break;
            case 8:
                printf("輸入你要查找的元素前驅：");
                scanf("%d", &tp);
                result = PriorElem(L, tp, &e);
                if (result == ERROR) printf("查找失敗！\n");
                else if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("%d的前驅為%d\n", tp, e);
                break;
            case 9:
                printf("輸入你要查找的元素後繼：");
                scanf("%d", &tp);
                result = NextElem(L, tp, &e);
                if (result == ERROR) printf("查找失敗！\n");
                else if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("%d的後繼為%d\n", tp, e);
                break;
            case 10:
                printf("輸入在第i個元素前插入的元素的名?和值：");
                scanf("%s %d %d", nodeName, &tp, &e);
                result = ListInsert(&L, tp, nodeName, e);
                if (result == ERROR) printf("插入失敗！\n");
                else if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("OK\n");
                break;
            case 11:
                printf("輸入你要刪除的第i個元素：");
                scanf("%d", &tp);
                result = ListDelete(&L, tp, &e);
                if (result == ERROR) printf("刪除失敗！\n");
                else if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("已刪除第%d個元素%d\n", tp, e);
                break;
            case 12:
                result = ListTraverse(L);
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                break;
            case 13:
                result = reverseList(&L);
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("?表已翻?\n");
                break;
            case 14:
                printf("?入要?除的倒?第n???：");
                scanf("%d", &n);
                result = RemoveNthFromEnd(&L, n);
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                else if (result == ERROR) printf("?除失?！\n");
                else printf("已?除倒?第%d???\n", n);
                break;
            case 15:
                result = sortList(&L);
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("?表已排序\n");
                break;
            case 16:
                printf("輸入保存文件名: ");
                scanf("%s", s1);
                result = SaveList(L, s1);
                if (result == INFEASIBLE) printf("線性表不存在！\n");
                else printf("保存成功\n");
                break;
            case 17:
                printf("輸入加載文件名: ");
                scanf("%s", s1);
                result = LoadList(&L, s1);
                if (result == INFEASIBLE) printf("文件加?失?！\n");
                else printf("加?成功\n");
                break;
            case 0:
                // 操作完把 L 复制回??表
                if (count > 0) {
                    TableNode *p = Tables;
                    for (int i = 1; i < count; i++) {
                        p = p->next;
                    }
                    if (p != NULL) {
                        DestroyList(&(p->L));
                        InitList(&(p->L));
                        LinkList temp = L->next;
                        int j = 1;
                        while (temp != NULL) {
                            ListInsert(&(p->L), j++, temp->Name, temp->data);
                            temp = temp->next;
                        }
                    }
                }
                // 重置 L
                if (L != NULL) {
                    DestroyList(&L);
                }
                InitList(&L);
                op0 = 4;
                goto op0;
                break;
        }
        system("pause");
    }
    return 0;
}

status InitList(LinkList *L) {
    if (*L != NULL) {
        return INFEASIBLE;
    }
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return OK;
}

status DestroyList(LinkList *L) {
    if (*L == NULL) {
        return INFEASIBLE;
    }
    LinkList p = *L;
    LinkList temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    *L = NULL;
    return OK;
}

status ClearList(LinkList *L) {
    if (*L == NULL) {
        return INFEASIBLE;
    }
    LinkList p = (*L)->next;
    LinkList temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    (*L)->next = NULL;
    return OK;
}

status ListEmpty(LinkList L) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    return (L->next == NULL) ? TRUE : FALSE;
}

int ListLength(LinkList L) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    int len = 0;
    LinkList p = L->next;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

status GetElem(LinkList L, int i, ElemType *e) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    if (i <= 0) {
        return ERROR;
    }
    LinkList p = L;
    for (int j = 0; j < i; j++) {
        if (p->next == NULL) {
            return ERROR;
        }
        p = p->next;
    }
    *e = p->data;
    return OK;
}

status LocateElem(LinkList L, ElemType e) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    LinkList p = L->next;
    int i = 1;
    while (p != NULL) {
        if (p->data == e) {
            return i;
        }
        p = p->next;
        i++;
    }
    return ERROR;
}

status PriorElem(LinkList L, ElemType cur, ElemType *pre_e) {
    if (L == NULL || L->next == NULL || L->next->data == cur) {
        return ERROR;
    }
    LinkList p = L->next;
    LinkList prev = L;
    while (p != NULL) {
        if (p->data == cur) {
            *pre_e = prev->data;
            return OK;
        }
        prev = p;
        p = p->next;
    }
    return ERROR;
}

status NextElem(LinkList L, ElemType cur, ElemType *next_e) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    LinkList p = L->next;
    while (p != NULL) {
        if (p->data == cur) {
            if (p->next == NULL) {
                return ERROR;
            }
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

status ListInsert(LinkList *L, int i, const char *name, ElemType e) {
    if (*L == NULL) return INFEASIBLE;
    if (i < 1) return ERROR;
    LinkList p = *L;
    for (int j = 1; j < i; j++) {
        if (p->next == NULL) {
            return ERROR;
        }
        p = p->next;
    }
    LinkList newNode = (LinkList)malloc(sizeof(LNode));
    strcpy(newNode->Name, name);
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

status ListDelete(LinkList *L, int i, ElemType *e) {
    if (*L == NULL) return INFEASIBLE;
    if (i < 1) return ERROR;
    LinkList p = *L;
    LinkList prev = NULL;
    for (int j = 0; j < i; j++) {
        if (p->next == NULL) {
            return ERROR;
        }
        prev = p;
        p = p->next;
    }
    *e = p->data;
    prev->next = p->next;
    free(p);
    return OK;
}

status ListTraverse(LinkList L) {
    if (L == NULL) return INFEASIBLE;
    LinkList p = L->next;
    while (p != NULL) {
        printf("%s: %d ", p->Name, p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
    
