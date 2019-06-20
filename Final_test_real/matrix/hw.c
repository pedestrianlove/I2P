#include <stdio.h>
#include <stdlib.h>

// global
int dim, sub_dim;
int matrix[20][20];
int sub_matrix[20][20];

// interface
int Check_matrix (int x, int y);

int main ()
{
	scanf("%d%d", &dim, &sub_dim);

	for (int i = 0; i < dim; i++) 
		for (int j = 0; j < dim; j++)
			scanf("%d", &matrix[i][j]);
	for (int i = 0; i < sub_dim; i++) 
		for (int j = 0; j < sub_dim; j++)
			scanf("%d", &sub_matrix[i][j]);


	for (int row = 0;  row < dim; row++)
		for (int col = 0; col < dim; col++)
			if (matrix[row][col] == sub_matrix[0][0]) {
				if (Check_matrix (row, col)){
					printf("%d %d\n", row, col);
					return 0;
				}
			}


	printf("Failed\n");
	return 0;
}

int Check_matrix (int x, int y)
{
	for (int row = 0; row < sub_dim; row++)
		for (int col = 0; col < sub_dim; col++){
			if (matrix[row+x][col+y] != sub_matrix[row][col]) {
				return 0;
			}
		}
	return 1;
}
