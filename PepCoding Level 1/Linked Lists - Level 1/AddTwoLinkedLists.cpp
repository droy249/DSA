// Question Link: https://nados.io/question/add-two-linked-lists
// Video Link: https://youtu.be/tK4eez3syAQ?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/add-two-numbers-ii/
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
}

int main() {
    ListNode* head1{construct({7,2,4,3})};
    cout << "\nLinked list 1: ";
    display(head1);

    ListNode* head2{construct({7,2,4,3})};
    cout << "\nLinked list 2: ";
    display(head2);    

    cout << "Linked List after segregating odd and even values: ";
    ListNode* head{addTwoNumbers(head1, head2)};
    display(head);

    destruct(head1);
    destruct(head2);
    destruct(head);
}