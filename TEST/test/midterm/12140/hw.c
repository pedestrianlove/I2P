#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Public variables
char str[1001], sub_str[1001];
char spare[1001];

int check(int start, int end)
{
	int counter = 0;
	// set the delim
	const char* delim = sub_str;
	strcpy(spare, str);
	char* token = strtok(spare, delim);
	while(token!=NULL){
		counter++;
		token = strtok(NULL, delim);
	}
	if(counter ==0)
		return 0;
	return counter-1;
	

}

int main()
{
	// Input both strings
	scanf("%s%s", str, sub_str);

	// Get queries
	int queries;
	int start, end;
	scanf("%d", &queries);
	for(int i = 0; i< queries; i++){
		// Input start, end index
		scanf("%d%d", &start, &end);
		printf("%d\n", check(start, end));
	}


	return 0;
}
