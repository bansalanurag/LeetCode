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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL;
        ListNode *ans = l3;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (!ans) {
                    ans = new ListNode(l1->val);
                    l3 = ans;
                } else {
                    ans->next = new ListNode(l1->val);
                    ans = ans->next;
                }
                l1 = l1->next;
            } else if (l1->val > l2->val) {
                if (!ans) {
                    ans = new ListNode(l2->val);
                    l3 = ans;
                } else {
                    ans->next = new ListNode(l2->val);
                    ans = ans->next;
                }
                l2 = l2->next;
            } else {
                if (!ans) {
                    ans = new ListNode(l1->val);
                    l3 = ans;
                    ans->next = new ListNode(l2->val);
                    ans = ans->next;
                } else {
                    ans->next = new ListNode(l1->val);
                    ans = ans->next;
                    ans->next = new ListNode (l2->val);
                    ans = ans->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }
                
        if (l1) {
            if (!ans) return l1;
            else ans->next = l1;
        }
        if (l2) {
            if (!ans) return l2;
            else ans->next = l2;
        }
        return l3;
    }
};
