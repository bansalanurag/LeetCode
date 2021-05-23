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
    vector<vector<int>> ans;
    
    void dfs(TreeNode* root, int sum, int curr, vector<int> &path) {
        if (!root->left && !root->right) { 
            if (root->val + curr == sum) {
                path.push_back(root->val);
                ans.push_back(path);                                
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        if (root->left) dfs(root->left, sum, curr + root->val, path);
        if (root->right) dfs(root->right, sum, curr + root->val, path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return ans;
        vector<int> path;
        dfs(root, sum, 0, path);
        return ans;
    }
};
