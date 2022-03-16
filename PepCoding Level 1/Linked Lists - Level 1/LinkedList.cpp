// Playlist Link: https://youtube.com/playlist?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Article Link 1: https://www.pepcoding.com/resources/online-java-foundation/linked-lists
// Article Link 2: https://nados.io/content/linked-lists-for-beginners
// Leetcode Link: https://leetcode.com/problems/design-linked-list/
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

struct LinkedList {
    ListNode *head, *tail;
    int size;

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    LinkedList(vector<int>);

    void addAtTail(int);
    void addAtHead(int);
    void addAtIndex(int, int);

    int deleteAtHead();
    int deleteAtTail();
    int deleteAtIndex(int);

    void display();
    int getAt(int);
    ListNode* getNodeAt(int);

    void reverseDataIterative();
    void reversePointerIterative();
    void displayReverseRecursive();
    void reverseDataRecursive();
    void reversePointerRecursive();

    void reversePointerHelper(ListNode*);
    void reverseDataHelper(ListNode*, ListNode*&, int);
};

int main() {
    cout << "-------------LINKED LIST MENU-------------\n";
    cout << "0. Initialize linked list with given array\n";
    cout << "1. Add node at tail\n";
    cout << "2. Add node at head\n";
    cout << "3. Add node at given index\n";
    cout << "4. Delete node at tail\n";
    cout << "5. Delete node at head\n";
    cout << "6. Delete node at given index\n";
    cout << "7. Display linked list\n";
    cout << "8. Display size of linked list\n";
    cout << "9. Get value of node at index\n";
    cout << "10. Reverse linked list (data iterative)\n";
    cout << "11. Reverse linked list (pointer interative)\n";
    cout << "12. Display reverse of linked list (recursive)\n";
    cout << "13. Reverse linked list (pointer recursive)\n";
    cout << "14. Reverse linked list (data recursive)\n";
    cout << "15. Quit\n";

    LinkedList linkedList;
    int choice;

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:

            case 1:
                cout << "Enter value to add: ";
                int val;
                cin >> val;
                linkedList.addAtTail(val);
                break;

            case 2:
                cout << "Enter value to add: ";
                int val;
                cin >> val;
                linkedList.addAtHead(val);
                break;

            case 3:
                cout << "Enter index: ";
                int index;
                cin >> index;
                cout << "Enter value to add: ";
                int val;
                cin >> val;
                linkedList.addAtIndex(index, val);
                break;

            case 4:
                int deleted{linkedList.deleteAtTail()};
                if (deleted == -1)
                    cout << "Linked list is empty";
                else
                    cout << "Value deleted at tail: " << deleted;
                break;

            case 5:
                int deleted{linkedList.deleteAtHead()};
                if (deleted == -1)
                    cout << "Linked list is empty";
                else
                    cout << "Value deleted at head: " << deleted;
                break;

            case 6:
                cout << "Enter index: ";
                int index;
                cin >> index;
                cout << "Value deleted at tail: " << linkedList.deleteAtIndex(index);
                break;

            case 7:
                linkedList.display();
                break;

            case 8:
                cout << "Size of given linked list is: " << linkedList.size;
                break;

            case 9:
                cout << "Enter index: ";
                int index;
                cin >> index;
                cout << "Value at index " << index << " is: " << linkedList.getAt(index);
                break;

            case 10:
                cout << "Current linked list: ";
                linkedList.display();
                linkedList.reverseDataIterative();
                cout << "Reversed linked list: ";
                linkedList.display();
                break;

            case 11:
                cout << "Current linked list: ";
                linkedList.display();
                linkedList.reversePointerIterative();
                cout << "Reversed linked list: ";
                linkedList.display();
                break;

            case 12:
                cout << "Recursive display of reverse of linked list: ";
                linkedList.displayReverseRecursive();
                break;

            case 13:
                cout << "Current linked list: ";
                linkedList.display();
                linkedList.reversePointerRecursive();
                cout << "Reversed linked list: ";
                linkedList.display();
                break;

            case 14:
                cout << "Current linked list: ";
                linkedList.display();
                linkedList.reverseDataRecursive();
                cout << "Reversed linked list: ";
                linkedList.display();
                break;

            case 15:
                cout << "Exiting...\n\n";
                return 0;

            default:
                cout << "Incorrect choice...\n";
                return 0;
        }
    } while (choice != 10);
}

LinkedList::LinkedList(vector<int> nums) {
    for (auto&& num : nums) {
        if (!head and !tail)
            head = tail = new ListNode(num);
        else {
            tail->next = new ListNode(num);
            tail = tail->next;
        }
        ++size;
    }
}

// Question Link: https://nados.io/question/add-last-in-linked-list
// Video Link: https://youtu.be/fjjORH3nWy4?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Analysis: https://nados.io/article/add-last-in-linked-list#:~:text=4.-,Analysis,-Time%20Complexity%3A
void LinkedList::addAtTail(int val) {
    if (!size)
        head = tail = new ListNode(val);
    else
        tail = tail->next = new ListNode(val);
    ++size;
}

// Question Link: https://nados.io/question/add-first-in-linked-list
// Video Link: https://youtu.be/DfP-tb68t20?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
void LinkedList::addAtHead(int val) {
    // addAtIndex(0, val);
    ListNode* node{new ListNode(val, head)};
    head = node;

    if (size == 0) {
        tail = node;

        ++size;
    }
}

