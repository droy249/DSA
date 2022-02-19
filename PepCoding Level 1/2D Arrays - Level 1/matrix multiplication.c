/* Program to multiply two matrices
Time Complexity: O(n^3)
Space Complexity: O(1)
 */
#include <stdio.h>

int main(void){
	printf("*****************MATRIX MULTIPLICATION*****************\n");
	
	// Taking input for size of first matrix
	int row1, col1;
	printf("\nEnter the number of rows and columns of first matrix: ");
	scanf("%d %d", &row1, &col1);
	
	// Initializing first matrix
	int one[row1][col1];
	
	// Taking input for first matrix
	printf("\nEnter the elements of first matrix:\n");
	for(int i = 0; i < row1; ++i)
		for(int j = 0; j < col1; ++j)
			scanf("%d", &one[i][j]);
	
	// Taking input for size of second matrix
	int row2, col2;
	printf("\nEnter the number of rows and columns of second matrix: ");
	scanf("%d %d", &row2, &col2);
	
	// Initializing second matrix
	int two[row2][col2];
	
	// Taking input for second matrix
	printf("\nEnter the elements of second matrix:\n");
	for(int i = 0; i < row2; ++i)
		for(int j = 0; j < col2; ++j)
			scanf("%d", &two[i][j]);
	
	// For invalid input
	if(col1 != row2) {
		printf("\nInvalid input\n");
		return 0;
	}
	
	// Initializing product matrix
	int prod[row1][col2];
	
	// Performing matrix multiplication
	for(int i = 0; i < row1; ++i)
		for(int j = 0; j < col2; ++j){
			prod[i][j] = 0;
			for(int k = 0; k < row2 /*or col1*/; ++k)
				prod[i][j] += one[i][k] * two[k][j];
		}
	
	// Printing final answer
	printf("\nResultant matrix:\n");
	for(int i = 0; i < row1; ++i)
		for(int j = 0; j < col2; ++j)
			printf("%d%c", prod[i][j], j == col2 - 1 ? '\n' : ' ');
}