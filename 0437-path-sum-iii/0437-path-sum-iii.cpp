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
    void dev(TreeNode* node,int & count,long long sum, int targetSum){
        if(node == nullptr){
            return; 
        }
        sum += node->val;
        if(sum == targetSum){
            count++;
        }
        dev(node->left,count,sum,targetSum);
        dev(node->right,count,sum,targetSum);
    }
    void first(TreeNode * node ,int & count, int targetSum){
        if(node == nullptr){
            return;
        }
        dev(node,count,0,targetSum);
        first(node->left,count,targetSum);
        first(node->right,count,targetSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        first(root,count,targetSum);
        return count;
    }
};