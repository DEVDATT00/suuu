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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return{};
        vector<vector<int>>ans;
        bool even = false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>subans;
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode * node = q.front();
                subans.push_back(node->val);
                q.pop();
                if(node -> left)
                    q.push(node->left);
                if(node -> right)
                    q.push(node -> right);
            }
            if(even)
                reverse(subans.begin(),subans.end());
            ans.push_back(subans);
            even = !even;
        }
        return ans;
    }
};