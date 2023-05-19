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
    int pairSum(ListNode* head) {
        vector<int> v;
        
        ListNode* curr = head;
        while(curr!= NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        int i = 0 , j = v.size() - 1 , sum = 0, maxi = INT_MIN;
        
        while(i<j){
            sum = v[i] + v[j];
            maxi = max(maxi,sum);
            i++,j--;
        }
        return maxi;
    }
};