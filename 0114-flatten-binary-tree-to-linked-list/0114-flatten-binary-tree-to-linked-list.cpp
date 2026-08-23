class Solution {
    TreeNode* prev = nullptr;
    void visited(TreeNode* root) {
        if (root == nullptr)
            return;
        visited(root->right);
        visited(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

public:
    void flatten(TreeNode* root) {
        visited(root);
    }
};