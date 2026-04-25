#include "definition.hpp"

/***********************************************
*函數名稱：isSafe
* 函數功能：檢查在給定的行、列和數位的情況下，數位是否可以安全地放置在數獨棋盤上。
* 注釋：用於生成數獨時，檢查數位是否可以放置在數獨棋盤上。
* 返回值：如果數位可以安全地放置在數獨棋盤上，則返回true，否則返回false。
************************************************/
bool isSafe(const vector<int>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        // 檢查行
        if (board[row * SIZE + x] == num)
            return false;
        // 檢查列
        if (board[x * SIZE + col] == num)
            return false;
    }

    // 檢查九宮格
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[(startRow + i) * SIZE + (startCol + j)] == num)
                return false;
        }
    }

    // 檢查上陰影
    if (row >0 and row<=3 and col >0 and col<=3) {
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(i!=row and j!=col){
                    if (board[i * SIZE + j] == num)
                        return false;                    
                }
            }
        }
    }

    //檢查下陰影
    if (row >4 and row<=7 and col >4 and col<=7) {
        for(int i=5;i<=7;i++){
            for(int j=5;j<=7;j++){
                if(i!=row and j!=col){
                    if (board[i * SIZE + j] == num)
                        return false;                    
                }
            }
        }
    }    

    // 檢查對角線
    if (row + col == SIZE - 1) {
        for (int i = 0; i < SIZE; i++) {
            if (board[i * SIZE + (SIZE - 1 - i)] == num)
                return false;
        }
    }

    return true;
}

/***********************************************
*函數名稱：solveSudoku
* 函數功能：隨機生成數獨棋盤
* 注釋：利用遞迴回溯的思想，生成數獨棋盤。
* 返回值：bool類型，如果成功生成數獨棋盤，則返回true，否則返回false。
************************************************/
bool solveSudoku(vector<int>& board) 
{
    for (int row = 1; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row * SIZE + col] == 0) { //如果當前位置為空
                for (int num = 1; num <= SIZE; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row * SIZE + col] = num; // 放置數字

                        if (solveSudoku(board))
                            return true; // 遞迴

                        // Backtrack
                        board[row * SIZE + col] = 0; //回溯
                    }
                }
                return false; // 遞迴失敗
            }
        }
    }
    return true; // 生成成功
}
/***********************************************
*函數名稱：GenerateFirstLine
* 函數功能：隨機產生數獨棋盤的第一行
* 注釋：solveSudoku函數的輔助函數，用於生成數獨棋盤的第一行，這決定了後續數獨棋盤的生成。
* 返回值：void
************************************************/
void GenerateFirstLine(vector<int>& a) {

    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand() % SIZE + 1;
        int j = 0;
        while (j < i) {
            if (a[i] == a[j]) {//如果生成的數字重複
                a[i] = rand() % SIZE + 1;//重新生成
                j = 0;//重新檢查
            }
            else {
                j++;
            }
        }
    }
}

/***********************************************
*函數名稱：generateDiagonalSudoku
* 函數功能：隨機生成數獨棋盤
* 注釋：傳入board陣列，生成數獨棋盤。
* 返回值：void
************************************************/
void generateDiagonalSudoku(vector<int>& board) {
    for (int i = 0; i < 81; i++)
    {
        board[i] = 0;
    }
    GenerateFirstLine(board);
    solveSudoku(board);
   
}
void PrintBoard(const vector<int>& Board)
{
    cout << "   數 獨 棋 盤" << endl;

    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0) {
            cout << "+-----+-----+-----+" << endl;//每三行列印一次
        }
        cout << "|";//每行開始列印
        for (int col = 0; col < 9; col++) {
            if (Board[row * 9 + col] != 0)
            {
                cout << Board[row * 9 + col];//列印數位
           }
            else
            {
                cout << "_";//列印空格
            }
            if (col % 3 == 2) {
                cout << "|";//每三列列印一次
            }
            else {
                cout << " ";//每列之間列印一個空格
            }
        }
        cout << endl;
    }
    cout << "+-----+-----+-----+" << endl;
}
int generateGameBoard(const vector<int>& normalBoard, vector<int>& gameBoard) {
    
    // 隨機挖去的數位數量
    int numToRemove = 35 + rand() % 13;

    // 複製 normalBoard 到 gameBoard
    gameBoard = normalBoard;

    // 創建索引陣列
    vector<int> indices(81,0);
    for (int i = 0; i <81; ++i) {
        indices[i] = i;
    }
   
    // 打亂索引陣列
    for (int i = 80; i > 0; --i) {
        int j = rand()%i;
        swap(indices[i], indices[j]);
    }

    // 挖去數字
    for (int i = 0; i < numToRemove; ++i) {
        gameBoard[indices[i]] = 0; // 0 表示空白
    }
    return numToRemove;
}

