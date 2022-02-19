// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/coin-change-permutations-official/ojquestion
// Video Link: https://youtu.be/yc0LunmJA1A?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/combination-sum-iv/
import java.util.Scanner;

class CoinChangePermutation {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter number of coin denominations: ");
		int n = scn.nextInt();
		
		System.out.print("Enter coin denominations: ");
		int[] coins = new int[n];
		for(int i = 0; i < n; ++i)
			coins[i] = scn.nextInt();
		
		System.out.print("Enter amount: ");
		int amount = scn.nextInt();
		
		System.out.println("Total number of possible permutations: ");
		System.out.println("Recursive: " + recursive(coins, amount, n));
		System.out.println("Memoized: " + memoize(coins, amount, n, new Integer[n+1][amount+1]));
		System.out.println("Tabulated: " + tabulate(coins, amount));
		System.out.println("Optimized: " + tabulateOptimized(coins, amount));

		scn.close();
	}
	
	private static int recursive(final int[] coins, int amount, int index){
		if(amount == 0) return 1;
		if(index == 0) return 0;
		
		if(coins[index - 1] <= amount)
			return recursive(coins, amount, index - 1) + recursive(coins, amount - coins[index - 1], index);
		else
			return recursive(coins, amount, index - 1);
	}
	
	private static int memoize(final int[] coins, int amount, int index, Integer[][] memo){
		return 0;
	}
	
	private static int tabulate(final int[] coins, final int amount){
		int[][] dp = new int[coins.length + 1][amount + 1];
		
		for(int i = 0; i < dp.length; ++i)
			dp[i][0] = 1;
		
		for(int j = 1; j < dp[0].length; ++j)
			for(int i = 1; i <= dp.length; ++i)
				if(coins[i-1] <= j)
					dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
				else
					dp[i][j] = dp[i-1][j];
		
		return dp[coins.length][amount];
	}
	
	private static int tabulateOptimized(final int[] coins, final int amount){
		int[] dp = new int[amount + 1];
		dp[0] = 1;
		
		for(int i = 1; i <= amount; ++i)
			for(int coin : coins)
				if(coin <= i)
					dp[i] += dp[i - coin];
		
		return dp[amount];
	}
}
