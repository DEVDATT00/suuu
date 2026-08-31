class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};
        ListNode* first = head->next;
        ListNode* pre = head;
        int position = 1;
        int firstcri = -1;
        int prevcri = -1;
        int mn = INT_MAX;
        while(first->next != nullptr) {
            bool critical = false;
            if(first->val > pre->val && first->val > first->next->val)
                critical = true;
            else if(first->val < pre->val && first->val < first->next->val)
                critical = true;
            if(critical) {
                if(firstcri == -1) {
                    firstcri = position;
                }
                else {
                    mn = min(mn, position - prevcri);
                }
                prevcri = position;
            }
            pre = first;
            first = first->next;
            position++;
        }
        if(firstcri == prevcri)
            return {-1, -1};
        int mx = prevcri - firstcri;
        return {mn, mx};
    }
};