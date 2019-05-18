#include<stdio.h>
#include<stdlib.h>

int main()
{
	int conv;
	int output[32] = {0};
	float num;
	while(scanf("%f", &num) != EOF){
		if (num < 0){
			num = -num;
			output[0] = 1;
		}
		else
			output[0] = 0;
		conv = *(int*)&num;
		for ( int i= 31; i >0; i--) {
			output[i] = conv%2;
			conv = conv/2;
		}


		for(int i= 0; i< 32; i++)
			printf("%d", output[i]);
		printf("\n");
	}


	return 0;
}
