// Video Link: https://youtu.be/cBQs7kqK_Dw?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/generic_tree_multisolver/topic
// Article Link 2: https://nados.io/article/multisolver-for-generic-tree
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

int treeSize;
int treeHeight;
int maxData{numeric_limits<int>::min()};
int minData{numeric_limits<int>::max()};
void multisolver(Node* root, int treeDepth = 0) {
    ++treeSize; 
    minData = min(minData, root->data);
    maxData = max(maxData, root->data);
    treeHeight = max(treeHeight, treeDepth);

    for (auto&& child: root->children)
        multisolver(child, treeDepth + 1);
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    multisolver(root);
    cout << "\nNumber of nodes (size) of tree: " << treeSize;
    cout << "\nHeight of tree:" << treeHeight;
    cout << "\nMin node in tree: " << minData;
    cout << "\nMax node in tree: " << maxData;

    destructor(root);
    cout << "\n\n";
}