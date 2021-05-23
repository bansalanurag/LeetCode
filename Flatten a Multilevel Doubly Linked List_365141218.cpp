/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        
        if (!head->next && head->child) {
            head->next = flatten(head->child);
            head->child = NULL;
            head->next->prev = head;
            return head;
        }
        
        
        Node* traverse = head;
        while (traverse) {
            if (traverse->child) {
                Node* nextNode = traverse->next;                        
                traverse->next = flatten(traverse->child);
                traverse->child = NULL;
                
                traverse->next->prev = traverse;                
                Node* innerList = traverse->next;
                while (innerList->next) innerList = innerList->next;
                
                nextNode->prev = innerList;
                innerList->next = nextNode;
                traverse = nextNode;
            } else traverse = traverse->next;
        }
        
        return head;        
    }
};
