/*---------------------------------------------
|  Binary Tree On Binary Linked List          |
|  Author:qrq 2402                            |
|  Date:2025.4.27                             |
---------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

typedef int status;
typedef int KeyType;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;
#define MAXSIZE 10 // Maximum number of nodes in the tree

typedef struct
{
    KeyType key;
    char others[30]; // Other information
} TElemType;         // data type of the element

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild; // Left and right children
} BiTNode, *BiTree;                  // Binary tree node type

typedef struct
{
    BiTree root;   // Root node of the tree
    char name[30]; // Name of the tree
} Tree;            // Tree type

typedef struct Trees
{
    Tree elem[MAXSIZE]; // Array of trees
    int length;
    int cur_index; // Current index of the tree
} TREES;           // Tree array type

/*--------------------------------------------------*/

// basic operations
status ConstructSubTree(BiTree &T, TElemType definition[], int &index, set<KeyType> &keys);
status KeyExistInTree(BiTree T, KeyType key);
BiTNode *GetParent(BiTree T, KeyType key);
status preorderSave(BiTree T, FILE *fp);
status visit(BiTree T);

// BiTree system operations
status CreateBiTree(BiTree &T, TElemType definition[]);
status DestroyBiTree(BiTree &T);
status ClearBiTree(BiTree &T);
status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
BiTNode *LocateNode(BiTree T, KeyType e);
status Assign(BiTree &T, KeyType e, TElemType value);
BiTNode *GetSibling(BiTree T, KeyType e);
status InsertNode(BiTree &T, KeyType e, int LR, TElemType c);
status DeleteNode(BiTree &T, KeyType e);
status PreOrderTraverse(BiTree T);
status InOrderTraverse(BiTree T);
status PostOrderTraverse(BiTree T);
status LevelOrderTraverse(BiTree T);

// Additional operations
status SaveBiTree(BiTree T, char FileName[]);
status LoadBiTree(BiTree &T, char FileName[]);
status MaxPathSum(BiTree T);
BiTNode *LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2);
status InvertTree(BiTree &T);

// multiple trees operations
int LocateTree(TREES Trees, char FileName[]);
status AddTree(TREES &Trees, char FileName[]);
status RemoveTree(TREES &T, char ListName[]);
status SwitchTree(TREES &Trees, char ListName[]);
void PrintTrees(TREES Trees);
void PrintMenu(TREES &Trees);

/*--------------------------------------------------*/

status CreateBiTree(BiTree &T, TElemType definition[])
{
    int index = 0;
    set<KeyType> keys;

    return ConstructSubTree(T, definition, index, keys);
}

status ConstructSubTree(BiTree &T, TElemType definition[], int &index, set<KeyType> &keys)
{
    // 空節點
    if (definition[index].key == 0)
    {
        T = NULL;
        index++;
        return OK;
    }
    if (definition[index].key == -1)
    {
        T = NULL;
        return OK;
    }
    // 檢查 key 是否重複
    KeyType currentKey = definition[index].key;
    if (keys.find(currentKey) != keys.end())
    {
        return ERROR;
    }
    keys.insert(currentKey);

    // 創建新節點
    BiTNode *newNode = (BiTNode *)malloc(sizeof(BiTNode));
    if (!newNode)
        return OVERFLOW;

    newNode->data = definition[index];
    newNode->lchild = newNode->rchild = NULL;
    T = newNode;
    index++;

    // 遞迴構造左右子樹
    status leftStatus = ConstructSubTree(T->lchild, definition, index, keys);
    if (leftStatus != OK)
        return leftStatus;
    return ConstructSubTree(T->rchild, definition, index, keys);
}

status DestroyBiTree(BiTree &T)
// 初始條件是二叉樹T已存在；操作結果是銷毀二叉樹T；銷毀了則原先所有分配的空間都銷毀。
{
    if (T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
        T = NULL;
    }
    return OK;
}

status ClearBiTree(BiTree &T)
// 將二叉樹設置成空，但保留結點空間
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE;

    ClearBiTree(T->lchild);
    ClearBiTree(T->rchild);

    T->lchild = NULL;
    T->rchild = NULL;

    return OK;
    /********** End **********/
}

status BiTreeEmpty(BiTree T)
// 判斷二叉樹是否為空
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL)
        return TRUE;
    else
        return FALSE;
    /********** End **********/
}

