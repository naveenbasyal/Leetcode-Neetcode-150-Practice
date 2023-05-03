/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* currNode= node;
        ListNode* prev = NULL;
        
        while(currNode->next != NULL){
            currNode->val = currNode->next->val;
            prev= currNode;
            currNode = currNode->next;
        }
        
        prev->next = NULL;
        
    }
};