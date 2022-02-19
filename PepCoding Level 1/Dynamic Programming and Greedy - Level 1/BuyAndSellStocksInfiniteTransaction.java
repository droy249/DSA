// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-and-sell-stocks-ita-official/ojquestion
// Video Link: https://youtu.be/HWJ9kIPpzXs?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
import java.util.Scanner;

public class BuyAndSellStocksInfiniteTransaction {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter nummber of days: ");
        int n = scn.nextInt();

        System.out.print("Enter the price of stock for every day: ");
        int prices[] = new int[n];
        for (int i = 0; i < prices.length; i++) {
            prices[i] = scn.nextInt();
        }

        System.out.println("Maximum profit that can be achieved from a single transaction: " + maxProfit(prices));

        scn.close();
    }

    private static int maxProfit(int[] prices) {
        int buyingDate = 0;
        int sellingDate = 0;
        int totalProfit = 0;

        for (int i = 1; i < prices.length; ++i) {
            if(prices[i] > prices[i - 1]){
                ++sellingDate;
            } else {
                totalProfit += prices[sellingDate] - prices[buyingDate];
                sellingDate = buyingDate = i;
            }
        }
        
        return totalProfit + prices[sellingDate] - prices[buyingDate];
    }
}
