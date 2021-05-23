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
    bool dfs(TreeNode* root, int sum, int curr) {
        if (!root->left && !root->right)  return root->val + curr == sum ? true : false;
        if (root->left) if (dfs(root->left, sum, curr + root->val)) return true;
        if (root->right) if (dfs(root->right, sum, curr + root->val)) return true;
        return false;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return dfs(root, sum, 0);
    }
};
