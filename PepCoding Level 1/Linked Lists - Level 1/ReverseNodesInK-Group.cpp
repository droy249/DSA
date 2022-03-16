// Question Link: https://nados.io/question/k-reverse-in-linked-list
// Video Link: https://youtu.be/jhm2pYGFIos?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
#include <iostream>
#include <stack>
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

ListNode* reverse(ListNode* head, ListNode* tail) {
    auto prev = tail;
    while (head != tail) {
        auto tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    return prev;
}

// https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11435/C%2B%2B-Elegant-and-Small
ListNode* reverseKGroup1(ListNode* head, const int& k) {
    auto node = head;

    for (int i{}; i < k; ++i)
        if (!node)
            return head;
        else
            node = node->next;

    auto newHead = reverse(head, node);
    head->next = reverseKGroup1(node, k);
    return newHead;
}

ListNode* reverseKGroup2(ListNode* head, int k) {
    stack<ListNode*> st;
    ListNode *curr{head}, *prev;

    while (curr) {
        // for (int count{}; curr and count < k; st.emplace(curr), ++count, curr = curr->next)
        //     ;

        int count{};
        while (curr != NULL && count < k) {
            st.push(curr);
            curr = curr->next;
            count++;
        }

        while (!st.empty()) {
            if (!prev)
                curr = prev = st.top();
            else
                prev = prev->next = st.top();

            st.pop();
        }
    }

    prev->next = nullptr;
    return head;
}

int main() {
    ListNode* head{construct({2, 8, 9, 1, 5, 4, 3})};
    cout << "\nGiven linked list: ";
    display(head);

    cout << "Enter k: ";
    int k;
    cin >> k;

    cout << "Linked List after reversing in groups of " << k << " : ";
    display(head = reverseKGroup2(head, k));

    destruct(head);
}