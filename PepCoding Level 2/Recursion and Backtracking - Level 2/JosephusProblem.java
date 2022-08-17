// Video Link: https://youtu.be/dzYq5VEMZIg?list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0
// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/josephus-problem-official/ojquestion
public class JosephusProblem {
    public static void main(String[] args) {
        int n = 4, k = 2;
        System.out.println("Person who survives: " + josepuhs(n, k));
    }

    private static int  josepuhs(int n, int k) {
        if(n == 1) {
            return 0;
        }

        int survivorOfN_1 = josepuhs(n - 1, k);
        return (survivorOfN_1 + k) % n;
    }
}
