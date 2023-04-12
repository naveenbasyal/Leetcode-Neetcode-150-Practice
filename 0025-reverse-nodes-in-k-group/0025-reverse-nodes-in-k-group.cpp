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
    int getLen(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLen(head);
        if(len<k || head == NULL || head->next == NULL) return head;
        
        ListNode* curr = head; ListNode* prev= NULL; ListNode* next = NULL;
        int count = k;
        while(curr!= NULL and count > 0){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};