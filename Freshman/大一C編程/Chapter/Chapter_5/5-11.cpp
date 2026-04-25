#include <stdio.h>
#include <stdlib.h>
void generateSpiralMatrix(int n, int matrix[][100]);
void printMatrix(int n, int matrix[][100]);
int main() {
    int n;
    int matrix[100][100];
    scanf("%d", &n);
    generateSpiralMatrix(n, matrix);  
    printMatrix(n, matrix);
    return 0;
}
void generateSpiralMatrix(int n, int matrix[][100]) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    while (num <= n * n) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }
}
void printMatrix(int n, int matrix[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
