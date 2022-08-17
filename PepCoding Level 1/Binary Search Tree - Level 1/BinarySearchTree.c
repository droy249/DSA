// Article Link: https://nados.io/content/binary-search-tree-for-beginners
// Playlist Link: https://www.youtube.com/playlist?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Article Link: https://nados.io/article/binary-search-tree-constructor
// Video Link: https://youtu.be/yGrs-VuPCYg?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
struct TreeNode* construct(const int arr[], int low, int high) {
    if (low > high) return NULL;

    int mid = low + (high - low) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
    root->left = construct(arr, low, mid - 1);
    root->right = construct(arr, mid + 1, high);
    return root;
}

// Article Link: https://nados.io/content/display-a-binary-tree
// Video Link: https://youtu.be/sYU6AnSJyjo?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
void display(struct TreeNode* root) {
    if (!root) return;

    if (root->left)
        printf("%d", root->left->val);
    else
        printf("null");
    printf("<-%d->", root->val);
    if (root->right)
        printf("%d", root->right->val);
    else
        printf("null");
    printf("\n");

    display(root->left);
    display(root->right);
}

void destruct(struct TreeNode** root) {
    if (!*root) return;
    destruct(&((*root)->left));
    destruct(&((*root)->right));
    free(*root);
    *root = NULL;
}

// Question Link: https://nados.io/question/add-node-to-bst
// Video Link: https://youtu.be/lraQt-zHOHk?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// LeetCode Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (!root) {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
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

int maxInBST(struct TreeNode* root) {
    return root->right == NULL ? root->val : maxInBST(root->right);
}

// Question Link: https://nados.io/question/remove-node-from-bst
// Video Link: https://youtu.be/5_AZcOOc-kM?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// Leetcode Link: https://leetcode.com/problems/delete-node-in-a-bst/
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) return NULL;

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    if (key > root->val)
        root->right = deleteNode(root->right, key);

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    else if (key < root->val)
        root->left = deleteNode(root->left, key);
    
    // If key is same as root's key, then this is the node to be deleted
    else {
        // Node to be deleted has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } 
        // Node to be deleted has one child
        else if (root->left != NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        else if (root->right != NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        // Node to be deleted has two children
        else {
            int max = maxInBST(root->left);
            root->val = max;
            root->left = deleteNode(root->left, max);
            return root;
        }
    }
    
}

int main() {
    const int arr[] = {12, 25, 37, 50, 62, 75, 87};
    struct TreeNode* root = construct(arr, 0, sizeof(arr) / sizeof(*arr) - 1);
    printf("\nGiven BST: \n");
    display(root);

    printf("\nEnter value to be inserted: ");
    int val;
    scanf("%d ", &val);
    root = insertIntoBST(root, val);

    printf("\nEnter value to be deleted: ");
    int del;
    scanf("%d ", &del);
    root = deleteNode(root, del);

    display(root);
    destruct(&root);
}