// Question Link: https://nados.io/question/odd-even-linked-list
// Video Link: https://youtu.be/calrG6RJ9qI?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Gfg Link: https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* construct(vector<int> nums) {
    ListNode* head{new ListNode(nums.back())};

    for (int i(nums.size() - 2); ~i; --i) {
        ListNode* temp{new ListNode{nums.at(i), head}};
        head = temp;
    }

    return head;
}

void destruct(ListNode*& head) {
    if (!head) return;

    for (ListNode* temp{nullptr}; head;) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

void display(ListNode*& head) {
    if (!head) {
        cout << "Empty\n\n";
        return;
    }

    for (ListNode* ptr{head}; ptr; ptr = ptr->next)
        cout << ptr->val << "->";
    cout << "null\n\n";
}

void segregateOddEven(ListNode*& head) {
    ListNode *oddStart{nullptr}, *oddEnd{nullptr}, *evenStart{nullptr}, *evenEnd{nullptr}, *node{head};

    while (node) {
        if (node->val & 1)
            if (!oddStart)
                oddEnd = oddStart = node;
            else
                oddEnd = oddEnd->next = node;
        else 
            if (!evenStart)
                evenEnd = evenStart = node;
            else
                evenEnd = evenEnd->next = node;

        node = node->next;
    }

    if (!oddStart or !evenStart) return;

    oddEnd->next = evenStart;
    evenEnd->next = nullptr;
    head = oddStart;
}

int main() {
    ListNode* head{construct({2, 8, 9, 1, 5, 4, 3})};
    cout << "\nGiven linked list: ";
    display(head);

    cout << "Linked List after segregating odd and even values: ";
    segregateOddEven(head);
    display(head);

    destruct(head);
}