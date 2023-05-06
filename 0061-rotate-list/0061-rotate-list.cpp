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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* kth = head;
        ListNode* last = head;
        ListNode* kPrev = head;
        int size=1;
        //getting size and going to last node
        while(last->next != NULL){
            last = last->next;
            size++;
        }
        //creating ring
        last -> next = head;
        int count = size - (k % size); //modulo (for the cases where k is greater than size)
        while(count - 1 > 0){
            kPrev = kPrev->next;
            count--;
        }
        kth = kPrev->next;
        kPrev->next = NULL;
       
        return kth;
        
    }
};