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
    
    TreeNode* buildTree(TreeNode *root, vector<int> &preorder, vector<int> &inorder) {
        TreeNode *node = new TreeNode(preorder[0]);
        int inRoot = lower_bound(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();  
        
        vector<int> P1{preorder.begin() + 1, preorder.begin() + inRoot + 1};
        vector<int> I1{inorder.begin(), inorder.begin() + inRoot};
        if (P1.size() != 0)
            node->left = buildTree(node, P1, I1);
        
        vector<int> P2{preorder.begin() + inRoot + 1, preorder.end()};
        vector<int> I2{inorder.begin() + inRoot + 1, inorder.end()};
        if (P2.size() != 0)
            node->right = buildTree(node, P2, I2);
        
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0)
            return NULL;
        
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        
        TreeNode *root = new TreeNode(preorder[0]);
        int inRoot = lower_bound(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();  
        
        vector<int> P1{preorder.begin() + 1, preorder.begin() + inRoot + 1};
        vector<int> I1{inorder.begin(), inorder.begin() + inRoot};
        if (P1.size() != 0)
            root->left = buildTree(root, P1, I1);
        
        vector<int> P2{preorder.begin() + inRoot + 1, preorder.end()};
        vector<int> I2{inorder.begin() + inRoot + 1, inorder.end()};
        if (P2.size() != 0)
            root->right = buildTree(root, P2, I2);
            
        return root;
    }
};
