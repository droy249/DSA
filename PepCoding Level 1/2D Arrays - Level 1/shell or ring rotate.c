/* You are given a n*m matrix where n are the number of rows and m are the number of columns. You are also given n*m numbers representing the elements of the matrix.
You will be given a ring number 's' representing the ring of the matrix. 
You will be given a number 'r' representing number of rotations in an ANTI-CLOCKWISE MANNER of the SPECIFIED RING.
You are required to rotate the 's'th ring by 'r' rotations and display the rotated matrix.

Question Link: https://www.pepcoding.com/resources/online-java-foundation/2d-arrays/ring_rotate/topic
Video Link: https://www.youtube.com/watch?v=atMK9aA-s7Y&list=PL-Jc9J83PIiFkOETg2Ybq-FMuJjkZSGeH&index=13
Related Question: https://leetcode.com/problems/cyclically-rotating-a-grid/
 */
#include <stdio.h>

void reverseArr(int *oneD, int left, int right){
	while(left < right){
		int tmp = oneD[left];
		oneD[left] = oneD[right];
		oneD[right] = tmp;
		++left, ++right;
	}
}

int main(){
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
	
	// Taking input for shell number
	int shellNumber;
	printf("\nEnter shell number: ");
	scanf("%d", &shellNumber);
	
	// Taking input for number of rotations
	int rotations;
	printf("\nEnter number of rotations: ");
	scanf("%d", &rotations);
	
	/* Calculate number of elements in the shell, i.e. sizeof of 1D array and then fill the 1D array with elements in the shell */
	const int minRow = shellNumber - 1, minCol = shellNumber - 1, maxRow = row - shellNumber, maxCol = col - shellNumber;
	const int size = (maxRow - minRow + maxCol - minRow) / 2;
	
	// Create a temporary array to store elements from shell
	int arr[size];
	
	// Now fill up the array
	int idx = 0;
	
	//Left Wall
	for(int i = minRow, j = minCol; i <= maxRow; ++i)
		arr[idx++] = grid[i][j];
	
	// Bottom Wall
	for(int i = maxRow, j = minCol + 1; j <= maxCol; ++j)
		arr[idx++] = grid[i][j];
	
	//Right Wall
	for(int i = maxRow - 1, j = maxCol; i >= minRow; --i)
		arr[idx++] = grid[i][j];
	
	// Top Wall
	for(int i = minRow, j = maxCol - 1; j >= minCol - 1; --j)
		arr[idx++] = grid[i][j];
	
	// Now we shall rotate the array 'r' number of times in anticlockwise direction
	rotations %= size;									// To avoid unnecesarry cycles, take modulus of 'r' with 'n' so that 0 <= r < n
	if(rotations < 0) rotations += size;						// To convert negative rotations to positive number
	
	// Reversing the array
	reverseArr(arr, 0, size - 1 - rotations);
	reverseArr(arr, size - rotations, size - 1);
	reverseArr(arr, 0, size - 1);
	
	// Now fill up the shell
	idx = 0;
	
	//Left Wall
	for(int i = minRow, j = minCol; i <= maxRow; ++i)
		grid[i][j] = arr[idx++];
	
	// Bottom Wall
	for(int i = maxRow, j = minCol + 1; j <= maxCol; ++j)
		grid[i][j] = arr[idx++];
	
	//Right Wall
	for(int i = maxRow - 1, j = maxCol; i >= minRow; --i)
		grid[i][j] = arr[idx++];
	
	// Top Wall
	for(int i = minRow, j = maxCol - 1; j >= minCol - 1; --j)
		grid[i][j] = arr[idx++];
	
	// Display final output
	printf("\nEnter the elements of matrix:\n");
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			printf("%d%c", grid[i][j], j == col - 1 ? '\n' : ' ');
}