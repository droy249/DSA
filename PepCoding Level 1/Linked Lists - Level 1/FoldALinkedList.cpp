// Question Link: https://nados.io/question/fold-a-linked-list
// Video Link: https://youtu.be/U4M9O8UxB6I?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/reorder-list/
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

class linked_list {
   private:
    ListNode *head, *tail;
    int size = 0;

   public:
    linked_list() {
        head = NULL;
        tail = NULL;
    }

    void addFirst(int val) {
        ListNode* temp = new ListNode();
        temp->val = val;
        temp->next = head;
        head = temp;

        if (size == 0) {
            tail = temp;
        }

        size++;
    }

    void add_node(int n) {
        ListNode* tmp = new ListNode;
        tmp->val = n;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
    }
    void display() {
        for (ListNode* tmp = head; tmp != NULL; tmp = tmp->next) {
            cout << tmp->val << "->";
        }
        cout << "null\n";
    }

    ListNode* pleft;
    int IsPalindromeHelper(ListNode* right) {
        if (right == NULL) {
            return 1;
        }

        int rres = IsPalindromeHelper(right->next);
        if (rres == 0) {
            return 0;
        } else if (pleft->val != right->val) {
            return 0;
        } else {
            pleft = pleft->next;
            return 1;
        }
    }

    int isPalindrome() {
        pleft = head;
        return IsPalindromeHelper(head);
    }

    void foldHelper(ListNode* right, int floor) {
        if (right == nullptr) return;

        foldHelper(right->next, floor + 1);

        if (floor > size / 2) {
            ListNode* temp = fleft->next;
            fleft->next = right;
            right->next = temp;
            fleft = temp;
        } else if (floor == size / 2) {
            tail = right;
            tail->next = nullptr;
        }
    }

    ListNode* fleft;
    void fold() {
        fleft = head;
        foldHelper(head, 0);
    }
};

// From leetcode
void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    // Find the penultimate ListNode i.e second last ListNode of the linkedlist
    struct ListNode* penultimate = head;
    while (penultimate->next->next) penultimate = penultimate->next;

    // Link the penultimate with the second element
    penultimate->next->next = head->next;
    head->next = penultimate->next;

    // Again set the penultimate to the the last
    penultimate->next = NULL;

    // Do the above steps rcursive
    reorderList(head->next->next);
}

int main() {
    ListNode* head{construct({2, 8, 9, 1, 5, 4, 3})};
    cout << "\nGiven linked list: ";
    display(head);

    cout << "Linked List after reordering: ";
    linked_list ll;
    ll.add_node(2), ll.add_node(8), ll.add_node(9), ll.add_node(1), ll.add_node(5), ll.add_node(4), ll.add_node(3);
    ll.fold();
    ll.display();
    // reorderList(head);
    // display(head);

    destruct(head);
}