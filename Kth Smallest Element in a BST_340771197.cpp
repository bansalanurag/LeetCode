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
    
    void getInorder(TreeNode * root, priority_queue<int, vector<int>, greater<int>> &A) {
        if (root) {
            getInorder(root->left, A);
            A.push(root->val);            
            getInorder(root->right, A);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        priority_queue<int, vector<int>, greater<int>> inorder;
        getInorder(root, inorder);
        
        int ans;
        while (k--) {
            ans = inorder.top();
            inorder.pop();
        }
        
        return ans;
    }
};
