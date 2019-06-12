#include<stdio.h>
#include<stdlib.h>

int INFLUENCE[1000][1000] = {0};
char MAP[1000][1000];
int COUNTER = 0;
int ROW, COL;
// interface
void find_ponds (int row, int col);

int main()
{
	// input dimension
	scanf("%d%d", &ROW, &COL);

	// input the map
	
	for (int i = 0; i< ROW; i++) {
		for (int j = 0; j < COL; j++)
			scanf(" %c", &MAP[i][j]);
	}


	// count the pond
	for (int i = 0; i< ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (MAP[i][j] == '~') {
				if (INFLUENCE[i][j] == 0) {
					COUNTER ++;
					//printf("Currently at point (%d, %d), influence is %d, COUNTER is now %d\n", i, j, INFLUENCE[i][j], COUNTER);
					find_ponds (i, j);
				}
			}

		}
	}



	// output the counter
	printf("%d\n", COUNTER);
	return 0;
}

void find_ponds (int row, int col)
{
	//printf("Finding ponds at (%d,%d)\n", row, col);
	// Write in the influence itself
	INFLUENCE[row][col] = 1;
	// Spread the influence
	if (row + 1 < ROW && MAP[row+1][col] == '~' && INFLUENCE[row+1][col] == 0) 
		find_ponds (row+1, col);
	if (row - 1 >= 0 && MAP[row-1][col] == '~' && INFLUENCE[row-1][col] == 0)
		find_ponds (row-1, col);
	if (col + 1 < COL && MAP[row][col+1] == '~' && INFLUENCE[row][col+1]==0)
		find_ponds (row, col+1);
	if (col - 1 >= 0 && MAP[row][col-1] == '~' && INFLUENCE[row][col-1]==0)
		find_ponds (row, col-1);
}
