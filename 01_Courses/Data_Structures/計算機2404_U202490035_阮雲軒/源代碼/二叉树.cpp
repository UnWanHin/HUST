/* Linear Table On Sequence Structure */
#include<bits/stdc++.h>
/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1 

typedef int status; 
typedef int ElemType; //資料元素類型定義

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int KeyType; 
typedef struct {  //二叉樹結點資料類型定義
     KeyType  key;
     char others[20];
} TElemType; 
typedef struct BiTNode{  //二叉鏈表結點的定義
      TElemType  data;
      struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
BiTree T,Ttemp;
typedef struct{  //線性表的集合類型定義
     struct { char name[30];
               BiTree T; 
     } elem[10];
     int length;
}LISTS;
LISTS Lists;      //線性表集合的定義Lists

/*-----page 19 on textbook ---------*/
status CreateBiTree(BiTree &T,TElemType definition[]);
status ClearBiTree(BiTree &T);
status DestroyBiTree(BiTree &T);
status BiTreeEmpty(BiTree &T);
int BiTreeDepth(BiTree T);
BiTNode* LocateNode(BiTree T,KeyType e);
status Assign(BiTree &T,KeyType e,TElemType value);
BiTNode* GetSibling(BiTree T,KeyType e);
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c);
status DeleteNode(BiTree &T,KeyType e);
status PreOrderTraverse(BiTree T,void (*visit)(BiTree));
status InOrderTraverse(BiTree T,void (*visit)(BiTree));
status PostOrderTraverse(BiTree T,void (*visit)(BiTree));
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree));
status SaveBiTree(BiTree T, const char FileName[]);
status LoadBiTree(BiTree &T,  const char FileName[]);
int MaxPathSum(BiTree &T);
BiTNode* LowestCommonAncestor(BiTree &T,int e1,int e2);
BiTree InvertTree(BiTree &T);
status AddList(LISTS &Lists,char ListName[]);
status RemoveList(LISTS &Lists,char ListName[]);
int LocateList(LISTS Lists,char ListName[]);
void visit(BiTree T)
{
    printf(" %d,%s",T->data.key,T->data.others);
}
int op=1,result,tp,e,k,op1=1,t,lflag,len,ldeep=1,ldeepmax,i_1,LR;
BiTNode *p_7,*p_8,*p_16;
std::map<int,int> flag;
TElemType definition[100],c;
char ch[1000];
char name[30];
//簡化過
/*--------------------------------------------*/
int main(){

while(op1){
    system("cls");  printf("\n\n");
    printf("-------------------------------------------------\n");
    printf("1.進入多二叉樹管理        2.進入單二叉樹管理\n");
    printf("0. Exit\n");
    printf("-------------------------------------------------\n");
    scanf("%d",&op1);   
    switch(op1){
        case 1:
            op=1;
            while(op!=0 and op!=4){
                t=0;
                system("cls");  printf("\n\n");
                printf("      多二叉樹管理！     \n");         
                printf("-------------------------------------------------\n");
                printf("          1. AddTree       3. LocateTree\n");
                printf("          2. DestroyTree   4. 返回選擇頁面\n");       
                printf("          0.Exit\n");   
                printf("-------------------------------------------------\n");
                printf("    請選擇你的操作[0~4]:");        
                scanf("%d",&op);
                switch(op){
                    case 1:
                        printf("添加一個二叉樹，請輸入二叉樹名稱：");
                        
                        scanf("%s",name);
                        result=AddList(Lists,name);                 
                        if(result==OK) printf("OK!\n");
                        break;
                    case 2:
                        printf("刪除一個二叉樹，請輸入二叉樹名稱：");
                        scanf("%s",name);
                        result=RemoveList(Lists,name);                  
                        if(result==OK) printf("OK!\n");
                        else printf("二叉樹不存在！\n");               
                        break;
                    case 3:
                        printf("查找一個二叉樹，請輸入二叉樹名稱：");
                        scanf("%s",name);
                        result=LocateList(Lists,name);                  
                        if(result==ERROR) printf("二叉樹不存在！\n");
                        else{
                            int t;
                            printf("OK!  按1對其進行單二叉樹操作,按其他按鈕返回");
                            scanf("%d",&t);
                            if(t==1){
                                T=Lists.elem[result-1].T;
                                while(op!=0 and op!=20){
                                    int t=0;
                                    system("cls");  printf("\n\n");
                                    printf("      單二叉樹管理！     \n");
                                    printf("-------------------------------------------------\n");
                                    printf("          1. CreateBiTree       7. Assign\n");
                                    printf("          2. DestroyBiTree   8. GetSibling\n");
                                    printf("          3. ClearBiTree       9. InsertNode \n");
                                    printf("          4. BiTreeEmpty     10. DeleteNode\n");
                                    printf("          5. BiTreeDepth     11. PreOrderTraverse\n");
                                    printf("          6. LocateNode       12. InOrderTraverse\n");
                                    printf("          13. PostOrderTraverse     14. LevelOrderTraverse\n");
                                    printf("          15. MaxPathSum      16. LowestCommonAncestor\n");
                                    printf("          17. InvertTree      18. SaveBiTree\n");
                                    printf("          19. LoadBiTree     20.返回多線性表操作\n");   
                                    printf("          0. Exit\n");
                                    printf("-------------------------------------------------\n");
                                    printf("    請選擇你的操作[0~18]:");
                                    scanf("%d",&op);
                                    switch(op){
                                        case 1:
                                                if(T!=NULL){
                                                    printf("二叉樹已存在！");
                                                    break;    
                                                }
                                                printf("請輸入定義序列:\n");                                               
                                                i_1=0;
                                                do {
                                                    scanf("%d%s",&definition[i_1].key,definition[i_1].others);
                                                } while (definition[i_1++].key!=-1);
                                                lflag=len=0;
                                                flag.clear();
                                                result=CreateBiTree(T,definition);
                                                if (result==OK) printf("OK\n");
                                                if (result==ERROR) printf("關鍵字重複！\n");               
                                         break;
                                        case 2:
                                                result=DestroyBiTree(T);
                                                if (result==OK) printf("OK\n");     
                                                else printf("二叉樹不存在！\n");   
                                         break;
                                        case 3:
                                                result=ClearBiTree(T);
                                                if (result==OK) printf("OK\n");         
                                                else printf("二叉樹不存在！\n");                                           
                                         break;
                                        case 4:
                                                result=BiTreeEmpty(T);
                                                if (result==TRUE) printf("二叉樹為空！\n");
                                                if(result==FALSE) printf("二叉樹不為空！\n");
                                                if (result==INFEASIBLE) printf("二叉樹不存在！\n");                    
                                         break;
                                       case 5:
                                                result= BiTreeDepth(T);
                                                ldeep = 1;ldeepmax = 0; 
                                                if (result==INFEASIBLE) printf("二叉樹不存在！\n");    
                                                else printf("二叉樹深度為%d\n",result);
                                         break;
                                       case 6:
                                                printf("輸入你要查找的元素關鍵字：");
                                                scanf("%d",&tp);
                                                p_7=LocateNode(T,tp);    
                                                if (p_7==NULL) printf("查找失敗！\n");
                                                else printf("%d,%s",p_7->data.key,p_7->data.others);                
                                         break;
                                       case 7:
                                                printf("輸入關鍵字與修改為的值：");
                                                scanf("%d%d%s",&tp,&c.key,c.others);
                                                result=Assign(T,tp,c);   
                                                if(result == OK) printf("OK");
                                                else printf("修改失敗！\n");     
                                         break;                                      
                                       case 8:
                                                printf("輸入你要查找的關鍵字的兄弟：");
                                                scanf("%d",&e);
                                                p_8=GetSibling(T,e);         
                                                if (p_8==NULL) printf("沒有兄弟！\n");
                                                else printf("%d,%s",p_8->data.key,p_8->data.others);
                                         break;
                                       case 9:                          
                                                printf("輸入4個元素，分別表示插入位置，左右（0或1，-1表示作為根節點），插入關鍵字和資料：");
                                                scanf("%d%d%d%s",&e,&LR,&c.key,c.others);
                                                result=InsertNode(T,e,LR,c);     
                                                if (result==OK) printf("OK！\n");
                                                else printf("插入失敗！\n");
                                         break;
                                       case 10:
                                                printf("輸入你要刪除的元素關鍵字：");
                                                scanf("%d",&tp);
                                                result=DeleteNode(T,tp);         
                                                if(result == OK) printf("OK!");
                                                else printf("刪除失敗！"); 
                                         break;
                                       case 11:
                                            PreOrderTraverse(T,visit);
                                         break;
                                       case 12:
                                            InOrderTraverse(T,visit);
                                         break;
                                       case 13:
                                            PostOrderTraverse(T,visit);
                                         break;                                                                                  
                                        case 14:
                                            LevelOrderTraverse(T,visit);    
                                            break;      
                                        case 15:
                                                result=MaxPathSum(T);
                                                if (result==-1) printf("二叉樹不存在！\n");
                                                else printf("最大路徑為%d!\n",result);               
                                            break;  
                                        case 16:
                                                int e1,e2;
                                                printf("請輸入兩個關鍵字！：\n");
                                                scanf("%d%d",&e1,&e2);
                                                p_16=LowestCommonAncestor(T,e1,e2);
                                                if (p_16==NULL) printf("查找失敗！\n");
                                                else printf("%d %s\n",p_16->data.key,p_16->data.others);                
                                            break;      
                                        case 17:
                                                T = InvertTree(T);
                                                if(T != NULL) printf("OK!");                
                                                else printf("翻轉失敗！");
                                            break; 
                                        case 18:
                                                printf("輸入檔案名：");
                                                 scanf("%s",ch);
                                                 result=SaveBiTree(T,ch);
                                                if (result==OK) printf("OK\n");
                                                else printf("二叉樹不存在！\n");                
                                            break;
                                        case 19:
                                                printf("輸入檔案名：");
                                                 scanf("%s",ch);
                                                 result=LoadBiTree(T,ch);
                                                if (result==OK) printf("OK\n");
                                                else printf("二叉樹不存在！\n");                       
                                            break;
                                        case 20:
                                            break;
                                        case 0:
                                            t=1;
                                            break;
                                        Lists.elem[result-1].T=T;   
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
            T=Ttemp;
            while(op!=0 and op!=20){
                int t=0;
                system("cls");  printf("\n\n");
                printf("      單二叉樹管理！     \n");
                printf("-------------------------------------------------\n");
                printf("          1. CreateBiTree       7. Assign\n");
                printf("          2. DestroyBiTree   8. GetSibling\n");
                printf("          3. ClearBiTree       9. InsertNode \n");
                printf("          4. BiTreeEmpty     10. DeleteNode\n");
                printf("          5. BiTreeDepth     11. PreOrderTraverse\n");
                printf("          6. LocateNode       12. InOrderTraverse\n");
                printf("          13. PostOrderTraverse     14. LevelOrderTraverse\n");
                printf("          15. MaxPathSum      16. LowestCommonAncestor\n");
                printf("          17. InvertTree      18. SaveBiTree\n");
                printf("          19. LoadBiTree     20.返回選擇頁面\n"); 
                printf("          0. Exit\n");
                printf("-------------------------------------------------\n");
                printf("    請選擇你的操作[0~18]:");
                scanf("%d",&op);
                switch(op){
                   case 1:
                            if(T!=NULL){
                                printf("二叉樹已存在！");
                                break;    
                            }
                            printf("請輸入定義序列:\n");
                            i_1=0;
                            do {
                                scanf("%d%s",&definition[i_1].key,definition[i_1].others);
                            } while (definition[i_1++].key!=-1);
                            lflag=len=0;
                            flag.clear();
                            result=CreateBiTree(T,definition);
                            if (result==OK) printf("OK\n");
                            if (result==ERROR) printf("關鍵字重複！\n");               
                     break;
                   case 2:
                            result=DestroyBiTree(T);
                            if (result==OK) printf("OK\n");     
                            else printf("二叉樹不存在！\n");   
                     break;
                   case 3:
                            result=ClearBiTree(T);
                            if (result==OK) printf("OK\n");         
                            else printf("二叉樹不存在！\n");                                           
                     break;
                   case 4:
                            result=BiTreeEmpty(T);
                            if (result==TRUE) printf("二叉樹為空！\n");
                            if(result==FALSE) printf("二叉樹不為空！\n");
                            if (result==INFEASIBLE) printf("二叉樹不存在！\n");                    
                     break;
                   case 5:
                            result= BiTreeDepth(T);
                            ldeep = 1;ldeepmax = 0; 
                            if (result==INFEASIBLE) printf("二叉樹不存在！\n");    
                            else printf("二叉樹深度為%d\n",result);
                     break;
                   case 6:
                            printf("輸入你要查找的元素關鍵字：");
                            scanf("%d",&tp);
                            p_7=LocateNode(T,tp);        
                            if (p_7==NULL) printf("查找失敗！\n");
                            else printf("%d,%s",p_7->data.key,p_7->data.others);                
                     break;
                   case 7:
                            printf("輸入關鍵字與修改為的值：");
                            scanf("%d%d%s",&tp,&c.key,c.others);
                            result=Assign(T,tp,c);   
                            if(result == OK) printf("OK");
                            else printf("修改失敗！\n");     
                     break;                                      
                   case 8:
                            printf("輸入你要查找的關鍵字的兄弟：");
                            scanf("%d",&e);
                            p_8=GetSibling(T,e);         
                            if (p_8==NULL) printf("沒有兄弟！\n");
                            else printf("%d,%s",p_8->data.key,p_8->data.others);
                     break;
                   case 9:
                            printf("輸入4個元素，分別表示插入位置，左右（0或1，-1表示作為根節點），插入關鍵字和資料：");
                            scanf("%d%d%d%s",&e,&LR,&c.key,c.others);
                            result=InsertNode(T,e,LR,c);     
                            if (result==OK) printf("OK！\n");
                            else printf("插入失敗！\n");
                     break;
                   case 10:
                            printf("輸入你要刪除的元素關鍵字：");
                            scanf("%d",&tp);
                            result=DeleteNode(T,tp);         
                            if(result == OK) printf("OK!");
                            else printf("刪除失敗！"); 
                     break;
                   case 11:
                        PreOrderTraverse(T,visit);
                     break;
                   case 12:
                        InOrderTraverse(T,visit);
                     break;
                   case 13:
                        PostOrderTraverse(T,visit);
                     break;                                                                                  
                    case 14:
                        LevelOrderTraverse(T,visit);    
                        break;      
                    case 15:
                            result=MaxPathSum(T);
                            if (result==-1) printf("二叉樹不存在！\n");
                            else printf("最大路徑為%d!\n",result);               
                        break;  
                    case 16:
                            int e1,e2;
                            printf("請輸入兩個關鍵字！：\n");
                            scanf("%d%d",&e1,&e2);
                            p_16=LowestCommonAncestor(T,e1,e2);
                            if (p_16==NULL) printf("查找失敗！\n");
                            else printf("%d %s\n",p_16->data.key,p_16->data.others);                
                        break;      
                    case 17:
                            T = InvertTree(T);
                            if(T != NULL) printf("OK!");                
                            else printf("翻轉失敗！");
                        break;
                    case 18:
                            printf("輸入檔案名：");
                             scanf("%s",ch);
                             result=SaveBiTree(T,ch);
                            if (result==OK) printf("OK\n");
                            else printf("二叉樹不存在！\n");                
                        break;
                    case 19:
                            printf("輸入檔案名：");
                             scanf("%s",ch);
                             result=LoadBiTree(T,ch);
                            if (result==OK) printf("OK\n");
                            else printf("二叉樹不存在！\n");                       
                        break;
                    case 20:
                        Ttemp = T;
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
status CreateBiTree(BiTree &T,TElemType definition[])
/*根據帶空枝的二叉樹先根遍歷序列definition構造一棵二叉樹，將根節點指針賦值給T並返回OK，
如果有相同的關鍵字，返回ERROR。此題允許通過增加其它函數輔助實現本關任務*/
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(definition[len].key == -1){
        T=NULL;
        return OK;
    }
    if(definition[len].key == 0){
        T=NULL;
        len++;
        return OK;
    }    
    T=(BiTree)malloc(sizeof(BiTNode));
    if(flag[definition[len].key] == 1){
        lflag=1;
    }
    flag[definition[len].key] = 1;
    T->data.key = definition[len].key;
    strcpy(T->data.others , definition[len].others);
    T->lchild=T->rchild = NULL;
    len++;
    CreateBiTree(T->lchild,definition);
    CreateBiTree(T->rchild,definition);
    if(lflag == 1 ) return ERROR;
    return OK;
    /********** End **********/
}

status DestroyBiTree(BiTree &T)
//將二叉樹設置成空，並刪除所有結點，釋放結點空間
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    if(T->lchild!=NULL) ClearBiTree(T->lchild);
    if(T->rchild!=NULL) ClearBiTree(T->rchild);
    free(T); 
    T = NULL ;
    return OK;
    /********** End **********/
}

status ClearBiTree(BiTree &T)
//將二叉樹設置成空，並刪除所有結點，釋放結點空間
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    T->lchild = NULL;
    T->rchild = NULL;
    T->data.key = 0;
    strcpy(T->data.others , "");
    return OK;
    /********** End **********/
}

status BiTreeEmpty(BiTree &T)
// 如果線性表L存在，判斷線性表L是否為空，空就返回TRUE，否則返回FALSE；如果線性表L不存在，返回INFEASIBLE。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    if(T->data.key==0) return TRUE;
    else return FALSE; 

    /********** End **********/
}

int BiTreeDepth(BiTree T)
//求二叉樹T的深度
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T==NULL) return 0;
    if(T->lchild!=NULL){
        ldeep++;
        BiTreeDepth(T->lchild);
        ldeep--;
    }
    if(T->rchild!=NULL){
        ldeep++;
        BiTreeDepth(T->rchild);
        ldeep--;
    }
    ldeepmax=std::max(ldeepmax,ldeep);
    return ldeepmax;
    /********** End **********/
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找結點
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T==NULL) return NULL;
    if(T->data.key == e) return T;
    BiTNode* k=LocateNode(T->lchild,e);
    if(k == NULL) return LocateNode(T->rchild,e);
    else return k;

    /********** End **********/
}

bool check_Assign(BiTree T,int k,BiTNode* now){
    if(T==NULL) return true;
    if(T!=now && T->data.key==k) return false;
    return check_Assign(T->lchild,k,now)&&check_Assign(T->rchild,k,now);
}
status Assign(BiTree &T,KeyType e,TElemType value)
//實現結點賦值。此題允許通過增加其它函數輔助實現本關任務
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    BiTNode* p= LocateNode(T,e);
    if(p==NULL) return ERROR;
    if(value.key == e ){
        p->data = value;
        return OK;
    }
    else {
        if(check_Assign(T,value.key,p)){
            p->data = value;
            return OK;            
        }
        else return ERROR;
    }

    /********** End **********/
}

BiTNode* GetSibling(BiTree T,KeyType e)
//實現獲得兄弟結點
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if (T == NULL) {
        return NULL;
    }

    // 檢查左孩子是否是目標節點
    if (T->lchild != NULL && T->lchild->data.key == e) {
        return T->rchild;
    }

    // 檢查右孩子是否是目標節點
    if (T->rchild != NULL && T->rchild->data.key == e) {
        return T->lchild;
    }

    // 遞迴在左子樹中查找
    BiTNode* leftResult = GetSibling(T->lchild, e);
    if (leftResult != NULL) {
        return leftResult;
    }

    // 遞迴在右子樹中查找
    return GetSibling(T->rchild, e);

    /********** End **********/
}

bool check_Insert(BiTree T,int k){
    if(T==NULL) return true;
    if(T->data.key==k) return false;
    return check_Insert(T->lchild,k)&&check_Insert(T->rchild,k);
}
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入結點。此題允許通過增加其它函數輔助實現本關任務
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    BiTNode* temp=(BiTree)malloc(sizeof(BiTNode));
    temp->data = c;
    temp->lchild=temp->rchild=NULL;
    if(LR == -1){
        temp->rchild = T;
        T = temp;
        return OK;
    }
    BiTNode* p=LocateNode(T,e);
    if(p==NULL) return ERROR; 
    if(!check_Insert(T,c.key)) return ERROR;
    if(LR==0){
        temp->rchild=p->lchild;
        p->lchild=temp;
    }
    if(LR==1){
        temp->rchild=p->rchild;
        p->rchild=temp;
    }    
    return OK;
    /********** End **********/
}

status DeleteNode(BiTree &T,KeyType e)
//刪除結點。此題允許通過增加其它函數輔助實現本關任務
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T==NULL) return ERROR;
    if(T->data.key == e ){
        if(T->lchild==NULL && T->rchild == NULL){ 
            free(T);
            T=NULL;
        }
        else if(T->lchild != NULL && T->rchild!=NULL)  {
            BiTree p = T->lchild;
            while(p->rchild!=NULL) p = p->rchild;
            p->rchild =T->rchild;
            BiTree temp = T;
            T= T->lchild;
            free(temp);
        }     
        else if( T->lchild != NULL){
            BiTree temp = T;
            T= T->lchild;
            free(temp);
        }    
        else if( T->rchild != NULL){
            BiTree temp = T;
            T= T->rchild;
            free(temp);
        }
        return OK;
    }
    if (DeleteNode(T->lchild,e) == OK) return OK;
    if (DeleteNode(T->rchild,e) == OK) return OK;
    return ERROR;

    /********** End **********/
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍歷二叉樹T
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    printf(" %d,%s",T->data.key,T->data.others);
    if(T->lchild!=NULL) PreOrderTraverse(T->lchild,visit);
    if(T->rchild!=NULL) PreOrderTraverse(T->rchild,visit);
    /********** End **********/
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍歷二叉樹T
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T->lchild!=NULL) InOrderTraverse(T->lchild,visit);
    printf(" %d,%s",T->data.key,T->data.others);
    if(T->rchild!=NULL) InOrderTraverse(T->rchild,visit);

    /********** End **********/
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//後序遍歷二叉樹T
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(T->lchild!=NULL) PostOrderTraverse(T->lchild,visit); 
    if(T->rchild!=NULL) PostOrderTraverse(T->rchild,visit);
    printf(" %d,%s",T->data.key,T->data.others);
    /********** End **********/
}
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按層遍歷二叉樹T
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    std::queue<BiTree> q;
    BiTree p;
    q.push(T);
    while(!q.empty()){
        p = q.front();
        q.pop();
        printf(" %d,%s",p->data.key,p->data.others);
        if(p->lchild!=NULL) q.push(p->lchild);
        if(p->rchild!=NULL) q.push(p->rchild);
    } 

    /********** End **********/
}

