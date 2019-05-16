#include<stdio.h>
#include<stdlib.h>

// Structure to store the successful games' queens' position
typedef struct GAME{
	int BOARD[8][8];	
}GAME;

// Record the influence
int BOARD[8][8] = {0};

// Record the score
int SCORE[8][8];

// Record the real time queens' position
int REAL[8][8];

// A list to retrieve successful games
GAME** game_index;
int game_counter = 0;

// USER INTERFACE
void INITIALIZE ()
{
	// Allocate the space
	GAME* new = malloc (sizeof(GAME));
	
	// INITIALIZE THE VALUE
	for (int i = 0; i < 8; i++)
		for (int j = 0; j< 8; j++)
			new -> BOARD[i][j] = REAL[i][j];
	game_index[game_counter] = new;
	game_counter ++;
}


void influence (int row, int col, int do_undo)
{
	//printf("Writing in (%d,%d)...\n", row, col);
	// DO THE STRAIGHT PART ONLY
	for (int i = 0; i< 8; i++){
		BOARD[i][col] += do_undo;
		BOARD[row][i] += do_undo;
	}
	BOARD[row][col] -= do_undo;
	
	// DO THE SLANTED PART
	for (int i = 0, j = 0; row+i < 8 && col+i < 8; i++, j++)
		BOARD[row+i][col+j] += do_undo;
	for (int i = 0, j = 0; row-i >= 0 && col-i >=0; i++,j++)
		BOARD[row-i][col-j] += do_undo;
	// Another side
	for (int i = 0, j = 0; row+i < 8 && col-i >=0; i++,j++)
		BOARD[row+i][col-j] += do_undo;
	for (int i = 0, j = 0; row-i >= 0 && col+i <8; i++,j++)
		BOARD[row-i][col+j] += do_undo;

	BOARD[row][col] -= 4*do_undo;
	// Write in the real location
	REAL[row][col] += do_undo;
}

void find_queens (int row, int col, int remain)
{
	// Write in the influence
	influence (row, col, 1);
	
	if (remain == 0){
		INITIALIZE ();
		influence (row, col, -1);
		return;
	}

	for (int i  = 0; i< 8; i++){
		if (col+1 < 8)
			if (BOARD[i][col+1] == 0){
				find_queens (i, col+1, remain-1);
			}
	}
	// Revert the influence
	influence (row, col, -1);
}

int main()
{
	int max , sum;
	int queries;

	// Have a index to retrieve qualified games easily
	game_index = malloc (92*sizeof(GAME*));
	
	// Generate the game list by recursive method
	for (int i = 0; i< 8; i++){
		if (BOARD[i][0] == 0)
			find_queens (i, 0, 8-1);
	}
	
	// Handle the queries
	scanf("%d", &queries);
	for (int i = 0; i< queries; i++){
		max = 0;
		// Input the score
		for(int row = 0; row < 8; row++)
			for (int col = 0; col < 8; col++)
				scanf("%d",&SCORE[row][col]);

		// Compute the max sum game by game
		for (int j = 0; j < 92; j++){
			sum = 0;
			// Traverse the matrix and compute the product
			for (int rows = 0; rows < 8; rows++)
				for (int cols = 0; cols < 8; cols++)
					if (game_index[j] -> BOARD[rows][cols] == 1)
						sum += SCORE[rows][cols];

			if (max < sum)
				max = sum;
		}
		printf("%d\n", max);
	}


	
	
	// Free the memory
	for ( int i = 0; i< 92; i++)
		free (game_index[i]);
	free (game_index);
	return 0;
}
