// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/min-cost-maze-traversal-official/ojquestion
// Video Link: https://youtu.be/BzTIOsC0xWM?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/minimum-path-sum/
import java.util.*;

class MinCostInMazeTraversal {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter the number of rows and columns: ");
		int row = scn.nextInt();
		int col = scn.nextInt();
		
		System.out.println("Enter the elements of matrix: ");
		int[][] grid = new int[row][col];
		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j)
				grid[i][j] = scn.nextInt();
		
		// Refer: https://leetcode.com/problems/minimum-path-sum/discuss/344980/Java.-Details-from-Recursion-to-DP.
		System.out.println("The minimum cost of traversing from top-left to bottom-right corner is: ");
		System.out.println("Recursive: " + recursive(grid, row - 1, col - 1));
		System.out.println("Memoized: " + memoized(grid, row - 1, col - 1, new int[row + 1][col + 1]));
		System.out.println("Tabulated: " + tabulated(grid));

		scn.close();
	}
	
	// Traversing from (0,0)
	private static int recursive(int[][] grid, int row, int col){
		if(row == 0 && col == 0) return grid[row][col];
		else if(row == 0) return grid[row][col] + recursive(grid, row, col - 1);
		else if(col == 0) return grid[row][col] + recursive(grid, row - 1, col);
		else return grid[row][col] + Math.min(recursive(grid, row, col - 1), recursive(grid, row - 1, col));
	}
	
	// Traversing from (0,0)
	private static int memoized(int[][] grid, int row, int col, int[][] dp){
		if(dp[row][col] > 0) return dp[row][col];
		if(row == 0 && col == 0) dp[row][col] =  grid[row][col];
		else if(row == 0) dp[row][col] = grid[row][col] + recursive(grid, row, col - 1);
		else if(col == 0) dp[row][col] = grid[row][col] + recursive(grid, row - 1, col);
		else dp[row][col] =  grid[row][col] + Math.min(recursive(grid, row, col - 1), recursive(grid, row - 1, col));
		return dp[row][col];
	}
	
	// Traversing from (0,0)
	private static int tabulated(int[][] grid){
		for(int row = 0; row < grid.length; ++row)
			for(int col = 0; col < grid[0].length; ++col){
				if(row == 0 && col == 0) continue;
				else if(row == 0) grid[row][col] += grid[row][col-1];
				else if(col == 0) grid[row][col] += grid[row-1][col];
				else grid[row][col] += Math.min(recursive(grid, row, col - 1), recursive(grid, row - 1, col));
			}
		return grid[grid.length - 1][grid[0].length - 1];
	}
	
	/* Pepcoding approach */
	// Traversing to (0,0)
	
	// Traversing to (0,0)
	
	// Traversing to (0,0)
}
