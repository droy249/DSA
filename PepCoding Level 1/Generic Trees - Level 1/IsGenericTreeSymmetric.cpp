// Question Link: https://nados.io/question/is-generic-tree-symmetric
// Video Link: https://youtu.be/oEBwL5pHzTs?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Gfg Link:
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

bool areTreesMirrorInShape(Node* root1, Node* root2) {
    if (root1->children.size() != root2->children.size()) return false;

    int n{root1->children.size()};
    for (int i{}, j{n - 1}; i < n and compl j; ++i, --j)
        if (not areTreesMirrorInShape(root1->children.at(i), root2->children.at(j)))
            return false;

    return true;
}

// Recursive Approach
// Time Complexity: O(n)
// https://nados.io/article/is-generic-tree-symmetric#:~:text=3.-,Analysis,-%3A
bool isGenericTreeSymmetric(Node* root) {
    return areTreesMirrorInShape(root, root);
}

int main() {
    const vector<int> nums{
        // 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1
        // 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, -1, 90, -1, -1, 40, 100, -1, 110, -1, -1, -1
        1, 2, 4, 8, -1, 9, -1, -1, 5, 10, -1, -1, -1, 3, 6, 11, -1, -1, 7, 12, -1, 13, -1, -1, -1, -1
    };
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    // Note: we are comparing ONLY SHAPE of tree and NOT VALUES OF NODES
    cout << "\nThis generic tree is" << (isGenericTreeSymmetric(root) ? " " : " not ") << "symmetric";

    destructor(root);
    cout << "\n\n";
}