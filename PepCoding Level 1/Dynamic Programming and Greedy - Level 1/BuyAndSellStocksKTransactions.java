// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-and-sell-stocks-kta-official/ojquestion
// Video Link: https://youtu.be/3YILP-PdEJA?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
import java.util.*;

public class BuyAndSellStocksKTransactions {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter number of days: ");
        int n = scn.nextInt();

        System.out.print("Enter the price of stock for every day: ");
        int prices[] = new int[n];
        for (int i = 0; i < prices.length; i++) {
            prices[i] = scn.nextInt();
        }

        System.out.println("Enter the maximum possible number of transactions: ");
        int K = scn.nextInt();

        System.out.println("Maximum profit that can be achieved: ");
        System.out.println("Tabulated: " + tabulated(K, prices));
        System.out.println("Optimized 1: " + optimized1(K, prices));
        System.out.println("Optimized 2: " + optimized2(K, prices));

        scn.close();
    }

    // Time Complexity: O(n * k * k)
    // Space Complexity: O(n * k)
    private static int tabulated(int K, int prices[]) {
        if (K >= prices.length / 2) { // if k >= n/2, then you can make maximum number of transactions
            int profit = 0;
            for (int i = 1; i < prices.length; i++)
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            return profit;
        }
        
        int dp[][] = new int[K + 1][prices.length];

        for (int i = 1; i < dp.length; i++) {
            for (int j = 1; j < dp[0].length; j++) {
                dp[i][j] = dp[i][j-1];
                for(int k = 0; k < j; ++k){
                    dp[i][j] = Integer.max(dp[i][j], dp[i-1][k] + prices[j] - prices[k]);
                }
            }
        }
        
        return dp[K][prices.length - 1];
    }

    // Time Complexity: O(n * k)
    // Space Complexity: O(n * k)
    private static int optimized1(int K, int prices[]) {
        if (K >= prices.length / 2) { // if k >= n/2, then you can make maximum number of transactions
            int profit = 0;
            for (int i = 1; i < prices.length; i++)
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            return profit;
        }
        
        int dp[][] = new int[K + 1][prices.length];
        
        for (int i = 0; i < dp.length; i++) {
            int max = Integer.MIN_VALUE;

            for (int j = 0; j < dp[0].length; j++) {
                max = Integer.max(max, dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = Integer.max(dp[i][j-1], max + prices[j]);
            }
        }

        return dp[K][prices.length - 1];
    }

    // Time Complexity: O(n * k)
    // Space Complexity: O(k)
    // Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/54125/Very-understandable-solution-by-reusing-Problem-III-idea#:~:text=Here%20is%20the-,solution,-.
    private static int optimized2(int k, int prices[]) {
        int[] buy = new int[k + 1], sell = new int[k + 1];
        Arrays.fill(buy, Integer.MIN_VALUE);
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = Integer.max(buy[i], sell[i - 1] - price);
                sell[i] = Integer.max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
}