int MaxPathSum(BiTree &T){
    if (T == NULL) {
        return -1;
    }
    int leftMax = MaxPathSum(T->lchild);
    int rightMax = MaxPathSum(T->rchild);
    int maxPath = (leftMax > rightMax ? leftMax : rightMax) + 1;
    return maxPath;
}

BiTNode* LowestCommonAncestor(BiTree &T,int e1,int e2){
    if (T == NULL) return NULL; 
    if (T->data.key == e1 || T->data.key == e2)
        return T;
    BiTree left = LowestCommonAncestor(T->lchild, e1, e2);
    BiTree right = LowestCommonAncestor(T->rchild, e1, e2);
    if (left && right)
        return T;
    return left ? left : right; 
}

BiTree InvertTree(BiTree &T) {
    if (T == NULL) {
        return NULL; // 空樹直接返回
    }
    
    // 交換當前節點的左右子樹
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    
    // 遞迴翻轉新的左右子樹（原右、左子樹）
    InvertTree(T->lchild);
    InvertTree(T->rchild);
    
    return T; // 返回翻轉後的根節點
}

status SaveBiTree(BiTree T, const char FileName[])
//將二叉樹的結點數據寫入到文件FileName中
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin 1 *********/
    int s = 1,flag=1,lq;
    std::queue<BiTree> q;
    BiTree p;
    FILE *fp = fopen(FileName, "w");
    q.push(T);
    while(flag==1){
        flag=0;
        lq=q.size();
        for(int i=1;i<=lq;i++){
            p = q.front();
            q.pop();
            if(p==NULL){
                q.push(NULL);
                q.push(NULL);
                s++;
                continue;
            }    
            fprintf(fp, "%d %d %s\n", s ,p->data.key,p->data.others); 
            if(p->lchild!=NULL or p->rchild!=NULL) flag = 1;
            q.push(p->lchild);
            q.push(p->rchild);
            s++;        
        }
    }
    fprintf(fp, "%d %d %s\n", 0 ,0,NULL); 
    fclose(fp);
    return OK;

    /********** End 1 **********/
}
status LoadBiTree(BiTree &T,  const char FileName[])
//讀入文件FileName的結點數據，創建二叉樹
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName, "r");
    TElemType d[100];
    int ans,i=0,kt=1;
    BiTNode *p[100]={NULL};
    while (1){
        fscanf(fp, "%d%d%s",&kt,&d[i].key,d[i].others);   
        if(kt==0) break;
        p[kt]=(BiTNode *)malloc(sizeof(BiTNode));
        p[kt]->data=d[i];
        p[kt]->lchild=NULL;
        p[kt]->rchild=NULL;
        if (kt!=1){
            if (kt%2==0) p[kt/2]->lchild=p[kt];  
            else p[kt/2]->rchild=p[kt];            
        }
        i++;      
    } 
    T=p[1];
    fclose(fp);
    return OK;
    /********** End 2 **********/
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一個名稱為ListName的空線性表，線性表資料又後臺測試程式插入。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/  
    Lists.elem[Lists.length].T=(BiTree)malloc(sizeof(BiTNode));
    Lists.elem[Lists.length].T=NULL;
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



