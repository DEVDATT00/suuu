/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void doit(TreeNode* node, int& count) {
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
            count += node->left->val;
        }
        doit(node->left, count);
        doit(node->right, count);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int count = 0;
        doit(root, count);
        return count;
    }
};