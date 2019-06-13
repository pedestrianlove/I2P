#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct vector {
	int* x[2];
}vector;
int dot_product (vector a, vector b)
{
	int sum = 0;
	for (int i = 0; i < 2; i++)
		sum += *(a.x[i]) *  (*(b.x[i]));
	return sum;
}


typedef struct matrix {
	int number[2][2];
	
	vector row[2], col[2];
}matrix;
matrix* INIT_matrix ()
{
	matrix* new = malloc (sizeof(matrix));
	new->number[0][0] = 1;
	new->number[0][1] = 1;
	new->number[1][0] = 1;
	new->number[1][1] = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new->row[i].x[j] = &(new -> number[i][j]);
			new->col[i].x[j] = &(new -> number[j][i]);
		}
	}
	return new;
}
matrix* matrix_multiplication (matrix* A, matrix* B)
{
	matrix* C = INIT_matrix ();
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			C -> number[i][j] = dot_product (A->row[i], B->col[j]);
	return C;
}








// internal
int trivial_fib (int);

// interface
int Find_fib (int);

int main()
{
	int number;
	while (scanf("%d", &number) != EOF) {
		printf("%d\n", Find_fib(number));
	}
	return 0;
}


int Find_fib (int number)
{
	if (number <= 2) {
		return trivial_fib (number);
	}
	number = number - 2;
	printf("----------------------------------------\n");
	printf("The number I received is %d\n", number);	
	matrix* base = INIT_matrix ();
	matrix* multiplier = INIT_matrix ();
	matrix* tmp;
	while (number > 1) {
		printf("The number is now %d\n", number);
		if (number %2 == 0) {
			printf("I squared the base\n");
			base = matrix_multiplication (base, base);
			number /= 2;
		}
		else {
			printf("I squared the base with pattern 2\n");
			tmp = base;
			base = matrix_multiplication (base, base);
			base = matrix_multiplication (base, tmp);
			number --;
			number /= 2;
		}
	}
		
	int sum = base->number[0][0] + base -> number[0][1];
	free (base);
	free (multiplier);
	free (tmp);
	return sum;
}
int trivial_fib (int number)
{
	switch (number) {
		case 1: return 1;
		case 2: return 2;
		default: return -1;
	}


}
