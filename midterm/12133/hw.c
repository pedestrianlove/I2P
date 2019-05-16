#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str_a[100001], str_b[100001];
// For debugging purpose
void report(char* a, char* b)
{
	printf("Comparing %s and %s ...\n", a, b);
}
int compare(char* str_a, char* str_b)
{
	// Check if completely same
	if(strcmp(str_a, str_b)==0)
		return 1;
	// Or it must me Even
	if(strlen(str_a)%2)
		return 0;
	else{
		// Check if follow the special rule
		char* str_a_1 = malloc(sizeof(char)*((strlen(str_a)/2)+1));
		char* str_a_2 = malloc(sizeof(char)*((strlen(str_a)/2)+1));
		char* str_b_1 = malloc(sizeof(char)*((strlen(str_b)/2)+1));
		char* str_b_2 = malloc(sizeof(char)*((strlen(str_b)/2)+1));
		
		memcpy(str_a_1, str_a, strlen(str_a)/2);
		memcpy(str_a_2, str_a+strlen(str_a_1), strlen(str_a_1));
		memcpy(str_b_1, str_b, strlen(str_b)/2);
		memcpy(str_b_2, str_b+strlen(str_b_1), strlen(str_b_1));

		// Direct split compare or cross compare
		if((compare(str_a_1, str_b_1) && compare(str_a_2, str_b_2)) ||
				(compare(str_a_1, str_b_2) && compare(str_b_1, str_a_2)))
			return 1;
		else
			return 0;

		free(str_a_1);
		free(str_a_2);
		free(str_b_1);
		free(str_b_2);
	}
}

int main()
{
	// Input 2 strings
	scanf("%s%s", str_a, str_b);
	if(strlen(str_a)==strlen(str_b)){
		if(compare(str_a, str_b))
			printf("YES\n");
		else
			printf("NO\n");
	}else
		printf("NO\n");
	return 0;
}
