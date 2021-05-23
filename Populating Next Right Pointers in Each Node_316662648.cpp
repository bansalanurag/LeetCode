/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        queue<Node*> Q;
        Q.push(root);
        int curr = 1, next = 0;
        while (!Q.empty()) {
            Node* top = Q.front();
            Q.pop();
            
            if (top->left) { Q.push(top->left); next++; }
            if (top->right) { Q.push(top->right); next++; }
            
            if (--curr == 0) {
                top->next = NULL;
                curr = next;
                next = 0;
            } else {
                top->next = Q.front();
            }
        }
        
        return root;
    }
};
