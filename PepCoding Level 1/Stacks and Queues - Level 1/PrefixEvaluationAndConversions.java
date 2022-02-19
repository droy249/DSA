// Question Link: https://nados.io/question/prefix-evaluation-and-conversions
// Video Link: https://youtu.be/Q-Nw-dTApjk?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class PrefixEvaluationAndConversions {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter prefix expression: ");
        String prefix = br.readLine();

        Stack<Integer> values = new Stack<Integer>();
        Stack<String> infix = new Stack<String>();
        Stack<String> postfix = new Stack<String>();

        for (int i = prefix.length() - 1; i >= 0; --i) {
            char ch = prefix.charAt(i);

            if(Character.isDigit(ch)){
                values.push(ch - '0');
                infix.push(ch + "");
                postfix.push(ch + "");
            } else {
                int val1 = values.pop();
                int val2 = values.pop();
                int val = operation(val1, val2, ch);
                values.push(val);

                String infixVal1 = infix.pop();
                String infixVal2 = infix.pop();
                String infixVal = "(" + infixVal1 + ch + infixVal2 + ")";
                infix.push(infixVal);

                String postfixVal1 = postfix.pop();
                String postfixVal2 = postfix.pop();
                String postfixVal = postfixVal1 + postfixVal2 + ch;
                postfix.push(postfixVal);
            }
        }

        System.out.println("Prefix exression after evaluation: " + values.pop());
        System.out.println("Equivalent infix expression: " + infix.pop());
        System.out.println("Equivalent postfix expression: " + postfix.pop());
    }

    private static int operation(int val1, int val2, char operation) {
        switch (operation) {
            case '+': return val1 + val2;
            case '-': return val1 - val2;
            case '*': return val1 * val2;
            default:
                if(val2 == 0) throw new UnsupportedOperationException("Canot divide by zero");
                return val1 / val2;
        }
    }
}
