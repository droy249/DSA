/* Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
 * Example:
 * 
 * Input:   0 1 1 0
 *          1 1 1 1
 *          1 1 1 1
 *          1 1 0 0
 * 
 * Output:  1 1 1 1
 *          1 1 1 1
 * 
 * Video Link: https://youtu.be/St0Jf_VmG_g?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
 * Gfg Link: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
 * Leetcode Link: https://leetcode.com/problems/maximal-rectangle/
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* Maximum Area Histogram code:
 * Time Complexity: O(m), where m -> length of column of matrix
 * Space Complexity: O(m)
 */
int largestRectangleArea(vector<int>& heights) {
        int n(heights.size());
        stack<int> stack;
        
        int left[n];
        for(int i{}; i < n; ++i){
            while(!stack.empty() and heights.at(stack.top()) >= heights.at(i)) 
                stack.pop();
            left[i] = stack.empty() ? -1 : stack.top();
            stack.emplace(i);
        }
        
        while(!stack.empty()) stack.pop();
        
        int right[n];
        for(int i{n - 1}; ~i; --i){
            while(!stack.empty() and heights.at(stack.top()) >= heights.at(i))
                stack.pop();
            right[i] = stack.empty() ? n : stack.top();
            stack.emplace(i);
        }
        
        int maxArea{};
        for(int i{}; i < n; ++i)
            maxArea = max(maxArea, heights.at(i) * (right[i] - left[i] - 1));
        
        return maxArea;
    }

/* Function to calculate max area in Binary matrix
 * Time Complexity: O(n * m), where n -> number of rows, m -> number of columns
 * Space Complexity: O(m) , from largestAreaRectangle(nums) function
 */
int maximalRectangle(vector<vector<char>>& matrix) {
    int maxArea{};
    vector<int> nums(matrix.front().size());
    
    for(const auto& row: matrix){
        for(int i{}; i < row.size(); ++i)
            nums.at(i) = row.at(i) - '0' ? nums.at(i) + row.at(i) - '0' : 0;
        
        maxArea = max(maxArea, largestRectangleArea(nums));
    }
    
    return maxArea;
}

int main() {
    cout << "Enter number if rows: ";
    int rowSize; cin >> rowSize;

    cout << "Enter number of columns: ";
    int colSize; cin >> colSize;

    vector<vector<char>> matrix{rowSize, vector<char>(colSize)};

    for(auto &&row : matrix)
        for (auto &&cell : row)
            cin >> cell;
    
    cout << endl << "Maximum area of binary rectangle in given matrix is: " << maximalRectangle(matrix);
}