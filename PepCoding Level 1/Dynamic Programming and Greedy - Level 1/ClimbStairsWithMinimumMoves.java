// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-minimum-moves-official/ojquestion
// Video Link: https://youtu.be/Zobz9BXpwYE?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode link: https://leetcode.com/problems/jump-game-ii/
import java.util.Scanner;

class ClimbStairsWithMinimumMoves {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter size of staircase: ");
		int n = scn.nextInt();
		
		System.out.println("Enter no of moves for each step: ");
		int[] steps = new int[n];
		for(int i = 0; i < n; ++i)
			steps[i] = scn.nextInt();
		
		int[] dp = new int[n+1];
		dp[n] = 0;
		for(int i = n - 1; i >= 0; --i){
			int min = Integer.MAX_VALUE;
			if(steps[i] > 0)
				for(int j = 1; j <= steps[i] && i + j <= n; ++j)
					min = Math.min(min, dp[i+j]);
			
			if(min != Integer.MAX_VALUE)
				dp[i] = min + 1;
		}
		
		// /* PepCoding used Integer in video (why?)*/
		// Integer[] dp = new Integer[n+1];
		// dp[n] = 0;
		// for(int i = n - 1; i >= 0; --i){
			// int min = Integer.MAX_VALUE;
			// if(steps[i] > 0)
				// for(int j = 1; j <= steps[i] && i + j <= n; ++j)
					// min = Math.min(min, dp[i+j]);
			
			// if(min != Integer.MAX_VALUE)
				// dp[i] = min + 1;
		// }
		
		System.out.println("Minimum number of moves to cover " + n + " steps are: " + dp[0]);

		scn.close();
	}
}