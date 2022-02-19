// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/tiling1-official/ojquestion
// Video Link: https://youtu.be/dVT9JeUMMDE?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Gfg Link: https://www.geeksforgeeks.org/tiling-problem/#:~:text=to%20the%20solution-,.,-Implementation%20%E2%80%93%C2%A0
import java.util.Scanner;

public class TilingWith2x1Tiles {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter length of tiling board: ");
        int n = scn.nextInt();

        System.out.println("Number of ways to cover floor of dimensions " + n + " X 2 with tiles of size 2 X 1 is:");
        System.out.println("Recursive: " + recursive(n));
        System.out.println("Memoized: " + memoized(n, new Integer[n + 1]));
        System.out.println("Tabulated: " + tabulated(n));
        System.out.println("Optimized: " + optimized(n));

        scn.close();
    }

    private static int recursive(int n) {
        if(n == 0) return 1;
        else if(n < 4) return n;

        return recursive(n - 1) + recursive(n - 2);
    }

    private static int memoized(int n, Integer memo[]) {
        if(n == 0) return 1;
        else if(n < 4) return n;

        if(memo[n] != null) return memo[n];

        return memo[n] = memoized(n - 1, memo) + memoized(n - 2, memo);
    }

    private static int tabulated(int n) {
        if(n == 0) return 1;
        else if(n < 4) return n;

        int dp[] = new int[n + 1];
        dp[0] = dp[1] = 1;

        for(int i = 2; i <= n; ++i)
            dp[i] = dp[i - 2] + dp[i - 1];

        return dp[n];
    }

    private static int optimized(int n) {
        if(n == 0) return 1;
        else if(n < 4) return n;

        int a = 1, b = 1, c;

        for(int i = 2; i <= n; ++i){
            c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
}