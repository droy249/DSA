// Question Link: https://nados.io/question/distance-between-two-nodes-in-a-generic-tree
// Video Link: https://youtu.be/5N5tpizDXys?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
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

// https://nados.io/article/distance-between-two-nodes-in-a-generic-tree#:~:text=4.-,Analysis,-%3A
int distanceBetweenNodes(Node* root, int data1, int data2) {
    vector<int> path1{nodeToRootPath(root, data1)}, path2{nodeToRootPath(root, data2)};

    if (path1.empty() or path2.empty()) return -1;

    int i{path1.size() - 1}, j{path2.size() - 1};
    while (i >= 0 and j >= 0 and path1.at(i) == path2.at(j)) --i, --j;

    return i + j + 2;
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    cout << "\nEnter nodes for which to find distance between: ";
    int data1, data2;
    cin >> data1 >> data2;

    cout << "\nDistance (i.e number of edges) between given nodes is: " << distanceBetweenNodes(root, data1, data2);

    destructor(root);
    cout << "\n\n";
}