// Video Link Part 1: https://www.youtube.com/watch?v=cyu_nuW5utA&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=7
// Video Link Part 2: https://www.youtube.com/watch?v=TfQPoaRDeMQ&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=8
// Gfg Link: https://www.geeksforgeeks.org/longest-sub-array-sum-k/
// Gfg Practice Link: https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/
// Equivalent Leetcode Link: https://leetcode.com/problems/minimum-size-subarray-sum/
#include <bits/stdc++.h>
using namespace std;

// This correct approach which works for all inputs;
int lenOfLongSubarr(int A[], int N, int K) {
    unordered_map<int, int> mp;
    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += A[i];

        if (sum == K) {
            maxLen = max(i + 1, maxLen);
        } else if (mp.find(sum - K) != mp.end()) {
            maxLen = max(i - mp[sum - K], maxLen);
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxLen;
}

// This Aditya Verma's Approach to explain this concept 
// for positive numbers ONLY
int adityaVerma(int A[], int N, int K) {
    int i = 0, j = 0;
    long long sum = 0;
    int ans = 0;

    while (j < N) {
        sum += A[j];

        if (sum < K) {
            ++j;
        } else if (sum == K) {
            ans = max(ans, j - i + 1);
            sum -= A[i];

            ++i;
            ++j;
        } else {  // sum > K
            while (sum > K) {
                sum -= A[i];
                ++i;
            }

            if (sum == K) {
                ans = max(ans, j - i + 1);
            }

            ++j;
        }
    }

    return ans;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    cout << "Largest substring of sum K is of size: " << lenOfLongSubarr(arr, sizeof(arr) / sizeof(*arr), 15);
}