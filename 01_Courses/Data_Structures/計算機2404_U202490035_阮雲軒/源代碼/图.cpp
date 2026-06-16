/* Linear Table On Sequence Structure */
#include<bits/stdc++.h>
/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1 
#define MAX_VERTEX_NUM 20

typedef int status; 
typedef int ElemType; //資料元素類型定義

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct {
     KeyType  key;
     char others[20];
} VertexType; //頂點類型定義

typedef struct ArcNode {         //表結點類型定義
     int adjvex;              //頂點位置編號 
     struct ArcNode  *nextarc;     //下一個表結點指標
} ArcNode;
typedef struct VNode{               //頭結點及其陣列類型定義
     VertexType data;           //頂點信息
     ArcNode *firstarc;          //指向第一條弧
    } VNode,AdjList[MAX_VERTEX_NUM];
typedef  struct {  //鄰接表的類型定義
    AdjList vertices;        //頭結點陣列
    int vexnum,arcnum;        //頂點數、弧數
    GraphKind  kind;        //圖的類型
   } ALGraph;
typedef struct{  //線性表的集合類型定義
     struct { char name[30];
               ALGraph G;
     } elem[10];
     int length;
}LISTS;
LISTS Lists;      //線性表集合的定義Lists

/*-----page 19 on textbook ---------*/
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);
status DestroyGraph(ALGraph &G);
status LocateVex(ALGraph G,KeyType u);
status PutVex(ALGraph &G,KeyType u,VertexType value);
int FirstAdjVex(ALGraph G,KeyType u);
int NextAdjVex(ALGraph G,KeyType v,KeyType w);
status InsertVex(ALGraph &G,VertexType v);
status DeleteVex(ALGraph &G,KeyType v);
status InsertArc(ALGraph &G,KeyType v,KeyType w);
status DeleteArc(ALGraph &G,KeyType v,KeyType w);
status DFSTraverse(ALGraph &G,void (*visit)(VertexType)); 
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));
int VerticesSetLessThanK(ALGraph &G,int v,int k);
int ShortestPathLength(ALGraph &G,int v,int k);
int ConnectedComponentsNums(ALGraph &G);
status SaveGraph(ALGraph G, char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]);

