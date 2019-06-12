#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// FIXME
int cmp (const void * a, const void * b) // TBD
{
	const char** va	= (const char**)a;
	const char** vb	= (const char**)b;
	
	// Exclude the equivalent length cases
	int a_len = strlen (*va);
	int b_len = strlen (*vb);
	if (a_len ==  b_len){
		return strcmp (*vb, *va);
	}
	else{
		int n = (a_len < b_len)? a_len : b_len;
		if (n = strncmp (*vb, *va, n) == 0)
			if (a_len > b_len)
				return -1;
			else
				return 1;
		else
			return n;
				
	}
}



int main()
{
	int SIZE;
	char **data;
	while(scanf("%d", &SIZE) != EOF){
		// Allocate the space and input the data
		data = malloc (sizeof(char*) * SIZE);
		for (int i = 0; i< SIZE; i++){
			data[i] = malloc (sizeof(char) * 1000);
			scanf (" %s", data[i]);
		}

		// Sort the data list
		qsort (data, SIZE, sizeof(char*), cmp);

		// Output the arranged number
		for (int i = 0; i< SIZE; i++){
			printf("%s", data[i]);
		}
		printf("\n");

		// Free the memory used	
		free (data);
	}



	return 0;
}
