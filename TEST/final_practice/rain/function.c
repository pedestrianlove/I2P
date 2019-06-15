#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _NODE
{
	char color[10];
	struct _NODE *next;
} Node;

// global
int list_length = 0;

// operations
Node* init_node (char*);
Node* jump_node (Node** ,int);


void insert (Node** head, char* color, int dst)
{
	Node* new = init_node (color);
	Node* Dst = jump_node (head, list_length);
	
	new -> next = Dst -> next;
	Dst -> next = new;
	list_length ++;
}

void erase1 (Node** head, int dst)
{
	Node* Dst_prev = jump_node (head, dst-1);
	
	Node* Dst = Dst_prev -> next;
	Dst_prev -> next = Dst_prev -> next -> next;

	free (Dst);
}

void erase2(Node** head, char* dst)
{
	Node* ptr = *head;
	Node* tmp;
	while (ptr -> next != NULL) {
		if (strcmp (ptr->next->color, dst) == 0) {
			tmp = ptr -> next;
			ptr -> next = ptr -> next -> next;
			free (tmp);
			continue;
		}
		ptr = ptr -> next;
	}
}

void reverse(Node** head, int start, int dst)
{
	if (start > dst)
		reverse (head, dst, start);

	Node* Start = jump_node (head, start - 1);
	Node* Dst = jump_node (head, dst + 1);

	
	Node *tmp;
	Node* ptr = Start -> next;
	Node* to_connect = Dst;
	
	while (ptr -> next != Dst) {
		tmp = ptr;
		ptr = ptr -> next;
		tmp -> next = to_connect;
		to_connect = tmp;
	}
	
	Start -> next = ptr;
}

/*-------------------------------------------------------*/

Node* init_node (char* color)
{
	Node* new = malloc (sizeof(Node));
	strcpy (new -> color, color);
	new -> next = NULL;
	return new;
}

Node* jump_node (Node** head, int dst)
{
	Node* ptr = *head;
	if (list_length <= dst)
		for (int i = 0; i < list_length; i++) {
			ptr = ptr -> next;
		}
	else
		for (int i = 0; i < dst; i++) {
			ptr = ptr -> next;
		}
	return ptr;
}
