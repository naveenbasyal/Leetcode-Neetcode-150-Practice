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
        int c = 0; ListNode* temp =head;
        while(temp != NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getlen(head);
        
        if(n < k || head==NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* nex=NULL;
        ListNode* curr=head;
        int count = k;
        while(curr !=NULL && count!=0){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            count--;
        }
        head->next=reverseKGroup(curr,k);
        
        return prev;
    }


};