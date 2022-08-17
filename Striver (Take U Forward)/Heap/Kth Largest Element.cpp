// Striver Sheet Link: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
// Leetcode Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// All Approaches: https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
// All Approaches 2: https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/893847/C%2B%2B-Ten-Solutions

#include <bits/stdc++.h>
using namespace std;

int usingNth_element(vector<int> nums, int k) {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    return nums.at(k - 1);
    // nth_element(nums.begin(), nums.begin() + nums.size() - k, nums.end());
    // return nums[nums.size() - k];
}

int usingPartial_sort(vector<int> nums, int k) {
    partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
    return nums.at(k - 1);
    // partial_sort(nums.begin(), nums.begin() + nums.size() - k + 1, nums.end());
    // return nums[nums.size() - k];
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
int usingMinHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int& num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

// Time Complexity : O(n + k log n)
// Space Complexity: O(n)
int usingMaxHeap(vector<int>& nums, int k) {
    priority_queue<int> maxHeap(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {  // since the kth largest will be at (k - 1)th index, remove all others
        maxHeap.pop();
    }
    return maxHeap.top();
}

// Time Complexity: O(n) {avg}, O(n ^ 2) {worst}
// Space Complexity: O(n)
int quickSelect(vector<int>&, int, int, int);
int usingQuickselect(vector<int> nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);

    // int lo = 0, hi = nums.size() - 1;
    // k = nums.size() - k;
    // int kth = nums[0];

    // while (lo <= hi) {
    //     int num = nums[hi];
    //     stable_partition(nums.begin() + lo, nums.begin() + hi + 1, [&](auto& x) { return x <= num; });
    //     int pi = partition_point(nums.begin() + lo, nums.begin() + hi + 1, [&](auto& x) { return x <= num; }) - nums.begin();

    //     if(k == pi) {
    //         kth = nums[pi];
    //         break;
    //     } else if(k < pi) {
    //         hi = pi - 1;
    //     } else {
    //         lo = pi + 1;
    //     }
    // }

    // return kth;
}

int quickSelect(vector<int>& nums, int lo, int hi, int k) {
    int num = nums.back();
    stable_partition(nums.begin() + lo, nums.begin() + hi + 1, [&](auto& x) { return x <= num; });
    int pi = partition_point(nums.begin() + lo, nums.begin() + hi + 1, [&](auto& x) { return x <= num; }) - nums.begin();

    if (k == pi) {
        return nums[pi];
    } else if (k < pi) {
        return quickSelect(nums, lo, pi - 1, k);
    } else {
        return quickSelect(nums, pi + 1, hi, k);
    }
}

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};  // 4
    int k = 4;

    cout << "Using nth_element: " << usingNth_element(nums, k) << "\n";
    cout << "Using partial_sort: " << usingPartial_sort(nums, k) << "\n";
    cout << "Using min heap: " << usingMinHeap(nums, k) << "\n";
    cout << "Using max Heap: " << usingMaxHeap(nums, k) << "\n";
    cout << "Using quickselect: " << usingQuickselect(nums, k) << "\n";
}
