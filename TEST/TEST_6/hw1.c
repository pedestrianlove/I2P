#include<stdio.h>
#include<stdlib.h>

int Fib (int number)
{
	if (number == 1 || number == 2)
		return 1;
	else
		return Fib(number-1) + Fib (number-2);
}


int main ()
{
	int number;
	while (scanf("%d", &number) != EOF) {
		printf("%d\n", Fib (number));
	}



	return 0;
}
