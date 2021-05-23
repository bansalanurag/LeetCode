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
    
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode *curr = S.top(); S.pop();
            
            if (curr->right)
                S.push(curr->right);
            if (curr->left)
                S.push(curr->left);
            
            if (!S.empty()) {
                curr->right = S.top();
                curr->left = NULL;
            }
        }
    }
};
