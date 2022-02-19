// Question Link: https://nados.io/question/merge-overlapping-interval
// Video Link: https://youtu.be/QlaDyZTCAbM?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Leetcode Link: https://leetcode.com/problems/merge-intervals/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Stack;

public class MergeOverlappingIntervals {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter number of intervals: ");
        int n = Integer.parseInt(bf.readLine());

        System.out.println("Enter intervals: ");
        int intervals[][] = new int[n][2];
        for (int i = 0; i < intervals.length; i++) {
            String line = bf.readLine();
            intervals[i][0] = Integer.parseInt(line.split(" ")[0]);
            intervals[i][1] = Integer.parseInt(line.split(" ")[1]);
        }

        System.out.println("The merged intervals are: " + Arrays.deepToString(merge(intervals)).replace("], ", "]\n").replace("[[", "[").replace("]]", "]"));
    }

    private static int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]);
        Stack<int[]> stack = new Stack<>();
        for (int[] interval : intervals) 
            if (stack.empty() || interval[0] > stack.peek()[1]) 
                stack.push(interval);
            else 
                stack.peek()[1] = Integer.max(stack.peek()[1], interval[1]);
        
        int mergedIntervals[][] = new int[stack.size()][2];
        for (int i = mergedIntervals.length - 1; i >= 0; --i) {
            mergedIntervals[i][0] = stack.peek()[0];
            mergedIntervals[i][1] = stack.pop()[1];
        }

        return mergedIntervals;
    }
}
