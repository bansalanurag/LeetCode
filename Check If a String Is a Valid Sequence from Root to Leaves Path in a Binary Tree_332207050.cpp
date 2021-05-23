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
    
    bool dfs(TreeNode *root, vector<int> &A, int i, int n) {
        if (!root) return false;
        if ((root && i == n ) || (A[i] != root->val)) return false;
        if (!root->left && !root->right) {
            if (i == n - 1 && A[i] == root->val) return true;
            return false;
        }
        
        return dfs(root->left, A, i + 1, n) || dfs(root->right, A, i + 1, n);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int n = arr.size();
        return dfs(root, arr, 0, n);
    }
};
