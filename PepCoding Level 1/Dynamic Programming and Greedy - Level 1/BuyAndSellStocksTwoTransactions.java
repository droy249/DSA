// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-sell-stocks-tta-official/ojquestion
// Video Link: https://youtu.be/wuzTpONbd-0?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
import java.util.Scanner;

public class BuyAndSellStocksTwoTransactions {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter number of days: ");
        int n = scn.nextInt();

        System.out.print("Enter the price of stock for every day: ");
        int prices[] = new int[n];
        for (int i = 0; i < prices.length; i++) {
            prices[i] = scn.nextInt();
        }

        System.out.println("Maximum profit that can be achieved: " + maxProfit(prices));

        scn.close();
    }

    private static int maxProfit(int prices[]) {
        int n = prices.length;
            
        int minFromLeft = prices[0];
        int[] dpFromLeft = new int[n + 1];

        for(int i = 1; i < n; ++i){
            minFromLeft = Integer.min(minFromLeft, prices[i]);
            dpFromLeft[i] = Integer.max(dpFromLeft[i-1], prices[i] - minFromLeft);
        }

        int maxFromRight = prices[n - 1];
        int[] dpFromRight = new int[n + 1];

        for(int i = n - 2; i >= 0; --i){
            maxFromRight = Integer.max(maxFromRight, prices[i]);
            dpFromRight[i] = Integer.max(dpFromRight[i+1], maxFromRight - prices[i]);
        }

        int mostProfit = 0;
        for(int i = 0; i < n; ++i)
            mostProfit = Integer.max(mostProfit, dpFromLeft[i] + dpFromRight[i]);

        return mostProfit;
    }
}
