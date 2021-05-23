/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *prev, *curr, *nextPair;
        curr = head;
        
        while (curr && curr->next) {
            nextPair = curr->next->next;
            
            if (curr == head) {
                head = curr->next;
                head->next = curr;
            } else {
                ListNode *temp = curr->next;
                temp->next = curr;
                prev->next = temp;
            }
            
            curr->next = nextPair;   
            prev = curr;
            curr = nextPair;
        }
        
        return head;
    }
};
