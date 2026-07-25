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
    void justdothis(TreeNode * node,vector<int>&tem){
        if(node == nullptr)
            return;
        justdothis(node->left,tem);
        if(node -> left == nullptr && node->right == nullptr){
            tem.push_back(node->val);
        }
        justdothis(node->right,tem);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>first;
        vector<int>second;
        justdothis(root1,first);
        justdothis(root2,second);
        return first == second;
    }
};