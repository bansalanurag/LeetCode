/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = slow->next;
        
        while (slow != fast) {
            if (!fast || !fast->next)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (slow != fast)
            return NULL;
        
        int c = 1;
        slow = slow->next;
        while (slow != fast) {
            slow = slow->next;
            c += 1;
        }
        ListNode *p1, *p2;
        p1 = head;
        while (c-- > 0) {
            p1 = p1->next;
        }
        
        p2 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};
