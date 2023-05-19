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
    
    void getLeaf1(TreeNode* root1 , vector<int> &leaf1){
        if(root1 == NULL) return;
        if(root1->left == NULL and root1->right == NULL){
            leaf1.push_back(root1->val);
        }
        getLeaf1(root1->left,leaf1);
        getLeaf1(root1->right,leaf1);
    }
    
    void getLeaf2(TreeNode* root2 , vector<int> &leaf2){
        if(root2 == NULL) return;
        if(root2->left == NULL and root2->right == NULL){
            leaf2.push_back(root2->val);
        }
        getLeaf2(root2->left,leaf2);
        getLeaf2(root2->right,leaf2);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // if(root1 == NULL or root2 == NULL) return false;
        vector<int> leaf1;
        vector<int> leaf2;
        getLeaf1(root1 , leaf1);
        getLeaf2(root2,leaf2);
        
        return leaf1 == leaf2;
    }
};