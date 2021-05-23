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
    
    void dfs(TreeNode *root, TreeNode* parent, TreeNode *gparent) {
        if (!root) return;
        if (gparent && (!(gparent->val&1))) sum += root->val;        
        
        gparent = parent;            
        parent = root;
        
        dfs(root->left, parent, gparent);
        dfs(root->right, parent, gparent);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        dfs(root, NULL, NULL);
        return sum;
    }
};
