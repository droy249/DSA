// Gfg Link: https: www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// Practice Link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1/
#include <bits/stdc++.h>
using namespace std;

// Video Link: https://youtu.be/bzXM1Zond9U?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
// Time Complexity: O(n ^ 3)
// Space Complexity: O(n ^ 2)
class MemoizeWithPairs {
    vector<vector<pair<int, int>>> dp;

    // Use a pair to store both true and false respectively for left or right subexpression
    pair<int, int> memoizeWithVectorOfPair(string &s, int i, int j) {
        if (i > j)
            return dp[i][j] = {0, 0};

        if (i == j)
            return dp[i][j] = s[i] == 'T' ? make_pair(1, 0) : make_pair(0, 1);

        if (dp[i][j] != make_pair(-1, -1)) return dp[i][j];

        int trueCount = 0;
        int falseCount = 0;

        // K simply iterates over the operators ONLY
        for (int k = i + 1; k <= j; k += 2) {
            auto [leftTrue, leftFalse] = dp[i][k - 1] != make_pair(-1, -1) ? dp[i][k - 1]
                                                                           : memoizeWithVectorOfPair(s, i, k - 1);  // left subString s(i ... k-1)
            auto [rightTrue, rightFalse] = dp[i + 1][j] != make_pair(-1, -1) ? dp[k + 1][j]
                                                                             : memoizeWithVectorOfPair(s, k + 1, j);  // right subString s(k+1 ... j)

            switch (s[k]) {
                case '&':
                    trueCount += leftTrue * rightTrue;
                    falseCount += leftFalse * rightFalse + leftFalse * rightTrue + leftTrue * rightFalse;
                    break;

                case '|':
                    trueCount += leftTrue * rightFalse + leftFalse * rightTrue + leftTrue * rightTrue;
                    falseCount += leftFalse * rightFalse;
                    break;

                case '^':
                    trueCount += leftFalse * rightTrue + leftTrue * rightFalse;
                    falseCount += leftFalse * rightFalse + leftTrue * rightTrue;
                    break;
            }

            trueCount %= 1003;
            falseCount %= 1003;
        }

        return dp[i][j] = {trueCount, falseCount};
    }

   public:
    int countWays(int N, string S) {
        dp.resize(N + 1, vector<pair<int, int>>(N + 1, {-1, -1}));
        return memoizeWithVectorOfPair(S, 0, N - 1).first;
    }
};

class MemoizeWith3dArray {
    int t[205][205][2];

