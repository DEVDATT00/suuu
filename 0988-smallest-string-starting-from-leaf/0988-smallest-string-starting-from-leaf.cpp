class Solution {
public:
    string ans = "";
    void dfs(TreeNode* root, string path) {
        if (root == NULL)
            return;
        path = char('a' + root->val) + path;
        if (root->left == NULL && root->right == NULL) {
            if (ans == "" || path < ans) {
                ans = path;
            }
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};