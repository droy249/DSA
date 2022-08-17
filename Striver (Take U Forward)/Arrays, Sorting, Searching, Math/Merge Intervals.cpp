// Question Link: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
// Video Link: https://youtu.be/2JzRBPFYbKE?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
// Leetcode Link: https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>
using namespace std;

/* SOLUTION 1: BRUTE FORCE

Approach: First check whether the array is sorted or not. If not sort the array.
Now linearly iterate over the array and then check for all of its next intervals
whether they are overlapping with the interval at the current index. Take a new
data structure and insert the overlapped interval. If while iterating if the
interval lies in the interval present in the data structure simply continue and
move to the next interval.

TIME COMPLEXITY: O(NlogN)+O(N*N). O(NlogN) for sorting the array, and O(N*N) because
 we are checking to the right for each index which is a nested loop.

SPACE COMPLEXITY: O(N), as we are using a separate data structure.

CODE: 
vector<pair<int, int>> merge(vector<pair<int, int>> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i].first, end = arr[i].second;

        // since the intervals already lies
        // in the data structure present we continue
        if (!ans.empty()) {
            if (start <= ans.back().second) {
                continue;
            }
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[j].first <= end) {
                end = arr[j].second;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}
*/

/* SOLUTION 2: OPTIMAL APPROACH

APPROACH: Linearly iterate over the array if the data structure is empty 
insert the interval in the data structure. If the last element in the data
structure overlaps with the current interval we merge the intervals by 
updating the last element in the data structure, and if the current interval
does not overlap with the last element in the data structure simply insert it 
into the data structure.

Intuition: Since we have sorted the intervals, the intervals which will be 
merging are bound to be adjacent. We kept on merging simultaneously as we were 
traversing through the array and when the element was non-overlapping we simply 
inserted the element in our data structure. 

TIME COMPLEXITY: O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.
SPACE COMPLEXITY: O(N) to return the answer of the merged intervals.

*/
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (auto &&interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

int main() {
    Solution ob;

    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "\nMerged intervals: \n";
    for (auto &&merged : ob.merge(intervals1))
        cout << merged[0] << " " << merged[1] << "\n";

    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    cout << "\nMerged intervals: \n";
    for (auto &&merged : ob.merge(intervals2))
        cout << merged[0] << " " << merged[1] << "\n";
}