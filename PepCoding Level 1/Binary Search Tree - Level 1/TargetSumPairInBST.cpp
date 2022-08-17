// Question Link: https://nados.io/question/target-sum-pair-in-bst
// Video Link: https://youtu.be/ouuGHu9Sjhg?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// Video Link 2: https://youtu.be/iK2VFYxFC4o?list=PL-Jc9J83PIiGl_-iS5k7R7SZoZPt0Fab2
// Leetcode Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include <bits/stdc++.h>
using namespace std;

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

bool find(struct TreeNode* root, int val) {
    if (root == NULL) return false;

    if (val > root->val)
        return find(root->right, val);
    else if (val < root->val)
        return find(root->left, val);
    else
        return true;
}

// Approach 1: Intuitive brute force
// Time Complexity: O(n log n) or O (n * h), h = height of tree
// Space Complexity: O(h)
void printAllTargetSumPairs(struct TreeNode* ROOT, struct TreeNode* root, int target) {
    if (root == NULL) return;

    printAllTargetSumPairs(ROOT, root->left, target);

    int complement = target - root->val;
    if (root->val < complement)
        if (find(ROOT, complement))
            printf("%d and %d\n", root->val, complement);

    printAllTargetSumPairs(ROOT, root->right, target);
}

void inorder(TreeNode* root, vector<int>& list) {
    if (root == NULL) return;
    inorder(root->left, list);
    list.push_back(root->val);
    inorder(root->right, list);
}

// Approach 2: Store inorder traversal in a list
// Time Complexity: O(n)
// Space Complexity: O(n)
void printAllTargetSumPairs2(TreeNode* root, int target) {
    vector<int> list;
    inorder(root, list);

    for (int i = 0, j = list.size() - 1; i < j;)
        if (list[i] + list[j] < target)
            ++i;
        else if (list[i] + list[j] > target)
            --j;
        else {
            printf("%d and %d\n", list[i], list[j]);
            ++i;
            --j;
        }
}

TreeNode* getNextFromInorder(stack<pair<TreeNode*, int>>& stack) {
    while (not stack.empty()) {
        auto &top = stack.top();

        /* top.first -> node (TreeNode*)
           top.second -> state (int)
         */
        
        // state = 0 --> PRERDER
        if (top.second == 0) {
            if (top.first->left)
                stack.push({top.first->left, 0});
            ++top.second;
        }
        
        // state = 1 --> INORDER
        else if (top.second == 1) {
            if (top.first->right)
                stack.push({top.first->right, 0});
            ++top.second;
            return top.first;
        } 
        
        // state = 2 --> POSTORDER
        else {  // state == 2
            stack.pop();
        }
    }

    return nullptr;
}

TreeNode* getNextFromReverseInorder(stack<pair<TreeNode*, int>>& stack) {
    while (not stack.empty()) {
        auto &top = stack.top();

        /* top.first -> node (TreeNode*)
           top.second -> state (int)
         */
        
        // state = 0 --> PRERDER
        if (top.second == 0) {
            if (top.first->right)
                stack.push({top.first->right, 0});
            ++top.second;
        }
        
        // state = 1 --> INORDER
        else if (top.second == 1) {
            if (top.first->left)
                stack.push({top.first->left, 0});
            ++top.second;
            return top.first;
        } 
        
        // state = 2 --> POSTORDER
        else {  // state == 2
            stack.pop();
        }
    }

    return nullptr;
}

/* BEST APPROACH */
// Approach 3: Iterative inorder (for left) + reversive iterative inorder for (right) approach
// Time Complexity: O(n)
// Space Complexity: O(h)
void printAllTargetSumPairs3(TreeNode* root, int target) {
    stack<pair<TreeNode*, int>> leftStack, rightStack;
    
    leftStack.push({root, 0});
    rightStack.push({root, 0});

    TreeNode* left = getNextFromInorder(leftStack);
    TreeNode* right = getNextFromReverseInorder(rightStack);

    while (left->val < right->val)
        if (left->val + right->val < target)
            left = getNextFromInorder(leftStack);
        else if (left->val + right->val > target)
            right = getNextFromReverseInorder(rightStack);
        else {
            cout << left->val << " " << right->val << endl;
            left = getNextFromInorder(leftStack);
            right = getNextFromReverseInorder(rightStack);
        }
}

int main() {
    const int arr[] = {12, 25, 37, 50, 62, 75, 87};
    struct TreeNode* root = construct(arr, 0, sizeof(arr) / sizeof(*arr) - 1);
    printf("\nGiven BST: \n");
    display(root);

    printf("\nEnter target sum: ");
    int target;
    scanf("%d", &target);

    printf("\nPairs which add up to %d are:\n", target);
    printAllTargetSumPairs(root, root, target);
    // printAllTargetSumPairs2(root, target);
    printAllTargetSumPairs3(root, target);

    destruct(&root);
}