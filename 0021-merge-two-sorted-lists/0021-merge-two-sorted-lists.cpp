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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        ListNode * first = list1;
        ListNode * second = list2;
        ListNode* r;
        ListNode* fin;
        if(first -> val < second-> val){
            r = first;
            fin = first;
            first = first->next;
        }else {
            r = second;
            fin = second;
            second = second -> next;
        }
        while(first != nullptr && second != nullptr){
            if(first -> val >= second -> val){
                fin -> next = second;
                second = second -> next;
            }else{
                fin -> next = first;
                first = first -> next;
            }
            fin = fin -> next;
        }
        while(first != nullptr){
            fin -> next = first;
            first = first -> next;
            fin = fin -> next;
        }
        while(second != nullptr){
            fin -> next = second;
            second = second -> next;
            fin = fin -> next;
        }
        return r;
    }
};