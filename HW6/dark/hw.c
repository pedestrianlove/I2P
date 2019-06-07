#include<stdio.h>
#include<stdlib.h>
#define ALIVE 1
#define DEAD 0

typedef struct point {
	int X;
	int Y;
}point;
typedef struct man {
	int HP;
	int AD;
	point POS;
}man;

// global variables
man* MAP[5][5];

man** NPC;
int NUMBER_OF_NPC = 0; 

// internal
man* get_info ();
void get_pos (man*);

// interface
man* Init_Asher ();
void Init_NPC ();
void Prepare_map ();
int Adventure (man*);

void FREE (man*);

int main()
{
	man* Asher = Init_Asher ();
	Init_NPC ();

	Prepare_map ();
	
	if (Adventure (Asher) == ALIVE)
		printf("HEIR OF FIRE DESTROYED\n");
	else
		printf("YOU DIED\n");


	FREE (Asher);
	return 0;
}


man* Init_Asher ()
{
	man* Asher = get_info ();
	
	Asher->POS.X = 0;
	Asher->POS.Y = 0;

	return Asher;
}
man* get_info ()
{
	man* new = malloc (sizeof(man));
	scanf("%d%d", &(new->HP), &(new->AD) );

	return new;
}


void Init_NPC ()
{
	scanf("%d", &NUMBER_OF_NPC);
	NPC = malloc (sizeof(man) * NUMBER_OF_NPC);

	for (int i = 0; i < NUMBER_OF_NPC; i++) {
		NPC[i] = get_info ();
		get_pos (NPC[i]);
	}
}
void get_pos (man* npc)
{
	scanf("%d%d", &(npc->POS.X), &(npc->POS.Y) );
}


void Prepare_map ()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			MAP[i][j] = NULL;

	for (int i = 0; i< NUMBER_OF_NPC) {
		MAP[NPC[i]->POS.X][NPC[i]->POS.Y] = NPC[i];
	}
}


int Adventure (man* Asher)
{




}




void FREE (man* Asher)
{
	free (Asher);
	for (int i = 0; i< NUMBER_OF_NPC ; i++) {
		free (NPC[i]);
	}
	free (NPC);
}
