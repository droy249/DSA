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

    for (int i{nums.size() - 2}; ~i; --i) {
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

void display(ListNode* head) {
    if (!head) {
        cout << "Empty\n\n";
        return;
    }

    for (ListNode* ptr{head}; ptr; ptr = ptr->next)
        cout << ptr->val << "->";
    cout << "null\n\n";
}

// Question Link: https://nados.io/question/reverse-linked-list-pointer-iterative
// Video Link: https://youtu.be/71NqKy7287g?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/reverse-linked-list/
ListNode* reverseList(ListNode* head) {
    ListNode *curr = head, *before = nullptr, *after = nullptr;
    while (curr) {
        after = curr->next;
        curr->next = before;
        before = curr;
        curr = after;
    }
    return before;
}

int main() {
    ListNode* head{construct({1, 2, 3, 4, 5})};
    cout << "Given linked list: ";
    display(head);

    cout << "Linked list after reversing: ";
    display(reverseList(head));

    destruct(head);
    // display(head);
    // cout << "\n\n";
}