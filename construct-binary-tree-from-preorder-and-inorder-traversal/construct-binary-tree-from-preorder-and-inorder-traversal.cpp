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
    
    int getPos(vector<int> &inorder , int n , int element){
        for(int i = 0; i < n; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& preorder,vector<int> & inorder,
                    int &preorder_id,int n , int inorder_left ,int inorder_right)
    {
        
        if(preorder_id > n || inorder_left > inorder_right) return NULL;
        
        int element = preorder[preorder_id++];
        
        TreeNode* root = new TreeNode(element);
        
        int pos = getPos(inorder , n , element);
        
        root->left = solve(preorder,inorder,preorder_id , n , inorder_left , pos - 1);
        root->right = solve(preorder,inorder,preorder_id  , n , pos + 1 , inorder_right);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preorder_id = 0 , inorder_Left = 0 ,  inorder_Right = n - 1 ;
       TreeNode* root =  solve(preorder , inorder , preorder_id , n , inorder_Left ,inorder_Right);
        
        return root;
        
    }
};