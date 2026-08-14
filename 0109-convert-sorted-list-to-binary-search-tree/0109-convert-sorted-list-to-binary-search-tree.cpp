class Solution {
public:
    TreeNode* buildTree(vector<int>& arr, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildTree(arr, left, mid - 1);
        root->right = buildTree(arr, mid + 1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        return buildTree(arr, 0, arr.size() - 1);
    }
};