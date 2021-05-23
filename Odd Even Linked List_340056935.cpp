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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        
        ListNode *a, *b, *head2;
        a = head;
        head2 = head->next;
        b = head2;
        
        int count = 0;
        while (a || b) {
            if (!count) {
                if (b) {
                    a->next = b->next;
                    a = a->next;
                } else 
                    a = NULL;
            } else {
                if (a) {
                    b->next = a->next;
                    b = b->next;
                } else 
                    b = NULL;
            }
            count ^= 1;
        }
        
        a = head;
        while (a->next) {
            a = a->next;
        }
        a->next = head2;
        
        return head;
    }
};
