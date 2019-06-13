#include<stdio.h>
#include<stdlib.h>
#define KEY 1000000007

typedef struct vector {
	long long *x[3];
}vector;


typedef struct matrix {
	long long number[3][3];

	vector row[3];
	vector col[3];
}matrix;


// internal
long long trivial (long long);
long long getPx (long long);
matrix* init_matrix ();
matrix* matrix_multiplication (matrix*, matrix*);
long long dot_product (vector, vector);
void matrix_quotient (matrix*);
int check_entry_overflow (matrix*);
void fill_matrix (matrix*);

// interface
long long Compute (long long);

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	int counter = 0;
	int queries;
	scanf("%d", &queries);
	long long number;
	for (int i = 0; i< queries; i++) {
		scanf("%lld", &number);
		printf("%lld\n", Compute(number));
		counter ++;
	}
	printf("This loop has been running for %d times\n", counter);


	return 0;
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

long long Compute (long long number)
{
	if (number <= 3)
		return trivial (number);

	number = getPx (number);
	
	return number % KEY;	

}
long long trivial (long long number)
{
	switch (number) {
		case 1: 
			return 1;
			break;
		case 2: 
			return 12;
			break;
		case 3: 
			return 13;
			break;
		default:
			return 0;
			break;
	}

}
long long getPx (long long number)
{
	matrix* base = init_matrix ();
	matrix* tmp = init_matrix ();
	long long a = 13, b = 12, c = 1;
	vector target = {&a, &b, &c};	
	
	// square
	number -= 3;
	while (number > 0) {	
		base = matrix_multiplication (base, base);
		number = number/2 + number%2;
		if (number == 1) {
			base = matrix_multiplication (base, tmp);
			number --;
		}
		
		if (check_entry_overflow (base))
			matrix_quotient (base);
	}	

	return dot_product (base->row[0], target);
}
matrix* init_matrix ()
{
	matrix* new = malloc (sizeof(matrix));

	fill_matrix (new);
	new -> number[0][0] = 1;
	new -> number[0][1] = 2;
	new -> number[0][2] = 1;
	new -> number[1][0] = 1;
	new -> number[2][1] = 1;	

	for (int i = 0; i < 3; i++)	
		for (int j = 0; j < 3; j++) {
			new->row[i].x[j] = &new->number[i][j];
			new->col[i].x[j] = &new->number[j][i];
		}
	return new;
}
matrix* matrix_multiplication (matrix* A, matrix* B)
{
	matrix* ans = init_matrix ();
	fill_matrix(ans);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ans->number[i][j] = dot_product (A->row[i], B->col[j]);
	free (A);
	return ans;
}
long long dot_product (vector A, vector B)
{
	long long sum = 0;
	for (int i = 0; i < 3; i++)
		sum += *(A.x[i]) * *(B.x[i]);

	return sum;
}
void matrix_quotient (matrix* A)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A->number[i][j] = A->number[i][j] % KEY;
}
int check_entry_overflow (matrix* A)
{
	for (int i = 0; i< 3; i++)
		for (int j = 0; j < 3; j++)
			if (A->number[i][j] > KEY)
				return 1;
	return 0;
}
void fill_matrix (matrix* A)
{
	for (int i = 0; i< 3; i++)
		for (int j = 0; j < 3; j++)
			A->number[i][j] = 0;
}
