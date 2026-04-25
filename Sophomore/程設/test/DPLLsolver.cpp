#include "definition.hpp"

//單子句判斷
int is_single_word(literalList L){
    if(L!=NULL and L->next == NULL) return TRUE;
    return FALSE;
}

//單子句查找
int find_single(clauseList L){
    clauseList p=L;
    while(p){
        if(is_single_word(p->head)){
            return p->head->literal;
        }
        p = p->next;
    }
    return ERROR;
}

//刪除子句
status DestroyClause(clauseList &cL)
{
    literalList p = cL->head;
    while (p)
    {
        literalList temp = p;
        p = p->next; 
        free(temp);  
    }
    free(cL);  
    cL = NULL; 
    return OK;
}

//化簡公式
void Simplify(clauseList &cL, int literal)
{
    clauseList pre = NULL, p = cL; // pre指向前一個子句
    while (p != NULL)
    {
        bool clauseDeleted = false;           // 是否刪除子句
        literalList lpre = NULL, q = p->head; // lpre指向前一個文字
        while (q != NULL)
        {
            if (q->literal == literal) // 刪除該子句
            {
                if (pre == NULL) // 刪除的是第一個子句
                    cL = p->next;
                else // 刪除的不是第一個子句
                    pre->next = p->next;
                DestroyClause(p);                   // 銷毀該子句
                p = (pre == NULL) ? cL : pre->next; // 指向下一個子句
                clauseDeleted = true;               // 子句已刪除
                break;
            }
            else if (q->literal == -literal) // 刪除該文字
            {
                if (lpre == NULL) // 刪除的是第一個文字
                    p->head = q->next;
                else // 刪除的不是第一個文字
                    lpre->next = q->next;
                free(q);                                   // 釋放該文字
                q = (lpre == NULL) ? p->head : lpre->next; // 指向下一個文字
            }
            else // 未刪除
            {
                lpre = q;
                q = q->next;
            }
        }
        if (!clauseDeleted) // 子句未刪除
        {
            pre = p;
            p = p->next;
        }
    }
}

/*
 @ 函數名稱: CopyCnf
 @ 接受參數: clauseList
 @ 函數功能: 複製cnf
 @ 返回值: clauseList
 */
clauseList CopyCnf(clauseList cL)
{
    // 初始化新的CNF
    clauseList newCnf = (clauseList)malloc(sizeof(clauseNode));
    clauseList lpa, lpb;  // lpa指向新的子句,lpb指向舊的子句
    literalList tpa, tpb; // tpa指向新的文字,tpb指向舊的文字
    newCnf->head = (literalList)malloc(sizeof(literalNode));
    newCnf->next = NULL;
    newCnf->head->next = NULL;
    for (lpb = cL, lpa = newCnf; lpb != NULL; lpb = lpb->next, lpa = lpa->next)
    {
        for (tpb = lpb->head, tpa = lpa->head; tpb != NULL; tpb = tpb->next, tpa = tpa->next)
        {
            tpa->literal = tpb->literal;
            tpa->next = (literalList)malloc(sizeof(literalNode));
            tpa->next->next = NULL;
            if (tpb->next == NULL) // 舊的子句中的文字已經複製完
            {
                free(tpa->next);
                tpa->next = NULL;
            }
        }
        lpa->next = (clauseList)malloc(sizeof(clauseNode));
        lpa->next->head = (literalList)malloc(sizeof(literalNode));
        lpa->next->next = NULL;
        lpa->next->head->next = NULL;
        if (lpb->next == NULL) // 舊的CNF中的子句已經複製完
        {
            free(lpa->next->head);
            free(lpa->next);
            lpa->next = NULL;
        }
    }
    return newCnf;
}

//未優化：直接選擇
int ChooseLiteral_1(CNF cnf)
{
    return cnf->root->head->literal;
}

//優化2：選擇出現次數最多的文字
int ChooseLiteral_2(CNF cnf)
{
    clauseList lp = cnf->root;
    literalList dp;
    int *count, MaxWord, max; // count記錄每個文字出現次數,MaxWord記錄出現最多次數的文字
    count = (int *)malloc(sizeof(int) * (cnf->boolCount * 2 + 1));
    for (int i = 0; i <= cnf->boolCount * 2; i++)
        count[i] = 0; // 初始化
    // 計算子句中各文字出現次數
    for (lp = cnf->root; lp != NULL; lp = lp->next)
    {
        for (dp = lp->head; dp != NULL; dp = dp->next)
        {
            if (dp->literal > 0) // 正文字
                count[dp->literal]++;
            else
                count[cnf->boolCount - dp->literal]++; // 負文字
        }
    }
    max = 0;
    // 找到出現次數最多的正文字
    for (int i = 1; i <= cnf->boolCount; i++)
    {
        if (max < count[i])
        {
            max = count[i];
            MaxWord = i;
        }
    }
    if (max == 0)
    {
        // 若沒有出現正文字,找到出現次數最多的負文字
        for (int i = cnf->boolCount + 1; i <= cnf->boolCount * 2; i++)
        {
            if (max < count[i])
            {
                max = count[i];
                MaxWord = cnf->boolCount - i;
            }
        }
    }
    free(count);
    return MaxWord;
}

