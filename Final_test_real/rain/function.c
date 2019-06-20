#include "function.h"

Node* jump (Node**, int);
Node* init_node ( char*);
void insert (Node** head, char* color, int position)
{
	node* pos = jump (head, position);
	node* next = pos -> next;
	node* new = init_node (color);
	pos -> next = new;
	new -> next = pos;
}


void erase1 (Node** head, int position)
{
	node* before = jump (head, position - 1);
	node* tmp = before -> next;
	before -> next = before -> next -> next;
	free (tmp);
}


void erase2 (Node** head, char* color)
{
	Node* ptr = *head;
	while (ptr != NULL) {
		if (strcmp (ptr -> color))
	}

}


void reverse (Node** head, int start, int end)
{
	
}

Node* init_node (char* color )
{
	node* new = malloc (sizeof(node));
	new -> color = color;
	new -> next = NULL;
	return new;
}

Node* jump (Node** head, int position)
{
	Node* ptr = *head;
	for (int i = 0; i < position && ptr->next != NULL; i++) {
		ptr = ptr -> next;
	}

	return ptr;
}
