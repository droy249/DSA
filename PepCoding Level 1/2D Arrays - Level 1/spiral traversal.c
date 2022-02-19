/* Write a program to traverse a matrix like a spiral
 */
#include <stdio.h>

int main(void){
	printf("*****************SPIRAL TRAVERSAL*****************\n");
	
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
	printf("\nSpiral traversal of given matrix:\n");
	int minRow = 0, minCol = 0, maxRow = row - 1, maxCol = col - 1;
	
	while(minRow <= maxCol && minCol <= maxCol){
		/* After traversing every wall, make sure to either incerment or decrement the "boundary", i.e. the grid coordinfate that remains unchanged.
         * min___ becomes ++, max___ becomes --
		 * This will ensure that the outer loop does not run infinitely and terminates once we reach the innermost box.
		*/
		
		// Left Wall ---> after trvaersal, do ++minCol
		for(int i = minRow, j = minCol; i <= maxRow; ++i)
			printf("%d, ", grid[i][j]);
		++minCol;
		
		// Bottom Wall ---> after traversal, do --maxRow
		for(int i = maxRow, j = minCol; j <= maxCol; ++j)
			printf("%d, ", grid[i][j]);
		--maxRow;
		
		// Right Wall ---> after traversal, do --maxCol
		for(int i = maxRow, j = maxCol; i >= minRow; --i)
			printf("%d, ", grid[i][j]);
		--maxCol;
		
		// Top Wall ---> after taversal, do ++minRow
		for(int i = minRow, j = maxCol; j >= minCol; --j)
			printf("%d, ", grid[i][j]);
		++minRow;
	}
	printf("\n");
}