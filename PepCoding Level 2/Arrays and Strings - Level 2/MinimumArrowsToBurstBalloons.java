// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/find-minimum-number-of-arrows-needed-to-burst-balloon-official/ojquestion#
// Video Link: https://youtu.be/Z9o-lqwgSWA?list=PL-Jc9J83PIiE-TR27GB7V5TBLQRT5RnSl
// Leetcode Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
import java.util.Arrays;
import java.util.Scanner;

public class MinimumArrowsToBurstBalloons {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter number of balloons: ");
        int n = scn.nextInt();

        System.out.println("Enter end poins of every balloon:");
        int points[][] = new int[n][2];
        for(int i = 0; i < n; ++i){
            points[i][0] = scn.nextInt();
            points[i][1] = scn.nextInt();
        }

        System.out.println("Minimum number of arrows to fire all balloons: " + findMinArrowShots1(points));
        System.out.println("Minimum number of arrows to fire all balloons: " + findMinArrowShots2(points));

        scn.close();
    }

    private static int findMinArrowShots1(int points[][]) {
        Arrays.sort(points, (a,b) -> a[1] - b[1]);
        // for(int[] point: points)
        //     System.err.println(point[0] + "," + point[1]);
        int end = points[0][1], arrows = 1;
        
        for(int point[]: points)
            if (point[1] > end) {
                end = point[1];
                ++arrows;
            }
        
        return arrows;
    }

    // Alternate solution on leetcode
    private static int findMinArrowShots2(int points[][]) {
        Arrays.sort(points);
        int end = points[0][1], ans = 0;
        for(int point[]: points) 
            if(end >= point[0]) {
                end = Integer.min(end, point[1]);
            } else {
                ans++;
                end = point[1];
            }
        
        return ans + 1;
    }
}