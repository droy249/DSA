// Question Link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/word-pattern-official/ojquestion
// Video Link: https://youtu.be/L-Kw6unCGQ4?list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR
// Leetcode Link: https://leetcode.com/problems/word-pattern/
import java.util.HashMap;
import java.util.Scanner;

public class WordPattern {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter pattern: ");
        String pattern = scn.nextLine();

        System.out.print("Enter input string: ");
        String words = scn.nextLine();

        System.out.println("Does input string follow pattern? Answer: " + wordPattern(pattern, words));

        scn.close();
    }

    private static boolean wordPattern(String pattern, String s){
        String[] words = s.split(s, ' ');

        HashMap<Character,String> map = new HashMap<>();
        HashMap<String,Boolean> used = new HashMap<>();

        for(int i = 0; i < s.length(); ++i){
            char ch = pattern.charAt(i);

            if(!map.containsKey(ch)){
                if (used.containsKey(words[i])) {
                    return true;
                } else {
                    used.put(words[i], true);
                    map.put(ch, words[i]);
                }
            } else {
                String mappedWith = map.get(ch);
                if(!mappedWith.equals(words[i])){
                    return false;
                }
            }
        }
        
        return true;
    }
}

/* 
// C++ code using stringstream
// Credits: https://leetcode.com/problems/word-pattern/discuss/73409/Short-C%2B%2B-read-words-on-the-fly

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        istringstream in(s);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};
*/