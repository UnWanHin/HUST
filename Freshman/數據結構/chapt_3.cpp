/* Linear Table On Sequence Structure */
#include<bits/stdc++.h>
/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1 

typedef int status; 
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int KeyType; 
typedef struct {  //二叉树结点数据类型定义
     KeyType  key;
     char others[20];
} TElemType; 
typedef struct BiTNode{  //二叉链表结点的定义
      TElemType  data;
      struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
BiTree T,Ttemp;
typedef struct{  //线性表的集合类型定义
     struct { char name[30];
               BiTree T; 
     } elem[10];
     int length;
}LISTS;
LISTS Lists;      //线性表集合的定义Lists

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
//简化过
/*--------------------------------------------*/
int main(){

while(op1){
	system("cls");	printf("\n\n");
	printf("-------------------------------------------------\n");
	printf("1.进入多二叉树管理        2.进入单二叉树管理\n");
	printf("0. Exit\n");
	printf("-------------------------------------------------\n");
	scanf("%d",&op1);	
	switch(op1){
		case 1:
			op=1;
			while(op!=0 and op!=4){
				t=0;
				system("cls");	printf("\n\n");
				printf("      多二叉树管理！     \n");			
				printf("-------------------------------------------------\n");
				printf("    	  1. AddTree       3. LocateTree\n");
				printf("    	  2. DestroyTree   4. 返回选择页面\n");		
				printf("          0.Exit\n");	
				printf("-------------------------------------------------\n");
				printf("    请选择你的操作[0~4]:");		
				scanf("%d",&op);
				switch(op){
					case 1:
						printf("添加一个二叉树，请输入二叉树名称：");
						
	    				scanf("%s",name);
   						result=AddList(Lists,name);					
   						if(result==OK) printf("OK!\n");
						break;
					case 2:
						printf("删除一个二叉树，请输入二叉树名称：");
	    				scanf("%s",name);
   						result=RemoveList(Lists,name);					
   						if(result==OK) printf("OK!\n");
						else printf("二叉树不存在！\n");				
						break;
					case 3:
						printf("查找一个二叉树，请输入二叉树名称：");
	    				scanf("%s",name);
   						result=LocateList(Lists,name);					
   						if(result==ERROR) printf("二叉树不存在！\n");
						else{
							int t;
							printf("OK!  按1对其进行单二叉树操作,按其他按钮返回");
							scanf("%d",&t);
							if(t==1){
								T=Lists.elem[result-1].T;
								while(op!=0 and op!=20){
									int t=0;
									system("cls");	printf("\n\n");
									printf("      单二叉树管理！     \n");
									printf("-------------------------------------------------\n");
									printf("    	  1. CreateBiTree       7. Assign\n");
									printf("    	  2. DestroyBiTree   8. GetSibling\n");
									printf("    	  3. ClearBiTree       9. InsertNode \n");
									printf("    	  4. BiTreeEmpty     10. DeleteNode\n");
									printf("    	  5. BiTreeDepth     11. PreOrderTraverse\n");
									printf("    	  6. LocateNode       12. InOrderTraverse\n");
									printf("    	  13. PostOrderTraverse     14. LevelOrderTraverse\n");
									printf("    	  15. MaxPathSum      16. LowestCommonAncestor\n");
									printf("    	  17. InvertTree      18. SaveBiTree\n");
									printf("    	  19. LoadBiTree     20.返回多线性表操作\n");	
									printf("    	  0. Exit\n");
									printf("-------------------------------------------------\n");
									printf("    请选择你的操作[0~18]:");
									scanf("%d",&op);
								    switch(op){
									    case 1:
									   			if(T!=NULL){
									   				printf("二叉树已存在！");
													break;    
												}
												printf("请输入定义序列:\n");									   			
												i_1=0;
												do {
													scanf("%d%s",&definition[i_1].key,definition[i_1].others);
												} while (definition[i_1++].key!=-1);
												lflag=len=0;
												flag.clear();
												result=CreateBiTree(T,definition);
												if (result==OK) printf("OK\n");
												if (result==ERROR) printf("关键字重复！\n");               
										 break;
									    case 2:
												result=DestroyBiTree(T);
												if (result==OK) printf("OK\n");		
												else printf("二叉树不存在！\n");	
										 break;
									    case 3:
												result=ClearBiTree(T);
												if (result==OK) printf("OK\n");			
												else printf("二叉树不存在！\n");							   				
										 break;
									    case 4:
												result=BiTreeEmpty(T);
												if (result==TRUE) printf("二叉树为空！\n");
												if(result==FALSE) printf("二叉树不为空！\n");
												if (result==INFEASIBLE) printf("二叉树不存在！\n");		   			
										 break;
									   case 5:
												result= BiTreeDepth(T);
												ldeep = 1;ldeepmax = 0; 
												if (result==INFEASIBLE) printf("二叉树不存在！\n");	
												else printf("二叉树深度为%d\n",result);
										 break;
									   case 6:
									   			printf("输入你要查找的元素关键字：");
									   			scanf("%d",&tp);
												p_7=LocateNode(T,tp);	 
												if (p_7==NULL) printf("查找失败！\n");
												else printf("%d,%s",p_7->data.key,p_7->data.others);				
										 break;
									   case 7:
									   			printf("输入关键字与修改为的值：");
									   			scanf("%d%d%s",&tp,&c.key,c.others);
												result=Assign(T,tp,c);	 
												if(result == OK) printf("OK");
												else printf("修改失败！\n");		
										 break;										 
									   case 8:
									   			printf("输入你要查找的关键字的兄弟：");
									   			scanf("%d",&e);
												p_8=GetSibling(T,e);		 
												if (p_8==NULL) printf("没有兄弟！\n");
												else printf("%d,%s",p_8->data.key,p_8->data.others);
										 break;
									   case 9:							
												printf("输入4个元素，分别表示插入位置，左右（0或1，-1表示作为根节点），插入关键字和数据：");
									   			scanf("%d%d%d%s",&e,&LR,&c.key,c.others);
												result=InsertNode(T,e,LR,c);	 
												if (result==OK) printf("OK！\n");
												else printf("插入失败！\n");
										 break;
									   case 10:
									   			printf("输入你要删除的元素关键字：");
									   			scanf("%d",&tp);
												result=DeleteNode(T,tp);		 
												if(result == OK) printf("OK!");
												else printf("删除失败！"); 
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
												if (result==-1) printf("二叉树不存在！\n");
												else printf("最大路径为%d!\n",result);				
											break;	
										case 16:
												int e1,e2;
												printf("请输入两个关键字！：\n");
												scanf("%d%d",&e1,&e2);
												p_16=LowestCommonAncestor(T,e1,e2);
												if (p_16==NULL) printf("查找失败！\n");
												else printf("%d %s\n",p_16->data.key,p_16->data.others);				
											break;		
										case 17:
												T = InvertTree(T);
												if(T != NULL) printf("OK!");				
												else printf("翻转失败！");
											break; 
										case 18:
												printf("输入文件名：");
												 scanf("%s",ch);
												 result=SaveBiTree(T,ch);
												if (result==OK) printf("OK\n");
												else printf("二叉树不存在！\n");				 
											break;
										case 19:
												printf("输入文件名：");
												 scanf("%s",ch);
												 result=LoadBiTree(T,ch);
												if (result==OK) printf("OK\n");
												else printf("二叉树不存在！\n");						
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
				system("cls");	printf("\n\n");
				printf("      单二叉树管理！     \n");
				printf("-------------------------------------------------\n");
				printf("    	  1. CreateBiTree       7. Assign\n");
				printf("    	  2. DestroyBiTree   8. GetSibling\n");
				printf("    	  3. ClearBiTree       9. InsertNode \n");
				printf("    	  4. BiTreeEmpty     10. DeleteNode\n");
				printf("    	  5. BiTreeDepth     11. PreOrderTraverse\n");
				printf("    	  6. LocateNode       12. InOrderTraverse\n");
				printf("    	  13. PostOrderTraverse     14. LevelOrderTraverse\n");
				printf("    	  15. MaxPathSum      16. LowestCommonAncestor\n");
				printf("    	  17. InvertTree      18. SaveBiTree\n");
				printf("    	  19. LoadBiTree     20.返回选择页面\n");	
				printf("    	  0. Exit\n");
				printf("-------------------------------------------------\n");
				printf("    请选择你的操作[0~18]:");
				scanf("%d",&op);
			    switch(op){
				   case 1:
							if(T!=NULL){
				   				printf("二叉树已存在！");
								break;    
							}
							printf("请输入定义序列:\n");
							i_1=0;
							do {
								scanf("%d%s",&definition[i_1].key,definition[i_1].others);
							} while (definition[i_1++].key!=-1);
							lflag=len=0;
							flag.clear();
							result=CreateBiTree(T,definition);
							if (result==OK) printf("OK\n");
							if (result==ERROR) printf("关键字重复！\n");               
					 break;
				   case 2:
							result=DestroyBiTree(T);
							if (result==OK) printf("OK\n");		
							else printf("二叉树不存在！\n");	
					 break;
				   case 3:
							result=ClearBiTree(T);
							if (result==OK) printf("OK\n");			
							else printf("二叉树不存在！\n");							   				
					 break;
				   case 4:
							result=BiTreeEmpty(T);
							if (result==TRUE) printf("二叉树为空！\n");
							if(result==FALSE) printf("二叉树不为空！\n");
							if (result==INFEASIBLE) printf("二叉树不存在！\n");		   			
					 break;
				   case 5:
							result= BiTreeDepth(T);
							ldeep = 1;ldeepmax = 0; 
							if (result==INFEASIBLE) printf("二叉树不存在！\n");	
							else printf("二叉树深度为%d\n",result);
					 break;
				   case 6:
				   			printf("输入你要查找的元素关键字：");
				   			scanf("%d",&tp);
							p_7=LocateNode(T,tp);		 
							if (p_7==NULL) printf("查找失败！\n");
							else printf("%d,%s",p_7->data.key,p_7->data.others);				
					 break;
				   case 7:
				   			printf("输入关键字与修改为的值：");
				   			scanf("%d%d%s",&tp,&c.key,c.others);
							result=Assign(T,tp,c);	 
							if(result == OK) printf("OK");
							else printf("修改失败！\n");		
					 break;										 
				   case 8:
				   			printf("输入你要查找的关键字的兄弟：");
				   			scanf("%d",&e);
							p_8=GetSibling(T,e);		 
							if (p_8==NULL) printf("没有兄弟！\n");
							else printf("%d,%s",p_8->data.key,p_8->data.others);
					 break;
				   case 9:
							printf("输入4个元素，分别表示插入位置，左右（0或1，-1表示作为根节点），插入关键字和数据：");
				   			scanf("%d%d%d%s",&e,&LR,&c.key,c.others);
							result=InsertNode(T,e,LR,c);	 
							if (result==OK) printf("OK！\n");
							else printf("插入失败！\n");
					 break;
				   case 10:
				   			printf("输入你要删除的元素关键字：");
				   			scanf("%d",&tp);
							result=DeleteNode(T,tp);		 
							if(result == OK) printf("OK!");
							else printf("删除失败！"); 
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
							if (result==-1) printf("二叉树不存在！\n");
							else printf("最大路径为%d!\n",result);				
						break;	
					case 16:
							int e1,e2;
							printf("请输入两个关键字！：\n");
							scanf("%d%d",&e1,&e2);
							p_16=LowestCommonAncestor(T,e1,e2);
							if (p_16==NULL) printf("查找失败！\n");
							else printf("%d %s\n",p_16->data.key,p_16->data.others);				
						break;		
					case 17:
							T = InvertTree(T);
							if(T != NULL) printf("OK!");				
							else printf("翻转失败！");
						break;
					case 18:
							printf("输入文件名：");
							 scanf("%s",ch);
							 result=SaveBiTree(T,ch);
							if (result==OK) printf("OK\n");
							else printf("二叉树不存在！\n");				 
						break;
					case 19:
							printf("输入文件名：");
							 scanf("%s",ch);
							 result=LoadBiTree(T,ch);
							if (result==OK) printf("OK\n");
							else printf("二叉树不存在！\n");						
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
printf("欢迎下次再使用本系统！\n");
return 0;
}//end of main()
/*--------page 23 on textbook --------------------*/
status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
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
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
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
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    if(T->data.key==0) return TRUE;
    else return FALSE; 

    /********** End **********/
}

int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
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
//查找结点
{
    // 请在这里补充代码，完成本关任务
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
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
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
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL) {
        return NULL;
    }

    // 检查左孩子是否是目标节点
    if (T->lchild != NULL && T->lchild->data.key == e) {
        return T->rchild;
    }

    // 检查右孩子是否是目标节点
    if (T->rchild != NULL && T->rchild->data.key == e) {
        return T->lchild;
    }

    // 递归在左子树中查找
    BiTNode* leftResult = GetSibling(T->lchild, e);
    if (leftResult != NULL) {
        return leftResult;
    }

    // 递归在右子树中查找
    return GetSibling(T->rchild, e);

    /********** End **********/
}

bool check_Insert(BiTree T,int k){
    if(T==NULL) return true;
    if(T->data.key==k) return false;
    return check_Insert(T->lchild,k)&&check_Insert(T->rchild,k);
}
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
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
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
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
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    printf(" %d,%s",T->data.key,T->data.others);
    if(T->lchild!=NULL) PreOrderTraverse(T->lchild,visit);
    if(T->rchild!=NULL) PreOrderTraverse(T->rchild,visit);
    /********** End **********/
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T->lchild!=NULL) InOrderTraverse(T->lchild,visit);
    printf(" %d,%s",T->data.key,T->data.others);
    if(T->rchild!=NULL) InOrderTraverse(T->rchild,visit);

    /********** End **********/
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T->lchild!=NULL) PostOrderTraverse(T->lchild,visit); 
    if(T->rchild!=NULL) PostOrderTraverse(T->rchild,visit);
    printf(" %d,%s",T->data.key,T->data.others);
    /********** End **********/
}
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
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
        return NULL; // 空树直接返回
    }
    
    // 交换当前节点的左右子树
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    
    // 递归翻转新的左右子树（原右、左子树）
    InvertTree(T->lchild);
    InvertTree(T->rchild);
    
    return T; // 返回翻转后的根节点
}

status SaveBiTree(BiTree T, const char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
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
//读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
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
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/  
    Lists.elem[Lists.length].T=(BiTree)malloc(sizeof(BiTNode));
    Lists.elem[Lists.length].T=NULL;
    strcpy(Lists.elem[Lists.length].name,ListName);
    Lists.length++;
    return OK;
    /********** End **********/
}
status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
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
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for(int i=0;i<Lists.length;i++){
        if(strcmp(Lists.elem[i].name,ListName)==0) return i+1;
    }
    return ERROR;
    /********** End **********/
}
