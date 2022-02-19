
// Leetcode Link: https://leetcode.com/problems/arithmetic-slices/
// Question Link: https://nados.io/question/arithmetic-slices-1
// Video Link: https://youtu.be/rSi4MpGEz1M?list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ArithmeticSlices {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter length of array: ");
        int n = Integer.parseInt(br.readLine());

        System.out.print("Enter elements of array: ");
        int[] arr = new int[n];
        String nums[] = br.readLine().split(" ");
        for (int i = 0; i < arr.length; i++)
            arr[i] = Integer.parseInt(nums[i]);

        System.out.println("Total number of subarrays which form arithmetic sequences are:");
        System.out.println("Recursive = " + recursive(arr, 2, 0, 0));
        System.out.println("Tabulated = " + tabulated(arr));
    }

    static int recursive(int[] nums, int i, int total, int prevSeqTotal) {
        if (i >= nums.length)
            return total;

        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            return recursive(nums, i + 1, total + 1 + prevSeqTotal, prevSeqTotal + 1);

        return recursive(nums, i + 1, total, 0);
    }

    static int tabulated(int[] nums) {
        int dp[] = new int[nums.length];
        int ans = 0;

        for (int i = 2; i < dp.length; i++)
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                ans += dp[i] += dp[i - 1] + 1;

        return ans;
    }
}