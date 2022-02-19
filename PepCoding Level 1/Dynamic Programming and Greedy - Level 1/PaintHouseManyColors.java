// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-many-colors-official/ojquestion
// Video Link: https://youtu.be/jGywRalvoRw?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
import java.util.Scanner;

public class PaintHouseManyColors {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter number of houses: ");
        int n = scn.nextInt();

        System.out.print("Enter number colors for each house: ");
        int k = scn.nextInt();

        System.out.println("Enter cost of painting each house: ");
        int costs[][] = new int[n][k];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < k; ++j)
                costs[i][j] = scn.nextInt();
                
        System.out.println("Minimum cost of painting " + n + " houses such that adjacent houses have different colours is: ");
        System.out.println("Tabulated: " + tabulated(costs));
        System.out.println("Optimized: " + optimized(costs));

        scn.close();
    }

    // Time Complexity: O(n * k * k)
    private static int tabulated(int costs[][]) {
        for(int i = 1; i < costs.length; ++i){
            for(int j = 0; j < costs[0].length; ++j){
                int min = Integer.MAX_VALUE;
                for(int k = 0; k < costs[0].length; ++k){
                    if(j != k){
                        min = Math.min(min, costs[i-1][k]);
                    }
                }
                costs[i][j] += min;
            }
        }

        int minCost = costs[costs.length - 1][0];
        for(int j = 1; j < costs[0].length; ++j){
            minCost = Math.min(minCost, costs[costs.length - 1][j]);
        }

        return minCost;
    }

    // Time Complexity: O(n * k) 
    private static int optimized(int costs[][]) {
        int least = Integer.MAX_VALUE;
        int secondLeast = Integer.MAX_VALUE;

        for(int j = 1; j < costs[0].length; ++j){
            if(costs[0][j] <= least){
                secondLeast = least;
                least = costs[0][j];
            } 
            else if (costs[0][j] <= secondLeast) {
                secondLeast = costs[0][j];
            }
        }

        for(int i = 1; i < costs.length; ++i){
            int _least = Integer.MAX_VALUE;
            int _secondLeast = Integer.MAX_VALUE;

            for(int j = 0; j < costs[0].length; ++j){
                // Calculating minimum cost for given row
                if (least == costs[i-1][j]) {
                    costs[i][j] += secondLeast;
                } else {
                    costs[i][j] += least;
                }

                // Updating temporary least and secondLeast indices for given column
                if(costs[i][j] <= _least){
                    _secondLeast = _least;
                    _least = costs[i][j];
                } 
                else if (costs[i][j] <= _secondLeast) {
                    _secondLeast = costs[i][j];
                }
            }

            // Updating global least and secondLeast indices for given row
            least = _least;
            secondLeast = _secondLeast;
        }
        
        return least;
    }
    /* private static int optimized(int costs[][]) {
        int leastIndex = 0;
        int secondLeastIndex = 0;

        for(int j = 1; j < costs[0].length; ++j){
            if(costs[0][j] <= costs[0][leastIndex]){
                secondLeastIndex = leastIndex;
                leastIndex = j;
            } 
            else if (costs[0][j] <= costs[0][secondLeastIndex]) {
                secondLeastIndex = j;
            }
        }

        for(int i = 1; i < costs.length; ++i){
            int _leastIndex = 0;
            int _secondLeastIndex = 0;

            for(int j = 0; j < costs[0].length; ++j){
                // Calculating minimum cost for given row
                if (costs[i-1][leastIndex] == costs[i-1][j]) {
                    costs[i][j] += costs[i-1][secondLeastIndex];
                } else {
                    costs[i][j] += costs[i-1][leastIndex];
                }

                // Updating temporary least and secondLeast indices for given column
                if(costs[i][j] <= costs[i][_leastIndex]){
                    _secondLeastIndex = _leastIndex;
                    _leastIndex = j;
                } 
                else if (costs[i][j] <= costs[i][_secondLeastIndex]) {
                    _secondLeastIndex = j;
                }
            }

            // Updating global least and secondLeast indices for given row
            leastIndex = _leastIndex;
            secondLeastIndex = _secondLeastIndex;
        }
        
        return costs[costs.length - 1][leastIndex];
    } */
}
