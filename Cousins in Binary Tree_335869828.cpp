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
    
    vector<int> dfs(TreeNode *root, int v, int depth, int parent) {
        vector<int> info(2);
        if (root->val == v) {
            info[0] = parent;
            info[1] = depth;
            return info;
        }
        
        vector<int> left, right;
        if (root->left) left = dfs(root->left, v, depth + 1, root->val);
        if (root->right) right = dfs(root->right, v, depth + 1, root->val);
        
        info = left.empty() ? right : left;
        return info;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        if (!root) return false;
        
        vector<int> xInfo = dfs(root, x, 0, root->val);
        vector<int> yInfo = dfs(root, y, 0, root->val);
        
        cout << xInfo[0] << " " << xInfo[1] << " " << yInfo[0] << " " << yInfo[1] << endl;
        return (xInfo[0] != yInfo[0] && xInfo[1] == yInfo[1]); 
    }
};
