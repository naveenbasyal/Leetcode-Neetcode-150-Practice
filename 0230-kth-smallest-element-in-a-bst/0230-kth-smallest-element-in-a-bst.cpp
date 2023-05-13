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
    // <-------------------------------- Normal Brute Force Approch------------------------------->
//     void inorder(TreeNode* root, vector<int> &ans){
//         if(root == NULL) return;
//         inorder(root->left , ans);
//         ans.push_back(root->val);
//         inorder(root->right , ans);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         inorder(root,ans);
        
//         return ans[k-1];
//     }
    // <----------------------- Little Optimised Approach ------------------------------->
    
    void inorder(TreeNode* root, int &k , int &ans){
        
        if(root == NULL) return;
        inorder(root->left , k, ans);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        inorder(root->right , k , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root,k,ans);
        
        return ans;
    }
};