bool checkSafe(const vector<int>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        // 檢查行
        if (board[row * SIZE + x] == num){
            printf("行衝突\n");
            return false;
        }
            
        // 檢查列
        if (board[x * SIZE + col] == num){
            printf("列衝突\n");
            return false;
        }
            
    }

    // 檢查九宮格
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[(startRow + i) * SIZE + (startCol + j)] == num){
                printf("九宮格衝突\n");
                return false;
            }
                
        }
    }

    // 檢查上陰影
    if (row >0 and row<=3 and col >0 and col<=3) {
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(i!=row and j!=col){
                    if (board[i * SIZE + j] == num){
                        printf("上百分號衝突\n");
                        return false;     
                    }
                                       
                }
            }
        }
    }

    //檢查下陰影
    if (row >4 and row<=7 and col >4 and col<=7) {
        for(int i=5;i<=7;i++){
            for(int j=5;j<=7;j++){
                if(i!=row and j!=col){
                    if (board[i * SIZE + j] == num){
                        printf("下百分號衝突\n");
                        return false;     
                    }              
                }
            }
        }
    }    

    // 檢查對角線
    if (row + col == SIZE - 1) {
        for (int i = 0; i < SIZE; i++) {
            if (board[i * SIZE + (SIZE - 1 - i)] == num){
                        printf("對角線衝突\n");
                        return false;     
                    }
        }
    }

    return true;
}

/*
 @ 函數名稱: WriteToFile
 @ 接受參數: int[][],int
 @ 函數功能: 將數獨約束條件寫入檔
 @ 返回值: status
 */
