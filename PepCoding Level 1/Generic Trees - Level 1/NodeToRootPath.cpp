// Question Link: https://nados.io/question/node-to-root-path-in-generic-tree
// Video Link: https://youtu.be/oEBwL5pHzTs?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Similar Question Gfg Link: https://www.geeksforgeeks.org/print-all-root-to-leaf-paths-of-an-n-ary-tree/
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

vector<int> nodeToRootPath(Node* root, int data) {
    if (root->data == data)
        return {data};

    for (auto&& child : root->children) {
        vector<int> path{nodeToRootPath(child, data)};
        if (!path.empty()) {
            path.emplace_back(root->data);
            return path;
        }
    }

    return {};
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    cout << "Enter node data: ";
    int data;
    cin >> data;

    cout << "\nGiven node to root paths: ";
    for (auto&& node : nodeToRootPath(root, data))
        cout << node << ' ';

    destructor(root);
    cout << "\n\n";
}