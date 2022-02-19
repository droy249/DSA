// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/target-sum-subsets-dp-official/ojquestion#
// Video Link: https://youtu.be/tRpkluGqINc?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
import java.util.Scanner;

class TargetSumSubsets {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter size of array: ");
		int n = scn.nextInt();
		
		System.out.println("Enter elements of array: ");
		int[] arr = new int[n];
		for(int i = 0; i < n; ++i)
			arr[i] = scn.nextInt();
		
		System.out.print("Enter target: ");
		int target = scn.nextInt();
		
		System.out.println("Does a subset of target" + target + "exist? Answer:");
		System.out.println("Recursive: " + recursive(arr, target, arr.length));
		System.out.println("Memoized: " + memoize(arr, target, arr.length, new Boolean[arr.length + 1][target + 1]));
		System.out.println("Tabulate: " + tabulate(arr, target));
		
		scn.close();
	}
	
	// public static boolean recursive(final int[] arr, int target, int index){
		// if(index == arr.length){
			// return target == 0;
		// }
		// return recursive(arr, target - arr[index], index + 1) || recursive(arr, target, index + 1);
	// }
	
	private static boolean recursive(final int[] arr, int target, int index){
		if(target == 0) return true;
		else if(index == 0) return false;
		
		if(arr[index - 1] > target)
			return recursive(arr, target, index - 1);
		else
			return recursive(arr, target - arr[index - 1], index - 1) || recursive(arr, target, index - 1);
	}
	
	/* To memoize a boolean array, use Boolean */
	private static boolean memoize(final int[] arr, int target, int index, Boolean[][] memo){
		if(target == 0) return true;
		if(index == 0) return false;
		
		if(memo[index][target] != null) return memo[index][target];
		
		if(arr[index - 1] > target)
			memo[index][target] = memoize(arr, target, index - 1, memo);
		else
			memo[index][target] = memoize(arr, target - arr[index - 1], index - 1, memo) || memoize(arr, target, index - 1, memo);
		
		return memo[index][target];
	}
	
	private static boolean tabulate(final int[] arr, final int target){
		boolean[][] dp = new boolean[arr.length + 1][target + 1];
		
		for(int i = 0; i < dp.length; ++i)
			dp[i][0] = true;
		
		for(int i = 1; i < dp.length; ++i)
			for(int j = 1; j < dp[0].length; ++j)
				if(arr[i-1] > j)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
		
		return dp[arr.length][target];
	}
}
