#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unordered_map> 
#include <queue> 
#include <vector> 

using namespace std; 
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define INFEASIBLE -1 
#define OVERFLOW -2 
#define MAX_VERTEX_NUM 20 
#define MAX_GRAPH_SIZE 10 
typedef int status; 
typedef int KeyType; 
typedef enum 
{ 
DG, 
DN, 
UDG, 
UDN 
} GraphKind; // 本程式以無向圖為例 
typedef struct 
{ 
KeyType key; 
char others[20]; 
} VertexType; // 頂點類型定義 
typedef struct ArcNode 
{ 
// 鄰接表結點類型定義 
int adjvex; 
// 頂點位置編號 
struct ArcNode *nextarc; // 下一個結點指標 
} ArcNode; 
typedef struct VNode 
{ 
// 頭結點及其陣列類型定義 
VertexType data; 
// 頂點信息 
ArcNode *firstarc; // 指向第一條弧 
} VNode, AdjList[MAX_VERTEX_NUM]; 
typedef struct 
{ 
// 鄰接表的類型定義 
AdjList vertices; 
// 頭結點陣列 
int vexnum, arcnum; // 頂點數、弧數 
GraphKind kind; 
// 圖的類型 
char name[30]; 
// 圖的名稱 
} ALGraph; 
typedef struct 
{ 
ALGraph elem[MAX_GRAPH_SIZE]; 
int length; 
int cur_index; 
} GRAPHS; 
/*----------------------------------------------*/ 
// basic operations 
status isKeyTypeUnique(VertexType V[]); 
status isKeyTypeUniqueInAdjlist(AdjList list, int len); 
status visit(VertexType v); 
void dfs(ALGraph G, int n, int visited[]); 
// ALGraph system operations 
status CreateGraph(ALGraph &G, VertexType V[], KeyType VR[][2]); 
status DestroyGraph(ALGraph &G); 
int LocateVertex(ALGraph G, KeyType u); 
status PutVex(ALGraph &G, KeyType u, VertexType value); 
int FirstAdjVex(ALGraph G, KeyType u); 
int NextAdjVex(ALGraph G, KeyType v, KeyType w); 
status InsertVex(ALGraph &G, VertexType v); 
status DeleteVex(ALGraph &G, KeyType v); 
status InsertArc(ALGraph &G, KeyType v, KeyType w); 
status DeleteArc(ALGraph &G, KeyType v, KeyType w); 
status DFSTraverse(ALGraph &G); 
status BFSTraverse(ALGraph &G); 
// Additional operations 
status SaveGraph(ALGraph G, const char FileName[]); 
status LoadGraph(ALGraph &G, const char FileName[]); 
int ShortestPathLength(ALGraph G, KeyType v, KeyType k); 
void VerticesWithinDistanceK(ALGraph G, KeyType v, KeyType K); 
int ConnectedComponentsNum(ALGraph G); 
// multiple graphs operation 
int LocateGraph(GRAPHS Graphs, char *Graphname); 
status AddGraph(GRAPHS &Graphs, char *Graphname); 
status RemoveGraph(GRAPHS &Graphs, char *Graphname); 
status SwitchGraph(GRAPHS &Graphs, char *Graphname); 
void PrintGraphslist(GRAPHS Graphs); 
void PrintMenu(GRAPHS Graphs); 
void PrintGraphWithAdjList(ALGraph G); 
/*----------------------------------------------*/ 
status isKeyTypeUnique(VertexType V[]) 
{ 
unordered_map<int, int> keyCnt; 
unordered_map<string, int> othersCnt; 
int i = 0; 
while (V[i].key != -1) 
{ 
keyCnt[V[i].key]++; 
othersCnt[V[i].others]++; 
if (keyCnt[V[i].key] > 1 || othersCnt[V[i].others] > 1) 
return ERROR; 
i++; 
} 
return OK; 
} 
status CreateGraph(ALGraph &G, VertexType V[], KeyType VR[][2]) 
{ 
// G.kind = UDG; 
// 算出頂點數和邊數 
G.vexnum = 0; 
G.arcnum = 0; 
int i = 0, j = 0; 
while (V[i].key != -1) 
{ 
i++; 
} 
while (VR[j][0] != -1) 
{ 
j++; 
} 
G.vexnum = i; 
G.arcnum = j; 
// 判斷頂點數和邊數是否超過最大值 
if (G.arcnum > MAX_VERTEX_NUM * (MAX_VERTEX_NUM - 1) / 2) 
return ERROR; 
if (G.vexnum > MAX_VERTEX_NUM) 
return ERROR; 
if (isKeyTypeUnique(V) == ERROR) 
return ERROR; 
// 創建圖 
for (int i = 0; i < G.vexnum; i++) 
{ 
G.vertices[i].data = V[i]; 
G.vertices[i].firstarc = NULL; 
} 
for (int i = 0; i < j; i++) 
{ 
int v1 = LocateVertex(G, VR[i][0]); 
int v2 = LocateVertex(G, VR[i][1]); 
// 判斷邊的兩個頂點是否在圖中 
if (v1 == -1 || v2 == -1) 
return ERROR; 
// 判斷邊的兩個頂點是否相同，如果相同則跳過 
if (v1 == v2) 
{ 
G.arcnum--; 
continue; 
} 
// 判斷邊的兩個頂點是否已經存在 
int flag = 1; 
if (G.vertices[v1].firstarc != NULL) 
{ 
ArcNode *p = G.vertices[v1].firstarc; 
while (p != NULL) 
{ 
if (p->adjvex == v2) 
flag = 0; 
p = p->nextarc; 
} 
} 
if (!flag) 
{ 
G.arcnum--; 
continue; 
} 
// 在 v1 的鄰接表中插入 v2 
ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode)); 
if (!p) 
return OVERFLOW; 
p->adjvex = v2; 
p->nextarc = G.vertices[v1].firstarc; 
G.vertices[v1].firstarc = p; 
// 在 v2 的鄰接表中插入 v1 
ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode)); 
if (!q) 
return OVERFLOW; 
q->adjvex = v1; 
q->nextarc = G.vertices[v2].firstarc; 
G.vertices[v2].firstarc = q; 
} 
return OK; 
} 
status DestroyGraph(ALGraph &G) 
/* 銷毀無向圖 G, 刪除 G 的全部頂點和邊 */ 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
for (int i = 0; i < G.vexnum; i++) 
{ 
ArcNode *p = G.vertices[i].firstarc; 
while (p) 
{ 
ArcNode *q = p; 
p = p->nextarc; 
free(q); 
} 
G.vertices[i].firstarc = NULL; 
} 
G.vexnum = 0; 
G.arcnum = 0; 
return OK; 
/********** End **********/ 
} 
int LocateVertex(ALGraph G, KeyType u) 
// 根據 u 在圖 G 中查找頂點，查找成功返回位序，否則返回-1； 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (G.vertices[i].data.key == u) 
return i; 
} 
return -1; 
/********** End **********/ 
} 
status isKeyTypeUniqueInAdjlist(AdjList list, int len) 
{ 
unordered_map<int, int> keyCnt; 
unordered_map<string, int> othersCnt; 
for (int i = 0; i < len; i++) 
{ 
keyCnt[list[i].data.key]++; 
othersCnt[list[i].data.others]++; 
if (keyCnt[list[i].data.key] > 1 || othersCnt[list[i].data.others] 
> 1) 
return ERROR; 
} 
return OK; 
} 
status PutVex(ALGraph &G, KeyType u, VertexType value) 
// 根據 u 在圖 G 中查找頂點，查找成功將該頂點值修改成 value，返回 OK； 
// 如果查找失敗或關鍵字不唯一，返回 ERROR 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (G.vertices[i].data.key == u) 
{ 
VertexType temp = G.vertices[i].data;  
G.vertices[i].data = value; 
if (isKeyTypeUniqueInAdjlist(G.vertices, G.vexnum)) 
{ 
return OK; 
} 
else 
{ 
G.vertices[i].data = temp; 
return ERROR; 
} 
} 
} 
return ERROR; 
/********** End **********/ 
} 
int FirstAdjVex(ALGraph G, KeyType u)  
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
int i = LocateVertex(G, u); 
if (i == -1) 
{ 
return -1; 
} 
ArcNode *p = G.vertices[i].firstarc; 
if (p) 
{ 
return p->adjvex; 
}  
else 
return -1; 
/********** End **********/ 
} 
int NextAdjVex(ALGraph G, KeyType v, KeyType w) 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
int n = LocateVertex(G, v); 
int m = LocateVertex(G, w); 
if (n == -1 || m == -1) 
{ 
printf(" 頂點不存在\n"); 
return -1; 
} 
ArcNode *p = G.vertices[n].firstarc; 
while (p && p->adjvex != m) 
{ 
p = p->nextarc; 
} 
if (p == NULL) 
{ 
printf(" 頂點 %d 不是頂點 %d 的鄰接頂點\n", w, v); 
return -1; 
}  
if (p && p->nextarc) 
{ 
return p->nextarc->adjvex; 
} 
else 
{ 
printf(" 頂點 %d 是頂點 %d 的最後一個鄰接頂點, 沒有下一個鄰接頂點\n", w, v); 
return -1; 
} 
/********** End **********/ 
} 
status InsertVex(ALGraph &G, VertexType v) 
// 在圖 G 中插入頂點 v，成功返回 OK, 否則返回 ERROR 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
if (G.vexnum == MAX_VERTEX_NUM) 
{ 
printf(" 圖的頂點數已達上限，無法插入新頂點\n"); 
return ERROR; 
} 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (G.vertices[i].data.key == v.key || 
strcmp(G.vertices[i].data.others, v.others) == 0) 
{ 
printf(" 圖中已存在該頂點，無法插入\n"); 
return ERROR; 
} 
} 
G.vertices[G.vexnum].data = v; 
G.vertices[G.vexnum].firstarc = NULL;  
G.vexnum++; 
return OK; 
/********** End **********/ 
} 
status DeleteVex(ALGraph &G, KeyType v) 
// 在圖 G 中刪除關鍵字 v 對應的頂點以及相關的弧，成功返回 OK, 否則返回 ERROR 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
int n = LocateVertex(G, v); 
if (n == -1) 
{ 
printf(" 圖中不存在該頂點，無法刪除\n"); 
return ERROR; 
} 
// 如果只有一個結點，不能刪除 
if (G.vexnum == 1) 
{ 
printf(" 圖中只有一個結點，無法刪除\n"); 
return ERROR; 
} 
// 1. 刪除所有指向該點的鄰接表結點 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (i == n) 
continue; 
ArcNode *pre = NULL; 
ArcNode *p = G.vertices[i].firstarc; 
while (p) 
{ 
if (p->adjvex == n)  
{ 
if (pre == NULL) 
{ 
G.vertices[i].firstarc = p->nextarc; 
} 
else 
{ 
pre->nextarc = p->nextarc; 
} 
ArcNode *tmp = p; 
p = p->nextarc; 
free(tmp); 
G.arcnum--; 
} 
else 
{ 
if (p->adjvex > n) 
p->adjvex--; 
pre = p; 
p = p->nextarc; 
} 
} 
} 
// 2. 刪除該點關聯的鄰接表結點 
ArcNode *p = G.vertices[n].firstarc; 
while (p) 
{ 
ArcNode *tmp = p; 
p = p->nextarc; 
free(tmp); 
}  
// 3. 調整頂點陣列 
for (int i = n; i < G.vexnum - 1; i++) 
{ 
G.vertices[i] = G.vertices[i + 1]; 
} 
G.vexnum--; 
// printf("%d %d",G.vexnum,G.arcnum); 
return OK; 
/********** End **********/ 
} 
status InsertArc(ALGraph &G, KeyType v, KeyType w) 
// 在圖 G 中增加弧 <v,w>，成功返回 OK, 否則返回 ERROR 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
int n = LocateVertex(G, v); 
int m = LocateVertex(G, w); 
if (n == -1 || m == -1) 
{ 
printf(" 圖中不存在該頂點，無法插入\n"); 
return ERROR; 
} 
ArcNode *temp = G.vertices[m].firstarc; 
while (temp) 
{ 
if (temp->adjvex == n) 
{ 
printf(" 圖中已存在該弧，無法插入\n"); 
return ERROR; 
} 
temp = temp->nextarc;  
} 
ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode)); 
p->adjvex = n; 
p->nextarc = G.vertices[m].firstarc; 
G.vertices[m].firstarc = p; 
ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode)); 
q->adjvex = m; 
q->nextarc = G.vertices[n].firstarc; 
G.vertices[n].firstarc = q; 
G.arcnum++; 
return OK; 
/********** End **********/ 
} 
status DeleteArc(ALGraph &G, KeyType v, KeyType w) 
// 在圖 G 中刪除弧 <v,w>，成功返回 OK, 否則返回 ERROR 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
int n = LocateVertex(G, v); 
int m = LocateVertex(G, w); 
if (n == -1 || m == -1) 
{ 
printf(" 圖中不存在該頂點，無法刪除\n"); 
return ERROR; 
} 
ArcNode *temp = G.vertices[m].firstarc; 
int flag = 0; 
while (temp) 
{  
if (temp->adjvex == n) 
flag = 1; 
temp = temp->nextarc; 
} 
if (!flag) 
{ 
printf(" 圖中不存在該弧，無法刪除\n"); 
return ERROR; 
} 
ArcNode *p = G.vertices[m].firstarc; 
temp = NULL; 
while (p && p->adjvex != n) 
{ 
temp = p; 
p = p->nextarc; 
} 
if (p == G.vertices[m].firstarc) 
{ 
G.vertices[m].firstarc = p->nextarc; 
} 
else 
{ 
temp->nextarc = p->nextarc; 
} 
free(p); 
ArcNode *q = G.vertices[n].firstarc; 
temp = NULL; 
while (q && q->adjvex != m) 
{ 
temp = q; 
q = q->nextarc; 
}  
if (q == G.vertices[n].firstarc) 
{ 
G.vertices[n].firstarc = q->nextarc; 
} 
else 
{ 
temp->nextarc = q->nextarc; 
} 
free(q); 
G.arcnum--; 
return OK; 
/********** End **********/ 
} 
void dfs(ALGraph G, int n, int visited[]) 
{ 
visited[n] = 1; 
visit(G.vertices[n].data); 
ArcNode *p = G.vertices[n].firstarc; 
while (p) 
{ 
if (!visited[p->adjvex]) 
{ 
dfs(G, p->adjvex, visited); 
} 
p = p->nextarc; 
} 
return; 
}  
status visit(VertexType v) 
{ 
// 訪問頂點的操作 
printf("%d %s\n", v.key, v.others); 
return OK; 
} 
status DFSTraverse(ALGraph &G) 
// 對圖 G 進行深度優先搜索遍歷，依次對圖中的每一個頂點使用函數 visit 訪問一次，且僅訪問一次 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
int visited[G.vexnum] = {0}; 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (!visited[i]) 
{ 
dfs(G, i, visited); 
} 
} 
return OK; 
/********** End **********/ 
} 
status BFSTraverse(ALGraph &G) 
// 對圖 G 進行廣度優先搜索遍歷，依次對圖中的每一個頂點使用函數 visit 訪問一 次，且僅訪問一次 
{ 
// 請在這裡補充代碼，完成本關任務 
/********** Begin *********/ 
bool visited[G.vexnum] = {FALSE};  
queue<int> q; 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (!visited[i]) 
{ 
visit(G.vertices[i].data); 
visited[i] = TRUE; 
q.push(i); 
} 
while (!q.empty()) 
{ 
int n = q.front(); 
q.pop(); 
ArcNode *p = G.vertices[n].firstarc; 
while (p) 
{ 
int m = p->adjvex; 
if (!visited[m]) 
{ 
visit(G.vertices[m].data); 
visited[m] = TRUE; 
q.push(m); 
} 
p = p->nextarc; 
} 
} 
} 
return OK; 
/********** End **********/ 
}  
status SaveGraph(ALGraph G, const char FileName[]) 
{ 
FILE *fp = fopen(FileName, "w"); 
if (!fp) 
return ERROR; 
fprintf(fp, "%d %d\n", G.vexnum, G.arcnum); // 寫入頂點數和邊數 
for (int i = 0; i < G.vexnum; ++i) 
{ 
// 寫入頂點 key 和 others 
fprintf(fp, "%d %s", G.vertices[i].data.key, 
G.vertices[i].data.others); 
// 寫入鄰接點索引 
ArcNode *p = G.vertices[i].firstarc; 
while (p != NULL) 
{ 
fprintf(fp, " %d", p->adjvex); // 寫入鄰接點在陣列中的索引 
p = p->nextarc; 
} 
fprintf(fp, " -1 "); // 結束鄰接點的輸入 
// 換行 
fprintf(fp, "\n"); 
} 
fclose(fp); 
return OK; 
} 
status LoadGraph(ALGraph &G, const char FileName[]) 
{ 
FILE *fp = fopen(FileName, "r"); 
if (!fp) 
return ERROR;  
// 讀取頂點數和邊數 
fscanf(fp, "%d %d", &G.vexnum, &G.arcnum); 
if (G.vexnum > MAX_VERTEX_NUM || G.arcnum > MAX_VERTEX_NUM * 
(MAX_VERTEX_NUM - 1) / 2) 
return ERROR; 
// 讀取頂點和它的鄰接點 
for (int i = 0; i < G.vexnum; ++i) 
{ 
fscanf(fp, "%d %s", &G.vertices[i].data.key, 
G.vertices[i].data.others); 
G.vertices[i].firstarc = NULL; 
int adjvex; 
while (fscanf(fp, "%d", &adjvex) == 1 && adjvex != -1) 
{ 
ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode)); 
if (!p) 
return OVERFLOW; 
p->adjvex = adjvex; 
// 尾插法構建鄰接表 
ArcNode *q = G.vertices[i].firstarc; 
if (q == NULL) 
{ 
G.vertices[i].firstarc = p; 
p->nextarc = NULL; 
} 
else 
{ 
while (q->nextarc != NULL) 
q = q->nextarc; 
q->nextarc = p; 
p->nextarc = NULL; 
} 
}  
} 
fclose(fp); 
return OK; 
} 
int ShortestPathLength(ALGraph G, KeyType v, KeyType k) 
{ 
int n = LocateVertex(G, v); 
int m = LocateVertex(G, k); 
if (n == -1 || m == -1) 
return ERROR; 
int visited[G.vexnum] = {0}; 
int distance[G.vexnum] = {0}; 
queue<int> q; 
q.push(n); 
visited[n] = 1; 
distance[n] = 0; 
while (!q.empty()) 
{ 
int u = q.front(); 
q.pop(); 
ArcNode *p = G.vertices[u].firstarc; 
while (p) 
{ 
int w = p->adjvex; 
if (!visited[w]) 
{ 
visited[w] = 1; 
distance[w] = distance[u] + 1;  
q.push(w); 
} 
p = p->nextarc; 
} 
} 
if (visited[m]) 
return distance[m]; 
else 
return ERROR; 
} 
void VerticesWithinDistanceK(ALGraph G, KeyType v, KeyType K) 
{ 
if (K < 0) 
{ 
printf(" 輸入的 K 值不合法\n"); 
return; 
} 
int start = LocateVertex(G, v); 
if (start == -1) 
{ 
printf(" 輸入的頂點不合法\n"); 
return; 
} 
if (G.vexnum == 0) 
{ 
printf(" 圖為空\n"); 
return; 
} 
if (G.arcnum == 0) 
{  
printf(" 圖中沒有邊\n"); 
return; 
} 
// 使用一次 BFS 求所有點到 v 的距離，避免多次 ShortestPathLength 調用 
int distance[MAX_VERTEX_NUM]; 
for (int i = 0; i < G.vexnum; ++i) 
distance[i] = -1; 
queue<int> q; 
distance[start] = 0; 
q.push(start); 
while (!q.empty()) 
{ 
int u = q.front(); 
q.pop(); 
ArcNode *p = G.vertices[u].firstarc; 
while (p) 
{ 
int w = p->adjvex; 
if (distance[w] == -1) 
{ 
distance[w] = distance[u] + 1; 
q.push(w); 
} 
p = p->nextarc; 
} 
} 
int flag = 0; 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (i == start) 
continue; 
if (distance[i] != -1 && distance[i] < K)  
{ 
flag = 1; 
printf(" %d %s", G.vertices[i].data.key, 
G.vertices[i].data.others); 
} 
} 
if (!flag) 
printf(" 沒有滿足條件的頂點\n"); 
return; 
} 
int ConnectedComponentsNum(ALGraph G) 
{ 
vector<int> visited(G.vexnum, 0); 
int cnt = 0; 
for (int i = 0; i < G.vexnum; i++) 
{ 
if (!visited[i]) 
{ 
cnt++; 
queue<int> q; 
q.push(i); 
visited[i] = 1; 
while (!q.empty()) 
{ 
int u = q.front(); 
q.pop(); 
ArcNode *p = G.vertices[u].firstarc; 
while (p) 
{  
int w = p->adjvex; 
if (!visited[w]) 
{ 
visited[w] = 1; 
q.push(w); 
} 
p = p->nextarc; 
} 
} 
} 
} 
return cnt; 
} 
int LocateGraph(GRAPHS Graphs, char *Graphname) 
{ 
for (int i = 0; i < Graphs.length; i++) 
{ 
if (strcmp(Graphs.elem[i].name, Graphname) == 0) 
return i; 
} 
return -1; 
} 
status AddGraph(GRAPHS &Graphs, char *Graphname) 
{ 
if (Graphs.length >= MAX_GRAPH_SIZE) 
{ 
printf(" 圖的數量已達上限，無法添加新圖\n"); 
return ERROR;  
} 
for (int i = 0; i < Graphs.length; i++) 
{ 
if (strcmp(Graphs.elem[i].name, Graphname) == 0) 
{ 
printf(" 圖已存在，無法添加\n"); 
return ERROR; 
} 
} 
// 創建新圖 
ALGraph newGraph; 
newGraph.vexnum = 0; 
newGraph.arcnum = 0; 
newGraph.kind = UDG; // 默認無向圖 
strcpy(newGraph.name, Graphname); 
Graphs.elem[Graphs.length] = newGraph; 
Graphs.length++; 
Graphs.cur_index = Graphs.length - 1; 
return OK; 
} 
status RemoveGraph(GRAPHS &Graphs, char *Graphname) 
{ 
int index = LocateGraph(Graphs, Graphname); 
if (index == -1) 
{ 
printf(" 圖不存在，無法刪除\n"); 
return ERROR; 
} 
// 銷毀圖 
DestroyGraph(Graphs.elem[index]);  
memset(&Graphs.elem[index], 0, sizeof(ALGraph)); 
// 刪除圖 
for (int i = index; i < Graphs.length - 1; i++) 
{ 
Graphs.elem[i] = Graphs.elem[i + 1]; 
} 
Graphs.length--; 
return OK; 
} 
status SwitchGraph(GRAPHS &Graphs, char *Graphname) 
{ 
int index = LocateGraph(Graphs, Graphname); 
if (index == -1) 
{ 
printf(" 圖不存在，無法切換\n"); 
return ERROR; 
} 
Graphs.cur_index = index; 
return OK; 
} 
void PrintGraphslist(GRAPHS Graphs) 
{ 
printf(" 當前圖列表：\n"); 
for (int i = 0; i < Graphs.length; i++) 
{ 
printf("%d: %s\n", i + 1, Graphs.elem[i].name); 
} 
} 
void PrintGraphWithAdjList(ALGraph G)  
{ 
printf("\n當前的圖和鄰接表：\n"); 
printf("-----------------------------------------------\n"); 
printf(" 圖名稱：%s\n", G.name); 
printf(" 頂點數：%d，邊數：%d\n", G.vexnum, G.arcnum); 
printf("-----------------------------------------------\n"); 
printf(" 位置序號 頂點資訊 鄰接點\n"); 
printf("-----------------------------------------------\n"); 
for (int i = 0; i < G.vexnum; i++) 
{ 
printf("%-9d %-3d %-10s ", i, G.vertices[i].data.key, 
G.vertices[i].data.others); 
ArcNode *p = G.vertices[i].firstarc; 
if (!p) 
{ 
printf("(無鄰接點)"); 
} 
else 
{ 
while (p) 
{ 
printf("%d", p->adjvex); 
p = p->nextarc; 
if (p) 
printf("->"); 
} 
} 
printf("\n"); 
} 
printf("-----------------------------------------------\n"); 
} 
void PrintMenu(GRAPHS Graphs)  
{ 
printf("\n"); 
printf("---------------------------------------------------------\n"); 
printf(" Menu for Graph System On Adjacency List \n"); 
printf("---------------------------------------------------------\n\n"); 
printf(" 當前圖：%s\n", Graphs.elem[Graphs.cur_index].name); 
printf("Basic Operations:\n"); 
printf(" 1. CreateGraph 2. DestroyGraph \n"); 
printf(" 3. LocateVex 4. PutVex \n"); 
printf(" 5. FirstAdjVex 6. NextAdjVex \n"); 
printf(" 7. InsertVex 8. DeleteVex \n"); 
printf(" 9. InsertArc 10. DeleteArc \n"); 
printf(" 11. DFSTraverse 12. BFSTraverse \n"); 
printf("Additional Operations:\n"); 
printf(" 13. SaveGraph 14. LoadGraph \n"); 
printf(" 15. ShortestPathLength 16. VerticesWithinK \n"); 
printf(" 17. ConnectedComponentsNum \n"); 
printf("Multiple Graphs Operations:\n"); 
printf(" 18. AddGraph 19. RemoveGraph \n"); 
printf(" 20. SwitchGraph 21. PrintGraphs \n"); 
printf(" 0. Exit 22. PrintGraphWithAdjList\n"); 
printf("---------------------------------------------------------\n"); 
printf(" 請輸入操作選項：\n"); 
} 
int main() 
{ 
GRAPHS Graphs; 
Graphs.length = 1; 
Graphs.cur_index = 0; 
ALGraph G; 
G.vexnum = 0; 
G.arcnum = 0;  
G.kind = UDG; // 默認無向圖 
Graphs.elem[0] = G; 
char firstname[30]; 
system("cls"); 
printf("--------------------------------------------------\n"); 
printf(" 鄰接表實現的圖系統，可以對單個或多個無向圖進行操作\n"); 
printf("Author: HUST Cupid-qrq\n"); 
printf("--------------------------------------------------\n"); 
printf(" 在開始之前，請先輸入第一個圖的名稱：\n"); 
if (scanf("%s", firstname) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
scanf("%s", firstname); 
} 
printf(" 輸入成功，第一個圖的名稱是：%s\n", firstname); 
strcpy(Graphs.elem[0].name, firstname); 
printf(" 接下來，進入功能表介面，按任意鍵繼續：\n"); 
getchar(); 
getchar(); 
int op = 1; 
// 功能表選項 
VertexType V[MAX_VERTEX_NUM]; 
// 頂點陣列 
KeyType VR[MAX_VERTEX_NUM][2]; // 邊陣列 
int exist; 
char filename[100], treename[100]; 
// to be continued 
while (op) 
{ 
PrintMenu(Graphs); 
if (scanf("%d", &op) != 1) 
{ 
op = -1; 
 
} 
switch (op) 
{ 
case 1: 
{ 
// 創建圖 
if (Graphs.elem[Graphs.cur_index].vexnum != 0) 
{ 
printf(" 當前圖已存在，創建失敗！\n"); 
break; 
} 
// 初始化定義陣列 
memset(V, 0, sizeof(V)); 
memset(VR, 0, sizeof(VR)); 
printf(" 請輸入圖的頂點序列，格式為：key others，以 -1 nil 結束。 \n"); 
int i = 0; 
do 
{ 
scanf("%d%s", &V[i].key, V[i].others); 
} while (V[i++].key != -1); 
i = 0; 
printf(" 請輸入圖的邊序列，格式為：v1 v2，以 -1 -1 結束。\n"); 
do 
{ 
scanf("%d%d", &VR[i][0], &VR[i][1]); 
} while (VR[i++][0] != -1); 
// 構造新圖 
status res = CreateGraph(Graphs.elem[Graphs.cur_index], V, 
VR);  
if (res == OK) 
{ 
printf(" 圖創建成功。\n"); 
} 
else 
{ 
printf(" 圖創建失敗，可能原因：重複 key 或記憶體不足。\n"); 
} 
break; 
} 
case 2: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，銷毀失敗！\n"); 
break; 
} 
if (DestroyGraph(Graphs.elem[Graphs.cur_index]) == OK) 
printf(" 圖銷毀成功！\n"); 
else 
printf(" 圖不存在，銷毀失敗！\n"); 
break; 
} 
case 3: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，查找失敗！\n"); 
break; 
} 
int index;  
printf(" 請輸入要查找的結點的關鍵字：\n"); 
if (scanf("%d", &exist) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
index = LocateVertex(Graphs.elem[Graphs.cur_index], exist); 
if (index == -1) 
{ 
printf(" 查找失敗，結點不存在！\n"); 
} 
else 
{ 
printf(" 查找成功，結點的頂點位置序號是：%d\n", index); 
} 
break; 
} 
case 4: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，修改失敗！\n"); 
break; 
} 
exist = 0; 
printf(" 請輸入要修改的結點的關鍵字：\n"); 
if (scanf("%d", &exist) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
}  
int index = LocateVertex(Graphs.elem[Graphs.cur_index], 
exist); 
if (index == -1) 
{ 
printf(" 查找失敗，結點不存在！\n"); 
} 
else 
{ 
printf(" 請輸入新的結點值：\n"); 
VertexType newVex; 
scanf("%d", &newVex.key); 
strcpy(newVex.others, 
Graphs.elem[Graphs.cur_index].vertices[index].data.others); 
if (PutVex(Graphs.elem[Graphs.cur_index], exist, newVex) 
== OK) 
{ 
printf(" 修改成功！\n"); 
} 
else 
{ 
printf(" 修改失敗，可能原因：重複 key 或記憶體不足。\n"); 
} 
} 
break; 
} 
case 5: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，查找失敗！\n"); 
break; 
}  
exist = 0; 
printf(" 請輸入要查找的結點的關鍵字：\n"); 
if (scanf("%d", &exist) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
int res = FirstAdjVex(Graphs.elem[Graphs.cur_index], exist); 
if (res == -1) 
{ 
printf(" 查找失敗，結點不存在！\n"); 
} 
else 
{ 
printf(" 查找成功，結點的第一鄰接頂點是：\n"); 
printf(" %d %s\n", 
Graphs.elem[Graphs.cur_index].vertices[res].data.key, 
Graphs.elem[Graphs.cur_index].vertices[res].data.others); 
} 
break; 
} 
case 6: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，查找失敗！\n"); 
break; 
} 
int v, w; 
printf(" 請輸入要查找的結點的關鍵字：\n"); 
if (scanf("%d", &v) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n");  
continue; 
} 
printf(" 請輸入該結點的一個鄰接結點的關鍵字：\n"); 
if (scanf("%d", &w) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
int res2 = NextAdjVex(Graphs.elem[Graphs.cur_index], v, w); 
if (res2 == -1) 
{ 
printf(" 查找失敗\n"); 
} 
else 
{ 
printf(" 查找成功，結點的下一個鄰接頂點是：\n"); 
printf(" %d %s\n", 
Graphs.elem[Graphs.cur_index].vertices[res2].data.key, 
Graphs.elem[Graphs.cur_index].vertices[res2].data.others); 
} 
break; 
} 
case 7: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，插入頂點失敗！\n"); 
break; 
} 
VertexType newVex; 
printf(" 請輸入要插入的結點的 key 和 others：\n"); 
if (scanf("%d %s", &newVex.key, newVex.others) != 2) 
{  
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (InsertVex(Graphs.elem[Graphs.cur_index], newVex) == OK) 
{ 
printf(" 插入成功！\n"); 
} 
else 
{ 
printf(" 插入失敗\n"); 
} 
break; 
} 
case 8: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，刪除頂點失敗！\n"); 
break; 
} 
int exist = 0; 
printf(" 請輸入要刪除的結點的關鍵字：\n"); 
if (scanf("%d", &exist) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (DeleteVex(Graphs.elem[Graphs.cur_index], exist) == OK) 
{ 
printf(" 刪除成功！\n"); 
}  
else 
{ 
printf(" 刪除失敗。\n"); 
} 
break; 
} 
case 9: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，插入邊失敗！\n"); 
break; 
} 
int v1, v2; 
printf(" 請輸入要插入的弧的兩個頂點的關鍵字：\n"); 
if (scanf("%d %d", &v1, &v2) != 2) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (InsertArc(Graphs.elem[Graphs.cur_index], v1, v2) == OK) 
{ 
printf(" 插入成功！\n"); 
} 
else 
{ 
printf(" 插入失敗。\n"); 
} 
break; 
} 
case 10:  
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，刪除邊失敗！\n"); 
break; 
} 
int v1, v2; 
v1 = v2 = 0; 
printf(" 請輸入要刪除的弧的兩個頂點的關鍵字：\n"); 
if (scanf("%d %d", &v1, &v2) != 2) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (DeleteArc(Graphs.elem[Graphs.cur_index], v1, v2) == OK) 
{ 
printf(" 刪除成功！\n"); 
} 
else 
{ 
printf(" 刪除失敗。\n"); 
} 
break; 
} 
case 11: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，遍歷失敗！\n"); 
break; 
}  
printf(" 深度優先遍歷結果：\n"); 
DFSTraverse(Graphs.elem[Graphs.cur_index]); 
printf("\n"); 
break; 
} 
case 12: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，遍歷失敗！\n"); 
break; 
} 
printf(" 廣度優先遍歷結果：\n"); 
BFSTraverse(Graphs.elem[Graphs.cur_index]); 
printf("\n"); 
break; 
} 
case 13: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，保存失敗！\n"); 
break; 
} 
printf(" 請輸入要保存的檔案名：\n"); 
if (scanf("%s", filename) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (SaveGraph(Graphs.elem[Graphs.cur_index], filename) == OK) 
{ 
printf(" 保存成功！\n"); 
} 
else 
{ 
printf(" 保存失敗。\n"); 
} 
break; 
} 
case 14: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum != 0) 
{ 
printf(" 當前圖已存在，載入失敗！\n"); 
break; 
} 
printf(" 請輸入要載入的檔案名：\n"); 
if (scanf("%s", filename) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (LoadGraph(Graphs.elem[Graphs.cur_index], filename) == OK) 
{ 
printf(" 載入成功！\n"); 
} 
else 
{ 
printf(" 載入失敗。\n"); 
}  
break; 
} 
case 15: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，查找失敗！\n"); 
break; 
} 
int v1, v2; 
v1 = v2 = 0; 
printf(" 請輸入要查找的結點的關鍵字：\n"); 
if (scanf("%d %d", &v1, &v2) != 2) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
int res3 = ShortestPathLength(Graphs.elem[Graphs.cur_index], 
v1, v2); 
if (res3 == ERROR) 
{ 
printf(" 查找失敗，結點不存在！\n"); 
} 
else 
{ 
printf(" 查找成功，最短路徑長度是：%d\n", res3); 
} 
break; 
} 
case 16: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
 
