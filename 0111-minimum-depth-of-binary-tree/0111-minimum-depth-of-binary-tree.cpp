/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int mx(TreeNode* node ){
        if(node == nullptr){
            return 0;
        }
        if(node->left == nullptr && node->right == nullptr){
            return 1;
        }
        if(node->left == nullptr){
            return 1 + mx(node->right); 
        }
        if(node->right == nullptr){
            return 1 + mx(node->left); 
        }
        return 1 + min(mx(node->left),mx(node->right));
    }
public:
    int minDepth(TreeNode* root) {
        return mx(root);
    }
};