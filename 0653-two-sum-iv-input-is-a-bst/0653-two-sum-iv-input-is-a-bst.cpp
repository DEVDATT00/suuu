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
    void dothat(TreeNode* node , vector<int>&ans){
        if(node == NULL){
            return;
        }
        dothat(node->left,ans);
        ans.push_back(node->val);
        dothat(node->right,ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        dothat(root,ans);
        int i = 0 , j = ans.size() - 1,tem;
        while(i < j){
            tem = ans[i]+ans[j];
            if(tem == k){
                return true;
            }else if(tem > k){
                j--;
            }else if(tem < k){
                i++;
            }
        }
        return false;
    }
};