// Question Link: https://nados.io/question/postfix-evaluation-and-conversions
// Video Link: https://youtu.be/BlNXOtll7jo?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class PostfixEvaluationAndConversions {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter postfix expression: ");
        String s = bf.readLine();

        Stack<Integer> values = new Stack<Integer>();
        Stack<String> prefix = new Stack<String>();
        Stack<String> infix = new Stack<String>();

        for(int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);

            if (Character.isDigit(ch)) {
                values.push(ch - '0');
                infix.push(ch + "");
                prefix.push(ch + "");
            } else {
                int val2 = values.pop();
                int val1 = values.pop();
                int val = operation(val1, val2, ch);
                values.push(val);

                String infixVal2 = infix.pop();
                String infixVal1 = infix.pop();
                String infixVal = "(" + infixVal1 + ch + infixVal2 + ")";
                infix.push(infixVal);

                String prefixVal2 = prefix.pop();
                String prefixVal1 = prefix.pop();
                String prefixVal = ch + prefixVal1 + prefixVal2;
                prefix.push(prefixVal);
            }
        }

        System.out.println("Postfix expression after evalution: " + values.pop());
        System.out.println("Equivalent infix expression: " + infix.pop());
        System.out.println("Equivalent prefix expression: " + prefix.pop());
    }

    private static int operation(int val1, int val2, char operation) {
        switch (operation) {
            case '+': return val1 + val2;
            case '-': return val1 - val2;
            case '*': return val1 * val2;
            default: 
                if(val2 == 0) throw new UnsupportedOperationException("Cannot divide by zero");
                return val1 / val2;
        }
    }
}
