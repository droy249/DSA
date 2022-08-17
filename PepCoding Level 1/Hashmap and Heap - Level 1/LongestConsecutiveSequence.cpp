// Question Link: https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/lcqs-official/ojquestion
// Video Link: 
// Leetcode Link: https://leetcode.com/problems/longest-consecutive-sequence/
#include <bits/stdc++.h>
using namespace std;

// Leetcode solution using unordered_set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        int longestStreak{};
        for (int num : num_set) {
            if (num_set.find(num - 1) == num_set.end()) {
                int currentStreak{1};
                while (num_set.find(num + currentStreak) != num_set.end()) {
                    ++currentStreak;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main() {
    vector<int> nums{0,3,7,2,5,8,4,6,0,1};
    Solution ob;
    cout << "\nLength of longest sequence: " << ob.longestConsecutive(nums) << "\n";

    // Pepcoding solution using unordered_map
    unordered_map<int,bool> mp;
    for(auto& num : nums) mp[num] = true;

    for(auto& num : nums) mp[num] = mp.find(num - 1) == mp.end();

    int maxStreak{};
    int maxNum{};
    for(auto& [num, isBegin] : mp)
        if(isBegin) {
            int curStreak{1};
            
            while (mp.find(num + curStreak) != mp.end())
                ++curStreak;

            if (curStreak > maxStreak) {
                maxStreak = curStreak;
                maxNum = num;
            }
        }
    
}
