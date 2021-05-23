/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void dfs(Node *root, vector<int> &ans) {
        ans.push_back(root->val);
        for (auto u : root->children) dfs(u, ans);        
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        dfs(root, ans);
        return ans;
    }
};
