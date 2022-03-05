// Question Link: https://nados.io/question/predecessor-and-successor-of-an-element
// Video Link: https://youtu.be/lXL9xs0G8Uo?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
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

<<<<<<< HEAD
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

=======
void destructor(Node* root) {
    for (auto&& child : root->children)
        destructor(child);
    delete root;
}

>>>>>>> origin/main
// Displays tree in adjacency list form
// Video Link: https://youtu.be/3xovYxKCgBQ?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/display_a_generic_tree/topic
void display(Node* root) {
<<<<<<< HEAD
    if (!root) {
        cout << "Empty!!\n";
        return;
    }

=======
>>>>>>> origin/main
    string str(to_string(root->data) + " -> ");

    for (auto&& child : root->children)
        str += to_string(child->data) + ", ";
    str += ".";

    cout << str << '\n';

    for (auto&& child : root->children)
        display(child);
}

<<<<<<< HEAD
// https://nados.io/article/predecessor-and-successor-of-an-element#:~:text=5.-,Analysis,-%3A
void predecessorAndSuccessorOfNode(Node* root, const int& data, Node*& predecessor, Node*& successor, int& state) { 
    // It is necessary to pass all parameters (except root) BY REFERENCE fo code to work, ESPECIALLY STATE. Otherwise code doesn't work.
    // Also, this code only works when all the nodes of tree are UNIQUE. Else it will fail.
    
    if (state == 0)
        if (root->data == data)
            state = 1;
        else
            predecessor = root;
    else if (state == 1) {
        successor = root;
        state = 2;
    }

    for (auto&& child : root->children)
        predecessorAndSuccessorOfNode(child, data, predecessor, successor, state);
=======
void predecessorAndSuccessorOfNode(Node* root, int data, Node* predecessor = nullptr, Node* successor = nullptr, int state = 0) {
    for (auto&& child: root->children)
>>>>>>> origin/main
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

<<<<<<< HEAD
    cout << "\nEnter node data: ";
    int data;
    cin >> data;

    Node* predecessor{root};
    Node* successor{root};
    int state{};
    predecessorAndSuccessorOfNode(root, data, predecessor, successor, state);
    cout << "The predecessor of given node is " << predecessor->data << "\n";
    cout << "The successor of given node is " << successor->data << "\n";
=======
    cout << "Enter node data: ";
    int data;
    cin >> data;

    predecessorAndSuccessorOfNode(root, data);
>>>>>>> origin/main

    destructor(root);
    cout << "\n\n";
}