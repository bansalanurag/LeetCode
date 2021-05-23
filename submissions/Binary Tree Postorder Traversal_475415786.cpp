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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        if (!root) {
            return order;
        }
        
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode *curr = S.top(); S.pop();
            order.push_back(curr->val);
            
            if (curr->left)
                S.push(curr->left);
            if (curr->right)
                S.push(curr->right);
        }
        
        reverse(order.begin(), order.end());
        return order;
    }
};
