#include<stdio.h>
#include<stdlib.h>

int cmp (const void * a, const void * b)
{
	const int* va = (const int* )a;
	const int* vb = (const int* )b;
	return *vb-*va;
}



int main()
{
	int SIZE;
	char* data;
	while(scanf("%d", &SIZE) != EOF){
		// Allocate the space and input the data
		data = malloc (sizeof(int) * SIZE);
		for (int i = 0; i< SIZE; i++)
			scanf ("%d", &data[i]);

		// Sort the data list
		qsort (data, SIZE, sizeof(int), cmp);

		// Output the arranged number
		for (int i = 0; i< SIZE; i++){
			printf("%d", data[i]);
		}
		printf("\n");

		// Free the memory used	
		free (data);
	}



	return 0;
}
