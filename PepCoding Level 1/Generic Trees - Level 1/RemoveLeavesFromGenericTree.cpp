// Question Link: https://nados.io/question/remove-leaves-in-generic-tree
// Video Link: https://youtu.be/0PBC_EEBHGg?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Gfg Link: https://www.geeksforgeeks.org/remove-all-leaf-nodes-from-a-generic-tree-or-n-ary-tree/
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

<<<<<<< HEAD
// https://nados.io/article/remove-leaves-in-generic-tree#:~:text=root)%3B%0A%20%20%20%20display(root)%3B%0A%20%20%7D%0A%20%0A%7D-,Analysis,-%3A
=======
>>>>>>> origin/main
void removeLeaves(Node* root) {
    // // Pepcoding approach to removal
    // for (int i = root->children.size() - 1; i >= 0; i--)
    //     if (root->children.at(i)->children.empty())
    //         root->children.erase(root->children.begin() + i);

    // // Removal approach from comments
    // for (int i = 0; i < root->children.size(); i++)
    //     if (root->children.at(i)->children.empty()) {
    //         root->children.erase(root->children.begin() + i);
    //         continue;
    //         // // or do
    //         // --i;
    //     }

    for (auto it = rbegin(root->children); it != rend(root->children); ++it)
        if ((*it)->children.empty())
            root->children.erase(next(it).base());

    for (auto&& child : root->children)
        removeLeaves(child);
}

void removeLeavesIterative(Node* root) {  // solved using BFS
    if (!root) return;

    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        root = queue.front();
        queue.pop();

        for (int i = root->children.size() - 1; ~i; --i)
            if (root->children.at(i)->children.empty())
                root->children.erase(root->children.begin() + i);
            else
                queue.push(root->children.at(i));
    }
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    // removeLeaves(root);
    removeLeavesIterative(root);

    cout << "\nGeneric tree after removing leaf nodes ('.' denotes null): \n";
    display(root);

    destructor(root);
    cout << "\n\n";
}