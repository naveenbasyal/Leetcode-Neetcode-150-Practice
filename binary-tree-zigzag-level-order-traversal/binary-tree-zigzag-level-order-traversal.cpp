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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root== NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left_right = true;
        
        while(!q.empty()){
            vector<int> v;
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(!left_right) reverse(v.begin(),v.end());
            left_right = !left_right;
            ans.push_back(v);
        }
        
        return ans;
    }
};