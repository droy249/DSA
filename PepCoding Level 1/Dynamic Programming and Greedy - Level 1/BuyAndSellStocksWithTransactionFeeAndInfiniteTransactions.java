// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-sell-stocks-transaction-fee-ita-official/ojquestion
// Video Link: https://youtu.be/pTQB9wbIpfU?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// LeetCode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
import java.util.Scanner;

public class BuyAndSellStocksWithTransactionFeeAndInfiniteTransactions {
    public static void main(String[] args) throws Exception{
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter nummber of days: ");
        int n = scn.nextInt();

        System.out.print("Enter the price of stock for every day: ");
        int prices[] = new int[n];
        for (int i = 0; i < prices.length; i++) {
            prices[i] = scn.nextInt();
        }

        System.out.print("Enter fee to be paid for each transaction: ");
        int fee = scn.nextInt();

        System.out.println("Maximum profit that can be achieved: " + maxProfit(prices, fee));

        scn.close();
    }

    private static int maxProfit(int prices[], int fee) {
        int oldBoughtStateProfit = -prices[0];     // This means that you have a share. You initially start off with $0, then you take a loan 
        int oldSoldStateProfit = 0;                // This means that you are all clear. jitne khareede utne bech diye

        for(int i = 1; i < prices.length; ++i){
            int newBoughtStateProfit = 0;
            int newSoldStateProfit = 0;

            if(oldSoldStateProfit - prices[i] > oldBoughtStateProfit){
                newBoughtStateProfit = oldSoldStateProfit - prices[i];
            } else {
                newBoughtStateProfit = oldBoughtStateProfit;
            }

            if(oldBoughtStateProfit + prices[i] - fee > oldSoldStateProfit){
                newSoldStateProfit = oldBoughtStateProfit + prices[i] - fee;
            } else {
                newSoldStateProfit = oldSoldStateProfit;
            }

            oldBoughtStateProfit = newBoughtStateProfit;
            oldSoldStateProfit = newSoldStateProfit;
        }

        return oldSoldStateProfit;
    }
}

// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/#:~:text=Read%20More-,Awesome%20solution!,-I%20added%20some
/* I added some notes below to help me understand it:

Only 1 share of the stock can be bought or sold;
A stock can be bought or sold for multiple times in one day, but it has to be sold before being bought again;
The service fee is only charged when stock is sold;
Cash(i): the cash in hand, if you are not holding the stock at the end of day(i):
You might be not holding the stock at the end of day(i-1), and do nothing in day(i): a = cash(i-1); or
You might be holding the stock at the end of day(i-1), and sell it at the end of day(i):
b = hold(i-1) + prices[i] - fee;
Choose the greatest one as the value of cash(i) to get the greater potential profit:
cash(i) = max(a, b) = max(cash(i-1), hold(i-1) + prices[i] - fee);
Hold(i): the cash in hand, if you are holding the stock at the end of day(i):
You might be holding the stock at the end of day(i-1), and do nothing in day(i): a = hold(i-1); or
You might be not holding the stock at the end of day(i-1), and buy it at the end of day(i): b = cash(i-1) - prices[i]; or
You might be holding the stock at the end of day(i-1), sell it on day(i), and buy it again at the end of day(i):
c = (hold(i-1) + prices[i] - fee) - prices[i];
Choose the greatest one as the value of hold(i) to get the greater potential profit:
hold(i) = max(a,b,c)
Because max(b, c) = max(cash(i-1), hold(i-1) + prices[i] - fee) - prices[i] = cash(i) - prices[i],
so hold(i) = max(hold(i-1), cash(i) - prices[i]);
There is another way to calculate hold(i), which is more straight forward:
You might be holding the stock at the end of day(i-1), and do nothing in day(i): a = hold(i-1); or
You might be not holding the stock at the end of day(i-1), and buy it at the end of day(i): b = cash(i-1) - prices[i]; or
You might be holding the stock at the end of day(i-1), sell it on day(i), and buy it again at the end of day(i):
c = (hold(i-1) + prices[i] - fee) - prices[i] = hold(i-1) - fee;
Obviously, a > c, so max(a, c) = a, hold(i) = max(a, b, c) = max(a, b) = max(hold(i-1), cash(i-1) - prices[i])
The target is to find the maximum profit at the end of day(N): cash(N);
class Solution {
    public int maxProfit(int[] prices, int fee) {
        // In day(0), cash(0) (stands for initial profit) is 0, hold(0) is -prices[0]
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.length; i++) {
            // cash(i) = max(cash(i-1), hold(i-1) + prices[i] - fee)
            // cash(i-1) => not holding stock at the end of day(i-1), and do nothing on day(i)
            // hold(i-1) + prices[i] - fee => hold the stock at the end of day(i-1), sell it on day(i)
            // NOTE: so cash(i) >= cash(i-1)
            cash = Math.max(cash, hold + prices[i] - fee);

            // hold(i) = max(hold(i-1), cash(i) - prices[i])
            // hold(i-1) => holding stock at the end of day(i-1), and do nothing on day(i)
            // cash(i) - prices[i] => because cash(i) >= cash(i-1), if selling stock on day(i) results in more cash in hand than cash(i-1), 
            // it makes sense to sell it on day(i) and buy it back instead of selling it on day(i-1) and buy it on day(i).
            // Take the following case as an example:
            // service fee: 1
            // prices: [5, 10, 15, ...]
            // cash[0, 4, 9, ...]
            // hold[-5, -5, ?, ...]
            // Now consider all possible values of hold(2):
            // 1. Do nothing: a = hold(1) = -5
            // 2. Sell on day(1), buy on day(2): b = cash(1) - price(2) = 4 - 15 = -9
            // 3. Sell on day(2), and buy again: c = hold(1) + p(2) - fee - p(2) = -5 + 15 - 1 - 15 = -6
            // c > b, so buying on day(2) results in more profit.
            // However, since a = -5, which is a better choice, finally, hold(2) is resolved to "-5", which is obvious because the price is keeping
            // rising, so the best choice would be buy it on day(0) and hold it.
            hold = Math.max(hold, cash - prices[i]);
        }
        return cash;
    }
}
// This is another way to calculate hold(i): 
// hold(i) = max(hold(i-1), cash(i-1) - price(i))
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.length; i++) {
            int prev_cash = cash;
            cash = Math.max(prev_cash, hold + prices[i] - fee);
            hold = Math.max(hold, prev_cash - prices[i]);
        }
        return cash;
    }
}
*/