#include<stdio.h>
#include<stdlib.h>



int main()
{
	// Input
	int length, queries, target;
	scanf("%d%d", &length, &queries);
	int* num = malloc (length*sizeof(int));
	for (int i = 0; i< length; i++)
		scanf("%d", &num[i]);
	
	// Get the queries and use binary search
	for (int i= 0 ; i< queries; i++){
		scanf ("%d", target);
		if (find (num, length-1, target))
			printf("I know de way to your home.\n");
		else
			printf("Wake up, you homeless poor.\n");	
	}	

	free (num);
	return 0;
}
