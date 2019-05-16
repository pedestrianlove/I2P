#define MAX_N 103
int solve(int *n, int *k, int *sputum, int (*spell)[MAX_N])
{	
	// Return 0 if failed, else return 1
	int counter;
	for (int rows = 0; rows < *n; rows++)
		for (int cols = 0 ; cols < *n; cols++){
			counter = 0;
			if (spell[rows][cols]==0)
				continue;
			while (spell[rows][cols] > sputum[counter]){
				counter ++;
				if (counter == *k)
					return 0;
			}
			sputum[counter] = 0;
		}
	return 1;
}

