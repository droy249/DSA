// Question Link: https://nados.io/question/smallest-number-following-pattern
// Video Link: https://youtu.be/GOCbsY7Arw4?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Gfg Link: https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class SmallestNumberFollowingPattern {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter pattern: ");
        System.out.println("Pattern Formed: " + printMinNumberForPattern(br.readLine()));
    }

    private static String printMinNumberForPattern(String S) {
        int num = 1;
        Stack<Integer> stack = new Stack<Integer>();
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < S.length(); i++) {
            stack.push(num++);
            if (S.charAt(i) == 'i' || S.charAt(i) == 'I') 
                while(!stack.empty()) sb.append(stack.pop());
        }

        stack.push(num);
        while (!stack.empty()) sb.append(stack.pop());

        return sb.toString();
    }
}
