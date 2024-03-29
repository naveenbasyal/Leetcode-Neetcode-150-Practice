/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;
        
        if(root->val == p->val or root->val == q->val){
            return root;
        }
        
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        
        if(leftAns != NULL and rightAns != NULL){
            return root;
        }
        else if(leftAns == NULL and rightAns != NULL){
            return rightAns;
        }
        else if(leftAns != NULL and rightAns == NULL){
            return leftAns;
        }
        else{
            return NULL;
        }
        
        
    }
};