class Solution {
    TreeNode* remove(TreeNode* root, int target) {
        if (root == nullptr)
            return nullptr;
        root->left = remove(root->left, target);
        root->right = remove(root->right, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return remove(root, target);
    }
};