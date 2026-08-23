class Solution {
    TreeNode* justdo(TreeNode* node, set<int>& s, vector<TreeNode*>& ans) {
        if (node == nullptr)
            return nullptr;
        node->left = justdo(node->left, s, ans);
        node->right = justdo(node->right, s, ans);
        if (s.find(node->val) != s.end()) {
            if (node->left)
                ans.push_back(node->left);
            if (node->right)
                ans.push_back(node->right);
            return nullptr;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s;
        vector<TreeNode*> ans;
        for (int i : to_delete)
            s.insert(i);
        root = justdo(root, s, ans);
        if(root)
            ans.push_back(root);
        return ans;
    }
};