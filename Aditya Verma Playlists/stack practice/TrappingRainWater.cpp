/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. (Source: )
 * Input: arr[]   = {2, 0, 2}
 * Output: 2
 * Structure is like below
 * | |
 * |_|
 * We can trap 2 units of water in the middle gap.
 * 
 * Video Link: https://youtu.be/FbGG2qpNp4U?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
 * Gfg Link: https://www.geeksforgeeks.org/trapping-rain-water/
 * Leetcode Link: https://leetcode.com/problems/trapping-rain-water/
 * Link for other aprroaches: https://leetcode.com/problems/trapping-rain-water/solution/
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* Brute Force approach
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int bruteForce(vector<int>& height) {
    int ans = 0;
    for(int i = 0; i < height.size(); ++i) {
        int left_max = 0, right_max = 0;
        
        for (int j = 0; j < height.size(); j++) {
            left_max = max(left_max, height[j]); 
            right_max = max(right_max, height[j]);
        }

        ans += min(left_max, right_max) - height.at(i);
    }

    return ans;
}

/* 3-pass DP approach by Aditya Verma
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int dpApproach(vector<int>& height) {
    int size(height.size());

    int maxLeft[size];
    int maxRight[size];
    int water[size];

    maxLeft[0] = height[0];
    for (int i = 1; i < size; i++)
        maxLeft[i] = max(maxLeft[i - 1], height.at(i));
    
    maxRight[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--)
        maxRight[i] = max(maxRight[i + 1], height.at(i));
    
    for(int i = 0; i < size; i++)
        water[i] = min(maxLeft[i], maxRight[i]) - height.at(i);
    
    int waterSum(0);
    for(int i = 0; i < size; ++i)
        waterSum += water[i];

    return waterSum;
}

/* 1-pass Stack approach
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int stackApproach(vector<int>& height) {
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}

/* 1 pass 2-pointer approach
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int twpPointerApproach(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

int main() {
    cout << "Enter heights of buildings: ";
    int height = 0;
    vector<int> heights;

    while (height > 0) 
    {
        cin >> height;
        heights.push_back(height);
    }

    cout << "Maximum amount of rainwater trapped: " << dpApproach(heights);
}