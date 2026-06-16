/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <malloc.h>
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
typedef int ElemType; //資料元素類型定義

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct LNode{  //單鏈表（鏈式結構）結點的定義
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;
LinkList L,Ltemp;
typedef struct{  //線性表的集合類型定義
     struct { char name[30];
               LinkList L;    
     } elem[10];
     int length;
}LISTS;
LISTS Lists;      //線性表集合的定義Lists
/*-----page 19 on textbook ---------*/
status InitList(LinkList &L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L,int i,ElemType &e);
status LocateElem(LinkList L,ElemType e);
status PriorElem(LinkList L,ElemType e,ElemType &pre);
status NextElem(LinkList L,ElemType e,ElemType &next);
status ListInsert(LinkList &L,int i,ElemType e);
status ListDelete(LinkList &L,int i,ElemType &e);
status ListTraverse(LinkList L);
status SaveList(LinkList L,char FileName[]);
status LoadList(LinkList &L,char FileName[]);
status AddList(LISTS &Lists,char ListName[]);
status RemoveList(LISTS &Lists,char ListName[]);
int LocateList(LISTS Lists,char ListName[]);
status reverseList(LinkList L);
int RemoveNthFromEnd(LinkList L,int k);
int sortList(LinkList L);
//簡化過
/*--------------------------------------------*/
int main(){
int op=1,result,tp,e,k,op1=1,t;
char ch[1000];
char name[30];
while(op1){
    system("cls");  printf("\n\n");
    printf("-------------------------------------------------\n");
    printf("1.進入多線性表管理        2.進入單線性表管理\n");
    printf("0. Exit\n");
    printf("-------------------------------------------------\n");
    scanf("%d",&op1);   
    switch(op1){
        case 1:
            op=1;
            while(op!=0 and op!=4){
                t=0;
                system("cls");  printf("\n\n");
                printf("      多線性表管理！     \n");         
                printf("-------------------------------------------------\n");
                printf("          1. AddList       3. LocateList\n");
                printf("          2. DestroyList   4. 返回選擇頁面\n");       
                printf("          0.Exit\n");   
                printf("-------------------------------------------------\n");
                printf("    請選擇你的操作[0~4]:");        
                scanf("%d",&op);
                switch(op){
                    case 1:
                        printf("添加一個線性表，請輸入線性表名稱：");
                        
                        scanf("%s",name);
                        result=AddList(Lists,name);                 
                        if(result==OK) printf("OK!\n");
                        break;
                    case 2:
                        printf("刪除一個線性表，請輸入線性表名稱：");
                        scanf("%s",name);
                        result=RemoveList(Lists,name);                  
                        if(result==OK) printf("OK!\n");
                        else printf("線性表不存在！\n");               
                        break;
                    case 3:
                        printf("查找一個線性表，請輸入線性表名稱：");
                        scanf("%s",name);
                        result=LocateList(Lists,name);                  
                        if(result==ERROR) printf("線性表不存在！\n");
                        else{
                            int t;
                            printf("OK!  按1對其進行單線性表操作,按其他按鈕返回");
                            scanf("%d",&t);
                            if(t==1){
                                L=Lists.elem[result-1].L;
                                while(op!=0 and op!=18){
                                    int t=0;
                                    system("cls");  printf("\n\n");
                                    printf("      單線性表管理！     \n");
                                    printf("-------------------------------------------------\n");
                                    printf("          1. InitList       7. LocateElem\n");
                                    printf("          2. DestroyList   8. PriorElem\n");
                                    printf("          3. ClearList       9. NextElem \n");
                                    printf("          4. ListEmpty     10. ListInsert\n");
                                    printf("          5. ListLength     11. ListDelete\n");
                                    printf("          6. GetElem       12. ListTrabverse\n");
                                    printf("          13. reverseList     14. RemoveNthFromEnd\n");
                                    printf("          15. sortList       16. SaveList\n");
                                    printf("          17. LoadList      18.返回多線性表操作\n");    
                                    printf("          0. Exit\n");
                                    printf("-------------------------------------------------\n");
                                    printf("    請選擇你的操作[0~18]:");
                                    scanf("%d",&op);
                                    switch(op){
                                       case 1:
                                                result=InitList(L);
                                                if (result==OK) printf("OK\n");
                                                if (result==INFEASIBLE) printf("線性表已存在！\n");               
                                         break;
                                       case 2:
                                                result=DestroyList(L);
                                                if (result==OK) printf("OK\n");
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");
                                         break;
                                       case 3:
                                                result=ClearList(L);
                                                if (result==OK) printf("OK\n");
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");                
                                         break;
                                       case 4:
                                                result=ListEmpty(L);
                                                if (result==TRUE) printf("線性表為空！\n");
                                                if(result==FALSE) printf("線性表不為空！\n");
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");                    
                                         break;
                                       case 5:
                                                result= ListLength(L);
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");    
                                                else printf("線性表長度為%d\n",result);
                                         break;
                                       case 6:
                                                printf("獲取線性表的第i個元素：");
                                                scanf("%d",&tp);
                                                result=GetElem(L,tp,e);
                                                if (result==ERROR) printf("查找失敗！\n");
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                if(result==OK) printf("第%d個元素為%d\n",tp,e);  
                                         break;
                                       case 7:
                                                printf("輸入你要查找的元素：");
                                                scanf("%d",&tp);
                                                result=LocateElem(L,tp);         
                                                if (result==ERROR) printf("查找失敗！\n");
                                                else if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("第%d個元素為%d\n",result,tp);                   
                                         break;
                                       case 8:
                                                printf("輸入你要查找的元素前驅：");
                                                scanf("%d",&tp);
                                                result=PriorElem(L,tp,e);        
                                                if (result==ERROR) printf("查找失敗！\n");
                                                else if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("%d的前驅為%d\n",tp,e);
                                         break;
                                       case 9:
                                                printf("輸入你要查找的元素後繼：");
                                                scanf("%d",&tp);
                                                result=NextElem(L,tp,e);         
                                                if (result==ERROR) printf("查找失敗！\n");
                                                else if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("%d的後繼為%d\n",tp,e);
                                         break;
                                       case 10:
                                                printf("輸入在第i個元素前插入的元素：");
                                                scanf("%d%d",&tp,&e);
                                                result=ListInsert(L,tp,e);
                                                if (result==ERROR) printf("插入失敗！\n");
                                                else if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("OK\n");                
                                         break;
                                       case 11:
                                                printf("輸入你要刪除的第i個元素：");
                                                scanf("%d",&tp);
                                                result=ListDelete(L,tp,e);       
                                                if (result==ERROR) printf("查找失敗！\n");
                                                else if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("已刪除第%d個元素%d\n",tp,e);
                                         break;
                                       case 12:
                                            result= ListTraverse(L);
                                            if (result==INFEASIBLE) printf("線性表不存在！\n");
                                         break;
                                        case 13:
                                                result=reverseList(L);
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("OK!\n");   
                                            break;       
                                        case 14:
                                            printf("刪除倒數第n個數:");
                                            scanf("%d",&k);
                                            result=RemoveNthFromEnd(L,k);
                                            if (result==INFEASIBLE) printf("線性表不存在或為空！\n");
                                            else if(result == ERROR) printf("刪除失敗！\n");
                                            else printf("已刪除倒數第%d個數%d！\n",k,result);    
                                            break;      
                                        case 15:
                                                result=sortList(L);
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("OK!\n");               
                                            break;  
                                        case 16:
                                                printf("輸入檔案名：");
                                                 scanf("%s",ch);
                                                 result=SaveList(L,ch);
                                                if (result==INFEASIBLE) printf("線性表不存在！\n");
                                                else printf("OK\n");                 
                                            break;
                                        case 17:
                                                printf("輸入檔案名：");
                                                 scanf("%s",ch);
                                                 result=LoadList(L,ch);
                                                if (result==INFEASIBLE) printf("線性表已存在！\n");
                                                else printf("OK\n");                        
                                            break;
                                        case 18:
                                            break;
                                        case 0:
                                            t=1;
                                            break;
                                        Lists.elem[result-1].L=L;   
                                    }//end of switch
                                    system("PAUSE");                
                                }                               
                            }
                        }                                   
                        break;
                    case 4:
                        break;
                    case 0:
                        t=1;
                        break;                                                                      
                }       
                system("PAUSE");                        
            }
            break;
            
        case 2:
            op=1;
            L=Ltemp;
            while(op!=0 and op!=18){                
                t=0;
                system("cls");  printf("\n\n");
                printf("      單線性表管理！     \n");
                printf("-------------------------------------------------\n");
                printf("          1. InitList       7. LocateElem\n");
                printf("          2. DestroyList   8. PriorElem\n");
                printf("          3. ClearList       9. NextElem \n");
                printf("          4. ListEmpty     10. ListInsert\n");
                printf("          5. ListLength     11. ListDelete\n");
                printf("          6. GetElem       12. ListTrabverse\n");
                printf("          13. reverseList     14. RemoveNthFromEnd\n");
                printf("          15. sortList       16. SaveList\n");
                printf("          17. LoadList      18.返回選擇頁面\n");  
                printf("          0. Exit\n");
                printf("-------------------------------------------------\n");
                printf("    請選擇你的操作[0~18]:");
                scanf("%d",&op);
                switch(op){
                   case 1:
                            result=InitList(L);
                            if (result==OK) printf("OK\n");
                            if (result==INFEASIBLE) printf("線性表已存在！\n");               
                     break;
                   case 2:
                            result=DestroyList(L);
                            if (result==OK) printf("OK\n");
                            if (result==INFEASIBLE) printf("線性表不存在！\n");
                     break;
                   case 3:
                            result=ClearList(L);
                            if (result==OK) printf("OK\n");
                            if (result==INFEASIBLE) printf("線性表不存在！\n");                
                     break;
                   case 4:
                            result=ListEmpty(L);
                            if (result==TRUE) printf("線性表為空！\n");
                            if(result==FALSE) printf("線性表不為空！\n");
                            if (result==INFEASIBLE) printf("線性表不存在！\n");                    
                     break;
                   case 5:
                            result= ListLength(L);
                            if (result==INFEASIBLE) printf("線性表不存在！\n");    
                            else printf("線性表長度為%d\n",result);
                     break;
                   case 6:
                            printf("獲取線性表的第i個元素：");
                            scanf("%d",&tp);
                            result=GetElem(L,tp,e);
                            if (result==ERROR) printf("查找失敗！\n");
                            if (result==INFEASIBLE) printf("線性表不存在！\n");
                            if(result==OK) printf("第%d個元素為%d\n",tp,e);  
                     break;
                   case 7:
                            printf("輸入你要查找的元素：");
                            scanf("%d",&tp);
                            result=LocateElem(L,tp);         
                            if (result==ERROR) printf("查找失敗！\n");
                            else if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("第%d個元素為%d\n",result,tp);                   
                     break;
                   case 8:
                            printf("輸入你要查找的元素前驅：");
                            scanf("%d",&tp);
                            result=PriorElem(L,tp,e);        
                            if (result==ERROR) printf("查找失敗！\n");
                            else if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("%d的前驅為%d\n",tp,e);
                     break;
                   case 9:
                            printf("輸入你要查找的元素後繼：");
                            scanf("%d",&tp);
                            result=NextElem(L,tp,e);         
                            if (result==ERROR) printf("查找失敗！\n");
                            else if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("%d的後繼為%d\n",tp,e);
                     break;
                   case 10:
                            printf("輸入在第i個元素前插入的元素：");
                            scanf("%d%d",&tp,&e);
                            result=ListInsert(L,tp,e);
                            if (result==ERROR) printf("插入失敗！\n");
                            else if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("OK\n");                
                     break;
                   case 11:
                            printf("輸入你要刪除的第i個元素：");
                            scanf("%d",&tp);
                            result=ListDelete(L,tp,e);       
                            if (result==ERROR) printf("查找失敗！\n");
                            else if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("已刪除第%d個元素%d\n",tp,e);
                     break;
                   case 12:
                        result= ListTraverse(L);
                        if (result==INFEASIBLE) printf("線性表不存在！\n");
                     break;
                    case 13:
                            result=reverseList(L);
                            if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("OK!\n");   
                        break;       
                    case 14:
                            printf("刪除倒數第n個數:");
                            scanf("%d",&k);
                            result=RemoveNthFromEnd(L,k);
                            if (result==INFEASIBLE) printf("線性表不存在或為空！\n");
                            else if(result == ERROR) printf("刪除失敗！\n");
                            else printf("已刪除倒數第%d個數%d！\n",k,result);        
                        break;      
                    case 15:
                            result=sortList(L);
                            if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("OK!\n");               
                        break;  
                    case 16:
                            printf("輸入檔案名：");
                             scanf("%s",ch);
                             result=SaveList(L,ch);
                            if (result==INFEASIBLE) printf("線性表不存在！\n");
                            else printf("OK\n");                 
                        break;
                    case 17:
                            printf("輸入檔案名：");
                             scanf("%s",ch);
                             result=LoadList(L,ch);
                            if (result==INFEASIBLE) printf("線性表已存在！\n");
                            else printf("OK\n");                        
                        break;
                    case 18:
                        Ltemp=L;
                        break;
                    case 0:
                        t=1;
                        break;
                }//end of switch
                system("PAUSE");                
            }
        
            break;//case2 break
        case 0:
            break;
        
    }
    if(t==1) break;
    
  }//end of while
printf("歡迎下次再使用本系統！\n");
return 0;
}//end of main()
/*--------page 23 on textbook --------------------*/
status InitList(LinkList &L)
// 線性表L不存在，構造一個空的線性表，返回OK，否則返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L != NULL) return INFEASIBLE;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    return OK;

    /********** End **********/
}
status DestroyList(LinkList &L)
// 如果線性表L存在，銷毀線性表L，釋放資料元素的空間，返回OK，否則返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL){
        return INFEASIBLE;
    }
    LinkList p=L;
    while (p != NULL) {
        LinkList temp = p->next; 
        free(p);             
        p = temp;         
    }
    L = NULL; 
    return OK;

    /********** End **********/
}

