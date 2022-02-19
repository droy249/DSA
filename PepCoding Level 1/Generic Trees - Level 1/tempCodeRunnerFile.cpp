vector<int> nodeToRootPath(Node* root, int data) {
    if (root->data == data)
        return {data};

    for (auto&& child : root->children) {
        vector<int> path{nodeToRootPath(child, data)};
        if (!path.empty()) {
            path.emplace_back(root->data);
            return path;
        }
    }

    return {};
}