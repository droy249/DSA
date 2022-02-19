// Question Link: https://www.pepcoding.com/resources/online-java-foundation/linked-lists/merge-two-sorted-linked-lists-official/ojquestion
// Question Link 2: https://nados.io/question/merge-two-sorted-linked-lists
// Video Link: https://youtu.be/6vFEuO1pfJA?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/merge-two-sorted-lists/
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head{new ListNode()};
    ListNode* res{head};

    while (list1 and list2) {
        if (list1->val < list2->val) {
            head = head->next = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            head = head->next = new ListNode(list2->val);
            list2 = list2->next;
        }
    }

    while (list1) {
        head = head->next = new ListNode(list1->val);
        list1 = list1->next;
    }

    while (list2) {
        head = head->next = new ListNode(list2->val);
        list2 = list2->next;
    }

    return res->next;
}

int main() {
    ListNode* head1{construct({1, 2, 3, 4, 5})};
    cout << "Linked list 1: ";
    display(head1);

    ListNode* head2{construct({1, 2, 3, 4, 5})};
    cout << "Linked list 2: ";
    display(head2);

    cout << "List obtained after merging both lists is : ";
    ListNode* head{mergeTwoLists(head1, head2)};
    display(head);

    destruct(head1);
    destruct(head2);
    destruct(head);
    cout << "\n\n";
}