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
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        bool left_to_right = true;
        
        q.push(root);
        
        while(!q.empty()){
            vector<int> value;
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                value.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(!left_to_right) reverse(value.begin(),value.end());
            left_to_right = !left_to_right;
            ans.push_back(value);
        }
        return ans;
    }
};