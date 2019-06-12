#include<stdio.h>
#include<stdlib.h>
#define DO 1
#define UNDO -1
#define QUEEN 1
#define ROOK 0

// Global
int BOARD[12][12] = {0}; // Record the influence by stacking up the scalars
int REAL[12][12] = {0};
int size;
int COUNTER = 0;

// DEBUG
void print_the_board (int size)
{
	for (int rows = 0; rows < size; rows++){
		for(int cols = 0; cols < size; cols++)
				printf ("%5d ", BOARD[rows][cols]);
		printf("\n");
	}
	printf("\n");
}

// Internal
int avoid_queen (int row, int col)
{
	// (row, col) to (size,size)
	for (int i = row, j = col ; i < size && j < size ; i++, j++){
		if (REAL[i][j] == 1)
			return 0;
	}
	// (row, col) to (0, 0)
	for (int i = row, j = col ; i >= 0 && j >= 0 ; i--, j--){
		if (REAL[i][j] == 1)
			return 0;
	}
	// (row, col) to (0,size)
	for (int i = row, j = col ; i >= 0 && j < size ; i--, j++){
		if (REAL[i][j] == 1)
			return 0;
	}
	// (row, col) to (size, 0)
	for (int i = row, j = col ; i < size && j >= 0 ; i++, j--){
		if (REAL[i][j] == 1)
			return 0;
	}
		
	return 1;
}
void influence (int row, int col, int queen_or_rook, int do_undo)
{
	//printf("%d in %d at (%d,%d)\n", do_undo,queen_or_rook, row, col);
	// Record the actual location
	REAL[row][col] += do_undo;
	// Do the straight part first
	for (int i = 0; i< size ; i++){
		BOARD[row][i] += do_undo;
		BOARD[i][col] += do_undo;
	}
	BOARD[row][col] -= do_undo;
	
	// If Queen, Do the slanted part
	if (queen_or_rook == QUEEN){
		// (row, col) to (size,size)
		for (int i = row, j = col ; i < size && j < size ; i++, j++){
			BOARD[i][j] += do_undo;
		}
		// (row, col) to (0, 0)
		for (int i = row, j = col ; i >= 0 && j >= 0 ; i--, j--){
			BOARD[i][j] += do_undo;
		}
		// (row, col) to (0,size)
		for (int i = row, j = col ; i >= 0 && j < size ; i--, j++){
			BOARD[i][j] += do_undo;
		}
		// (row, col) to (size, 0)
		for (int i = row, j = col ; i < size && j >= 0 ; i++, j--){
			BOARD[i][j] += do_undo;
		}
		
		BOARD[row][col] = BOARD[row][col] -4*do_undo;
	}
	//print_the_board (size);
}

// User
void FIND_QUEEN (int row, int col, int queen, int castle, int rook_or_queen)
{
	// Check the remaining number of queens and castles
	if (queen < 0 || castle < 0)
		return;
	if (queen == 0 && castle ==0){
		//printf("Solution found!\n");
		//print_the_board(size);
		COUNTER++;
		return;
	}

	// Write in the current influence
	influence (row, col, rook_or_queen, 1);
		
	// Traverse along the tree	
	for (int i = 0; i < size ; i++) {
		if (BOARD[i][col+1] == 0 && (col+1)<size) {
			FIND_QUEEN (i, col+1, queen, castle-1, ROOK);
			if (avoid_queen(i, col+1))
				FIND_QUEEN (i, col+1, queen-1, castle, QUEEN);
		}
	}

	// Revert the caused influence and return
	influence (row, col, rook_or_queen, -1);
	return;
}


int main()
{
	// Input
	int queens, castles;
	scanf ("%d%d", &queens, &castles);
	// Record the whole matrix size
	size = queens + castles;

	// Search for the solution and count
	for (int row = 0; row < size; row++) {
		FIND_QUEEN (row, 0, queens-1, castles, QUEEN);
		FIND_QUEEN (row, 0, queens, castles-1, ROOK);
	}
/*
	for (int i= 0; i< size; i++)
		for (int j = 0; j< size; j++){
			influence (i, j, QUEEN, 1);
			influence (i, j, QUEEN, -1);
		}
*/
	// Output the outcome
	printf("%d\n", COUNTER);

	return 0;
}
