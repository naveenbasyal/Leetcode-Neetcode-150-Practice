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
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;ListNode* curr = head;
        while(curr != NULL){
            ListNode* currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        // using Array
//         vector<int> v;
//         ListNode* curr = head;
//         while(curr != NULL){
//             v.push_back(curr->val);
//             curr = curr->next;
//         }
//         int i=0, j = v.size()-1;
        
//         while(i <= j){
//             if(v[i] != v[j]){
//                 return false;
//             }
//             i++,j--;
//         }
//         return true;
        
        
        ListNode* slow = head; ListNode* fast = head;
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* firstHalf = head;
        ListNode* secondHalf = reverse(slow->next);
        
        while(secondHalf != NULL){
            if(firstHalf->val != secondHalf->val){
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
        
    }
};