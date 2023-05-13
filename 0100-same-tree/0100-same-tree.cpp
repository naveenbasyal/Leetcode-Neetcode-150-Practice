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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p or !q) return p == q;
        if(!p and !q) return true;
        
        if(p->val != q->val) return false;
        bool leftCheck = isSameTree(p->left, q->left);
        bool rightCheck = isSameTree(p->right, q->right);
        if(leftCheck and rightCheck){
            return true;
        }
        else{
            return false;
        }
    }
};