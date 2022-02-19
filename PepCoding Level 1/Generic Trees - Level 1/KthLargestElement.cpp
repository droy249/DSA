// Question Link: https://nados.io/question/kth-largest-element-in-tree
// Video Link: https://youtu.be/DmAGEAeYhJs?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
#include <bits/stdc++.h>
using namespace std;

// Node definition
struct Node {
    int data;
    vector<Node*> children;
};

// Build/construct a generic tree
// Video Link: https://youtu.be/9Oi3WamOCPo?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/generic_tree_constructor/topic
Node* constructor(const vector<int> nums) {
    Node* root = nullptr;
    stack<Node*> stack;

    for (const int& num : nums) {
        if (num == -1)
            stack.pop();
        else {
            Node* node = new Node;
            node->data = num;

            if (!root)
                root = node;
            else
                stack.top()->children.push_back(node);

            stack.push(node);
        }
    }
    return root;
}

void destructor(Node*& root) {
    if (!root) return;
    for (auto&& child: root->children)
        destructor(child);
    delete root;
    root = nullptr;
}

// void destructor(Node*& root) {
//     if (!root) return;

//     queue<Node*> qu;
//     qu.push(root);

//     while (!qu.empty()) {
//         Node* node{qu.front()};
//         qu.pop();

//         for (auto&& child : root->children)
//             if (child)
//                 qu.push(child);
//     }

//     delete root;
//     root = nullptr;
// }

// Displays tree in adjacency list form
// Video Link: https://youtu.be/3xovYxKCgBQ?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/display_a_generic_tree/topic
void display(Node* root) {
    if (!root) {
        cout << "Empty!!\n";
        return;
    }

    string str(to_string(root->data) + " -> ");

    for (auto&& child : root->children)
        str += to_string(child->data) + ", ";
    str += ".";

    cout << str << '\n';

    for (auto&& child : root->children)
        display(child);
}


void floorOfNode(Node* root, const int& data, int& floor) {
    if (root->data > floor and root->data < data)
        floor = root->data;

    for (auto&& child : root->children)
        floorOfNode(child, data, floor);
}

// https://nados.io/article/kth-largest-element-in-tree#:~:text=4.-,Analysis,-%3A
int kthLargestElement(Node* root, int& k) {
    int element{numeric_limits<int>::max()};
    int floor{numeric_limits<int>::min()};

    while (k--) {
        floorOfNode(root, element, floor);
        element = floor;
        floor = numeric_limits<int>::min();
    }

    return element;
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    cout << "\nEnter k: ";
    int k;
    cin >> k;

    cout << "The kth largest element is " << kthLargestElement(root, k);

    destructor(root);
    cout << "\n\n";
}