class Solution {
    int findposition(vector<int>& nums, int element, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (nums[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int& index, int start, int end) {
        if (start > end)
            return nullptr;
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findposition(inorder, element, start, end);
        root->left = solve(inorder, preorder, index,start, position - 1);
        root->right = solve(inorder, preorder, index,position + 1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int index = 0;
        TreeNode* ans = solve(inorder, preorder, index,0, n - 1);
        return ans;
    }
};