class Solution {
    TreeNode* solve(unordered_map<int, int>&map, vector<int>& inorder,vector<int>& preorder, int& index, int start, int end) {
        if (start > end)
            return nullptr;
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = map[element];
        root->left = solve(map, inorder, preorder, index, start, position - 1);
        root->right = solve(map, inorder, preorder, index, position + 1, end);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        int index = 0;
        TreeNode* ans = solve(map, inorder, preorder, index, 0, n - 1);
        return ans;
    }
};