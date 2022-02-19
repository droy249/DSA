/* Write a program to rotate a matrix clockwise bby 90 degrees in-place.

NOTE: There are 2 ways to solve this problem.
(Detailed solution: https://leetcode.com/problems/rotate-image/solution/)
1) Swap the four corners of the matrix one after another in a clock wise fashion.
2) Perform transpose on the matrix, followed by reversing the rows.
 */
#include <stdio.h>

int main(void){
	// Taking input for size of matrix
	int row, col;
	printf("\nEnter the number of rows and columns of matrix: ");
	scanf("%d %d", &row, &col);
	
	if(row != col){
		printf("\nInvalid output\n");
		return 0;
	}
	
	// Initializing matrix
	int grid[row][col];
	
	// Taking input for matrix
	printf("\nEnter the elements of matrix:\n");
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			scanf("%d", &grid[i][j]);
	
	int n = row;
	// First way of solving problem:
	// for(int i = 0; i < n/2; ++i)
		// for(int j = 0; j < n/2; ++j){
			// int temp = grid[n - 1 - j][i];
			// grid[n - 1 - j][i] = grid[n - 1 - i][n - j - 1];
			// grid[n - 1 - i][n - j - 1] = grid[j][n - 1 -i];
			// grid[j][n - 1 - i] = grid[i][j];
			// grid[i][j] = temp;
		// }
	
	// Second way of solving: 
	
	// Step 1: Take transpose
	for(int i = 0; i < row; ++i)
        for(int j = i + 1; j < col; ++j){
            int tmp = grid[i][j];
            grid[i][j] = grid[j][i];
            grid[j][i] = tmp;
        }
	
	// Step 2: Reverse the rows of transpose
	for(int i = 0; i < row; ++i)
        for(int j = 0; j < col / 2; ++j){
            int tmp = grid[i][n - 1 - j];
            grid[i][n - 1 - j] = grid[i][j];
            grid[i][j] = tmp;
        }
	
	
	// Final Output
	printf("\nAfter rotation:\n");
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			printf("%d%c", grid[i][j], j == col - 1 ? '\n' : ' ');
}