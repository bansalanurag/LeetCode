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
    
    int getIndexInInorder(vector<int> &inorder, int val) {
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode* AddNode(TreeNode *root, vector<int> &preorder, vector<int> &inorder) {
        TreeNode *node = new TreeNode(preorder[0]);        
        int inRoot = getIndexInInorder(inorder, preorder[0]);
        
        vector<int> P1{preorder.begin() + 1, preorder.begin() + inRoot + 1};
        vector<int> I1{inorder.begin(), inorder.begin() + inRoot};
        if (P1.size() != 0)
            node->left = AddNode(node, P1, I1);
        
        vector<int> P2{preorder.begin() + inRoot + 1, preorder.end()};
        vector<int> I2{inorder.begin() + inRoot + 1, inorder.end()};
        if (P2.size() != 0)
            node->right = AddNode(node, P2, I2);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[0]);
        int inRoot = getIndexInInorder(inorder, preorder[0]);  
        
        vector<int> P1{preorder.begin() + 1, preorder.begin() + inRoot + 1};
        vector<int> I1{inorder.begin(), inorder.begin() + inRoot};
        if (P1.size() != 0)
            root->left = AddNode(root, P1, I1);
        
        vector<int> P2{preorder.begin() + inRoot + 1, preorder.end()};
        vector<int> I2{inorder.begin() + inRoot + 1, inorder.end()};
        if (P2.size() != 0)
            root->right = AddNode(root, P2, I2);
            
        return root;
    }
};
