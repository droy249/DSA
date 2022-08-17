import java.util.Arrays;

public class CountOccurrencesOfAnagrams {
    public static void main(String[] args) {
        String pat = "for", txt = "forxxorfxdofr";
        System.out.println("Number of occurrences of \"" + pat + "\" in \"" + txt + "\" is: " + search(pat, txt));
    }

    private static int search(String pat, String txt) {
        int cnt = 0, mpPat[] = new int[26], mpTxt[] = new int[26];
        
        for (int i = 0; i < pat.length(); i++) {
            ++mpPat[pat.charAt(i) - 'a'];
        }

        for (int start = 0, end = 0; end < txt.length(); ++end) {
            int window = end - start + 1;
            char cur = txt.charAt(end);
            char prev = txt.charAt(start);

            if (window < pat.length()) {
                ++mpTxt[cur - 'a'];
            } else if (window == pat.length()) {
                if (Arrays.equals(mpTxt, mpPat)) {
                    ++cnt;
                }

                ++mpTxt[cur - 'a'];
                --mpTxt[prev- 'a'];
                
                ++start;
            }
        }
        
        System.out.println("pat: " + Arrays.toString(mpPat));
        System.out.println("txt: " + Arrays.toString(mpTxt));

        return cnt;
    }

    
}
