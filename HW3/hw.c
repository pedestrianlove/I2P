#include<stdio.h>
#include<stdlib.h>

int gcd(int x, int y); // x>y 
int find_gcd(int* sugar, int index_number); // RETURN GCD
int main()
{
	int number_of_brothers;
	scanf("%d", &number_of_brothers);

	int* amount_of_sugar;
	amount_of_sugar = (int*) malloc(number_of_brothers*sizeof(int));
	
	// INPUT MAIN DATA
	for(int i = 0; i < number_of_brothers; i++){
		scanf("%d", &amount_of_sugar[i]);
	}
	
	// PROCESS AND OUTPUT THE ASSIGNED
	printf("%d\n", find_gcd(amount_of_sugar, number_of_brothers));

	// MISCELLANEOUS
	free(amount_of_sugar);
	return 0;
}


int gcd(int x, int y) // x > y
{
	if(x%y == 0)
		return y;
	return gcd(y, x%y);
}

int find_gcd(int* sugar, int index_number)
{
	int max_gcd = 1, temp;
	for(int i = 0; i< index_number; i++)
		for(int j = 0; j<index_number; j++)
			if(i!=j){
				temp = gcd(sugar[i], sugar[j]);
				if(max_gcd < temp)
					max_gcd = temp;
				//printf("%d %d\n", temp, max_gcd);
			}	
	return max_gcd;	
}
