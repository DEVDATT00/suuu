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
    int maintask(TreeNode*node,int count){
        if(node == nullptr){
            return 0 ;
        }
        count = count * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr)
        return count;
        
        return maintask(node->right, count)+maintask(node->left, count);
    }
public:
    int sumNumbers(TreeNode* root) {
        return maintask(root, 0);
    }
}; 