// Question Link: https://nados.io/question/add-at-index-in-linked-list
// Video Link: https://youtu.be/n9E27Z4zjpk?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
void LinkedList::addAtIndex(int index, int val) {
    if (size == 0 or index < 0 or index >= size) {
        cout << "Not possible to add\n";
        return;
    } else if (index == 0)
        LinkedList::addAtHead(val);
    else if (index == size - 1)
        LinkedList::addAtTail(val);
    else {
        ListNode* node{new ListNode(val)};
        ListNode* temp{head};

        for (int i{}; i < index - 1; ++i)
            temp = temp->next;

        node->next = temp->next;
        temp->next = node;

        ++size;
    }
}

// Question Link: https://nados.io/question/remove-first-in-linkedlist
// Video Link: https://youtu.be/QyfG6meLJBQ?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
int LinkedList::deleteAtHead() {
    if (size == 0) {
        return -1;
    } else {
        int val{head->val};

        if (size == 1)
            tail = nullptr;
        else if (size > 1)
            head = head->next;

        --size;
        delete head;
        return val;
    }
}

// Question Link: https://nados.io/question/remove-last-in-linked-list
// Video Link: https://youtu.be/WTG87ZABrtY?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
int LinkedList::deleteAtTail() {
    if (size == 0) {
        return -1;
    } else if (size == 1) {
        int val{tail->val};
        delete tail;
        size == 0;
        return val;
    } else {
        ListNode* secondLast{head};

        while (secondLast->next->next)
            secondLast = secondLast->next;

        int val{secondLast->val};
        delete secondLast->next;
        return val;
    }
}

// Question Link: https://nados.io/question/remove-at-index-in-linked-list
// Video Link: https://youtu.be/tYKLCwlx4Lk?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
int LinkedList::deleteAtIndex(int index) {
    if (size == 0 or index < 0 or index >= size)
        return -1;
    else if (index == 0)
        return deleteAtHead();
    else if (index == size - 1)
        return deleteAtTail();
    else {
        ListNode* temp{head};
        for (int i{}; i < index - 1; ++i)
            temp = temp->next;

        int val{temp->next->val};
        ListNode* tmp{temp->next};
        temp->next = temp->next->next;
        delete tmp;
        return val;
    }
}

// Question Link: https://nados.io/question/display-a-linkedlist
// Video Link: https://youtu.be/3yK7SkmdZrE?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
void LinkedList::display() {
    for (ListNode* temp{head}; temp; temp = temp->next)
        cout << temp->val << " ";
}

// Question Link: https://nados.io/question/get-value-in-linked-list
// Video Link: https://youtu.be/MGwnkGap5s8?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
int LinkedList::getAt(int index) {
    if (size == 0 or index < 0 or index >= size)
        return -1;
    else {
        ListNode* temp{head};
        while (index--)
            temp = temp->next;
        return temp->val;
    }
}

ListNode* LinkedList::getNodeAt(int index) {
    if (size == 0 or index < 0 or index >= size)
        return nullptr;
    else {
        ListNode* temp{head};
        while (index--)
            temp = temp->next;
        return temp;
    }
}

// Question Link: https://nados.io/question/reverse-a-linked-list-data-iterative
// Video Link: https://youtu.be/yRKvWfbSNM8?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Analysis: https://nados.io/article/reverse-a-linked-list-data-iterative#:~:text=4.-,Analysis,-Time%20Complexity%3A%20O
// Leetcode Link: https://leetcode.com/problems/reverse-linked-list/
void LinkedList::reverseDataIterative() {
    for (int low{}, high{size - 1}; low < high; ++low, --high)
        swap(getNodeAt(low)->val, getNodeAt(high)->val);
    cout << "\n";
}

// Question Link: https://nados.io/question/reverse-linked-list-pointer-iterative
// Video Link: https://youtu.be/71NqKy7287g?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
// Leetcode Link: https://leetcode.com/problems/reverse-linked-list/
void LinkedList::reversePointerIterative() {
    ListNode* prev{nullptr};
    ListNode* curr{head};

    while (curr) {
        ListNode* originalCurrNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = originalCurrNext;
    }

    swap(head, tail);
}

void displayRecursiveHelper(ListNode* node) {
    if (!node) return;
    displayRecursiveHelper(node->next);
    cout << node->val << " ";
}

// Question Link: https://nados.io/question/display-reverse-recursive-linked-list
// Video Link: https://youtu.be/kgmHuB6w0PM?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
void LinkedList::displayReverseRecursive() {
    displayRecursiveHelper(head);
    cout << "\n";
}

void LinkedList::reversePointerHelper(ListNode* node) {
    if (!node) return;
    
    reversePointerHelper(node->next);
    
    if (node != tail)
        node = node->next->next;
}

// Question Link: https://nados.io/question/reverse-linked-list-pointer-recursive
// Video Link: https://youtu.be/q9PE0PjVHIo?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
void LinkedList::reversePointerRecursive() {
    reversePointerHelper(head);
    head->next = nullptr;
    swap(head, tail);
}

void LinkedList::reverseDataHelper(ListNode* right, ListNode*& left, int level) {
    if(!right) return;
    reverseDataHelper(right->next, left, level + 1);
    if (level >= size / 2)
        swap(right->val, left->val);
    left = left->next;
}

// Question Link: 
// Video Link: https://youtu.be/aL3l2-S9koY?list=PL-Jc9J83PIiF5VZmktfqW6WVU1pxBF6l_
void LinkedList::reverseDataRecursive() {
    reverseDataHelper(head, head, 0);
}

LinkedList::~LinkedList() {
    for (ListNode* ptr{head}; head and size--; head = head->next) {
        delete ptr;
        ptr = head;
    }
}