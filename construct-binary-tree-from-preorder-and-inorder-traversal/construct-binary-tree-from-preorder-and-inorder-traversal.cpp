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
    // This is Optimal Code, check prevb code for Brute Force
    map<int,int> mp;
    void createInorderMapping(vector<int> &inorder, int n){
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
    }
    TreeNode* helper(vector<int>& preorder , vector<int>& inorder, int &id , int inLeft , int inRight , int n){
        //base 
        if(inLeft > inRight) return NULL;
        
        int node = preorder[id++];
        TreeNode* root = new TreeNode(node);
        int pos = mp[node];
        
        root->left = helper(preorder , inorder , id , inLeft , pos - 1 , n);
        root->right = helper(preorder , inorder , id , pos + 1 , inRight , n);
        return root;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int id = 0 , inLeft = 0 , inRight = n - 1 ;
        //creating node to index mapping
        createInorderMapping(inorder , n);
        TreeNode* root = helper(preorder , inorder , id , inLeft , inRight , n);
        return root;
    }
};
