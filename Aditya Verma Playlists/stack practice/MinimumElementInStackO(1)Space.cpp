/* Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.
 * 
 * Video Link: https://youtu.be/ZvaRHYYI0-4?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
 * Gfg Link: https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
 * Leetcode Link: https://leetcode.com/problems/min-stack/
 */
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    long min;
    stack<long> stack;
public:
    MinStack() : min(LONG_MAX) {}
    
    void push(int val) {
        if(stack.empty()) {
            stack.emplace(val);
            min = val;
        }
        else
            if(val >= min)
                stack.emplace(val);
            else {
                stack.emplace(2l * val - min);
                min = val;
            }
    }
    
    void pop() {
        if(stack.top() >= min)
            stack.pop();
        else {
            min = 2 * min - stack.top();
            stack.pop();
        }
    }
    
    int top() {
        return stack.top() >= min ? stack.top() : min;
    }
    
    int getMin() {
        return min;
    }
};

int main() {
    cout << "----------------------MENU----------------------" << endl;
    cout << "1. Create a new instance" << endl;
	cout << "2. Push value to stack" << endl;
	cout << "3. Pop value from stack" << endl;
	cout << "4. Return top of stack" << endl;
	cout << "5. Return minimum value of stack" << endl;
	cout << "6. Exit" << endl;

    MinStack* obj;
	int ch = 0;
	while (ch != 6){
		cout << endl << "Enter your choice: ";
		cin >> ch;

        switch(ch) {
            case 1:
                if(obj == nullptr)
                    obj = new MinStack();
                else 
                    cout << "Not possible to reinstantiate existing object..." << endl;
                break;
            
            case 2:
                cout << endl << "Enter value to be pushed: ";
                int val; cin >> val;
                obj->push(val);
                break;
            
            case 3:
                obj->pop();
                cout << endl << "Value popped from Stack!" << endl;
                break;
            
            case 4:
                cout << "Value on top of the stack: " << obj->top() << endl;
                break;
            
            case 5:
                cout << "Minimum element of stack: " << obj->getMin() << endl;
                break;
            
            case 6:
                cout << "Exiting..." << endl;
                obj->~MinStack();
                return 0;
            
            default:
                cout << "Incorrect input..." << endl;
        }
	}

}