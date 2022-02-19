// Question Link: https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/infix-conversions-official/ojquestion
// Video Link: https://youtu.be/f29emeUcw6c?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class InfixConversions {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter infix expression: ");
        String s = bf.readLine();

        Stack<Character> operators = new Stack<>();
        Stack<String> postfix = new Stack<>();
        Stack<String> prefix = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch == '(') {
                operators.push(ch);
            } else if (Character.isLetterOrDigit(ch)) {
                postfix.push(ch + "");
                prefix.push(ch + "");
            } else if (ch == ')') {
                while (operators.peek() != '(') {
                    char operator = operators.pop();

                    String postVal2 = postfix.pop();
                    String postVal1 = postfix.pop();
                    postfix.push(postVal1 + postVal2 + operator);
                    System.err.println(postfix.peek());

                    String preVal1 = prefix.pop();
                    String preVal2 = prefix.pop();
                    prefix.push("" + operator + preVal1 + preVal2);
                    System.err.println(prefix.peek());
                }
                
                operators.pop(); 
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                while (!operators.empty() && operators.peek() != '(' && precedence(ch) <= precedence(operators.peek())) {
                    char operator = operators.pop();

                    String postVal2 = postfix.pop();
                    String postVal1 = postfix.pop();
                    postfix.push(postVal1 + postVal2 + operator);
                    System.err.println(postfix.peek());

                    String preVal1 = prefix.pop();
                    String preVal2 = prefix.pop();
                    prefix.push("" + operator + preVal1 + preVal2);
                    System.err.println(prefix.peek());
                }

                operators.push(ch); 
            }
        }
        
        System.out.println("Prefix expression: " + prefix.pop());
        System.out.println("Postfix expression: " + postfix.pop());
    }

    static int precedence(char operator) {
        if (operator == '*' || operator == '/') {
            return 2;
        } else if (operator == '+' || operator == '-'){
            return 1;
        } else {
            return 0;
        }
    }

    /* static int operation(String a, String b, char operator) {
        switch (operator) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
            if (b == 0) throw new UnsupportedOperationException("Cannot divide by zero");    
            return a / b;
        }
        return 0;
    } */
}
