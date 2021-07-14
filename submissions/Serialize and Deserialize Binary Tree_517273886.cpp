/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoding = "";
        if (!root) {
            return encoding;
        }
        
        stack<TreeNode*> S;
        S.push(root); 
        while (!S.empty()) {
            TreeNode* current = S.top();
            encoding += (current == NULL ? "null" : to_string(current->val)) + ",";
            S.pop();
            
            if (current == NULL)
                continue;
                
            S.push(current->right);
            S.push(current->left);
        }
        
        return encoding;
    }

    void splitString(string data, queue<int> &Q) {
        for (int i = 0, j = 0; i < data.length(); i = j + 1) {
            j = i;
            while (j < data.length() && data[j] != ',') {
                j++;
            }
            
            int val = data.substr(i, j - i) == "null" ? INT_MAX : stoi(data.substr(i, j - i));
            Q.push(val);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<int> Q;
        splitString(data, Q);
        return deserializeHelper(Q);
    }
    
    TreeNode* deserializeHelper(queue<int> &Q) {
        if (Q.empty())
            return NULL;
        
        if (Q.front() == INT_MAX) {
            Q.pop();
            return NULL;
        }
        
        TreeNode *node = new TreeNode(Q.front());
        Q.pop();
        node->left = deserializeHelper(Q);
        node->right = deserializeHelper(Q);
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));