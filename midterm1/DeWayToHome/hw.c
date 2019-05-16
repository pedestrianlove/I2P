#include<stdio.h>
#include<stdlib.h>
int half;
int find (int* num, int length, int target) 
{ 
	if (num[length] < target || target < num[0])
		return 0;
        half = length / 2; 
        
	
	// Check if x is present at mid 
        if (num[half] == target) 
            	return 1; 
	else if (length == 0)
		return 0;	      
        
	// If x greater, ignore left half 
        if (num[half] < target) 
            	find (num+half+1,half, target);
  	
        // If x is smaller, ignore right half 
        else
        	find (num, half-1, target);
  
    	// if we reach here, then element was 
    	// not present 
} 
int main()
{
	// Input
	int length, queries, target;
	scanf("%d%d", &length, &queries);
	int *num = malloc (length*sizeof(int));
	for (int i = 0; i< length; i++){
		scanf("%d", &num[i]);
		printf("%d ",num[i] );
	}
	printf("\n");
		
	// Get the queries and use binary search
	for (int i= 0 ; i< queries; i++){
		scanf ("%d", &target);
		if (find (num, length-1, target))
			printf("I know de way to your home.\n");
		else
			printf("Wake up, you homeless poor.\n");	
	}	

	free (num);
	return 0;
}