status AddList(LISTS &Lists,char ListName[]);
status RemoveList(LISTS &Lists,char ListName[]);
int LocateList(LISTS Lists,char ListName[]);
void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}
int op=1,result,tp,e,k,op1=1,t,len,i_1;
std::map<int,int> flagdfs,flagbfs,flagsave;
std::queue<int> q;
VertexType V[30],c;
KeyType VR[100][2];
char ch[1000];
char name[30];
ALGraph G,Gtemp;
//簡化過
/*--------------------------------------------*/
int main(){

while(op1){
    system("cls");  printf("\n\n");
    printf("-------------------------------------------------\n");
    printf("1.進入多圖管理        2.進入單圖管理\n");
    printf("0. Exit\n");
    printf("-------------------------------------------------\n");
    scanf("%d",&op1);   
    switch(op1){
        case 1:
            op=1;
            while(op!=0 and op!=4){
                t=0;
                system("cls");  printf("\n\n");
                printf("      多圖管理！     \n");           
                printf("-------------------------------------------------\n");
                printf("          1. AddGraph       3. LocateGraph\n");
                printf("          2. DestroyGraph   4. 返回選擇頁面\n");      
                printf("          0.Exit\n");   
                printf("-------------------------------------------------\n");
                printf("    請選擇你的操作[0~4]:");        
                scanf("%d",&op);
                switch(op){
                    case 1:
                        printf("添加一個圖，請輸入圖名稱：");
                        
                        scanf("%s",name);
                        result=AddList(Lists,name);                 
                        if(result==OK) printf("OK!\n");
                        break;
                    case 2:
                        printf("刪除一個圖，請輸入圖名稱：");
                        scanf("%s",name);
                        result=RemoveList(Lists,name);                  
                        if(result==OK) printf("OK!\n");
                        else printf("圖不存在！\n");             
                        break;
                    case 3:
                        printf("查找一個圖，請輸入圖名稱：");
                        scanf("%s",name);
                        result=LocateList(Lists,name);                  
                        if(result==ERROR) printf("圖不存在！\n");
                        else{
                            int t;
                            printf("OK!  按1對其進行單圖操作,按其他按鍵返回");
                            scanf("%d",&t);
                            if(t==1){
                                G=Lists.elem[result-1].G;
                                while(op!=0 and op!=18){
                                    int t=0;
                                    system("cls");  printf("\n\n");
                                    printf("      單圖管理！     \n");
                                    printf("-------------------------------------------------\n");
                                    printf("          1. CreateCraph       7. InsertVex\n");
                                    printf("          2. DestroyGraph   8. DeleteVex \n");
                                    printf("          3. LocateVex       9. InsertArc \n");
                                    printf("          4. PutVex     10. DeleteArc\n");
                                    printf("          5. FirstAdjVex     11. DFSTraverse\n");
                                    printf("          6. NextAdjVex       12. BFSTraverse\n");
                                    printf("          13. VerticesSetLessThanK     14. ShortestPathLength\n");
                                    printf("          15. ConnectedComponentsNums      16. SaveGraph\n");
                                    printf("          17. LoadGraph     18.返回多線性表操作\n");    
                                    printf("          0. Exit\n");
                                    printf("-------------------------------------------------\n");
                                    printf("    請選擇你的操作[0~18]:");
                                    scanf("%d",&op);
                                    switch(op){
                                        case 1:
                                                if(G.vexnum!=0){
                                                    printf("圖已存在！");
                                                    break;    
                                                }
                                                printf("請輸入定義序列:\n");                                               
                                                i_1=0;
                                                do {
                                                    scanf("%d%s",&V[i_1].key,V[i_1].others);
                                                } while(V[i_1++].key!=-1);
                                                i_1=0;
                                                do {
                                                    scanf("%d%d",&VR[i_1][0],&VR[i_1][1]);
                                                   } while(VR[i_1++][0]!=-1);
                                                result=CreateCraph(G,V,VR);
                                                if (result==OK) printf("OK\n");
                                                if (result==ERROR) printf("輸入錯誤！\n");               
                                         break;
                                        case 2:
                                                result=DestroyGraph(G);
                                                if (result==OK) printf("OK\n");     
                                                else printf("圖不存在！\n"); 
                                         break;
                                        case 3:
                                                printf("輸入查找的關鍵字：");
                                                scanf("%d",&tp); 
                                                result=LocateVex(G,tp);
                                                if (result!=-1) printf("%d %s\n",G.vertices[result].data.key,G.vertices[result].data.others);           
                                                else printf("ERROR！\n");                                            
                                         break;
                                        case 4:
                                                printf("輸入關鍵字與修改為的值：");
                                                scanf("%d%d%s",&tp,&c.key,c.others);                                                
                                                result=PutVex(G,tp,c);
                                                if (result==OK) printf("OK！\n");
                                                else printf("ERROR！\n");            
                                         break;
                                       case 5:
                                                printf("輸入要查找的關鍵字：");
                                                scanf("%d",&tp);
                                                result= FirstAdjVex(G,tp);
                                                if (result==-1) printf("ERROR！\n"); 
                                                else printf("%d %s\n",G.vertices[result].data.key,G.vertices[result].data.others);
                                         break;
                                       case 6:
                                                printf("輸入v和w：");
                                                scanf("%d%d",&tp,&e);
                                                result= NextAdjVex(G,tp,e);
                                                if (result==-1) printf("ERROR！\n"); 
                                                else printf("%d %s\n",G.vertices[result].data.key,G.vertices[result].data.others);          
                                         break;
                                       case 7:
                                                printf("輸入插入的點：");
                                                scanf("%d%s",&c.key,c.others);  
                                                result=InsertVex(G,c);   
                                                if(result == OK) printf("OK!\n");
                                                else printf("ERROR！\n");        
                                         break;                                      
                                       case 8:
                                                printf("輸入你要刪除的關鍵字：");
                                                scanf("%d",&e);
                                                result=DeleteVex(G,e);       
                                                if (result==OK) printf("OK！\n");
                                                else printf("ERROR!\n");
                                         break;
                                       case 9:                          
                                                printf("輸入插入的弧<v,w>");
                                                scanf("%d%d",&e,&tp);
                                                result=InsertArc(G,e,tp);    
                                                if (result==OK) printf("OK！\n");
                                                else printf("插入失敗！\n");
                                         break;
                                       case 10:                                             
                                                printf("輸入插入的弧<v,w>");
                                                scanf("%d%d",&e,&tp);
                                                result=DeleteArc(G,e,tp);    
                                                if (result==OK) printf("OK！\n");
                                                else printf("插入失敗！\n");
                                         break;
                                       case 11:
                                            flagdfs.clear();
                                            DFSTraverse(G,visit);
                                         break;
                                       case 12:
                                            flagbfs.clear();
                                            while (!q.empty()) {
                                                q.pop(); 
                                            }
                                            BFSTraverse(G,visit);
                                         break;
                                       case 13:
                                            flagbfs.clear();
                                            while (!q.empty()) {
                                                q.pop(); 
                                            }
                                            printf("輸入v與k：");
                                            scanf("%d%d",&tp,&e);
                                            result=VerticesSetLessThanK(G,tp,e);
                                            if (result==ERROR) printf("頂點不存在！\n");                                          
                                         break;                                                                                  
                                        case 14:
                                            
                                            flagbfs.clear();
                                                while (!q.empty()) {
                                                    q.pop(); 
                                                }
                                            printf("輸入v與w：");
                                            scanf("%d%d",&tp,&e);
                                            result=ShortestPathLength(G,tp,e);
                                            if (result==-1) printf("不存在！\n");
                                            else printf("距離為%d！\n",result); 
                                            break;      
                                        case 15:
                                                flagbfs.clear();
                                                while (!q.empty()) {
                                                    q.pop(); 
                                                }                                       
                                                result=ConnectedComponentsNums(G);
                                                if (result==-1) printf("圖不存在！\n");
                                                else printf("連通分量有%d個!\n",result);              
                                            break;  
                                        case 16:
                                                flagsave.clear();
                                                printf("輸入檔案名：");
                                                 scanf("%s",ch);
                                                 result=SaveGraph(G,ch);
                                                if (result==OK) printf("OK\n");
                                                else printf("ERROR！\n");                 
                                            break;
                                        case 17:
                                                printf("輸入檔案名：");
                                                 scanf("%s",ch);
                                                 result=LoadGraph(G,ch);
                                                if (result==OK) printf("OK\n");
                                                else printf("ERROR！\n");                        
                                            break;
                                        case 18:
                                            break;
                                        case 0:
                                            t=1;
                                            break;
                                        Lists.elem[result-1].G=G;   
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
            G=Gtemp;
            while(op!=0 and op!=18){
                int t=0;
                system("cls");  printf("\n\n");
                printf("      單圖管理！     \n");
                printf("-------------------------------------------------\n");
                printf("          1. CreateCraph       7. InsertVex\n");
                printf("          2. DestroyGraph   8. DeleteVex \n");
                printf("          3. LocateVex       9. InsertArc \n");
                printf("          4. PutVex     10. DeleteArc\n");
                printf("          5. FirstAdjVex     11. DFSTraverse\n");
                printf("          6. NextAdjVex       12. BFSTraverse\n");
                printf("          13. VerticesSetLessThanK     14. ShortestPathLength\n");
                printf("          15. ConnectedComponentsNums      16. SaveGraph\n");
                printf("          17. LoadGraph     18.返回多線性表操作\n");    
                printf("          0. Exit\n");
                printf("-------------------------------------------------\n");
                printf("    請選擇你的操作[0~18]:");
                scanf("%d",&op);
                switch(op){
                    case 1:
                            if(G.vexnum!=0){
                                printf("圖已存在！");
                                break;    
                            }
                            printf("請輸入定義序列:\n");                                               
                            i_1=0;
                            do {
                                scanf("%d%s",&V[i_1].key,V[i_1].others);
                            } while(V[i_1++].key!=-1);
                            i_1=0;
                            do {
                                scanf("%d%d",&VR[i_1][0],&VR[i_1][1]);
                               } while(VR[i_1++][0]!=-1);
                            result=CreateCraph(G,V,VR);
                            if (result==OK) printf("OK\n");
                            if (result==ERROR) printf("輸入錯誤！\n");               
                     break;
                    case 2:
                            result=DestroyGraph(G);
                            if (result==OK) printf("OK\n");     
                            else printf("圖不存在！\n"); 
                     break;
                    case 3:
                            printf("輸入查找的關鍵字：");
                            scanf("%d",&tp); 
                            result=LocateVex(G,tp);
                            if (result!=-1) printf("%d %s\n",G.vertices[result].data.key,G.vertices[result].data.others);           
                            else printf("ERROR！\n");        
                     break;
                    case 4:
                            printf("輸入關鍵字與修改為的值：");
                            scanf("%d%d%s",&tp,&c.key,c.others);                                                
                            result=PutVex(G,tp,c);
                            if (result==OK) printf("OK！\n");
                            else printf("ERROR！\n");            
                     break;
                   case 5:
                            printf("輸入要查找的關鍵字：");
                            scanf("%d",&tp);
                            result= FirstAdjVex(G,tp);
                            if (result==-1) printf("ERROR！\n"); 
                            else printf("%d %s\n",G.vertices[result].data.key,G.vertices[result].data.others);
                     break;
                   case 6:
                            printf("輸入v和w：");
                            scanf("%d%d",&tp,&e);
                            result= NextAdjVex(G,tp,e);
                            if (result==-1) printf("ERROR！\n"); 
                            else printf("%d %s\n",G.vertices[result].data.key,G.vertices[result].data.others);          
                     break;
                   case 7:
                            printf("輸入插入的點：");
                            scanf("%d%s",&c.key,c.others);  
                            result=InsertVex(G,c);   
                            if(result == OK) printf("OK!\n");
                            else printf("ERROR！\n");        
                     break;                                      
                   case 8:
                            printf("輸入你要刪除的關鍵字：");
                            scanf("%d",&e);
                            result=DeleteVex(G,e);       
                            if (result==OK) printf("OK！\n");
                            else printf("ERROR!\n");
                     break;
                   case 9:                          
                            printf("輸入插入的弧<v,w>");
                            scanf("%d%d",&e,&tp);
                            result=InsertArc(G,e,tp);    
                            if (result==OK) printf("OK！\n");
                            else printf("插入失敗！\n");
                     break;
                   case 10:                                             
                            printf("輸入插入的弧<v,w>");
                            scanf("%d%d",&e,&tp);
                            result=DeleteArc(G,e,tp);    
                            if (result==OK) printf("OK！\n");
                            else printf("插入失敗！\n");
                     break;
                   case 11:
                        flagdfs.clear();
                        DFSTraverse(G,visit);
                     break;
                   case 12:
                        flagbfs.clear();
                        while (!q.empty()) {
                            q.pop(); 
                        }
                        BFSTraverse(G,visit);
                     break;
                   case 13:
                        flagbfs.clear();
                        while (!q.empty()) {
                            q.pop(); 
                        }
                        printf("輸入v與k：");
                        scanf("%d%d",&tp,&e);
                        result=VerticesSetLessThanK(G,tp,e);
                        if (result==ERROR) printf("頂點不存在！\n");                                          
                     break;                                                                                  
                    case 14:
                        
                        flagbfs.clear();
                        while (!q.empty()) {
                            q.pop(); 
                        }
                        printf("輸入v與w：");
                        scanf("%d%d",&tp,&e);
                        result=ShortestPathLength(G,tp,e);
                        if (result==-1) printf("不存在！\n");
                        else printf("距離為%d！\n",result); 
                        break;      
                    case 15:
                            flagbfs.clear();
                            while (!q.empty()) {
                                q.pop(); 
                            }                                           
                            result=ConnectedComponentsNums(G);
                            if (result==-1) printf("圖不存在！\n");
                            else printf("連通分量有%d個!\n",result);              
                        break;  
                    case 16:
                            flagsave.clear();
                            printf("輸入檔案名：");
                             scanf("%s",ch);
                             result=SaveGraph(G,ch);
                            if (result==OK) printf("OK\n");
                            else printf("ERROR！\n");                 
                        break;
                    case 17:
                            printf("輸入檔案名：");
                             scanf("%s",ch);
                             result=LoadGraph(G,ch);
                            if (result==OK) printf("OK\n");
                            else printf("ERROR！\n");                        
                        break;
                    case 18:
                        Gtemp = G;
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
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根據V和VR構造圖T並返回OK，如果V和VR不正確，返回ERROR
如果有相同的關鍵字，返回ERROR。此題允許通過增加其它函數輔助實現本關任務*/
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    G.vexnum = 0;
    while (G.vexnum <= MAX_VERTEX_NUM && V[G.vexnum].key != -1) { // 假設以-1結束
        G.vexnum++;
    }
    if (G.vexnum > MAX_VERTEX_NUM or G.vexnum==0) return ERROR;

    // 檢查頂點關鍵字唯一性
    for (int i = 0; i < G.vexnum; ++i) {
        for (int j = i + 1; j < G.vexnum; ++j) {
            if (V[i].key == V[j].key)
                return ERROR;
        }
    }

    // 初始化圖的頂點
    for (int i = 0; i < G.vexnum; ++i) {
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;
    }

    // 計算邊數
    G.arcnum = 0;
    while (VR[G.arcnum][0] != -1 && VR[G.arcnum][1] != -1) { // 假設以-1結束
        G.arcnum++;
    }

    // 處理每條邊
    for (int k = 0; k < G.arcnum; ++k) {
        KeyType u = VR[k][0];
        KeyType v = VR[k][1];

        int i = LocateVex(G, u);
        int j = LocateVex(G, v);
        if (i == -1 || j == -1)
            return ERROR;

        // 將j添加到i的鄰接表中
        ArcNode *arc_i = (ArcNode *)malloc(sizeof(ArcNode));
        if (!arc_i) return OVERFLOW;
        arc_i->adjvex = j;
        arc_i->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = arc_i;

        // 將i添加到j的鄰接表中
        ArcNode *arc_j = (ArcNode *)malloc(sizeof(ArcNode));
        if (!arc_j) {
            free(arc_i);
            return OVERFLOW;
        }
        arc_j->adjvex = i;
        arc_j->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = arc_j;
    }

    G.kind = UDG;
    return OK;
    /********** End **********/
}

status DestroyGraph(ALGraph &G)
/*銷毀無向圖G,刪除G的全部頂點和邊*/
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(G.vexnum==0) return ERROR;
    for (int i = 0; i < G.vexnum; ++i) {
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL) {
            ArcNode *temp = p;      
            p = p->nextarc;        
            free(temp);            
        }
        G.vertices[i].firstarc = NULL; 
    }
    G.vexnum = 0;
    G.arcnum = 0;
    
    
    return OK; 

    /********** End **********/
}

int LocateVex(ALGraph G,KeyType u)
//根據u在圖G中查找頂點，查找成功返回位序，否則返回-1；
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; ++i) {
        if(G.vertices[i].data.key == u) return i;
    }
    return -1;

    /********** End **********/
}

int checkput(ALGraph G,int x,VertexType v){
    for (int i = 0; i < G.vexnum; ++i) {
        if(i == x) continue ;
        if(v.key == G.vertices[i].data.key) return 0;
    }
    return 1;    
}
status PutVex(ALGraph &G,KeyType u,VertexType value)
//根據u在圖G中查找頂點，查找成功將該頂點值修改成value，返回OK；
//如果查找失敗或關鍵字不唯一，返回ERROR
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; ++i) {
        if(G.vertices[i].data.key == u){
            if(checkput(G,i,value)== 1){
                G.vertices[i].data=value;
                return OK;
            }
            else return ERROR;
        }
    }
    return ERROR;

    /********** End **********/
}

int FirstAdjVex(ALGraph G,KeyType u)
//根據u在圖G中查找頂點，查找成功返回頂點u的第一鄰接頂點位序，否則返回-1；
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    int t = LocateVex(G,u);
    if(G.vertices[t].firstarc!=NULL) return G.vertices[t].firstarc->adjvex;
    return -1;
    /********** End **********/
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v對應G的一個頂點,w對應v的鄰接頂點；操作結果是返回v的（相對於w）下一個鄰接頂點的位序；如果w是最後一個鄰接頂點，或v、w對應頂點不存在，則返回-1。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    int t = LocateVex(G,v);
    int wt = LocateVex(G,w);
    if (t==-1 or wt == -1) return -1;
    ArcNode *p = G.vertices[t].firstarc;
    while(p!=NULL){
        if(p->adjvex==wt){
            if(p->nextarc!=NULL) return p->nextarc->adjvex;
            else return -1;
        }
        p=p->nextarc;
    }    
    return -1;

    /********** End **********/
}

status InsertVex(ALGraph &G,VertexType v)
//在圖G中插入頂點v，成功返回OK,否則返回ERROR
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(G.vexnum == MAX_VERTEX_NUM) return ERROR;
    for(int i=0;i<G.vexnum;i++){
        if(G.vertices[i].data.key==v.key) return ERROR;
    }
    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc=NULL;
    G.vexnum++;
    return OK;
    /********** End **********/
}

status DeleteVex(ALGraph &G,KeyType v)
//在圖G中刪除關鍵字v對應的頂點以及相關的弧，成功返回OK,否則返回ERROR
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    if(G.vexnum == 1) return ERROR;
    int pos_v = LocateVex(G, v);
    if (pos_v == -1) return ERROR;

    ArcNode *current = G.vertices[pos_v].firstarc;
    while (current != NULL) {
        int w_pos = current->adjvex;
        
        ArcNode *w_prev = NULL;
        ArcNode *w_p = G.vertices[w_pos].firstarc;
        while (w_p != NULL) {
            if (w_p->adjvex == pos_v) {
                if (w_prev == NULL) {
                    G.vertices[w_pos].firstarc = w_p->nextarc;
                } else {
                    w_prev->nextarc = w_p->nextarc;
                }
                ArcNode *temp = w_p;
                w_p = w_p->nextarc;
                free(temp);
                G.arcnum--; 
                break;
            } else {
                w_prev = w_p;
                w_p = w_p->nextarc;
            }
        }

        ArcNode *temp = current;
        current = current->nextarc;
        free(temp);
    }
    G.vertices[pos_v].firstarc = NULL;

    for (int i = pos_v; i < G.vexnum - 1; i++) {
        G.vertices[i] = G.vertices[i + 1];
    }
    G.vexnum--;
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL) {
            if (p->adjvex > pos_v) {
                p->adjvex--; 
            }
            p = p->nextarc;
        }
    }

    return OK;
    /********** End **********/
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在圖G中增加弧<v,w>，成功返回OK,否則返回ERROR
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    int vt = LocateVex(G,v),wt = LocateVex(G,w);
    if(vt == -1 or wt == -1) return ERROR;
    ArcNode *p = G.vertices[wt].firstarc;
    while(p!=NULL){
        if(p->adjvex == vt) return ERROR;
        p=p->nextarc;
    }
    ArcNode *temp1 = (ArcNode *)malloc(sizeof(ArcNode));
    temp1->nextarc = G.vertices[vt].firstarc;
    temp1->adjvex = wt;
    G.vertices[vt].firstarc = temp1;
    
    ArcNode *temp2 = (ArcNode *)malloc(sizeof(ArcNode));
    temp2->nextarc = G.vertices[wt].firstarc;
    temp2->adjvex = vt;
    G.vertices[wt].firstarc = temp2;    

    G.arcnum++;
    return OK;
    /********** End **********/
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在圖G中刪除弧<v,w>，成功返回OK,否則返回ERROR
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    int v_pos = LocateVex(G, v);
    int w_pos = LocateVex(G, w);
    if (v_pos == -1 || w_pos == -1) return ERROR;

    ArcNode *prev = NULL;
    ArcNode *curr = G.vertices[v_pos].firstarc;
    bool found = false;
    while (curr != NULL) {
        if (curr->adjvex == w_pos) {
            if (prev == NULL) {
                G.vertices[v_pos].firstarc = curr->nextarc;
            } else {
                prev->nextarc = curr->nextarc;
            }
            free(curr);
            found = true;
            break;
        }
        prev = curr;
        curr = curr->nextarc;
    }
    if (!found) return ERROR; 

    prev = NULL;
    curr = G.vertices[w_pos].firstarc;
    while (curr != NULL) {
        if (curr->adjvex == v_pos) {
            if (prev == NULL) {
                G.vertices[w_pos].firstarc = curr->nextarc;
            } else {
                prev->nextarc = curr->nextarc;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->nextarc;
    }

    G.arcnum--; 
    return OK;

    /********** End **********/
}

void dfs(ALGraph G,int t,void (*visit)(VertexType)){
    visit(G.vertices[t].data);
    flagdfs[t]=1;
    ArcNode *p = G.vertices[t].firstarc;
    while(p!=NULL){
        if(flagdfs[p->adjvex]==0) dfs(G,p->adjvex,visit);
        p=p->nextarc;
    }
}

status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//對圖G進行深度優先搜索遍歷，依次對圖中的每一個頂點使用函數visit訪問一次，且僅訪問一次
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    for(int i=0;i<G.vexnum;i++){
        if(flagdfs[i]==0){
            dfs(G,i,visit);
            printf("\n"); 
        }
    }

    /********** End **********/
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//對圖G進行廣度優先搜索遍歷，依次對圖中的每一個頂點使用函數visit訪問一次，且僅訪問一次
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/
    for(int i=0;i<G.vexnum;i++){
        if(flagbfs[i]==0){
            q.push(i);
            flagbfs[i]=1;
        }
        else continue;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            visit(G.vertices[u].data);
            ArcNode *p = G.vertices[u].firstarc;
            while(p!=NULL){
                if(flagbfs[p->adjvex]==0){
                    q.push(p->adjvex);
                    flagbfs[p->adjvex]=1;
                }
                p=p->nextarc;
            }
        }
        printf("\n");
    }

    /********** End **********/
}
int VerticesSetLessThanK(ALGraph &G,int v,int k){
    int u0= LocateVex(G,v),s[100]={-1};
    if(u0==-1) return ERROR;
    q.push(u0);
    s[u0]=0;
    flagbfs[u0]=1;
    printf("%d %s\n",G.vertices[u0].data.key,G.vertices[u0].data.others);   
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ArcNode *p = G.vertices[u].firstarc;
        while(p!=NULL){
            if(flagbfs[p->adjvex]==0){
                s[p->adjvex]=s[u]+1;
                if(s[p->adjvex]<k){
                    flagbfs[p->adjvex]=1;
                    q.push(p->adjvex);
                    printf("%d %s\n",G.vertices[p->adjvex].data.key,G.vertices[p->adjvex].data.others);                     
                }                               
            }
            p=p->nextarc;
        }
    }
    return OK;
}

