// Video Link: https://youtu.be/uUXXEgK2Jh8?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj
// Gfg Practice Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class FirstNegativeIntegerInEveryWindowOfSizeK {
    public static void main(String[] args) {
        long[] arr = { 12, -1, -7, 8, -15, 30, 16, 28 };
        int k = 3;
        System.out.println("Ans: " + Arrays.toString(printFirstNegativeInteger(arr, arr.length, k)));
    }

    private static long[] printFirstNegativeInteger(long A[], int N, int K) {
        long[] ans = new long[N - K + 1];
        Queue<Long> q = new LinkedList<>();

        for (int i = 0, j = 0, idx = 0; j < N; ) {
            int window = j - i + 1;

            if (A[j] < 0) {   
                q.add(A[j]);
            }

            if (window < K) {
                ++j;
            } else if (window == K) {
                ans[idx++] = q.element();

                if (!q.isEmpty() && q.element() == A[i]) {
                    q.remove();
                }
                ++i;
                ++j;
            }
        }

        return ans;
    }
}