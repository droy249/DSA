// Question Link: https://nados.io/question/celebrity-problem
// Video Link: https://youtu.be/CiiXBvrX-5A?list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM
// Gfg Link: https://www.geeksforgeeks.org/the-celebrity-problem/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class CelebrityProblem {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter number of people: ");
        int n = Integer.parseInt(bf.readLine());

        System.out.println("Enter elements of matrix: ");
        int arr[][] = new int[n][n];
        for (int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                arr[i][j] = Integer.parseInt(bf.readLine());

        findCelebrity(arr);
    }

    /** Stack based approach
     * Time complexity: O(n)
     * Space Complexity: O(n)
     * @param {int[][]} arr
     */
    private static void findCelebrity(int arr[][]) {
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            st.push(i);
        }

        while (st.size() >= 2) {
            int i = st.pop();
            int j = st.pop();
            
            if(arr[i][j] == 1) {
                // if i knows j => i is not a celebrity
                st.push(i);
            } else {
                // if i doesn't know j => i is a celebrity
                st.push(j);
            }
        }

        int pot = st.pop();
        for (int i = 0; i < arr.length; i++) {
            if (i != pot) {
                if (arr[i][pot] == 0 || arr[pot][i] == 1) {
                    System.out.println("There are no celebrities.");
                    return;
                }
            }
        }

        System.out.println(pot + " is a celebrity");
    }

    // /** Time Complexity: O(n)
    //  * Space Complexity: O(1)
    //  * @param n
    //  * @return
    //  */
    // public static int findCelebrity(int n) {
    //     int candidate = 0;
		
	// 	// First pass to find out the potential candidate
    //     for (int i = 1; i < n; i ++) {
    //         if (!knows(i, candidate)) {
    //             candidate = i;
    //         }
    //     }
        
	// 	// Second pass to determine if that candidate is a celebrity 
    //     for (int i = 0; i < n; i ++) {
    //         if (i != candidate) {
    //             if (!knows(i, candidate)) {
    //                 return -1;
    //             }
                
    //             if (knows(candidate, i)) {
    //                 return -1;
    //             }
    //         }
    //     }
        
    //     return candidate;
    // }
}
