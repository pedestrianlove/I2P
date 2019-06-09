#include<stdio.h>
#include<stdlib.h>

int* COUNT;
char* CHAR;

int knuckles ()
{
	int inputs;
	scanf("%d", &inputs);

	CHAR = malloc (sizeof(char) * (inputs+1));
	scanf("%s", CHAR);

	COUNT = malloc (sizeof(int) * 26);
	for (int i = 0; i < inputs; i++)
		COUNT[i] = 0;
	for (int i = 0; i < inputs; i++) {
		COUNT[CHAR[i] - 'a'] ++;	
		if (COUNT[CHAR[i] - 'a'] >= 2) 
			return 1;
	}
	
	return 0;
	
}




int main()
{
	if (knuckles ())
		printf("I'm the god of Knuckles!\n");
	else
		printf("Different makes perfect\n");

	free (CHAR);
	free (COUNT);
	return 0;
}
