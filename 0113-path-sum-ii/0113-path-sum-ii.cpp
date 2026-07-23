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
    void dothat(TreeNode * node,vector<vector<int>>&ans,vector<int>&tem,int count, int targetSum){
        if(node == nullptr){
            return;
        }
        tem.push_back(node->val);
        count += node->val;
        if(node->left == nullptr && node->right == nullptr && count == targetSum){
            ans.push_back(tem);
        }
        dothat(node->left,ans,tem,count,targetSum);
        dothat(node->right,ans,tem,count,targetSum);
        tem.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>tem;
        vector<vector<int>>ans;
        dothat(root,ans,tem,0,targetSum);
        return ans;
    }
};