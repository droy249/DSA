// Video Link: https://youtu.be/zmPj_Ee3B8c?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go
// Explained previously in Pepcoding Video the brute force + optimal solution

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int diameterHelper(struct TreeNode* root, int* diameter) {
    if (!root) return -1;

    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);

    *diameter = fmax(*diameter, leftHeight + rightHeight + 2);
    return fmax(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    diameterHelper(root, &diameter);
    return diameter;
}