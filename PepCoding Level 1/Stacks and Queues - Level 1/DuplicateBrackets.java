// Question Link: https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/duplicate-brackets-official/ojquestion
// Video Link: https://youtu.be/aMPXhEdpXFA?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
import java.util.Scanner;
import java.util.Stack;

public class DuplicateBrackets {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter expression: ");
        String s = scn.nextLine();

        Stack<Character> st = new Stack<>();
        for(int i = 0; i < s.length(); ++i){
            char ch = s.charAt(i);
            
            if (ch != ')') {
                st.push(ch);
            } else {
                int noOfPopped = 0;

                while(st.peek() != '('){
                    st.pop();
                    ++noOfPopped;
                }

                if(noOfPopped == 1){            // When ')' is the only character that is popped
                    System.out.println("Contains duplicate brackets.");
                    scn.close();
                    return;
                }
            }
        }

        System.out.println("Does not contain duplicate brackets.");

        scn.close();
    }


}