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
    bool dfs(TreeNode* root, int num , int targetSum) {
        if(root == nullptr ){
            return false;
        }
        num += root->val;
        if(root->left == nullptr && root->right == nullptr){
            return num == targetSum;
        }
        return dfs(root->left,num,targetSum) || dfs(root->right,num,targetSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0 , targetSum);
    }
};