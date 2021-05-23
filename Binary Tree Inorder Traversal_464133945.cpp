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
    
    void push(stack<TreeNode*> &stk, TreeNode* root) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> S;
        push(S, root);
        
        while (!S.empty()) {
            TreeNode* node = S.top();
            inorder.push_back(node->val);
            S.pop();
            push(S, node->right);
        }
        
        return inorder;
    }
};
