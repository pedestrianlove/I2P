#include<stdio.h>
#include<stdlib.h>

char number[100][1000];

int cmp (const void * a, const void * b)
{
	const char ** va = (const char **) a;
	const char ** vb = (const char **) b;
	int a_len = strlen(va);
	int b_len = strlen(vb);
	int min = (a_len < b_len)? 1:0;
	int n = (a_len<b_len)? a_len:b_len;
	if (a_len == b_len)
		return strcmp (vb, va);
	else
		if (n=strncmp(vb, va, n) == 0)
			if(min)
				return 1;
			else
				return -1;
		else
			if (n)
				return -1;
			else
				return 1;
}

int main()
{
	int lines;
	while (scanf("%d", &lines) != EOF) {
		// input numbers
		for (int i = 0; i< lines; i++) {
			scanf("%s", number[i]);
		}

		// sort
		qsort (number, lines, sizeof(char)*1000, cmp);
		
		// output
		for (int i = 0; i< lines; i++) 
			printf("%s", number[i]);
		printf("\n");
	}


	return 0;
}
