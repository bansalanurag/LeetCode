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
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
    
    ListNode* reverseList(ListNode *head) {
        ListNode *p, *q, *r;
        p = head;
        q = head->next;
        r = NULL;        
        while (q) {
            p->next = r;
            r = p;
            p = q;
            q = q->next;
        }        
        p->next = r;
        return p;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        
        int len = getListLength(head);
        int k = floor(len / 2);
        
        ListNode *a = head, *b;
        while (k--) {
            a = a->next;
        }
    
        b = reverseList(a->next);
        a->next = NULL;
        a = head;
        
        while (b) {
            ListNode *c = a->next;
            a->next = b;
            b = b->next;
            a->next->next = c;
            a = c;
        }
    }
};
