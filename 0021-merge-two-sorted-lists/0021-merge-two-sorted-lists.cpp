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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy = ListNode(0);
        ListNode* currDummy = &dummy;
        
        while(list1 !=NULL and list2 != NULL){
            if(list1 -> val <= list2 -> val){
                currDummy -> next = list1;
                list1 = list1->next;
            }
            else{
                currDummy -> next = list2;
                list2 = list2 -> next;
            }
            currDummy = currDummy->next;
        }
        list1 != NULL ? currDummy ->next = list1 : currDummy -> next = list2;
        return dummy.next;
    }
};