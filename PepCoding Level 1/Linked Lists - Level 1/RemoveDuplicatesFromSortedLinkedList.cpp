// Question Link: https://nados.io/question/remove-duplicates-in-a-sorted-linked-list
// Video Link: https://youtu.be/ErSDF5IM1fo?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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

void display(ListNode* head) {
    if (!head) {
        cout << "Empty\n\n";
        return;
    }

    for (ListNode* ptr{head}; ptr; ptr = ptr->next)
        cout << ptr->val << "->";
    cout << "null\n\n";
}

ListNode* deleteDuplicates(ListNode* head) {
    auto node = head;
    while (node and node->next)
        node->val == node->next->val ? node->next = node->next->next : node = node->next;
    return head;
}

int main() {
    ListNode* head{construct({2, 2, 2, 3, 3, 5, 5, 5, 5, 5})};
    cout << "\nGiven linked list: ";
    display(head);

    cout << "Linked List after removing duplicates: ";
    ListNode* head{deleteDuplicates(head)};
    display(head);

    destruct(head);
    cout << "\n\n";
}