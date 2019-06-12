#include<stdio.h>
#include<stdlib.h>

unsigned long long remainders (unsigned long long a,unsigned long long b,unsigned long long n)
{
	unsigned long long product = 1;
	a%=n;
	while(b>0){
		if(b%2)
			product = ((product%n)*(a%n)) %n;
		b /= 2;
		a = ((a%n)*(a%n))%n;	
	}
	return product;
}




int main()
{
	unsigned long long a, b;
	unsigned long long product;
	unsigned long long n;
	
	scanf("%lld%lld%lld", &a, &b, &n);
	unsigned long long c = a%n;
	
	product = remainders(c, b, n);	
	product = product % n;
	printf("%lld\n", product);
	return 0;
}
