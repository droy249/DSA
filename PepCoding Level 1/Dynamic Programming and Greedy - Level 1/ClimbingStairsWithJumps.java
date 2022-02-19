// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-variable-jumps-official/ojquestion
// Video Link: https://youtu.be/uNqoQ0sNZCM?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
import java.util.Scanner;

class ClimbingStairsWithJumps {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter size of staircase: ");
		int n = scn.nextInt();
		
		System.out.println("Enter elements of the array:");
		int[] steps = new int[n];
		for(int i = 0; i < n; ++i)
			steps[i] = scn.nextInt();
		
		System.out.println("All possible number of ways are: ");
		System.out.println("Recursive: " + recursive(steps));
		System.out.println("Memoized: " + memoization(steps, new int[n+1]));
		System.out.println("Tabulated: " + tabulation(steps));

		scn.close();
	}
	
	private static int recursive(int[] steps){
		return 0;
	}
	
	private static int memoization(int[] steps, int[] dp){
		return 0;
	}
	
	private static int tabulation(int[] steps){
		int n = steps.length;
		int[] dp = new int[n+1];
		dp[n] = 1;
		
		for(int i = n-1; i >= 0; --i)
			for(int j = 1; j <= steps[i] && i + j <= n; ++j)
				dp[i] += dp[i+j];
		
		return dp[0];
	}
}
