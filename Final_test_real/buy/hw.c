#include <stdio.h>
#include <stdlib.h>

typedef struct item {
	int PRICE[3];
	int MIN_DAY;
}item;
item* init_item (int day1, int day2)
{
	item* new = malloc (sizeof(item));
	new -> PRICE[0] = day1;
       	new -> PRICE[1] = day2;
	new -> PRICE[2] = day2-day1;
	new -> MIN_DAY = (day1 < day2)? 0: 1;

	return new;	
}


// global
item** LIST;
int QUOTA;
int LIST_LENGTH;

// internal
int* input_price ();
int cmp (const void*, const void*);

// interface
void Get_input ();
void Init_list ();
void Input_list ();
long long Buy_list ();

int main ()
{
	Get_input ();
	
	Init_list ();

	Input_list ();

	printf("%lld\n", Buy_list ());

	return 0;
}


void Get_input ()
{
	scanf ("%d%d", &LIST_LENGTH, &QUOTA);
}


void Init_list ()
{
	LIST = malloc (sizeof(item*) * LIST_LENGTH);
	for (int i = 0; i < LIST_LENGTH; i++)
		LIST[i] = NULL;
}


void Input_list ()
{
	int* DAY1 = input_price ();
	int* DAY2 = input_price ();

	for (int i=  0; i < LIST_LENGTH; i++)
		LIST[i] = init_item (DAY1[i], DAY2[i]);

	free (DAY1);
	free (DAY2);
}
int* input_price ()
{
	int* arr = malloc (sizeof(int) * LIST_LENGTH);
	for (int i = 0; i < LIST_LENGTH; i++)
		scanf("%d", &arr[i]);

	return arr;
}


long long Buy_list ()
{
	long long sum = 0;
	qsort (LIST, LIST_LENGTH, sizeof(item*), cmp);
	
	for (int i = 0; i < LIST_LENGTH; i++) {
		if (i < QUOTA) {
			sum += LIST[i] -> PRICE[0];
		}
		else
			sum += LIST[i] -> PRICE[LIST[i]->MIN_DAY];
	}
	return sum;
}
int cmp (const void * b, const void * a)
{
	const item ** va = (const item **) a;
	const item ** vb = (const item **) b;

	return (*va)->PRICE[2] - (*vb)->PRICE[2];
}
