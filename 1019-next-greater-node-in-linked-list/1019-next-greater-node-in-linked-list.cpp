class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int> ans(nums.size(), 0);
        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top();
            }
            s.push(nums[i]);
        }
        return ans;
    }
};