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
    vector<pair<int, pair<int, int>>> M;
    
    bool static sortbysecfirst (const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
        if (a.second.first < b.second.first) 
            return true;
        else if (a.second.first == b.second.first) {
            if (a.second.second < b.second.second)
                return true;
            else if (a.second.second == b.second.second) {
                if (a.first < b.first) 
                    return true;
            }   
        }
        return false;
    }
        
    void traverse(TreeNode *root, int width, int height) {
        if (root) {
            M.push_back({root->val, {width, height}});
            traverse(root->left, width - 1, height + 1);
            traverse(root->right, width + 1, height + 1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, 0, 0);
        sort(M.begin(), M.end(), sortbysecfirst); 
        
        for (int i = 0; i < M.size(); ) {
            vector<int> temp{M[i].first};            
            int j = i + 1;
            while (j < M.size() && M[j].second.first == M[j - 1].second.first) {
                    temp.push_back(M[j++].first);            
            }
            i = j;
            ans.push_back(temp);
        }
        return ans;
    }
};
