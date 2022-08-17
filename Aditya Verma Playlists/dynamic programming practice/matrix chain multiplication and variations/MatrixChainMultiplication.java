// Gfg Link: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// Practice Link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/
// Leetcode Summary Post: https://leetcode.com/discuss/general-discussion/1278305/all-about-matrix-chain-multiplication-easy
// Leetcode Problem: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

public class MatrixChainMultiplication {
    public static void main(String[] args) {
        int nums[] = { 40, 20, 30, 10, 30 };
        System.out.println("Least cost to performing MCM is: ");
        System.out.println("Recursive: " + recursive(nums, 1, nums.length - 1));
        System.out.println("Memoized: " + memoize(nums, 1, nums.length - 1, new Integer[nums.length][nums.length]));
    }

    // Video Link: https://youtu.be/kMK148J9qEE?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
    private static int recursive(int nums[], int i, int j) {
        if (i >= j)
            return 0;

        int cost = Integer.MAX_VALUE;
        for (int k = i; k < j; ++k) {
            int leftCost = recursive(nums, i, k);
            int rightCost = recursive(nums, k + 1, j);
            int curCost = nums[i - 1] * nums[k] * nums[j];
            cost = Integer.min(cost, leftCost + rightCost + curCost);
        }

        /* OR */
        // int maxCost = 0;
        // for (int k = i + 1; k <= j; k++) {
        // int leftCost = recursive(nums, i, k - 1);
        // int rightCost = recursive(nums, k, j);
        // int curCost = nums[i-1] * nums[k] * nums[j];
        // cost = Integer.min(cost, leftCost + rightCost + curCost);
        // }

        return cost;
    }

    // Video Link: https://youtu.be/9uUVFNOT3_Y?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
    private static int memoize(int nums[], int i, int j, Integer[][] memo) {
        if (i >= j)
            return 0;

        if (memo[i][j] != null)
            return memo[i][j];

        int cost = Integer.MAX_VALUE;
        for (int k = i; k < j; ++k) {
            int leftCost = memoize(nums, i, k, memo);
            int rightCost = memoize(nums, k + 1, j, memo);
            int curCost = nums[i - 1] * nums[k] * nums[j];
            cost = Integer.min(cost, leftCost + rightCost + curCost);
        }

        /* OR */
        // int maxCost = 0;
        // for (int k = i + 1; k <= j; k++) {
        // int leftCost = memoize(nums, i, k - 1, memo);
        // int rightCost = memoize(nums, k, j, memo);
        // int curCost = nums[i-1] * nums[k] * nums[j];
        // cost = Integer.min(cost, leftCost + rightCost + curCost);
        // }

        return memo[i][j] = cost;
    }

}