#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int index;
	int level;
	int number;
}node;
node* init_node (int index, int level, int number)
{
	node* new = malloc (sizeof(node));
	new -> index = index;
	new -> level = level;
	new -> number = number;
	return new;
}

// global
node** LIST;
int LIST_LENGTH;

// internal
int cmp_number (const void *, const void *);
int cmp_level (const void *, const void *);

// interface
void Get_input ();
void Init_list ();
void Input_list ();
void Sort_list ();
void Output_list ();

int main ()
{
	Get_input ();	

	Init_list ();

	Input_list ();

	Sort_list ();

	Output_list ();
	return 0;
}


void Get_input ()
{
	scanf("%d", &LIST_LENGTH);
}


void Init_list ()
{
	LIST = malloc (sizeof(node*)* LIST_LENGTH);
	for (int i = 0; i < LIST_LENGTH; i++) {
		LIST[i] = NULL;
	}
}


void Input_list ()
{
	int level, number;
	for (int i = 0; i < LIST_LENGTH; i++) {
		scanf("%d%d", &level, &number);
		LIST[i] = init_node (i+1, level, number);
	}
}


void Sort_list ()
{
	qsort (LIST, LIST_LENGTH, sizeof(node*), cmp_number);
	qsort (LIST, LIST_LENGTH, sizeof(node*), cmp_level);
}
int cmp_number (const void * a, const void *b)
{
	const node** va = (const node**) a;
	const node** vb = (const node**) b;
	return (*va)->number -  (*vb)->number;
}	
int cmp_level (const void * a, const void *b)
{
	const node** va = (const node**) a;
	const node** vb = (const node**) b;
	return (*va)->level - (*vb)->level;
}


void Output_list ()
{
	for (int i = 0; i < LIST_LENGTH; i++)
		if (i == LIST_LENGTH-1)
			printf("%d\n", LIST[i]->index);
		else
			printf("%d ", LIST[i]->index);
}
