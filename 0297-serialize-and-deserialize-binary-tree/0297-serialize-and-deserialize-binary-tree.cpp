/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private: 
    // Step1: do preorder traversal and make sure when its leaf node you should add its left and right nodes as null and store all the nodes in the string.
    // For ex:- from the exampl1 : the basic preorder would be : 
    // Simple Preorder: 1 , 2 , 3 , null , null , 4 , 5 
    // but we need to write the null part also of the leaf nodes like:
    // 1 , 2 , null , null , 3 , 4 , null , null , 5 , null , null
    // and then we push the string's data in the queue seperated by comma.
    // after that we start building our tree
    
    TreeNode* buildTree(queue<string> &q){
        string curr = q.front();
        q.pop();
        if(curr == "null") return NULL;
        TreeNode* root = new TreeNode(stoi(curr));
        root->left = buildTree(q);
        root->right = buildTree(q);
        
        return root;
    }
    
public:
    
    
    string serialize(TreeNode* root) {
        if(root == NULL) return "null,";
        
        string leftSide = serialize(root->left);
        string rightSide = serialize(root->right);
        
        return to_string(root->val) + "," + leftSide + rightSide; //preorder: root->left->right
    }

    
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s = "";
        for(auto i : data){
            if(i == ','){
                q.push(s);
                s = "";
                continue;
            }
            s += i;
        }
        return buildTree(q);
    }
};

