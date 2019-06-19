#include<stdio.h>
#include<stdlib.h>

typedef struct data {
	int INDEX;
	int LEVEL;
	int NUMBER;
}data;
data* init_data (int index, int level, int number)
{
	data* new = malloc (sizeof(data));
	
	new -> INDEX = index;
	new -> LEVEL = level;
	new -> NUMBER = number;
	
	return new;
}

/*-------------------------------------------------------------------*/
// global
data** LIST;
int LIST_LENGTH;

// internal
int cmp_level (const void *, const void *);
int cmp_number (const void *, const void *);

// interface
void Init_list ();
void Get_list ();
void Sort_list ();
void Print_list ();
void Delete_list ();

/*-------------------------------------------------------------------*/
int main()
{
	Init_list ();

	Get_list ();

	Sort_list ();

	Print_list ();	

	Delete_list ();

	return 0;
}


void Init_list ()
{
	scanf("%d", &LIST_LENGTH);
	LIST = malloc (sizeof(data*) * LIST_LENGTH);
		
	for (int i = 0; i < LIST_LENGTH; i++)
		LIST[i] = NULL;	
}


void Get_list ()
{
	int level, number;
	for (int i = 0; i < LIST_LENGTH; i++) {
		scanf("%d%d", &level, &number);
		LIST[i] = init_data (i+1, level, number);
	}
}


void Sort_list ()
{
	qsort (LIST, LIST_LENGTH, sizeof(data*), cmp_number);
	qsort (LIST, LIST_LENGTH, sizeof(data*), cmp_level);
}
int cmp_level (const void * a, const void * b)
{
	const data ** va = (const data **) a;
	const data ** vb = (const data **) b;
	return (*va)->LEVEL - (*vb)->LEVEL;
}
int cmp_number (const void * a, const void * b)
{
	const data ** va = (const data **) a;
	const data ** vb = (const data **) b;
	return (*va)->NUMBER - (*vb)->NUMBER;
}


void Print_list ()
{
	for (int i = 0; i < LIST_LENGTH; i++)
		if (i < LIST_LENGTH - 1)
			printf("%d ", LIST[i] -> INDEX);
		else
			printf("%d\n", LIST[i] -> INDEX);
}


void Delete_list ()
{
	for (int i = 0; i < LIST_LENGTH; i++)
		free (LIST[i]);
	free (LIST);
}
