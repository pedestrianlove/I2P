#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *a = malloc (sizeof(int)*1000);
	a[9][80] = 10;
	printf("%d\n", a[9][80]);
	return 0;
}
