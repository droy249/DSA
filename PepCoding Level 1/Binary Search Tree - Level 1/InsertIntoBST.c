/* I have written this code in C since there was no need to write in Java. Same logic applies irrespective of the language used. Its was not possible for me to write Boilerplate for this code, therfore I attached the LeetCode Link for practice.  */

// Question Link: https://www.pepcoding.com/resources/online-java-foundation/binary-search-tree/add-node-to-bst-official/ojquestion
// Video Link: https://youtu.be/lraQt-zHOHk?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// LeetCode Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (!root)
    {
        struct TreeNode *node = malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = node->right = NULL;
        return node;
    }

    if (val > root->val)
        root->right = insertIntoBST(root->right, val);
    else if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        ; // nothing to do

    return root;
}