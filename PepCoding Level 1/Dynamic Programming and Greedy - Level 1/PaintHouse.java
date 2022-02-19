
// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-official/ojquestion
// Video Link: https://youtu.be/kh48JLieeW8?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
import java.util.Scanner;

public class PaintHouse {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        System.out.print("Enter number of houses: ");
        int n = scn.nextInt();

        System.out.println("Enter cost of painting each house: ");
        int costs[][] = new int[n][3];
        for(int i = 0; i < n; ++i){
            costs[i][0] = scn.nextInt();                // red color costs
            costs[i][1] = scn.nextInt();                // blue color costs
            costs[i][2] = scn.nextInt();                // green color costs
        }
                

        System.out.println("Minimum cost of painting " + n + " houses such that adjacent houses have different colours is: ");
        System.out.println("Tabulated: " + tabulated(costs));
        System.out.println("Optimized: " + optimized(costs));

        scn.close();
    }

    private static int tabulated(int costs[][]) {
        for(int i = 1; i < costs.length; ++i){
            costs[i][0] += Math.min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += Math.min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += Math.min(costs[i-1][1], costs[i-1][0]);
        }

        return Math.min(costs[costs.length - 1][0], Math.min(costs[costs.length - 1][1], costs[costs.length - 1][2]));
    }

    private static int optimized(int costs[][]) {
        int red = 0, green = 0, blue =  0;
        for(int cost[] : costs){
            int _red = cost[0] + Math.min(green, blue);
            int _green = cost[1] + Math.min(blue, red);
            int _blue = cost[2] + Math.min(red, green);

            red = _red;
            green = _green;
            blue =  _blue;
        }
        return Math.min(green, Math.min(blue, green));
    }
}