class Solution {
    TreeNode* solve(unordered_map<int, int>& m, vector<int>& inorder,vector<int>& postorder, int& index, int start, int end) {
        if (start > end)
            return nullptr;
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int possition = m[element];
        root->right = solve(m, inorder, postorder, index, possition + 1, end);
        root->left =solve(m, inorder, postorder, index, start, possition - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        int index = n - 1;
        TreeNode* ans = solve(m, inorder, postorder, index, 0, n - 1);
        return ans;
    }
};