{ 
printf(" 當前圖不存在，查找失敗！\n"); 
break; 
} 
int v1 = 0; 
int k = 0; 
printf(" 請輸入要查找的結點的關鍵字：\n"); 
if (scanf("%d", &v1) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
printf(" 請輸入要查找的距離：\n"); 
if (scanf("%d", &k) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
printf(" 查找結果：\n"); 
VerticesWithinDistanceK(Graphs.elem[Graphs.cur_index], v1, k); 
printf("\n"); 
break; 
} 
case 17: 
{ 
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，查找失敗！\n"); 
break; 
} 
int num = 
ConnectedComponentsNum(Graphs.elem[Graphs.cur_index]); 
 
printf(" 連通分量的個數是：%d\n", num); 
break; 
} 
case 18: 
{ 
if (Graphs.length >= MAX_GRAPH_SIZE) 
{ 
printf(" 圖的數量已達上限，無法添加新圖\n"); 
break; 
} 
printf(" 請輸入要添加的圖的名稱：\n"); 
if (scanf("%s", treename) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (AddGraph(Graphs, treename) == OK) 
{ 
printf(" 添加成功！\n"); 
} 
else 
{ 
printf(" 添加失敗。\n"); 
} 
break; 
} 
case 19: 
{ 
printf(" 請輸入要刪除的圖的名稱：\n"); 
if (scanf("%s", treename) != 1) 
{ 
 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (RemoveGraph(Graphs, treename) == OK) 
{ 
printf(" 刪除成功！\n"); 
} 
break; 
} 
case 20: 
{ 
printf(" 請輸入要切換的圖的名稱：\n"); 
if (scanf("%s", treename) != 1) 
{ 
printf(" 輸入錯誤，請重新輸入：\n"); 
continue; 
} 
if (SwitchGraph(Graphs, treename) == OK) 
{ 
printf(" 切換成功！\n"); 
} 
break; 
} 
case 21: 
{ 
PrintGraphslist(Graphs); 
break; 
} 
case 22: 
{  
if (Graphs.elem[Graphs.cur_index].vexnum == 0) 
{ 
printf(" 當前圖不存在，列印失敗！\n"); 
break; 
} 
PrintGraphWithAdjList(Graphs.elem[Graphs.cur_index]); 
break; 
} 
case 0: 
{ 
printf(" 退出系統！\n"); i hq
break; 
} 
default: 
printf(" 輸入錯誤，請重新輸入：\n"); 
break; 
} 
if (op != 0) 
{ 
printf(" 按回車鍵鍵繼續...\n"); 
getchar(); 
getchar(); 
} 
} 
return 0; 
}

