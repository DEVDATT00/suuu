class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* second = new ListNode(0);
        ListNode* first = new ListNode(0);
        ListNode* visit = head;
        ListNode* small = first;
        ListNode* large = second;
        while (visit != nullptr) {
            if (visit->val < x) {
                small->next = visit;
                small = small->next;
            }
            else {
                large->next = visit;
                large = large->next;
            }
            visit = visit->next;
        }
        large->next = nullptr;
        small->next = second->next;
        return first->next;
    }
};