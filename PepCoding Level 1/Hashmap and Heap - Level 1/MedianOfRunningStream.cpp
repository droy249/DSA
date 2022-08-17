// Question Link: https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/median-priority-queue-official/ojquestion
// Video Link: https://youtu.be/dshWERdcAdg?list=PL-Jc9J83PIiHq5rMZasunIR19QG3E-PAA
// Leetcode Link: https://leetcode.com/problems/find-median-from-data-stream/
// Hackerrank Link: https://www.hackerrank.com/challenges/find-the-running-median/problem?isFullScreen=true
#include <iostream>
#include <queue>
using namespace std;

struct MedianPriorityQueue {
    priority_queue<int> left;                              // maxHeap
    priority_queue<int, vector<int>, greater<int>> right;  // minHeap

    void push(int val) {
        // write your code here
        if (right.size() > 0 and val > right.top()) {
            right.push(val);
        } else {
            left.push(val);
        }
    }

    int pop() {
        // write your code here
        if (this->size() == 0) {
            cout << "Underflow\n";
            return -1;
        }

        int median;
        if (left.size() >= right.size()) {
            median = left.top();
            left.pop();
        } else {
            median = right.top();
            right.pop();
        }
        return median;
    }

    int top() {
        // write your code here
        if (this->size() == 0) {
            cout << "Underflow\n";
            return -1;
        }
        return left.size() >= right.size() ? left.top() : right.top();
    }

    int size() {
        // write your code here
        return left.size() + right.size();
    }
};

int main() {
    MedianPriorityQueue pq;

    string str;
    cin >> str;
    while (str != "quit") {
        if (str == "add") {
            int val;
            cin >> val;
            pq.push(val);
        } else if (str == "remove") {
            int val = pq.pop();
            if (val != -1) {
                cout << val << endl;
            }
        } else if (str == "peek") {
            int val = pq.top();
            if (val != -1) {
                cout << val << endl;
            }
        } else if (str == "size") {
            cout << pq.size() << endl;
        }
        cin >> str;
    }

    return 0;
}