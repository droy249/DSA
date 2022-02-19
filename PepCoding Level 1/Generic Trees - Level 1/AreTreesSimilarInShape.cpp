// Question Link: https://nados.io/question/are-trees-similar-in-shape
// Video Link: https://youtu.be/y_PIhsd9vt0?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
#include <bits/stdc++.h>
using namespace std;

// Node definition
struct Node {
    int data;
    vector<Node*> children;
};

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

void destructor(Node*& root) {
    if (!root) return;
    for (auto&& child: root->children)
        destructor(child);
    delete root;
    root = nullptr;
}

// void destructor(Node*& root) {
//     if (!root) return;

//     queue<Node*> qu;
//     qu.push(root);

//     while (!qu.empty()) {
//         Node* node{qu.front()};
//         qu.pop();

//         for (auto&& child : root->children)
//             if (child)
//                 qu.push(child);
//     }

//     delete root;
//     root = nullptr;
// }

// Displays tree in adjacency list form
// Video Link: https://youtu.be/3xovYxKCgBQ?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/display_a_generic_tree/topic
void display(Node* root) {
    if (!root) {
        cout << "Empty!!\n";
        return;
    }

    string str(to_string(root->data) + " -> ");

    for (auto&& child : root->children)
        str += to_string(child->data) + ", ";
    str += ".";

    cout << str << '\n';

    for (auto&& child : root->children)
        display(child);
}

// https://nados.io/article/are-trees-similar-in-shape#:~:text=5.-,Analysis,-%3A
bool areTreesSimilarInShape(Node* root1, Node* root2) {
    if (root1->children.size() != root2->children.size()) return false;

    for (int i{}; i < root1->children.size(); ++i)
        if (!areTreesSimilarInShape(root1->children.at(i), root2->children.at(i)))
            return false;

    return true;
}

int main() {
    const vector<int> tree1{
        10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1
        // 10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1
    };
    Node* root1 = constructor(tree1);

    const vector<int> tree2{
        100, 200, -1, 300, 500, -1, 600, -1, -1, 400, -1, -1
        // 1, 2, 5, -1, 6, -1, -1, 3, 7, -1, 8, 11, -1, 12, -1, -1, 9, -1, -1, 4, 10, -1, -1, -1
    };
    Node* root2 = constructor(tree2);

    cout << "\nGiven generic tree1 ('.' denotes null): \n";
    display(root1);

    cout << "\nGiven generic tree2 ('.' denotes null): \n";
    display(root2);

    cout << "\nThese generic trees are" << (areTreesSimilarInShape(root1, root2) ? " " : " not ") << "similar in shape";

    destructor(root1);
    destructor(root2);
    cout << "\n\n";
}