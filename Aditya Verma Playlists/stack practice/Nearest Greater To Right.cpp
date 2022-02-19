/* Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1. 
 *
 * Video Link: https://youtu.be/NXOOYYwpbg4?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
 * Gfg Link: https://www.geeksforgeeks.org/next-greater-element/
 * Leetcode Link: https://leetcode.com/problems/next-greater-element-i/
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /* Brute Force Version 
     * Time Complexity: O(n ^ 2)
     * Space Complexity: O(1) 
     */
    vector<int> nextGreaterElementsWithoutStack(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        
        for(int i{}; i < nums.size() - 1; ++i)
            for (int j{i + 1}; j < nums.size(); ++j)
                if(nums.at(j) < nums.at(i)){
                    result.at(i) = nums.at(j);
                    break;
                }
            
        return result;
    }
    
    /* Aditya Verma Version 
     * Time Complexity: O(2n)
     * Space Complexity: O(n) 
     */
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;
        stack<int> st;

        for(int i = nums.size() - 1; i >= 0; --i)
        {
            if (st.empty())
            {
                result.push_back(-1);
            }
            else if (!st.empty() && st.top() > nums[i])
            {
                result.push_back(st.top());
            }
            else if (!st.empty() && st.top() <= nums[i])
            {
                while (!st.empty() && st.top() <= nums[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    result.push_back(-1);
                }
                else
                {
                    result.push_back(st.top());
                }
                
            }
            
            st.emplace(nums.at(i));
        }
              
        return vector<int> (result.rbegin(), result.rend());
    }
    
    /* Simplified version
     * Time Complexity: O(2n)
     * Space Complexity: O(n) 
     */
    vector<int> nextGreaterElementsSimplified(vector<int>& nums) {
        vector<int> result;
        stack<int> st;
        
        for(int i{nums.size()-1}; ~i; --i){
            while(!st.empty() && st.top() <= nums.at(i)) st.pop();
            result.emplace_back(st.empty() ? -1 : st.top());
            st.emplace(nums.at(i));
        }

        return vector<int> (result.rbegin(), result.rend());
    }
};

int main(){
    cout << "Enter array: ";
    vector<int> nums;
    int num;
    while(cin >> num)
        nums.emplace_back(num);
    cout << endl;

    Solution ob;
    cout << "Next greater element on the right for given array is: " << endl;
    
    for(const int& num : ob.nextGreaterElementsWithoutStack(nums))
        cout << num << ' ';
    cout << endl;
    
    for(const int& num : ob.nextGreaterElements(nums))
        cout << num << ' ';
    cout << endl;

    for(const int& num : ob.nextGreaterElementsSimplified(nums))
        cout << num << ' ';
    cout << endl;
}
