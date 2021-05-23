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
    
    TreeNode* buildTree(vector<int> &A, int l, int h) {
        if (l > h) return NULL;
        
        int m = floor((l + h) / 2);
        TreeNode *root = new TreeNode(A[m]);
        root->left = buildTree(A, l, m - 1);        
        root->right = buildTree(A, m + 1, h);
         
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = buildTree(nums, 0, nums.size() - 1);
        return root;
    }
};
