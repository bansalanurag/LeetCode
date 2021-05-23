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
    TreeNode* buildTree(TreeNode* root) {
        if (!root) return NULL;
                
        TreeNode *node = new TreeNode(root->val);
        node->left = buildTree(root->right);
        node->right = buildTree(root->left);
        
        return node;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* newTree = NULL;
        if (!root) return newTree;
        
        newTree = new TreeNode(root->val);
        newTree->left = buildTree(root->right);
        newTree->right = buildTree(root->left);
        
        return newTree;
    }
};
