#include<stdio.h>
#include<stdlib.h>
#define ALIVE 1
#define DEAD 0
#define DEFEND 1
#define ATTACK 0

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
void fight (man*);

// interface
man* Init_Asher ();
void Init_NPC ();
void Prepare_map ();
int Adventure (man*);

// misc
void FREE (man*);

// debug
void show_map ();

int main()
{
	man* Asher = Init_Asher ();
	Init_NPC ();

	Prepare_map ();
	show_map ();
	
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
	point pos;
	scanf("%d%d", &(pos.X), &(pos.Y) );
	pos.X--;
	pos.Y--;

	npc->POS = pos;
}


void Prepare_map ()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			MAP[i][j] = NULL;

	for (int i = 0; i< NUMBER_OF_NPC; i++) {
		MAP[NPC[i]->POS.X][NPC[i]->POS.Y] = NPC[i];
	}
}


int Adventure (man* Asher)
{
	printf("@Asher is now at point (%d, %d), HP is %d\n", Asher->POS.X, Asher->POS.Y, Asher->HP);
	if (MAP[Asher->POS.X][Asher->POS.Y] != NULL)
		fight (Asher);

	if (Asher->HP <= 0) {
		printf("Asher is dead at point (%d, %d) after a fight\n", Asher->POS.X, Asher->POS.Y);
		return DEAD;
	}
	
	if (Asher->POS.X == 4 && Asher->POS.Y == 4)
		return ALIVE;
	
	man Asher_bk = *Asher;
	// only move down or right
	// travel right
	if (Asher->POS.X + 1 < 5) {
		Asher->POS.X++;
		if (Adventure (Asher) == ALIVE)
			return ALIVE;
	}
	
	*Asher = Asher_bk;
	
	if (Asher->POS.Y + 1 < 5) {
		Asher->POS.Y++;
		if (Adventure (Asher) == ALIVE)
			return ALIVE;
	}

	return DEAD;
}
void fight (man* Asher)
{
	printf("\n");
	printf("---------------------------------------------\n");
	printf("A fight occurs at point (%d, %d):\n", Asher->POS.X, Asher->POS.Y);
	int turn = 0;
	man* NPC = MAP[Asher->POS.X][Asher->POS.Y];
	man NPC_bk = *NPC;

	while (Asher->HP > 0 && NPC->HP > 0) {
		printf("Asher's HP is now %d, NPC's HP is now %d\n", Asher->HP, NPC->HP);
		if ((turn++) %2 == ATTACK)
			NPC->HP -= Asher->AD;
		else
			Asher->HP -= NPC->AD;
	}	
	printf("Asher's HP is now %d, NPC's HP is now %d\n", Asher->HP, NPC->HP);
	printf("\n");
	*NPC = NPC_bk;
}

void show_map ()
{
	printf("There are %d NPC on the map\n", NUMBER_OF_NPC);
	int zero = 0;
	for (int i = 0; i< 5; i++) {
		for (int j = 0; j < 5; j++)
			if (MAP[i][j] == NULL)
				printf ("%4d ", zero);
			else
				printf("%4d ", MAP[i][j]->HP);
		printf("\n");
	}
}


void FREE (man* Asher)
{
	free (Asher);
	for (int i = 0; i< NUMBER_OF_NPC ; i++) {
		free (NPC[i]);
	}
	free (NPC);
}
