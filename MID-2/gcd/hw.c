#include<stdio.h>
#include<stdlib.h>

int gcd (int a, int b) // a > b
{
	if (a < b)
		return gcd(b, a);
	else
		if (a == b || a ==0 || b==0)
			return a;
		else
			return gcd(b, a%b);
}


int main()
{
	int queries, a, b;

	scanf("%d", &queries);
	for (int i = 0; i< queries; i++){
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
