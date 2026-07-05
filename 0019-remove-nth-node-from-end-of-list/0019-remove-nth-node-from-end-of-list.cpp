/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*tem = nullptr;
        if(head -> next == nullptr){
            return tem;
        }
        int count = 0;
        tem = head;
        while(tem != nullptr){
            count++;
            tem = tem -> next;
        }
        if(count == 1 && n == 1){
            return nullptr;
        }
        if(count == 2 && n == 1){
            head -> next = nullptr;
            return head;
        }
        if(count == n){
           return head->next;
        }
        count = count - n ;
        tem = head;
        for(int i = 0 ; i < count - 1 ; i++){
            tem = tem -> next;
        }
        if(tem -> next != nullptr &&tem -> next -> next != nullptr){
            tem -> next = tem -> next -> next;
        }
        else{
            tem -> next = nullptr;
        }
        return head;
    }
};