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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* evenHead = head , *oddHead = head->next;
        ListNode* currOdd = oddHead , *currEven = evenHead;
        
        while(currOdd->next != NULL or currEven->next != NULL){
            currEven -> next = currOdd -> next;
            
            if(currOdd->next != NULL){
                currEven = currOdd -> next;
            }
            
            currOdd -> next = currEven ->next;
            
            if(currEven->next != NULL){
                currOdd = currEven -> next;
            }
        }
        currEven->next = oddHead;
        
        return evenHead;
        
        
    }
};