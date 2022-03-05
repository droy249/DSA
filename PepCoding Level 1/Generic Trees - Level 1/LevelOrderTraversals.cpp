// Question Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/
// Alt Question Link: https://nados.io/content/generic-tree
// Playlist Link: https://youtube.com/playlist?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
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

// Free memory allocated to build generic tree
void destructor(Node* root) {
    for (auto&& child : root->children)
        destructor(child);
    delete root;
}

// Prints level order traversal of generic tree
// Question Link: https://nados.io/question/level-order-of-generic-tree
// Video Link: https://youtu.be/TUxo5YpKvxw?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
void levelOrder(Node* root) {
    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        root = queue.front();
        queue.pop();
        cout << root->data << " ";
        for (auto&& child : root->children)
            queue.push(child);
    }

    cout << "\n\n";
}

// Prints level order traversal LEVELWISE/LINEWISE of generic tree (APPROACH 1) (MAIN QUEUE AND CHILD QUEUE APPROACH)
// Question Link: https://nados.io/question/levelOrder-linewise-generic-tree
// Video Link:
void levelOrderLevelwise1(Node* root) {
    queue<Node*> mainQ, childQ;
    mainQ.push(root);

    while (!mainQ.empty()) {
        root = mainQ.front();
        mainQ.pop();
        cout << root->data << " ";

        for (auto&& child : root->children)
            childQ.push(child);

        if (mainQ.empty()) {
            swap(mainQ, childQ);
            cout << "\n";
        }
    }

    cout << "\n\n";
}

// Prints level order traversal LEVELWISE/LINEWISE of generic tree (APPROACH 2) (DELIMITER APPROACH)
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/level_order_traversal_more_approaches/topic
// Article Link 2: https://nados.io/article/level-order-traversal-more-approaches
// Video Link: https://youtu.be/NuASXwfaFaY?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_&t=92
void levelOrderLevelwise2(Node* root) {
    queue<Node*> queue;
    queue.push(root);
    queue.push(nullptr);  // nullptr is the delimiter for indicating levels

    while (!queue.empty()) {
        root = queue.front();
        queue.pop();

        if (root != nullptr) {
            cout << root->data << " ";
            for (auto&& child : root->children)
                queue.push(child);
        } else {
            if (!queue.empty()) {
                queue.push(root);
                cout << "\n";
            }
        }
    }

    cout << "\n\n";
}

// Prints level order traversal LEVELWISE/LINEWISE of generic tree (APPROACH 3) (COUNT APPROACH)
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/level_order_traversal_more_approaches/topic
// Article Link 2: https://nados.io/article/level-order-traversal-more-approaches
// Video Link: https://youtu.be/NuASXwfaFaY?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_&t=559
void levelOrderLevelwise3(Node* root) {
    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {  // PPA -> Pop, Print, Add for every size of every level of tree
        int size = queue.size();
        while (size--) {
            root = queue.front();
            cout << root->data << " ";
            queue.pop();
            for (auto&& child : root->children)
                queue.push(child);
        }
        cout << "\n";
    }

    cout << "\n\n";
}

// Prints level order traversal LEVELWISE/LINEWISE of generic tree (APPROACH 4) (Using Pairs -> {Key: Node*, Value: level})
// Article Link: https://www.pepcoding.com/resources/online-java-foundation/generic-tree/level_order_traversal_more_approaches/topic
// Article Link 2: https://nados.io/article/level-order-traversal-more-approaches
// Video Link: https://youtu.be/NuASXwfaFaY?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_&t=956
void levelOrderLevelwise4(Node* root) {
    queue<pair<Node*, int>> queue;
<<<<<<< HEAD
    int levelNumber = 1;
    queue.push({root, levelNumber});
=======
    int level = 1;
    queue.push({root, level});
>>>>>>> origin/main

    while (!queue.empty()) {
        auto pair = queue.front();
        queue.pop();
<<<<<<< HEAD
        if (pair.second > levelNumber) {
            levelNumber = pair.second;
=======
        if (pair.second > level) {
            level = pair.second;
>>>>>>> origin/main
            cout << '\n';
        }

        cout << pair.first->data << " ";
        for (auto&& child : pair.first->children)
            queue.push({child, pair.second + 1});
<<<<<<< HEAD
=======

        // delete pair.first;
>>>>>>> origin/main
    }

    cout << "\n\n";
}

// Prints level order traversal LEVELWISE in a ZIGZAG manner
// Question Link: https://nados.io/question/levelorder-linewise-generic-tree
// Video Link: https://youtu.be/eDdPZ05y4Os?list=PL-Jc9J83PIiEmjuIVDrwR9h5i9TT2CEU_
void levelOrderLevelwiseZigZag(Node* root) {
    stack<Node*> mainS, childS;
    mainS.push(root);

<<<<<<< HEAD
    int level;
=======
    bool leftToRight;
>>>>>>> origin/main
    while (!mainS.empty()) {
        root = mainS.top();
        mainS.pop();
        cout << root->data << " ";

<<<<<<< HEAD
        if (level & 1) 
            for (auto&& child : root->children)
                childS.push(child);
        else 
            for (int i = root->children.size() - 1; ~i; --i)
                childS.push(root->children.at(i));
        
=======
        if (leftToRight) {
            for (auto&& child : root->children)
                childS.push(child);
            leftToRight = false;
        } else {
            for (int i = root->children.size() - 1; ~i; --i)
                childS.push(root->children.at(i));
            leftToRight = true;
        }
>>>>>>> origin/main

        if (mainS.empty()) {
            swap(mainS, childS);
            cout << "\n";
        }
    }

    cout << "\n\n";
}

int main() {
    const vector<int> nums{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node* root = constructor(nums);

    cout << "Level order traversal of generic tree: ";
    levelOrder(root);

    cout << "Level order traversal (level-wise) of generic tree (Main Queue - Child Queue Approach): \n";
    levelOrderLevelwise1(root);

    cout << "Level order traversal (level-wise) of generic tree (Delimiter Approach): \n";
    levelOrderLevelwise2(root);

    cout << "Level order traversal (level-wise) of generic tree (Count Approach): \n";
    levelOrderLevelwise3(root);

    cout << "Level order traversal (level-wise) of generic tree (Pair Approach): \n";
    levelOrderLevelwise4(root);

    cout << "Level order travseral (level-wise, zig-zag) of generic tree: \n";
    levelOrderLevelwiseZigZag(root);

    destructor(root);
}