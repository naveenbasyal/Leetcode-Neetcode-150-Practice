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
    map<int,int> mp;
    void createMapping(vector<int>& inorder, int n){
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        } 
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int &id , int inleft , int inright , int n){
        //base
        if(inleft > inright) return NULL;
        
        int node = postorder[id--];
        int pos = mp[node];
        TreeNode* root = new TreeNode(node);
        
        root->right = solve(inorder , postorder , id , pos+1 , inright , n);
        root->left = solve(inorder , postorder , id , inleft , pos - 1 , n);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int id = n-1 , inleft = 0 , inright = n-1;
        
        createMapping(inorder,n);
        
        TreeNode* root = solve(inorder,postorder,id,inleft,inright,n);
        
        return root;
        
    }
};





