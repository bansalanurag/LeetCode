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
        Node* newNode = nullptr;
        if (!head)
            return newNode;
        
        if (!head->next) {
            newNode = new Node(head->val);
            newNode->random = head->random == head ? newNode : nullptr;
            return newNode;
        }
        
        Node* traverse = head;
        Node *traverse2;
        
        while (traverse) {
            Node* nextNode = traverse->next;
            traverse->next = new Node(traverse->val);
            traverse->next->next = nextNode;
            traverse = nextNode;
        }
        
        traverse = head;
        traverse2 = traverse->next;
        while (traverse) {
            traverse2->random = traverse->random == nullptr ? nullptr : traverse->random->next;
            traverse = traverse2->next;
            traverse2 = traverse == nullptr ? nullptr : traverse->next;
        }
        
        traverse = head;
        newNode = traverse2 = traverse->next;
        while (traverse) {
            traverse->next = traverse2->next;
            traverse = traverse->next;
            
            traverse2->next = traverse == nullptr ? nullptr : traverse->next;            
            traverse2 = traverse2->next;            
        }
        
        return newNode;
    }
};