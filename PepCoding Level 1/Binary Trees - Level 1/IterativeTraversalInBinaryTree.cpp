// Question Link: https://nados.io/question/iterative-pre-post-and-inorder-traversals-of-binary-tree
// Video Link: https://youtu.be/12aMTS0L6WI?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
// Analysis: https://nados.io/article/iterative-pre-post-and-inorder-in-binary-tree#:~:text=arr)%3B%0A%20%20%20%20iterativePrePostInTraversal(root)%3B%0A%20%20%7D%0A%0A%7D-,Analysis,-%3A
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
    while (!st.empty()) {
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
void display(TreeNode*& root) {
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

// Video Link: https://youtu.be/Bfqd8BsPVuw?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
// Gfg Link: https://www.geeksforgeeks.org/iterative-preorder-traversal/
void preorder(TreeNode*& root) {
    stack<TreeNode*> st;
    st.emplace(root);

    while (not st.empty()) {
        root = st.top();
        st.pop();

        cout << root->val << " ";
        if (root->right) st.emplace(root->right);
        if (root->left) st.emplace(root->left);
    }
}

// Video Link: https://youtu.be/lxTGsVXjwvM?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
// Gfg Link: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
void inorder(TreeNode*& root) {
    stack<TreeNode*> st;
    TreeNode* curr{root};

    while (true)
        if (curr) {
            st.emplace(curr);
            curr = curr->left;
        } else {
            if (st.empty()) break;
            curr = st.top();
            st.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
}

// Video Link: https://youtu.be/2YBhNLodD8Q?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
// Gfg Link: https://www.geeksforgeeks.org/iterative-postorder-traversal/
void postorder2Stacks(TreeNode* root) {
    stack<TreeNode*> st;
    
}

// Video Link: 
// Gfg Link: https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
void postorder1Stack(TreeNode* root) {

}

void allTraversals(TreeNode*& root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
    // Creating a stack of pairs to print tree traversals iteratively
    // Here pair.first denotes the node while pair.second defines "state"
    // The "state" can be either:
    // a) 1 -> Print node->val to PREORDER, push node->left if exists, and ++state
    // b) 2 -> Print node->val to INORDER, push node->right if exists, and ++state
    // c) 3 -> Print node->val to POSTORDER and pop() from stack
    stack<pair<TreeNode*, int>> st;
    st.emplace(root, 1);

    while (not st.empty()) {
        auto& [node, state] = st.top();
        // st.pop();

        switch (state) {
            case 1:
                preorder.emplace_back(node->val);
                ++state;
                if (node->left) st.emplace(node->left, 1);
                break;

            case 2:
                inorder.emplace_back(node->val);
                ++state;
                if (node->right) st.emplace(node->right, 1);
                break;

            case 3:
                postorder.emplace_back(node->val);
                st.pop();
                break;
        }
    }
}

int main() {
    TreeNode* root{construct1({50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1})};
    // int idx{};
    // TreeNode* root{construct2({50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1}, idx)};

    cout << "Given binary tree:\n";
    display(root);
    cout << "\n";

    cout << "Iterative preorder traversal in binary tree: ";
    preorder(root);
    cout << "\n\n";

    cout << "Iterative inorder traversal in binary tree: ";
    inorder(root);
    cout << "\n\n";

    cout << "Iterative postorder (2 stacks) traversal in binary tree: ";
    postorder2Stacks(root);
    cout << "\n\n";

    cout << "Iterative postorder (1 stacks) traversal in binary tree: ";
    postorder1Stack(root);
    cout << "\n\n";

    cout << "All iterative traversals at once:";
    vector<int> preorder, inorder, postorder;
    allTraversals(root, preorder, inorder, postorder);
    cout << "\nPreorder: ";
    for (auto&& val : preorder) cout << val << " ";
    cout << "\nInorder: ";
    for (auto&& val : inorder) cout << val << " ";
    cout << "\nPostorder: ";
    for (auto&& val : postorder) cout << val << " ";
    cout << "\n";

    destruct(root);
}