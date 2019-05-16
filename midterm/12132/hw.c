#include<stdio.h>
#include<stdlib.h>

int main()
{
	// Variables
	int number_of_fruits;
	scanf("%d", &number_of_fruits);
	int* index_dist = malloc(sizeof(int)* number_of_fruits);
	
	// Input the index
	for(int i = 0; i< number_of_fruits; i++){
		scanf("%d", &index_dist[i]);
	}

	// Input the eating order
	int now_want;
	int find_index, eaten;
	int* availability = malloc(sizeof(int)*number_of_fruits);
	for(int i = 0; i< number_of_fruits; i++)
		availability[i] = 1;

	find_index = 0;
	for(int i = 0; i<number_of_fruits; i++){
		scanf("%d", &now_want);
		eaten = 0;
		// Check for availability status first
		if(availability[now_want-1]){
			// Then scan for now_want while eating through the fruits
			while(now_want != index_dist[find_index]){
				// Check for availability status
				if(availability[find_index]){
					// EAT IT
					eaten++;
					availability[find_index] = 0;
				}
				// CONTINUE
				find_index ++;
			}
			// After encountering the now_want, eat it also
			availability[find_index] = 0;
			eaten++;
			find_index++;
		}

		if(i == number_of_fruits -1){
			printf("%d\n", eaten);
		}else{
			printf("%d ", eaten);
		}

	}
	free(availability);
	free(index_dist);
	return 0;
}
