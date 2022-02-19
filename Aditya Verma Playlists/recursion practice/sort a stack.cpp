#include <iostream>
#include <stack>
using namespace std;

void PrintStack(stack<int> s) {
    if (s.empty()) return;
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

void insertBack(stack<int>& v, int& t) {
    if(v.empty() || v.top() <= t) {
        v.push(t); return;
    }
    int temp = v.top();
    v.pop();
    insertBack(v, t);
    v.push(temp);
}

void sortstack(stack<int>& arr) {
    if(arr.size() < 2u) return;
    int temp = arr.top();
    arr.pop();
    sortstack(arr);
    insertBack(arr, temp);
}

int main() {
	stack<int> vec { {0,2,1,5,3,6,2} };
	sortstack(vec);
	PrintStack(vec);
	return 0;
}
