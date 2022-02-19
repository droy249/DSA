/* 
 * 
 * Video Link: 
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
    /* Brute Force Version 
     * Time Complexity: O(n ^ 2)
     * Space Complexity: O(1) 
     */
    vector<int> nextGreaterElementsWithoutStack(vector<int>& nums){
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
    vector<int> nextGreaterElements(vector<int>& nums){
        vector<int> result;
        stack<int> stack;
        
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            if (stack.empty())
            {
                result.push_back(-1);
            }
            else if (!stack.empty() && stack.top() < nums.at(i))
            {
                result.push_back(stack.top());
            }
            else if (!stack.empty() && stack.top() >= nums.at(i))
            {
                while (!stack.empty() && stack.top() >= nums.at(i))
                {
                    stack.pop();
                }
                if (stack.empty())
                {
                    result.push_back(-1);
                }
                else
                {
                    result.push_back(stack.top());
                }
                
            }
            
            stack.emplace(nums.at(i));
        }
              
        return vector<int> (result.rbegin(), result.rend());
    }

    /* Simplified version
     * Time Complexity: O(2n)
     * Space Complexity: O(n) 
     */
    vector<int> nextGreaterElementsSimplified(vector<int>& nums){
        vector<int> result;
        stack<int> st;
        
        for(int i{nums.size()-1}; ~i; --i){
            while(!st.empty() && st.top() >= nums.at(i)) st.pop();
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
    cout << "Next greater element on the left for given array is: " << endl;

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