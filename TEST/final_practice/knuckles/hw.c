#include<stdio.h>
#include<stdlib.h>

int* COUNT;

int knuckles () // FIXME UNKNOWN ISSUE
{
	int length;
	scanf("%d", &length);
	if (length == 1)
		return 1;


	COUNT = malloc (sizeof(int) * 26);
	for (int i = 0; i < 26; i++)
		COUNT[i] = 0;

	char CHAR;
	while (scanf(" %c", &CHAR) != EOF) { 
		COUNT[CHAR - 'a'] ++;	
		if (COUNT[CHAR - 'a'] >= 2) 
			return 1;
		COUNTER++;
	}

	return 0;
}




int main()
{
	if (knuckles ())
		printf("I'm the god of Knuckles!\n");
	else
		printf("Different makes perfect\n");

	free (COUNT);
	return 0;
}
