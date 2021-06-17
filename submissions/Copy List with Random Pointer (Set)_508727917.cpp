/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        Node *newHead = nullptr;
        
        Node *traverse1 = head;
        Node *traverse2 = newHead;
        
        while (traverse1) {
            if (newHead == nullptr) {
                newHead = new Node(traverse1->val);
                traverse2 = newHead;
            } else {
                traverse2->next = new Node(traverse1->val);
                traverse2 = traverse2->next;
            }
            
            mapping[traverse1] = traverse2;
            traverse1 = traverse1->next;
        }
        
        traverse1 = head;
        traverse2 = newHead;
        
        while (traverse1) {
            traverse2->random = traverse1->random == nullptr ? nullptr : mapping[traverse1->random];
            traverse1 = traverse1->next;
            traverse2 = traverse2->next;            
        }
        
        return newHead;
    }
};