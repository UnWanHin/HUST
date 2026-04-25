#include "definition.hpp"

/***********************************************
*函数名称：isSafe
* 函数功能：检查在给定的行、列和数字的情况下，数字是否可以安全地放置在数独棋盘上。
* 注释：用于生成数独时，检查数字是否可以放置在数独棋盘上。
* 返回值：如果数字可以安全地放置在数独棋盘上，则返回true，否则返回false。
************************************************/
bool isSafe(const vector<int>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        // 检查行
        if (board[row * SIZE + x] == num)
            return false;
        // 检查列
        if (board[x * SIZE + col] == num)
            return false;
    }

    // 检查九宫格
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[(startRow + i) * SIZE + (startCol + j)] == num)
                return false;
        }
    }

    // 检查上阴影
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

    //检查下阴影
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

    // 检查对角线
    if (row + col == SIZE - 1) {
        for (int i = 0; i < SIZE; i++) {
            if (board[i * SIZE + (SIZE - 1 - i)] == num)
                return false;
        }
    }

    return true;
}

/***********************************************
*函数名称：solveSudoku
* 函数功能：随机生成数独棋盘
* 注释：利用递归回溯的思想，生成数独棋盘。
* 返回值：bool类型，如果成功生成数独棋盘，则返回true，否则返回false。
************************************************/
bool solveSudoku(vector<int>& board) 
{
    for (int row = 1; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row * SIZE + col] == 0) { //如果当前位置为空
                for (int num = 1; num <= SIZE; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row * SIZE + col] = num; // 放置数字

                        if (solveSudoku(board))
                            return true; // 递归

                        // Backtrack
                        board[row * SIZE + col] = 0; //回溯
                    }
                }
                return false; // 递归失败
            }
        }
    }
	return true; // 生成成功
}
/***********************************************
*函数名称：GenerateFirstLine
* 函数功能：随机产生数独棋盘的第一行
* 注释：solveSudoku函数的辅助函数，用于生成数独棋盘的第一行，这决定了后续数独棋盘的生成。
* 返回值：void
************************************************/
void GenerateFirstLine(vector<int>& a) {

    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand() % SIZE + 1;
        int j = 0;
        while (j < i) {
			if (a[i] == a[j]) {//如果生成的数字重复
                a[i] = rand() % SIZE + 1;//重新生成
				j = 0;//重新检查
            }
            else {
                j++;
            }
        }
    }
}

/***********************************************
*函数名称：generateDiagonalSudoku
* 函数功能：随机生成数独棋盘
* 注释：传入board数组，生成数独棋盘。
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
    cout << "   数 独 棋 盘" << endl;

    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0) {
            cout << "+-----+-----+-----+" << endl;//每三行打印一次
        }
        cout << "|";//每行开始打印
        for (int col = 0; col < 9; col++) {
            if (Board[row * 9 + col] != 0)
            {
				cout << Board[row * 9 + col];//打印数字
           }
            else
            {
				cout << "_";//打印空格
            }
            if (col % 3 == 2) {
                cout << "|";//每三列打印一次
            }
            else {
                cout << " ";//每列之间打印一个空格
            }
        }
        cout << endl;
    }
    cout << "+-----+-----+-----+" << endl;
}
int generateGameBoard(const vector<int>& normalBoard, vector<int>& gameBoard) {
	
    // 随机挖去的数字数量
    int numToRemove = 35 + rand() % 13;

    // 复制 normalBoard 到 gameBoard
    gameBoard = normalBoard;

    // 创建索引数组
    vector<int> indices(81,0);
    for (int i = 0; i <81; ++i) {
        indices[i] = i;
    }
   
    // 打乱索引数组
    for (int i = 80; i > 0; --i) {
        int j = rand()%i;
        swap(indices[i], indices[j]);
    }

    // 挖去数字
    for (int i = 0; i < numToRemove; ++i) {
        gameBoard[indices[i]] = 0; // 0 表示空白
    }
    return numToRemove;
}

bool checkSafe(const vector<int>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        // 检查行
        if (board[row * SIZE + x] == num){
            printf("行冲突\n");
            return false;
        }
            
        // 检查列
        if (board[x * SIZE + col] == num){
            printf("列冲突\n");
            return false;
        }
            
    }

    // 检查九宫格
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[(startRow + i) * SIZE + (startCol + j)] == num){
                printf("九宫格冲突\n");
                return false;
            }
                
        }
    }

    // 检查上阴影
    if (row >0 and row<=3 and col >0 and col<=3) {
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(i!=row and j!=col){
                    if (board[i * SIZE + j] == num){
                        printf("上百分号冲突\n");
                        return false;     
                    }
                                       
                }
            }
        }
    }

    //检查下阴影
    if (row >4 and row<=7 and col >4 and col<=7) {
        for(int i=5;i<=7;i++){
            for(int j=5;j<=7;j++){
                if(i!=row and j!=col){
                    if (board[i * SIZE + j] == num){
                        printf("下百分号冲突\n");
                        return false;     
                    }              
                }
            }
        }
    }    

    // 检查对角线
    if (row + col == SIZE - 1) {
        for (int i = 0; i < SIZE; i++) {
            if (board[i * SIZE + (SIZE - 1 - i)] == num){
                        printf("对角线冲突\n");
                        return false;     
                    }
        }
    }

    return true;
}

/*
 @ 函数名称: WriteToFile
 @ 接受参数: int[][],int
 @ 函数功能: 将数独约束条件写入文件
 @ 返回值: status
 */
status shudutocnf(const vector<int>& board, int empty)
{
    FILE *fp;
    fp = fopen("shudu.cnf","w");
    fprintf(fp, "p cnf 729 %d\n", 13068 - empty); // 12978是数独的约束条件数量，81-empty为已填写格子数
    // 数字ijk表示第i行第j列的数字是k
    // 用公式(i-1)*81+(j-1)*9+k将每个变元映射到1-729的变元上
    /*提示数约束(写在前面,便于单子句规则进行)*/
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            if (board[(i - 1) * 9 + j - 1] != 0)
                fprintf(fp, "%d 0\n", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + board[(i - 1) * 9 + j - 1]);
        }
    }
    /*每个格子的约束*/
    // 每个格子必须填入一个数字
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
    // 每个格子不能填入两个数字
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
    /*行约束*/
    // 每一行必须填入1-9
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
    // 每一行不能填入两个相同的数字
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
    /*列约束*/
    // 每一列必须填入1-9
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
    // 每一列不能填入两个相同的数字
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
    /*3x3宫格约束*/
    // 每个3x3宫格必须填入1-9
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
    // 每个3x3宫格不能填入两个相同的数字
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
    /*对角线约束*/
    // 副对角线必须填入1-9
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            fprintf(fp, "%d ", (j - 1) * SIZE * SIZE + (SIZE - j) * SIZE + i);
        }
        fprintf(fp, "0\n");
    }
    // 副对角线不能填入两个相同的数字
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
    //百分号约束
    // 每个上百分号必须填入1-9
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
    // 每个上百分号不能填入两个相同的数字
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
    // 每个下百分号必须填入1-9
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
    // 每个上百分号不能填入两个相同的数字（正确代码）
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