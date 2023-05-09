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
    void traverse(TreeNode* root1,TreeNode* root2, bool &ans){
        if(root1 == NULL and root2 == NULL)return;
        if(root1 == NULL or root2 == NULL or root1->val != root2->val){
            ans = false;
            return;
        } 
        traverse(root1->left,root2->right ,ans);
        traverse(root1->right,root2->left,ans);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        bool ans = true;
        traverse(root->left, root->right,ans);
        return ans;
    }
};