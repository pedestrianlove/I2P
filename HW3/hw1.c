#include<stdio.h>
#include<stdlib.h>

int find_max_sum(int* minion_hp, int number_of_minions, int conti_kill, int* kills); // RETURN MAX SUM

int main()
{
	// VARIABLES
	int kills = 0;
	int number_of_minions, kill_streaks;
	scanf("%d%d", &number_of_minions, kill_streaks);
	
	int* minion_hp;
	minion_hp = (int*) malloc(number_of_minions*sizeof(int));

	// INPUT DATA
	for(int i = 0; i< number_of_minions; i++)
		scanf("%d", &minion_hp[i]);

	// PROCESS AND FIND THE MAX SUM
	printf("%.3f\n", (float)(find_max_sum(minion_hp, number_of_minions, kill_streaks, &kills)/kills));

}

int find_max_sum(int* minion_hp, int number_of_minions, int conti_kill, int* kills)
{
	minion_hp[computer];	
}