//優化3：選擇最短子句中出現次數最多的文字
int ChooseLiteral_3(CNF cnf)
{
    clauseList p = cnf->root;
    int *count = (int *)calloc(cnf->boolCount * 2 + 1, sizeof(int));
    int minSize = INT_MAX; // 初始化為大於可能的最大子句長度
    int literal = 0;
    clauseList temp = NULL;
    // 遍歷子句，找到最小子句並統計其文字
    while (p != NULL)
    {
        literalList q = p->head;
        int clauseSize = 0;
        while (q != NULL)
        {
            clauseSize++;
            q = q->next;
        }
        if (clauseSize < minSize)
        {
            minSize = clauseSize; // 更新最小子句大小
            temp = p;
        }
        p = p->next;
    }
    // 遍歷子句，統計最小子句中各文字出現次數
    literalList q = temp->head;
    while (q != NULL)
    {
        count[q->literal + cnf->boolCount]++;
        q = q->next;
    }
    // 找到最頻繁的文字
    int maxCount = 0;
    for (int i = 0; i < cnf->boolCount * 2 + 1; i++)
    {
        if (count[i] > maxCount)
        {
            maxCount = count[i];
            literal = i - cnf->boolCount;
        }
    }
    free(count);
    return literal;
}

//滿足條件判斷
status Satisfy(clauseList cL)
{
    if (cL == NULL)
        return OK;
    else
        return ERROR;
}

//查找空子句
status EmptyClause(clauseList cL)
{
    clauseList p = cL;
    while (p)
    {
        if (p->head == NULL) // 空子句，返回UNSAT
            return TRUE;
        p = p->next;
    }
    return FALSE;
}

//求解主程序
status DPLL(CNF cnf, bool value[], int flag)
{
    /*1.單子句規則*/
    int unitLiteral = find_single(cnf->root);
    while (unitLiteral != 0)
    {
        value[abs(unitLiteral)] = (unitLiteral > 0) ? TRUE : FALSE;
        Simplify(cnf->root, unitLiteral);
        // 終止條件
        if (Satisfy(cnf->root) == OK)
            return OK;
        if (EmptyClause(cnf->root) == TRUE)
            return ERROR;
        unitLiteral = find_single(cnf->root);
    }
    /*2.選擇一個未賦值的文字*/
    int literal;
    if (flag == 1)
        literal = ChooseLiteral_1(cnf); // 優化
    else if (flag == 2)
        literal = ChooseLiteral_2(cnf); 
    else
        literal = ChooseLiteral_3(cnf);
    /*3.將該文字賦值為真，遞迴求解*/
    
    CNF newCnf = (CNF)malloc(sizeof(cnfNode));
    newCnf->root = CopyCnf(cnf->root); // 複製CNF
    newCnf->boolCount = cnf->boolCount;
    newCnf->clauseCount = cnf->clauseCount;
    clauseList p = (clauseList)malloc(sizeof(clauseNode));
    p->head = (literalList)malloc(sizeof(literalNode));
    p->head->literal = literal;
    p->head->next = NULL;
    p->next = newCnf->root;
    newCnf->root = p; // 插入到表頭
    if (DPLL(newCnf, value, flag) == 1)
        return 1; // 在第一分支中搜索
    destroyCNF(newCnf);
    /*4.將該文字賦值為假，遞迴求解*/
    // newCnf = CopyCnf(cL);
    // newCnf=cL;
    clauseList q = (clauseList)malloc(sizeof(clauseNode));
    q->head = (literalList)malloc(sizeof(literalNode));
    q->head->literal = -literal;
    q->head->next = NULL;
    q->next = cnf->root;
    cnf->root = q; // 插入到表頭
    status re = DPLL(cnf, value, flag); // 回溯到執行分支策略的初態進入另一分支
    // DestroyCnf(cL);
    return re;
}

//保存求解結果

status SaveResult(int result, double time, double time_, bool value[], char fileName[], int boolCount)
{
    FILE *fp;
    char name[100];
    for (int i = 0; fileName[i] != '\0'; i++)
    {
        // 修改拓展名.res
        if (fileName[i] == '.' && fileName[i + 4] == '\0')
        {
            name[i] = '.';
            name[i + 1] = 'r';
            name[i + 2] = 'e';
            name[i + 3] = 's';
            name[i + 4] = '\0';
            break;
        }
        name[i] = fileName[i];
    }
    fp=fopen(name, "w");
    fprintf(fp, "s %d", result); // 求解結果
    if (result == 1)
    {
        fprintf(fp, "\nv");
        // 保存解值
        for (int i = 1, cnt = 1; i <= boolCount; i++, cnt++)
        {
            if (value[i] == true)
                fprintf(fp, " %d", i);
            else
                fprintf(fp, " %d", -i);
        }
    }
    fprintf(fp, "\nt %lfms", time * 1000); // 執行時間/毫秒
    if (time_ != 0)
    {
        fprintf(fp, "\nt %lfms(optimized)", time_ * 1000);        // 執行時間/毫秒
        double optimization_rate = ((time - time_) / time) * 100; // 優化率
        fprintf(fp, "\n時間優化率: %.2lf%%", optimization_rate);
    }
    fclose(fp);
    return OK;
}


