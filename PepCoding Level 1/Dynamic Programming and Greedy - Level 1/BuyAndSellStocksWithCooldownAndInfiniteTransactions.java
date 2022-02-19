// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-and-sell-stocks-cooldown-ita-official/ojquestion
// Video Link: https://youtu.be/GY0O57llkKQ?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
import java.util.Scanner;

public class BuyAndSellStocksWithCooldownAndInfiniteTransactions {
    public static void main(String[] args) throws Exception{
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
        int oldBoughtStateProfit = -prices[0];
        int oldSoldStateProfit = 0;
        int oldCooldownStateProfit = 0;

        for (int i = 1; i < prices.length; i++) {
            int newBoughtStateProfit = 0;
            int newSoldStateProfit = 0;
            int newCooldownStateProfit = 0;

            newBoughtStateProfit = Integer.max(oldBoughtStateProfit, oldCooldownStateProfit - prices[i]);
            newSoldStateProfit = Integer.max(oldSoldStateProfit, oldBoughtStateProfit + prices[i]);
            newCooldownStateProfit = Integer.max(oldCooldownStateProfit, oldSoldStateProfit);

            oldBoughtStateProfit = newBoughtStateProfit;
            oldSoldStateProfit = newSoldStateProfit;
            oldCooldownStateProfit = newCooldownStateProfit;
        }

        return oldSoldStateProfit;
    }
}
