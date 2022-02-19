// Question Link: https://nados.io/question/ceil-and-floor-in-generic-tree
// Video Link: https://youtu.be/I1rAT8hRnWI?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
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

// https://nados.io/article/ceil-and-floor-in-a-generic-tree#:~:text=and%20Space%20Complexity-,Analysis,-%3A
void ceilAndFloorOfNode(Node* root, const int& data, int& ceil, int& floor) {
    if (root->data < ceil and root->data > data)
        ceil = root->data;
    if (root->data > floor and root->data < data)
        floor = root->data;

    for (auto&& child : root->children)
        ceilAndFloorOfNode(child, data, ceil, floor);
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    cout << "\nEnter node data: ";
    int data;
    cin >> data;

    int ceil{numeric_limits<int>::max()};
    int floor(numeric_limits<int>::min());

    ceilAndFloorOfNode(root, data, ceil, floor);
    cout << "The ceil of given node is " << ceil << "\n";
    cout << "The floor of given node is " << floor << "\n";

    destructor(root);
    cout << "\n";
}