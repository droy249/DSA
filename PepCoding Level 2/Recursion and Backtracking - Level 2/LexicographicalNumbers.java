// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/lexicographical-numbers-official/ojquestion
// Video Link: https://youtu.be/gRo86WqFYSE?list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0
// Leetcode Link: https://leetcode.com/problems/lexicographical-numbers/
import java.util.ArrayList;

public class LexicographicalNumbers {
    public static void main(String[] args) {
        int n = 12;
        
        // My Approach
        ArrayList<Integer> ans = new ArrayList<Integer>();
        solve(1, n, ans);
        System.out.println("Lexicographical numbers (My Approach): " + ans);

        // Pepcoding Approach
        ArrayList<Integer> pep = new ArrayList<Integer>();
        for (int i = 1; i < 10; i++) {
            pepcoding(i, n, pep);
        }
        System.out.println("Lexicographical numbers (Pepcoding Approach): " + pep);
    }

    private static void solve(int i, int n, ArrayList<Integer> ans) {
        if(i > n) {
            return;
        }

        // Add number to ans
        ans.add(i);

        // Solve for family of i, i -> i * 10 -> i * 100 -> ... and so on
        solve(i * 10, n, ans);

        // Solve for i + 1
        if (i % 10 != 9) {
            solve(i + 1, n, ans);
        }
    }

    private static void pepcoding(int i, int n, ArrayList<Integer> pep) {
        if (i > n) {
            return;
        }

        pep.add(i);

        for (int j = 0; j < 10; j++) {
            pepcoding(10 * i + j, n, pep);
        }
    }
}
