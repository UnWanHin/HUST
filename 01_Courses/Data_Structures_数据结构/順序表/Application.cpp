/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
#include<algorithm>
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

typedef struct{
	ElemType * elem;
	int length;
	int listsize;
}SqList;

SqList L;

/*int sum,max;
for(int i=0;i<L.length;i++)
{
	for(int j=i)
}*/

/*-----page 19 on textbook ---------*/
status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList&L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType& e);
status LocateElem(SqList L,ElemType e); //?化?
status PriorElem(SqList L,ElemType cur,ElemType &pre_e);
status NextElem(SqList L,ElemType cur,ElemType&next_e);
status ListInsert(SqList &L,int i,ElemType e);
status ListDelete(SqList &L,int i,ElemType& e);
status ListTraverse(SqList L);  



/*--------------------------------------------*/
int main(){
  int op=1,result,tp,e;
while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("\t    	  1. InitList       \t7. LocateElem\n");
	printf("\t    	  2. DestroyList    \t8. PriorElem\n");
	printf("\t    	  3. ClearList       \t9. NextElem \n");
	printf("\t    	  4. ListEmpty     \t10. ListInsert\n");
	printf("\t    	  5. ListLength     \t11. ListDelete\n");
	printf("\t    	  6. GetElem       \t12. ListTrabverse\n\n");
	printf("\t    	  13. MaxSubArray  \t14. SubArrayNum\n");
	printf("\t    	  15. sortList      \t16. SavetoLocal\n");
	printf("\t    	  17. WithMultiLists\t0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    請選擇你的操作[0~12]:");
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
				result=PriorElem(L,tp,e);		 
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
	case 0:
         break;
	}//end of switch
	system("PAUSE");
  }//end of while
printf("歡迎下次再使用本系統！\n");
return 0;
}//end of main()



status InitList(SqList& L)
{
    if(L.elem == NULL)
    {
        L.elem=(ElemType *) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length=0;
        L.listsize=LIST_INIT_SIZE;
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }
}

status DestroyList(SqList& L)
{
    if(L.elem!=NULL)
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }
}

status ClearList(SqList& L)
{
    if(L.elem!=NULL)
    {

        L.length=0;
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }
}

status ListEmpty(SqList L)
{
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    if(L.length==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

status ListLength(SqList L)
{
    if(L.elem!=NULL)
    {
        return L.length;
    }
    else
    {
        return INFEASIBLE;
    }
}

status GetElem(SqList L,int i,ElemType &e)
{
    if(i<1||i>L.length)
    {
        return ERROR;
    }
    if(L.elem!=NULL)
    {
        e=L.elem[i-1];
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }
}

int LocateElem(SqList L,ElemType e)
{
    if(L.elem!=NULL)
    {
        for(int i=0;i<L.length;i++)
        {
            if(e==L.elem[i])
            {
                return i+1;
            }
        }
        return 0;
        
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
{
    if(L.elem!=NULL)
    {
        for(int i=1;i<L.length;i++)
        {
            if(e==L.elem[i])
            {
                pre=L.elem[i-1];
                return OK;
            }
            
        }
        return ERROR;
    }
    else
    {
        return INFEASIBLE;
    }
}

status NextElem(SqList L,ElemType e,ElemType &next)
{
    if(L.elem!=NULL)
    {
        for(int i=1;i<L.length-1;i++)
        {
            if(e==L.elem[i])
            {
                next=L.elem[i+1];
                return OK;
            }
            
        }
        return ERROR;
    }
    else
    {
        return INFEASIBLE;
    }
}

status ListInsert(SqList &L,int i,ElemType e)
{
    if(L.elem==NULL) return INFEASIBLE;
    if(i<1 || i>L.length+1) return ERROR;  
    if(L.length>=L.listsize){
        int *newbase=(int *)realloc(L.elem,(L.listsize+1)*sizeof(int));
        if(newbase==NULL) return 0;
        L.listsize++;
        L.elem=newbase;
    }
    for(int j=L.length;j>i-1;j--){
        L.elem[j]=L.elem[j-1];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}

status ListDelete(SqList &L,int i,ElemType &e)
{
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    if(i<=0 || i>L.length)
    {
        return ERROR;
    }
    e=L.elem[i-1];
    i--;
    for(i;i<=L.length-1;i++)
    {
        L.elem[i]=L.elem[i+1];
    }
    L.length--;
    return OK;
}

status ListTraverse(SqList L)
{
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    for(int i=0;i<L.length;i++)
    {
        printf("%d",L.elem[i]);
        if(i<L.length-1)
        {
            printf(" ");
        }
    }
    printf("\n");
    return OK;
}



