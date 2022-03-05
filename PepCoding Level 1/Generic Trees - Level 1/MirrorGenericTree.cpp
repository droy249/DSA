// Question Link: https://nados.io/question/mirror-a-generic-tree
// Video Link (Question Video Link because Answer Video Link is unavailable): https://youtu.be/CjtGTcG-fUU?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Gfg Link: https://www.geeksforgeeks.org/mirror-of-n-ary-tree/
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

// Free memory allocated to build generic tree
void destructor(Node* root) {
    for (auto&& child : root->children)
        destructor(child);
    delete root;
}

// Displays tree in adjacency list form
// Video Link: https://youtu.be/3xovYxKCgBQ?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/display_a_generic_tree/topic
void display(Node* root) {
    string str(to_string(root->data) + " -> ");

    for (auto&& child : root->children)
        str += to_string(child->data) + ", ";
    str += ".";

    cout << str << '\n';

    for (auto&& child : root->children)
        display(child);
}

<<<<<<< HEAD
// https://nados.io/article/mirror-of-a-generic-tree#:~:text=4.-,Analysis,-%3A
=======
>>>>>>> origin/main
void mirrorGenericTree(Node* root) {
    reverse(root->children.begin(), root->children.end());
    for (auto&& child : root->children)
        mirrorGenericTree(child);
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    mirrorGenericTree(root);

    cout << "\nGeneric tree after mirroring: \n";
    display(root);

    destructor(root);
    cout << "\n\n";
}