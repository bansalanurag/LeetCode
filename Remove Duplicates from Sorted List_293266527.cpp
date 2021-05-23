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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        while (head->next && head->val == head->next->val) head = head->next;
        ListNode *slow = head->next, *fast;
        while (slow) {
            if (slow->next) {
                fast = slow->next;
                while (fast->next && slow->val == fast->val)  fast = fast->next;
                slow->next = fast->val != slow->val ? fast : fast->next;                            
                slow = fast;            
            } else slow = slow->next;
        }
        return head;
    }
};