status ClearList(LinkList &L)
// 如果線性表L存在，刪除線性表L中的所有元素，返回OK，否則返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL){
        return INFEASIBLE;
    }
    LinkList p=L->next;
    while (p != NULL) {
        LinkList temp = p->next; 
        free(p);             
        p = temp;         
    }
    L->next = NULL; 
    return OK;

    /********** End **********/
}

status ListEmpty(LinkList L)
// 如果線性表L存在，判斷線性表L是否為空，空就返回TRUE，否則返回FALSE；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    if(L->next==NULL) return TRUE;
    else return FALSE; 

    /********** End **********/
}

int ListLength(LinkList L)
// 如果線性表L存在，返回線性表L的長度，否則返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    int s=0;
    LinkList p=L;
    while(p->next!=NULL){
        p=p->next;
        s++;
    }
    return s;
    /********** End **********/
}
status GetElem(LinkList L,int i,ElemType &e)
// 如果線性表L存在，獲取線性表L的第i個元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    int s=0;
    if(i<1) return ERROR;
    LinkList p=L;
    while(p->next!=NULL){
        s++;
        p=p->next;
        if(s==i){
            e=p->data;
            return OK;
        }
    }
    return ERROR;

    /********** End **********/
}

status LocateElem(LinkList L,ElemType e)
// 如果線性表L存在，查找元素e在線性表L中的位置序號；如果e不存在，返回ERROR；當線性表L不存在時，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    int s=0;
    LinkList p=L;
    while(p->next!=NULL){
        s++;
        p=p->next;
        if(e==p->data){
            return s;
        }
    }
    return ERROR;

    /********** End **********/
}
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果線性表L存在，獲取線性表L中元素e的前驅，保存在pre中，返回OK；如果沒有前驅，返回ERROR；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    int s=0;
    LinkList p=L,q;
    while(p->next!=NULL){
        s++;
        q=p;
        p=p->next;     
        if(e==p->data){
            if(s==1) return ERROR;
            pre=q->data;
            return OK;
        }
    }
    return ERROR;

    /********** End **********/
}
status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果線性表L存在，獲取線性表L元素e的後繼，保存在next中，返回OK；如果沒有後繼，返回ERROR；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList p=L;
    while(p->next!=NULL){
        p=p->next;     
        if(e==p->data){
            if(p->next==NULL) return ERROR;
            next=p->next->data;
            return OK;
        }
    }
    return ERROR;

    /********** End **********/
}
status ListInsert(LinkList &L,int i,ElemType e)
// 如果線性表L存在，將元素e插入到線性表L的第i個元素之前，返回OK；當插入位置不正確時，返回ERROR；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    if(i<1) return ERROR;
    int s=0;
    LinkList p=L,q, L1 = (LinkList)malloc(sizeof(LNode));
    L1->data=e;
    while(p!=NULL){
        s++;
        q=p;
        p=p->next;     
        if(s==i){
            L1->next=p;
            q->next=L1;
            return OK;
        }
    }
    return ERROR;

    /********** End **********/
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 如果線性表L存在，刪除線性表L的第i個元素，並保存在e中，返回OK；當刪除位置不正確時，返回ERROR；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    if(i<1) return ERROR;
    int s=0;
    LinkList p=L,q;
    while(p->next!=NULL){
        s++;
        q=p;
        p=p->next;     
        if(s==i){
            e=p->data;           
            q->next=p->next;
            free(p);
            return OK;
        }
    }
    return ERROR;

    /********** End **********/
}

