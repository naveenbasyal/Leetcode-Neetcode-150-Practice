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
    
    int getlen(ListNode* head){
        int len=0;
        ListNode* curr = head;
        while(curr!= NULL){
            len++;
            curr = curr->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getlen(head);
        if(head == NULL || head->next == NULL || k==1 || len < k) return head;
        
        ListNode* prev = NULL; ListNode* curr = head;
        int count = k;
        while(curr!= NULL and count>0){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            count--;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
        
    }
};