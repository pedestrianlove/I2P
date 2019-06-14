#include<stdio.h>
#include<stdlib.h>

// object and methods
typedef struct man {
	int HP;
	int POS;     // use the index of the track as POS
	int RELIFE;
	int BIKE_HP;
}man;
man* INIT_man (int k)
{
	man* new = malloc (sizeof(man));

	new -> HP = k;
	new -> POS = 0;
	new -> RELIFE = 0;

	return new;
}

typedef struct road {
	int* STATIONS_LOC;
	int STATIONS_NUM;
}road;

/*------------------------------------------------------------------*/


// global
man* RACER;
road* TRACK;


// internal
void ready_racer (int);
void ready_track (int);
void wear_the_bike (int);
void change_bike ();


// Interface
void Ready ();
int Go ();


/*------------------------------------------------------------------*/

int main ()
{
	Ready ();
	if (Go ())
		printf("%d\n", RACER -> LIFE);
	else
		printf("The Legend Falls.\n");	
}

/*-------------------------------------------------------------------*/
void Ready ()
{
	int stations, bike_hp;
	scanf("%d%d", &stations, &bike_hp);
	ready_racer (bike_hp);
	ready_track (stations);
}
void ready_racer (int bike_hp)
{
	RACER = INIT_man (bike_hp);
	RACER -> BIKE_HP = bike_hp;
}
void ready_track (int stations)
{
	TRACK = malloc (sizeof(road));

	TRACK -> STATIONS_NUM = stations + 1;
	TRACK -> STATIONS_LOC[0] = 0;
	for (int i = 1; i < stations + 1; i++)
		scanf("%d", &TRACK->STATIONS_LOC[i]);
}


int Go () // indexing using the number of stations
{
	wear_the_bike (TRACK -> STATIONS_LOC[RACER->POS+1]  -  TRACK -> STATIONS_LOC[RACER->POS]);

	if (RACER -> HP < 0) {
		if (RACER)
	}


	
	wear_the_bike (TRACK -> STATIONS_LOC[RATER->POS]  -  TRACK -> STATIONS_LOC[RACER->POS+1]);
	return 0;
}
void wear_the_bike (int distance)
{
	RACER -> HP -= distance;
}
void change_bike ()
{
	RACER -> HP = RACER -> BIKE_HP;
	RACER -> RELIFE ++;
}
