// Question Link: https://nados.io/question/kth-node-from-end-of-linked-list
// Video Link: https://youtu.be/ZVtJu3DpZHU?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

void destruct(ListNode** head) {
    for (ListNode* temp{nullptr}; *head;) {
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    *head = nullptr;
}

void display(ListNode** head) {
    for (ListNode* ptr{*head}; ptr; ptr = ptr->next)
        cout << ptr->val << "->";
    cout << "null\n\n";
}

int kthFromEnd(ListNode* head, int k) {
    ListNode *fast{head}, *slow{head};
    while (--k)
        fast = fast->next;
    while (fast->next)
        slow = slow->next, fast = fast->next;
    return slow->val;
}

int main() {
    ListNode* head{construct({1, 2, 3, 4, 5})};
    cout << "Given linked list: ";
    display(&head);

    cout << "Enter k: ";
    int k;
    cin >> k;
    cout << "Element at kth position from end: " << kthFromEnd(head, k) << "\n\n";

    destruct(&head);
    // display(&head);
}