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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* oddCurr = odd;
        ListNode* even = head->next;
        ListNode* evenCurr = even;
        while(oddCurr->next!=NULL and oddCurr->next->next != NULL){
            oddCurr->next = evenCurr->next;
            oddCurr = evenCurr->next;
            evenCurr->next = oddCurr->next;
            evenCurr = oddCurr->next;
        }
        oddCurr->next = even;
        return odd;

    }
};