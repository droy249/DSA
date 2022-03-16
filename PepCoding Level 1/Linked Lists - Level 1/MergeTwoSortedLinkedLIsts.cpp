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

// Approach 1: Using extra space (Pepcoding approach)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy{};
    ListNode* head{&dummy};

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

    return dummy.next;
}

// Approach 2: Without extra space
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    ListNode dummy{};
    ListNode* tail{&dummy};

    while (l1 and l2)
        if (l1->val < l2->val) {
            tail = tail->next = l1;
            l1 = l1->next;
        } else {
            tail = tail->next = l2;
            l2 = l2->next;
        }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Approach 3: Approach 2 using recursion
ListNode* mergeTwoLists3(ListNode* l1, ListNode* l2) {
    ListNode* result{nullptr};

    if (!l1)
        return l2;
    else if (!l2)
        return l1;

    if (l1->val > l2->val) {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    } else {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    }

    return result;
}

int main() {
    ListNode* head1{construct({1, 2, 3, 4, 5})};
    cout << "Linked list 1: ";
    display(head1);

    ListNode* head2{construct({1, 2, 3, 4, 5})};
    cout << "Linked list 2: ";
    display(head2);

    cout << "List obtained after merging both lists is : ";
    ListNode* head{mergeTwoLists3(head1, head2)};
    display(head);

    destruct(head1);
    destruct(head2);
    destruct(head);
    cout << "\n\n";
}