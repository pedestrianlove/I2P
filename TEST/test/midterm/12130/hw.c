// Oh! I find de way!
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

char* check(char* str)
{
	char temp = str[0];
	char* check = malloc(3*sizeof(char));
	char other = 'E';
	
	for(int i = 1; i< strlen(str); i++){
		if(temp != str[i]){
			other = str[i];
			break;
		}
	}
	check[0] = temp;
	check[1] = other;

	free(str);
	return check;
}

int main()
{
	// Variables
	int length;
       	char* check_value;
	char* str;

	// Input and allocate space for it
	while(scanf("%d", &length)!=EOF){
		str = malloc(sizeof(char)*(length+1));
		scanf("%s", str);
		// Process the obtained string
		check_value = check(str);
		if(check_value[1]=='E')
			printf("No\n");
		else{
			printf("Yes\n");
			printf("%s\n", check_value);
		}
		free(check_value);
	}
	return 0;
}

