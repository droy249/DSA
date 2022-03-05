// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/matrix-chain-multiplication-official/ojquestion
// Video Link: https://youtu.be/pEYwLmGJcvs?list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG
import java.util.*;
<<<<<<< HEAD
=======
import java.lang.*;
import java.io.*;
>>>>>>> origin/main

class MatrixChainMultiplication {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter size of array containing dimensions: ");
		int n = scn.nextInt();
		
		System.out.println("Enter dimensions of matrices: ");
		int[] dimensions = new int[n];
		
<<<<<<< HEAD
		for (int i = 0; i < dimensions.length; i++) {
			dimensions[i] = scn.nextInt();
		}
		
		int minNumberOfMultiplications = tabulate(dimensions);
		scn.close();
=======
		for(int dimension : dimensions)
			dimension = scn.nextInt();
		
		int minNumberOfMultiplications = tabulate(dimensions);
>>>>>>> origin/main
	}
	
	private static int tabulate(int[] dimensions){
		int dp[][] = new int[dimensions.length - 1][dimensions.length - 1];
		
		for(int gap = 0; gap < dp.length; ++gap){
			for(int i = 0, j = gap; j < dp.length; ++i, ++j){
				if(gap == 0)
					dp[i][j] = 0;
				else if(gap == 1)
			}
		}
		
		return dp[0][dp.length - 1];
	}
}
