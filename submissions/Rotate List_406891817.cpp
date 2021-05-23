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
    
    int getListLength(ListNode *head) {
        if (!head) return 0;
        
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }
        return len;            
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getListLength(head);
        if (len <= 1) return head;
        k %= len;
        if (k == 0) return head;
        
        ListNode *fast, *slow;
        fast = slow = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *traverse = head;
        while (traverse->next != slow) traverse = traverse->next;
        
        traverse->next = NULL;
        traverse = head;
        head = slow;
        while (slow->next) slow = slow->next;
        slow->next = traverse;
        
        return head;
    }
};