status shudutocnf(const vector<int>& board, int empty)
{
    FILE *fp;
    fp = fopen("shudu.cnf","w");
    fprintf(fp, "p cnf 729 %d\n", 13068 - empty); // 12978是數獨的約束條件數量，81-empty為已填寫格子數
    // 數字ijk表示第i行第j列的數字是k
    // 用公式(i-1)*81+(j-1)*9+k將每個變元映射到1-729的變元上
    /*提示數約束(寫在前面,便於單子句規則進行)*/
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            if (board[(i - 1) * 9 + j - 1] != 0)
                fprintf(fp, "%d 0\n", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + board[(i - 1) * 9 + j - 1]);
        }
    }
    /*每個格子的約束*/
    // 每個格子必須填入一個數字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                fprintf(fp, "%d ", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + k);
            }
            fprintf(fp, "0\n");
        }
    }
    // 每個格子不能填入兩個數字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; l <= SIZE; l++)
                {
                    fprintf(fp, "%d %d 0\n", 0 - ((i - 1) * SIZE * SIZE + (j - 1) * SIZE + k), 0 - ((i - 1) * SIZE * SIZE + (j - 1) * SIZE + l));
                }
            }
        }
    }
    /*行約束*/
    // 每一行必須填入1-9
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                fprintf(fp, "%d ", (i - 1) * SIZE * SIZE + (k - 1) * SIZE + j);
            }
            fprintf(fp, "0\n");
        }
    }
    // 每一行不能填入兩個相同的數字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; l <= SIZE; l++)
                {
                    fprintf(fp, "%d %d 0\n", 0 - ((i - 1) * SIZE * SIZE + (k - 1) * SIZE + j), 0 - ((i - 1) * SIZE * SIZE + (l - 1) * SIZE + j));
                }
            }
        }
    }
    /*列約束*/
    // 每一列必須填入1-9
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                fprintf(fp, "%d ", (k - 1) * SIZE * SIZE + (i - 1) * SIZE + j);
            }
            fprintf(fp, "0\n");
        }
    }
    // 每一列不能填入兩個相同的數字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; l <= SIZE; l++)
                {
                    fprintf(fp, "%d %d 0\n", 0 - ((k - 1) * SIZE * SIZE + (i - 1) * SIZE + j), 0 - ((l - 1) * SIZE * SIZE + (i - 1) * SIZE + j));
                }
            }
        }
    }
    /*3x3宮格約束*/
    // 每個3x3宮格必須填入1-9
    for (int i = 1; i <= SIZE; i += 3)
    {
        for (int j = 1; j <= SIZE; j += 3)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        fprintf(fp, "%d ", ((i + l - 1) * SIZE * SIZE + (j + m - 1) * SIZE + k));
                    }
                }
                fprintf(fp, "0\n");
            }
        }
    }
    // 每個3x3宮格不能填入兩個相同的數字
    for (int i = 1; i <= SIZE; i += 3)
    {
        for (int j = 1; j <= SIZE; j += 3)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l1 = 0; l1 < 3; l1++)
                {
                    for (int m1 = 0; m1 < 3; m1++)
                    {
                        for (int l2 = l1; l2 < 3; l2++)
                        {
                            int start = (l2 == l1) ? m1 + 1 : 0;
                            for (int m2 = start; m2 < 3; m2++)
                            {
                                fprintf(fp, "%d %d 0\n", 
                                    0 - ((i + l1 - 1) * SIZE * SIZE + (j + m1 - 1) * SIZE + k),
                                    0 - ((i + l2 - 1) * SIZE * SIZE + (j + m2 - 1) * SIZE + k));
                            }
                        }
                    }
                }
            }
        }
    }
    /*對角線約束*/
    // 副對角線必須填入1-9
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            fprintf(fp, "%d ", (j - 1) * SIZE * SIZE + (SIZE - j) * SIZE + i);
        }
        fprintf(fp, "0\n");
    }
    // 副對角線不能填入兩個相同的數字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = j + 1; k <= SIZE; k++)
            {
                fprintf(fp, "%d %d 0\n", 0 - ((j - 1) * SIZE * SIZE + (SIZE - j ) * SIZE + i), 0 - ((k - 1) * SIZE * SIZE + (SIZE - k) * SIZE + i));
            }
        }
    }
    //百分號約束
    // 每個上百分號必須填入1-9
    for (int k = 1; k <= SIZE; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            for (int m = 0; m < 3; m++)
            {
                fprintf(fp, "%d ", ((2 + l - 1) * SIZE * SIZE + (2 + m - 1) * SIZE + k));
            }
        }
        fprintf(fp, "0\n");
    }
    // 每個上百分號不能填入兩個相同的數字
    for (int k = 1; k <= SIZE; k++)
    {
        for (int l1 = 0; l1 < 3; l1++)
        {
            for (int m1 = 0; m1 < 3; m1++)
            {
                for (int l2 = l1; l2 < 3; l2++)
                {
                    int start = (l2 == l1) ? m1 + 1 : 0;
                    for (int m2 = start; m2 < 3; m2++)
                    {
                        fprintf(fp, "%d %d 0\n", 
                            0 - ((2 + l1 - 1) * SIZE * SIZE + (2 + m1 - 1) * SIZE + k),
                            0 - ((2 + l2 - 1) * SIZE * SIZE + (2 + m2 - 1) * SIZE + k));
                    }
                }
            }
        }
    }
    // 每個下百分號必須填入1-9
    for (int k = 1; k <= SIZE; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            for (int m = 0; m < 3; m++)
            {
                fprintf(fp, "%d ", ((6 + l - 1) * SIZE * SIZE + (6 + m - 1) * SIZE + k));
            }
        }
        fprintf(fp, "0\n");
    }
    // 每個上百分號不能填入兩個相同的數字（正確代碼）
    for (int k = 1; k <= SIZE; k++)
    {
        for (int l1 = 0; l1 < 3; l1++)
        {
            for (int m1 = 0; m1 < 3; m1++)
            {
                for (int l2 = l1; l2 < 3; l2++)
                {
                    int start = (l2 == l1) ? m1 + 1 : 0;
                    for (int m2 = start; m2 < 3; m2++)
                    {
                        fprintf(fp, "%d %d 0\n", 
                            0 - ((6 + l1 - 1) * SIZE * SIZE + (6 + m1 - 1) * SIZE + k),
                            0 - ((6 + l2 - 1) * SIZE * SIZE + (6 + m2 - 1) * SIZE + k));
                    }
                }
            }
        }
    }
    fclose(fp);
    return OK;
}

