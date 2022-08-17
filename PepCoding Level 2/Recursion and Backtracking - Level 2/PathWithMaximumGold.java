// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/gold-mine-2-official/ojquestion
// Video Link: https://youtu.be/lNwXq3Ki32I?list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0
import java.util.ArrayList;

public class PathWithMaximumGold {
    public static void main(String[] args) {
        int[][] grid = {
                { 0, 1, 4, 2, 8, 2 },
                { 4, 3, 6, 5, 0, 4 },
                { 1, 2, 4, 1, 4, 6 },
                { 2, 0, 7, 3, 2, 2 },
                { 3, 1, 5, 9, 2, 4 },
                { 2, 7, 0, 8, 5, 1 }
        };

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                /* Pepcoding approach: Using ArrayList */
                // ArrayList<Integer> bag = new ArrayList<Integer>();
                // Integer bag = 0;
                solve(i, j, grid);

                // int sum = 0;
                // for (int val : bag) {
                // sum += val;
                // }
                max = Math.max(bag, max);
                bag = 0;
            }
        }

        System.out.println("Maximum possible gold: " + max);
    }

    private static int max = 0, bag = 0;

    private static void solve(int r, int c, int[][] grid) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0) {
            return;
        }

        // bag.add(grid[r][c]);
        bag += grid[r][c];
        grid[r][c] = 0;
        solve(r - 1, c, grid);
        solve(r, c - 1, grid);
        solve(r + 1, c, grid);
        solve(r, c + 1, grid);
        // bag -= grid[r][c];
    }
}
