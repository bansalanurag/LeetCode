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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) {
            return ans;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        double sum = 0; 
        int count = 0;
        int curr = 1, next = 0;
        
        while (!Q.empty()) {
            TreeNode* top = Q.front();
            sum += top->val;
            count += 1;
            Q.pop();            
            
            if (top->left) { Q.push(top->left); next++; }
            if (top->right) { Q.push(top->right); next++; }
            
            if (--curr == 0) {
                curr = next;
                next = 0;
                ans.push_back(sum / count);
                sum = 0;
                count = 0;
            }
        }
        
        return ans;
    }
};
