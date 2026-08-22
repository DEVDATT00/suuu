
class Solution {
public: 
     ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head);
        ListNode* prev = newHead;
        ListNode* temp = prev->next;
        while(temp != NULL){
            if(temp->val < prev->val){
                temp = temp->next;
                prev->next = temp;
            }else {
                prev = temp; 
                temp = temp->next;
            }
        }
        return reverseList(newHead);
    }
};