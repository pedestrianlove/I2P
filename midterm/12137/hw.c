#include<stdio.h>
#include<stdlib.h>

long* numbers;
int counter, n;
void find(long target_sum, int start)
{
	// Substract the target_sum
	target_sum -= numbers[start++];

	// Check stop conditions (including successful cases)
	if(target_sum<0 || start==n)
		return;
	if(target_sum==0){
		counter++;
		return;
	}

	// Continue searching
	for(int i = start; i< n;i++)
		find(target_sum, i);	
}

int main()
{
	// Input the numbers and the target_sum
	long target_sum;
	scanf("%d%ld", &n, &target_sum);
	numbers = malloc(sizeof(long)*n);
	for(int i = 0; i< n; i++){
		scanf("%ld", &numbers[i]);
	}
	
	// Find the combination for target_sum
	counter = 0;
	if(target_sum ==0)
		counter++;
	else
		for(int i = 0; i< n; i++){
			find(target_sum, i);
		}
	// Output the counter
	printf("%d\n", counter+1);
	free(numbers);
	return 0;
}
