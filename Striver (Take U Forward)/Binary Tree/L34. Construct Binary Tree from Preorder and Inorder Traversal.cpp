// SDE Sheet Link: https://takeuforward.org/data-structure/construct-a-binary-tree-from-inorder-and-preorder-traversal/
// Video Link: https://youtu.be/aZNaLrVebKQ?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk
// Gfg Link: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
// Leetcode Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

class Solution {
    TreeNode* buildThisTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
        if (preIndex >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndex]);
        
        int inIndex = 0;
        
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == preorder[preIndex]) {
                inIndex = i;
                break;
            }
        }
        
        ++preIndex;
        
        root->left = buildThisTree(preorder, inorder, preIndex, inStart, inIndex - 1);
        root->right = buildThisTree(preorder, inorder, preIndex, inIndex + 1, inEnd);

        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return buildThisTree(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
};

// Time Complexity: O(N) {Assumption: Hashmap returns the answer in constant time.}
// Space Complexity: O(N) {Reason: We are using an external hashmap of size ‘N’ = inorder.size().}
class HashMapApproach {
    unordered_map<int,int> inorderMap;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd) {
        
        // Eihter of left subtre
        if(preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        // Using hashMap to find index of root node
        // in inorder[]
        int inRoot = inorderMap[root->val];
        
        // Number of nodes to the left position of 
        // root node in inorder traversal
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd);

        return root;
    }
};