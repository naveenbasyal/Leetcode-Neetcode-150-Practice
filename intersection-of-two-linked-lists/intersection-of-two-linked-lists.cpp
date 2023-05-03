/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int sizeA = 0 , sizeB =0;
        ListNode* currA = headA; ListNode* currB = headB;
        while(currA != NULL){
            sizeA++;
            currA = currA->next;
        }
        currA = headA;
         while(currB != NULL){
            sizeB++;
            currB = currB->next;
        }
        currB = headB;
        int diff = abs(sizeA - sizeB);
        
        if(sizeA > sizeB){
            while(diff){
                currA = currA->next;
                diff--;
            }
        }
        else{
            while(diff){
                currB = currB->next;
                diff--;
            }
        }

        while(currA != NULL and currB != NULL){
            if(currA == currB){
               return currA;
            }
             currA = currA->next;
             currB = currB->next;
        }
        return nullptr;
         
        
        
    }

};
