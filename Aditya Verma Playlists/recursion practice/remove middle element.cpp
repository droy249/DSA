#include <iostream>
#include <stack>
using namespace std;

void removeMiddleElement(stack<int>& s, int curr = 0) {
    int n = s.size();
    if(!n || curr == n) return;
    int temp = s.top();
    s.pop();
    removeMiddleElement(s, curr + 1);
    if(curr != (n+2)/2) s.push(temp);
}

void PrintStack(stack<int>& s) {
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

int main() {
	stack<int> vec { {0,2,1,5,3,6,2} };
	cout << endl << "Before: ";
	PrintStack(vec);
	// reverseStack(vec);
    cout << endl;
	removeMiddleElement(vec);
	cout << endl << "After: ";
	PrintStack(vec);
    cout<<endl;
	return 0;
}