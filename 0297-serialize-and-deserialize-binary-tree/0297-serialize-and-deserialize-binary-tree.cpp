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
public:


    string serialize(TreeNode* root) {
        
        if(root == NULL) return "null,";
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + right;
        
    }

    TreeNode* buildTree(queue<string> &q){
        string s = q.front();
        q.pop();
         if(s == "null"){
             return NULL;
         }
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        string s="";
        queue<string> q;
        
        for(auto i:data){
            if(i == ','){
                q.push(s);
                s="";
                continue;// this is to not include comma(,) in the string s or queue(q)
            }
            s += i;
        }
        return buildTree(q);
    }
};