int ShortestPathLength(ALGraph &G,int v,int k){
    int u0= LocateVex(G,v),s[100]={-1},v0=LocateVex(G,k);
    if(u0==-1 or v0==-1) return -1;
    q.push(u0);
    s[u0]=0;
    flagbfs[u0]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ArcNode *p = G.vertices[u].firstarc;
        while(p!=NULL){
            if(flagbfs[p->adjvex]==0){
                s[p->adjvex]=s[u]+1;
                if(p->adjvex==v0){
                    return s[p->adjvex];                
                }           
                flagbfs[p->adjvex]=1;
                q.push(p->adjvex);                  
            }
            p=p->nextarc;
        }
    }
    return ERROR;
}

int ConnectedComponentsNums(ALGraph &G){
    if(G.vexnum==0) return -1;
    int s=0; 
    for(int i=0;i<G.vexnum;i++){
        if(flagbfs[i]==0){
            q.push(i);
            flagbfs[i]=1;
        }
        else continue;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ArcNode *p = G.vertices[u].firstarc;
            while(p!=NULL){
                if(flagbfs[p->adjvex]==0){
                    q.push(p->adjvex);
                    flagbfs[p->adjvex]=1;
                }
                p=p->nextarc;
            }
        }
        s++;
    }
    return s;
}

