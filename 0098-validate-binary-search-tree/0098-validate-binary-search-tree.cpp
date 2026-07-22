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
    void in(TreeNode* node, vector<int>&ans){
        if(node == nullptr){
            return;
        }
        in(node->left,ans);
        ans.push_back(node->val);
        in(node->right,ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        in(root,ans);
        for(int i = 0 ; i < ans.size()-1 ; i++){
            if(ans[i] >= ans[i+1]){
                return false;
            }
        }
        return true;
    }
};