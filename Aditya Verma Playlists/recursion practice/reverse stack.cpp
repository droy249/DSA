#include <iostream>
#include <stack>
using namespace std;

void insertStack(stack<int>& s, int t) {
    if(s.empty()) {
        s.push(t); return;
    }
    int x = s.top();
    s.pop();
    insertStack(s, t);
    s.push(x);
}

void reverseStack(stack<int>& s) {
    if(s.empty()) return;
    int t = s.top();
    s.pop();
    reverseStack(s);
    insertStack(s, t);
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
	reverseStack(vec);
	cout << endl << "After: ";
	PrintStack(vec);
    cout << endl << endl;
	return 0;
}
