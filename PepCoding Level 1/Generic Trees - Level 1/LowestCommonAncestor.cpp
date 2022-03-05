// Question Link: https://nados.io/question/lowest-common-ancestor-generic-tree
// Video Link: https://youtu.be/w8rr1AYMlfw?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Gfg Link: https://www.geeksforgeeks.org/lca-n-ary-tree-constant-query-o1/
#include <bits/stdc++.h>
using namespace std;

// Node definition
struct Node {
    int data;
    vector<Node*> children;
};

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

<<<<<<< HEAD
// https://nados.io/article/lowest-common-ancestor-generic-tree#:~:text=Play%20Video-,Analysis,-%3A
=======
>>>>>>> origin/main
int lowestCommonAncestor(Node* root, int data1, int data2) {
    vector<int> path1{nodeToRootPath(root, data1)}, path2{nodeToRootPath(root, data2)};

    if (path1.empty() or path2.empty()) return -1;

    int i{path1.size() - 1}, j{path2.size() - 1};
    while (i >= 0 and j >= 0 and path1.at(i) == path2.at(j))
        --i, --j;

    return path1.at(i + 1);  // or return path2.at(j + 1);
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    cout << "\nEnter nodes to find lowest common ancestor for: ";
    int data1, data2;
    cin >> data1 >> data2;

    cout << "\nLowest common ancestor of given nodes is: " << lowestCommonAncestor(root, data1, data2);

    destructor(root);
    cout << "\n\n";
}