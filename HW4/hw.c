#include "function.h"

int linear_search(int* numbers, int target)
{
	int i = 0;
	while(numbers[i] < target)
		i++;
	return i+1;
}


int BS(int *numbers, int target, int length)
{	
	int real_length = 0;
	int* ptr = numbers;
	while(ptr[real_length + length/2] != length){
		if(length < 100){
			real_length += linear_search(ptr+real_length, target);
			return real_length-1;
		}
		if(ptr[real_length + length/2] < target){
			length = length/2-1;
		}
		else{
			real_length += length/2;
			length = length - length/2;
		}
		
	}
	real_length += length/2;
	return real_length - 1;
	/*
	// Trivial case
	if(numbers[length/2-1]==target)
		return length/2;
	
	// Handle 2 parts of the array
	if(numbers[length/2-1]<target)
		return BS(numbers, target, length/2-1);
	else
		return length/2 + BS(numbers+(length/2-1)+1, target, length-length/2);
	*/
}
