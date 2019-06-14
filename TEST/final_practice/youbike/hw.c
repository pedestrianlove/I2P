/*
 * If we use the recursive implementation in this HW, the last test data will get TLE
 * while the While-loop implementation works fine, passing with 28 ms
 */

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


// misc
void FREE ();
/*------------------------------------------------------------------*/

int main ()
{
	Ready ();
	if (Go ())
		printf("%d\n", RACER -> RELIFE);
	else
		printf("The Legend Falls.\n");	


	FREE ();
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
	TRACK -> STATIONS_LOC = malloc (sizeof(int) * (stations + 1));
	TRACK -> STATIONS_LOC[0] = 0;
	for (int i = 1; i < stations + 1; i++)
		scanf("%d", &TRACK->STATIONS_LOC[i]);
}


int Go () // indexing using the number of stations
{
// While-loop implementation
	while (RACER->POS != TRACK->STATIONS_NUM) {
		if (TRACK -> STATIONS_LOC[RACER->POS+1]  -  TRACK -> STATIONS_LOC[RACER->POS]  <=  RACER -> HP) {
			wear_the_bike (TRACK -> STATIONS_LOC[RACER->POS+1]  -  TRACK -> STATIONS_LOC[RACER->POS]);
			RACER -> POS ++;
		}
		else {
			change_bike ();
			if (TRACK -> STATIONS_LOC[RACER->POS+1]  -  TRACK -> STATIONS_LOC[RACER->POS]  <=  RACER -> HP) {
				wear_the_bike (TRACK -> STATIONS_LOC[RACER->POS+1]  -  TRACK -> STATIONS_LOC[RACER->POS]);
				RACER -> POS ++;
			}
			else
				return 0;
		}
	}
	return 1;	
// Recursive implementation
/*
	printf("The racer is now at station NO.%d, HP=%d\n", RACER -> POS, RACER -> HP);
	wear_the_bike (TRACK -> STATIONS_LOC[RACER->POS+1]  -  TRACK -> STATIONS_LOC[RACER->POS]);
	if (RACER -> HP >= 0) {
		RACER -> POS ++;
		if (RACER -> POS  ==  TRACK -> STATIONS_NUM) 
			return 1;

		if (Go ())
			return 1;
		else {
			printf("The racer failed at station NO.%d, HP=%d\n", RACER -> POS, RACER -> HP);
			change_bike ();
			if (Go ())
				return 1;
		}
		RACER -> POS --;

	}

	wear_the_bike (TRACK -> STATIONS_LOC[RACER->POS]  -  TRACK -> STATIONS_LOC[RACER->POS+1]);
	return 0;
*/
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


void FREE ()
{
	free (RACER);
	free (TRACK -> STATIONS_LOC);
	free (TRACK);
}
