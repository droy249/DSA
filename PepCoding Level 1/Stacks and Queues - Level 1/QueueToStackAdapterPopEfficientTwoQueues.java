// Question Link: https://nados.io/question/queue-to-stack-adapter-pop-efficient
// Video Link: https://youtu.be/bJpPuLMiUgA?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Leetcode Link: https://leetcode.com/problems/implement-stack-using-queues/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class QueueToStackAdapterPopEfficientTwoQueues {

    public static class QueueToStackAdapter {
        Queue<Integer> mainQ;
        Queue<Integer> helperQ;

        public QueueToStackAdapter() {
            this.mainQ = new ArrayDeque<>();
            this.helperQ = new ArrayDeque<>();
        }

        int size() {
            // write your code here
            return mainQ.size();
        }

        void push(int val) {
            // write your code here
            while (!mainQ.isEmpty())
                helperQ.offer(mainQ.poll());

            mainQ.offer(val);

            while (!helperQ.isEmpty())
                mainQ.offer(helperQ.poll());
        }

        int pop() {
            // write your code here
            if (size() == 0) {
                System.out.println("Stack Underflow");
                return -1;
            } else {
                return mainQ.poll();
            }
        }

        int top() {
            // write your code here
            if (size() == 0) {
                System.out.println("Stack Underflow");
                return -1;
            } else {
                return mainQ.peek();
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        QueueToStackAdapter st = new QueueToStackAdapter();

        String str = br.readLine();
        while (str.equals("quit") == false) {
            if (str.startsWith("push")) {
                int val = Integer.parseInt(str.split(" ")[1]);
                st.push(val);
            } else if (str.startsWith("pop")) {
                int val = st.pop();
                if (val != -1) {
                    System.out.println(val);
                }
            } else if (str.startsWith("top")) {
                int val = st.top();
                if (val != -1) {
                    System.out.println(val);
                }
            } else if (str.startsWith("size")) {
                System.out.println(st.size());
            }
            str = br.readLine();
        }
    }
}