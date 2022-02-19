/* Write a program to traverse a matrix like a wave
 */
#include <stdio.h>

int main(void){
	printf("*****************WAVE TRAVERSAL*****************\n");
	
	// Taking input for size of matrix
	int row, col;
	printf("\nEnter the number of rows and columns of matrix: ");
	scanf("%d %d", &row, &col);
	
	// Initializing matrix
	int grid[row][col];
	
	// Taking input for matrix
	printf("\nEnter the elements of matrix:\n");
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			scanf("%d", &grid[i][j]);
	
	// Final output
	printf("\nWave traversal of given matrix:\n");
	for(int i = 0; i < col; ++i)
		if(i & 1)
			for(int j = row - 1; ~j; --j)
				printf("%d ", grid[j][i]);
		else 
			for(int j = 0; j < row; ++j)
				printf("%d ", grid[j][i]);
	
	printf("\n");
}