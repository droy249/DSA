// Video Link: https://youtu.be/xFJXtB5vSmM?list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj
// Leetcode Link: https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k >= nums.size()) {
        return {*max_element(nums.begin(), nums.end())};
    }

    vector<int> ans;
    list<int> l;

    int i = 0, j = 0;

    while (j < nums.size()) {
        if (l.empty()) {
            l.push_back(nums[j]);
        } else {
            while (!l.empty() && l.back() < nums[j]) {
                l.pop_back();
            }
            l.push_back(nums[j]);
        }

        int window = j - i + 1;

        if (window < k) {
            ++j;
        } else if (window == k) {
            ans.push_back(l.front());
            if (l.front() == nums[i]) {
                l.pop_front();
            }

            ++i;
            ++j;
        }
    }

    return ans;
}

int main() {
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};

    cout << "\nMaximum of all subarrays of size k:\n";
    for (auto& num : maxSlidingWindow(nums, 3)) {
        cout << num << " ";
    }
    cout << "\n";
}