int BiTreeDepth(BiTree T)
// 求二叉樹T的深度
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL)
        return 0;

    int Ldepth = BiTreeDepth(T->lchild);
    int Rdepth = BiTreeDepth(T->rchild);

    return 1 + (Ldepth > Rdepth ? Ldepth : Rdepth);

    /********** End **********/
}

BiTNode *LocateNode(BiTree T, KeyType e)
// 查找結點
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL || T->data.key == e)
        return T;

    BiTNode *left = LocateNode(T->lchild, e);
    return left ? left : LocateNode(T->rchild, e);
    /********** End **********/
}

status Assign(BiTree &T, KeyType e, TElemType value)
// 實現結點賦值。此題允許通過增加其它函數輔助實現本關任務
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE;

    BiTree p = LocateNode(T, e);

    if (p != NULL)
    {
        // 暫存原始關鍵字
        KeyType originalKey = p->data.key;

        // 賦值新值
        p->data = value;

        // 檢查賦值後是否存在重複關鍵字
        if (KeyExistInTree(T, value.key) > 1)
        {
            // 如果發現重複關鍵字，恢復原始關鍵字
            p->data.key = originalKey;
            return ERROR;
        }
        return OK;
    }

    return ERROR;
    /********** End **********/
}

BiTNode *GetSibling(BiTree T, KeyType e)
// 獲取兄弟結點
{
    // 如果樹為空或者沒有兄弟結點，返回NULL
    if (T == NULL || T->lchild == NULL || T->rchild == NULL)
        return NULL;

    // 檢查左孩子是否是給定關鍵字的兄弟
    if (T->lchild->data.key == e)
        return T->rchild;

    // 檢查右孩子是否是給定關鍵字的兄弟
    if (T->rchild->data.key == e)
        return T->lchild;

    // 遞迴在左子樹和右子樹中查找兄弟結點
    BiTNode *sibling = GetSibling(T->lchild, e);
    return sibling ? sibling : GetSibling(T->rchild, e);
}

int KeyExistInTree(BiTree T, KeyType key)
{
    if (!T)
    {
        return 0;
    }
    if (T->data.key == key)
    {
        return 1;
    }
    int leftResult = KeyExistInTree(T->lchild, key);
    int rightResult = KeyExistInTree(T->rchild, key);

    return leftResult + rightResult;
}

status InsertNode(BiTree &T, KeyType e, int LR, TElemType c)
/*插入結點。此題允許通過增加其它函數輔助實現本關任務初始條件是二叉樹T存在，e是和T中結點關鍵字類型相同的給定值，LR為0或1，c是待插入結點；操作結果是根據LR為0或者1，插入結點c到T中，作為關鍵字為e的結點的左或右孩子結點，結點e的原有左子樹或右子樹則為結點c的右子樹；
特殊情況，LR-1時，作為根結點插入，原根結點作為c的右子樹。*/
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (KeyExistInTree(T, c.key))
        return INFEASIBLE;

    if (LR == -1)
    {
        BiTree NewNode = (BiTree)malloc(sizeof(BiTNode));
        NewNode->data = c;
        NewNode->rchild = T;
        T = NewNode;
        return OK;
    }
    else
    {
        BiTree t = LocateNode(T, e); // 未找到關鍵字為e的結點
        if (!t)
            return ERROR;
        else
        {
            if (LR == 1)
            {
                BiTree tr = t->rchild;
                BiTree NewNode = (BiTree)malloc(sizeof(BiTNode));
                NewNode->data = c;
                t->rchild = NewNode;
                NewNode->rchild = tr;
                NewNode->lchild = NULL;
            }
            else if (LR == 0)
            {
                BiTree tl = t->lchild;
                BiTree NewNode = (BiTree)malloc(sizeof(BiTNode));
                NewNode->data = c;
                t->lchild = NewNode;
                NewNode->rchild = tl;
                NewNode->lchild = NULL;
            }
            return OK;
        }
    }
    /********** End **********/
}

BiTNode *GetParent(BiTree T, KeyType key)
{
    if (T == NULL || T->data.key == key)
        return NULL;

    if ((T->lchild != NULL && T->lchild->data.key == key) ||
        (T->rchild != NULL && T->rchild->data.key == key))
    {
        return T;
    }

    BiTNode *parent = GetParent(T->lchild, key);
    return parent ? parent : GetParent(T->rchild, key);
}

