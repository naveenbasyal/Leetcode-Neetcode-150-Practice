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
    
    ListNode* findmid(ListNode* head){
        ListNode* slow = head; ListNode* fast = head;
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while(left != NULL and right != NULL){
            if(left->val <= right->val){
                curr -> next = left;
                curr = curr -> next;
                left = left -> next;
            }
            else{
                curr -> next = right;
                curr = curr->next;
                right = right->next;
            }
        }
        while(left != NULL){
            curr -> next = left;
            curr = curr -> next;
            left = left -> next;
        }
        while(right != NULL){
             curr -> next = right;
             curr = curr->next;
             right = right->next;
        }
        return dummy->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        // base
        if(head == NULL or head->next == NULL) return head;
    
        //finding mid;
        ListNode* mid = findmid(head);
        
        //splitting list
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* ans = merge(left,right);
    
        return ans;
        
    }
    
};