#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
	char str[1001];
}string;

// global
string* LIST;

// internal
int cmp (const void * a, const void * b) 
{
	const string * va = (const string *) a;
	const string * vb = (const string *) b;
	return strcmp (va -> str, vb->str);
}

// interface
int Check_substr (string sub_str, string str);

int main ()
{
	int n;
	scanf("%d", &n);

	LIST = malloc (sizeof(string) * n);
	for (int i = 0; i < n; i++)
		scanf("%s", LIST[i].str);

	qsort (LIST, n, sizeof(string), cmp);


	for (int i = 0; i < n-1; i++) {
		if (!Check_substr (LIST[i], LIST[i+1])) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", LIST[i].str);

	free (LIST);
	return 0;
}


int Check_substr (string sub_str, string str)
{
	int n = strlen (sub_str.str);
	char* SUB_STR = sub_str.str;
	char* STR = str.str;

	//printf("Comparing %s and %s...", STR, SUB_STR);
	for (int i = 0; i < strlen(STR) - n + 1; i++) {
		if (strncmp (STR + i, SUB_STR, n) == 0) {
			//printf("SUCCESS\n");
			return 1;
		}
	}
	//printf("Failed\n");
	return 0;

}
