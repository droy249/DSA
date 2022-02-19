// Question Link: https://nados.io/question/mid-of-linked-list
// Video Link: https://youtu.be/jEfzUFcgGkk?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/middle-of-the-linked-list/
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

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}

int main() {
    ListNode* head{construct({1, 2, 3, 4, 5})};
    cout << "Given linked list: ";
    display(head);

    cout << "List starting from middle node of linked list: ";
    display(middleNode(head));

    destruct(head);
    // display(head);
    cout << "\n\n";
}