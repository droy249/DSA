// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-and-sell-stocks-ota-official/ojquestion
// Video Link: https://youtu.be/4YjEHmw1MX0?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
import java.util.Scanner;

public class BestTimeToBuyAndSellStocks {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter nummber of days: ");
        int n = scn.nextInt();

        System.out.print("Enter the price of stock for every day: ");
        int prices[] = new int[n];
        for (int i = 0; i < prices.length; i++) {
            prices[i] = scn.nextInt();
        }

        System.out.println("Maximum profit that can be achieved from a infnite transaction: " + maxProfit(prices));

        scn.close();
    }

    private static int maxProfit(int prices[]) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;
        
        for(int price : prices){
            if(minPrice > price){
                minPrice = price;
            } else {
                maxProfit = Integer.max(maxProfit, price - minPrice);
            }
        }

        return maxProfit;
    }
}
