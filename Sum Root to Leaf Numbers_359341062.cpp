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
    int sum = 0;
    
    void dfs(TreeNode* root, string num) {
        if (!root) return;
        if (!root->left && !root->right) {
            sum += stoi(num + to_string(root->val));
            return;
        }
        
        dfs(root->left, num + to_string(root->val));
        dfs(root->right, num + to_string(root->val));
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root) sum;        
        dfs(root, "");
        return sum;
    }
};
