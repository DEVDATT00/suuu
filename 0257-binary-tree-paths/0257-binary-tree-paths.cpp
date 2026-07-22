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
    void dothat(TreeNode* node , vector<string>&ans,string s){
        if(node == nullptr){
            return;
        }
        s += to_string(node->val);
        if(node->right == nullptr && node->left == nullptr){
            ans.push_back(s);
            return;
        }
        s += "->";
        dothat(node->left,ans,s);
        dothat(node->right,ans,s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        
        dothat(root,ans,"");
        return ans;
    }
};