    long memoizeWith3dArray(string s, int i, int j, bool isTrue) {
        if (i > j)
            return 0;

        if (i == j) {
            if (isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (t[i][j][isTrue] != -1)
            return t[i][j][isTrue];

        long ans = 0, lt, lf, rt, rf;

        for (int k = i + 1; k < j; k = k + 2) {
            if (t[i][k - 1][1] != -1) {
                lt = t[i][k - 1][1];
            } else {
                lt = memoizeWith3dArray(s, i, k - 1, true);
                t[i][k - 1][1] = lt;
            }

            if (t[i][k - 1][0] != -1) {
                lf = t[i][k - 1][0];
            } else {
                lf = memoizeWith3dArray(s, i, k - 1, false);
                t[i][k - 1][0] = lf;
            }

            if (t[k + 1][j][1] != -1) {
                rt = t[k + 1][j][1];
            } else {
                rt = memoizeWith3dArray(s, k + 1, j, true);
                t[k + 1][j][1] = rt;
            }

            if (t[k + 1][j][0] != -1) {
                rf = t[k + 1][j][0];

            } else {
                rf = memoizeWith3dArray(s, k + 1, j, false);
                t[k + 1][j][0] = rf;
            }

            switch (s[k]) {
                case '&':
                    if (isTrue == true)
                        ans += lt * rt;
                    else
                        ans += lt * rf + lf * rt + lf * rf;
                    break;

                case '|':
                    if (isTrue == true)
                        ans += lt * rf + lf * rt + lt * rt;
                    else
                        ans += lf * rf;
                    break;

                case '^':
                    if (isTrue == true)
                        ans += rt * lf + rf * lt;
                    else
                        ans += rt * lt + rf * lf;
                    break;
            }
        }

        return t[i][j][isTrue] = ans % 1003;
    }

   public:
    int countWays(int N, string S) {
        memset(t, -1, sizeof t);
        return memoizeWith3dArray(S, 0, S.size() - 1, true);
    }
};

class MemoizeWithPairOfStringInt {
     unordered_map<string,int> mp;
    
    int solve(string S,int i,int j, bool isTrue)
    {
        if(i > j) return 0;
        if(i == j) {
            if(isTrue) {
                return S[i] == 'T' ? 1 : 0;
            }
            else {
                return S[i] == 'F' ? 1 : 0;
            }
        }
        
        string key = to_string(i);
        key.push_back(' ');
        key.append(to_string(j));
        key.push_back(' ');
        key.append(to_string(isTrue));
        
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }
        
        int ans = 0;
        
        for(int k = i+1; k<=j-1; k=k+2)
        {
            int leftTrue, leftFalse, rightTrue, rightFalse;
            
            string leftTruekey = to_string(i);
            leftTruekey.push_back(' '); 
            leftTruekey.append(to_string(k-1)); 
            leftTruekey.push_back(' '); 
            leftTruekey.append(to_string(true));
            
            string leftFalsekey = to_string(i);
            leftFalsekey.push_back(' '); 
            leftFalsekey.append(to_string(k-1)); 
            leftFalsekey.push_back(' '); 
            leftFalsekey.append(to_string(false));
            
            string rightTruekey = to_string(k+1); 
            rightTruekey.push_back(' '); 
            rightTruekey.append(to_string(j)); 
            rightTruekey.push_back(' '); 
            rightTruekey.append(to_string(true));
            
            string rightFalsekey = to_string(k+1); 
            rightFalsekey.push_back(' '); 
            rightFalsekey.append(to_string(j)); 
            rightFalsekey.push_back(' ');
            rightFalsekey.append(to_string(false));
            
            if(mp.find(leftTruekey) != mp.end()) {
                leftTrue = mp[leftTruekey];
            }
            else {
                leftTrue = solve(S,i,k-1,true);
            }
            
            if(mp.find(leftFalsekey) != mp.end()) {
                leftFalse = mp[leftFalsekey];
            }
            else {
                leftFalse = solve(S,i,k-1,false);
            }
            
            if(mp.find(rightTruekey) != mp.end()) {
                rightTrue = mp[rightTruekey];
            }
            else {
                rightTrue = solve(S,k+1,j,true);
            }
            
            if(mp.find(rightFalsekey) != mp.end()) {
                rightFalse = mp[rightFalsekey];
            }
            else {
                rightFalse = solve(S,k+1,j,false);
            }
            
            if(S[k] == '&') 
            {
                if(isTrue) {
                    ans = ans + leftTrue*rightTrue; 
                }
                else {
                    ans = ans + leftFalse*rightTrue + leftTrue*rightFalse + leftFalse*rightFalse;  
                }
            }
            else if(S[k] == '|') 
            {
                if(isTrue) {
                    ans = ans + leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue;
                }
                else {
                    ans = ans + leftFalse*rightFalse;  
                }
            }
            else // S[k] == "^" 
            {
                if(isTrue) {
                    ans = ans + leftFalse*rightTrue + leftTrue*rightFalse; 
                }
                else {
                    ans = ans + leftTrue*rightTrue + leftFalse*rightFalse;  
                }
            }
            
        }
        return mp[key] = ans % 1003;
    }
    
public:
    int countWays(int N, string S){
        mp.clear();
        return solve(S,0,N-1,true);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s{"T&F|T^F"};
    cout << "The number of ways to parenthesize " << s << " so that it evaluates to true: \n";

    MemoizeWithPairs ob1;
    cout << "Memoize with vector of vector of pairs: " << ob1.countWays(s.length(), s);

    MemoizeWith3dArray ob2;
    cout << "Memoize with 3d array: " << ob2.countWays(s.length(), s);

    MemoizeWithPairOfStringInt ob3;
    cout << "Memoize with map of string to int: " << ob3.countWays(s.length(), s);
}