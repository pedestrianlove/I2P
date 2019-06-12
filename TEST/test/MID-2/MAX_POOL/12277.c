#include <stdio.h>
#include "function.h"

void Print(int m, int n, int matrix[][500])
{
    int i, j;
	for (i = 0; i < m; i++ ) {
        for (j = 0; j < n; j++ ) {
            printf("%d%c", matrix[i][j], " \n"[j==n-1] );
        }
    }
}

int main()
{
    int matrix[500][500];
    int row, col, k;
    scanf("%d%d%d", &row, &col, &k);
    int i, j;
    for (i = 0; i < row; i++ ) {
        for (j = 0; j < col; j++ ) {
            scanf("%d", &matrix[i][j]);
        }
    }
    max_pooling(matrix, row, col, k);
    Print(row/k, col/k, matrix);
    return 0;
}
