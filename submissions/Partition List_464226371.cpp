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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        
        ListNode *less, *greater;
        ListNode *temp = head;
        less = greater = NULL;
        ListNode *a = NULL, *b = NULL;
        
        while (temp) {
            if (temp->val < x) {
                if (less == NULL) {
                    less = new ListNode(temp->val);
                    a = less;
                } else {
                    a->next = new ListNode(temp->val);
                    a = a->next;
                }
            }
            temp = temp->next;
        }        
        
        temp = head;
        while (temp) {
            if (temp->val >= x) {
                if (greater == NULL) {
                    greater = new ListNode(temp->val);
                    b = greater;
                } else {
                    b->next = new ListNode(temp->val);
                    b = b->next;
                }
            }
            temp = temp->next;
        }                
        if (!less && greater)
            return greater;
        else if (!greater && less)
            return less;
        
        a->next = greater;
        return less;
    }
};
