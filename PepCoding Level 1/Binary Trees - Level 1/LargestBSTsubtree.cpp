// Question Link: https://nados.io/question/largest-bst-subtree
// Video Link: https://youtu.be/UGsJz8fSYp0?list=PL-Jc9J83PIiHYxUk8dSu2_G7MR1PaGXN4
// Gfg Link: https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
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

// Article Link: https://nados.io/content/binary-tree-constructor
// Video Link: https://youtu.be/XV1ADVV6FbQ?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
TreeNode* construct1(vector<int> nums) {
    TreeNode* root{new TreeNode{nums.front()}};

    // Creating a stack of pairs to create binary tree from list
    // Here pair.first denotes the node while pair.second defines "state"
    // The "state" can be either:
    // a) 1 -> Node has been inserted in stack, now push its left child if exists else state += 1
    // b) 2 -> Left Subtree of Node has been traversed, now push its left child if exists else state += 1
    // c) 3 -> Pop node from stack. It has been fully traversed
    stack<pair<TreeNode*, int>> st;
    st.emplace(root, 1);

    int idx{};
    while (not st.empty()) {
        auto& [node, state] = st.top();
        if (state == 1) {
            ++idx;
            if (nums.at(idx) != -1) {
                node->left = new TreeNode{nums.at(idx)};
                st.emplace(node->left, 1);
            } else {
                node->right = nullptr;
            }
            ++state;
        } else if (state == 2) {
            ++idx;
            if (nums.at(idx) != -1) {
                node->right = new TreeNode{nums.at(idx)};
                st.emplace(node->right, 1);
            } else {
                node->right = nullptr;
            }
            ++state;
        } else {
            st.pop();
        }
    }

    return root;
}

TreeNode* construct2(vector<int> nums, int& idx) {
    if (idx == nums.size() or nums.at(idx) == -1) {
        ++idx;
        return nullptr;
    }
    return new TreeNode{nums.at(idx++), construct2(nums, idx), construct2(nums, idx)};
}

// Article Link: https://nados.io/content/display-a-binary-tree
// Video Link: https://youtu.be/sYU6AnSJyjo?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
void display(TreeNode* root) {
    if (not root) return;

    cout << (root->left ? to_string(root->left->val) : "null");
    cout << "<-" << to_string(root->val) << "->";
    cout << (root->right ? to_string(root->right->val) : "null") << endl;

    display(root->left);
    display(root->right);
}

void destruct(TreeNode*& root) {
    if (not root) return;
    destruct(root->left);
    destruct(root->right);
    delete root;
    root = nullptr;
}

// Approach 1 (Pepcoding approach)
tuple<bool,int,int,TreeNode*,int> largest_BST_subtree(TreeNode* root) {
    if (not root) return {true, numeric_limits<int>::max(), numeric_limits<int>::min(), nullptr, 0};

    auto [isLeftBST, leftMin, leftMax, rootOfLeftLargestBST_sutree, noOfNodesLeftLargestBST_subtree] = largest_BST_subtree(root->left);
    auto [isRightBST, rightMin, rightMax, rootOfRightLargestBST_subtree, noOfNodesRightLargestBST_subtree] = largest_BST_subtree(root->right);

    bool isCurBST{isLeftBST and isRightBST and (root->val > leftMax and root->val < rightMin)};
    int curMin{min({root->val, leftMin, rightMin})};
    int curMax{max({root->val, leftMax, rightMax})};
    TreeNode* rootOfCurLargestBST_subtree;
    int noOfNodesCurLargestBST_subtree;

    if (isCurBST) 
    {
        rootOfCurLargestBST_subtree = root;
        noOfNodesCurLargestBST_subtree = noOfNodesLeftLargestBST_subtree + noOfNodesRightLargestBST_subtree + 1;
    } 
    else if (noOfNodesLeftLargestBST_subtree > noOfNodesRightLargestBST_subtree) 
    {
        rootOfCurLargestBST_subtree = rootOfLeftLargestBST_sutree;
        noOfNodesCurLargestBST_subtree = noOfNodesLeftLargestBST_subtree;
    } 
    else 
    {
        rootOfCurLargestBST_subtree = rootOfRightLargestBST_subtree;
        noOfNodesCurLargestBST_subtree = noOfNodesRightLargestBST_subtree;
    }

    return {isCurBST, curMin, curMax, rootOfCurLargestBST_subtree, noOfNodesCurLargestBST_subtree};
}

int main() {
    TreeNode* root{construct1({
        // 50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1
        10, 20, 40, -1, -1, 50, -1, 80, -1, -1, 30, 60, 90, -1, -1, -1, 70, -1, -1
    })};
    // int idx{};
    // 50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
    // TreeNode* root{construct2({50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1}, idx)};

    cout << "Given binary tree:\n";
    display(root);
    cout << "\n";

    cout << "Largest BST subtree has root : " << get<3>(largest_BST_subtree(root))->val << " and has " << get<4>(largest_BST_subtree(root)) << "nodes.";

    cout << endl;
    destruct(root);
}