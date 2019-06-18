#include<stdio.h>
#include<stdlib.h>

typedef struct item {
	int PRICE[3];

	int MIN_DAY;
}item;

// global
item** LIST;
int LIST_LENGTH;

// internal
item* init_item ();
int cmp_diff (const void*, const void*);

// interface
void Init_list ();
void Input_list ();
int Analyze_list ();
void Delete_list ();

int main()
{
	Init_list ();

	Input_list ();

	printf("%d\n", Analyze_list ());
	Delete_list ();
	return 0;
}


void Init_list ()
{
	scanf("%d", &LIST_LENGTH);
		
	LIST = malloc (sizeof(item*) * LIST_LENGTH);
	
	for (int i = 0; i < LIST_LENGTH; i++)
		LIST[i] = init_item();
}
item* init_item ()
{
	item* new = malloc (sizeof(item));
	
	new -> PRICE[0] = 0;
	new -> PRICE[1] = 0;
	new -> MIN_DAY = 4;

	return new;
}


void Input_list ()
{
	int entry;
	for (int i = 0; i< LIST_LENGTH; i++) {
		scanf("%d", &entry);
		LIST[i] -> PRICE[0] = entry;
	}
	for (int i = 0; i < LIST_LENGTH; i++) {
		scanf("%d", &entry);
		LIST[i] -> PRICE[1] = entry;
	}
	for (int i = 0; i < LIST_LENGTH; i++) {
		LIST[i] -> PRICE[2]  =  LIST[i] -> PRICE[1]  -  LIST[i] -> PRICE[0];
	}
}


int Analyze_list (int first_day_quota) // FIXME Logic error
{
	int min_sum = 0;
	
	
	for (int i = 0; i < LIST_LENGTH; i++)
		LIST[i]->MIN_DAY = (LIST[i]->PRICE[0] <= LIST[i]->PRICE[1])? 0 : 1;

	for (int i = 0; i < LIST_LENGTH; i++)
		printf("%d ", LIST[i]->PRICE[2]);
	printf("\n");
	qsort (LIST, LIST_LENGTH, sizeof(item*), cmp_diff);	
	for (int i = 0; i < LIST_LENGTH; i++)
		printf("%d ", LIST[i]->PRICE[2]);
	printf("\n");
	
	for (int i = 0; i < LIST_LENGTH; i++) {
		if (i < first_day_quota) {
			min_sum += LIST[i] -> PRICE[0];
		}
		else
			min_sum += LIST[i] -> PRICE[LIST[i]->MIN_DAY];
	}

	return min_sum;
}
int cmp_diff (const void * a, const void * b) // decreasing
{
	const item * va = (const item *) a;
	const item * vb = (const item *) b;

	return va->PRICE[2] - vb->PRICE[2];
}



void Delete_list ()
{
	for (int i = 0; i < LIST_LENGTH; i++)
		free (LIST[i]);

	free (LIST);
}
