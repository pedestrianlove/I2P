void max_pooling (int A[500][500], int H, int W, int k)
{
	// H = row, W = col
	int max;
	// Find pt for every partition
	//printf("H/k = %d, W/k = %d",H/k, W/k );
	for(int pt_row = 0; pt_row < (H/k); pt_row ++){
		for (int pt_col = 0; pt_col < (W/k); pt_col++){
			// For every submatrix, find max
			max = A[pt_row*k][pt_col*k];
			for (int row = pt_row * k; row < (pt_row*k + k); row++){
				for (int col = pt_col*k; col< (pt_col*k + k); col++){
					printf("%d ", A[row][col]);
					if (max < A[row][col]){
						max = A[row][col];
					}
				}
				printf("\n");
			}
			printf("\n");
			A[pt_row][pt_col] = max;

		}
	}	



}
