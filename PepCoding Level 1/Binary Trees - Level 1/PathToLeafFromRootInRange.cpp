// Question Link: https://nados.io/question/path-to-leaf-from-root-in-range
// Video Link: https://youtu.be/A6Z5YvsrDtg?list=PLNQqARTgXkMbp1R47hg9NnCNVAraXJv99
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

void nodeToRootPathWithinRange(vector<vector<int>>& paths, TreeNode*&    root, const int& low, const int& high, vector<int> path = {}, int sum = 0) {
    // Base case for null root or when node has only one child
    if (not root) return;

    // First we are adding the root->val to both path and sum because we have not fone so for child node.
    path.emplace_back(root->val);
    sum += root->val;

    // When we reach leaf nodethem we simply check 
    if (root->left == root->right) {
        if (low <= sum and sum <= high)
            paths.emplace_back(path);
        return;
    }

    nodeToRootPathWithinRange(paths, root->left, low, high, path, sum);
    nodeToRootPathWithinRange(paths, root->right, low, high, path, sum);

    // // Backtrack not needed as control never reaches here
    // sum -= root->val;
    // path.pop_back();
}

int main() {
    TreeNode* root{construct1({
        // 50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1
        50, 25, 12, -1, -1, 37, 30, -1, -1, 40, -1, -1, 75, 62, 60, -1, -1, 70, -1, -1, 87, -1, -1
    })};
    // int idx{};
    // 50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
    // TreeNode* root{construct2({50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1}, idx)};

    cout << "Given binary tree:\n";
    display(root);
    cout << "\n";

    cout << "Enter lower range: ";
    int low;
    cin >> low;

    cout << "Enter higher range: ";
    int high;
    cin >> high;

    cout << "All paths from root to leaf with sum of all nodes within path lying within range: \n";
    vector<vector<int>> allPaths;
    nodeToRootPathWithinRange(allPaths, root, low, high);
    for (auto&& path : allPaths) {
        for (auto&& node : path)
            cout << node << " ";
        cout << "\n";
    }
    cout << "\n";

    destruct(root);
}