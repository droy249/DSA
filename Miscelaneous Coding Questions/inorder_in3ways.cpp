// Question: 
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
// (Can be applied to both preorder and postorder traversal as well.)

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

// Question link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Answer link: https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris

// There are three solutions to this problem.

//     Iterative solution using stack: O(n) time and O(n) space;
//     Recursive solution: O(n) time and O(n) space (function call stack);
//     Morris traversal: O(n) time and O(1) space.

#include <bits/stdc++.h>
using namespace std;

// Iterative solution using stack
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};

// Recursive solution
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};

// Morris traversal
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    nodes.push_back(root -> val);
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};
