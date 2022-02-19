// Question Link: https://nados.io/question/node-with-maximum-subtree-sum
// Video Link: https://youtu.be/tDx3PPwgSxs?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
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

void floorOfNode(Node* root, const int& data, int& floor) {
    if (root->data > floor and root->data < data)
        floor = root->data;

    for (auto&& child : root->children)
        floorOfNode(child, data, floor);
}

// https://nados.io/article/node-with-maximum-subtree-sum#:~:text=4.-,Analysis,-%3A
int findMaxSumSubtree(Node* root, int& maxSum, int& maxSumNode) {
    int sum{root->data};

    for (auto&& child : root->children)
        sum += findMaxSumSubtree(child, maxSum, maxSumNode);

    if (sum > maxSum)
        maxSum = sum, maxSumNode = root->data;

    return sum;
}

int main() {
    const vector<int> nums{10, 20, -50, -1, 60, -1, -1, 30, -70, -1, 80, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    int maxSumNode{}, maxSum{numeric_limits<int>::min()};
    findMaxSumSubtree(root, maxSum, maxSumNode);
    cout << "\nNode with maximum sum subtree is " << maxSumNode << " with sum = " << maxSum;

    destructor(root);
    cout << "\n\n";
}