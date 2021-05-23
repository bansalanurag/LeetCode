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
    
    TreeNode* buildTree(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return NULL;
        if (!t1 && t2)  return t2;        
        if (t1 && !t2)  return t1;
        
        TreeNode* root = new TreeNode();
        
        root->val = t1->val + t2->val;
        root->left = buildTree(t1->left, t2->left);
        root->right = buildTree(t1->right, t2->right);
        
        return root;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* tree = new TreeNode;
        tree = buildTree(t1, t2);
        return tree;
    }
};
