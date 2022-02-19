// Question Link: https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/infix-evaluation-official/ojquestion
// Video Link: https://youtu.be/IY0nZLEg6MA?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Leetcode Link 1: https://leetcode.com/problems/basic-calculator/
// Leetcode Link 2: https://leetcode.com/problems/basic-calculator-ii/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class InfixEvaluation {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter infix expression: ");
        String s = br.readLine();

        System.out.println("Given expression evaluates to " + calculate(s));
    }

    static int calculate(String s) {
        Stack<Character> operators = new Stack<>();
        Stack<Integer> operands = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == ' ') continue;
            else if (ch == '(') operators.push(ch);
            else if(ch >= '0' && ch <= '9') operands.push(ch - '0');
            else if(ch == ')') {
                while (operators.peek() != '(') {
                    char operator = operators.pop();
                    int val2 = operands.pop();
                    int val1 = operands.pop();
                    int result = operation(val1, val2, operator);
                    operands.push(result);
                }
                operators.pop();
            }
            else {
                while (!operators.empty() && operators.peek() != '(' && precedence(ch) <= precedence(operators.peek())) {
                    char operator = operators.pop();
                    int val2 = operands.pop();
                    int val1 = operands.pop();
                    int result = operation(val1, val2, operator);
                    operands.push(result);
                }
                operators.push(ch);
            }
        }

        while (!operators.empty()) {
            char operator = operators.pop();
            int val2 = operands.pop();
            int val1 = operands.pop();
            int result = operation(val1, val2, operator);
            operands.push(result);
        }

        return operands.pop();
    }

    static int precedence(char operator) {
        return operator == '*' || operator == '/' ? 1 : 0;
    }

    static int operation(int a, int b, char operator) {
        switch (operator) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default:
                if (b == 0) throw new UnsupportedOperationException("Cannot divide by zero");    
                return a / b;
        }
    }
}
