void traverse(TreeNode *node, vector<int> &inorder) {
    if (!node)
        return;
    traverse(node->left, inorder);
    inorder.push_back(node->val);
    traverse(node->right, inorder);
}

TreeNode *solve(int i, int j, vector<int> &inorder) {
    if (i > j)
        return NULL;
    int mid = (i + j) / 2;
    TreeNode *node = new TreeNode(inorder[mid]);
    node->left = solve(i, mid - 1, inorder);
    node->right = solve(mid + 1, j, inorder);
    return node;
}

TreeNode *balanceBST(TreeNode *root) {
    vector<int> inorder;
    traverse(root, inorder);
    int n = inorder.size();
    return solve(0, n - 1, inorder);
}