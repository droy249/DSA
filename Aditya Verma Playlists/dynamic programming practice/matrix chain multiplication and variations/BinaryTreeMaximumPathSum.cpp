// Video Link: https://youtu.be/Osz-Vwer6rw?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
// Leetcode Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int solve(TreeNode* root, int& res) {
    if(root == NULL) return 0;
    
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    
    res = max({res, root->val, l + root->val, r + root->val, l + r + root->val});    
    return max(max(l,r) + root->val, root->val);
}

int maxPathSum(TreeNode* root){
    int res = numeric_limits<int>::min();
    solve(root, res);
    return res;
}