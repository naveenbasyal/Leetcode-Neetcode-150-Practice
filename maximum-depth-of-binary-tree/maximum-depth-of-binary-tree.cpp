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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        //recursively finding the height of left and right subtree
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        int ans = max(leftHeight, rightHeight) + 1; //1 is for counting root node itself
        
        return ans;
        
        
    }
};