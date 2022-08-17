// Question Link: https://nados.io/question/remove-leaves-in-binary-tree
// Video Link: https://youtu.be/CkooURhePkg?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Article Link: https://nados.io/content/binary-tree-constructor
// Video Link: https://youtu.be/XV1ADVV6FbQ?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
TreeNode* construct1(vector<int> nums) {
    TreeNode* root{new TreeNode{nums.front()}};

    // Creating a stack of pairs to create binary tree from list
    // Here pair.first denotes the node while pair.second defines "state"
    // The "state" can be either:
    // a) 1 -> Node has been inserted in stack, now push its left child if exists else state += 1
    // b) 2 -> Left Subtree of Node has been traversed, now push its left child if exists else state += 1
    // c) 3 -> Pop node from stack. It has been fully traversed
    stack<pair<TreeNode*, int>> st;
    st.emplace(root, 1);

    int idx{};
    while (not st.empty()) {
        auto& [node, state] = st.top();
        if (state == 1) {
            ++idx;
            if (nums.at(idx) != -1) {
                node->left = new TreeNode{nums.at(idx)};
                st.emplace(node->left, 1);
            } else {
                node->right = nullptr;
            }
            ++state;
        } else if (state == 2) {
            ++idx;
            if (nums.at(idx) != -1) {
                node->right = new TreeNode{nums.at(idx)};
                st.emplace(node->right, 1);
            } else {
                node->right = nullptr;
            }
            ++state;
        } else {
            st.pop();
        }
    }

    return root;
}

TreeNode* construct2(vector<int> nums, int& idx) {
    if (idx == nums.size() or nums.at(idx) == -1) {
        ++idx;
        return nullptr;
    }
    return new TreeNode{nums.at(idx++), construct2(nums, idx), construct2(nums, idx)};
}

// Article Link: https://nados.io/content/display-a-binary-tree
// Video Link: https://youtu.be/sYU6AnSJyjo?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
void display(TreeNode* root) {
    if (not root) return;

    cout << (root->left ? to_string(root->left->val) : "null");
    cout << "<-" << to_string(root->val) << "->";
    cout << (root->right ? to_string(root->right->val) : "null") << endl;

    display(root->left);
    display(root->right);
}

void destruct(TreeNode*& root) {
    if (not root) return;
    destruct(root->left);
    destruct(root->right);
    delete root;
    root = nullptr;
}

// Approach 1 (My Approach)
void removeLeafNodes1(TreeNode*& root) {
    if (not root) return;

    if (root->left and root->left->left == root->left->right) {
        TreeNode* node{root->left};
        delete node;
        root->left = nullptr;
    }

    if (root->right and root->right->left == root->right->right) {
        TreeNode* node{root->right};
        delete node;
        root->right = nullptr;
    }

    removeLeafNodes1(root->left);
    removeLeafNodes1(root->right);
}

// Approach 2 (Pepcoding Approach)
// Analysis: https://nados.io/article/remove-leaves-in-binary-tree#:~:text=4.-,Analysis,-%3A
TreeNode* removeLeafNodes2(TreeNode*& root) {
    if (not root or root->left == root->right) return;
    root->left = removeLeafNodes2(root->left);
    root->right = removeLeafNodes2(root->right);
    return root;
}

int main() {
    TreeNode* root{construct1({// 50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1
                               10, 20, 40, -1, -1, 50, -1, 80, -1, -1, 30, 60, 90, -1, -1, -1, 70, -1, -1})};
    // int idx{};
    // 50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
    // TreeNode* root{construct2({50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1}, idx)};

    cout << "Given binary tree:\n";
    display(root);
    cout << "\n";

    removeLeafNodes1(root);

    cout << "Binary tree after removing leaf nodes: \n";
    display(root);
    cout << "\n\n";

    destruct(root);
}