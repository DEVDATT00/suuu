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
    int getDecimalValue(ListNode* head) {
        int count = 0 ;
        ListNode* check = head;
        while(check != nullptr){
            count++;
            check = check -> next;
        }
        int i = count - 1;
        check = head;
        count = 0;
        for(; i >= 0 && check != nullptr ; i--){
            if(check -> val == 1){
                count += pow(2,i);
            }
            check = check -> next;
        }
        return count;
    }
};