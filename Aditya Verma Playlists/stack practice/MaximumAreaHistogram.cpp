/* Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.
 * 
 * Video Link: https://youtu.be/J2X70jj_I1o?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
 * Striver 1-Pass Video Link: https://youtu.be/jC_cWLy7jSI?list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj
 * Gfg Link: https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 * Leetcode Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* Two pass solution using stack
 * Time Complexity: O(4n) => O(n)
 * Space Complexity: O(n)
 */
int largestRectangleAreaAdityaVerma(vector<int>& heights) {
    int n(heights.size());
    stack<int> stack;
    
    // Calculating "Nearest Greater to Left" and storing respective indices in left[] array
    int left[n];
    for(int i{}; i < n; ++i){
        while(!stack.empty() and heights.at(stack.top()) >= heights.at(i)) 
            stack.pop();
        left[i] = stack.empty() ? -1 : stack.top();
        stack.emplace(i);
    }
    
    // Emptying stack for next
    while(!stack.empty()) stack.pop();
    
    // Calculating "Nearest Greater to Right" and storing respective indices in right[] array
    int right[n];
    for(int i{n - 1}; ~i; --i){
        while(!stack.empty() and heights.at(stack.top()) >= heights.at(i))
            stack.pop();
        right[i] = stack.empty() ? n : stack.top();
        stack.emplace(i);
    }
    
    int maxArea{};

    // Calculating greatest area by calculating {heights[i] * width[i]} and comparing 
    for(int i{}; i < n; ++i)
        maxArea = max(maxArea, heights.at(i) * (right[i] - left[i] - 1));
    
    return maxArea;
}

int largestRectangleAreaStriver(vector<int>& heights) {
    int maxArea{};
    stack<int> stack;

    for (int i{}; i < heights.size(); ++i) {
        //TBD
    }
    
    return maxArea;
}

int main() {
    cout << "Enter heights of histogram: ";
    int height{};
    vector<int> heights;

    while (height > 0) 
    {
        cin >> height;
        heights.emplace_back(height);
    }

    cout << "Largest possible area of a rectangle in given histogram is:" << endl;
    cout << "Aditya Verma (Two Pass) Approach: " << largestRectangleAreaAdityaVerma(heights);
    cout << "Striver (One Pass) Approach: " << largestRectangleAreaStriver(heights);
}