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
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast->next) {
            slow = slow->next;
            if (fast->next) {
                if (fast->next->next) fast = fast->next->next;      
                else fast = fast->next;
            }
        }
        return slow;
    }
};
