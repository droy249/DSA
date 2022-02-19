/* 
1. You are given a number n, representing the number of rows and columns of a square matrix.
2. You are given n * n numbers, representing elements of 2d array a.
3. You are required to diagonally traverse the upper half of the matrix and print the contents.

Question Link: https://www.pepcoding.com/resources/online-java-foundation/2d-arrays/the_state_of_wakanda_2/topic
Video Link: https://www.youtube.com/watch?v=lvRdFCMD_Ew&list=PL-Jc9J83PIiFkOETg2Ybq-FMuJjkZSGeH&index=15
 */
#include <stdio.h>

int main(){
	// Taking input for size of matrix
	int n;
	printf("\nEnter the size of matrix: ");
	scanf("%d", &n);
	
	// Initializing matrix
	int grid[n][n];
	
	// Taking input for matrix
	printf("\nEnter the elements of matrix:\n");
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &grid[i][j]);
	
	// Final Output
	printf("\nRequired traversal:\n");
	int diff = 0;
	do
		for(int i = 0; i + diff < n; ++i)
			printf("%d ", grid[i][i + diff]);
	while(diff++ < n);

	printf("\n");
}