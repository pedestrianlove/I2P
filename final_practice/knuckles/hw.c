#include<stdio.h>
#include<stdlib.h>

int knuckles ()
{
	int inputs;
	scanf("%d", &inputs);

	char* CHAR = malloc (sizeof(char) * (inputs+1));
	scanf("%s", CHAR);

	int* COUNT = malloc (sizeof(int) * 26);
	for (int i = 0; i < inputs; i++)
		COUNT[i] = 0;
	int i;
	for ( i = 0; i < inputs; i++) {
		COUNT[CHAR[i] - 'a'] ++;	
		if (COUNT[CHAR[i] - 'a'] >= 2)
			break;
	}

	if (COUNT[CHAR[i] - 'a' >= 2])
		return 1;
	else 
		return 0;
}




int main()
{
	if (knuckles ())
		printf("I'm the god of Knuckles!\n");
	else
		printf("Different makes perfect\n");

	return 0;
}
