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
    
    void getPath(TreeNode* root,vector<vector<int>> &ans ,vector<int> &path,int &sum, int targetSum){
        if(root == NULL) return;
        sum += root->val;
        path.push_back(root->val);
        
        if(sum == targetSum and root->left == NULL and root->right == NULL){
            ans.push_back(path);
        }
        getPath(root->left , ans, path, sum , targetSum);
        getPath(root->right, ans, path, sum , targetSum);
        
        path.pop_back();
        sum-= root->val;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum =0;
        if(!root ) return ans;
        vector<int> path;
        getPath(root, ans,path,sum,targetSum);
        return ans;
        
    }
};