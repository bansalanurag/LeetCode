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
    bool isEqual(TreeNode *s, TreeNode *t) {
        if (s && !t || !s && t)
            return false;
        
        if (!s && !t)
            return true;
        
        if (s->val != t->val)
            return false;
            
        return isEqual(s->left, t->left) && isEqual(s->right, t->right);         
    }
    
    bool traverse(TreeNode *s, TreeNode *t) {
        if (!s)
            return false;
        
        return isEqual(s, t) || traverse(s->left, t) || traverse(s->right, t);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s, t);
    }
};
