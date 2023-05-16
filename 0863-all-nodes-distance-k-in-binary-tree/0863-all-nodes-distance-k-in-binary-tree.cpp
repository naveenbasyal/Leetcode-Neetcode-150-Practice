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
    
    TreeNode* createMapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &nodeToParent , TreeNode* target){
        queue<TreeNode*> q; 
        q.push(root);
        nodeToParent[root] = NULL;
        TreeNode* targetNode = NULL;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val == target->val){
                    targetNode = curr;
                }
                if(curr->left and curr->right){
                    nodeToParent[curr->left] = curr;
                    nodeToParent[curr->right] = curr;
                    q.push(curr->left);
                    q.push(curr->right);
                }
                else if(curr->left){
                    nodeToParent[curr->left] = curr;
                    q.push(curr->left);
                }
                else if(curr->right){
                    nodeToParent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        return targetNode;
    }
    
    void findNode(TreeNode* targetNode,unordered_map<TreeNode* , bool> &visited,unordered_map<TreeNode*,TreeNode*> &nodeToParent , vector<int> &ans , int k){
        queue<TreeNode*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        while(!q.empty() and k--){
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left and !visited[curr->left]){
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right and !visited[curr->right]){
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if(nodeToParent[curr] and !visited[nodeToParent[curr]]){
                    visited[nodeToParent[curr]] = true;
                    q.push(nodeToParent[curr]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL) return ans;
        unordered_map<TreeNode* , TreeNode*> nodeToParent;
        unordered_map<TreeNode* , bool> visited;
        TreeNode* targetNode = createMapping(root , nodeToParent , target);
        findNode(targetNode,visited,nodeToParent,ans,k);
        
        return ans;
    }
};