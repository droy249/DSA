// Question Link: https://nados.io/question/iterative-preorder-and-postorder-of-generic-tree
// Video Link: https://youtu.be/5ry6gRrzPqc?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
#include <bits/stdc++.h>
using namespace std;

// Node definition
struct Node {
    int data;
    vector<Node*> children;
};

// Build/construct a generic tree
// Video Link: https://youtu.be/9Oi3WamOCPo?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/generic_tree_constructor/topic
Node* constructor(const vector<int> nums) {
    Node* root = nullptr;
    stack<Node*> stack;

    for (const int& num : nums) {
        if (num == -1)
            stack.pop();
        else {
            Node* node = new Node;
            node->data = num;

            if (!root)
                root = node;
            else
                stack.top()->children.push_back(node);

            stack.push(node);
        }
    }
    return root;
}

void destructor(Node* root) {
    for (auto&& child : root->children)
        destructor(child);
    delete root;
}

// Displays tree in adjacency list form
// Video Link: https://youtu.be/3xovYxKCgBQ?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/display_a_generic_tree/topic
void display(Node* root) {
    string str(to_string(root->data) + " -> ");

    for (auto&& child : root->children)
        str += to_string(child->data) + ", ";
    str += ".";

    cout << str << '\n';

    for (auto&& child : root->children)
        display(child);
}

void iterativePreorderAndPostorder(Node* root, vector<int>& preorder, vector<int>& postorder) {
    // pair.first denotes the node
    // pair.second denotes the state
    stack<pair<Node*, int>> st;

    /* state == -1  --->    Print in preorder and ++state
     * 0 <= state <= root->children.size()-1    --->    Push child to stack (equivalent to recursive stack call in iterative mode) and ++state
     * state == root->children.size()   --->    Print in postorder and pop()
     **/

    st.push({root, -1});
    while (!st.empty()) {
        auto p = st.top();

        if (p.second == -1) {
            preorder.push_back(p.first->data);
            ++p.second;
        } else if (p.second == p.first->children.size()) {
            postorder.push_back(p.first->data);
            st.pop();
        } else {
            st.push({p.first->children.at(p.second), -1});
            ++p.second;
        }
    }
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "\nGiven generic tree ('.' denotes null): \n";
    display(root);

    vector<int> preorder, postorder;
    iterativePreorderAndPostorder(root, preorder, postorder);

    cout << "\nPreorder traversal: ";
    for (auto&& data : preorder) cout << data << ' ';

    cout << "\nPostorder traversal: ";
    for (auto&& data : postorder) cout << data << ' ';

    destructor(root);
    cout << "\n\n";
}