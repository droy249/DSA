// Gfg Link: https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
// Practice Link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1/
// Leetcode Link: https://leetcode.com/problems/palindrome-partitioning-ii/

public class PalindromePartitioning {
    public static void main(String[] args) {
        String s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        System.out.println("Minimum number of partitions:");
        System.out.println("Recursive: " + recursive(s, 0, s.length() - 1));
        System.out.println("Memoization: " + memo(s, 0, s.length() - 1, new Integer[s.length()][s.length()]));

        boolean[][] checkPalindrome = new boolean[s.length()][s.length()];
        precomputePalindromes(s, checkPalindrome);
        System.out.println("Optimal memoization: " + memoOptimized(s, 0, s.length() - 1,
                new Integer[s.length()][s.length()], checkPalindrome));
    }

    // Video Link: https://youtu.be/szKVpQtBHh8?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
    private static int recursive(String s, int i, int j) {
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        int ans = Integer.MAX_VALUE;
        for (int k = i; k < j; k++) {
            int left = recursive(s, i, k);
            int right = recursive(s, k + 1, j);
            ans = Integer.min(ans, left + right + 1);
        }

        return ans;
    }

    // Video Link: https://youtu.be/fOUlNlawdAU?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
    private static int memo(String s, int i, int j, Integer[][] cache) {
        if (i >= j || isPalindrome(s, i, j))
            return 0;

        if (cache[i][j] != null)
            return cache[i][j];

        cache[i][j] = Integer.MAX_VALUE;
        for (int k = i; k < j; ++k) {
            int left = memo(s, i, k, cache);
            int right = memo(s, k + 1, j, cache);
            cache[i][j] = Integer.min(cache[i][j], left + right + 1);
        }

        return cache[i][j];
    }

    // Video Link: https://youtu.be/9h10fqkI7Nk?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
    private static int memoOptimized(String s, int i, int j, Integer[][] cache, boolean[][] checkPalindrome) {
        if (i >= j)
            return 0;

        if (cache[i][j] != null)
            return cache[i][j];

        if (checkPalindrome[i][j] == true)
            return 0;

        cache[i][j] = Integer.MAX_VALUE;
        for (int k = i; k < j; k++) {
            int left = cache[i][k] != null ? cache[i][k] : memoOptimized(s, i, k, cache, checkPalindrome);
            int right = cache[k + 1][j] != null ? cache[k + 1][j] : memoOptimized(s, k + 1, j, cache, checkPalindrome);
            cache[i][j] = Integer.min(cache[i][j], left + right + 1);
        }

        return cache[i][j];
    }

    private static boolean isPalindrome(String s, int i, int j) {
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            ++i;
            --j;
        }
        return true;
    }

    private static void precomputePalindromes(String s, boolean[][] checkPalindrome) {
        // Arrays.fill(checkPalindrome, true);

        for (int i = 0; i < s.length(); i++)
            for (int j = i + 1; j < s.length(); j++)
                checkPalindrome[i][j] = isPalindrome(s, i, j);
    }
}
