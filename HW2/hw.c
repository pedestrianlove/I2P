#include <stdio.h>
#include <stdlib.h>

int main()
{
	//VAR DEFINED
	int test_rounds, rows;
	//INPUT PARAMETER
	scanf("%d%d\n", &rows, &test_rounds);
	long garbage_temp = 0, stream;
	long* garbage_count;
	garbage_count = (long*) malloc(rows*sizeof(long));

	// input the garbage count
	for(int i = 0; i<rows; i++)
	{
		scanf("%d", &stream);
		garbage_temp = garbage_temp + stream;
		garbage_count[i] = garbage_temp;
		
		// eliminate the noise made by TA
		while(getchar()!=' ');    // stop until space
		if(i==rows-1)
			while(getchar()!= '\n');
		else
			while(getchar()!= ' ');			
		
	}

	
	int start, end;
	for(int j = 0; j< test_rounds; j++)
	{
		scanf("%d%d\n", &start, &end);
		if(start==1)
		{
			printf("%d\n", garbage_count[end-1]);
		}
		else
		{
			printf("%ld\n", garbage_count[end-1]-garbage_count[start-2]);
		}

	}

	free(garbage_count);
	return 0;
}
