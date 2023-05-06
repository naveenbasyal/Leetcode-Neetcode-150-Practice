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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root == NULL) return v;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> levelValues;
            while(size){
                TreeNode* curr = q.front();
                levelValues.push_back(curr->val);
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);   
                size--;
            }
            v.push_back(levelValues);
        }
        return v;
        
    }
};