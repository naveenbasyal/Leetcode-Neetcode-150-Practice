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
    void createMapping(vector<int> &inorder , int size){
        for(int i = 0; i < size; i++){
            mp[inorder[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int> &preorder, int &id , int left , int right , int size){
        if(left > right) return NULL;
        
        int element = preorder[id++];
        int pos = mp[element];
        TreeNode* root = new TreeNode(element);
        
        root->left = solve(preorder , id , left , pos - 1 , size);
        root->right = solve(preorder , id , pos + 1 , right , size);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int id = 0; // to iterate over preorder array
        int size = inorder.size();
        int left = 0 , right = size - 1;
        createMapping(inorder,size);
        return solve(preorder,id,left,right, size);
        
        
    }
};