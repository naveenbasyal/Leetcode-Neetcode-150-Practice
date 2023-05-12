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
    
    bool isIdentical(TreeNode*root, TreeNode* subRoot){
        if(!root or !subRoot){
            return root == subRoot;
        }
        
        return root->val == subRoot->val and 
            isIdentical(root->left,subRoot->left) and isIdentical(root->right,subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root or !subRoot){
            return root == subRoot;
        }
         // If subRoot is identical to root, return true
        if(isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};