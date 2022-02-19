// Question Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/
// Alt Question Link: https://nados.io/content/generic-tree
// Playlist Link: https://youtube.com/playlist?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Leetcode Explore Card Link: https://leetcode.com/explore/learn/card/n-ary-tree
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

// Counts number of nodes in generic tree
// Question Link: https://nados.io/question/size-of-generic-tree
// Video Link: https://youtu.be/epQq3XWitxA?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
int sizeOfTree(Node* root) {
    if (!root) return 0;

    int size{1};
    for (auto&& child : root->children)
        size += sizeOfTree(child);

    return size;
}

// Finds node with maximum value in generic tree
// Question Link: https://nados.io/question/maximum-in-a-generic-tree
// Video Link: https://youtu.be/eJnf0QBg64g?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
int maxInTree(Node* root) {
    if (!root)
        return 0;
    else if (root->children.empty())
        return root->data;

    int maxVal{root->data};
    for (auto&& child : root->children)
        maxVal = max(maxVal, maxInTree(child));

    return maxVal;
}

// Finds height of generic tree
// Question Link: https://nados.io/question/height-of-a-generic-tree
// Video Link: https://youtu.be/duRYlVs72js?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Leetcode Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
int heightOfTree(Node* root) {
    if (!root) return 0;

    int height{};
    for (auto&& child : root->children)
        height = max(height, heightOfTree(child));

    return 1 + height;  // adding to 1 to final output to take in account curent node which itself represents a unit of height
}

// Prints the preorder traversal of generic tree
// Question Link: https://nados.io/question/generic-tree-traversals-pre-order-post-order
// Video Link: https://youtu.be/YnufWAWOfI8?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Leetcode Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal
void preorder(Node* root) {
    cout << root->data << " ";
    for (auto&& child : root->children)
        preorder(child);
}

// Prints the postorder traversal of generic tree
// Question Link: https://nados.io/question/generic-tree-traversals-pre-order-post-order
// Video Link: https://youtu.be/YnufWAWOfI8?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Leetcode Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
void postorder(Node* root) {
    for (auto&& child : root->children)
        postorder(child);
    cout << root->data << " ";
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    cout << "\nNumber of nodes in generic tree: " << sizeOfTree(root);

    cout << "\nMaximum Value in generic tree: " << maxInTree(root);

    cout << "\nHeight of generic tree: " << heightOfTree(root);

    cout << "\nPreorder traversal of generic tree: ";
    preorder(root);

    cout << "\nPostorder traversal of generic tree: ";
    postorder(root);

    destructor(root);
    cout << "\n\n";
}