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

bool findInGenericTree(Node* root, int data) {
    bool found = root->data == data;
    for (auto&& child : root->children)
        found |= findInGenericTree(child, data);

    return found;
}

// https://nados.io/article/find-in-generic-tree#:~:text=5.-,Analysis,-%3A
bool findInGenericTreeOptimized(Node* root, int data) {
    if (root->data == data)
        return true;

    for (auto&& child : root->children)
        if (findInGenericTreeOptimized(child, data))
            return true;

    return false;
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): ";
    display(root);

    cout << "\nEnter element to find: ";
    int data;
    cin >> data;

    cout << (findInGenericTree(root, data) ? "Node exists" : "Node doesn't exist") << "\n";
    cout << (findInGenericTreeOptimized(root, data) ? "Node exists" : "Node doesn't exist") << "\n\n";
}