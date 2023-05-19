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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(slow->next->next == NULL) {
            slow->next = NULL;
            return head;
        }
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        while(slow != fast){
            
            slow->val = slow->next->val;
            if(slow->next->next == NULL){
                delete slow->next;
                slow->next = NULL;
                break;
            }
            slow = slow->next;
        }

        
        return head;
    }
};