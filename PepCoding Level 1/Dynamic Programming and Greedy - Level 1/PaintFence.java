// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-fence-official/ojquestion
// Video Link: https://youtu.be/ju8vrEAsa3Q?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// GFG practice link: https://www.geeksforgeeks.org/painting-fence-algorithm/#:~:text=k%20%3D%202%0AOutput%20%3A%206-,R,-%3A%20Please%20solve%20it
import java.util.Scanner;

public class PaintFence {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter number of posts in fence: ");
        int n = scn.nextInt();

        System.out.print("Enter number of colors to paint with: ");
        int k = scn.nextInt();

        System.out.println("Total number of ways of painting fence: ");
        System.out.println("Tabulation: " + tabulation(n, k));
        System.out.println("Optimized: " + optimized(n, k));

        scn.close();
    }

    private final static int mod = 1_000_000_007;

    private static int tabulation(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return (k * k) % mod;

        int dp[][] = new int[n + 1][3];
        
        dp[2][0] = k % mod;
        dp[2][1] = (k * (k - 1)) % mod;
        dp[2][2] = (dp[2][0] + dp[2][1]) % mod;

        for (int i = 3; i <= n; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = (dp[i - 1][2] * (k - 1)) % mod;
            dp[i][2] = (dp[i][0] + dp[i][1]) % mod;
        }
        return dp[n][2];
    }

    private static int optimized(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return (k * k) % mod;

        int same = k % mod;
        int diff = (k * (k - 1)) % mod;
        int total = same + diff;

        for(int i = 3; i <= n; ++i){
            same = diff % mod;
            diff = (total * (k - 1)) % mod;
            total = (same + diff) % mod;
        }

        return total;
    }
}

