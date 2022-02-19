import java.util.*;
import java.lang.*;
import java.io.*;

class StringCompression {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter String: ");
		String str = scn.next();
		System.out.println(compression1(str));
		System.out.println(compression2(str));
	}
	
	private static String compression1(String s){
		StringBuilder ans = new StringBuilder(s.substring(0,1));
		
		for(int i = 1; i < s.length(); ++i){
			char prev = s.charAt(i-1);
			char curr = s.charAt(i);
			
			if(prev != curr)
				ans.append(curr);
		}
		
		return ans.toString();
	}
	
	private static String compression2(String s){
		StringBuilder ans = new StringBuilder(s.substring(0,1));
		int count = 0;
		
		for(int i = 1; i < s.length(); ++i){
			char prev = s.charAt(i-1);
			char curr = s.charAt(i);
			
			if(prev != curr){
				if(count > 1)
					ans.append(count);
				ans.append(curr);
				count = 1;
			} else ++count;
		}
		
		return ans.toString();
	}
}
