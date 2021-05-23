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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> levelOrder;
        queue<TreeNode *> Q;
        int numOfNodes = 1, numOfNodesNext = 0;
        
        if (!root) return result;
        
        Q.push(root);
        vector<int> temp;
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            temp.push_back(node->val);
            numOfNodes--;            
            if (node->left) {
                Q.push(node->left);
                numOfNodesNext++;
            }
            if (node->right) {
                Q.push(node->right);
                numOfNodesNext++;
            }
            if (numOfNodes == 0) { 
                levelOrder.push_back(temp); 
                temp.clear(); 
                numOfNodes = numOfNodesNext;
                numOfNodesNext = 0;
            }
            Q.pop();
        }
        
        for (auto i : levelOrder)
            result.push_back(i[i.size() - 1]);        
        return result;
    }
};
