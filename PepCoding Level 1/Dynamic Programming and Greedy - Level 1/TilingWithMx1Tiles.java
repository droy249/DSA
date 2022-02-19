// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/tiling2-official/ojquestion
// Video Link: https://youtu.be/_c_R-uIi-zU?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Gfg Link: https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/#:~:text=%C2%A0-,Recommended,-%3A%20Please%20solve%20it
import java.util.Scanner;

public class TilingWithMx1Tiles {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter length of tiling board: ");
        int n = scn.nextInt();

        System.out.print("Enter length of tile: ");
        int m = scn.nextInt();

        System.out.println("Number of ways to cover floor of dimensions " + m + " X " + n + " with tiles of size " + m + " X 1 is:");
        System.out.println("Recursive: " + recursive(n, m));
        System.out.println("Memoized: " + memoized(n, m, new Integer[n + 1]));
        System.out.println("Tabulated: " + tabulated(n, m));

        scn.close();
    }

    private static int recursive(int n, int m) {
        if(n < m) return 1;
        return recursive(n - m, m) + recursive(n - 1, m);
    }

    private static int memoized(int n, int m, Integer memo[]) {
        if(n < m) return 1;
        if(memo[n] != null) return memo[n];
        return memoized(n - m, m, memo) + memoized(n - 1, m, memo);
    }

    private static int tabulated(int n, int m) {
        if(n < m) return 1;

        int dp[] = new int[n + 1];
        for(int i = 0; i <= n; ++i)
            dp[i] = i < m ? 1 : dp[i - 1] + dp[i - m];
        
        return dp[n];
    }
}
