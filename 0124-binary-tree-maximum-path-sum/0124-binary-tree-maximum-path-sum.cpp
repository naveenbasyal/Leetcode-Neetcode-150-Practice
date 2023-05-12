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
    
    int maxSum = INT_MIN;
    
    int solve(TreeNode* root){    
        if(root == NULL) return NULL;
            
        int leftSum = max(solve(root->left) , 0);
        int rightSum = max(solve(root->right) , 0);
        int sum = root->val + leftSum + rightSum;
        
        maxSum = max(maxSum , sum);
        
        return root->val + max(leftSum , rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};