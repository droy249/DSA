// Gfg Link: https: www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// Practice Link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1/

public class BooleanParenthesization {
    public static void main(String[] args) {
        String s = "T^F|F";

        System.out.println("The number of ways to parenthesize " + s + " so that it evaluates to true: ");
        System.out.println("Recursive: " + recursive(s, 0, s.length() - 1, true));
        System.out.println("Memoized: " + memoize(s, 0, s.length() - 1, true, new Integer[s.length()][s.length()][2]));
    }

    // Video Link : https://youtu.be/pGVguAcWX4g?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
    private static int recursive(String s, int i, int j, boolean isTrue) {
        if (i > j)
            return 0;

        if (i == j)
            if ((s.charAt(i) == 'T' && isTrue) || (s.charAt(i) == 'F' && !isTrue))
                return 1;

        int ans = 0;
        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = recursive(s, i, k - 1, true);
            int leftFalse = recursive(s, i, k - 1, false);

            int rightTrue = recursive(s, k + 1, j, true);
            int rightFalse = recursive(s, k + 1, j, false);

            switch (s.charAt(k)) {
                case '&':
                    ans += isTrue ? leftTrue * rightTrue
                            : leftFalse * rightTrue + leftTrue * rightFalse + leftFalse * rightFalse;
                    break;

                case '|':
                    ans += isTrue ? leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue
                            : leftFalse * rightFalse;
                    break;

                case '^':
                    ans += isTrue ? leftTrue * rightFalse + leftFalse * rightTrue
                            : leftTrue * rightTrue + leftFalse * rightFalse;
                    break;
            }
        }

        return ans;
    }

    // Video Link:
    // 
    private static int memoize(String s, int i, int j, boolean isTrue, Integer[][][] cache) {
        int idx = isTrue ? 1 : 0;

        if (i > j)
            return cache[i][j][idx] = 0;

        if (i == j)
            if ((s.charAt(i) == 'T' && isTrue) || (s.charAt(i) == 'F' && !isTrue))
                return cache[i][j][idx] = 1;

        if (cache[i][j][idx] != null)
            return cache[i][j][idx];

        int ans = 0;
        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = cache[i][k - 1][1] != null ? cache[i][k - 1][idx]
                    : memoize(s, i, k - 1, true, cache);
            int leftFalse = cache[i][k - 1][0] != null ? cache[i][k - 1][idx]
                    : memoize(s, i, k - 1, false, cache);

            int rightTrue = cache[k + 1][j][1] != null ? cache[k + 1][j][idx]
                    : memoize(s, k + 1, j, true, cache);
            int rightFalse = cache[k + 1][j][0] != null ? cache[k + 1][j][idx]
                    : memoize(s, k + 1, j, false, cache);

            switch (s.charAt(k)) {
                case '&':
                    ans += isTrue ? leftTrue * rightTrue
                            : leftFalse * rightTrue + leftTrue * rightFalse + leftFalse * rightFalse;
                    break;

                case '|':
                    ans += isTrue ? leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue
                            : leftFalse * rightFalse;
                    break;

                case '^':
                    ans += isTrue ? leftTrue * rightFalse + leftFalse * rightTrue
                            : leftTrue * rightTrue + leftFalse * rightFalse;
                    break;
            }
        }

        return cache[i][j][idx] = ans;
    }
}