status DeleteNode(BiTree &T, KeyType e)
// 刪除結點。此題允許通過增加其它函數輔助實現本關任務
/*初始條件是二叉樹T存在，e是和T中結點關鍵字類型相同的給定值。操作結果是刪除T中關鍵字為e的結點；同時，如果關鍵字為e的結點度為0，刪除即可；如關鍵字為e的結點度為1，用關鍵字為e的結點孩子代替被刪除的e位置；如關鍵字為e的結點度為2，用e的左孩子代替被刪除的e位置，e的右子樹作為e的左子樹中最右結點的右子樹；
 */
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE;

    BiTree current = LocateNode(T, e);
    if (current == NULL)
    {
        printf("結點 %d 不存在！\n", e);
        return ERROR;
    }

    int degree = (current->lchild != NULL) + (current->rchild != NULL);

    BiTNode *parent = GetParent(T, e);

    if (degree == 0)
    {
        printf("結點 %d 的度為0\n", e);
        if (current == NULL)
        {
            T = NULL;
        }
        else
        {
            if (parent->lchild == current)
            {
                parent->lchild = NULL;
            }
            else
            {
                parent->rchild = NULL;
            }
        }
        free(current);

        return OK;
    }
    else if (degree == 1)
    {
        printf("結點 %d 的度為1\n", e);
        BiTNode *child = (current->lchild != NULL) ? current->lchild : current->rchild;

        if (parent == NULL)
        {
            T = child;
        }
        else
        {
            if (parent->lchild == current)
            {
                parent->lchild = child;
            }
            else
            {
                parent->rchild = child;
            }
        }
        free(current);

        return OK;
    }
    else
    {
        printf("結點 %d 的度為2\n", e);
        BiTNode *LC = current->lchild;
        BiTNode *RC = current->rchild;

        BiTNode *rightMostInLeft = LC;
        while (rightMostInLeft != NULL && rightMostInLeft->rchild != NULL)
        {
            rightMostInLeft = rightMostInLeft->rchild;
        }

        rightMostInLeft->rchild = RC;

        if (parent == NULL)
        {
            T = LC;
        }
        else
        {
            if (parent->lchild == current)
            {
                parent->lchild = LC;
            }
            else
            {
                parent->rchild = LC;
            }
        }
        free(current);
        return OK;
    }

    /********** End **********/
}

status visit(BiTree T)
{
    // 訪問結點的操作
    if (T != NULL)
    {
        printf("%d %s\n", T->data.key, T->data.others);
    }
    return OK;
}

status PreOrderTraverse(BiTree T)
// 先序遍歷二叉樹T，非遞迴實現
// 先序遍歷的順序是：根結點->左子樹->右子樹
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE;
    BiTree stack[1000];
    int top = -1;
    stack[++top] = T;

    while (top != -1)
    {
        BiTree cur = stack[top--];
        visit(cur);

        if (cur->rchild)
            stack[++top] = cur->rchild;
        if (cur->lchild)
            stack[++top] = cur->lchild;
    }

    return OK;

    /********** End **********/
}

status InOrderTraverse(BiTree T)
// 中序遍歷二叉樹T，非遞迴實現
// 中序遍歷的順序是：左子樹->根結點->右子樹
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    BiTree stack[1000];
    int top = -1;
    BiTree cur = T;

    while (cur != NULL || top != -1)
    {
        while (cur != NULL)
        {
            stack[++top] = cur;
            cur = cur->lchild;
        }

        cur = stack[top--];
        visit(cur);

        cur = cur->rchild;
    }

    return OK;
    /********** End **********/
}

status PostOrderTraverse(BiTree T)
// 後序遍歷二叉樹T
{
    /********** Begin *********/
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T);

        return OK;
    }
    else
        return INFEASIBLE;
    /********** End **********/
}

status LevelOrderTraverse(BiTree T)
// 按層遍歷二叉樹T
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL)
        return INFEASIBLE;
    BiTree queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = T;

    while (front < rear)
    {
        T = queue[front++];
        visit(T);

        if (T->lchild != NULL)
            queue[rear++] = T->lchild;
        if (T->rchild != NULL)
            queue[rear++] = T->rchild;
    }

    return OK;

    /********** End **********/
}

status preorderSave(BiTree T, FILE *fp)
{
    // 先序遍歷保存二叉樹到檔
    if (T)
    {
        fprintf(fp, "%d %s ", T->data.key, T->data.others);
        preorderSave(T->lchild, fp);
        preorderSave(T->rchild, fp);
        return OK;
    }
    else
    {
        // 如果結點為空，輸出0和null
        fprintf(fp, "0 null ");
        return OK;
    }

    return ERROR;
}

