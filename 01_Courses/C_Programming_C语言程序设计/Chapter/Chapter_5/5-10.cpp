#include <stdio.h>
void markRowsToEliminate(int board[][100], int rows, int cols, int mark[][100]);
void markColumnsToEliminate(int board[][100], int rows, int cols, int mark[][100]);
void eliminateMarkedPositions(int board[][100], int rows, int cols, int mark[][100]);

int main() {
    int board[100][100];
    int rows, cols;
    int i, j;
    scanf("%d %d", &rows, &cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    int rowMark[100][100] = {0};
    int colMark[100][100] = {0};
    markRowsToEliminate(board, rows, cols, rowMark);
    markColumnsToEliminate(board, rows, cols, colMark);
    eliminateMarkedPositions(board, rows, cols, rowMark);
    eliminateMarkedPositions(board, rows, cols, colMark);
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d", board[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
void markRowsToEliminate(int board[][100], int rows, int cols, int mark[][100]) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        j = 0;
        while (j < cols) {
            int count = 1;
            k = j + 1;
            while (k < cols && board[i][k] == board[i][j]) {
                count++;
                k++;
            }
            if (count >= 3) {
                for (k = j; k < j + count; k++) {
                    mark[i][k] = 1;
                }
            }
            j = k;
        }
    }
}
void markColumnsToEliminate(int board[][100], int rows, int cols, int mark[][100]) {
    int i, j, k;
    for (j = 0; j < cols; j++) {
        i = 0;
        while (i < rows) {
            int count = 1;
            k = i + 1;
            while (k < rows && board[k][j] == board[i][j]) {
                count++;
                k++;
            }
            if (count >= 3) {
                for (k = i; k < i + count; k++) {
                    mark[k][j] = 1;
                }
            }
            i = k;
        }
    }
}
void eliminateMarkedPositions(int board[][100], int rows, int cols, int mark[][100]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mark[i][j] == 1) {
                board[i][j] = 0;
            }
        }
    }
}
