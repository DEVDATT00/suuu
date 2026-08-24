class Solution {
    int count = 0;
    pair<int, int> findout(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        auto left = findout(root->left);
        auto right = findout(root->right);
        int sum = root->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;
        if (root->val == sum / nodes)
            count++;
        return {sum, nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        findout(root);
        return count;
    }
};