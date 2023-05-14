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
    map<int , int> nodeToIndex;
    
    void createMapping(vector<int>& inorder , int size){
        for(int i = 0; i < size; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int>& postorder , int &id , int left, int right, int size){
        if(left > right) return NULL; 
        
        int data = postorder[id--];
        int pos = nodeToIndex[data];//getting the pos of the curr element left and right part of root or node.
        TreeNode* root = new TreeNode(data);
        
        root->right = solve(postorder, id, pos + 1 , right, size);
        root->left = solve(postorder, id, left, pos - 1, size);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int id = size - 1 , left = 0 , right = size - 1;
        createMapping(inorder , size);
        
        return solve(postorder , id, left , right , size);
    }
};