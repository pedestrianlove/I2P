#include<stdio.h>
#include<stdlib.h>

// object and methods
typedef struct man {
	int HP;
	int POS;
	int LIFE;
}man;
man* INIT_man (int k)
{
	man* new = malloc (sizeof(man));

	new -> HP = k;
	new -> POS = 0;
	new -> LIFE = 0;

	return new;
}


// global
man* RACER;
int BIKE_HP;
int* TRACK;
int TRACK_LEN;
int POS_index;

// internal
void ready_racer (int);
void ready_track (int);
void change_bike ();

// Interface
void Ready ();
int Go ();

int main ()
{
	Ready ();
	int tmp;
	if (Go ())
		printf("%d\n", RACER -> LIFE);
	else
		printf("The Legend Falls.\n");	
}

void Ready ()
{
	int stations, bike_dur;
	scanf("%d%d", &stations, &bike_dur);
	ready_racer (bike_dur);
	ready_track (stations);
}
void ready_racer (int k)
{
	RACER = INIT_man (k);
	BIKE_HP = k;
}
void ready_track (int stations)
{
	TRACK = malloc (sizeof(int) * stations);
	for (int i = 0; i < stations; i++)
		scanf("%d", &TRACK[i]);
	TRACK_LEN = stations;
	POS_index = 0;
}


int Go ()
{
	int changed_flag = 0;
	while (POS_index < TRACK_LEN && RACER -> HP > 0) {
		if (TRACK[POS_index] - RACER->POS >= 0) {
			changed_flag = 0;
			RACER -> HP -= TRACK[POS_index] - RACER->POS;
			RACER -> POS = TRACK[POS_index++];
			
		}
		else {
			if (changed_flag == 0) change_bike ();
			else
				return 0;
			changed_flag ++;
		}
	}
	return 1;
		
}
void change_bike ()
{
	if (RACER -> POS == TRACK[POS_index]) {
		RACER -> HP = BIKE_HP;
	}
	RACER -> LIFE ++;
}
