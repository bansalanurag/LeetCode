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
    
    vector<TreeNode*> roots;
    unordered_map<TreeNode*, bool> M;
    
    bool dfs(TreeNode *root, int delValue, TreeNode *parent) {
        if (root) {
            if (root->val == delValue) {
                M[root] = true;
                if (root->left) M[root->left] = false;
                if (root->right) M[root->right] = false;         
                
                if (parent) {
                    if (parent->left == root)
                        parent->left = NULL;
                    if (parent->right == root)
                        parent->right = NULL;
                }                
                
                root = NULL;                
                delete(root);
                
                return true;
            }
            
            return dfs(root->left, delValue, root) || dfs(root->right, delValue, root);
        }
        return false;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (to_delete.empty())
            return roots;  
                
        M[root] = false;
        for (int val : to_delete) {
            for (auto newRoot : M) {
                if (!newRoot.second && dfs(newRoot.first, val, NULL))
                    break;
            }            
        }
        
        for (auto newRoots : M) {
            if (!newRoots.second)
                roots.push_back(newRoots.first);
        }
        
        return roots;
    }
};
