class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* start = head;
        while (start != nullptr) {
            count++;
            start = start->next;
        }
        int size = count / k;
        int extra = count % k;
        vector<ListNode*> ans(k, nullptr);
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ans[i] = curr;
            int partSize = size + (i < extra ? 1 : 0);
            for (int j = 1; j < partSize && curr != nullptr; j++) {
                curr = curr->next;
            }
            if (curr != nullptr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }
        return ans;
    }
};