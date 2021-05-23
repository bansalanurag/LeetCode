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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        vector<vector<int>> ReverseLevelOrder;
        if (!root) return ReverseLevelOrder;
        
        int numOfNodesAtThisLevel = 1, numOfNodesAtNextLevel = 0;
        vector<int> nodesAtThisLevel;            
        queue<TreeNode *> Q;
        Q.push(root);
        
        while (!Q.empty()) {
            TreeNode* top = Q.front();
            Q.pop();
            nodesAtThisLevel.push_back(top->val);
            numOfNodesAtThisLevel -= 1;
            
            if (top->left) { Q.push(top->left); numOfNodesAtNextLevel += 1; }
            if (top->right) { Q.push(top->right); numOfNodesAtNextLevel += 1; }
            
            if (numOfNodesAtThisLevel == 0) {
                ReverseLevelOrder.push_back(nodesAtThisLevel);
                nodesAtThisLevel.clear();
                numOfNodesAtThisLevel = numOfNodesAtNextLevel;
                numOfNodesAtNextLevel = 0;
            }            
        }
        
        reverse(ReverseLevelOrder.begin(), ReverseLevelOrder.end());
        return ReverseLevelOrder;
    }
};
