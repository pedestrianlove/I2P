#include<stdio.h>
#include<stdlib.h>

// objects and methods
typedef struct node {
	int number;
	struct node *next, *prev;
}node;
node* _init_node (int number) 
{
	node* new = malloc (sizeof(node));
	new -> number = number;
	return new;
}

/*-----------------------------------------------------*/

// global


// internal


// interface
void Get_operations (char*);
void Run_operations (char*)



/*-------------------------------------------------------*/

int main()
{
	





	return 0;
}

/*--------------------------------------------------------*/
