// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/friends-pairing-official/ojquestion
// Video Link: https://youtu.be/SHDu0Ufjyk8?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
import java.util.Scanner;

public class FriendsPairing {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter number of friends: ");
        int n = scn.nextInt();

        System.out.println("Number of ways " + n + " friends can be grouped are:");
        System.out.println("Tabulated: " + recursive(n));
        System.out.println("Memoized: " + memoized(n, new Integer[n + 1]));
        System.out.println("Tabulated: " + tabulated(n));
        // System.out.println("Optimized: " + optimized(n));

        scn.close();
    }

    private static int recursive(int n) {
        // if(n == 0) return 1;
        // else 
        if(n < 3) return n;
        return recursive(n - 1) + (n - 1) * recursive(n - 2);
    }

    private static int memoized(int n, Integer memo[]) {
        if(n < 3) return n;
        if(memo[n] != null) return memo[n];
        return memo[n] = memoized(n - 1, memo) + (n - 1) * memoized(n - 2, memo);
    }

    private static int tabulated(int n) {
        int dp[] = new int[n + 1];
    
        for(int i = 0; i <= n; ++i)
            dp[i] = i < 3 ? i : dp[i - 1] + (i - 1) * dp[i - 2];
        
        return dp[n];
    }
}
