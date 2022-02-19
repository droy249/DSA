// Question Link: https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/balanced-brackets-official/ojquestion
// Video Link: https://youtu.be/uuE2pEjLiEI?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Leetcode Link: https://leetcode.com/problems/valid-parentheses/
import java.util.Scanner;
import java.util.Stack;

public class BalancedBrackets {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter expression: ");
        String s = scn.nextLine();
        scn.close();

        System.out.println(isBalanced(s) ? "Expression has balanced brackets" : "Expression does not have balanced brackets");
    }

    // private static boolean isBalanced(String s) {
    //     Stack<Character> st = new Stack<>();
    //     for(int i = 0; i < s.length(); ++i){
    //         char ch = s.charAt(i);

    //         switch (ch) {
    //             case '(':
    //                 st.push(')');
    //                 break;

    //             case '[':
    //                 st.push(']');
    //                 break;

    //             case '{':
    //                 st.push('}');
    //                 break;
                
    //             case ')':
    //             case '}':
    //             case ']':
    //                 if(st.empty() || st.peek() != ch) return false;
    //                 else st.pop();
    //         }
    //     }

    //     return st.empty();
    // }

    // Pepcoding answer
    private static boolean isBalanced(String s) {
        Stack<Character> st = new Stack<>();
        for(int i = 0; i < s.length(); ++i)
            switch (s.charAt(i)) {
                case '(':
                    st.push('(');
                    break;

                case '[':
                    st.push('[');
                    break;

                case '{':
                    st.push('{');
                    break;
                
                case ')':
                    if(st.empty() || st.peek() != '(') return false;
                    else st.pop();
                    break;

                case '}':
                    if(st.empty() || st.peek() != '{') return false;
                    else st.pop();
                    break;

                case ']':
                    if(st.empty() || st.peek() != '[') return false;
                    else st.pop();
                    break;
            }

        return st.empty();
    }
}