status ListTraverse(LinkList L)
// 如果線性表L存在，依次顯示線性表中的元素，每個元素間空一格，返回OK；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList p=L;
    while(p->next!=NULL){
        p=p->next;     
        printf("%d ",p->data);
    }
    return OK;

    /********** End **********/
}
status SaveList(LinkList L,char FileName[])
// 如果線性表L存在，將線性表L的的元素寫到FileName檔中，返回OK，否則返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin 1 *********/
    if (L==NULL) {
        return INFEASIBLE;
    }
    FILE *fp = fopen(FileName, "w");
    LinkList p = L->next;
    while (p != NULL) {
        fprintf(fp, "%d\n", p->data); 
        p = p->next;
    }
    
    fclose(fp);
    return OK;

    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 如果線性表L不存在，將FileName檔中的資料讀入到線性表L中，返回OK，否則返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin 2 *********/
    if (L != NULL) {
        return INFEASIBLE;
    }
    L = (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    FILE *fp = fopen(FileName, "r");
    LinkList tail = L; 
    ElemType elem;
    while (fscanf(fp, "%d", &elem) == 1) { // 逐行讀取數據
        LinkList newNode = (LinkList)malloc(sizeof(LNode));
        newNode->data = elem;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    
    fclose(fp);
    return OK;

    /********** End 2 **********/
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一個名稱為ListName的空線性表，線性表資料又後臺測試程式插入。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/  
    Lists.elem[Lists.length].L=NULL;
    InitList(Lists.elem[Lists.length].L);
    strcpy(Lists.elem[Lists.length].name,ListName);
    Lists.length++;
    return OK;
    /********** End **********/
}
status RemoveList(LISTS &Lists,char ListName[])
// Lists中刪除一個名稱為ListName的線性表
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    for(int i=0;i<Lists.length;i++){
        if(strcmp(ListName,Lists.elem[i].name)==0){
            for(int j=i;j<Lists.length-1;j++){
                Lists.elem[j]=Lists.elem[j+1];
            }
            Lists.length--;
            return OK;
        }
    }
    return ERROR;
    /********** End **********/
}
int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一個名稱為ListName的線性表，成功返回邏輯序號，否則返回0
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    for(int i=0;i<Lists.length;i++){
        if(strcmp(Lists.elem[i].name,ListName)==0) return i+1;
    }
    return ERROR;
    /********** End **********/
}
status reverseList(LinkList L){
    if(L == NULL) return INFEASIBLE;
    if (L->next == NULL) return OK;
    LinkList p=L->next->next,lp=L->next,temp;
    lp->next = NULL;
    while( p!=NULL){
        temp=p->next;
        p->next=lp;
        lp=p;
        p=temp;
    }
    L->next=lp;
    return OK;
}
int RemoveNthFromEnd(LinkList L,int k){
    if(L==NULL or L->next == NULL) return INFEASIBLE;
    if(k<1) return ERROR;
    LinkList fast=L,slow=L;
    for(int i=1;i<=k;i++){
        fast=fast->next;
        if(fast == NULL) return ERROR;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    int ans = slow->next->data;
    slow->next=slow->next->next;
    return ans;
}
int sortList(LinkList L){
    if(L==NULL) return INFEASIBLE;
    int a[100],len=0;
    LinkList p=L;
    while(p->next!=NULL){
        p=p->next;
        a[++len]=p->data;
    }
    std::sort(a+1,a+len+1);
    p=L,len=0;
    while(p->next!=NULL){
        p=p->next;
        p->data=a[++len];
    }
    return OK;
}



