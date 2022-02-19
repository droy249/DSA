// Question Link: https://nados.io/question/count-of-subarrays-having-sum-equals-to-k
// Video Link: https://youtu.be/20v8zSo2v18?list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR
// Leetcode Link: https://leetcode.com/problems/subarray-sum-equals-k/
import java.util.HashMap;
import java.util.Scanner;

public class SubarraySumEqualsK {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter length of array: ");
        int n = scn.nextInt();

        System.out.println("Enter elements of array:");
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }

        System.out.print("Enter k: ");
        int k = scn.nextInt();

        System.out.println("Number of subarrays having sum = " + k + " are: " + subarraySum(arr, k));

        scn.close();
    }

    private static int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        map.put(0, 1);

        int count = 0;
        int sum = 0;

        for (int num : nums) {
            sum += num;
            if(map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }

        return count;
    }
}