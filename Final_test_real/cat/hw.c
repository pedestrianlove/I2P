#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x, y;
	int USED;
}point;
point* init_point (int x, int y)
{
	point* new = malloc (sizeof(point));
	new -> x = x;
	new -> y = y;
	new -> USED = 0;
	return new;
}


// global
int remaining;
int num;
long long distance;
point** LIST;

// internal
int check_dist (point*, point*);

// interface
void Get_data ();
void Init_list ();
void Input_list ();
int Process_list ();

int main ()
{
	Get_data ();

	Init_list ();

	Input_list ();

	int collisions = Process_list (0);

	printf("%d %d\n", remaining, collisions);

	return 0;
}


void Get_data ()
{
	scanf ("%d%lld", &num, &distance);
	remaining = num;
	distance = distance * distance;
}


void Init_list ()
{
	LIST = malloc (sizeof(point*) * num);
	for (int i = 0; i < num; i++)
		LIST[i] = NULL;
}


void Input_list ()
{
	int x, y;
	for (int i = 0; i < num; i++) {
		scanf("%d%d", &x, &y);
		LIST[i] = init_point (x, y);
	}
}


int Process_list (int index)
{
	int collisions = 0;
	
	for (int i = 0; i < num ; i++) {
		if (check_dist (LIST[index], LIST[i]) == 1) {
			if (LIST[i]->USED == 0) {
				LIST[i]->USED = 1;
				remaining--;	
				collisions += Process_list(i);
			}
		}

	}


	return collisions;
}
int check_dist (point* pt1, point* pt2)
{
	long long x_d = pt1->x - pt2->x;
	long long y_d = pt1->y - pt2->y;
	long long dist = x_d*x_d + y_d*y_d;

	if (dist >= distance)
		return 0;
	else
		return 1;
}
