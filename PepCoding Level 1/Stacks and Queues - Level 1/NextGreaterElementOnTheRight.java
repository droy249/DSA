// Question Link: https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/next-greater-element-official/ojquestion
// Video Link: https://youtu.be/rSf9vPtKcmI?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Alt Video Link: https://youtu.be/XP8iEi9Aa8c?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Leetcode Link: https://leetcode.com/problems/next-greater-element-i/
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class NextGreaterElementOnTheRight {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = scn.nextInt();

        System.out.println("Enter elements of array: ");
        int arr[] = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }

        System.out.println("Next greater element on the right for given array is: ");
        System.out.println(Arrays.toString(nextGreaterElementOnTheRight(arr)));
        System.out.println(Arrays.toString(nextGreaterElementsOnTheRightAlt(arr)));

        scn.close();
    }

    // Time Complexity: O(2n)
    // Space Complexity: O(n)
    private static int[] nextGreaterElementOnTheRight(int[] arr) {
        int[] result = new int[arr.length];
        result[arr.length - 1] = -1;

        Stack<Integer> st = new Stack<>();
        st.push(arr[arr.length - 1]);
        
        for (int i = arr.length - 2; i >= 0; --i) {
            while(!st.empty() && st.peek() <= arr[i]) st.pop();
            result[i] = st.empty() ? -1 : st.peek();
            st.push(arr[i]);
        }

        return result;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    private static int[] nextGreaterElementsOnTheRightAlt(int[] arr) {
        int[] result = new int[arr.length];
        // Arrays.fill(arr, -1);
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < result.length; i++) {
            while (!st.empty() && arr[i] > arr[st.peek()]) {
                result[st.pop()] = arr[i];
            }

            st.push(i);
        }

        while (!st.empty()) {
            result[st.pop()] = -1;
        }

        return result;
    }

}
