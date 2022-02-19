/* FOUND PEPCOING SOLUTION HARD TO COMPREHEND. HENCE WHY I PROCEEDED VIA LEETCODE LINK MENTIONED BELOW */
// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-encodings-official/ojquestion
// Video Link: https://youtu.be/jFZmBQ569So?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Leetcode Link: https://leetcode.com/problems/decode-ways/
import java.util.Scanner;

class DecodeWays {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter encoded string: ");
        String inputString = scn.next();

        /*
         * For this solution I have refered to this link for understanding:
         * https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion
         * -to-dp
         */
        System.out.println("Total number of possible encodings is: ");
        System.out.println("Recursive: " + recursive(inputString, 0));
		System.out.println("Memoized: " + memoized(inputString, 0, new Integer[inputString.length() + 1]));
		System.out.println("Tabulated: " + tabulated(inputString));
		System.out.println("Optimized: " + optimized(inputString));

		scn.close();
    }

    private static int recursive(final String s, int i) {
        if (i == s.length())
            return 1;
        if (s.charAt(i) == '0')
            return 0;

        if (i + 1 < s.length()
                && (s.charAt(i) == '1' || s.charAt(i) == '2' && s.charAt(i + 1) < '7'))
            return recursive(s, i + 1) + recursive(s, i + 2);
        else
            return recursive(s, i + 1);
    }

    private static int memoized(String s, int i, Integer memo[]) {
        if (i == s.length())
            return 1;
        if (s.charAt(i) == '0')
            return 0;
        if (memo[i] != null)
            return memo[i];

        if (i + 1 < s.length()
                && (s.charAt(i) == '1' || s.charAt(i) == '2' && s.charAt(i + 1) < '7'))
            memo[i] = memoized(s, i + 1, memo) + memoized(s, i + 2, memo);
        else
            memo[i] = memoized(s, i + 1, memo);

        return memo[i];
    }

    private static int tabulated(final String s) {
        int dp[] = new int[s.length() + 1];

        dp[s.length()] = 1;
        for (int i = s.length() - 1; i >= 0; --i)
            if(s.charAt(i) == '0')
                dp[i] = 0;
            else
                if (i + 1 < s.length() && (s.charAt(i) == '1' || s.charAt(i) == '2' && s.charAt(i + 1) < '7'))
                    dp[i] = dp[i + 1] + dp[i + 2];
                else
                    dp[i] = dp[i + 1];

        return dp[0];
    }

    private static int optimized(final String input) {
        return 0;
    }
}