status SaveBiTree(BiTree T, char FileName[])
// 將二叉樹的結點數據寫入到文件FileName中
{
    FILE *fp = fopen(FileName, "w");
    if (!fp)
        return ERROR;

    preorderSave(T, fp);

    fprintf(fp, "-1 null");
    fclose(fp);

    return OK;
}

status LoadBiTree(BiTree &T, char FileName[])
{
    FILE *fp = fopen(FileName, "r");
    if (!fp)
    {
        printf("無法打開文件：%s\n", FileName);
        return ERROR;
    }

    // 讀取檔內容
    TElemType definition[100];
    memset(definition, 0, sizeof(definition));
    int defIndex = 0;
    while (fscanf(fp, "%d %s", &definition[defIndex].key, definition[defIndex].others) == 2)
    {
        if (definition[defIndex].key == -1)
            break;
        defIndex++;
    }

    // 檢查是否讀取到有效資料
    if (defIndex == 0)
    {
        fclose(fp);
        return ERROR;
    }

    // 構造新樹
    status res = CreateBiTree(T, definition);

    fclose(fp);
    return res == OK ? OK : ERROR;
}

status MaxPathSum(BiTree T)
{
    if (T == NULL)
        return 0;

    if (!T->lchild && !T->rchild)
    {
        return T->data.key;
    }

    int lsum = MaxPathSum(T->lchild);
    int rsum = MaxPathSum(T->rchild);

    return T->data.key + max(lsum, rsum);
}

BiTNode *LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2)
{
    if (T == NULL || T->data.key == e1 || T->data.key == e2)
        return T;

    BiTNode *left = LowestCommonAncestor(T->lchild, e1, e2);
    BiTNode *right = LowestCommonAncestor(T->rchild, e1, e2);

    if (left && right)
        return T;
    else
        return left ? left : right;
}

status InvertTree(BiTree &T)
{
    if (T == NULL)
        return INFEASIBLE;

    // 遞迴反轉左右子樹
    InvertTree(T->lchild);
    InvertTree(T->rchild);

    // 交換左右孩子指針
    BiTNode *temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;

    return OK;
}

status AddTree(TREES &Trees, char FileName[])
{
    if (Trees.length >= MAXSIZE)
        return ERROR;

    for (int i = 0; i < Trees.length; i++)
    {
        if (strcmp(Trees.elem[i].name, FileName) == 0)
            return ERROR;
    }

    Trees.elem[Trees.length].root = NULL;
    strcpy(Trees.elem[Trees.length].name, FileName);
    Trees.length++;
    Trees.cur_index = Trees.length - 1;

    printf("當前二叉樹：%s\n\n", Trees.elem[Trees.cur_index].name);
    return OK;
}

status RemoveTree(TREES &T, char ListName[])
{
    for (int i = 0; i < T.length; i++)
    {
        if (strcmp(T.elem[i].name, ListName) == 0)
        {
            DestroyBiTree(T.elem[i].root);
            for (int j = i; j < T.length - 1; j++)
            {
                T.elem[j] = T.elem[j + 1];
            }
            T.elem[T.length - 1].root = NULL;
            memset(T.elem[T.length - 1].name, 0, 30);

            T.length--;
            T.cur_index = 0;
            return OK;
        }
    }
    return ERROR;
}

status SwitchTree(TREES &Trees, char ListName[])
{
    for (int i = 0; i < Trees.length; i++)
    {
        if (strcmp(Trees.elem[i].name, ListName) == 0)
        {
            Trees.cur_index = i;
            return OK;
        }
    }
    return ERROR;
}

status LocateTree(TREES Trees, char ListName[])
{
    for (int i = 0; i < Trees.length; i++)
    {
        if (strcmp(Trees.elem[i].name, ListName) == 0)
            return i + 1;
    }
    return ERROR;
}

void PrintTrees(TREES Trees)
{
    printf("--------------------------------------------------\n");
    printf("當前二叉樹列表：\n");
    for (int i = 0; i < Trees.length; i++)
    {
        printf("%d. %s\n", i + 1, Trees.elem[i].name);
    }
    printf("--------------------------------------------------\n");
}

