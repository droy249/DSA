// Question Link: https://nados.io/question/linearize-a-generic-tree
// Approach 1 Video Link: https://youtu.be/TKZEBXtzKSM?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Approach 2 Video Link: https://youtu.be/D5RYXVgJ5NM?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
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

Node* getTail(Node* node) {
    while (node->children.size() == 1)
        node = node->children.front();

    return node;
}

// Approach 1: Brute Force
// Time Complexity: O(n^2)
<<<<<<< HEAD
// https://nados.io/article/linearize-a-generic-tree#:~:text=3.-,Analysis,-%3A
=======
>>>>>>> origin/main
void linearizeGenericTree(Node* root) {
    //		// Pepcoding approach
    // while (root->children.size() > 1) {
    //     Node* lastChild = root->children.back();
    //     root->children.pop_back();

    //     // Node* secondLastChild = ;
    //     Node* tail = getTail(root->children.back());  // get the tail of second last child
    //     tail->children.push_back(lastChild);
    // }

    while (root->children.size() > 1) {
        Node* lastChild = root->children.back();
        root->children.pop_back();

        Node* tailPtr = root->children.back();  // tail pointer initialized and pointing to second last child
        while (tailPtr->children.size() == 1)
            tailPtr = tailPtr->children.front();

        tailPtr->children.push_back(lastChild);
    }

    for (auto&& child : root->children)
        linearizeGenericTree(child);
}

// Approach 2: optimized
// Time Complexity: O(n)
<<<<<<< HEAD
// https://nados.io/article/linearize-a-generic-tree-efficient-approach#:~:text=6.-,Analysis,-%3A
=======
>>>>>>> origin/main
Node* linearizeGenericTreeOptimized(Node* root) {
    if (root->children.empty())
        return root;

<<<<<<< HEAD
    Node* tailOfLastChild = linearizeGenericTreeOptimized(root->children.back());
=======
    Node* tailOfLastChlid = linearizeGenericTreeOptimized(root->children.back());
>>>>>>> origin/main
    while (root->children.size() > 1) {
        Node* lastChild = root->children.back();
		root->children.pop_back();

        Node* secondLastChild = root->children.back();
        Node* tailOfSecondLastChlid = linearizeGenericTreeOptimized(secondLastChild);
<<<<<<< HEAD
        tailOfSecondLastChlid->children.push_back(lastChild);
    }
    return tailOfLastChild;
=======
        tailOfSecondLastChlid->children.push_back(secondLastChild);
    }
    return tailOfLastChlid;
>>>>>>> origin/main
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    // linearizeGenericTree(root);
<<<<<<< HEAD
    linearizeGenericTreeOptimized(root);

    cout << "\nGeneric tree after linearizing: \n";
=======
    linearizeGenericTree(root);

    cout << "\nGeneric tree after mirroring: \n";
>>>>>>> origin/main
    display(root);

    destructor(root);
    cout << "\n\n";
}