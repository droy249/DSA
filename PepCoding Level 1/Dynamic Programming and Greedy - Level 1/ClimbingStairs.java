// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-official/ojquestion
// Video Link: https://youtu.be/A6mOASLl2Dg?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode link: https://leetcode.com/problems/climbing-stairs/
// Alt leetcode link: https://leetcode.com/problems/n-th-tribonacci-number/
import java.util.Scanner;

class ClimbingStairs {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);

		System.out.print("Enter size of staircase: ");
		int n = scn.nextInt();
		
		System.out.println("Possible number of ways to climb " + n + " steps are: ");
		System.out.println("Recursive: " + recursizeCountWays(n));
		System.out.println("Memoized: " + memoizeCountWays(n, new int[n+1]));
		System.out.println("Tabulated: " + tabulateCountWays(n));
		System.out.println("Optimized: " + optimizedCountWays(n));
		System.out.println("Further optimized: " + furtherOptimizedCountWays(n));
		System.out.println("Matrix multiplication: " + matrixMultiplicationCountWays(n));

		scn.close();
	}
	
	/* Approach 1: Recursion */
	private static int recursizeCountWays(int n) {
        if(n < 0) return 0;
		else if(n == 0 || n == 1) return 1;
		else if(n == 2) return 2;
		else return recursizeCountWays(n-1) + recursizeCountWays(n-2) + recursizeCountWays(n-3);
		// return n < 0 ? 0 : n < 2 ? n == 2 ? 2 : recursizeCountWays(n-1) + recursizeCountWays(n-2) + recursizeCountWays(n-3);		// Doesn't work
    }
	
	/* Approach 2: Memoization */
	private static int memoizeCountWays(int n, int[] steps){
		if(n < 0) return 0;
		else if(n == 0) return 1;
		
		if(steps[n] > 0) return steps[n];
		
		steps[n] = memoizeCountWays(n-1, steps) + memoizeCountWays(n-2, steps) + memoizeCountWays(n-3, steps);
		
		return steps[n];
		// return steps[n] = n < 0 ? 0 : n < 2 ? 1 : n == 2 ? 2 : steps[n-1] + steps[n-2] + steps[n-3];								// Doesn't work
	}
	
	/* Approach 3: Tabulation */
	private static int tabulateCountWays(final int n){
		int[] steps = new int[n + 1];
		
		steps[0] = 1; steps[1] = 1; steps[2] = 2;
		for(int i = 3; i <= n; ++i)
			steps[i] = steps[i-1] + steps[i-2] + steps[i-3];
		
		// /* PepCoding Approach */
		// for(int i = 0; i <= n; ++i){
			// if(i == 0)
				// steps[i] = 1;
			// else if(i == 1)
				// steps[i] = steps[i-1];
			// else if(i == 2)
				// steps[i] = steps[i-1] + steps[i-2];
			// else
				// steps[i] = steps[i-1] + steps[i-2] + steps[i-3];
		// }
		
		return steps[n];
	}
	
	/* Approach 4: Space Optimized No. 1*/
	private static int optimizedCountWays(final int n){
		int a = 1, b = 1, c = 2, d;
		for(int i = 0; i < n - 2; ++i){
			d = a + b + c;
			a = b;
			b = c;
			c = d;
		}
		return c;
	}
	
	/* Approach 5: Space Optimized No. 2 
	Reference Link: https://leetcode.com/problems/n-th-tribonacci-number/discuss/345236/JavaC%2B%2BPython-Easy-and-Concise#:~:text=Suggested%20by%20%40modusV-,Java,-%3A */
	private static int furtherOptimizedCountWays(final int n){
		int dp[] = {1, 1, 2};
        for (int i = 3; i <= n; ++i)
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        return dp[n % 3];
	}
	
	/* Approach 6: Matrix multiplication 
	Reference Link: https://leetcode.com/problems/n-th-tribonacci-number/discuss/1482728/C%2B%2BPython-2-solutions%3A-DP-Matrix-exponential-Picture-explained-Clean-and-Concise#:~:text=%E2%9C%94%EF%B8%8F%20Solution%202%3A-,Matrix%20exponential,-This%20problem%20is */
	private static int matrixMultiplicationCountWays(final int n) {
		return 0;
	}
	
}