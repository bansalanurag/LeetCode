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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        
        while (head && head->val == val)
            head = head->next;
        
        ListNode *a = head;
        while (a) {
            ListNode *b = a->next;
            while (b && b->val == val) {
                b = b->next; 
            }
            a->next = b;
            a = a->next;
        }
        
        return head;        
    }
};
