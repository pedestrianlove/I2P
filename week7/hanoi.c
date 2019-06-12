#include<stdio.h>

void hanoi(int times, int from, int to, int temp)
{
	if(times>0){
		hanoi(times-1, from, temp, to);
		printf("%d->%d\n", from, to);
		hanoi(times-1, temp, to, from);
	}
}
int main()
{
	// INPUt THE NUMBER OF DISKS
	int times, from, to, temp;

	scanf("%d%d%d%d\n",&times, &from, &to, &temp);
	hanoi(times, from, to, temp);
	return 0;
}