void PrintMenu(TREES &Trees)
{
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf(" Menu for Binary Tree System On Binary Linked List \n");
    printf("---------------------------------------------------------\n\n");
    printf("當前二叉樹：%s\n", Trees.elem[Trees.cur_index].name);
    printf("Basic Operations:\n");
    printf("      1. CreateTree               2. DestoryTree         \n");
    printf("      3. ClearTree                4. BiTreeEmpty         \n");
    printf("      5. BiTreeDepth              6. LocateNode          \n");
    printf("      7. Assign                   8. GetSibling          \n");
    printf("      9. InsertNode               10. DeleteNode         \n");
    printf("     11. PreOrderTraverse         12. InOrderTraverse    \n");
    printf("     13. PostOrderTraverse        14. LevelOrderTraverse \n");
    printf("Additional Operations:\n");
    printf("     15. MaxPathSum               16. InvertTree         \n");
    printf("     17. LoadTree                 18. SaveTree           \n");
    printf("     19. LowestCommonAncestor                            \n");
    printf("Multiple Trees Operations:\n");
    printf("     20. AddTree                  21. RemoveTree         \n");
    printf("     22. SwitchTree               23. PrintTrees         \n");
    printf("     0. Exit\n");
    printf("---------------------------------------------------------\n");
    printf("請輸入操作選項：\n");
}

