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

void multisolver(Node* root, int& treeSize, int& treeHeight, int& maxData, int& minData, int treeDepth = 0) {
    ++treeSize;
    minData = min(minData, root->data);
    maxData = max(maxData, root->data);
    treeHeight = max(treeHeight, treeDepth);

    for (auto&& child : root->children)
        multisolver(child, treeSize, treeHeight, maxData, minData, treeDepth + 1);
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    int treeSize{};
    int treeHeight{};
    int maxData{numeric_limits<int>::min()};
    int minData{numeric_limits<int>::max()};

    multisolver(root, treeSize, treeHeight, maxData, minData);

    cout << "\nNumber of nodes (size) of tree: " << treeSize;
    cout << "\nHeight of tree:" << treeHeight;
    cout << "\nMin node in tree: " << minData;
    cout << "\nMax node in tree: " << maxData;
    cout << "\n\n";

    destructor(root);
    cout << "\n\n";
}