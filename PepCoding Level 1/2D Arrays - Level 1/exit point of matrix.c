/* Write program to find exit point of a boolean matrix, where 0 represents to move forwas and 1 represents turning right

Probem Link: https://practice.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1
Video Link: https://www.youtube.com/watch?v=FUBlb360kqU&list=PL-Jc9J83PIiFkOETg2Ybq-FMuJjkZSGeH&index=9
*/
#include <stdio.h>

int main(void){
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
	
	// For direction: 0 -> East, 1 -> South, 2 -> West, 3 -> North
	int dir = 0;
	
	// Coordinates for grid
	int i = 0, j = 0;
	
	// Calculating answer
	while(i != row && j != col){
		dir = (dir + grid[i][j]) % 4;
		
		if(dir == 0) ++j;
		else if(dir == 1) ++i;
		else if(dir == 2) --j;
		else if(dir == 3) --i;
		
		if(i < 0){
			++i;
			break;
		} 
		else if(j < 0){
			++j;
			break;
		}
		else if(i == row){
			--i;
			break;
		}		
		else if(j == col) {
			--j;
			break;
		}
	}
	
	// Final answer
	printf("\nExit point: (%d,%d)\n", i, j);
}