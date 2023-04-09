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
    void reorderList(ListNode* head) {
         if (head == NULL || head->next == NULL) return;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while( fast -> next!= NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow points to the mid of the ll
        ListNode *head2 = slow->next;
        slow->next = NULL; 
        // now the first and second half is spliitted.
        // we need to reverse the second half
        
        if(head2 != NULL){
            ListNode *prev = NULL;
            ListNode *curr = head2;
        
            while(curr!=NULL){
                ListNode *forward = curr -> next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
          head2 = prev;
        }
        // now second half is reversed, we need to merge both half
        
        ListNode *curr1 = head;
        ListNode *curr2 = head2;
        
        
        while(curr1 != NULL and curr2 != NULL){
            ListNode *next1 = curr1->next;
            ListNode *next2 = curr2->next;
            
            curr1->next = curr2;
            curr2->next = next1;
            
            curr1 = next1;
            curr2 = next2;
        }   
        
    }
    
};