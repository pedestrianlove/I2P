#include<stdio.h>
#include<stdlib.h>
// PUBLIC DATA
void dec2bin(int);
int* bin;
int main()
{
	int dec;
	scanf("%d", &dec);
	bin = malloc(sizeof(int)*dec);
	dec2bin(dec);
	
	return 0;
}

void dec2bin(int dec)
{
	if(dec%2==0){
		dec2bin(dec/2);
		printf("0");	
	}
	else{
		dec2bin((dec-1)/2);
		printf("1");
	}
}
