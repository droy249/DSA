// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/maximum-sum-non-adjacent-elements-official/ojquestion
// Video Link: https://youtu.be/VT4bZV24QNo?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Gfg Link: https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
// Leetcode Link: https://leetcode.com/problems/delete-and-earn/
import java.util.Scanner;

public class MaximumSumNonAdjacentElements {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        System.out.print("Enter size of array: ");
        int n = scn.nextInt();
        
        System.out.println("Enter elements of array: ");
        int nums[] = new int[n];
        for(int i = 0; i < nums.length; ++i)
            nums[i] = scn.nextInt();

        /* This line was understood from this link: https://leetcode.com/problems/house-robber/discuss/1605797/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP */        
        System.out.println("Maximum sum of not adjacent elements is given by:");
        System.out.println("Recursive: " + recursive(nums, 0));
        System.out.println("Memoized: " + memoized(nums, 0, new Integer[n + 1]));
        System.out.println("Tabulated: " + tabulated(nums));
        System.out.println("Optimized" + optimized(nums));;

        scn.close();
    }

    private static int recursive(int nums[], int i) {
        if(i >= nums.length) return 0;
        return Math.max(recursive(nums, i + 1), recursive(nums, i + 2) + nums[i]);
    }

    private static int memoized(int nums[], int i, Integer memo[]) {
        if(i >= nums.length) return 0;
        if(memo[i] != null) return memo[i];
        return memo[i] = Math.max(memoized(nums, i + 1, memo), memoized(nums, i + 2, memo) + nums[i]);
    }

    private static int tabulated(int nums[]){
        int dp[] = new int[nums.length + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= nums.length; ++i)
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i-1]);
        return dp[nums.length];
    }

    private static int optimized(int arr[]) {
        int include = arr[0], exclude = 0;
        for(int i = 1; i < arr.length; ++i){
            int _exclude = Math.max(include, exclude);
            int _include = exclude + arr[i];

            include = _include;
            exclude = _exclude;
        }
        return Math.max(include, exclude);
    }
}
