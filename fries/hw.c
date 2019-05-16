#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void PRINT(long* seq, int length)
{
	for(int i = 0; i< length; i++)
		printf("%ld ", seq[i]);

	printf("\n");
}
long* shifter(long* seq, int shift, int length)
{
	int half = length-shift;
	long* seq_temp = malloc(sizeof(long)*length);
	memcpy(seq_temp,seq+shift, half*8);
	memcpy(seq_temp+half, seq, shift*8);
	free(seq);
	return seq_temp;
}

int main()
{
	// get the variables
	int length, shift, queries;
	scanf("%d%d%d", &length, &shift, &queries);
	
	// GET THE SEQUENCE
	long* sequence = malloc(sizeof(long)*length);
	for(int i = 0; i< length ; i++)
		scanf("%ld", &sequence[i]);
	
	// SHIFT THE SEQUENCE
	sequence = shifter(sequence, shift, length);

	PRINT(sequence, length);

	// GET THE QUERIES
	long target, max = -1, ref;
	int max_index = -1;
	for(int i = 0; i< queries; i++){
		scanf("%ld", &target);
		for(int j = 0 ; j< length; j++){
			if(sequence[j]>target){
				if(max==-1){
					max = sequence[j];
					max_index = j;
					continue;
				}
				if(sequence[j]<max)
					max = sequence[j];
			}
		}
		if(max == -1 ){
			printf("gan ni nya sai bau\n");
		}
		else
			printf("%d\n", max_index);
		
	}

	
	free(sequence);
	return 0;
}
