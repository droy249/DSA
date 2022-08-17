// Question Link: https://nados.io/question/replace-with-sum-of-larger
// Video Link: https://youtu.be/MLff3CxNVTc?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// Leetcode Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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

int sum;

void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->right);
    int temp = root->val;
    root->val = sum;
    sum += temp;
    inorder(root->left);
}

struct TreeNode* bstToGst(struct TreeNode* root){
    if(root == NULL) return NULL;
    sum = 0;
    inorder(root);
    return root;
}

int main() {
    const int arr[] = {12, 25, 37, 50, 62, 75, 87};
    struct TreeNode* root = construct(arr, 0, sizeof(arr) / sizeof(*arr) - 1);
    printf("\nGiven BST: \n");
    display(root);

    printf("\nBST after converting to greater tree:\n");
    root = bstToGst(root);

    display(root);
    destruct(&root);
}