#include<stdio.h>
#include<stdlib.h>

int BOARD[20][20] = {0};
int castles;
int COUNTER = 0;
void print ()
{
	printf("\n");
	for (int i = 0; i< castles; i++){
		for (int j = 0; j<castles; j++)
			printf("%3d ", BOARD[i][j]);
		printf("\n");
	}

}

void influence (int row, int col, int do_undo)
{
	//printf("Writing in (%d,%d)...\n", row, col);
	// DO THE STRAIGHT PART ONLY
	for (int i = 0; i< castles; i++){
		BOARD[i][col] += do_undo;
		BOARD[row][i] += do_undo;
	}
	BOARD[row][col] -= do_undo;
	//print ();
}

void find_castles (int row, int col, int remain)
{
	if (remain == 0)
		COUNTER ++;
	// Write in the influence
	influence (row, col, 1);

	for (int i  = 0; i< castles; i++){
		if (col+1 < castles)
			if (BOARD[i][col+1] == 0){
				find_castles (i, col+1, remain-1);
			}
	}
	// revert the influence
	influence (row, col, -1);
}

int main()
{
	int broken;
	int row, col;
	scanf("%d%d", &castles, &broken);
	for (int i = 0; i< broken; i++){
		scanf("%d%d", &row, &col);
		//printf("(%d,%d) is broken \n", row, col);
		BOARD[row][col] += 1;
	}



	// Process the recursive part
	for (int i = 0; i< castles; i++){
		if (BOARD[i][0] == 0)
			find_castles (i, 0, castles-1);
	}


	printf("%d\n", COUNTER);

}
