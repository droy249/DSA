// Question Link: https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/sliding-window=maximum-official/ojquestion
// Video Link: https://youtu.be/tCVOQX3lWeI?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Leetcode Link: https://leetcode.com/problems/sliding-window-maximum/
// All approach Video Link: https://youtu.be/MCvGwtkqJS0
// C++ all approaches: https://leetcode.com/problems/sliding-window-maximum/discuss/637304/Very-Straightforward-C%2B%2B-Solutions-all-3-solutions-compared
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

public class SlidingWindowMaximum {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = scn.nextInt();

        System.out.print("Enter elements in array: ");
        int arr[] = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }

        System.out.print("Enter size of window: ");
        int k = scn.nextInt();

        System.out.println("Sliding Window maximum of given array is: ");
        System.out.println("Brute Force approach: " + Arrays.toString(bruteForceApproach(arr, k)));
        System.out.println("Stack approach: " + Arrays.toString(stackAndSlidingWindowApproach(arr, k)));
        System.out.println("AVL Tree/Priority Queue approach: " + Arrays.toString(heapApproach(arr, k)));
        System.out.println("Deque approach: " + Arrays.toString(dequeApproach(arr,k)));

        scn.close();
    }
    
    /* Time Complexity: O(n * k)
     * Space Complexity: O(1)
     */
    private static int[] bruteForceApproach(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];
        for (int i = 0, idx = 0; i < ans.length; i++) {
            int max = Integer.MIN_VALUE;
            for (int j = 0; j < k; j++) 
                max = Integer.max(max, nums[i + j]);
            ans[idx++] = max;
        }
        return ans;
    }
    
    /* Time Complexity: O(n)
     * Space Complexity: O(k)
     */
    private static int[] dequeApproach(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int[] ans = new int[nums.length - k + 1];
        int i = 0, j = 0;

        for (; i < k; ++i) {
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()])
                dq.removeLast();
            dq.addLast(i);
        }

        for (; i < nums.length; ++i) {
            ans[j++] = nums[dq.peek()];
            while (!dq.isEmpty() && dq.peek() <= i - k) 
                dq.removeFirst();
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()])
                dq.removeLast();
            dq.addLast(i);
        }

        ans[j++] = nums[dq.peek()];

        return ans;
    }
    
    /* Time Complexity: O(n log k)
     * Space Complexity: O(k)
     */
    private static int[] heapApproach(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int[] ans = new int[nums.length - k + 1];

        for (int i = 0, j = 0; i < nums.length; i++) {
            pq.offer(nums[i]);
            if (pq.size() > k) {
                pq.remove(nums[i-k]);            
            }
            if (pq.size() == k) {
                ans[j++] = pq.peek();
            }
        }

        return ans;
    }

    private static int[] stackAndSlidingWindowApproach(int[] nums, int k) {
        int[] nextGreater = nextGreaterElementOnTheRight(nums);
        int[] ans = new int[nums.length - k + 1];

        int j = 0;
        for (int i = 0; i <= nums.length - k ; i++) {
            if(j < i) j = i;
            while(nextGreater[j] < i + k) j = nextGreater[j];
            ans[i] = nums[j];
        }

        return ans;
    }

    private static int[] nextGreaterElementOnTheRight(int[] arr) {
        int[] result = new int[arr.length];
        result[arr.length - 1] = arr.length;

        Stack<Integer> st = new Stack<>();
        st.push(arr.length - 1);
        
        for (int i = arr.length - 2; i >= 0; --i) {
            while(!st.empty() && arr[st.peek()] <= arr[i]) st.pop();
            result[i] = st.empty() ? arr.length : arr[st.peek()];
            st.push(i);
        }

        return result;
    }
}
