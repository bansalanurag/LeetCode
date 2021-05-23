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
    
    bool dfs(TreeNode *root, TreeNode *target, vector<TreeNode*> &path) {
        if (!root)
            return false;
        
        if (root == target) {
            path.push_back(root);
            return true;
        }        
            
        if (dfs(root->left, target, path)) {
            path.push_back(root);
            return true;
        }
        
        if (dfs(root->right, target, path)) {
            path.push_back(root);
            return true;
        }        
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathA, pathB;
        dfs(root, p, pathA);
        dfs(root, q, pathB);
        
        // for (auto i : pathA) cout << i->val << " "; cout << "\n";
        // for (auto i : pathB) cout << i->val << " "; cout << "\n";
        
        unordered_set<TreeNode*> S;
        for (auto i : pathA) S.insert(i);
        // reverse(pathB.begin(), pathB.end());
        for (auto i : pathB) if (S.find(i) != S.end()) return i;
        
        return NULL;
    }
};
