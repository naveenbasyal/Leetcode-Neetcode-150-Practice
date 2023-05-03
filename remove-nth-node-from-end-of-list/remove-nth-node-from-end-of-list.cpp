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
        
        ListNode* dummy= new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        int count= 0;
        while(curr!= NULL){
            count++;
            curr= curr->next;
        }
        curr = dummy;
        for(int i=0;i < (count - n); i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return dummy->next;
        
    }
};