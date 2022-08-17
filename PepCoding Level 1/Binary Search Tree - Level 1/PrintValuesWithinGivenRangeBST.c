// Question Link: https://nados.io/question/print-in-range
// Video Link: https://youtu.be/NEJUsqEFOI4?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// Leetcode Link: https://leetcode.com/problems/range-sum-of-bst/
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

void printIfWithinRangeBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) return;

    if (root->val > low)
        printIfWithinRangeBST(root->left, low, high);

    if (root->val >= low && root->val <= high)
        printf("%d\n", root->val);

    if (root->val < high)
        printIfWithinRangeBST(root->right, low, high);
}

int main() {
    const int arr[] = {12, 25, 37, 50, 62, 75, 87};
    struct TreeNode* root = construct(arr, 0, sizeof(arr) / sizeof(*arr) - 1);
    printf("\nGiven BST: \n");
    display(root);

    int low, high;
    printf("\nEnter lower limit: ");
    scanf("%d", &low);
    printf("\nEnter upper limit: ");
    scanf("%d", &high);

    printf("\nValues which lie between given range are\n");
    printIfWithinRangeBST(root, low, high);

    destruct(&root);
}