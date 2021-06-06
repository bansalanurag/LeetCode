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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root)
            return 0;
        
        if (root->val < L)
            return rangeSumBST(root->right, L, R);
        else if (root->val > R) 
            return rangeSumBST(root->left, L, R);
        
        return ((root->val >= L && root->val <= R ? root->val : 0) + 
                rangeSumBST(root->left, L, min(root->val, R)) + rangeSumBST(root->right , max(root->val, L), R));    
    }
};