int main()
{
    TREES Trees;
    Trees.length = 1;
    Trees.cur_index = 0;
    Trees.elem[0].root = NULL;
    char firstname[30];
    system("cls");
    printf("--------------------------------------------------\n");
    printf("這是一個多二叉樹系統，可以對單個或多個二叉樹進行操作\n");
    printf("Author：HUST Cupid-qrq\n");
    printf("--------------------------------------------------\n");
    printf("在開始之前，請先輸入第一個二叉樹的名稱：\n");
    if (scanf("%s", firstname) != 1)
    {
        printf("輸入錯誤，請重新輸入：\n");
        scanf("%s", firstname);
    }
    printf("輸入成功，第一個二叉樹的名稱是：%s\n", firstname);
    strcpy(Trees.elem[0].name, firstname);
    printf("接下來，進入功能表介面，按任意鍵繼續：\n");
    getchar();
    getchar();

    int op = 1;                // 功能表選項
    int depth;                 // 二叉樹深度
    TElemType definition[100]; // 創建二叉樹的定義陣列
    int defIndex;              // 定義陣列索引
    int exist;                 // 查找結點的關鍵字
    int exist2;                // 賦值結點的關鍵字
    TElemType value;           // 賦值結點的值
    int e1, e2;                // 查找最近公共祖先的兩個結點的關鍵字
    int LR;                    // 插入函數的參數，0表示左子樹，1表示右子樹，-1表示根結點
    TElemType c;               // 待插入結點
    BiTNode *node;             // 查找結點的指針
    BiTNode *sibling;          // 兄弟結點的指針
    BiTNode *lca;              // 最近公共祖先的指針
    int res;                   // 函數的返回值
    int index;                 // 二叉樹的索引
    int maxPathSum;            // 最大路徑和

    char filename[100], treename[100];

    while (op)
    {
        PrintMenu(Trees);

        if (scanf("%d", &op) != 1)
        {
            op = -1;
        }

        switch (op)

        {
        case 1:
        {
            // 如果當前樹存在，創建失敗
            if (Trees.elem[Trees.cur_index].root != NULL)
            {
                printf("當前二叉樹已存在，創建失敗！\n");
                break;
            }

            // 初始化 definition 陣列
            defIndex = 0;
            memset(definition, 0, sizeof(definition));

            int key;
            char others[30];

            printf("請輸入二叉樹的先序遍歷序列，格式為：key others，空節點用 0 null 表示，以 -1 null 結束。\n");

            while (1)
            {
                if (scanf("%d", &key) != 1)
                {
                    printf("輸入錯誤，請重新輸入。\n");
                    continue;
                }

                if (key == -1)
                {
                    // 讀取最後一個 "null"，結束輸入
                    scanf("%s", others);
                    break;
                }

                definition[defIndex].key = key;

                // 讀取 others
                if (scanf("%s", others) != 1)
                {
                    printf("輸入錯誤，請重新輸入。\n");
                    continue;
                }

                strncpy(definition[defIndex].others, others, 29);
                definition[defIndex].others[29] = '\0';
                defIndex++;
            }

            // 構造新樹
            status res = CreateBiTree(Trees.elem[Trees.cur_index].root, definition);

            if (res == OK)
            {
                printf("樹創建成功。\n");
            }
            else
            {
                printf("樹創建失敗，可能原因：重複 key 或記憶體不足。\n");
            }

            break;
        }

        case 2:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，銷毀失敗！\n");
                break;
            }

            if (DestroyBiTree(Trees.elem[Trees.cur_index].root) == OK)
                printf("二叉樹銷毀成功！\n");
            else
                printf("二叉樹不存在，銷毀失敗！\n");
            break;

        case 3:
            if (ClearBiTree(Trees.elem[Trees.cur_index].root) == OK)
                printf("二叉樹清空成功！\n");
            else
                printf("二叉樹不存在，清空失敗！\n");
            break;

        case 4:
            if (BiTreeEmpty(Trees.elem[Trees.cur_index].root) == TRUE)
                printf("二叉樹為空！\n");
            else if (BiTreeEmpty(Trees.elem[Trees.cur_index].root) == FALSE)
                printf("二叉樹非空！\n");
            else
                printf("二叉樹不存在！\n");
            break;

        case 5:
            depth = BiTreeDepth(Trees.elem[Trees.cur_index].root);
            if (depth != 0)
                printf("二叉樹的深度為：%d\n", depth);
            else
                printf("二叉樹不存在！\n");
            break;

        case 6:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法查找結點！\n");
                break;
            }

            printf("請輸入要查找的結點的關鍵字：\n");
            scanf("%d", &exist);
            node = LocateNode(Trees.elem[Trees.cur_index].root, exist);
            if (node != NULL)
                printf("結點 %d 的信息為：%d %s\n", exist, node->data.key, node->data.others);
            else
                printf("結點 %d 不存在！\n", exist);
            break;

        case 7:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法賦值！\n");
                break;
            }

            printf("請輸入要賦值的結點的關鍵字：\n");
            scanf("%d", &exist2);
            printf("請輸入新的結點資訊（格式：\"key others\"）：\n");
            scanf("%d %s", &value.key, value.others);
            if (Assign(Trees.elem[Trees.cur_index].root, exist2, value) == OK)
            {
                printf("賦值成功！\n");
            }
            else
                printf("賦值失敗，結點不存在或關鍵字重複！\n");
            break;

        case 8:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法查找兄弟結點！\n");
                break;
            }

            printf("請輸入要查找兄弟的結點的關鍵字：\n");
            scanf("%d", &exist);
            sibling = GetSibling(Trees.elem[Trees.cur_index].root, exist);
            if (sibling != NULL)
                printf("結點 %d 的兄弟結點為：%d %s\n", exist, sibling->data.key, sibling->data.others);
            else
                printf("結點 %d 沒有兄弟結點或不存在！\n", exist);
            break;

        case 9:
            if (Trees.elem[Trees.cur_index].root == NULL && LR != -1)
            {
                printf("當前二叉樹不存在，無法插入結點！\n");
                break;
            }

            printf("請輸入要插入的位置的關鍵字：\n");
            scanf("%d", &exist);
            printf("請輸入插入的新結點的資訊（格式：\"key others\"）：\n");
            scanf("%d %s", &c.key, c.others);
            printf("請輸入插入的方式（0表示左子樹，1表示右子樹，-1表示根結點）：\n");
            scanf("%d", &LR);
            res = InsertNode(Trees.elem[Trees.cur_index].root, exist, LR, c);
            if (res == INFEASIBLE)
                printf("插入失敗，關鍵字重複！\n");
            else if (res == ERROR)
                printf("插入失敗，插入位置不存在！\n");
            else
                printf("插入成功！\n");
            break;

        case 10:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法刪除結點！\n");
                break;
            }
            printf("請輸入要刪除的結點的關鍵字：\n");
            scanf("%d", &exist);
            if (DeleteNode(Trees.elem[Trees.cur_index].root, exist) == OK)
                printf("刪除成功！\n");
            else
                printf("刪除失敗，結點不存在或樹為空！\n");
            break;

        case 11:
            printf("前序遍歷結果：\n");
            if (BiTreeEmpty(Trees.elem[Trees.cur_index].root) == TRUE)
                printf("二叉樹為空！\n");
            else
            {
                printf("--------------------------------------------------\n");
                PreOrderTraverse(Trees.elem[Trees.cur_index].root);
                printf("--------------------------------------------------\n");
            }
            break;

        case 12:
            printf("中序遍歷結果：\n");
            if (BiTreeEmpty(Trees.elem[Trees.cur_index].root) == TRUE)
                printf("二叉樹為空！\n");
            else
            {
                printf("--------------------------------------------------\n");
                InOrderTraverse(Trees.elem[Trees.cur_index].root);
                printf("--------------------------------------------------\n");
            }
            break;

        case 13:
            printf("後序遍歷結果：\n");
            if (BiTreeEmpty(Trees.elem[Trees.cur_index].root) == TRUE)
                printf("二叉樹為空！\n");
            else
            {
                printf("--------------------------------------------------\n");
                PostOrderTraverse(Trees.elem[Trees.cur_index].root);
                printf("--------------------------------------------------\n");
            }
            break;

        case 14:
            printf("層序遍歷結果：\n");
            if (BiTreeEmpty(Trees.elem[Trees.cur_index].root) == TRUE)
                printf("二叉樹為空！\n");
            else
            {
                printf("--------------------------------------------------\n");
                LevelOrderTraverse(Trees.elem[Trees.cur_index].root);
                printf("--------------------------------------------------\n");
            }
            break;

        case 15:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法計算最大路徑和！\n");
                break;
            }

            if (BiTreeEmpty(Trees.elem[Trees.cur_index].root) == TRUE)
                printf("二叉樹為空！\n");
            else
            {
                maxPathSum = MaxPathSum(Trees.elem[Trees.cur_index].root);
                printf("二叉樹的最大路徑和為：%d\n", maxPathSum);
            }
            break;

        case 16:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法反轉！\n");
                break;
            }

            if (InvertTree(Trees.elem[Trees.cur_index].root) == OK)
                printf("二叉樹反轉成功！\n");
            else
                printf("二叉樹不存在，反轉失敗！\n");

            break;

        case 17:
            printf("請輸入要載入的檔案名：\n");
            scanf("%s", filename);
            if (LoadBiTree(Trees.elem[Trees.cur_index].root, filename) == OK)
                printf("二叉樹載入成功！\n");
            else
                printf("二叉樹載入失敗！\n");
            break;

        case 18:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法保存！\n");
                break;
            }
            else
            {
                printf("請輸入要保存的檔案名：\n");
                scanf("%s", filename);
                if (SaveBiTree(Trees.elem[Trees.cur_index].root, filename) == OK)
                    printf("二叉樹保存成功！\n");
                else
                    printf("二叉樹保存失敗！\n");
            }
            break;

        case 19:
            if (Trees.elem[Trees.cur_index].root == NULL)
            {
                printf("當前二叉樹不存在，無法查找最近公共祖先！\n");
                break;
            }

            printf("請輸入要查找的兩個結點的關鍵字：\n");
            scanf("%d %d", &e1, &e2);
            lca = LowestCommonAncestor(Trees.elem[Trees.cur_index].root, e1, e2);
            if (lca != NULL)
                printf("最近公共祖先結點為：%d %s\n", lca->data.key, lca->data.others);
            else
                printf("最近公共祖先結點不存在！\n");
            break;

        case 20:
            printf("請輸入要添加的樹的名稱：\n");
            scanf("%s", treename);
            if (AddTree(Trees, treename) == OK)
                printf("樹添加成功！\n");
            else
                printf("樹添加失敗！\n");
            break;

        case 21:
            printf("請輸入要刪除的樹的名稱：\n");
            scanf("%s", treename);
            if (RemoveTree(Trees, treename) == OK)
                printf("樹刪除成功！\n");
            else
                printf("樹刪除失敗！\n");
            break;

        case 22:
            printf("請輸入要切換的樹的名稱：\n");
            scanf("%s", treename);
            index = LocateTree(Trees, treename);
            if (index != ERROR)
            {
                Trees.cur_index = index - 1;
                printf("切換成功！當前樹為：%s\n", Trees.elem[Trees.cur_index].name);
            }
            else
                printf("樹不存在，切換失敗！\n");
            break;

        case 23:
            PrintTrees(Trees);
            break;

        case 0:
            printf("退出程式！\n");
            break;

        default:
            printf("無效操作，請重新輸入！\n");
            break;
        }

        if (op != 0)
        {
            printf("按回車鍵繼續...\n");
            getchar();
            getchar();
        }
    }

    return 0;
}

/*

         1(root)
       /        \
   2(a)        4(c)
      \           \
       3(b)       5(d)

*/


