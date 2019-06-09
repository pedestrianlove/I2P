#include<stdio.h>
#include<stdlib.h>

#define MINE 1
#define NOT_MINE 0

typedef struct item {
	int PRICE[2];
	int STATE;
}item;

// global
item** LIST;
int LIST_LENGTH;

// internal
item* init_item ();
int cmp_day1 (const void*, const void*);
int cmp_day2 (const void*, const void*);

// interface
void Init_list ();
void Input_list ();
int Analyze_list ();
void Delete_list ();

int main()
{
	Init_list ();

	Input_list ();

	int sum = Analyze_list ();
	printf("%d\n", sum);

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
	new -> STATE = NOT_MINE;

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
}


int Analyze_list (int first_day_quota) // FIXME
{
	int min_sum = 0;


	qsort (LIST, LIST_LENGTH, sizeof(item*), cmp_day1);	


	for (int i = 0; i < first_day_quota; i++) {
		min_sum += LIST[i] -> PRICE[0];
		LIST[i] -> STATE = MINE;
	}


	qsort (LIST, LIST_LENGTH, sizeof(item*), cmp_day2);


	for (int i = 0; i < LIST_LENGTH; i++)
		if (LIST[i]->STATE == NOT_MINE )
			min_sum += LIST[i] ->PRICE[1];	
	

	return min_sum;
}
int cmp_day1 (const void * a, const void * b)
{
	const item * va = (const item *) a;
	const item * vb = (const item *) b;

	return va->PRICE[0] - vb->PRICE[0];
}
int cmp_day2 (const void * a, const void * b)
{
	const item * va = (const item *) a;
	const item * vb = (const item *) b;

	return va->PRICE[1] - vb->PRICE[1];
}


void Delete_list ()
{
	for (int i = 0; i < LIST_LENGTH; i++)
		free (LIST[i]);

	free (LIST);
}
