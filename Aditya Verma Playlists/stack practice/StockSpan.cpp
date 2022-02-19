/* The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
 * The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
 * For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6 
 * 
 * {Based on NEAREST GREATER TO THE LEFT}
 * 
 * Video Link: https://youtu.be/p9T-fE1g1pU?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
 * Gfg Link: https://www.geeksforgeeks.org/the-stock-span-problem/
 * Leetcode Link: https://leetcode.com/problems/online-stock-span/
 * */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* Brute Force Version
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
vector<int> stockSpanBruteForce(vector<int>& prices) {
    vector<int> spans(prices.size());
    
    for(int i{}; i < prices.size(); ++i)
        for(int j{i}; j >= 0; --j){
            if(prices.at(j) <= prices.at(i))
                ++spans.at(i);
            else
                break;
        }
            // spans.at(i) += prices.at(i) >= prices.at(j);
        
    return spans;
}

/* Aditya Verma Version
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> stockSpanAdityaVerma(vector<int>& prices) {
    vector<int> spans;
    stack<int> stack;         // pair.first -> Next Greater to Left, pair.second -> index

    for (int i = 0; i < prices.size(); i++)
    {
        if(stack.empty())
        {
            spans.push_back(-1);
        } 
        else if (!stack.empty() and prices[stack.top()] > prices[i])
        {
            spans.push_back(stack.top());
        }
        else if (!stack.empty() and prices[stack.top()] <= prices[i])
        {
            while (!stack.empty() and prices[stack.top()] <= prices[i])
            {
                stack.pop();
            }

            if (stack.empty())
            {
                spans.push_back(-1);
            }
            else
            {
                spans.push_back(stack.top());
            }
            
        }
        
        stack.push(i);
    }

    // assert(spans.size() == prices.size());
    
    for (int i = 0; i < spans.size(); i++)
    {
        spans[i] = i - spans[i];
    }

    return spans;
}

vector<int> stockSpanSimplified(vector<int>& prices){
    vector<int> spans(prices.size());
    stack<int> stack;

    for(int i{}; i < prices.size(); ++i){
        while(!stack.empty() and prices.at(i) >= prices.at(stack.top())) 
            stack.pop();
        spans.at(i) = i - (stack.empty() ? -1 : stack.top());
        stack.emplace(i);
    }

    return spans;
}

int main() {
    cout << "Enter prices of stock (Press 0 to terminate): ";
    int price{};
    vector<int> prices;

    while (cin >> price and price > 0) 
    {
        prices.emplace_back(price);
    } 
    
    cout << endl << "Stock Spans of given prices (Brute Force): " << endl;
    for (auto &&span : stockSpanBruteForce(prices))
        cout << span << ' ';
    cout << endl;
    
    cout << endl << "Stock Spans of given prices (Optimized): " << endl;
    for (auto &&span : stockSpanAdityaVerma(prices))
        cout << span << ' ';
    cout << endl;

    cout << endl << "Stock Spans of given prices (Simplified): " << endl;
    for (auto &&span : stockSpanSimplified(prices))
        cout << span << ' ';
    cout << endl;
    
}