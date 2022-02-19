/* REWATCH VIDEO AGAIN!! */

// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/partition-into-subsets-official/ojquestion
// Video Link: https://youtu.be/IiAsqfjhZnY?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
import java.util.Scanner;

public class PartionIntoSubsets {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        System.out.print("Enter number of elements: ");
        int n = scn.nextInt();

        System.out.print("Enter number of groups: ");
        int k = scn.nextInt();

        System.out.println("Number of ways to create " + k + " subsets of " + n + " elements is:");
        System.out.println("Recursive: " + recursive(n, k));
        System.out.println("Memoized: " + memoized(n, k, new Integer[n + 1][k + 1]));
        System.out.println("Tabulation: "+ tabulation(n,k));

        scn.close();
    }

    private static int recursive(int n, int k) {
        if(n == 0 || k == 0 || n < k) return 0;
        if(k == 1 || n == k) return 1;
        return k * recursive(n - 1, k) + recursive(n - 1, k - 1);
    }

    private static int memoized(int n, int k, Integer[][] memo) {
        if(n == 0 || k == 0 || n < k) return 0;
        if(k == 1 || n == k) return 1;
        if(memo[n][k] != null) return memo[n][k];
        memo[n][k] =  k * memoized(n - 1, k, memo) + memoized(n - 1, k - 1, memo);
        return memo[n][k];
    }

    private static int tabulation(int n, int k) {
        int dp[][] = new int[n + 1][k + 1];

        for(int i = 1; i < dp.length; ++i){
            for(int j = 1; j < dp[0].length; ++j){
                if(i < j){
                    dp[i][j] = 0;
                } else if (j == 1 || i == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
                }
            }
        }

    return dp[n][k];
    }
}
