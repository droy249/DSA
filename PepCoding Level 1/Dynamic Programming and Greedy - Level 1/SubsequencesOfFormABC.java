// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-a+b+c+subsequences-official/ojquestion#
// Video Link: 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SubsequencesOfFormABC {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter input string: ");
        String s = bf.readLine();

        System.out.println("Number of subsequences of the form A+B+C+ is: " + countSubsequences(s));
    }

    private static int countSubsequences(final String s) {
        int aCount = 0, bCount = 0, cCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == 'a' || c == 'A')
                aCount = 2 * aCount + 1;
            else if(c == 'b' || c == 'B')
                bCount = 2 * bCount + aCount;
            else if(c == 'c' || c == 'C')
                cCount = 2 * cCount + bCount;
        }
        return cCount;
    }
}
