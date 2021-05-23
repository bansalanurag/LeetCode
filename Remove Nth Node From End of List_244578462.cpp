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
    int getListLength(ListNode* head) {
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getListLength(head);
        if (!head || n == 0) return head;
        if (n >= len) { head = head->next;  return head;    }
        
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast) {
            if (n-- < 0)
                slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};
