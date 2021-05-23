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
    
    void inorder(TreeNode *root, multiset<int> &M) {
        if (root) {
            M.insert(root->val);
            inorder(root->left, M);
            inorder(root->right, M);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        multiset<int> M;
        inorder(root1, M);
        inorder(root2, M);
        for (auto i : M) ans.push_back(i);
        return ans;
    }
};
