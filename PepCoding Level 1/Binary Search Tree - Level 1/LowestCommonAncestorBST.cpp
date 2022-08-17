// Question Link: https://nados.io/question/lca-of-bst
// Video Link: https://youtu.be/5E3MeajU9XQ?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// Leetcode Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else 
        return root;
}

int main() {
    const int arr[] = {12, 25, 37, 50, 62, 75, 87};
    struct TreeNode* root = construct(arr, 0, sizeof(arr) / sizeof(*arr) - 1);
    printf("\nGiven BST: \n");
    display(root);

    printf("\n\n");
    

    display(root);
    destruct(&root);
}