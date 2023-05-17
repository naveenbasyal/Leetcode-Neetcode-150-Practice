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
    
   void getPath(TreeNode* root, vector<vector<int>>& ans, vector<int>& path, int& sum, int targetSum) {
    if (root == nullptr)
        return;

    sum += root->val;
    path.push_back(root->val);

    if (sum == targetSum && root->left == nullptr && root->right == nullptr) {
        ans.push_back(path);
    }

    getPath(root->left, ans, path, sum, targetSum);
    getPath(root->right, ans, path, sum, targetSum);

    // Backtrack by removing the last element from the path and subtracting its value from sum
    path.pop_back();
    sum -= root->val;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    vector<int> path;
    int sum = 0;
    getPath(root, ans, path, sum, targetSum);

    return ans;
}

};