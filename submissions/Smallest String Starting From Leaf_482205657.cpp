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
    
    string ans = "";
    
    void dfs(TreeNode *root, string curr) {
        if (root) {            
            curr = (char) (root->val + 97) + curr;
            
            if (!root->left && !root->right) {
                ans = ans == "" ? curr : min(curr, ans);
            }
            
            dfs(root->left, curr);
            dfs(root->right, curr);
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
