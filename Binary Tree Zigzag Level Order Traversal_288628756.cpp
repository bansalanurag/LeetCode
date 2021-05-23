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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> Q;
        Q.push(root);
        ans.push_back(vector<int> {root->val});
        int size = 1, nextsize = 0, level = 1;
        vector<int> nextLevel;          
        while (!Q.empty()) {
            if (size == 0) {
                size = nextsize;
                nextsize = 0;
                if (level) 
                    reverse(nextLevel.begin(), nextLevel.end());                
                ans.push_back(nextLevel);
                level ^= 1;
                nextLevel.clear();
            }
            TreeNode* node = Q.front();
            if (node->left) {
                Q.push(node->left);
                nextsize += 1;
                nextLevel.push_back(node->left->val);
            }
            if (node->right) {
                Q.push(node->right);
                nextsize += 1;
                nextLevel.push_back(node->right->val);
            }
            Q.pop();
            size -= 1;
        }
        return ans;
    }
};