status SaveGraph(ALGraph G, char FileName[])
//將圖的資料寫入到檔FileName中
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin 1 *********/
    FILE *fp = fopen(FileName, "w");
    for(int i=0;i<G.vexnum;i++){
        fprintf(fp,"%d %s ", G.vertices[i].data.key , G.vertices[i].data.others); 
    }
    fprintf(fp,"%d %s ", -1 , "nil"); 
    for(int i=0;i<G.vexnum;i++){
        flagsave[i]=1;
        ArcNode *p = G.vertices[i].firstarc;
        while(p!=NULL){
            if(flagsave[p->adjvex] == 0){
                fprintf(fp,"%d %d ", G.vertices[i].data.key , G.vertices[p->adjvex].data.key);                     
            }
            p=p->nextarc; 
        }
    }    
    fprintf(fp,"%d %d ", -1 , -1);
    fclose(fp);
    return OK;

    /********** End 1 **********/
}

status LoadGraph(ALGraph &G, char FileName[])
//讀入檔FileName的圖資料，創建圖的鄰接表
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName, "r");
    VertexType V[21];
    KeyType VR[100][2];
    int i=0;
    do {
        fscanf(fp,"%d%s",&V[i].key,V[i].others);
    } while(V[i++].key!=-1);
    i=0;
    do {
        fscanf(fp,"%d%d",&VR[i][0],&VR[i][1]);
        if(VR[i][0]>VR[i][1]) std::swap(VR[i][0],VR[i][1]);
    } while(VR[i++][0]!=-1);
    i--;
    for(int j=0;j<i-1;j++){
        for(int r=0;r<i-1-j;r++)
        if(VR[r][0] > VR[r+1][0] || (VR[r][0] == VR[r+1][0] && VR[r][1] > VR[r+1][1])){
            std::swap(VR[r],VR[r+1]);
        }
    }
    if(CreateCraph(G,V,VR)==OK) {
        fclose(fp);
        return OK;        
    }
    else{
        fclose(fp);
        return ERROR;               
    }
    /********** End 2 **********/
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一個名稱為ListName的空線性表，線性表資料又後臺測試程式插入。
{
    // 請在這裡補充代碼，完成本關任務
    /********** Begin *********/  
    Lists.elem[Lists.length].G = ALGraph(); // C++ 方式初始化
    ALGraph &graph = Lists.elem[Lists.length].G;
    graph.vexnum = 0;
    graph.arcnum = 0;
    graph.kind = UDG;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        graph.vertices[i].firstarc = NULL;
    }
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



