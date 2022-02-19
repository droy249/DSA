/* Given an array of integers, find the closest (not considering distance, but value) greater on left of every element. If an element has no greater on the left side, print -1.
 *
 * Video Link: https://youtu.be/T5s96ynzArg?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
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

        for(int i{nums.size() - 2}; ~i; --i)
            for(int j{i - 1}; ~j; --j)
                if(nums.at(j) > nums.at(i)){
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
        
        for(const int& num: nums)
        {
            if (stack.empty())
            {
                result.push_back(-1);
            }
            else if (!stack.empty() && stack.top() > num)
            {
                result.push_back(stack.top());
            }
            else if (!stack.empty() && stack.top() <= num)
            {
                while (!stack.empty() && stack.top() <= num)
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
            
            stack.emplace(num);
        }
              
        return result;
    }

    /* Simplified version
     * Time Complexity: O(2n)
     * Space Complexity: O(n) 
     */
    vector<int> nextGreaterElementsSimplified(vector<int>& nums){
        vector<int> result;
        stack<int> stack;

        for(const int& num: nums){
            while (!stack.empty() && stack.top() <= num) stack.pop();
            result.emplace_back(stack.empty() ? -1 : stack.top());
            stack.emplace(num);            
        }

        return result;
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