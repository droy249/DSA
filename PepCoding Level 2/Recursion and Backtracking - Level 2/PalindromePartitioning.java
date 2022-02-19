// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/all-palindromic-partitions-official/ojquestion#
// Video Link: https://youtu.be/wvaYrOp94k0?list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0
// Leetcode link: https://leetcode.com/problems/palindrome-partitioning/
import java.util.*;
// import java.lang.*;
// import java.io.*;

class PalindromePartitioning {
	public static void main(String[] args) throws java.lang.Exception {
		Scanner scn = new Scanner(System.in);

		System.out.print("Enter input string: ");
		String inputString = scn.next();

		System.out.println("Palindromic partitions of " + inputString + " are:");
		printPalindromes(inputString, "");
		scn.close();
	}

	private static void printPalindromes(String input, String output) {
		if (input.isEmpty()) {
			System.out.println(output.toString());
			return;
		}

		for (int i = 0; i < input.length(); ++i) 
			if (isPalindrome(input, 0, i)) {
				String prefix = input.substring(0, i + 1);
				String restOfString = input.substring(i + 1);

				printPalindromes(restOfString, output + "(" + prefix + ")");
			}
		
	}

	private static boolean isPalindrome(String s, int start, int end) {
		while (start < end)
			if (s.charAt(start++) != s.charAt(end--))
				return false;

		return true;
	}
}
