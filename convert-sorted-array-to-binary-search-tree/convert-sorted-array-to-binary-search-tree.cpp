/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* build(vector<int> &nums, int l, int r){
        if(l > r){
            return NULL;
        }
        int mid = (l + r)/2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums , l , mid - 1);
        node->right = build(nums , mid + 1 , r);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0 , right = nums.size() - 1;
        return build(nums, left, right);
    }
};