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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        
        ListNode *p, *q, *r;
        p = head;
        q = p->next;
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
};
