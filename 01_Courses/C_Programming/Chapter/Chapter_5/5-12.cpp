#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100
typedef struct {
    int x;
    int y;
} Point;
int pathCount = 0;
void findAllPaths(int maze[MAX_ROWS][MAX_COLS], int rows, int cols);
void printPath(int path[MAX_ROWS][MAX_COLS], int rows, int cols);
void dfs(int maze[MAX_ROWS][MAX_COLS], int path[MAX_ROWS][MAX_COLS], Point current, Point end, int rows, int cols);
int main() {
    int maze[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int i, j;
    scanf("%d %d", &rows, &cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    findAllPaths(maze, rows, cols);
    return 0;
}
void findAllPaths(int maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int path[MAX_ROWS][MAX_COLS];
    Point start = {0, 0};
    Point end = {rows - 1, cols - 1};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            path[i][j] = 0;
        }
    }
    dfs(maze, path, start, end, rows, cols);
}
void dfs(int maze[MAX_ROWS][MAX_COLS], int path[MAX_ROWS][MAX_COLS], Point current, Point end, int rows, int cols) {
    if (current.x < 0 || current.x >= rows || current.y < 0 || current.y >= cols ||
        maze[current.x][current.y] == 0 || path[current.x][current.y] == 1) {
        return;
    }
    path[current.x][current.y] = 1;
    if (current.x == end.x && current.y == end.y) {
        pathCount++;
        printf("%d\n", pathCount);
        printPath(path, rows, cols);
        path[current.x][current.y] = 0;
        return;
    }
    Point up = {current.x - 1, current.y};
    dfs(maze, path, up, end, rows, cols);
    Point down = {current.x + 1, current.y};
    dfs(maze, path, down, end, rows, cols);
    Point left = {current.x, current.y - 1};
    dfs(maze, path, left, end, rows, cols);
    Point right = {current.x, current.y + 1};
    dfs(maze, path, right, end, rows, cols);
    path[current.x][current.y] = 0;
}
void printPath(int path[MAX_ROWS][MAX_COLS], int rows, int cols) {
	printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", path[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
