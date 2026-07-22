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
    void let(TreeNode* node,vector<int>&ans){
        if(node == nullptr)
            return;
        let(node->left,ans);
        ans.push_back(node->val);
        let(node->right,ans);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        vector<int>fans;
        let(root1,ans1);
        let(root2,ans2);
        int i = 0 , j = 0;
        while(i < ans1.size() && j < ans2.size()){
            if(ans1[i] <= ans2[j]){
                fans.push_back(ans1[i]);
                i++;
            }else if(ans1[i] > ans2[j]){
                fans.push_back(ans2[j]);
                j++;
            }
        }
        while(i < ans1.size()){
            fans.push_back(ans1[i]);
            i++;
        }
        while(j < ans2.size()){
            fans.push_back(ans2[j]);
            j++;
        }
        return fans;
    }
};