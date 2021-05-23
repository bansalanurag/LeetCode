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
    
    bool check(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) && check(t1->right, t2->left) && check(t1->left, t2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;    
        return check(root, root);
    }
};
